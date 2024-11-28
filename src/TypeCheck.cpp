#include "TypeCheck.h"
//global tabels
//typeMap func2retType; // function name to return type

// global token ids to type
typeMap g_token2Type; 

// local token ids to type, since func param can override global param
typeMap funcparam_token2Type;
vector<typeMap*> local_token2Type;
// 当前作用域的token2Type
typeMap* current_token2Type = &g_token2Type;

// 记录定义过的函数
functionsVector definedFunctions;
// 记录当前函数
string currentFunction = "";
// 记录函数的参数
paramMemberMap func2Param;
// 记录struct的成员
paramMemberMap struct2Members;
// 记录数组的长度
arrayLengthMap array2Len;

// private util functions
void error_print(std::ostream& out, A_pos p, string info)
{
    out << "Typecheck error in line " << p->line << ", col " << p->col << ": " << info << std::endl;
    exit(0);
}

void print_token_map(typeMap* map){
    for(auto it = map->begin(); it != map->end(); it++){
        std::cout << it->first << " : ";
        switch (it->second->type->type)
        {
        case A_dataType::A_nativeTypeKind:
            switch (it->second->type->u.nativeType)
            {
            case A_nativeType::A_intTypeKind:
                std::cout << "int";
                break;
            default:
                break;
            }
            break;
        case A_dataType::A_structTypeKind:
            std::cout << *(it->second->type->u.structType);
            break;
        default:
            break;
        }
        switch(it->second->isVarArrFunc){
            case 0:
                std::cout << " scalar";
                break;
            case 1:
                std::cout << " array";
                break;
            case 2:
                std::cout << " function";
                break;
        }
        std::cout << std::endl;
    }
}


void print_token_maps(){
    std::cout << "global token2Type:" << std::endl;
    print_token_map(&g_token2Type);
    std::cout << "local token2Type:" << std::endl;
    print_token_map(&funcparam_token2Type);
}


bool comp_aA_type(aA_type target, aA_type t){
    if(!target || !t)
        return false;
    if(target->type != t->type)
        return false;
    if(target->type == A_dataType::A_nativeTypeKind)
        if(target->u.nativeType != t->u.nativeType)
            return false;
    if(target->type == A_dataType::A_structTypeKind)
        if(target->u.structType != t->u.structType)
            return false;
    return true;
}


bool comp_tc_type(tc_type target, tc_type t){
    if(!target || !t)
        return false;
    
    // arr kind first
    if (target->isVarArrFunc && t->isVarArrFunc == 0)
        return false;
    
    // if target type is nullptr, alwayse ok
    return comp_aA_type(target->type, t->type);
}


tc_type tc_Type(aA_type t, uint isVarArrFunc){
    tc_type ret = new tc_type_;
    ret->type = t;
    ret->isVarArrFunc = isVarArrFunc;
    return ret;
}


tc_type tc_Type(aA_varDecl vd){
    if(vd->kind == A_varDeclType::A_varDeclScalarKind)
        return tc_Type(vd->u.declScalar->type, 0);
    else if(vd->kind == A_varDeclType::A_varDeclArrayKind)
        return tc_Type(vd->u.declArray->type, 1);
    return nullptr;
}

/**
 * @brief 在函数参数列表、符号表中查找id是否存在，如果存在，则返回类型，否则返回nullptr
*/
tc_type get_tc_type(typeMap* typeMap, string id) {
    if (funcparam_token2Type.find(id) != funcparam_token2Type.end())
        return funcparam_token2Type[id];
    if (typeMap->find(id) != typeMap->end())
        return (*typeMap)[id];
    return nullptr;
}

/**
 * @brief 当结构体类型是structType时，检查是否定义
 * @return true: 不为structType或者已定义，false: 为structType但未定义
*/
bool check_structTypeDefinedWhenIsStructType(std::ostream& out, aA_type t){
    if(!t)
        return false;
    if (t->type != A_dataType::A_structTypeKind)
        return true;
    if(struct2Members.find(*t->u.structType) == struct2Members.end()){
        error_print(out, t->pos, "Undefined struct type!");
        return false;
    }
    return true;
}

