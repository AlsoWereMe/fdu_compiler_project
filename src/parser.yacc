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
  A_pos pos;
  A_tokenId tokenId;
  A_tokenNum tokenNum;
  A_type type;
  A_program program;
  A_programElementList programElementList;
  A_programElement programElement;
  A_arithExpr arithExpr;
  A_exprUnit exprUnit;
  A_arithUExpr arithUExpr;
  A_arrayExpr arrayExpr;
  A_memberExpr memberExpr;
  A_boolExpr boolExpr;
  A_boolUnit boolUnit;
  A_comExpr comExpr;
  A_boolUOpExpr boolUOpExpr;
  A_leftVal leftVal;
  A_rightVal rightVal;
  A_rightValList rightValList;
  A_assignStmt assignStmt;
  // Struct definition
  A_structDef structDef;
  A_varDeclList varDeclList;
  // Variable statement
  A_varDeclStmt varDeclStmt;
  A_varDecl varDecl;
  A_varDeclScalar varDeclScalar;
  A_varDeclArray varDeclArray; 
  A_varDef varDef;
  A_varDefScalar varDefScalar;
  A_varDefArray varDefArray; 
  // Funtion declarae statement
  A_fnDeclStmt fnDeclStmt;
  A_fnDecl fnDecl;
  A_paramDecl paramDecl;
  // Funtion definite statement
  A_fnDef fnDef;
  A_codeBlockStmtList codeBlockStmtList;
  A_codeBlockStmt codeBlockStmt;
  A_fnCall fnCall;
}

// Declaration and precedence of operators
%left  <pos> COMMA
%right <pos> ASSIGN
%left  <pos> OR
%left  <pos> AND
%left  <pos> EQ NE
%left  <pos> GT GE LT LE
%left  <pos> ADD SUB
%left  <pos> MUL DIV
%right <pos> NOT UMINUS
%left  <pos> POINT ARROW
// Keyword
%token <type> INT;
%token <pos> IF
%token <pos> ELSE
%token <pos> FN
%token <pos> LET
%token <pos> STRUCT
%token <pos> CONTINUE
%token <pos> BREAK
%token <pos> RETURN
%token <pos> WHILE
// Bracket
%token <pos> LPARENT
%token <pos> RPARENT
%token <pos> LBRACKETS
%token <pos> RBRACKETS
%token <pos> LBRACES
%token <pos> RBRACES
// Special
%token <pos> COLON
%token <pos> SEMICOLON
%token <tokenId> ID;
%token <tokenNum> NUM;

%type <program> Program
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <arithExpr> ArithExpr
%type <arithUExpr> ArithUExpr
%type <exprUnit> ExprUnit
%type <arrayExpr> ArrayExpr
%type <memberExpr> MemberExpr
%type <boolExpr> BoolExpr
%type <boolUnit> BoolUnit
%type <comExpr> ComExpr
%type <boolUOpExpr> BoolUOpExpr
%type <leftVal> LeftVal
%type <rightVal> RightVal
%type <rightValList> RightValList
%type <assignStmt> AssignStmt
%type <structDef> StructDef
%type <varDeclList> VarDeclList
%type <varDeclStmt> VarDeclStmt
%type <varDecl> VarDecl
%type <varDeclScalar> VarDeclScalar
%type <varDeclArray> VarDeclArray 
%type <varDef> VarDef
%type <varDefScalar> VarDefScalar
%type <varDefArray> VarDefArray 
%type <fnDeclStmt> FnDeclStmt
%type <fnDecl> FnDecl
%type <paramDecl> ParamDecl
%type <fnDef> FnDef
%type 
%type <fnCall> FnCall
%type <type> Type;

%start Program

%%                   /* beginning of rules section */

Program: 
  ProgramElementList 
  {  
    root = A_Program($1);
    $$ = A_Program($1);
  }
  ;

ProgramElementList: 
  ProgramElement ProgramElementList
  {
    $$ = A_ProgramElementList($1, $2);
  }
  | /* Empty */
  {
    $$ = nullptr;
  }
  ;

ProgramElement: 
  VarDeclStmt
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

VarDeclStmt:
  LET VarDecl SEMICOLON
  {
    $$ = A_VarDeclStmt($2->pos, $2);
  }
  |
  LET VarDef SEMICOLON
  {
    $$ = A_VarDefStmt($2->pos, $2);
  }
  ;

VarDecl:
  VarDeclScalar
  {
    $$ = A_VarDecl_Scalar($1->pos, $1);
  }
  |
  VarDeclArray
  {
    $$ = A_VarDecl_Array($1->pos, $1);
  }
  ;

VarDeclScalar:
  ID COLON Type
  {
    $$ = A_VarDeclScalar($1->pos, $1->id, $3);
  }
  | ID 
  {
    $$ = A_VarDeclScalar($1->pos, $1->id, nullptr);
  }
  ;

VarDeclArray:
  ID LBRACKETS NUM RBRACKETS COLON Type
  {
    $$ = A_VarDeclArray($1->pos, $1->id, $3->num, $6);
  }
  | ID LBRACKETS NUM RBRACKETS
  {
    $$ = A_VarDeclArray($1->pos, $1->id, $3->num, nullptr);
  }
  ;

