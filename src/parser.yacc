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
  // Expression
  A_arithExpr arithExpr;
  A_exprUnit exprUnit;
  A_arrayExpr arrayExpr;
  A_memberExpr memberExpr;
  A_boolExpr boolExpr;
  A_boolUnit boolUnit;
  A_comExpr comExpr;
  A_boolUOpExpr boolUOpExpr;
  // Value
  A_leftVal leftVal;
  A_rightVal rightVal;
  A_rightValList rightValList;
  A_assignStmt assignStmt;
  A_indexExpr indexExpr;
  // Struct definition
  A_structDef structDef;
  A_varDeclList varDeclList;
  // Variable Declaration and Definition
  A_varDeclStmt varDeclStmt;
  A_varDecl varDecl;
  A_varDeclScalar varDeclScalar;
  A_varDeclArray varDeclArray; 
  A_varDef varDef;
  A_varDefScalar varDefScalar;
  A_varDefArray varDefArray; 
  // Funtion Declaration and Definition
  A_fnDeclStmt fnDeclStmt;
  A_fnDecl fnDecl;
  A_paramDecl paramDecl;
  A_fnDef fnDef;
  A_fnCall fnCall;
  // Code blocks
  A_codeBlockStmtList codeBlockStmtList;
  A_codeBlockStmt codeBlockStmt;
  // All kind of keyword statement
  A_callStmt callStmt;
  A_ifStmt ifStmt;
  A_whileStmt whileStmt;
  A_returnStmt returnStmt;
}

// token
// operators
%token <pos> OR
%token <pos> AND
%token <pos> NOT
%token <pos> ADD
%token <pos> SUB
%token <pos> MUL
%token <pos> DIV
%token <pos> GT
%token <pos> LT
%token <pos> GE
%token <pos> LE
%token <pos> EQ
%token <pos> NE
%token <pos> ASSIGN
%token <pos> UMINUS
%token <pos> POINT
%token <pos> ARROW

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

// Precedence of operators
%left  COMMA
%right ASSIGN
%left  OR
%left  AND
%left  EQ NE
%left  GE LE GT LT
%left  ADD SUB
%left  MUL DIV
%right NOT UMINUS
%left  POINT ARROW

// Non-terminated token
%type <program> Program
%type <programElementList> ProgramElementList
%type <programElement> ProgramElement
%type <arithExpr> ArithExpr
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
%type <indexExpr> IndexExpr
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
%type <codeBlockStmtList> CodeBlockStmtList
%type <codeBlockStmt> CodeBlockStmt
%type <callStmt> CallStmt
%type <ifStmt> IfStmt
%type <whileStmt> WhileStmt
%type <returnStmt> ReturnStmt
%type <fnCall> FnCall
%type <type> Type;

%start Program

%%                   /* beginning of rules section */

Program: 
  ProgramElementList 
  {  
    root = A_Program($1);
    $$ = root;
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
    $$ = A_VarDef_Array($1->pos, $1);
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
    $$ = A_StructDef($1, $2->id, $4);
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
    $$ = A_FnDecl($1, $2->id, $4, $7);
  }
  | FN ID LPARENT ParamDecl RPARENT
  {
    $$ = A_FnDecl($1, $2->id, $4, nullptr);
  }
  ;

ParamDecl:
  VarDeclList
  {
    $$ = A_ParamDecl($1);
  }
  | /* No parameters */
  {
    $$ = A_ParamDecl(nullptr);
  }
  ;

FnDef:
  FnDecl LBRACES CodeBlockStmtList RBRACES
  {
    $$ = A_FnDef($1->pos, $1, $3);
  }
  ;

CodeBlockStmtList:
  CodeBlockStmt CodeBlockStmtList
  {
    $$ = A_CodeBlockStmtList($1, $2);
  }
  | CodeBlockStmt
  {
    $$ = A_CodeBlockStmtList($1, nullptr);
  }
  | /* No code statement */
  {
    $$ = A_CodeBlockStmtList(nullptr, nullptr);
  }
  ;

CodeBlockStmt:
  VarDeclStmt
  {
    $$ = A_BlockVarDeclStmt($1->pos, $1);
  }
  | AssignStmt
  {
    $$ = A_BlockAssignStmt($1->pos, $1);
  }
  | CallStmt
  {
    $$ = A_BlockCallStmt($1->pos, $1);
  }
  | IfStmt
  {
    $$ = A_BlockIfStmt($1->pos, $1);
  }
  | WhileStmt
  {
    $$ = A_BlockWhileStmt($1->pos, $1);
  }
  | ReturnStmt
  {
    $$ = A_BlockReturnStmt($1->pos, $1);
  } 
  | CONTINUE SEMICOLON
  {
    $$ = A_BlockContinueStmt($1);
  } 
  | BREAK SEMICOLON
  {
    $$ = A_BlockBreakStmt($1);
  }
  | SEMICOLON
  {
    $$ = A_BlockNullStmt($1);
  }
  ;

CallStmt:
  FnCall SEMICOLON
  {
    $$ = A_CallStmt($1->pos, $1);
  }
  ;

FnCall:
  ID LPARENT RightValList RPARENT 
  {
    $$ = A_FnCall($1->pos, $1->id, $3);
  }
  ;