/**
 * @brief 检查右值
*/
tc_type check_rightVal(std::ostream& out, aA_rightVal rv) {
    if (rv->kind == A_rightValType::A_arithExprValKind)
        return check_ArithExpr(out, rv->u.arithExpr);
    else { // A_boolExprValKind
        check_BoolExpr(out, rv->u.boolExpr);
        aA_type aAType = new aA_type_;
        aAType->pos = rv->pos;
        aAType->type = A_dataType::A_nativeTypeKind;
        aAType->u.nativeType = A_nativeType::A_intTypeKind;
        return tc_Type(aAType, 0);
    }
}

/**
 * @brief 进入新的作用域
*/
void begin_scope(){
    typeMap* newMap;
    // 如果当前作用域为空，则新建一个全局作用域
    // 否则，新建一个当前作用域的子作用域
    if (local_token2Type.size() == 0)
        newMap = new typeMap(g_token2Type);
    else 
        newMap = new typeMap(*local_token2Type.back());
    local_token2Type.push_back(newMap);
    current_token2Type = newMap;
}

/**
 * @brief 退出当前作用域
*/
void end_scope() {
    local_token2Type.pop_back();
    delete current_token2Type;
    current_token2Type = local_token2Type.size() == 0 ? &g_token2Type : local_token2Type.back();
}

// public functions 对外接口
void check_Prog(std::ostream& out, aA_program p)
{
    for (auto ele : p->programElements)
    {
        if(ele->kind == A_programVarDeclStmtKind){
            check_VarDecl(out, ele->u.varDeclStmt);
        }else if (ele->kind == A_programStructDefKind){
            check_StructDef(out, ele->u.structDef);
        }
    }
    
    for (auto ele : p->programElements){
        if(ele->kind == A_programFnDeclStmtKind){
            check_FnDeclStmt(out, ele->u.fnDeclStmt);
        }
        else if (ele->kind == A_programFnDefKind){
            check_FnDecl(out, ele->u.fnDef->fnDecl);
        }
    }

    for (auto ele : p->programElements){
        if(ele->kind == A_programFnDefKind){
            check_FnDef(out, ele->u.fnDef);
        }
        else if (ele->kind == A_programNullStmtKind){
            // do nothing
        }
    }

    out << "Typecheck passed!" << std::endl;
    return;
}

