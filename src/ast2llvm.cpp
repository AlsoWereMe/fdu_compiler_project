#include "ast2llvm.h"
#include <vector>
#include <unordered_map>
#include <string>
#include <cassert>
#include <list>

using namespace std;
using namespace LLVMIR;

static unordered_map<string, FuncType> funcReturnMap;
static unordered_map<string, StructInfo> structInfoMap;
static unordered_map<string, Name_name *> globalVarMap;
static unordered_map<string, Temp_temp *> localVarMap;
static list<L_stm *> emit_irs;

LLVMIR::L_prog *ast2llvm(aA_program p)
{
    auto defs = ast2llvmProg_first(p);
    auto funcs = ast2llvmProg_second(p);
    vector<L_func *> funcs_block;
    for (const auto &f : funcs)
    {
        funcs_block.push_back(ast2llvmFuncBlock(f));
    }
    for (auto &f : funcs_block)
    {
        ast2llvm_moveAlloca(f);
    }
    return new L_prog(defs, funcs_block);
}

int ast2llvmRightVal_first(aA_rightVal r)
{
    if (r == nullptr)
    {
        return 0;
    }
    switch (r->kind)
    {
    case A_arithExprValKind:
    {
        return ast2llvmArithExpr_first(r->u.arithExpr);
        break;
    }
    case A_boolExprValKind:
    {
        return ast2llvmBoolExpr_first(r->u.boolExpr);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmBoolExpr_first(aA_boolExpr b)
{
    switch (b->kind)
    {
    case A_boolBiOpExprKind:
    {
        return ast2llvmBoolBiOpExpr_first(b->u.boolBiOpExpr);
        break;
    }
    case A_boolUnitKind:
    {
        return ast2llvmBoolUnit_first(b->u.boolUnit);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmBoolBiOpExpr_first(aA_boolBiOpExpr b)
{
    int l = ast2llvmBoolExpr_first(b->left);
    int r = ast2llvmBoolExpr_first(b->right);
    if (b->op == A_and)
    {
        return l && r;
    }
    else
    {
        return l || r;
    }
}

int ast2llvmBoolUOpExpr_first(aA_boolUOpExpr b)
{
    if (b->op == A_not)
    {
        return !ast2llvmBoolUnit_first(b->cond);
    }
    return 0;
}

int ast2llvmBoolUnit_first(aA_boolUnit b)
{
    switch (b->kind)
    {
    case A_comOpExprKind:
    {
        return ast2llvmComOpExpr_first(b->u.comExpr);
        break;
    }
    case A_boolExprKind:
    {
        return ast2llvmBoolExpr_first(b->u.boolExpr);
        break;
    }
    case A_boolUOpExprKind:
    {
        return ast2llvmBoolUOpExpr_first(b->u.boolUOpExpr);
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmComOpExpr_first(aA_comExpr c)
{
    auto l = ast2llvmExprUnit_first(c->left);
    auto r = ast2llvmExprUnit_first(c->right);
    switch (c->op)
    {
    case A_lt:
    {
        return l < r;
        break;
    }
    case A_le:
    {
        return l <= r;
        break;
    }
    case A_gt:
    {
        return l > r;
        break;
    }
    case A_ge:
    {
        return l >= r;
        break;
    }
    case A_eq:
    {
        return l == r;
        break;
    }
    case A_ne:
    {
        return l != r;
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmArithBiOpExpr_first(aA_arithBiOpExpr a)
{
    auto l = ast2llvmArithExpr_first(a->left);
    auto r = ast2llvmArithExpr_first(a->right);
    switch (a->op)
    {
    case A_add:
    {
        return l + r;
        break;
    }
    case A_sub:
    {
        return l - r;
        break;
    }
    case A_mul:
    {
        return l * r;
        break;
    }
    case A_div:
    {
        return l / r;
        break;
    }
    default:
        break;
    }
    return 0;
}

int ast2llvmArithUExpr_first(aA_arithUExpr a)
{
    if (a->op == A_neg)
    {
        return -ast2llvmExprUnit_first(a->expr);
    }
    return 0;
}

int ast2llvmArithExpr_first(aA_arithExpr a)
{
    switch (a->kind)
    {
    case A_arithBiOpExprKind:
    {
        return ast2llvmArithBiOpExpr_first(a->u.arithBiOpExpr);
        break;
    }
    case A_exprUnitKind:
    {
        return ast2llvmExprUnit_first(a->u.exprUnit);
        break;
    }
    default:
        assert(0);
        break;
    }
    return 0;
}

int ast2llvmExprUnit_first(aA_exprUnit e)
{
    if (e->kind == A_numExprKind)
    {
        return e->u.num;
    }
    else if (e->kind == A_arithExprKind)
    {
        return ast2llvmArithExpr_first(e->u.arithExpr);
    }
    else if (e->kind == A_arithUExprKind)
    {
        return ast2llvmArithUExpr_first(e->u.arithUExpr);
    }
    else
    {
        assert(0);
    }
    return 0;
}

std::vector<LLVMIR::L_def *> ast2llvmProg_first(aA_program p)
{
    vector<L_def *> defs;
    for (const auto &v : p->programElements)
    {
        switch (v->kind)
        {
        case A_programNullStmtKind:
        {
            break;
        }
        case A_programVarDeclStmtKind:
        {
            if (v->u.varDeclStmt->kind == A_varDeclKind)
            {
                if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclScalarKind)
                {
                    if (v->u.varDeclStmt->u.varDecl->u.declScalar->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                                             Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id), *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP, 0, *v->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declScalar->id,
                                             Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declScalar->id)));
                        TempDef def(TempType::INT_TEMP, 0);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declScalar->id, def, vector<int>()));
                    }
                }
                else if (v->u.varDeclStmt->u.varDecl->kind == A_varDeclArrayKind)
                {
                    if (v->u.varDeclStmt->u.varDecl->u.declArray->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                                             Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id), v->u.varDeclStmt->u.varDecl->u.declArray->len, *v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR, v->u.varDeclStmt->u.varDecl->u.declArray->len, *v->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDecl->u.declArray->id,
                                             Name_newname_int_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDecl->u.declArray->id), v->u.varDeclStmt->u.varDecl->u.declArray->len));
                        TempDef def(TempType::INT_PTR, v->u.varDeclStmt->u.varDecl->u.declArray->len);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDecl->u.declArray->id, def, vector<int>()));
                    }
                }
                else
                {
                    assert(0);
                }
            }
            else if (v->u.varDeclStmt->kind == A_varDefKind)
            {
                if (v->u.varDeclStmt->u.varDef->kind == A_varDefScalarKind)
                {
                    if (v->u.varDeclStmt->u.varDef->u.defScalar->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defScalar->id,
                                             Name_newname_struct(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defScalar->id), *v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType));
                        TempDef def(TempType::STRUCT_TEMP, 0, *v->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defScalar->id,
                                             Name_newname_int(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defScalar->id)));
                        TempDef def(TempType::INT_TEMP, 0);
                        vector<int> init;
                        init.push_back(ast2llvmRightVal_first(v->u.varDeclStmt->u.varDef->u.defScalar->val));
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defScalar->id, def, init));
                    }
                }
                else if (v->u.varDeclStmt->u.varDef->kind == A_varDefArrayKind)
                {
                    if (v->u.varDeclStmt->u.varDef->u.defArray->type->type == A_structTypeKind)
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defArray->id,
                                             Name_newname_struct_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defArray->id), v->u.varDeclStmt->u.varDef->u.defArray->len, *v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType));
                        TempDef def(TempType::STRUCT_PTR, v->u.varDeclStmt->u.varDef->u.defArray->len, *v->u.varDeclStmt->u.varDef->u.defArray->type->u.structType);
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id, def, vector<int>()));
                    }
                    else
                    {
                        globalVarMap.emplace(*v->u.varDeclStmt->u.varDef->u.defArray->id,
                                             Name_newname_int_ptr(Temp_newlabel_named(*v->u.varDeclStmt->u.varDef->u.defArray->id), v->u.varDeclStmt->u.varDef->u.defArray->len));
                        TempDef def(TempType::INT_PTR, v->u.varDeclStmt->u.varDef->u.defArray->len);
                        vector<int> init;
                        for (auto &el : v->u.varDeclStmt->u.varDef->u.defArray->vals)
                        {
                            init.push_back(ast2llvmRightVal_first(el));
                        }
                        defs.push_back(L_Globaldef(*v->u.varDeclStmt->u.varDef->u.defArray->id, def, init));
                    }
                }
                else
                {
                    assert(0);
                }
            }
            else
            {
                assert(0);
            }
            break;
        }
        case A_programStructDefKind:
        {
            StructInfo si;
            int off = 0;
            vector<TempDef> members;
            for (const auto &decl : v->u.structDef->varDecls)
            {
                if (decl->kind == A_varDeclScalarKind)
                {
                    if (decl->u.declScalar->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_TEMP, 0, *decl->u.declScalar->type->u.structType);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declScalar->id, info);
                        members.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_TEMP, 0);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declScalar->id, info);
                        members.push_back(def);
                    }
                }
                else if (decl->kind == A_varDeclArrayKind)
                {
                    if (decl->u.declArray->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, decl->u.declArray->len, *decl->u.declArray->type->u.structType);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declArray->id, info);
                        members.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_PTR, decl->u.declArray->len);
                        MemberInfo info(off++, def);
                        si.memberinfos.emplace(*decl->u.declArray->id, info);
                        members.push_back(def);
                    }
                }
                else
                {
                    assert(0);
                }
            }
            structInfoMap.emplace(*v->u.structDef->id, std::move(si));
            defs.push_back(L_Structdef(*v->u.structDef->id, members));
            break;
        }
        case A_programFnDeclStmtKind:
        {
            FuncType type;
            if (v->u.fnDeclStmt->fnDecl->type == nullptr)
            {
                type.type = ReturnType::VOID_TYPE;
            }
            else if (v->u.fnDeclStmt->fnDecl->type->type == A_nativeTypeKind)
            {
                type.type = ReturnType::INT_TYPE;
            }
            else if (v->u.fnDeclStmt->fnDecl->type->type == A_structTypeKind)
            {
                type.type = ReturnType::STRUCT_TYPE;
                type.structname = *v->u.fnDeclStmt->fnDecl->type->u.structType;
            }
            else
            {
                assert(0);
            }
            if (funcReturnMap.find(*v->u.fnDeclStmt->fnDecl->id) == funcReturnMap.end())
                funcReturnMap.emplace(*v->u.fnDeclStmt->fnDecl->id, std::move(type));
            vector<TempDef> args;
            for (const auto &decl : v->u.fnDeclStmt->fnDecl->paramDecl->varDecls)
            {
                if (decl->kind == A_varDeclScalarKind)
                {
                    if (decl->u.declScalar->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, 0, *decl->u.declScalar->type->u.structType);
                        args.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_TEMP, 0);
                        args.push_back(def);
                    }
                }
                else if (decl->kind == A_varDeclArrayKind)
                {
                    if (decl->u.declArray->type->type == A_structTypeKind)
                    {
                        TempDef def(TempType::STRUCT_PTR, -1, *decl->u.declArray->type->u.structType);
                        args.push_back(def);
                    }
                    else
                    {
                        TempDef def(TempType::INT_PTR, -1);
                        args.push_back(def);
                    }
                }
                else
                {
                    assert(0);
                }
            }
            defs.push_back(L_Funcdecl(*v->u.fnDeclStmt->fnDecl->id, args, type));
            break;
        }
        case A_programFnDefKind:
        {
            if (funcReturnMap.find(*v->u.fnDef->fnDecl->id) == funcReturnMap.end())
            {
                FuncType type;
                if (v->u.fnDef->fnDecl->type == nullptr)
                {
                    type.type = ReturnType::VOID_TYPE;
                }
                else if (v->u.fnDef->fnDecl->type->type == A_nativeTypeKind)
                {
                    type.type = ReturnType::INT_TYPE;
                }
                else if (v->u.fnDef->fnDecl->type->type == A_structTypeKind)
                {
                    type.type = ReturnType::STRUCT_TYPE;
                    type.structname = *v->u.fnDef->fnDecl->type->u.structType;
                }
                else
                {
                    assert(0);
                }
                funcReturnMap.emplace(*v->u.fnDef->fnDecl->id, std::move(type));
            }
            break;
        }
        default:
            assert(0);
            break;
        }
    }
    return defs;
}