VarDef:
  VarDefScalar
  {
    $$ = A_VarDef_Scalar($1->pos, $1);
  }
  | VarDefArray
  {
    $$ = A_varDef_Array($1->pos, $1);
  }
  ;

VarDefScalar:
  ID COLON Type ASSIGN RightVal
  {
    $$ = A_VarDefScalar($1->pos, $1->id, $3, $5);
  }
  | ID ASSIGN RightVal
  {
    $$ = A_VarDefScalar($1->pos, $1->id, nullptr, $3);
  }
  ;

VarDefArray:
  ID LBRACKETS NUM RBRACKETS COLON Type ASSIGN LBRACES RightValList RBRACES
  {
    $$ = A_VarDefArray($1->pos, $1->id, $3->num, $6, $9);
  }
  | ID LBRACKETS NUM RBRACKETS ASSIGN LBRACES RightValList RBRACES 
  {
    $$ = A_VarDefArray($1->pos, $1->id, $3->num, nullptr, $7);
  }
  ;

StructDef:
  STRUCT ID LBRACES VarDeclList RBRACES
  {
    $$ = A_StructDef($1->pos, $2->id, $4);
  }
  ;
VarDeclList:
  VarDecl COMMA VarDeclList
  {
    $$ = A_VarDeclList($1, $3);
  }
  | VarDecl
  {
    $$ = A_VarDeclList($1, nullptr);
  }
  ;

FnDeclStmt:
  FnDecl SEMICOLON
  {
    $$ = A_FnDeclStmt($1->pos, $1);
  }
  ;

FnDecl:
  FN ID LPARENT ParamDecl RPARENT ARROW Type
  {
    $$ = A_FnDecl($1->pos, $2->id, $4, $7);
  }
  | FN ID LPARENT ParamDecl RPARENT
  {
    $$ = A_FnDecl($1->pos, $2->id, $4, nullptr);
  }
  ;

ParamDecl:
  VarDeclList
  {
    $$ = A_ParamDecl($1);
  }
  | 
  {
    $$ = A_ParamDecl(nullptr);
  }
  ;

FnDef:
  
CodeBlockStmtList:

CodeBlockStmt:

ArithExpr: 
  ExprUnit
  {
    $$ = A_ExprUnit($1->pos, $1);
  }
  | ArithExpr ADD ArithExpr
  {
    $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_add, $1, $3));
  }
  | ArithExpr SUB ArithExpr
  {
    $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_sub, $1, $3));
  }
  | ArithExpr MUL ArithExpr
  {
    $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_mul, $1, $3));
  }
  | ArithExpr DIV ArithExpr
  {
    $$ = A_ArithBiOp_Expr($1->pos, A_ArithBiOpExpr($1->pos, A_div, $1, $3));
  }
  ;

ExprUnit:
  NUM
  {
    $$ = A_NumExprUnit($1->pos, $1->num);
  }
  | ID
  {
    $$ = A_IdExprUnit($1->pos, $1->id);
  }
  | LPARENT ArithExpr RPARENT
  {
    $$ = A_ArithExprUnit($2->pos, $2);
  }
  | ArithUExpr
  {
    $$ = A_ArithUExprUnit($1->pos, $1);
  }
  | FnCall
  {
    $$ = A_CallExprUnit($1->pos, $1);
  }
  | ArrayExpr
  {
    $$ = A_ArrayExprUnit($1->pos, $1);
  }
  | MemberExpr
  {
    $$ = A_MemberExpr($1->pos, $1);
  }
  ;

BoolExpr:
  BoolUnit
  {
    $$ = A_BoolExpr($1->pos, $1);
  }
  | BoolExpr AND BoolExpr
  {
    $$ = A_BoolBiOp_Expr($1->pos, A_BoolBiOpExpr($1->pos, A_and, $1, $3));
  } BoolExpr OR BoolExpr
  {
    $$ = A_BoolBiOp_Expr($1->pos, A_BoolBiOpExpr($1->pos, A_or, $1, $3));
  }
  ;

BoolUnit:
  BoolUOpExpr
  {
    $$ = A_BoolUOpExprUnit($1->pos, $1);
  }
  | LPARENT BoolExpr RPARENT
  {
    $$ = A_BoolExprUnit($2->pos, $2);
  }
  | LPARENT ComExpr RPARENT
  {
    $$ = A_ComExprUnit($2->pos, $2);
  }
  ;

  
LeftVal:
  ID
  {
    $$ = A_IdExprLVal($1->pos, $1->id);
  }
  | ArrayExpr
  {
    $$ = A_ArrExprLVal($1->pos, $1);
  }
  | MemberExpr
  {
    $$ = A_MemberExprLVal($1->pos, $1);
  }
  ;

RightVal:
  ArithExpr
  {
    $$ = A_ArithExprRVal($1->pos, $1);
  }
  | BoolExpr
  {
    $$ = A_BoolExprRVal($1->pos, $1);
  }
  ;

RightValList:
  RightVal COMMA RightValList
  {
    $$ = A_RightValList($1, $3);
  }
  | RightVal
  {
    $$ = A_RightValList($1, nullptr);
  }
  |
  {
    $$ = A_RightValList(nullptr, nullptr);
  }
  ;

Type:
  INT 
  {
    $$ = A_NativeType($1->pos, A_intTypekind);
  }
  | ID 
  {
    $$ = A_StructType($1->pos, $1->id);
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


