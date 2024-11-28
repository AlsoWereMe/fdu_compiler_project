/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ADD = 258,                     /* ADD  */
    SUB = 259,                     /* SUB  */
    MUL = 260,                     /* MUL  */
    DIV = 261,                     /* DIV  */
    SEMICOLON = 262,               /* SEMICOLON  */
    DOT = 263,                     /* DOT  */
    COLON = 264,                   /* COLON  */
    COMMA = 265,                   /* COMMA  */
    LPAR = 266,                    /* LPAR  */
    RPAR = 267,                    /* RPAR  */
    LBRACKET = 268,                /* LBRACKET  */
    RBRACKET = 269,                /* RBRACKET  */
    LBRACE = 270,                  /* LBRACE  */
    RBRACE = 271,                  /* RBRACE  */
    ASSIGN = 272,                  /* ASSIGN  */
    ARROW = 273,                   /* ARROW  */
    LT = 274,                      /* LT  */
    GT = 275,                      /* GT  */
    LE = 276,                      /* LE  */
    GE = 277,                      /* GE  */
    EQ = 278,                      /* EQ  */
    NEQ = 279,                     /* NEQ  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    NOT = 282,                     /* NOT  */
    LET = 283,                     /* LET  */
    FN = 284,                      /* FN  */
    STRUCT = 285,                  /* STRUCT  */
    RETURN = 286,                  /* RETURN  */
    CONTINUE = 287,                /* CONTINUE  */
    BREAK = 288,                   /* BREAK  */
    IF = 289,                      /* IF  */
    ELSE = 290,                    /* ELSE  */
    WHILE = 291,                   /* WHILE  */
    INT = 292,                     /* INT  */
    NUM = 293,                     /* NUM  */
    ID = 294                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define SEMICOLON 262
#define DOT 263
#define COLON 264
#define COMMA 265
#define LPAR 266
#define RPAR 267
#define LBRACKET 268
#define RBRACKET 269
#define LBRACE 270
#define RBRACE 271
#define ASSIGN 272
#define ARROW 273
#define LT 274
#define GT 275
#define LE 276
#define GE 277
#define EQ 278
#define NEQ 279
#define AND 280
#define OR 281
#define NOT 282
#define LET 283
#define FN 284
#define STRUCT 285
#define RETURN 286
#define CONTINUE 287
#define BREAK 288
#define IF 289
#define ELSE 290
#define WHILE 291
#define INT 292
#define NUM 293
#define ID 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.yacc"

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

#line 191 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