std::vector<Func_local *> ast2llvmProg_second(aA_program p)
{
    vector<Func_local *> funcs;
    for (const auto &v : p->programElements)
    {
        switch (v->kind)
        {
        case A_programNullStmtKind:
        {
            break;
        }
        case A_programVarDeclStmtKind:
        {
            break;
        }
        case A_programStructDefKind:
        {
            break;
        }
        case A_programFnDeclStmtKind:
        {
            break;
        }
        case A_programFnDefKind:
        {
            funcs.push_back(ast2llvmFunc(v->u.fnDef));
            break;
        }
        default:
            assert(0);
            break;
        }
    }
    return funcs;
}

Func_local *ast2llvmFunc(aA_fnDef f)
{
    std::string func_name = *f->fnDecl->id;
    vector<Temp_temp *> params;
    emit_irs.clear();
    emit_irs.push_back(L_Label(Temp_newlabel_named(func_name)));
    localVarMap.clear();
    for (const auto &vardecl : f->fnDecl->paramDecl->varDecls)
    {
        bool is_int = false; // struct type only exists in global variable
        // scalar
        if (vardecl->kind == A_varDeclType::A_varDeclScalarKind)
        {
            // int
            if (vardecl->u.declScalar->type->type == A_dataType::A_nativeTypeKind)
            {
                is_int = true;
                Temp_temp *param = Temp_newtemp_int();
                param->len = 0;
                params.push_back(param);
                Temp_temp *temp_ptr = Temp_newtemp_int_ptr(0);
                AS_operand *arg_ptr = AS_Operand_Temp(temp_ptr);
                emit_irs.push_back(L_Alloca(arg_ptr));
                emit_irs.push_back(L_Store(AS_Operand_Temp(param), arg_ptr));
                localVarMap.emplace(*vardecl->u.declScalar->id, temp_ptr);
            }
            // struct
            else
            {
                Temp_temp *param = Temp_newtemp_struct_ptr(0, *vardecl->u.declScalar->type->u.structType);
                params.push_back(param);
            }
        }
        // array
        else
        {
            if (vardecl->u.declArray->type->type == A_structTypeKind)
            {
                params.push_back(Temp_newtemp_struct_ptr(-1, *vardecl->u.declArray->type->u.structType));
            }
            else
            {
                params.push_back(Temp_newtemp_int_ptr(-1));
            }
        }
        if (!is_int)
        {
            localVarMap.emplace(*vardecl->u.declScalar->id, params.back());
        }
    }

    for (const auto &stmt : f->stmts)
    {
        ast2llvmBlock(stmt, nullptr, nullptr);
    }

    return new Func_local(func_name, funcReturnMap[func_name], params, emit_irs);
}

