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
    OR = 258,                      /* OR  */
    AND = 259,                     /* AND  */
    NOT = 260,                     /* NOT  */
    ADD = 261,                     /* ADD  */
    SUB = 262,                     /* SUB  */
    MUL = 263,                     /* MUL  */
    DIV = 264,                     /* DIV  */
    GT = 265,                      /* GT  */
    LT = 266,                      /* LT  */
    GE = 267,                      /* GE  */
    LE = 268,                      /* LE  */
    EQ = 269,                      /* EQ  */
    NE = 270,                      /* NE  */
    ASSIGN = 271,                  /* ASSIGN  */
    UMINUS = 272,                  /* UMINUS  */
    POINT = 273,                   /* POINT  */
    ARROW = 274,                   /* ARROW  */
    INT = 275,                     /* INT  */
    IF = 276,                      /* IF  */
    ELSE = 277,                    /* ELSE  */
    FN = 278,                      /* FN  */
    LET = 279,                     /* LET  */
    STRUCT = 280,                  /* STRUCT  */
    CONTINUE = 281,                /* CONTINUE  */
    BREAK = 282,                   /* BREAK  */
    RETURN = 283,                  /* RETURN  */
    WHILE = 284,                   /* WHILE  */
    LPARENT = 285,                 /* LPARENT  */
    RPARENT = 286,                 /* RPARENT  */
    LBRACKETS = 287,               /* LBRACKETS  */
    RBRACKETS = 288,               /* RBRACKETS  */
    LBRACES = 289,                 /* LBRACES  */
    RBRACES = 290,                 /* RBRACES  */
    COLON = 291,                   /* COLON  */
    SEMICOLON = 292,               /* SEMICOLON  */
    ID = 293,                      /* ID  */
    NUM = 294,                     /* NUM  */
    COMMA = 295                    /* COMMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define OR 258
#define AND 259
#define NOT 260
#define ADD 261
#define SUB 262
#define MUL 263
#define DIV 264
#define GT 265
#define LT 266
#define GE 267
#define LE 268
#define EQ 269
#define NE 270
#define ASSIGN 271
#define UMINUS 272
#define POINT 273
#define ARROW 274
#define INT 275
#define IF 276
#define ELSE 277
#define FN 278
#define LET 279
#define STRUCT 280
#define CONTINUE 281
#define BREAK 282
#define RETURN 283
#define WHILE 284
#define LPARENT 285
#define RPARENT 286
#define LBRACKETS 287
#define RBRACKETS 288
#define LBRACES 289
#define RBRACES 290
#define COLON 291
#define SEMICOLON 292
#define ID 293
#define NUM 294
#define COMMA 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "parser.yacc"

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

#line 197 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