IfStmt: /* A_ifStmt A_IfStmt(A_pos pos, A_boolUnit boolUnit, A_codeBlockStmtList ifStmts, A_codeBlockStmtList elseStmts) */
  IF BoolUnit LBRACES CodeBlockStmtList RBRACES ELSE LBRACES CodeBlockStmtList RBRACES
  {
    $$ = A_IfStmt($1, $2, $4, $8);
  }
  | IF BoolUnit LBRACES CodeBlockStmtList RBRACES
  {
    $$ = A_IfStmt($1, $2, $4, nullptr);
  }
  ;

WhileStmt: /* A_whileStmt A_WhileStmt(A_pos pos, A_boolUnit boolUnit, A_codeBlockStmtList whileStmts) */
  WHILE BoolUnit LBRACES CodeBlockStmtList RBRACES
  {
    $$ = A_WhileStmt($1, $2, $4);
  }
  ;

ReturnStmt: /* A_returnStmt A_ReturnStmt(A_pos pos, A_rightVal retVal) */
  RETURN RightVal SEMICOLON
  {
    $$ = A_ReturnStmt($1, $2);
  }
  |
  RETURN SEMICOLON
  {
    $$ = A_ReturnStmt($1, nullptr);
  }
  ;

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
    $$ = A_ArithExprUnit($1, $2);
  }
  | SUB ExprUnit %prec UMINUS
  {
    /* A_ArithUExprUnit(A_pos pos, A_arithUExpr arithUExpr) */
    /* A_ArithUExpr(A_pos pos, A_arithUOp op, A_exprUnit expr) */
    if($2->kind == A_numExprKind) {
      $$ = A_NumExprUnit($2->pos, -($2->u.num));
    } else {
      $$ = A_ArithUExprUnit($1, A_ArithUExpr($1, A_neg, $2));
    }
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
    $$ = A_MemberExprUnit($1->pos, $1);
  }
  ;

BoolExpr:
  BoolExpr AND BoolExpr
  {
    $$ = A_BoolBiOp_Expr($1->pos, A_BoolBiOpExpr($1->pos, A_and, $1, $3));
  } 
  | BoolExpr OR BoolExpr
  {
    $$ = A_BoolBiOp_Expr($1->pos, A_BoolBiOpExpr($1->pos, A_or, $1, $3));
  }
  | BoolUnit
  {
    $$ = A_BoolExpr($1->pos, $1);
  }
  ;

BoolUnit:
  BoolUOpExpr
  {
    $$ = A_BoolUOpExprUnit($1->pos, $1);
  }
  | LPARENT BoolExpr RPARENT
  {
    $$ = A_BoolExprUnit($1, $2);
  }
  | LPARENT ComExpr RPARENT
  {
    $$ = A_ComExprUnit($1, $2);
  }
  ;

BoolUOpExpr: /* A_BoolUOpExpr(A_pos pos, A_boolUOp op, A_boolUnit cond) */
  NOT BoolUnit
  {
    $$ = A_BoolUOpExpr($1, A_not, $2);
  }
  ;

ComExpr: /* A_ComExpr(A_pos pos, A_comOp op, A_exprUnit left, A_exprUnit right) */
  ExprUnit LE ExprUnit
  {
    $$ = A_ComExpr($1->pos, A_le, $1, $3);
  }
  | ExprUnit LT ExprUnit
  {
    $$ = A_ComExpr($1->pos, A_lt, $1, $3);
  }
  | ExprUnit GE ExprUnit
  {
    $$ = A_ComExpr($1->pos, A_ge, $1, $3);
  }
  | ExprUnit GT ExprUnit
  {
    $$ = A_ComExpr($1->pos, A_gt, $1, $3);
  }
  | ExprUnit NE ExprUnit
  {
    $$ = A_ComExpr($1->pos, A_ne, $1, $3);
  }
  | ExprUnit EQ ExprUnit
  {
    $$ = A_ComExpr($1->pos, A_eq, $1, $3);
  }
  ;

LeftVal:
  ArrayExpr
  {
    $$ = A_ArrExprLVal($1->pos, $1);
  }
  | MemberExpr
  {
    $$ = A_MemberExprLVal($1->pos, $1);
  }
  | ID
  {
    $$ = A_IdExprLVal($1->pos, $1->id);
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

AssignStmt:
  LeftVal ASSIGN RightVal SEMICOLON
  {
    $$ = A_AssignStmt($1->pos, $1, $3);
  }
  ;

ArrayExpr: /* A_ArrayExpr(A_pos pos, A_leftVal arr, A_indexExpr idx) */
  LeftVal LBRACKETS IndexExpr RBRACKETS 
  {
    $$ = A_ArrayExpr($1->pos, $1, $3);
  }
  ;

MemberExpr: /* A_MemberExpr(A_pos pos, A_leftVal structId, char* memberId) */
  LeftVal POINT ID
  {
    $$ = A_MemberExpr($1->pos, $1, $3->id);
  }
  ;

IndexExpr: 
  ID
  {
    $$ = A_IdIndexExpr($1->pos, $1->id);
  }
  | NUM
  {
    $$ = A_NumIndexExpr($1->pos, $1->num);
  }
  ;

Type:
  INT 
  {
    $$ = A_NativeType($1->pos, A_intTypeKind);
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