void ast2llvmBlock(aA_codeBlockStmt b, Temp_label *con_label, Temp_label *bre_label)
{
    switch (b->kind)
    {
    case A_codeBlockStmtType::A_assignStmtKind:
    {
        AS_operand *leftstmt = ast2llvmLeftVal(b->u.assignStmt->leftVal);
        AS_operand *rightstmt = ast2llvmRightVal(b->u.assignStmt->rightVal);
        emit_irs.push_back(L_Store(rightstmt, leftstmt));
        break;
    }

    case A_codeBlockStmtType::A_breakStmtKind:
    {
        emit_irs.push_back(L_Jump(bre_label));
        break;
    }

    case A_codeBlockStmtType::A_callStmtKind:
    {
        std::vector<AS_operand *> args;
        for (auto &arg : b->u.callStmt->fnCall->vals)
        {
            AS_operand *temp = ast2llvmRightVal(arg);
            args.push_back(temp);
        }
        switch (funcReturnMap[*b->u.callStmt->fnCall->fn].type)
        {

        case ReturnType::VOID_TYPE:
        {
            emit_irs.push_back(L_Voidcall(*b->u.callStmt->fnCall->fn, args));
            break;
        }

        case ReturnType::INT_TYPE:
        {
            emit_irs.push_back(L_Call(*b->u.callStmt->fnCall->fn, AS_Operand_Temp(Temp_newtemp_int()), args));
            break;
        }

        case ReturnType::STRUCT_TYPE:
        {
            emit_irs.push_back(L_Call(*b->u.callStmt->fnCall->fn, AS_Operand_Temp(Temp_newtemp_struct(funcReturnMap[*b->u.callStmt->fnCall->fn].structname)), args));
            break;
        }

        default:
            assert(0);
        }
        break;
    }

    case A_codeBlockStmtType::A_continueStmtKind:
    {
        emit_irs.push_back(L_Jump(con_label));
        break;
    }

    case A_codeBlockStmtType::A_ifStmtKind:
    {
        Temp_label *t_label = Temp_newlabel();
        Temp_label *f_label = Temp_newlabel();
        AS_operand *condition = ast2llvmBoolUnit(b->u.ifStmt->boolUnit, t_label, f_label);
        emit_irs.push_back(L_Cjump(condition, t_label, f_label));
        emit_irs.push_back(L_Label(t_label));
        for (auto &stmt : b->u.ifStmt->ifStmts)
        {
            ast2llvmBlock(stmt, con_label, bre_label);
        }
        Temp_label *next_label = Temp_newlabel();
        emit_irs.push_back(L_Jump(next_label));
        emit_irs.push_back(L_Label(f_label));
        for (const auto &stmt : b->u.ifStmt->elseStmts)
        {
            ast2llvmBlock(stmt, con_label, bre_label);
        }
        emit_irs.push_back(L_Label(next_label));

        break;
    }

    case A_codeBlockStmtType::A_nullStmtKind:
    {
        break;
    }

    case A_codeBlockStmtType::A_returnStmtKind:
    {
        AS_operand *ret;
        if (b->u.returnStmt->retVal != nullptr)
            ret = ast2llvmRightVal(b->u.returnStmt->retVal);
        else
            ret = nullptr;
        emit_irs.push_back(L_Ret(ret));
        break;
    }

    case A_codeBlockStmtType::A_varDeclStmtKind:
    {
        switch (b->u.varDeclStmt->kind)
        {
        case A_varDeclStmtType::A_varDeclKind:
        {
            switch (b->u.varDeclStmt->u.varDecl->kind)
            {
            case A_varDeclType::A_varDeclScalarKind:
            {
                switch (b->u.varDeclStmt->u.varDecl->u.declScalar->type->type)
                {
                case A_dataType::A_nativeTypeKind:
                {
                    std::string varName = *b->u.varDeclStmt->u.varDecl->u.declScalar->id;
                    Temp_temp *temp = Temp_newtemp_int_ptr(0);
                    localVarMap[varName] = temp;
                    emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
                    break;
                }
                case A_dataType::A_structTypeKind:
                {
                    std::string varName = *b->u.varDeclStmt->u.varDecl->u.declScalar->id;
                    Temp_temp *temp = Temp_newtemp_struct_ptr(0, *b->u.varDeclStmt->u.varDecl->u.declScalar->type->u.structType);
                    localVarMap[varName] = temp;
                    emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
                    break;
                }

                default:
                    assert(0);
                }

                break;
            }
            case A_varDeclType::A_varDeclArrayKind:
            {
                switch (b->u.varDeclStmt->u.varDecl->u.declArray->type->type)
                {
                case A_dataType::A_nativeTypeKind:
                {
                    std::string varName = *b->u.varDeclStmt->u.varDecl->u.declArray->id;
                    Temp_temp *temp = Temp_newtemp_int_ptr(b->u.varDeclStmt->u.varDecl->u.declArray->len);
                    localVarMap[varName] = temp;
                    emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
                    /* code */
                    break;
                }

                case A_dataType::A_structTypeKind:
                {
                    std::string varName = *b->u.varDeclStmt->u.varDecl->u.declArray->id;
                    Temp_temp *temp = Temp_newtemp_struct_ptr(b->u.varDeclStmt->u.varDecl->u.declArray->len, *b->u.varDeclStmt->u.varDecl->u.declArray->type->u.structType);
                    localVarMap[varName] = temp;
                    emit_irs.push_back(L_Alloca(AS_Operand_Temp(temp)));
                    /* code */
                    break;
                }

                default:
                    break;
                }
                break;
            }

            default:
                assert(0);
                break;
            }
            break;
        }
        case A_varDeclStmtType::A_varDefKind:
        {
            switch (b->u.varDeclStmt->u.varDef->kind)
            {
            case A_varDefType::A_varDefScalarKind:
            {
                switch (b->u.varDeclStmt->u.varDef->u.defScalar->type->type)
                {
                case A_dataType::A_nativeTypeKind:
                {
                    std::string varName = *b->u.varDeclStmt->u.varDef->u.defScalar->id;
                    Temp_temp *temp = Temp_newtemp_int_ptr(0);
                    localVarMap[varName] = temp;
                    AS_operand *leftstmt = AS_Operand_Temp(temp);
                    AS_operand *rightstmt = ast2llvmRightVal(b->u.varDeclStmt->u.varDef->u.defScalar->val);
                    emit_irs.push_back(L_Alloca(leftstmt));
                    emit_irs.push_back(L_Store(rightstmt, leftstmt));
                    break;
                }
                case A_dataType::A_structTypeKind:
                {
                    std::string varName = *b->u.varDeclStmt->u.varDef->u.defScalar->id;
                    Temp_temp *temp = Temp_newtemp_struct_ptr(0, *b->u.varDeclStmt->u.varDef->u.defScalar->type->u.structType);
                    localVarMap[varName] = temp;
                    AS_operand *leftstmt = AS_Operand_Temp(temp);
                    AS_operand *rightstmt = ast2llvmRightVal(b->u.varDeclStmt->u.varDef->u.defScalar->val);
                    emit_irs.push_back(L_Alloca(leftstmt));
                    emit_irs.push_back(L_Store(rightstmt, leftstmt));
                    break;
                }

                default:
                    assert(0);
                    break;
                }
                /* code */
                break;
            }

            case A_varDefType::A_varDefArrayKind:
            {
                switch (b->u.varDeclStmt->u.varDef->u.defArray->type->type)
                {
                case A_dataType::A_nativeTypeKind:
                {
                    std::string varName = *b->u.varDeclStmt->u.varDef->u.defArray->id;
                    Temp_temp *temp = Temp_newtemp_int_ptr(b->u.varDeclStmt->u.varDef->u.defArray->len);
                    localVarMap[varName] = temp;
                    AS_operand *left = AS_Operand_Temp(temp);
                    emit_irs.push_back(L_Alloca(left));
                    int i = 0;
                    for (auto &el : b->u.varDeclStmt->u.varDef->u.defArray->vals)
                    {
                        AS_operand *element = AS_Operand_Temp(Temp_newtemp_int());
                        AS_operand *index = AS_Operand_Const(i++);
                        emit_irs.push_back(L_Gep(element, left, index));
                        AS_operand *right = ast2llvmRightVal(el);
                        emit_irs.push_back(L_Store(right, element));
                    }
                    break;
                }
                case A_dataType::A_structTypeKind:
                {
                    std::string varName = *b->u.varDeclStmt->u.varDef->u.defArray->id;
                    Temp_temp *temp = Temp_newtemp_struct_ptr(b->u.varDeclStmt->u.varDef->u.defArray->len, *b->u.varDeclStmt->u.varDef->u.defArray->type->u.structType);
                    localVarMap[varName] = temp;
                    AS_operand *left = AS_Operand_Temp(temp);
                    emit_irs.push_back(L_Alloca(left));
                    int i = 0;
                    for (auto &el : b->u.varDeclStmt->u.varDef->u.defArray->vals)
                    {
                        AS_operand *element = AS_Operand_Temp(Temp_newtemp_struct(*b->u.varDeclStmt->u.varDef->u.defArray->type->u.structType));
                        AS_operand *index = AS_Operand_Const(i++);
                        emit_irs.push_back(L_Gep(element, left, index));
                        AS_operand *right = ast2llvmRightVal(el);
                        emit_irs.push_back(L_Store(right, element));
                    }
                    break;
                }
                default:
                    break;
                }
                /* code */
                break;
            }

            default:
                assert(0);
                break;
            }
            break;
        }

        default:
            assert(0);
            break;
        }
        break;
    }

    case A_codeBlockStmtType::A_whileStmtKind:
    {
        Temp_label *test_label = Temp_newlabel();
        Temp_label *true_label = Temp_newlabel();
        Temp_label *false_label = Temp_newlabel();
        emit_irs.push_back(L_Label(test_label));
        AS_operand *condition = ast2llvmBoolUnit(b->u.whileStmt->boolUnit, true_label, false_label);
        emit_irs.push_back(L_Cjump(condition, true_label, false_label));
        emit_irs.push_back(L_Label(true_label));
        for (const auto &stmt : b->u.whileStmt->whileStmts)
        {
            ast2llvmBlock(stmt, test_label, false_label);
        }
        emit_irs.push_back(L_Jump(test_label));
        emit_irs.push_back(L_Label(false_label));
        break;
    }

    default:
        assert(0);
    }
}