/**
 * 检查<变量声明、变量定义>语句
 * 
*/
void check_VarDecl(std::ostream& out, aA_varDeclStmt vd)
{
    if (!vd)
        return;
    string name;
    if (vd->kind == A_varDeclStmtType::A_varDeclKind){
        // decl only
        aA_varDecl vdecl = vd->u.varDecl;
        if(vdecl->kind == A_varDeclType::A_varDeclScalarKind){
            name = *vdecl->u.declScalar->id;
            /* fill code here*/
            // 检查是否重复声明
            if (get_tc_type(current_token2Type, name) != nullptr)
                error_print(out, vdecl->pos, "Redeclared variable!");
            // 检查结构体类型是否定义
            check_structTypeDefinedWhenIsStructType(out, vdecl->u.declScalar->type);
            // 添加当前变量到当前作用域
            current_token2Type->insert({name, tc_Type(vdecl)});
        }else if (vdecl->kind == A_varDeclType::A_varDeclArrayKind){
            name = *vdecl->u.declArray->id;
            /* fill code here*/
            // 检查是否重复声明
            if (get_tc_type(current_token2Type, name) != nullptr)
                error_print(out, vdecl->pos, "Redeclared variable!");
            // 检查结构体类型是否定义
            check_structTypeDefinedWhenIsStructType(out, vdecl->u.declArray->type);
            // 添加当前变量到当前作用域
            current_token2Type->insert({name, tc_Type(vdecl)});
            // 记录数组长度
            array2Len.insert({name, vdecl->u.declArray->len});
        }
    }
    else if (vd->kind == A_varDeclStmtType::A_varDefKind){
        // decl and def
        aA_varDef vdef = vd->u.varDef;
        if (vdef->kind == A_varDefType::A_varDefScalarKind){
            name = *vdef->u.defScalar->id;
            /* fill code here, allow omited type */
            aA_varDefScalar varDefScalar = vdef->u.defScalar;
            // 检查是否重复定义
            if (get_tc_type(current_token2Type, name) != nullptr)
                error_print(out, varDefScalar->pos, "Redefined variable!");
            // 检查结构体类型是否定义
            check_structTypeDefinedWhenIsStructType(out, varDefScalar->type);
            // 检查右值
            tc_type t = check_rightVal(out, varDefScalar->val);
            // 检查是否类型匹配（包括缺省类型）
            if (varDefScalar->type == nullptr) { // 类型缺省
                current_token2Type->insert({name, t});
            } else {
                if (!comp_tc_type(t, tc_Type(varDefScalar->type, 0)))
                    error_print(out, varDefScalar->pos, "Type mismatch!");
                // 添加当前变量到当前作用域
                current_token2Type->insert({name, tc_Type(varDefScalar->type, 0)});
            }
        }else if (vdef->kind == A_varDefType::A_varDefArrayKind){ // 数组定义
            name = *vdef->u.defArray->id;
            /* fill code here, allow omited type */
            aA_varDefArray varDefArray = vdef->u.defArray;
            // 检查是否重复定义
            if (get_tc_type(current_token2Type, name) != nullptr)
                error_print(out, varDefArray->pos, "Redefined variable!");
            // 检查结构体类型是否定义
            check_structTypeDefinedWhenIsStructType(out, varDefArray->type);
            // 检查数组长度
            if (varDefArray->len != varDefArray->vals.size())
                error_print(out, varDefArray->pos, "Array length mismatch!");
            // 检查是否类型匹配（包括缺省类型）
            if (varDefArray->type == nullptr) { // 类型缺省
                tc_type t = check_rightVal(out, varDefArray->vals[0]);
                // 检查数组元素类型是否匹配
                for (aA_rightVal rv : varDefArray->vals)
                    if (!comp_tc_type(check_rightVal(out, rv), t))
                        error_print(out, rv->pos, "Array element type mismatch!");
                // 添加当前变量到当前作用域
                current_token2Type->insert({name, tc_Type(varDefArray->type, 1)});
            } else {
                // 检查数组元素类型是否匹配
                for (aA_rightVal rv : varDefArray->vals)
                    if (!comp_tc_type(check_rightVal(out, rv), tc_Type(varDefArray->type, 0)))
                        error_print(out, rv->pos, "Array element type mismatch!");
                // 添加当前变量到当前作用域
                current_token2Type->insert({name, tc_Type(varDefArray->type, 1)});
            }
        }
    }
    return;
}


void check_StructDef(std::ostream& out, aA_structDef sd)
{
    if (!sd)
        return;
    string name = *sd->id;
    if (struct2Members.find(name) != struct2Members.end())
        error_print(out, sd->pos, "This id is already defined!");
    struct2Members[name] = &(sd->varDecls);
    return;
}


void check_FnDecl(std::ostream& out, aA_fnDecl fd)
{
    if (!fd)
        return;
    string name = *fd->id;

    // if already declared, should match
    if (func2Param.find(name) != func2Param.end()){
        // is function ret val matches
        /* fill code here */
        if (!comp_aA_type(get_tc_type(&g_token2Type, name)->type, fd->type))
            error_print(out, fd->pos, "Function return type mismatch with declaration!");
        // is function params matches decl
        /* fill code here */
        if (func2Param[name]->size() != fd->paramDecl->varDecls.size())
            error_print(out, fd->pos, "Function param number mismatch with declaration!");
        // 检查参数类型是否匹配
        for (int i = 0; i < fd->paramDecl->varDecls.size(); i++) {
            A_varDeclType decledfunDeclType = func2Param[name]->at(i)->kind;
            A_varDeclType toCheckType = fd->paramDecl->varDecls[i]->kind;
            if (decledfunDeclType != toCheckType)
                error_print(out, fd->pos, "Function param type mismatch with declaration!");
            if (decledfunDeclType == A_varDeclType::A_varDeclScalarKind) { 
                if (!comp_aA_type(func2Param[name]->at(i)->u.declScalar->type, fd->paramDecl->varDecls[i]->u.declScalar->type))
                    error_print(out, fd->pos, "Function param type mismatch with declaration!");
            } else if (decledfunDeclType == A_varDeclType::A_varDeclArrayKind) {
                if (!comp_aA_type(func2Param[name]->at(i)->u.declArray->type, fd->paramDecl->varDecls[i]->u.declArray->type))
                    error_print(out, fd->pos, "Function param type mismatch with declaration!");
            }
        }
            
    }else{
        // if not defined
        /* fill code here */
        g_token2Type[name] = tc_Type(fd->type, 2);
        func2Param[name] = &(fd->paramDecl->varDecls);
    }
    return;
}


