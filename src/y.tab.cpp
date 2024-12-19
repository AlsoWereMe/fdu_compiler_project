/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.yacc"

#include <stdio.h>
#include "TeaplAst.h"

extern A_pos pos;
extern A_program root;

extern int yylex(void);

extern "C" {
    extern void yyerror(const char *s);
    extern int yywrap();
}

#line 86 "y.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ADD = 3,                        /* ADD  */
  YYSYMBOL_SUB = 4,                        /* SUB  */
  YYSYMBOL_MUL = 5,                        /* MUL  */
  YYSYMBOL_DIV = 6,                        /* DIV  */
  YYSYMBOL_SEMICOLON = 7,                  /* SEMICOLON  */
  YYSYMBOL_DOT = 8,                        /* DOT  */
  YYSYMBOL_COLON = 9,                      /* COLON  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_LPAR = 11,                      /* LPAR  */
  YYSYMBOL_RPAR = 12,                      /* RPAR  */
  YYSYMBOL_LBRACKET = 13,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 14,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 15,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 16,                    /* RBRACE  */
  YYSYMBOL_ASSIGN = 17,                    /* ASSIGN  */
  YYSYMBOL_ARROW = 18,                     /* ARROW  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_GT = 20,                        /* GT  */
  YYSYMBOL_LE = 21,                        /* LE  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_EQ = 23,                        /* EQ  */
  YYSYMBOL_NEQ = 24,                       /* NEQ  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_LET = 28,                       /* LET  */
  YYSYMBOL_FN = 29,                        /* FN  */
  YYSYMBOL_STRUCT = 30,                    /* STRUCT  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 32,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 33,                     /* BREAK  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_WHILE = 36,                     /* WHILE  */
  YYSYMBOL_INT = 37,                       /* INT  */
  YYSYMBOL_NUM = 38,                       /* NUM  */
  YYSYMBOL_ID = 39,                        /* ID  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_Program = 41,                   /* Program  */
  YYSYMBOL_ProgramElementList = 42,        /* ProgramElementList  */
  YYSYMBOL_ProgramElement = 43,            /* ProgramElement  */
  YYSYMBOL_ArithExpr = 44,                 /* ArithExpr  */
  YYSYMBOL_ArithBiOpExpr = 45,             /* ArithBiOpExpr  */
  YYSYMBOL_ExprUnit = 46,                  /* ExprUnit  */
  YYSYMBOL_ArrayExpr = 47,                 /* ArrayExpr  */
  YYSYMBOL_MemberExpr = 48,                /* MemberExpr  */
  YYSYMBOL_IndexExpr = 49,                 /* IndexExpr  */
  YYSYMBOL_BoolExpr = 50,                  /* BoolExpr  */
  YYSYMBOL_BoolBiOpExpr = 51,              /* BoolBiOpExpr  */
  YYSYMBOL_BoolUnit = 52,                  /* BoolUnit  */
  YYSYMBOL_BoolUOpExpr = 53,               /* BoolUOpExpr  */
  YYSYMBOL_ComExpr = 54,                   /* ComExpr  */
  YYSYMBOL_AssignStmt = 55,                /* AssignStmt  */
  YYSYMBOL_LeftVal = 56,                   /* LeftVal  */
  YYSYMBOL_RightVal = 57,                  /* RightVal  */
  YYSYMBOL_Fncall = 58,                    /* Fncall  */
  YYSYMBOL_RightValList = 59,              /* RightValList  */
  YYSYMBOL_VarDeclStmt = 60,               /* VarDeclStmt  */
  YYSYMBOL_VarDecl = 61,                   /* VarDecl  */
  YYSYMBOL_VarDeclScalar = 62,             /* VarDeclScalar  */
  YYSYMBOL_VarDeclArray = 63,              /* VarDeclArray  */
  YYSYMBOL_VarDef = 64,                    /* VarDef  */
  YYSYMBOL_VarDefScalar = 65,              /* VarDefScalar  */
  YYSYMBOL_VarDefArray = 66,               /* VarDefArray  */
  YYSYMBOL_Type = 67,                      /* Type  */
  YYSYMBOL_StructDef = 68,                 /* StructDef  */
  YYSYMBOL_FieldDecl = 69,                 /* FieldDecl  */
  YYSYMBOL_FieldDeclList = 70,             /* FieldDeclList  */
  YYSYMBOL_VarDeclList = 71,               /* VarDeclList  */
  YYSYMBOL_FnDeclStmt = 72,                /* FnDeclStmt  */
  YYSYMBOL_FnDecl = 73,                    /* FnDecl  */
  YYSYMBOL_ParamDecl = 74,                 /* ParamDecl  */
  YYSYMBOL_FnDef = 75,                     /* FnDef  */
  YYSYMBOL_CodeBlockStmtList = 76,         /* CodeBlockStmtList  */
  YYSYMBOL_CodeBlockStmt = 77,             /* CodeBlockStmt  */
  YYSYMBOL_ReturnStmt = 78,                /* ReturnStmt  */
  YYSYMBOL_CallStmt = 79,                  /* CallStmt  */
  YYSYMBOL_BoolUnit_ = 80,                 /* BoolUnit_  */
  YYSYMBOL_IfStmt = 81,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 82                  /* WhileStmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   157,   157,   165,   171,   177,   181,   185,   189,   193,
     200,   204,   211,   215,   219,   223,   230,   234,   238,   242,
     246,   250,   254,   261,   268,   275,   279,   286,   290,   297,
     301,   308,   312,   316,   323,   330,   334,   338,   342,   346,
     350,   357,   364,   368,   372,   379,   386,   393,   397,   403,
     409,   413,   420,   424,   431,   435,   442,   446,   453,   457,
     464,   468,   475,   479,   486,   490,   497,   504,   508,   515,
     519,   525,   531,   535,   541,   547,   554,   558,   565,   572,
     579,   585,   588,   595,   599,   603,   607,   611,   615,   619,
     623,   630,   634,   641,   648,   652,   656,   663,   667,   674
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ADD", "SUB", "MUL",
  "DIV", "SEMICOLON", "DOT", "COLON", "COMMA", "LPAR", "RPAR", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "ASSIGN", "ARROW", "LT", "GT", "LE",
  "GE", "EQ", "NEQ", "AND", "OR", "NOT", "LET", "FN", "STRUCT", "RETURN",
  "CONTINUE", "BREAK", "IF", "ELSE", "WHILE", "INT", "NUM", "ID",
  "$accept", "Program", "ProgramElementList", "ProgramElement",
  "ArithExpr", "ArithBiOpExpr", "ExprUnit", "ArrayExpr", "MemberExpr",
  "IndexExpr", "BoolExpr", "BoolBiOpExpr", "BoolUnit", "BoolUOpExpr",
  "ComExpr", "AssignStmt", "LeftVal", "RightVal", "Fncall", "RightValList",
  "VarDeclStmt", "VarDecl", "VarDeclScalar", "VarDeclArray", "VarDef",
  "VarDefScalar", "VarDefArray", "Type", "StructDef", "FieldDecl",
  "FieldDeclList", "VarDeclList", "FnDeclStmt", "FnDecl", "ParamDecl",
  "FnDef", "CodeBlockStmtList", "CodeBlockStmt", "ReturnStmt", "CallStmt",
  "BoolUnit_", "IfStmt", "WhileStmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,  -145,    -1,    18,    72,    89,  -145,     3,  -145,  -145,
    -145,     8,  -145,   108,    95,  -145,  -145,   113,  -145,  -145,
     112,   103,  -145,  -145,  -145,    73,    71,   100,    26,  -145,
    -145,   101,   102,  -145,    14,   132,   135,   133,   133,   134,
    -145,  -145,  -145,    43,   139,  -145,   136,    73,  -145,  -145,
    -145,  -145,  -145,  -145,   130,   137,   115,    26,  -145,     1,
     129,  -145,  -145,    58,    90,   111,  -145,  -145,    27,   138,
    -145,   142,    63,   140,   141,  -145,   148,  -145,  -145,    16,
     143,   144,    26,   117,    61,    26,  -145,  -145,  -145,  -145,
      26,    50,  -145,   110,    26,    26,    26,    26,    71,   122,
     101,   145,    71,   123,   102,  -145,  -145,    16,    23,   107,
      37,  -145,  -145,   150,   153,    73,    73,   157,   159,  -145,
     155,   158,   166,  -145,    71,   160,  -145,   131,   131,  -145,
    -145,  -145,   162,  -145,    71,  -145,   163,  -145,   107,    49,
    -145,   167,    16,  -145,    26,    26,    26,    26,    26,    26,
    -145,    23,    23,  -145,  -145,   164,   165,    26,  -145,  -145,
    -145,  -145,   161,    26,   173,  -145,   174,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,   124,   149,  -145,  -145,
     170,   171,    71,    71,   175,    26,  -145,  -145,  -145,    73,
     172,   176,  -145,  -145
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     9,     0,     0,     0,     0,     2,     4,     5,     6,
       7,     0,     8,    55,     0,    52,    53,     0,    58,    59,
       0,     0,     1,     3,    75,    81,     0,     0,     0,    50,
      51,    74,    71,    82,     0,     0,     0,     0,     0,    42,
      43,    44,    84,     0,     0,    83,     0,    81,    88,    85,
      86,    87,    64,    65,    54,     0,     0,     0,    16,    18,
      45,    10,    11,    21,    22,     0,    61,    20,    55,    73,
      78,     0,     0,    70,     0,    92,     0,    89,    90,     0,
       0,     0,    49,     0,     0,     0,    23,    93,    79,    80,
       0,    57,    17,     0,     0,     0,     0,     0,     0,     0,
      74,    76,     0,     0,    71,    66,    91,     0,     0,     0,
       0,    27,    28,    32,     0,    81,    81,    48,     0,    24,
       0,     0,     0,    60,     0,     0,    19,    12,    13,    14,
      15,    54,     0,    72,     0,    67,     0,    69,    11,     0,
      32,     0,     0,    34,     0,     0,     0,     0,     0,     0,
      96,     0,     0,    95,    94,     0,     0,    49,    46,    25,
      26,    41,    56,    49,    57,    77,     0,    33,    31,    36,
      35,    38,    37,    39,    40,    29,    30,    97,    99,    47,
       0,     0,     0,     0,     0,    49,    63,    56,    68,    81,
       0,     0,    62,    98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,   179,  -145,   -49,  -145,   -63,   -25,   -23,  -145,
     -74,  -145,    66,   114,   116,  -145,   -21,   -17,   -19,  -144,
      35,   187,  -145,  -145,  -145,  -145,  -145,   -95,  -145,  -145,
      87,    94,  -145,  -145,  -145,  -145,   -46,  -145,  -145,  -145,
     168,  -145,  -145
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    60,    61,    62,    63,    64,    86,
     139,   111,   112,   140,   141,    42,    65,   117,    67,   118,
      45,    69,    15,    16,    17,    18,    19,    54,     9,    73,
      74,    70,    10,    11,    71,    12,    46,    47,    48,    49,
      80,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    89,    41,   131,    43,   110,    44,   135,    93,   -42,
       1,    66,    82,   179,   -42,    24,   109,    76,    56,   181,
      56,    75,    40,    25,    41,    57,    43,   107,    44,   162,
      56,     2,     3,     4,   142,     8,    98,    57,    13,   165,
      99,   190,     8,   108,   138,   127,   128,   129,   130,   150,
     108,    83,    58,    59,    58,    59,    84,    20,    93,   124,
      85,   167,   151,   152,    58,    59,   -43,   125,   122,   155,
     156,   -43,   102,   123,   151,   152,   103,   175,   176,   109,
      33,   169,   170,   171,   172,   173,   174,   187,   188,    22,
      40,    40,    41,    41,    43,    43,    44,    44,   -44,   120,
     121,     2,    29,   -44,    34,    35,    36,    37,    52,    38,
      53,    21,    39,    94,    95,    96,    97,    26,    32,    83,
      30,    27,   126,    31,    84,    28,   144,   145,   146,   147,
     148,   149,    94,    95,    96,    97,    96,    97,    55,    77,
      68,    72,    78,   191,    79,    82,    87,    90,   100,   151,
     104,    91,    88,    92,   101,   106,   119,   105,   115,   116,
     132,   136,   153,   134,    40,   154,    41,   157,    43,   159,
      44,   158,   160,   161,   143,   163,   164,   166,   180,   168,
     177,   178,   182,   183,   184,   185,    23,   186,   192,    14,
     189,   137,   193,   113,   133,   114,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81
};

static const yytype_int16 yycheck[] =
{
      25,    47,    25,    98,    25,    79,    25,   102,    57,     8,
       7,    28,    11,   157,    13,     7,    79,    34,     4,   163,
       4,     7,    47,    15,    47,    11,    47,    11,    47,   124,
       4,    28,    29,    30,    11,     0,     9,    11,    39,   134,
      13,   185,     7,    27,   107,    94,    95,    96,    97,    12,
      27,     8,    38,    39,    38,    39,    13,    39,   107,     9,
      17,    12,    25,    26,    38,    39,     8,    17,    85,   115,
     116,    13,     9,    90,    25,    26,    13,   151,   152,   142,
       7,   144,   145,   146,   147,   148,   149,   182,   183,     0,
     115,   116,   115,   116,   115,   116,   115,   116,     8,    38,
      39,    28,     7,    13,    31,    32,    33,    34,    37,    36,
      39,    39,    39,     3,     4,     5,     6,     9,    15,     8,
       7,    13,    12,    11,    13,    17,    19,    20,    21,    22,
      23,    24,     3,     4,     5,     6,     5,     6,    38,     7,
      39,    39,     7,   189,    11,    11,     7,    17,    10,    25,
      10,    14,    16,    38,    12,     7,    39,    16,    15,    15,
      38,    38,    12,    18,   189,    12,   189,    10,   189,    14,
     189,    12,    14,     7,   108,    15,    14,    14,    17,    12,
      16,    16,     9,     9,    35,    15,     7,    16,    16,     2,
      15,   104,    16,    79,   100,    79,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    28,    29,    30,    41,    42,    43,    60,    68,
      72,    73,    75,    39,    61,    62,    63,    64,    65,    66,
      39,    39,     0,    42,     7,    15,     9,    13,    17,     7,
       7,    11,    15,     7,    31,    32,    33,    34,    36,    39,
      47,    48,    55,    56,    58,    60,    76,    77,    78,    79,
      81,    82,    37,    39,    67,    38,     4,    11,    38,    39,
      44,    45,    46,    47,    48,    56,    57,    58,    39,    61,
      71,    74,    39,    69,    70,     7,    57,     7,     7,    11,
      80,    80,    11,     8,    13,    17,    49,     7,    16,    76,
      17,    14,    38,    44,     3,     4,     5,     6,     9,    13,
      10,    12,     9,    13,    10,    16,     7,    11,    27,    46,
      50,    51,    52,    53,    54,    15,    15,    57,    59,    39,
      38,    39,    57,    57,     9,    17,    12,    44,    44,    44,
      44,    67,    38,    71,    18,    67,    38,    70,    46,    50,
      53,    54,    11,    52,    19,    20,    21,    22,    23,    24,
      12,    25,    26,    12,    12,    76,    76,    10,    12,    14,
      14,     7,    67,    15,    14,    67,    14,    12,    12,    46,
      46,    46,    46,    46,    46,    50,    50,    16,    16,    59,
      17,    59,     9,     9,    35,    15,    16,    67,    67,    15,
      59,    76,    16,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    43,
      44,    44,    45,    45,    45,    45,    46,    46,    46,    46,
      46,    46,    46,    47,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    53,    54,    54,    54,    54,    54,
      54,    55,    56,    56,    56,    57,    58,    59,    59,    59,
      60,    60,    61,    61,    62,    62,    63,    63,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    69,    69,    70,
      70,    70,    71,    71,    71,    72,    73,    73,    74,    75,
      76,    76,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    78,    78,    79,    80,    80,    80,    81,    81,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     1,     2,     1,     3,
       1,     1,     1,     2,     3,     3,     3,     1,     1,     3,
       3,     3,     1,     3,     2,     3,     3,     3,     3,     3,
       3,     4,     1,     1,     1,     1,     4,     3,     1,     0,
       3,     3,     1,     1,     3,     1,     6,     4,     1,     1,
       5,     3,    10,     8,     1,     1,     5,     3,     6,     3,
       1,     0,     3,     1,     0,     2,     5,     7,     1,     4,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     3,     2,     2,     3,     3,     3,     5,     9,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: ProgramElementList  */
