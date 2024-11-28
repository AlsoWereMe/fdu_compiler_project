%{
#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();
}

%}

// TODO:
// your parser

%union {
	A_pos pos; //position information
	A_type type;
	A_varDecl varDecl;
	A_varDef varDef;
	A_rightVal rightVal;
	A_arithExpr arithExpr;
	A_boolExpr boolExpr;
	A_arithBiOpExpr arithBiOpExpr;
	A_arithUExpr arithUExpr;
	A_exprUnit exprUnit;
	A_fnCall fnCall;
	A_indexExpr indexExpr;
	A_arrayExpr arrayExpr;
	A_memberExpr memberExpr;
	A_boolUnit boolUnit;
	A_boolBiOpExpr boolBiOpExpr;
	A_boolUOpExpr boolUOpExpr;
	A_comExpr comExpr;
	A_leftVal leftVal;
	A_assignStmt assignStmt;
	A_rightValList rightValList;
	A_varDefScalar varDefScalar;
	A_varDefArray varDefArray;
	A_varDeclScalar varDeclScalar;
	A_varDeclArray varDeclArray;
	A_varDeclStmt varDeclStmt;
	A_varDeclList varDeclList;
	A_structDef structDef;
	A_paramDecl paramDecl;
	A_fnDecl fnDecl;
	A_fnDef fnDef;
	A_codeBlockStmt codeBlockStmt;
	A_ifStmt ifStmt;
	A_whileStmt whileStmt;
	A_fnDeclStmt fnDeclStmt;
	A_callStmt callStmt;
	A_returnStmt returnStmt;
	A_programElement programElement;
	A_codeBlockStmtList codeBlockStmtList;
	A_programElementList programElementList;
	A_program program;
	A_tokenId tokenId;
	A_tokenNum tokenNum;
}

%token <pos> ADD          // +
%token <pos> SUB          // -
%token <pos> MUL          // *
%token <pos> DIV          // /
%token <pos> SEMICOLON    // ;
%token <pos> DOT					// .
%token <pos> COLON    		// :
%token <pos> COMMA        // ,
%token <pos> LPAR      		// (
%token <pos> RPAR      		// )
%token <pos> LBRACKET     // [
%token <pos> RBRACKET     // ]
%token <pos> LBRACE       // {
%token <pos> RBRACE       // }
%token <pos> ASSIGN       // =
%token <pos> ARROW				// ->
%token <pos> LT           // <
%token <pos> GT           // >
%token <pos> LE           // <=
%token <pos> GE           // >=
%token <pos> EQ           // ==
%token <pos> NEQ          // !=
%token <pos> AND          // &&
%token <pos> OR           // ||
%token <pos> NOT          // !
%token <pos> LET          // let
%token <pos> FN           // fn
%token <pos> STRUCT       // struct
%token <pos> RETURN          // ret
%token <pos> CONTINUE     // continue
%token <pos> BREAK        // break
%token <pos> IF           // if
%token <pos> ELSE         // else
%token <pos> WHILE        // while
%token <pos> INT          // int
// %token <pos> COMMENT_LINE // //
// %token <pos> COMMENT_BLOCK_START // /*
// %token <pos> COMMENT_BLOCK_END   // */

%token <tokenNum> NUM
%token <tokenId> ID