void check_FnDeclStmt(std::ostream& out, aA_fnDeclStmt fd)
{
    if (!fd)
        return;
    check_FnDecl(out, fd->fnDecl);
    return;
}


void check_FnDef(std::ostream& out, aA_fnDef fd)
{
    if (!fd)
        return;
    // 检查是否重复定义
    for(string func : definedFunctions){
        if(func == *fd->fnDecl->id)
            error_print(out, fd->pos, "Function redefined!");
    }
    // should match if declared
    check_FnDecl(out, fd->fnDecl);
    // add params to local tokenmap, 函数参数不能和局部变量重复
    for (aA_varDecl vd : fd->fnDecl->paramDecl->varDecls)
    {
        /* fill code here */
        // 检查是否重复定义
        if (get_tc_type(current_token2Type, *vd->u.declScalar->id) != nullptr)
            error_print(out, vd->pos, "Redeclared variable in function param!");
        if (vd->kind == A_varDeclType::A_varDeclScalarKind)
            funcparam_token2Type[*vd->u.declScalar->id] = tc_Type(vd);
        else if (vd->kind == A_varDeclType::A_varDeclArrayKind)
            funcparam_token2Type[*vd->u.declArray->id] = tc_Type(vd);
    }

    /* fill code here */
    begin_scope();
    currentFunction = *fd->fnDecl->id;
    for (aA_codeBlockStmt stmt : fd->stmts)
    {
        check_CodeblockStmt(out, stmt);
        /*
        在check_CodeblockStmt中会调用check_ReturnStmt中检查
        return value type should match 
        */
    }
    end_scope();
    currentFunction = "";
    // 清除函数参数
    for (aA_varDecl vd : fd->fnDecl->paramDecl->varDecls)
    {
        if (vd->kind == A_varDeclType::A_varDeclScalarKind)
            funcparam_token2Type.erase(*vd->u.declScalar->id);
        else if (vd->kind == A_varDeclType::A_varDeclArrayKind)
            funcparam_token2Type.erase(*vd->u.declArray->id);
    }
    // 记录已定义的函数
    definedFunctions.push_back(*fd->fnDecl->id);
    return;
}


void check_CodeblockStmt(std::ostream& out, aA_codeBlockStmt cs){
    if(!cs)
        return;
    // variables declared in a code block should not duplicate with outer ones.
    switch (cs->kind)
    {
    case A_codeBlockStmtType::A_varDeclStmtKind:
        check_VarDecl(out, cs->u.varDeclStmt);
        break;
    case A_codeBlockStmtType::A_assignStmtKind:
        check_AssignStmt(out, cs->u.assignStmt);
        break;
    case A_codeBlockStmtType::A_ifStmtKind:
        check_IfStmt(out, cs->u.ifStmt);
        break;
    case A_codeBlockStmtType::A_whileStmtKind:
        check_WhileStmt(out, cs->u.whileStmt);
        break;
    case A_codeBlockStmtType::A_callStmtKind:
        check_CallStmt(out, cs->u.callStmt);
        break;
    case A_codeBlockStmtType::A_returnStmtKind:
        check_ReturnStmt(out, cs->u.returnStmt);
        break;
    default:
        break;
    }
    return;
}