AS_operand *ast2llvmRightVal(aA_rightVal r)
{
    if (r->kind == A_rightValType::A_arithExprValKind)
    {
        return ast2llvmArithExpr(r->u.arithExpr);
    }
    else if (r->kind == A_rightValType::A_boolExprValKind)
    {
        Temp_label *true_label = Temp_newlabel();
        Temp_label *false_label = Temp_newlabel();
        Temp_label *next_label = Temp_newlabel();
        AS_operand *right = ast2llvmBoolExpr(r->u.boolExpr, true_label, false_label);
        AS_operand *ret = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
        AS_operand *ret_val = AS_Operand_Temp(Temp_newtemp_int());
        emit_irs.push_back(L_Alloca(ret));
        emit_irs.push_back(L_Cjump(right, true_label, false_label));
        emit_irs.push_back(L_Label(true_label));
        emit_irs.push_back(L_Store(AS_Operand_Const(1), ret)); // true
        emit_irs.push_back(L_Jump(next_label));

        emit_irs.push_back(L_Label(false_label));
        emit_irs.push_back(L_Store(AS_Operand_Const(0), ret)); // false
        emit_irs.push_back(L_Jump(next_label));

        emit_irs.push_back(L_Label(next_label));
        emit_irs.push_back(L_Load(ret_val, ret)); // return
        return ret_val;
    }
    else
    {
        assert(0);
    }
}