%type	<type> Type;
%type	<varDecl> VarDecl;
%type	<varDecl> FieldDecl;
%type	<varDef> VarDef;
%type	<rightVal> RightVal;
%type	<arithExpr> ArithExpr;
%type	<boolExpr> BoolExpr;
%type	<arithBiOpExpr> ArithBiOpExpr;
%type	<exprUnit> ExprUnit;
%type	<fnCall> Fncall;
%type	<indexExpr> IndexExpr;
%type	<arrayExpr> ArrayExpr;
%type	<memberExpr> MemberExpr;
%type	<boolUnit> BoolUnit;
%type	<boolUnit> BoolUnit_;
%type	<boolBiOpExpr> BoolBiOpExpr;
%type	<boolUOpExpr> BoolUOpExpr;
%type	<comExpr> ComExpr;
%type	<leftVal> LeftVal;
%type	<assignStmt> AssignStmt;
%type	<rightValList> RightValList;
%type	<varDefScalar> VarDefScalar;
%type	<varDefArray> VarDefArray;
%type	<varDeclScalar> VarDeclScalar;
%type	<varDeclArray> VarDeclArray;
%type	<varDeclStmt> VarDeclStmt;
%type	<varDeclList> VarDeclList;
%type <varDeclList> FieldDeclList;
%type	<structDef> StructDef;
%type	<paramDecl> ParamDecl;
%type	<fnDecl> FnDecl;
%type	<fnDef> FnDef;
%type	<codeBlockStmt> CodeBlockStmt;
%type	<ifStmt> IfStmt;
%type	<whileStmt> WhileStmt;
%type	<fnDeclStmt> FnDeclStmt;
%type	<callStmt> CallStmt;
%type	<returnStmt> ReturnStmt;
%type	<programElement> ProgramElement;
%type	<codeBlockStmtList> CodeBlockStmtList;
%type	<programElementList> ProgramElementList;
%type	<program> Program;

%left OR       // || 逻辑或
%left AND      // && 逻辑与
%left EQ NEQ    // ==  !=
%left LT LE GT GE // <  <=  >  >=
%left ADD SUB  // +  -
%left MUL DIV  // *  /
%right NOT     // ! 一元运算符

%start Program

%%                   /* beginning of rules section */

Program: ProgramElementList 
{  
  root = A_Program($1);
  $$ = A_Program($1);
}
;

ProgramElementList: ProgramElement ProgramElementList
{
  $$ = A_ProgramElementList($1, $2);
}
|
{
  $$ = nullptr;
}
;

ProgramElement: VarDeclStmt
{
  $$ = A_ProgramVarDeclStmt($1->pos, $1);
}
| StructDef
{
  $$ = A_ProgramStructDef($1->pos, $1);
}
| FnDeclStmt
{
  $$ = A_ProgramFnDeclStmt($1->pos, $1);
}
| FnDef
{
  $$ = A_ProgramFnDef($1->pos, $1);
}
| SEMICOLON
{
  $$ = A_ProgramNullStmt($1);
}
;

ArithExpr: ArithBiOpExpr{
	$$ = A_ArithBiOp_Expr($1->pos, $1);
}
| ExprUnit
{
  $$ = A_ExprUnit($1->pos, $1);
}
;

ArithBiOpExpr: ArithExpr ADD ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_add, $1, $3);
}
| ArithExpr SUB ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_sub, $1, $3);
}
| ArithExpr MUL ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_mul, $1, $3);
}
| ArithExpr DIV ArithExpr
{
  $$ = A_ArithBiOpExpr($1->pos, A_div, $1, $3);
}
;


ExprUnit: NUM{
	$$ = A_NumExprUnit($1->pos, $1->num);
}
| SUB NUM{
		$$ = A_NumExprUnit($1, -1*$2->num);
}
| ID{
	$$ = A_IdExprUnit($1->pos, $1->id);
}
| LPAR ArithExpr RPAR{
	$$ = A_ArithExprUnit($1, $2);
}
| Fncall{
	$$ = A_CallExprUnit($1->pos, $1);
}
| ArrayExpr{
	$$ = A_ArrayExprUnit($1->pos, $1);
}
| MemberExpr{
	$$ = A_MemberExprUnit($1->pos, $1);
}
;

ArrayExpr: LeftVal IndexExpr{
	$$ = A_ArrayExpr($1->pos, $1, $2);
};

MemberExpr: LeftVal DOT ID
{
    $$ = A_MemberExpr($1->pos, $1, $3->id);  
}
;

IndexExpr: LBRACKET NUM RBRACKET{
	$$ = A_NumIndexExpr($2->pos, $2->num);
}
| LBRACKET ID RBRACKET{
	$$ = A_IdIndexExpr($2->pos, $2->id);
}
;


BoolExpr: BoolBiOpExpr{
	$$ = A_BoolBiOp_Expr($1->pos, $1);
}
|BoolUnit{
	$$ = A_BoolExpr($1->pos, $1);
}
;