// 检查赋值语句
void check_AssignStmt(std::ostream& out, aA_assignStmt as){
    if(!as)
        return;
    string name;
    // deduced type if type is omitted at decl
    tc_type deduced_type = check_rightVal(out, as->rightVal);
    switch (as->leftVal->kind)
    {
        case A_leftValType::A_varValKind:{
            name = *as->leftVal->u.id;
            /* fill code here */
            tc_type leftType = get_tc_type(current_token2Type, name);
            if (leftType == nullptr)
                error_print(out, as->pos, "Undefined variable!");
            if (leftType->isVarArrFunc == 2)
                error_print(out, as->pos, "Function cannot be assigned!");
            if (leftType->type == nullptr) // 赋值时确定类型 
                current_token2Type->find(name)->second = deduced_type;
            else if (!comp_tc_type(leftType, deduced_type))
                error_print(out, as->pos, "Type mismatch in assignment!");
        }
            break;
        case A_leftValType::A_arrValKind:{
            /* fill code here */
            name = *as->leftVal->u.arrExpr->arr->u.id;
            tc_type leftType = get_tc_type(current_token2Type, name);
            if (leftType == nullptr)
                error_print(out, as->pos, "Undefined variable in array assignment!");
            if (leftType->isVarArrFunc == 2)
                error_print(out, as->pos, "Function cannot be assigned!");
            if (!comp_tc_type(leftType, deduced_type))
                error_print(out, as->pos, "Type mismatch in array assignment!");
        }
            break;
        case A_leftValType::A_memberValKind:{
            /* fill code here */
            aA_memberExpr memberExpr = as->leftVal->u.memberExpr;
            if (memberExpr->structId->kind != A_leftValType::A_varValKind) // 不是变量类型，报错
                error_print(out, as->pos, "Not a variable type in member assignment!");
            string structId = *memberExpr->structId->u.id;
            string memberId = *memberExpr->memberId;
            tc_type structType = get_tc_type(current_token2Type, structId);
            if (structType == nullptr)
                error_print(out, as->pos, "Undefined struct!");
            if (structType->type->type != A_dataType::A_structTypeKind) // 不是结构体类型，报错
                error_print(out, as->pos, "Not a struct type in member assignment!");
            // 检查 member 是否存在
            vector<aA_varDecl>* memberDecls = struct2Members.find(*(structType->type->u.structType))->second;
            bool isExist = false;
            for (aA_varDecl vd : *memberDecls) {
                string varName;
                if (vd->kind == A_varDeclType::A_varDeclScalarKind)
                    varName = *vd->u.declScalar->id;
                else
                    varName = *vd->u.declArray->id;
                if (varName == memberId) {
                    if (!comp_tc_type(tc_Type(vd), deduced_type))
                        error_print(out, as->pos, "Type mismatch in member assignment!");
                    isExist = true;
                    break;
                }
            }
            if (!isExist)
                error_print(out, as->pos, "Undefined member!");
        }
            break;
    }
    return;
}


void check_ArrayExpr(std::ostream& out, aA_arrayExpr ae){
    if(!ae)
        return;
    string name = *ae->arr->u.id;
    // check array name
    /* fill code here */
    if (get_tc_type(current_token2Type, name) == nullptr)
        error_print(out, ae->pos, "Undefined array!");
        
    // check index
    /* fill code here */
    A_indexExprKind indexKind = ae->idx->kind;
    if (indexKind == A_indexExprKind::A_idIndexKind) {
        if (get_tc_type(current_token2Type, *ae->idx->u.id) == nullptr)
            error_print(out, ae->pos, "Undefined index variable in array!");
    } else { // A_numIndexKind
        int index = ae->idx->u.num;
        if (index < 0 || index >= array2Len[name])
            error_print(out, ae->pos, "Index out of range in array!");
    }
    return;
}

 
tc_type check_MemberExpr(std::ostream& out, aA_memberExpr me){
    // check if the member exists and return the tyep of the member
    if(!me)
        return nullptr;
    string name = *me->structId->u.id;
    // check struct name
    /* fill code here */
    tc_type structType = get_tc_type(current_token2Type, name);
    if (structType == nullptr)
        error_print(out, me->pos, "Undefined struct!");
    if (structType->type->type != A_dataType::A_structTypeKind) 
        error_print(out, me->pos, "Not a struct type in member access!");

    // check member name
    /* fill code here */
    string structTypeName = *structType->type->u.structType;
    vector<aA_varDecl>* memberDecls = struct2Members[structTypeName];
    for (aA_varDecl vd : *memberDecls) {
        string varName;
        if (vd->kind == A_varDeclType::A_varDeclScalarKind)
            varName = *vd->u.declScalar->id;
        else
            varName = *vd->u.declArray->id;
        if (varName == *me->memberId) {
            if (vd->kind == A_varDeclType::A_varDeclScalarKind)
                return tc_Type(vd->u.declScalar->type, 0);
            else
                return tc_Type(vd->u.declArray->type, 1);
        }
    }    
    return nullptr;
}