AS_operand *ast2llvmLeftVal(aA_leftVal l)
{
    switch (l->kind)
    {
    case A_leftValType::A_varValKind:
    {
        std::string varName = *l->u.id;
        if (localVarMap.find(varName) != localVarMap.end())
        {
            return AS_Operand_Temp(localVarMap[varName]); // local variable
        }
        else
        {
            return AS_Operand_Name(globalVarMap[varName]); // global variable
        }
        /* code */
        break;
    }
    case A_leftValType::A_arrValKind:
    {
        AS_operand *base = ast2llvmLeftVal(l->u.arrExpr->arr);
        AS_operand *index = ast2llvmIndexExpr(l->u.arrExpr->idx);
        AS_operand *target;
        switch (base->kind)
        {
        case OperandKind::TEMP:
        {
            switch (base->u.TEMP->type)
            {
            case TempType::INT_PTR:
            {
                target = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
                /* code */
                break;
            }
            case TempType::STRUCT_PTR:
            {
                target = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, base->u.TEMP->structname));
                /* code */
                break;
            }

            default:
                assert(0);
                break;
            }
            /* code */
            break;
        }
        case OperandKind::NAME:
        {
            switch (base->u.NAME->type)
            {
            case TempType::INT_PTR:
            {
                target = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
                /* code */
                break;
            }
            case TempType::STRUCT_PTR:
            {
                target = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, base->u.NAME->structname));
                /* code */
                break;
            }

            default:
                assert(0);
                break;
            }
            /* code */
            break;
        }
        case OperandKind::ICONST:
        {
            assert(0);
            break;
        }
        default:
            assert(0);
            break;
        }
        emit_irs.push_back(L_Gep(target, base, index));
        return target;
        break;
    }
    case A_leftValType::A_memberValKind:
    {
        AS_operand *base = ast2llvmLeftVal(l->u.memberExpr->structId);
        std::string varName;
        switch (base->kind)
        {
        case OperandKind::TEMP:
            varName = base->u.TEMP->structname;
            break;
        case OperandKind::NAME:
            varName = base->u.NAME->structname;
            break;
        default:
            assert(0);
            break;
        }
        auto it = structInfoMap.find(varName);
        if (it != structInfoMap.end())
        {
            auto meminfo = it->second.memberinfos;
            std::string memberId = *l->u.memberExpr->memberId;
            auto member_it = meminfo.find(memberId);
            if (member_it != meminfo.end())
            {
                AS_operand *index = AS_Operand_Const(member_it->second.offset);
                AS_operand *target;
                switch (member_it->second.def.kind)
                {
                case TempType::INT_PTR:
                {
                    target = AS_Operand_Temp(Temp_newtemp_int_ptr(member_it->second.def.len));
                    /* code */
                    break;
                }
                case TempType::INT_TEMP:
                {
                    target = AS_Operand_Temp(Temp_newtemp_int());
                    /* code */
                    break;
                }
                case TempType::STRUCT_PTR:
                {
                    target = AS_Operand_Temp(Temp_newtemp_struct_ptr(member_it->second.def.len, member_it->second.def.structname));
                    /* code */
                    break;
                }
                case TempType::STRUCT_TEMP:
                {
                    target = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, member_it->second.def.structname));
                    /* code */
                    break;
                }

                default:
                    assert(0);
                    break;
                }
                emit_irs.push_back(L_Gep(target, base, index));
                return target;
            }
            else
            {
                assert(0);
            }
        }
        else
        {
            assert(0);
        }
        break;
    }

    default:
    {
        assert(0);
        break;
    }
    }
}