#line 158 "parser.yacc"
    {
        root = A_Program((yyvsp[0].programElementList));
        (yyval.program) = A_Program((yyvsp[0].programElementList));
    }
#line 1292 "y.tab.cpp"
    break;

  case 3: /* ProgramElementList: ProgramElement ProgramElementList  */
#line 166 "parser.yacc"
    {
        (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
    }
#line 1300 "y.tab.cpp"
    break;

  case 4: /* ProgramElementList: %empty  */
#line 171 "parser.yacc"
    {
        (yyval.programElementList) = nullptr;
    }
#line 1308 "y.tab.cpp"
    break;

  case 5: /* ProgramElement: VarDeclStmt  */
#line 178 "parser.yacc"
    {
        (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
    }
#line 1316 "y.tab.cpp"
    break;

  case 6: /* ProgramElement: StructDef  */
#line 182 "parser.yacc"
    {
        (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
    }
#line 1324 "y.tab.cpp"
    break;

  case 7: /* ProgramElement: FnDeclStmt  */
#line 186 "parser.yacc"
    {
        (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
    }
#line 1332 "y.tab.cpp"
    break;

  case 8: /* ProgramElement: FnDef  */
#line 190 "parser.yacc"
    {
        (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
    }
#line 1340 "y.tab.cpp"
    break;

  case 9: /* ProgramElement: SEMICOLON  */
#line 194 "parser.yacc"
    {
        (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
    }
#line 1348 "y.tab.cpp"
    break;

  case 10: /* ArithExpr: ArithBiOpExpr  */
#line 201 "parser.yacc"
    {
        (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[0].arithBiOpExpr)->pos, (yyvsp[0].arithBiOpExpr));
    }
#line 1356 "y.tab.cpp"
    break;

  case 11: /* ArithExpr: ExprUnit  */
#line 205 "parser.yacc"
    {
        (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
    }
#line 1364 "y.tab.cpp"
    break;

  case 12: /* ArithBiOpExpr: ArithExpr ADD ArithExpr  */
#line 212 "parser.yacc"
    {
        (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
    }
#line 1372 "y.tab.cpp"
    break;

  case 13: /* ArithBiOpExpr: ArithExpr SUB ArithExpr  */
#line 216 "parser.yacc"
    {
        (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
    }
#line 1380 "y.tab.cpp"
    break;

  case 14: /* ArithBiOpExpr: ArithExpr MUL ArithExpr  */
#line 220 "parser.yacc"
    {
        (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
    }
#line 1388 "y.tab.cpp"
    break;

  case 15: /* ArithBiOpExpr: ArithExpr DIV ArithExpr  */
#line 224 "parser.yacc"
    {
        (yyval.arithBiOpExpr) = A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr));
    }
#line 1396 "y.tab.cpp"
    break;

  case 16: /* ExprUnit: NUM  */
#line 231 "parser.yacc"
    {
        (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
    }
#line 1404 "y.tab.cpp"
    break;

  case 17: /* ExprUnit: SUB NUM  */
#line 235 "parser.yacc"
    {
        (yyval.exprUnit) = A_NumExprUnit((yyvsp[-1].pos), -1 * (yyvsp[0].tokenNum)->num);
    }
#line 1412 "y.tab.cpp"
    break;

  case 18: /* ExprUnit: ID  */
#line 239 "parser.yacc"
    {
        (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
    }
#line 1420 "y.tab.cpp"
    break;

  case 19: /* ExprUnit: LPAR ArithExpr RPAR  */
#line 243 "parser.yacc"
    {
        (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-2].pos), (yyvsp[-1].arithExpr));
    }
#line 1428 "y.tab.cpp"
    break;

  case 20: /* ExprUnit: Fncall  */
#line 247 "parser.yacc"
    {
        (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
    }
#line 1436 "y.tab.cpp"
    break;

  case 21: /* ExprUnit: ArrayExpr  */
#line 251 "parser.yacc"
    {
        (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
    }
#line 1444 "y.tab.cpp"
    break;

  case 22: /* ExprUnit: MemberExpr  */
#line 255 "parser.yacc"
    {
        (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
    }
#line 1452 "y.tab.cpp"
    break;

  case 23: /* ArrayExpr: LeftVal IndexExpr  */
#line 262 "parser.yacc"
    {
        (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-1].leftVal)->pos, (yyvsp[-1].leftVal), (yyvsp[0].indexExpr));
    }
#line 1460 "y.tab.cpp"
    break;

  case 24: /* MemberExpr: LeftVal DOT ID  */
#line 269 "parser.yacc"
    {
        (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
    }
#line 1468 "y.tab.cpp"
    break;

  case 25: /* IndexExpr: LBRACKET NUM RBRACKET  */
#line 276 "parser.yacc"
    {
        (yyval.indexExpr) = A_NumIndexExpr((yyvsp[-1].tokenNum)->pos, (yyvsp[-1].tokenNum)->num);
    }
#line 1476 "y.tab.cpp"
    break;

  case 26: /* IndexExpr: LBRACKET ID RBRACKET  */
#line 280 "parser.yacc"
    {
        (yyval.indexExpr) = A_IdIndexExpr((yyvsp[-1].tokenId)->pos, (yyvsp[-1].tokenId)->id);
    }
#line 1484 "y.tab.cpp"
    break;

  case 27: /* BoolExpr: BoolBiOpExpr  */
#line 287 "parser.yacc"
    {
        (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[0].boolBiOpExpr)->pos, (yyvsp[0].boolBiOpExpr));
    }
#line 1492 "y.tab.cpp"
    break;

  case 28: /* BoolExpr: BoolUnit  */
#line 291 "parser.yacc"
    {
        (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
    }
#line 1500 "y.tab.cpp"
    break;

  case 29: /* BoolBiOpExpr: BoolExpr AND BoolExpr  */
#line 298 "parser.yacc"
    {
        (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
    }
#line 1508 "y.tab.cpp"
    break;

  case 30: /* BoolBiOpExpr: BoolExpr OR BoolExpr  */
#line 302 "parser.yacc"
    {
        (yyval.boolBiOpExpr) = A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr));
    }
#line 1516 "y.tab.cpp"
    break;

  case 31: /* BoolUnit: LPAR ComExpr RPAR  */
#line 309 "parser.yacc"
    {
        (yyval.boolUnit) = A_ComExprUnit((yyvsp[-2].pos), (yyvsp[-1].comExpr));
    }
#line 1524 "y.tab.cpp"
    break;

  case 32: /* BoolUnit: BoolUOpExpr  */
#line 313 "parser.yacc"
    {
        (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos, (yyvsp[0].boolUOpExpr));
    }
#line 1532 "y.tab.cpp"
    break;

  case 33: /* BoolUnit: LPAR BoolExpr RPAR  */
#line 317 "parser.yacc"
    {
        (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
    }
#line 1540 "y.tab.cpp"
    break;

  case 34: /* BoolUOpExpr: NOT BoolUnit  */
#line 324 "parser.yacc"
    {
        (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[-1].pos), A_not, (yyvsp[0].boolUnit));
    }
#line 1548 "y.tab.cpp"
    break;

  case 35: /* ComExpr: ExprUnit GT ExprUnit  */
#line 331 "parser.yacc"
    {
        (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_gt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
    }
#line 1556 "y.tab.cpp"
    break;

  case 36: /* ComExpr: ExprUnit LT ExprUnit  */
#line 335 "parser.yacc"
    {
        (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_lt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
    }
#line 1564 "y.tab.cpp"
    break;

  case 37: /* ComExpr: ExprUnit GE ExprUnit  */
#line 339 "parser.yacc"
    {
        (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ge, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
    }
#line 1572 "y.tab.cpp"
    break;

  case 38: /* ComExpr: ExprUnit LE ExprUnit  */
#line 343 "parser.yacc"
    {
        (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_le, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
    }
#line 1580 "y.tab.cpp"
    break;

  case 39: /* ComExpr: ExprUnit EQ ExprUnit  */
#line 347 "parser.yacc"
    {
        (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_eq, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
    }
#line 1588 "y.tab.cpp"
    break;

  case 40: /* ComExpr: ExprUnit NEQ ExprUnit  */
#line 351 "parser.yacc"
    {
        (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ne, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
    }
#line 1596 "y.tab.cpp"
    break;

  case 41: /* AssignStmt: LeftVal ASSIGN RightVal SEMICOLON  */
#line 358 "parser.yacc"
    {
        (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
    }
#line 1604 "y.tab.cpp"
    break;

  case 42: /* LeftVal: ID  */
#line 365 "parser.yacc"
    {
        (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
    }
#line 1612 "y.tab.cpp"
    break;

  case 43: /* LeftVal: ArrayExpr  */
#line 369 "parser.yacc"
    {
        (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
    }
#line 1620 "y.tab.cpp"
    break;

  case 44: /* LeftVal: MemberExpr  */
#line 373 "parser.yacc"
    {
        (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
    }
#line 1628 "y.tab.cpp"
    break;

  case 45: /* RightVal: ArithExpr  */
#line 380 "parser.yacc"
    {
        (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
    }
#line 1636 "y.tab.cpp"
    break;

  case 46: /* Fncall: ID LPAR RightValList RPAR  */
#line 387 "parser.yacc"
    {
        (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
    }
#line 1644 "y.tab.cpp"
    break;

  case 47: /* RightValList: RightVal COMMA RightValList  */
#line 394 "parser.yacc"
    {
        (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
    }
#line 1652 "y.tab.cpp"
    break;

  case 48: /* RightValList: RightVal  */
#line 398 "parser.yacc"
    {
        (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal), NULL);
    }
#line 1660 "y.tab.cpp"
    break;

  case 49: /* RightValList: %empty  */
#line 403 "parser.yacc"
    {
        (yyval.rightValList) = NULL;
    }
#line 1668 "y.tab.cpp"
    break;

  case 50: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 410 "parser.yacc"
    {
        (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-1].varDecl)->pos, (yyvsp[-1].varDecl));
    }
#line 1676 "y.tab.cpp"
    break;

  case 51: /* VarDeclStmt: LET VarDef SEMICOLON  */
#line 414 "parser.yacc"
    {
        (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-1].varDef)->pos, (yyvsp[-1].varDef));
    }
#line 1684 "y.tab.cpp"
    break;

  case 52: /* VarDecl: VarDeclScalar  */
#line 421 "parser.yacc"
    {
        (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].varDeclScalar)->pos, (yyvsp[0].varDeclScalar));
    }
#line 1692 "y.tab.cpp"
    break;

  case 53: /* VarDecl: VarDeclArray  */
#line 425 "parser.yacc"
    {
        (yyval.varDecl) = A_VarDecl_Array((yyvsp[0].varDeclArray)->pos, (yyvsp[0].varDeclArray));
    }
#line 1700 "y.tab.cpp"
    break;

  case 54: /* VarDeclScalar: ID COLON Type  */
#line 432 "parser.yacc"
    {
        (yyval.varDeclScalar) = A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type));
    }
#line 1708 "y.tab.cpp"
    break;

  case 55: /* VarDeclScalar: ID  */
#line 436 "parser.yacc"
    {
        (yyval.varDeclScalar) = A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, NULL);
    }
#line 1716 "y.tab.cpp"
    break;

  case 56: /* VarDeclArray: ID LBRACKET NUM RBRACKET COLON Type  */
#line 443 "parser.yacc"
    {
        (yyval.varDeclArray) = A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type));
    }
#line 1724 "y.tab.cpp"
    break;

  case 57: /* VarDeclArray: ID LBRACKET NUM RBRACKET  */
#line 447 "parser.yacc"
    {
        (yyval.varDeclArray) = A_VarDeclArray((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].tokenNum)->num, NULL);
    }
#line 1732 "y.tab.cpp"
    break;

  case 58: /* VarDef: VarDefScalar  */
#line 454 "parser.yacc"
    {
        (yyval.varDef) = A_VarDef_Scalar((yyvsp[0].varDefScalar)->pos, (yyvsp[0].varDefScalar));
    }
#line 1740 "y.tab.cpp"
    break;

  case 59: /* VarDef: VarDefArray  */
#line 458 "parser.yacc"
    {
        (yyval.varDef) = A_VarDef_Array((yyvsp[0].varDefArray)->pos, (yyvsp[0].varDefArray));
    }
#line 1748 "y.tab.cpp"
    break;

  case 60: /* VarDefScalar: ID COLON Type ASSIGN RightVal  */
#line 465 "parser.yacc"
    {
        (yyval.varDefScalar) = A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal));
    }
#line 1756 "y.tab.cpp"
    break;

  case 61: /* VarDefScalar: ID ASSIGN RightVal  */
#line 469 "parser.yacc"
    {
        (yyval.varDefScalar) = A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, NULL, (yyvsp[0].rightVal));
    }
#line 1764 "y.tab.cpp"
    break;

  case 62: /* VarDefArray: ID LBRACKET NUM RBRACKET COLON Type ASSIGN LBRACE RightValList RBRACE  */
#line 476 "parser.yacc"
    {
        (yyval.varDefArray) = A_VarDefArray((yyvsp[-9].tokenId)->pos, (yyvsp[-9].tokenId)->id, (yyvsp[-7].tokenNum)->num, (yyvsp[-4].type), (yyvsp[-1].rightValList));
    }
#line 1772 "y.tab.cpp"
    break;

  case 63: /* VarDefArray: ID LBRACKET NUM RBRACKET ASSIGN LBRACE RightValList RBRACE  */
#line 480 "parser.yacc"
    {
        (yyval.varDefArray) = A_VarDefArray((yyvsp[-7].tokenId)->pos, (yyvsp[-7].tokenId)->id, (yyvsp[-5].tokenNum)->num, NULL, (yyvsp[-1].rightValList));
    }
#line 1780 "y.tab.cpp"
    break;

  case 64: /* Type: INT  */
#line 487 "parser.yacc"
    {
        (yyval.type) = A_NativeType((yyvsp[0].pos), A_intTypeKind);
    }
#line 1788 "y.tab.cpp"
    break;

  case 65: /* Type: ID  */
#line 491 "parser.yacc"
    {
        (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
    }
#line 1796 "y.tab.cpp"
    break;

  case 66: /* StructDef: STRUCT ID LBRACE FieldDeclList RBRACE  */
#line 498 "parser.yacc"
    {
        (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
    }
#line 1804 "y.tab.cpp"
    break;

  case 67: /* FieldDecl: ID COLON Type  */
#line 505 "parser.yacc"
    {
        (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[-2].tokenId)->pos, A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type)));
    }
#line 1812 "y.tab.cpp"
    break;

  case 68: /* FieldDecl: ID LBRACKET NUM RBRACKET COLON Type  */
#line 509 "parser.yacc"
    {
        (yyval.varDecl) = A_VarDecl_Array((yyvsp[-5].tokenId)->pos, A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type)));
    }
#line 1820 "y.tab.cpp"
    break;

  case 69: /* FieldDeclList: FieldDecl COMMA FieldDeclList  */
#line 516 "parser.yacc"
    {
        (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
    }
#line 1828 "y.tab.cpp"
    break;

  case 70: /* FieldDeclList: FieldDecl  */
#line 520 "parser.yacc"
    {
        (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), NULL);
    }
#line 1836 "y.tab.cpp"
    break;

  case 71: /* FieldDeclList: %empty  */
#line 525 "parser.yacc"
    {
        (yyval.varDeclList) = NULL;
    }
#line 1844 "y.tab.cpp"
    break;

  case 72: /* VarDeclList: VarDecl COMMA VarDeclList  */
#line 532 "parser.yacc"
    {
        (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
    }
#line 1852 "y.tab.cpp"
    break;

  case 73: /* VarDeclList: VarDecl  */
#line 536 "parser.yacc"
    {
        (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), NULL);
    }
#line 1860 "y.tab.cpp"
    break;

  case 74: /* VarDeclList: %empty  */
#line 541 "parser.yacc"
    {
        (yyval.varDeclList) = NULL;
    }
#line 1868 "y.tab.cpp"
    break;

  case 75: /* FnDeclStmt: FnDecl SEMICOLON  */
#line 548 "parser.yacc"
    {
        (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
    }
#line 1876 "y.tab.cpp"
    break;

  case 76: /* FnDecl: FN ID LPAR ParamDecl RPAR  */
#line 555 "parser.yacc"
    {
        (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), NULL);
    }
#line 1884 "y.tab.cpp"
    break;

  case 77: /* FnDecl: FN ID LPAR ParamDecl RPAR ARROW Type  */
#line 559 "parser.yacc"
    {
        (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
    }
#line 1892 "y.tab.cpp"
    break;

  case 78: /* ParamDecl: VarDeclList  */
#line 566 "parser.yacc"
    {
        (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
    }
#line 1900 "y.tab.cpp"
    break;

  case 79: /* FnDef: FnDecl LBRACE CodeBlockStmtList RBRACE  */
#line 573 "parser.yacc"
    {
        (yyval.fnDef) = A_FnDef((yyvsp[-3].fnDecl)->pos, (yyvsp[-3].fnDecl), (yyvsp[-1].codeBlockStmtList));
    }
#line 1908 "y.tab.cpp"
    break;

  case 80: /* CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList  */
#line 580 "parser.yacc"
    {
        (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
    }
#line 1916 "y.tab.cpp"
    break;

  case 81: /* CodeBlockStmtList: %empty  */
#line 585 "parser.yacc"
    {
        (yyval.codeBlockStmtList) = NULL;
    }
#line 1924 "y.tab.cpp"
    break;

  case 82: /* CodeBlockStmtList: SEMICOLON  */
#line 589 "parser.yacc"
    {
        (yyval.codeBlockStmtList) = NULL;
    }
#line 1932 "y.tab.cpp"
    break;

  case 83: /* CodeBlockStmt: VarDeclStmt  */
#line 596 "parser.yacc"
    {
        (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
    }
#line 1940 "y.tab.cpp"
    break;

  case 84: /* CodeBlockStmt: AssignStmt  */
#line 600 "parser.yacc"
    {
        (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
    }
#line 1948 "y.tab.cpp"
    break;

  case 85: /* CodeBlockStmt: CallStmt  */
#line 604 "parser.yacc"
    {
        (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
    }
#line 1956 "y.tab.cpp"
    break;

  case 86: /* CodeBlockStmt: IfStmt  */
#line 608 "parser.yacc"
    {
        (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
    }
#line 1964 "y.tab.cpp"
    break;

  case 87: /* CodeBlockStmt: WhileStmt  */
#line 612 "parser.yacc"
    {
        (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
    }
#line 1972 "y.tab.cpp"
    break;

  case 88: /* CodeBlockStmt: ReturnStmt  */
#line 616 "parser.yacc"
    {
        (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
    }
#line 1980 "y.tab.cpp"
    break;

  case 89: /* CodeBlockStmt: CONTINUE SEMICOLON  */
#line 620 "parser.yacc"
    {
        (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[-1].pos));
    }
#line 1988 "y.tab.cpp"
    break;

  case 90: /* CodeBlockStmt: BREAK SEMICOLON  */
#line 624 "parser.yacc"
    {
        (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[-1].pos));
    }
#line 1996 "y.tab.cpp"
    break;

  case 91: /* ReturnStmt: RETURN RightVal SEMICOLON  */
#line 631 "parser.yacc"
    {
        (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
    }
#line 2004 "y.tab.cpp"
    break;

  case 92: /* ReturnStmt: RETURN SEMICOLON  */
#line 635 "parser.yacc"
    {
        (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), NULL);
    }
#line 2012 "y.tab.cpp"
    break;

  case 93: /* CallStmt: Fncall SEMICOLON  */
#line 642 "parser.yacc"
    {
        (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
    }
#line 2020 "y.tab.cpp"
    break;

  case 94: /* BoolUnit_: LPAR ComExpr RPAR  */
#line 649 "parser.yacc"
    {
        (yyval.boolUnit) = A_ComExprUnit((yyvsp[-2].pos), (yyvsp[-1].comExpr));
    }
#line 2028 "y.tab.cpp"
    break;

  case 95: /* BoolUnit_: LPAR BoolUOpExpr RPAR  */
#line 653 "parser.yacc"
    {
        (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolUOpExpr));
    }
#line 2036 "y.tab.cpp"
    break;

  case 96: /* BoolUnit_: LPAR BoolExpr RPAR  */
#line 657 "parser.yacc"
    {
        (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
    }
#line 2044 "y.tab.cpp"
    break;

  case 97: /* IfStmt: IF BoolUnit_ LBRACE CodeBlockStmtList RBRACE  */
#line 664 "parser.yacc"
    {
        (yyval.ifStmt) = A_IfStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-1].codeBlockStmtList), NULL);
    }
#line 2052 "y.tab.cpp"
    break;

  case 98: /* IfStmt: IF BoolUnit_ LBRACE CodeBlockStmtList RBRACE ELSE LBRACE CodeBlockStmtList RBRACE  */
#line 668 "parser.yacc"
    {
        (yyval.ifStmt) = A_IfStmt((yyvsp[-8].pos), (yyvsp[-7].boolUnit), (yyvsp[-5].codeBlockStmtList), (yyvsp[-1].codeBlockStmtList));
    }
#line 2060 "y.tab.cpp"
    break;

  case 99: /* WhileStmt: WHILE BoolUnit_ LBRACE CodeBlockStmtList RBRACE  */
#line 675 "parser.yacc"
    {
        (yyval.whileStmt) = A_WhileStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-1].codeBlockStmtList));
    }
#line 2068 "y.tab.cpp"
    break;


#line 2072 "y.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 680 "parser.yacc"


extern "C" {
void yyerror(const char *s)
{
    fprintf(stderr, "%s\n", s);
}

int yywrap()
{
    return 1;
}
}