void check_IfStmt(std::ostream& out, aA_ifStmt is){
    if(!is)
        return;
    check_BoolUnit(out, is->boolUnit);
    /* fill code here, take care of variable scope */
    begin_scope();
    for(aA_codeBlockStmt s : is->ifStmts){
        check_CodeblockStmt(out, s);
    }
    end_scope();
    /* fill code here */    
    begin_scope();
    for(aA_codeBlockStmt s : is->elseStmts){
        check_CodeblockStmt(out, s);
    }
    /* fill code here */
    end_scope();
    return;
}


void check_BoolExpr(std::ostream& out, aA_boolExpr be){
    if(!be)
        return;
    switch (be->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
        check_BoolExpr(out, be->u.boolBiOpExpr->left);
        check_BoolExpr(out, be->u.boolBiOpExpr->right);
        break;
    case A_boolExprType::A_boolUnitKind:
        check_BoolUnit(out, be->u.boolUnit);
        break;
    default:
        break;
    }
    return;
}


void check_BoolUnit(std::ostream& out, aA_boolUnit bu){
    if(!bu)
        return;
    switch (bu->kind)
    {
        case A_boolUnitType::A_comOpExprKind:{
            /* fill code here */
            aA_comExpr comExpr = bu->u.comExpr;
            tc_type leftType = check_ExprUnit(out, comExpr->left);
            tc_type rightType = check_ExprUnit(out, comExpr->right);
            if (!comp_tc_type(leftType, rightType))
                error_print(out, comExpr->pos, "Type mismatch in comparison operation!");
        }
            break;
        case A_boolUnitType::A_boolExprKind:
            check_BoolExpr(out, bu->u.boolExpr);
            break;
        case A_boolUnitType::A_boolUOpExprKind:
            check_BoolUnit(out, bu->u.boolUOpExpr->cond);
            break;
        default:
            break;
    }
    return;
}


tc_type check_ExprUnit(std::ostream& out, aA_exprUnit eu){
    // return the aA_type of expr eu
    if(!eu)
        return nullptr;
    tc_type ret;
    switch (eu->kind)
    {
        case A_exprUnitType::A_idExprKind:{
            /* fill code here */
            string name = *eu->u.id;
            tc_type t = get_tc_type(current_token2Type, name);
            if (t == nullptr)
                error_print(out, eu->pos, "Undefined variable!");
            aA_type id_type = new aA_type_;
            id_type->pos = eu->pos;
            id_type->type = t->type->type;
            if (id_type->type == A_dataType::A_nativeTypeKind)
                id_type->u.nativeType = t->type->u.nativeType;
            else
                id_type->u.structType = t->type->u.structType;
            ret = tc_Type(id_type, t->isVarArrFunc);
        }
            break;
        case A_exprUnitType::A_numExprKind:{
            aA_type numt = new aA_type_;
            numt->pos = eu->pos;
            numt->type = A_dataType::A_nativeTypeKind;
            numt->u.nativeType = A_nativeType::A_intTypeKind;
            ret = tc_Type(numt, 0);
        }
            break;
        case A_exprUnitType::A_fnCallKind:{
            // check_FuncCall will check if the function is defined
            check_FuncCall(out, eu->u.callExpr);
            /* fill code here */
            string func_name = *eu->u.callExpr->fn;
            aA_type funcCall_type = new aA_type_;
            funcCall_type->pos = eu->pos;
            funcCall_type->type = g_token2Type[func_name]->type->type;
            if (funcCall_type->type == A_dataType::A_nativeTypeKind)
                funcCall_type->u.nativeType = g_token2Type[func_name]->type->u.nativeType;
            else
                funcCall_type->u.structType = g_token2Type[func_name]->type->u.structType;
            ret = tc_Type(funcCall_type, 0);
        }
            break;
        case A_exprUnitType::A_arrayExprKind:{
            check_ArrayExpr(out, eu->u.arrayExpr);
            /* fill code here */
            aA_type array_type = new aA_type_;
            array_type->pos = eu->pos;

            if (eu->u.arrayExpr->arr->kind != A_leftValType::A_varValKind)
                error_print(out, eu->pos, "Not a variable type in array access!");
            tc_type t = get_tc_type(current_token2Type, *eu->u.arrayExpr->arr->u.id);
            array_type->type = t->type->type;
            if (array_type->type == A_dataType::A_nativeTypeKind)
                array_type->u.nativeType = t->type->u.nativeType;
            else
                array_type->u.structType = t->type->u.structType;
            ret = tc_Type(array_type, 1);
        }
            break;
        case A_exprUnitType::A_memberExprKind:{
            ret = check_MemberExpr(out, eu->u.memberExpr);
        }
            break;
        case A_exprUnitType::A_arithExprKind:{
            ret = check_ArithExpr(out, eu->u.arithExpr);
        }
            break;
        case A_exprUnitType::A_arithUExprKind:{
            ret = check_ExprUnit(out, eu->u.arithUExpr->expr);
        }
            break;
    }
    return ret;
}


