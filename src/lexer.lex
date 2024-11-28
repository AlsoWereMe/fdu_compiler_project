%{
#include <stdio.h>
#include <string.h>
#include "TeaplAst.h"
#include "y.tab.hpp"
extern int line, col;
int c;
int calc(const char *s, int len);
%}
%x COMMENT1 COMMENT2
%%
<INITIAL>{
    " " {col += 1;}
    "\t" { col+=4; }
    "\n" {line += 1; col = 0;}
    [1-9][0-9]* {yylval.tokenNum = A_TokenNum(A_Pos(line, col), calc(yytext, yyleng)); col+=yyleng; return NUM;}
    0 {yylval.tokenNum = A_TokenNum(A_Pos(line, col), 0);++col;return NUM;}
    "+" { yylval.pos = A_Pos(line, col); col += yyleng; return ADD; }
    "-" { yylval.pos = A_Pos(line, col); col += yyleng; return SUB; }
    "*" { yylval.pos = A_Pos(line, col); col += yyleng; return MUL; }
    "/" { yylval.pos = A_Pos(line, col); col += yyleng; return DIV; }
    ">=" { yylval.pos = A_Pos(line, col); col += yyleng; return GE; }
    ">" { yylval.pos = A_Pos(line, col); col += yyleng; return GT; }
    "<=" { yylval.pos = A_Pos(line, col); col += yyleng; return LE; }
    "<" { yylval.pos = A_Pos(line, col); col += yyleng; return LT; } 
    "!=" { yylval.pos = A_Pos(line, col); col += yyleng; return NEQ; }
    "==" { yylval.pos = A_Pos(line, col); col += yyleng; return EQ; }
    "(" { yylval.pos = A_Pos(line, col); col += yyleng; return LPAR; }
    ")" { yylval.pos = A_Pos(line, col); col += yyleng; return RPAR; } 
    "[" { yylval.pos = A_Pos(line, col); col += yyleng; return LBRACKET; }
    "]" { yylval.pos = A_Pos(line, col); col += yyleng; return RBRACKET; }
    "{" { yylval.pos = A_Pos(line, col); col += yyleng; return LBRACE; }
    "}" { yylval.pos = A_Pos(line, col); col += yyleng; return RBRACE; }
    "=" { yylval.pos = A_Pos(line, col); col += yyleng; return ASSIGN; }
    "," { yylval.pos = A_Pos(line, col); col += yyleng; return COMMA; }
    ";" { yylval.pos = A_Pos(line, col); col += yyleng; return SEMICOLON; }
    ":" { yylval.pos = A_Pos(line, col); col += yyleng; return COLON; }
    "let" { yylval.pos = A_Pos(line, col); col += yyleng; return LET; }
    "." { yylval.pos = A_Pos(line, col); col += yyleng; return DOT; }
    "ret" { yylval.pos = A_Pos(line, col); col += yyleng; return RETURN; }
    "&&" { yylval.pos = A_Pos(line, col); col += yyleng; return AND; }
    "||" { yylval.pos = A_Pos(line, col); col += yyleng; return OR; }
    "!" { yylval.pos = A_Pos(line, col); col += yyleng; return NOT; }
    "while" { yylval.pos = A_Pos(line, col); col += yyleng; return WHILE; }
    "break" { yylval.pos = A_Pos(line, col); col += yyleng; return BREAK; }
    "continue" { yylval.pos = A_Pos(line, col); col += yyleng; return CONTINUE; }
    "->" { yylval.pos = A_Pos(line, col); col += yyleng; return ARROW; }
    "int" { yylval.pos = A_Pos(line, col); col += yyleng; return INT; }
    "struct" { yylval.pos = A_Pos(line, col); col += yyleng; return STRUCT; }
    "fn" { yylval.pos = A_Pos(line, col); col += yyleng; return FN; }
    "if" { yylval.pos = A_Pos(line, col); col += yyleng; return IF; }
    "else" { yylval.pos = A_Pos(line, col); col += yyleng; return ELSE; }
    [a-z_A-Z][a-z_A-Z0-9]* {
        char * temp = (char *)malloc((yyleng + 1)*sizeof(char));
        strcpy(temp, yytext);
        temp[yyleng] = '\0';
        yylval.tokenId = A_TokenId(A_Pos(line, col), temp);
        col += yyleng;
        return ID;
        }
    "//" {BEGIN COMMENT1;}
    "/*" {BEGIN COMMENT2;}
}

<COMMENT1>{
"\n" { line += 1; col = 0; BEGIN INITIAL;}
[^\n\t]   {col += 1;}
"\t"   {col += 4;}
}
<COMMENT2>{
"*/" {BEGIN INITIAL;}
"\n" {line += 1; col =0;}
[^\n\t]   {col += 1;}
"\t"   {col += 4;}
}
.	{ printf("Illegal input \"%c\"\n", yytext[0]); }
%%

// This function takes a string of digits and its length as input, and returns the integer value of the string.
int calc(const char *s, int len) {
    int ret = 0;
    for(int i = 0; i < len; i++)
        ret = ret * 10 + (s[i] - '0');
    return ret;
}