BoolBiOpExpr:  BoolExpr AND BoolExpr {
	$$ = A_BoolBiOpExpr($1->pos, A_and, $1, $3);
}
| BoolExpr OR BoolExpr{
	$$ = A_BoolBiOpExpr($1->pos, A_or, $1, $3);
}
;

BoolUnit:LPAR ComExpr RPAR{
	$$ = A_ComExprUnit($1, $2);
}
| BoolUOpExpr{
	$$ = A_BoolUOpExprUnit($1->pos, $1);
}
| LPAR BoolExpr RPAR{
	$$ = A_BoolExprUnit($1, $2);
}
;

BoolUOpExpr:NOT BoolUnit{
	$$ = A_BoolUOpExpr($1, A_not,$2);
}
;

ComExpr: ExprUnit GT ExprUnit{
	$$ = A_ComExpr($1->pos, A_gt, $1, $3);
}
|ExprUnit LT ExprUnit{
	$$ = A_ComExpr($1->pos, A_lt, $1, $3);
}
|ExprUnit GE ExprUnit{
	$$ = A_ComExpr($1->pos, A_ge, $1, $3);
}
|ExprUnit LE ExprUnit{
	$$ = A_ComExpr($1->pos, A_le, $1, $3);
}
|ExprUnit EQ ExprUnit{
	$$ = A_ComExpr($1->pos, A_eq, $1, $3);
}
|ExprUnit NEQ ExprUnit{
	$$ = A_ComExpr($1->pos, A_ne, $1, $3);
}
;

AssignStmt: LeftVal ASSIGN RightVal SEMICOLON{
	$$ = A_AssignStmt($1->pos, $1, $3);
}
;

LeftVal: ID{
	$$ = A_IdExprLVal($1->pos, $1->id);
}
| ArrayExpr{
	$$ = A_ArrExprLVal($1->pos, $1);
}
| MemberExpr{
	$$ = A_MemberExprLVal($1->pos, $1);
}
;

RightVal: ArithExpr{
	$$ = A_ArithExprRVal($1->pos, $1);
}
;

Fncall: ID LPAR RightValList RPAR{
	$$ = A_FnCall($1->pos, $1->id, $3);
}
;

RightValList: RightVal COMMA RightValList{
	$$ = A_RightValList($1,$3);
}
| RightVal{
	$$ = A_RightValList($1,NULL);
}
| {
	$$ = NULL;
}
;

VarDeclStmt: LET VarDecl SEMICOLON{
	$$ = A_VarDeclStmt($2->pos, $2);
}
|LET VarDef SEMICOLON{
	$$ = A_VarDefStmt($2->pos, $2);
}
;

VarDecl:VarDeclScalar{
	$$ = A_VarDecl_Scalar($1->pos, $1);

}
| VarDeclArray{
	$$ = A_VarDecl_Array($1->pos, $1);
}
;

VarDeclScalar:ID COLON Type{
	$$ = A_VarDeclScalar($1->pos, $1->id, $3);
}
| ID {
	$$ = A_VarDeclScalar($1->pos, $1->id, nullptr);
}
;

VarDeclArray:ID LBRACKET NUM RBRACKET COLON Type{
	$$ = A_VarDeclArray($1->pos, $1->id, $3->num, $6);
}
| ID LBRACKET NUM RBRACKET{
	$$ = A_VarDeclArray($1->pos, $1->id, $3->num, nullptr);
}
;


VarDef:VarDefScalar{
	$$ = A_VarDef_Scalar($1->pos, $1);
}
| VarDefArray{
	$$ = A_VarDef_Array($1->pos, $1);
}
;

VarDefScalar: ID COLON Type ASSIGN RightVal{
	$$ = A_VarDefScalar($1->pos, $1->id, $3, $5);
} 
| ID ASSIGN RightVal{
	$$ = A_VarDefScalar($1->pos, $1->id, nullptr, $3);
}

VarDefArray: ID LBRACKET NUM RBRACKET COLON Type ASSIGN LBRACE RightValList RBRACE{
	$$ = A_VarDefArray($1->pos, $1->id, $3->num, $6, $9);
}
| ID LBRACKET NUM RBRACKET ASSIGN LBRACE RightValList RBRACE{
	$$ = A_VarDefArray($1->pos, $1->id, $3->num, nullptr, $7);
}
;