AS_operand *ast2llvmIndexExpr(aA_indexExpr index)
{
    switch (index->kind)
    {
    case A_indexExprKind::A_idIndexKind:
    {
        auto it = localVarMap.find(*index->u.id);
        if (it != localVarMap.end())
        {
            switch (it->second->type)
            {
            case TempType::INT_PTR:
            {
                AS_operand *temp = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(temp, AS_Operand_Temp(it->second)));
                return temp;
                /* code */
                break;
            }
            case TempType::STRUCT_PTR:
            {
                AS_operand *temp = AS_Operand_Temp(Temp_newtemp_struct(it->second->structname));
                emit_irs.push_back(L_Load(temp, AS_Operand_Temp(it->second)));
                return temp;
                /* code */
                break;
            }

            default:
                assert(0);
                break;
            }
        }
        else
        {
            auto it_global = globalVarMap.find(*index->u.id);
            if (it_global != globalVarMap.end())
            {
                AS_operand *temp = AS_Operand_Name(globalVarMap[*index->u.id]);
                AS_operand *target;
                if (globalVarMap[*index->u.id]->type == TempType::INT_TEMP)
                {
                    target = AS_Operand_Temp(Temp_newtemp_int());
                    emit_irs.push_back(L_Load(target, temp));
                }
                else
                    target = temp;
                return target;
            }
            else
            {
                assert(0);
            }
        }
    }
    case A_indexExprKind::A_numIndexKind:
    {
        return AS_Operand_Const(index->u.num);
    }
    default:
        assert(0);
        break;
    }
}

AS_operand *ast2llvmBoolExpr(aA_boolExpr b, Temp_label *true_label, Temp_label *false_label)
{
    switch (b->kind)
    {
    case A_boolExprType::A_boolBiOpExprKind:
    {
        /* code */
        return ast2llvmBoolBiOpExpr(b->u.boolBiOpExpr, true_label, false_label);
        break;
    }
    case A_boolExprType::A_boolUnitKind:
    {
        /* code */
        return ast2llvmBoolUnit(b->u.boolUnit, true_label, false_label);
        break;
    }

    default:
        assert(0);
        break;
    }
}

AS_operand *ast2llvmBoolBiOpExpr(aA_boolBiOpExpr b, Temp_label *true_label, Temp_label *false_label)
{
    AS_operand *leftstmt = ast2llvmBoolExpr(b->left, true_label, false_label);
    switch (b->op)
    {
    case A_boolBiOp::A_and:
    {
        Temp_label *and_true = Temp_newlabel();
        emit_irs.push_back(L_Cjump(leftstmt, and_true, false_label));
        emit_irs.push_back(L_Label(and_true));
        break;
    }
    case A_boolBiOp::A_or:
    {
        Temp_label *or_false = Temp_newlabel();
        emit_irs.push_back(L_Cjump(leftstmt, true_label, or_false));
        emit_irs.push_back(L_Label(or_false));
        break;
    }
    default:
        assert(0);
    }
    AS_operand *rightstmt = ast2llvmBoolExpr(b->right, true_label, false_label);
    return rightstmt;
}

AS_operand *ast2llvmBoolUnit(aA_boolUnit b, Temp_label *true_label, Temp_label *false_label)
{
    switch (b->kind)
    {
    case A_boolUnitType::A_boolExprKind:
        return ast2llvmBoolExpr(b->u.boolExpr, true_label, false_label);
        break;

    case A_boolUnitType::A_boolUOpExprKind:
        return ast2llvmBoolUnit(b->u.boolUOpExpr->cond, false_label, true_label); // not
        break;

    case A_boolUnitType::A_comOpExprKind:
        return ast2llvmComOpExpr(b->u.comExpr, true_label, false_label);
        break;

    default:
        assert(0);
        break;
    }
}

AS_operand *ast2llvmComOpExpr(aA_comExpr c, Temp_label *true_label, Temp_label *false_label)
{
    AS_operand *left = ast2llvmExprUnit(c->left);
    AS_operand *right = ast2llvmExprUnit(c->right);
    AS_operand *ret = AS_Operand_Temp(Temp_newtemp_int());
    switch (c->op)
    {
    case A_comOp::A_eq:
        emit_irs.push_back(L_Cmp(L_relopKind::T_eq, left, right, ret));
        /* code */
        break;

    case A_comOp::A_ge:
        emit_irs.push_back(L_Cmp(L_relopKind::T_ge, left, right, ret));
        /* code */
        break;

    case A_comOp::A_gt:
        emit_irs.push_back(L_Cmp(L_relopKind::T_gt, left, right, ret));
        /* code */
        break;

    case A_comOp::A_le:
        emit_irs.push_back(L_Cmp(L_relopKind::T_le, left, right, ret));
        /* code */
        break;

    case A_comOp::A_lt:
        emit_irs.push_back(L_Cmp(L_relopKind::T_lt, left, right, ret));
        /* code */
        break;

    case A_comOp::A_ne:
        emit_irs.push_back(L_Cmp(L_relopKind::T_ne, left, right, ret));
        /* code */
        break;

    default:
        assert(0);
        break;
    }
    return ret;
}