tc_type check_ArithExpr(std::ostream& out, aA_arithExpr ae){
    if(!ae)
        return nullptr;
    tc_type ret;
    switch (ae->kind)
    {
        case A_arithExprType::A_arithBiOpExprKind:{
            ret = check_ArithExpr(out, ae->u.arithBiOpExpr->left);
            tc_type rightTyep = check_ArithExpr(out, ae->u.arithBiOpExpr->right);
            if(ret->type->type > 0 || ret->type->type != A_dataType::A_nativeTypeKind || ret->type->u.nativeType != A_nativeType::A_intTypeKind ||
            rightTyep->type->type > 0 || rightTyep->type->type != A_dataType::A_nativeTypeKind || rightTyep->type->u.nativeType != A_nativeType::A_intTypeKind)
                error_print(out, ae->pos, "Only int can be arithmetic expression operation values!");
        }
            break;
        case A_arithExprType::A_exprUnitKind:
            ret = check_ExprUnit(out, ae->u.exprUnit);
            break;
    }
    return ret;
}


void check_FuncCall(std::ostream& out, aA_fnCall fc){
    if(!fc)
        return;
    // check if function defined
    string func_name = *fc->fn;
    /* fill code here */
    if (func2Param.find(func_name) == func2Param.end())
        error_print(out, fc->pos, "Undefined function!");
        
    // check if parameter list matches
    // 先检查数量是否匹配
    if (func2Param[func_name]->size() != fc->vals.size())
        error_print(out, fc->pos, "Function param number mismatch in function call!");
    // 再检查类型是否匹配
    for(int i = 0; i < fc->vals.size(); i++){
        /* fill code here */
        tc_type declType = tc_Type(func2Param[func_name]->at(i));
        tc_type paramType = check_rightVal(out, fc->vals[i]);
        if (!comp_tc_type(declType, paramType))
            error_print(out, fc->vals[i]->pos, "Function param type mismatch in function call!");
    }
    return ;
}


void check_WhileStmt(std::ostream& out, aA_whileStmt ws){
    if(!ws)
        return;
    check_BoolUnit(out, ws->boolUnit);
    /* fill code here, take care of variable scope */
    begin_scope();
    for(aA_codeBlockStmt s : ws->whileStmts){
        check_CodeblockStmt(out, s);
    }
    /* fill code here */
    end_scope();
    return;
}


void check_CallStmt(std::ostream& out, aA_callStmt cs){
    if(!cs)
        return;
    check_FuncCall(out, cs->fnCall);
    return;
}


void check_ReturnStmt(std::ostream& out, aA_returnStmt rs){
    if(!rs)
        return;
    if (currentFunction.empty())
        error_print(out, rs->pos, "Return statement not in function!");
    tc_type funcType = g_token2Type.find(currentFunction)->second;
    tc_type ret = check_rightVal(out, rs->retVal);
    if (ret->isVarArrFunc != 0 || !comp_aA_type(ret->type, funcType->type))
        error_print(out, rs->pos, "Return type mismatch!");
    return;
}