Type: INT{
	$$ =  A_NativeType($1, A_intTypeKind);
}
| ID{
	$$ = A_StructType($1->pos, $1->id);
}
;

StructDef: STRUCT ID LBRACE FieldDeclList RBRACE{
	$$ = A_StructDef($1, $2->id, $4);
}
;

FieldDecl:ID COLON Type{
	$$ = A_VarDecl_Scalar($1->pos, A_VarDeclScalar($1->pos, $1->id, $3));
}
|ID LBRACKET NUM RBRACKET COLON Type{
	$$ = A_VarDecl_Array($1->pos, A_VarDeclArray($1->pos, $1->id, $3->num, $6));
}

FieldDeclList: FieldDecl COMMA FieldDeclList{
	$$ = A_VarDeclList($1, $3);
}
| FieldDecl{
	$$ = A_VarDeclList($1, NULL);
}
| {
	$$ = NULL;
}
;

VarDeclList: VarDecl COMMA VarDeclList{
	$$ = A_VarDeclList($1, $3);
}
| VarDecl{
	$$ = A_VarDeclList($1, NULL);
}
| {
	$$ = NULL;
}
;

FnDeclStmt: FnDecl SEMICOLON{
	$$ = A_FnDeclStmt($1->pos,$1);
}
;

FnDecl: FN ID LPAR ParamDecl RPAR{
	$$ = A_FnDecl($1, $2->id, $4, nullptr);
}
| FN ID LPAR ParamDecl RPAR ARROW Type{
	$$ = A_FnDecl($1, $2->id, $4, $7);
}
;

ParamDecl: VarDeclList{
	$$ = A_ParamDecl($1);
}
;

FnDef: FnDecl LBRACE CodeBlockStmtList RBRACE{
	$$ = A_FnDef($1->pos, $1, $3);
}
;

CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList {
	$$ = A_CodeBlockStmtList($1, $2);
}
|
{
	$$ = nullptr;
}
|SEMICOLON
{
	$$ = nullptr;
}
;

CodeBlockStmt: VarDeclStmt{
	$$ = A_BlockVarDeclStmt($1->pos, $1);
}
| AssignStmt{
	$$ = A_BlockAssignStmt($1->pos, $1);
}
| CallStmt{
	$$ = A_BlockCallStmt($1->pos, $1);
}
| IfStmt{
	$$ = A_BlockIfStmt($1->pos, $1);
}
| WhileStmt{
	$$ = A_BlockWhileStmt($1->pos, $1);
}
| ReturnStmt{
	$$ = A_BlockReturnStmt($1->pos, $1);
}
| CONTINUE SEMICOLON{
	$$ = A_BlockContinueStmt($1);
}
| BREAK SEMICOLON{
	$$ = A_BlockBreakStmt($1);
}
;

ReturnStmt: RETURN RightVal SEMICOLON{
	$$ = A_ReturnStmt($1, $2);
}
|RETURN SEMICOLON{
	$$ = A_ReturnStmt($1, nullptr);
}
;

CallStmt: Fncall SEMICOLON{
	$$ = A_CallStmt($1->pos, $1);
}
;

BoolUnit_:LPAR ComExpr RPAR{
	$$ = A_ComExprUnit($1, $2);
}
| LPAR BoolUOpExpr %prec RPAR{
	$$ = A_BoolUOpExprUnit($1, $2);
}
| LPAR BoolExpr RPAR{
	$$ = A_BoolExprUnit($1, $2);
}
;

IfStmt: IF BoolUnit_ LBRACE CodeBlockStmtList RBRACE{
	$$ = A_IfStmt($1, $2, $4, nullptr);
}
| IF BoolUnit_ LBRACE CodeBlockStmtList RBRACE ELSE LBRACE CodeBlockStmtList RBRACE{
	$$ = A_IfStmt($1, $2, $4, $8);
}
;

WhileStmt: WHILE BoolUnit_ LBRACE CodeBlockStmtList RBRACE{
	$$ = A_WhileStmt($1, $2, $4);
}
;


%%

extern "C"{
void yyerror(const char * s)
{
  fprintf(stderr, "%s\n",s);
}
int yywrap()
{
  return(1);
}
}