AS_operand *ast2llvmArithBiOpExpr(aA_arithBiOpExpr a)
{
    AS_operand *left = ast2llvmArithExpr(a->left);
    AS_operand *right = ast2llvmArithExpr(a->right);
    AS_operand *ret = AS_Operand_Temp(Temp_newtemp_int());
    switch (a->op)
    {
    case A_arithBiOp::A_add:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_plus, left, right, ret));
        /* code */
        break;
    }
    case A_arithBiOp::A_sub:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_minus, left, right, ret));
        /* code */
        break;
    }
    case A_arithBiOp::A_mul:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_mul, left, right, ret));
        /* code */
        break;
    }
    case A_arithBiOp::A_div:
    {
        emit_irs.push_back(L_Binop(L_binopKind::T_div, left, right, ret));
        /* code */
        break;
    }

    default:
        assert(0);
        break;
    }
    return ret;
}

AS_operand *ast2llvmArithUExpr(aA_arithUExpr a)
{
    // neg
    AS_operand *expr = ast2llvmExprUnit(a->expr);
    AS_operand *ret = AS_Operand_Temp(Temp_newtemp_int());
    emit_irs.push_back(L_Binop(L_binopKind::T_minus, AS_Operand_Const(0), expr, ret));
    return ret;
}

AS_operand *ast2llvmArithExpr(aA_arithExpr a)
{
    switch (a->kind)
    {
    case A_arithExprType::A_arithBiOpExprKind:
        return ast2llvmArithBiOpExpr(a->u.arithBiOpExpr);
        break;

    case A_arithExprType::A_exprUnitKind:
        return ast2llvmExprUnit(a->u.exprUnit);
        break;

    default:
        assert(0);
        break;
    }
}

AS_operand *ast2llvmExprUnit(aA_exprUnit e)
{
    switch (e->kind)
    {
    case A_exprUnitType::A_arithExprKind:
    {
        return ast2llvmArithExpr(e->u.arithExpr);
        /* code */
        break;
    }
    case A_exprUnitType::A_arithUExprKind:
    {
        return ast2llvmArithUExpr(e->u.arithUExpr);
        /* code */
        break;
    }
    case A_exprUnitType::A_arrayExprKind:
    {
        AS_operand *base = ast2llvmLeftVal(e->u.arrayExpr->arr);
        AS_operand *index = ast2llvmIndexExpr(e->u.arrayExpr->idx);
        AS_operand *target;
        switch (base->kind)
        {
        case OperandKind::TEMP:
        {
            switch (base->u.TEMP->type)
            {
            case TempType::INT_PTR:
            {
                target = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
                /* code */
                break;
            }
            case TempType::STRUCT_PTR:
            {
                target = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, base->u.TEMP->structname));
                /* code */
                break;
            }

            default:
                assert(0);
                break;
            }
            /* code */
            break;
        }
        case OperandKind::NAME:
        {
            switch (base->u.NAME->type)
            {
            case TempType::INT_PTR:
            {
                target = AS_Operand_Temp(Temp_newtemp_int_ptr(0));
                /* code */
                break;
            }
            case TempType::STRUCT_PTR:
            {
                target = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, base->u.NAME->structname));
                /* code */
                break;
            }

            default:
                assert(0);
                break;
            }
            /* code */
            break;
        }
        case OperandKind::ICONST:
        {
            assert(0);
            break;
        }
        default:
            assert(0);
            break;
        }
        emit_irs.push_back(L_Gep(target, base, index));
        AS_operand *new_ptr = AS_Operand_Temp(Temp_newtemp_int());
        emit_irs.push_back(L_Load(new_ptr, target));
        return new_ptr;
    }
    case A_exprUnitType::A_fnCallKind:
    {
        vector<AS_operand *> args;
        for (int i = 0; i < e->u.callExpr->vals.size(); i++)
        {
            AS_operand *arg_init = ast2llvmRightVal(e->u.callExpr->vals[i]);
            args.push_back(arg_init);
        }
        AS_operand *ret;
        if (funcReturnMap[*e->u.callExpr->fn].type == ReturnType::INT_TYPE)
        {
            ret = AS_Operand_Temp(Temp_newtemp_int());
        }
        else if (funcReturnMap[*e->u.callExpr->fn].type == ReturnType::STRUCT_TYPE)
        {
            ret = AS_Operand_Temp(Temp_newtemp_struct(funcReturnMap[*e->u.callExpr->fn].structname));
        }
        else
        {
            assert(0);
        }
        emit_irs.push_back(L_Call(*e->u.callExpr->fn, ret, args));
        return ret;
        /* code */
        break;
    }
    case A_exprUnitType::A_idExprKind:
    {
        if (localVarMap.find(*e->u.id) != localVarMap.end())
        {
            Temp_temp *temp = localVarMap[*e->u.id];
            AS_operand *oper = AS_Operand_Temp(temp);
            if (temp->type == TempType::INT_PTR && temp->len == 0)
            {
                AS_operand *oper2 = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(oper2, oper));
                return oper2;
            }
            else
                return oper;
        }
        else if (globalVarMap.find(*e->u.id) != globalVarMap.end())
        {
            AS_operand *varName = AS_Operand_Name(globalVarMap[*e->u.id]);
            AS_operand *target;
            if (globalVarMap[*e->u.id]->type == TempType::INT_TEMP)
            {
                target = AS_Operand_Temp(Temp_newtemp_int());
                emit_irs.push_back(L_Load(target, varName));
            }
            else
                target = varName;
            return target;
        }
        else
        {
            assert(0);
        }
        /* code */
        break;
    }
    case A_exprUnitType::A_memberExprKind:
    {
        AS_operand *base = ast2llvmLeftVal(e->u.memberExpr->structId);
        std::string varName;
        switch (base->kind)
        {
        case OperandKind::TEMP:
        {
            varName = base->u.TEMP->structname;
            auto it = structInfoMap.find(varName);
            if (it != structInfoMap.end())
            {
                auto meminfo = it->second.memberinfos;
                std::string memberId = *e->u.memberExpr->memberId;
                auto member_it = meminfo.find(memberId);
                if (member_it != meminfo.end())
                {
                    AS_operand *index = AS_Operand_Const(member_it->second.offset);
                    AS_operand *target = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, base->u.TEMP->structname));
                    emit_irs.push_back(L_Gep(target, base, index));
                    AS_operand *new_ptr;
                    switch (member_it->second.def.kind)
                    {
                    case TempType::INT_PTR:
                    {
                        new_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(member_it->second.def.len));
                        /* code */
                        break;
                    }
                    case TempType::INT_TEMP:
                    {
                        new_ptr = AS_Operand_Temp(Temp_newtemp_int());
                        /* code */
                        break;
                    }
                    case TempType::STRUCT_PTR:
                    {
                        new_ptr = AS_Operand_Temp(Temp_newtemp_struct_ptr(member_it->second.def.len, member_it->second.def.structname));
                        /* code */
                        break;
                    }
                    case TempType::STRUCT_TEMP:
                    {
                        new_ptr = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, member_it->second.def.structname));
                        /* code */
                        break;
                    }

                    default:
                        assert(0);
                        break;
                    }
                    emit_irs.push_back(L_Load(new_ptr, target));
                    return new_ptr;
                }
                else
                {
                    assert(0);
                }
            }
            else
            {
                assert(0);
            }
            break;
        }

        case OperandKind::NAME:
        {
            varName = base->u.NAME->structname;
            auto it = structInfoMap.find(varName);
            if (it != structInfoMap.end())
            {
                auto meminfo = it->second.memberinfos;
                std::string memberId = *e->u.memberExpr->memberId;
                auto member_it = meminfo.find(memberId);
                if (member_it != meminfo.end())
                {
                    AS_operand *index = AS_Operand_Const(member_it->second.offset);
                    AS_operand *target = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, base->u.NAME->structname));
                    emit_irs.push_back(L_Gep(target, base, index));
                    AS_operand *new_ptr;
                    switch (member_it->second.def.kind)
                    {
                    case TempType::INT_PTR:
                    {
                        new_ptr = AS_Operand_Temp(Temp_newtemp_int_ptr(member_it->second.def.len));
                        /* code */
                        break;
                    }
                    case TempType::INT_TEMP:
                    {
                        new_ptr = AS_Operand_Temp(Temp_newtemp_int());
                        /* code */
                        break;
                    }
                    case TempType::STRUCT_PTR:
                    {
                        new_ptr = AS_Operand_Temp(Temp_newtemp_struct_ptr(member_it->second.def.len, member_it->second.def.structname));
                        /* code */
                        break;
                    }
                    case TempType::STRUCT_TEMP:
                    {
                        new_ptr = AS_Operand_Temp(Temp_newtemp_struct_ptr(0, member_it->second.def.structname));
                        /* code */
                        break;
                    }

                    default:
                        assert(0);
                        break;
                    }
                    emit_irs.push_back(L_Load(new_ptr, target));
                    return new_ptr;
                }
                else
                {
                    assert(0);
                }
            }
            else
            {
                assert(0);
            }
            break;
        }
        default:
            assert(0);
            break;
        }
        break;
    }
    case A_exprUnitType::A_numExprKind:
    {
        return AS_Operand_Const(e->u.num);
        /* code */
        break;
    }

    default:
        break;
    }
}

LLVMIR::L_func *ast2llvmFuncBlock(Func_local *f)
{
    list<L_block *> blocks;
    list<L_stm *> irs;
    for (auto &ir : f->irs)
    {
        switch (ir->type)
        {
        case L_StmKind::T_LABEL:
            if (irs.size() != 0)
            {
                irs.push_back(L_Jump(ir->u.LABEL->label));
                blocks.push_back(L_Block(irs));
                irs.clear();
            }
            irs.push_back(ir);
            break;

        case L_StmKind::T_CJUMP:
        case L_StmKind::T_JUMP:
        case L_StmKind::T_RETURN:
            irs.push_back(ir);
            if (irs.front()->type != L_StmKind::T_LABEL)
            {
                irs.push_front(L_Label(Temp_newlabel()));
            }
            blocks.push_back(L_Block(irs));
            irs.clear();
            break;

        default:
            irs.push_back(ir);
            break;
        }

        if (ir == f->irs.back())
        {
            if (irs.size() != 0)
            {
                if (irs.front()->type != L_StmKind::T_LABEL)
                {
                    irs.push_front(L_Label(Temp_newlabel()));
                }
                if (f->ret.type == ReturnType::VOID_TYPE)
                    irs.push_back(L_Ret(nullptr));
                else
                    irs.push_back(L_Ret(AS_Operand_Const(0)));
                blocks.push_back(L_Block(irs));
                irs.clear();
            }
        }
    }
    return new L_func(f->name, f->ret, f->args, blocks);
}

void ast2llvm_moveAlloca(LLVMIR::L_func *f)
{
    auto first_block = f->blocks.front();
    for (auto i = ++f->blocks.begin(); i != f->blocks.end(); ++i)
    {
        for (auto it = (*i)->instrs.begin(); it != (*i)->instrs.end();)
        {
            if ((*it)->type == L_StmKind::T_ALLOCA)
            {
                first_block->instrs.insert(++first_block->instrs.begin(), *it);
                it = (*i)->instrs.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}