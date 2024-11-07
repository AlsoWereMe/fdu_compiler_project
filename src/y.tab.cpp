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
extern "C"{
extern void yyerror(const char *s); 
extern int  yywrap();
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
  YYSYMBOL_OR = 3,                         /* OR  */
  YYSYMBOL_AND = 4,                        /* AND  */
  YYSYMBOL_NOT = 5,                        /* NOT  */
  YYSYMBOL_ADD = 6,                        /* ADD  */
  YYSYMBOL_SUB = 7,                        /* SUB  */
  YYSYMBOL_MUL = 8,                        /* MUL  */
  YYSYMBOL_DIV = 9,                        /* DIV  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_LT = 11,                        /* LT  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_LE = 13,                        /* LE  */
  YYSYMBOL_EQ = 14,                        /* EQ  */
  YYSYMBOL_NE = 15,                        /* NE  */
  YYSYMBOL_ASSIGN = 16,                    /* ASSIGN  */
  YYSYMBOL_UMINUS = 17,                    /* UMINUS  */
  YYSYMBOL_POINT = 18,                     /* POINT  */
  YYSYMBOL_ARROW = 19,                     /* ARROW  */
  YYSYMBOL_INT = 20,                       /* INT  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_FN = 23,                        /* FN  */
  YYSYMBOL_LET = 24,                       /* LET  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_CONTINUE = 26,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 27,                     /* BREAK  */
  YYSYMBOL_RETURN = 28,                    /* RETURN  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_LPARENT = 30,                   /* LPARENT  */
  YYSYMBOL_RPARENT = 31,                   /* RPARENT  */
  YYSYMBOL_LBRACKETS = 32,                 /* LBRACKETS  */
  YYSYMBOL_RBRACKETS = 33,                 /* RBRACKETS  */
  YYSYMBOL_LBRACES = 34,                   /* LBRACES  */
  YYSYMBOL_RBRACES = 35,                   /* RBRACES  */
  YYSYMBOL_COLON = 36,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 37,                 /* SEMICOLON  */
  YYSYMBOL_ID = 38,                        /* ID  */
  YYSYMBOL_NUM = 39,                       /* NUM  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Program = 42,                   /* Program  */
  YYSYMBOL_ProgramElementList = 43,        /* ProgramElementList  */
  YYSYMBOL_ProgramElement = 44,            /* ProgramElement  */
  YYSYMBOL_VarDeclStmt = 45,               /* VarDeclStmt  */
  YYSYMBOL_VarDecl = 46,                   /* VarDecl  */
  YYSYMBOL_VarDeclScalar = 47,             /* VarDeclScalar  */
  YYSYMBOL_VarDeclArray = 48,              /* VarDeclArray  */
  YYSYMBOL_VarDef = 49,                    /* VarDef  */
  YYSYMBOL_VarDefScalar = 50,              /* VarDefScalar  */
  YYSYMBOL_VarDefArray = 51,               /* VarDefArray  */
  YYSYMBOL_StructDef = 52,                 /* StructDef  */
  YYSYMBOL_VarDeclList = 53,               /* VarDeclList  */
  YYSYMBOL_FnDeclStmt = 54,                /* FnDeclStmt  */
  YYSYMBOL_FnDecl = 55,                    /* FnDecl  */
  YYSYMBOL_ParamDecl = 56,                 /* ParamDecl  */
  YYSYMBOL_FnDef = 57,                     /* FnDef  */
  YYSYMBOL_CodeBlockStmtList = 58,         /* CodeBlockStmtList  */
  YYSYMBOL_CodeBlockStmt = 59,             /* CodeBlockStmt  */
  YYSYMBOL_CallStmt = 60,                  /* CallStmt  */
  YYSYMBOL_FnCall = 61,                    /* FnCall  */
  YYSYMBOL_IfStmt = 62,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 63,                 /* WhileStmt  */
  YYSYMBOL_ReturnStmt = 64,                /* ReturnStmt  */
  YYSYMBOL_ArithExpr = 65,                 /* ArithExpr  */
  YYSYMBOL_ExprUnit = 66,                  /* ExprUnit  */
  YYSYMBOL_BoolExpr = 67,                  /* BoolExpr  */
  YYSYMBOL_BoolUnit = 68,                  /* BoolUnit  */
  YYSYMBOL_BoolUOpExpr = 69,               /* BoolUOpExpr  */
  YYSYMBOL_ComExpr = 70,                   /* ComExpr  */
  YYSYMBOL_LeftVal = 71,                   /* LeftVal  */
  YYSYMBOL_RightVal = 72,                  /* RightVal  */
  YYSYMBOL_RightValList = 73,              /* RightValList  */
  YYSYMBOL_AssignStmt = 74,                /* AssignStmt  */
  YYSYMBOL_ArrayExpr = 75,                 /* ArrayExpr  */
  YYSYMBOL_MemberExpr = 76,                /* MemberExpr  */
  YYSYMBOL_IndexExpr = 77,                 /* IndexExpr  */
  YYSYMBOL_Type = 78                       /* Type  */
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
#define YYLAST   182

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  174

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   169,   169,   177,   182,   188,   192,   196,   200,   204,
     211,   216,   223,   228,   235,   239,   246,   250,   257,   261,
     268,   272,   279,   283,   290,   296,   300,   307,   314,   318,
     325,   330,   336,   343,   347,   352,   358,   362,   366,   370,
     374,   378,   382,   386,   390,   397,   404,   411,   415,   422,
     429,   434,   441,   445,   449,   453,   457,   464,   468,   472,
     476,   486,   490,   494,   501,   505,   509,   516,   520,   524,
     531,   538,   542,   546,   550,   554,   558,   565,   569,   573,
     580,   584,   591,   595,   600,   606,   613,   620,   627,   631,
     638,   642
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
  "\"end of file\"", "error", "\"invalid token\"", "OR", "AND", "NOT",
  "ADD", "SUB", "MUL", "DIV", "GT", "LT", "GE", "LE", "EQ", "NE", "ASSIGN",
  "UMINUS", "POINT", "ARROW", "INT", "IF", "ELSE", "FN", "LET", "STRUCT",
  "CONTINUE", "BREAK", "RETURN", "WHILE", "LPARENT", "RPARENT",
  "LBRACKETS", "RBRACKETS", "LBRACES", "RBRACES", "COLON", "SEMICOLON",
  "ID", "NUM", "COMMA", "$accept", "Program", "ProgramElementList",
  "ProgramElement", "VarDeclStmt", "VarDecl", "VarDeclScalar",
  "VarDeclArray", "VarDef", "VarDefScalar", "VarDefArray", "StructDef",
  "VarDeclList", "FnDeclStmt", "FnDecl", "ParamDecl", "FnDef",
  "CodeBlockStmtList", "CodeBlockStmt", "CallStmt", "FnCall", "IfStmt",
  "WhileStmt", "ReturnStmt", "ArithExpr", "ExprUnit", "BoolExpr",
  "BoolUnit", "BoolUOpExpr", "ComExpr", "LeftVal", "RightVal",
  "RightValList", "AssignStmt", "ArrayExpr", "MemberExpr", "IndexExpr",
  "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-117)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      93,   -17,    21,    48,  -117,    70,  -117,    93,  -117,  -117,
    -117,   107,  -117,    67,    33,    72,  -117,  -117,    97,  -117,
    -117,    68,  -117,  -117,    84,  -117,   104,     9,    81,    17,
    -117,  -117,   104,     8,    98,   106,     5,     8,  -117,   117,
    -117,   116,    84,  -117,   111,  -117,  -117,  -117,    82,  -117,
    -117,  -117,   100,   112,  -117,   122,     8,    65,     9,   101,
    -117,  -117,   131,  -117,    30,  -117,  -117,    -7,  -117,    32,
      83,   121,  -117,  -117,   139,   123,     9,   125,  -117,  -117,
    -117,   119,   126,     9,  -117,  -117,  -117,     9,   124,     7,
     118,    17,   104,   142,  -117,    65,  -117,    76,   113,    27,
     132,    65,    65,    65,    65,     8,     8,     4,     9,  -117,
     113,    84,  -117,    84,   127,   133,   128,  -117,  -117,  -117,
     135,   136,  -117,  -117,    17,  -117,    65,    65,    65,    65,
      65,    65,  -117,  -117,    59,    59,  -117,  -117,   162,  -117,
     137,    17,  -117,   138,   140,     9,  -117,  -117,  -117,   134,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,     9,   156,   152,
    -117,  -117,    17,   141,   143,   144,  -117,  -117,     9,    84,
     145,   146,  -117,  -117
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,     9,     0,     2,     4,     5,     6,
       7,     0,     8,     0,    15,     0,    12,    13,     0,    18,
      19,     0,     1,     3,    35,    27,    31,     0,     0,     0,
      10,    11,     0,     0,     0,     0,     0,     0,    44,    79,
      36,     0,    34,    38,     0,    39,    40,    41,     0,    37,
      77,    78,    15,    26,    30,     0,     0,     0,     0,    58,
      57,    61,    80,    52,    81,    66,    67,     0,    21,    62,
      63,     0,    90,    91,    14,     0,     0,     0,    42,    43,
      51,     0,     0,    84,    32,    33,    45,     0,     0,     0,
       0,     0,     0,    29,    70,     0,    60,     0,    52,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,    24,
       0,    35,    50,    35,    83,     0,     0,    87,    88,    89,
       0,     0,    14,    25,     0,    59,     0,     0,     0,     0,
       0,     0,    68,    69,    53,    54,    55,    56,    65,    64,
       0,     0,    20,     0,     0,    84,    46,    85,    86,    17,
      28,    74,    72,    73,    71,    76,    75,    84,    16,    48,
      49,    82,     0,     0,     0,     0,    16,    23,    84,    35,
       0,     0,    22,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,   172,  -117,    99,   180,  -117,  -117,  -117,  -117,
    -117,  -117,   -26,  -117,  -117,  -117,  -117,   -40,  -117,  -117,
     -24,  -117,  -117,  -117,   -41,   -50,   -49,    -5,  -117,  -117,
     -23,   -12,  -116,  -117,   -20,   -19,  -117,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,    40,    53,    16,    17,    18,    19,
      20,     9,    54,    10,    11,    55,    12,    41,    42,    43,
      61,    45,    46,    47,    62,    63,    64,    65,    66,   100,
      67,   114,   115,    49,    69,    70,   120,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    48,    85,   122,    50,    51,    75,    96,    98,    99,
      56,    88,    57,    56,    56,    68,    57,    97,    44,    48,
     140,    13,    50,    51,    81,    89,   110,    99,    77,   161,
     105,   106,    82,   105,   106,    58,   150,    72,    76,    58,
     141,   163,    80,    59,    60,   118,   119,    59,    60,    27,
     -77,    94,   170,   158,    97,    73,   138,   139,   132,    14,
     134,   135,   136,   137,   -77,    28,   123,   103,   104,    29,
      22,   143,    57,   144,   166,   116,   151,   152,   153,   154,
     155,   156,   101,   102,   103,   104,    21,    44,    48,    44,
      48,    50,    51,    50,    51,    95,   142,    26,    87,     8,
      88,   -78,    32,    59,    60,    33,     8,   125,     2,    30,
      34,    35,    36,    37,    89,   -78,     1,     2,     3,   -79,
      71,    38,    39,   126,   127,   128,   129,   130,   131,   171,
       4,    83,    90,   -79,    31,    78,    91,   101,   102,   103,
     104,    24,    52,    79,    25,    44,    48,    83,    86,    50,
      51,    84,    92,    93,   107,   108,   112,   121,   109,   111,
     113,   124,   117,   133,   146,   147,   106,   145,   148,   149,
     162,   157,   164,   159,   165,   160,   167,   168,   169,    23,
     172,   173,    15
};

static const yytype_uint8 yycheck[] =
{
      24,    24,    42,    91,    24,    24,    32,    57,    58,    58,
       5,    18,     7,     5,     5,    27,     7,    58,    42,    42,
      16,    38,    42,    42,    36,    32,    76,    76,    33,   145,
       3,     4,    37,     3,     4,    30,   124,    20,    30,    30,
      36,   157,    37,    38,    39,    38,    39,    38,    39,    16,
      18,    56,   168,   141,    95,    38,   105,   106,    31,    38,
     101,   102,   103,   104,    32,    32,    92,     8,     9,    36,
       0,   111,     7,   113,   162,    87,   126,   127,   128,   129,
     130,   131,     6,     7,     8,     9,    38,   111,   111,   113,
     113,   111,   111,   113,   113,    30,   108,    30,    16,     0,
      18,    18,    34,    38,    39,    21,     7,    31,    24,    37,
      26,    27,    28,    29,    32,    32,    23,    24,    25,    18,
      39,    37,    38,    10,    11,    12,    13,    14,    15,   169,
      37,    30,    32,    32,    37,    37,    36,     6,     7,     8,
       9,    34,    38,    37,    37,   169,   169,    30,    37,   169,
     169,    35,    40,    31,    33,    16,    37,    39,    35,    34,
      34,    19,    38,    31,    31,    37,     4,    40,    33,    33,
      36,    34,    16,    35,    22,    35,    35,    34,    34,     7,
      35,    35,     2
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    24,    25,    37,    42,    43,    44,    45,    52,
      54,    55,    57,    38,    38,    46,    47,    48,    49,    50,
      51,    38,     0,    43,    34,    37,    30,    16,    32,    36,
      37,    37,    34,    21,    26,    27,    28,    29,    37,    38,
      45,    58,    59,    60,    61,    62,    63,    64,    71,    74,
      75,    76,    38,    46,    53,    56,     5,     7,    30,    38,
      39,    61,    65,    66,    67,    68,    69,    71,    72,    75,
      76,    39,    20,    38,    78,    53,    30,    68,    37,    37,
      37,    72,    68,    30,    35,    58,    37,    16,    18,    32,
      32,    36,    40,    31,    68,    30,    66,    65,    66,    67,
      70,     6,     7,     8,     9,     3,     4,    33,    16,    35,
      66,    34,    37,    34,    72,    73,    72,    38,    38,    39,
      77,    39,    78,    53,    19,    31,    10,    11,    12,    13,
      14,    15,    31,    31,    65,    65,    65,    65,    67,    67,
      16,    36,    72,    58,    58,    40,    31,    37,    33,    33,
      78,    66,    66,    66,    66,    66,    66,    34,    78,    35,
      35,    73,    36,    73,    16,    22,    78,    35,    34,    34,
      73,    58,    35,    35
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      45,    45,    46,    46,    47,    47,    48,    48,    49,    49,
      50,    50,    51,    51,    52,    53,    53,    54,    55,    55,
      56,    56,    57,    58,    58,    58,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    60,    61,    62,    62,    63,
      64,    64,    65,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    68,    68,    68,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    71,
      72,    72,    73,    73,    73,    74,    75,    76,    77,    77,
      78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     3,     1,     6,     4,     1,     1,
       5,     3,    10,     8,     5,     3,     1,     2,     7,     5,
       1,     0,     4,     2,     1,     0,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     4,     9,     5,     5,
       3,     2,     1,     3,     3,     3,     3,     1,     1,     3,
       2,     1,     1,     1,     3,     3,     1,     1,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     4,     4,     3,     1,     1,
       1,     1
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
#line 170 "parser.yacc"
  {  
    root = A_Program((yyvsp[0].programElementList));
    (yyval.program) = root;
  }
#line 1276 "y.tab.cpp"
    break;

  case 3: /* ProgramElementList: ProgramElement ProgramElementList  */
#line 178 "parser.yacc"
  {
    (yyval.programElementList) = A_ProgramElementList((yyvsp[-1].programElement), (yyvsp[0].programElementList));
  }
#line 1284 "y.tab.cpp"
    break;

  case 4: /* ProgramElementList: %empty  */
#line 182 "parser.yacc"
  {
    (yyval.programElementList) = nullptr;
  }
#line 1292 "y.tab.cpp"
    break;

  case 5: /* ProgramElement: VarDeclStmt  */
#line 189 "parser.yacc"
  {
    (yyval.programElement) = A_ProgramVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
  }
#line 1300 "y.tab.cpp"
    break;

  case 6: /* ProgramElement: StructDef  */
#line 193 "parser.yacc"
  {
    (yyval.programElement) = A_ProgramStructDef((yyvsp[0].structDef)->pos, (yyvsp[0].structDef));
  }
#line 1308 "y.tab.cpp"
    break;

  case 7: /* ProgramElement: FnDeclStmt  */
#line 197 "parser.yacc"
  {
    (yyval.programElement) = A_ProgramFnDeclStmt((yyvsp[0].fnDeclStmt)->pos, (yyvsp[0].fnDeclStmt));
  }
#line 1316 "y.tab.cpp"
    break;

  case 8: /* ProgramElement: FnDef  */
#line 201 "parser.yacc"
  {
    (yyval.programElement) = A_ProgramFnDef((yyvsp[0].fnDef)->pos, (yyvsp[0].fnDef));
  }
#line 1324 "y.tab.cpp"
    break;

  case 9: /* ProgramElement: SEMICOLON  */
#line 205 "parser.yacc"
  {
    (yyval.programElement) = A_ProgramNullStmt((yyvsp[0].pos));
  }
#line 1332 "y.tab.cpp"
    break;

  case 10: /* VarDeclStmt: LET VarDecl SEMICOLON  */
#line 212 "parser.yacc"
  {
    (yyval.varDeclStmt) = A_VarDeclStmt((yyvsp[-1].varDecl)->pos, (yyvsp[-1].varDecl));
  }
#line 1340 "y.tab.cpp"
    break;

  case 11: /* VarDeclStmt: LET VarDef SEMICOLON  */
#line 217 "parser.yacc"
  {
    (yyval.varDeclStmt) = A_VarDefStmt((yyvsp[-1].varDef)->pos, (yyvsp[-1].varDef));
  }
#line 1348 "y.tab.cpp"
    break;

  case 12: /* VarDecl: VarDeclScalar  */
#line 224 "parser.yacc"
  {
    (yyval.varDecl) = A_VarDecl_Scalar((yyvsp[0].varDeclScalar)->pos, (yyvsp[0].varDeclScalar));
  }
#line 1356 "y.tab.cpp"
    break;

  case 13: /* VarDecl: VarDeclArray  */
#line 229 "parser.yacc"
  {
    (yyval.varDecl) = A_VarDecl_Array((yyvsp[0].varDeclArray)->pos, (yyvsp[0].varDeclArray));
  }
#line 1364 "y.tab.cpp"
    break;

  case 14: /* VarDeclScalar: ID COLON Type  */
#line 236 "parser.yacc"
  {
    (yyval.varDeclScalar) = A_VarDeclScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, (yyvsp[0].type));
  }
#line 1372 "y.tab.cpp"
    break;

  case 15: /* VarDeclScalar: ID  */
#line 240 "parser.yacc"
  {
    (yyval.varDeclScalar) = A_VarDeclScalar((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id, nullptr);
  }
#line 1380 "y.tab.cpp"
    break;

  case 16: /* VarDeclArray: ID LBRACKETS NUM RBRACKETS COLON Type  */
#line 247 "parser.yacc"
  {
    (yyval.varDeclArray) = A_VarDeclArray((yyvsp[-5].tokenId)->pos, (yyvsp[-5].tokenId)->id, (yyvsp[-3].tokenNum)->num, (yyvsp[0].type));
  }
#line 1388 "y.tab.cpp"
    break;

  case 17: /* VarDeclArray: ID LBRACKETS NUM RBRACKETS  */
#line 251 "parser.yacc"
  {
    (yyval.varDeclArray) = A_VarDeclArray((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].tokenNum)->num, nullptr);
  }
#line 1396 "y.tab.cpp"
    break;

  case 18: /* VarDef: VarDefScalar  */
#line 258 "parser.yacc"
  {
    (yyval.varDef) = A_VarDef_Scalar((yyvsp[0].varDefScalar)->pos, (yyvsp[0].varDefScalar));
  }
#line 1404 "y.tab.cpp"
    break;

  case 19: /* VarDef: VarDefArray  */
#line 262 "parser.yacc"
  {
    (yyval.varDef) = A_VarDef_Array((yyvsp[0].varDefArray)->pos, (yyvsp[0].varDefArray));
  }
#line 1412 "y.tab.cpp"
    break;

  case 20: /* VarDefScalar: ID COLON Type ASSIGN RightVal  */
#line 269 "parser.yacc"
  {
    (yyval.varDefScalar) = A_VarDefScalar((yyvsp[-4].tokenId)->pos, (yyvsp[-4].tokenId)->id, (yyvsp[-2].type), (yyvsp[0].rightVal));
  }
#line 1420 "y.tab.cpp"
    break;

  case 21: /* VarDefScalar: ID ASSIGN RightVal  */
#line 273 "parser.yacc"
  {
    (yyval.varDefScalar) = A_VarDefScalar((yyvsp[-2].tokenId)->pos, (yyvsp[-2].tokenId)->id, nullptr, (yyvsp[0].rightVal));
  }
#line 1428 "y.tab.cpp"
    break;

  case 22: /* VarDefArray: ID LBRACKETS NUM RBRACKETS COLON Type ASSIGN LBRACES RightValList RBRACES  */
#line 280 "parser.yacc"
  {
    (yyval.varDefArray) = A_VarDefArray((yyvsp[-9].tokenId)->pos, (yyvsp[-9].tokenId)->id, (yyvsp[-7].tokenNum)->num, (yyvsp[-4].type), (yyvsp[-1].rightValList));
  }
#line 1436 "y.tab.cpp"
    break;

  case 23: /* VarDefArray: ID LBRACKETS NUM RBRACKETS ASSIGN LBRACES RightValList RBRACES  */
#line 284 "parser.yacc"
  {
    (yyval.varDefArray) = A_VarDefArray((yyvsp[-7].tokenId)->pos, (yyvsp[-7].tokenId)->id, (yyvsp[-5].tokenNum)->num, nullptr, (yyvsp[-1].rightValList));
  }
#line 1444 "y.tab.cpp"
    break;

  case 24: /* StructDef: STRUCT ID LBRACES VarDeclList RBRACES  */
#line 291 "parser.yacc"
  {
    (yyval.structDef) = A_StructDef((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].varDeclList));
  }
#line 1452 "y.tab.cpp"
    break;

  case 25: /* VarDeclList: VarDecl COMMA VarDeclList  */
#line 297 "parser.yacc"
  {
    (yyval.varDeclList) = A_VarDeclList((yyvsp[-2].varDecl), (yyvsp[0].varDeclList));
  }
#line 1460 "y.tab.cpp"
    break;

  case 26: /* VarDeclList: VarDecl  */
#line 301 "parser.yacc"
  {
    (yyval.varDeclList) = A_VarDeclList((yyvsp[0].varDecl), nullptr);
  }
#line 1468 "y.tab.cpp"
    break;

  case 27: /* FnDeclStmt: FnDecl SEMICOLON  */
#line 308 "parser.yacc"
  {
    (yyval.fnDeclStmt) = A_FnDeclStmt((yyvsp[-1].fnDecl)->pos, (yyvsp[-1].fnDecl));
  }
#line 1476 "y.tab.cpp"
    break;

  case 28: /* FnDecl: FN ID LPARENT ParamDecl RPARENT ARROW Type  */
#line 315 "parser.yacc"
  {
    (yyval.fnDecl) = A_FnDecl((yyvsp[-6].pos), (yyvsp[-5].tokenId)->id, (yyvsp[-3].paramDecl), (yyvsp[0].type));
  }
#line 1484 "y.tab.cpp"
    break;

  case 29: /* FnDecl: FN ID LPARENT ParamDecl RPARENT  */
#line 319 "parser.yacc"
  {
    (yyval.fnDecl) = A_FnDecl((yyvsp[-4].pos), (yyvsp[-3].tokenId)->id, (yyvsp[-1].paramDecl), nullptr);
  }
#line 1492 "y.tab.cpp"
    break;

  case 30: /* ParamDecl: VarDeclList  */
#line 326 "parser.yacc"
  {
    (yyval.paramDecl) = A_ParamDecl((yyvsp[0].varDeclList));
  }
#line 1500 "y.tab.cpp"
    break;

  case 31: /* ParamDecl: %empty  */
#line 330 "parser.yacc"
  {
    (yyval.paramDecl) = A_ParamDecl(nullptr);
  }
#line 1508 "y.tab.cpp"
    break;

  case 32: /* FnDef: FnDecl LBRACES CodeBlockStmtList RBRACES  */
#line 337 "parser.yacc"
  {
    (yyval.fnDef) = A_FnDef((yyvsp[-3].fnDecl)->pos, (yyvsp[-3].fnDecl), (yyvsp[-1].codeBlockStmtList));
  }
#line 1516 "y.tab.cpp"
    break;

  case 33: /* CodeBlockStmtList: CodeBlockStmt CodeBlockStmtList  */
#line 344 "parser.yacc"
  {
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[-1].codeBlockStmt), (yyvsp[0].codeBlockStmtList));
  }
#line 1524 "y.tab.cpp"
    break;

  case 34: /* CodeBlockStmtList: CodeBlockStmt  */
#line 348 "parser.yacc"
  {
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList((yyvsp[0].codeBlockStmt), nullptr);
  }
#line 1532 "y.tab.cpp"
    break;

  case 35: /* CodeBlockStmtList: %empty  */
#line 352 "parser.yacc"
  {
    (yyval.codeBlockStmtList) = A_CodeBlockStmtList(nullptr, nullptr);
  }
#line 1540 "y.tab.cpp"
    break;

  case 36: /* CodeBlockStmt: VarDeclStmt  */
#line 359 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockVarDeclStmt((yyvsp[0].varDeclStmt)->pos, (yyvsp[0].varDeclStmt));
  }
#line 1548 "y.tab.cpp"
    break;

  case 37: /* CodeBlockStmt: AssignStmt  */
#line 363 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockAssignStmt((yyvsp[0].assignStmt)->pos, (yyvsp[0].assignStmt));
  }
#line 1556 "y.tab.cpp"
    break;

  case 38: /* CodeBlockStmt: CallStmt  */
#line 367 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockCallStmt((yyvsp[0].callStmt)->pos, (yyvsp[0].callStmt));
  }
#line 1564 "y.tab.cpp"
    break;

  case 39: /* CodeBlockStmt: IfStmt  */
#line 371 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockIfStmt((yyvsp[0].ifStmt)->pos, (yyvsp[0].ifStmt));
  }
#line 1572 "y.tab.cpp"
    break;

  case 40: /* CodeBlockStmt: WhileStmt  */
#line 375 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockWhileStmt((yyvsp[0].whileStmt)->pos, (yyvsp[0].whileStmt));
  }
#line 1580 "y.tab.cpp"
    break;

  case 41: /* CodeBlockStmt: ReturnStmt  */
#line 379 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockReturnStmt((yyvsp[0].returnStmt)->pos, (yyvsp[0].returnStmt));
  }
#line 1588 "y.tab.cpp"
    break;

  case 42: /* CodeBlockStmt: CONTINUE SEMICOLON  */
#line 383 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockContinueStmt((yyvsp[-1].pos));
  }
#line 1596 "y.tab.cpp"
    break;

  case 43: /* CodeBlockStmt: BREAK SEMICOLON  */
#line 387 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockBreakStmt((yyvsp[-1].pos));
  }
#line 1604 "y.tab.cpp"
    break;

  case 44: /* CodeBlockStmt: SEMICOLON  */
#line 391 "parser.yacc"
  {
    (yyval.codeBlockStmt) = A_BlockNullStmt((yyvsp[0].pos));
  }
#line 1612 "y.tab.cpp"
    break;

  case 45: /* CallStmt: FnCall SEMICOLON  */
#line 398 "parser.yacc"
  {
    (yyval.callStmt) = A_CallStmt((yyvsp[-1].fnCall)->pos, (yyvsp[-1].fnCall));
  }
#line 1620 "y.tab.cpp"
    break;

  case 46: /* FnCall: ID LPARENT RightValList RPARENT  */
#line 405 "parser.yacc"
  {
    (yyval.fnCall) = A_FnCall((yyvsp[-3].tokenId)->pos, (yyvsp[-3].tokenId)->id, (yyvsp[-1].rightValList));
  }
#line 1628 "y.tab.cpp"
    break;

  case 47: /* IfStmt: IF BoolUnit LBRACES CodeBlockStmtList RBRACES ELSE LBRACES CodeBlockStmtList RBRACES  */
#line 412 "parser.yacc"
  {
    (yyval.ifStmt) = A_IfStmt((yyvsp[-8].pos), (yyvsp[-7].boolUnit), (yyvsp[-5].codeBlockStmtList), (yyvsp[-1].codeBlockStmtList));
  }
#line 1636 "y.tab.cpp"
    break;

  case 48: /* IfStmt: IF BoolUnit LBRACES CodeBlockStmtList RBRACES  */
#line 416 "parser.yacc"
  {
    (yyval.ifStmt) = A_IfStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-1].codeBlockStmtList), nullptr);
  }
#line 1644 "y.tab.cpp"
    break;

  case 49: /* WhileStmt: WHILE BoolUnit LBRACES CodeBlockStmtList RBRACES  */
#line 423 "parser.yacc"
  {
    (yyval.whileStmt) = A_WhileStmt((yyvsp[-4].pos), (yyvsp[-3].boolUnit), (yyvsp[-1].codeBlockStmtList));
  }
#line 1652 "y.tab.cpp"
    break;

  case 50: /* ReturnStmt: RETURN RightVal SEMICOLON  */
#line 430 "parser.yacc"
  {
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-2].pos), (yyvsp[-1].rightVal));
  }
#line 1660 "y.tab.cpp"
    break;

  case 51: /* ReturnStmt: RETURN SEMICOLON  */
#line 435 "parser.yacc"
  {
    (yyval.returnStmt) = A_ReturnStmt((yyvsp[-1].pos), nullptr);
  }
#line 1668 "y.tab.cpp"
    break;

  case 52: /* ArithExpr: ExprUnit  */
#line 442 "parser.yacc"
  {
    (yyval.arithExpr) = A_ExprUnit((yyvsp[0].exprUnit)->pos, (yyvsp[0].exprUnit));
  }
#line 1676 "y.tab.cpp"
    break;

  case 53: /* ArithExpr: ArithExpr ADD ArithExpr  */
#line 446 "parser.yacc"
  {
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_add, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
  }
#line 1684 "y.tab.cpp"
    break;

  case 54: /* ArithExpr: ArithExpr SUB ArithExpr  */
#line 450 "parser.yacc"
  {
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_sub, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
  }
#line 1692 "y.tab.cpp"
    break;

  case 55: /* ArithExpr: ArithExpr MUL ArithExpr  */
#line 454 "parser.yacc"
  {
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_mul, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
  }
#line 1700 "y.tab.cpp"
    break;

  case 56: /* ArithExpr: ArithExpr DIV ArithExpr  */
#line 458 "parser.yacc"
  {
    (yyval.arithExpr) = A_ArithBiOp_Expr((yyvsp[-2].arithExpr)->pos, A_ArithBiOpExpr((yyvsp[-2].arithExpr)->pos, A_div, (yyvsp[-2].arithExpr), (yyvsp[0].arithExpr)));
  }
#line 1708 "y.tab.cpp"
    break;

  case 57: /* ExprUnit: NUM  */
#line 465 "parser.yacc"
  {
    (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
  }
#line 1716 "y.tab.cpp"
    break;

  case 58: /* ExprUnit: ID  */
#line 469 "parser.yacc"
  {
    (yyval.exprUnit) = A_IdExprUnit((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
  }
#line 1724 "y.tab.cpp"
    break;

  case 59: /* ExprUnit: LPARENT ArithExpr RPARENT  */
#line 473 "parser.yacc"
  {
    (yyval.exprUnit) = A_ArithExprUnit((yyvsp[-2].pos), (yyvsp[-1].arithExpr));
  }
#line 1732 "y.tab.cpp"
    break;

  case 60: /* ExprUnit: SUB ExprUnit  */
#line 477 "parser.yacc"
  {
    /* A_ArithUExprUnit(A_pos pos, A_arithUExpr arithUExpr) */
    /* A_ArithUExpr(A_pos pos, A_arithUOp op, A_exprUnit expr) */
    if((yyvsp[0].exprUnit)->kind == A_numExprKind) {
      (yyval.exprUnit) = A_NumExprUnit((yyvsp[0].exprUnit)->pos, -((yyvsp[0].exprUnit)->u.num));
    } else {
      (yyval.exprUnit) = A_ArithUExprUnit((yyvsp[-1].pos), A_ArithUExpr((yyvsp[-1].pos), A_neg, (yyvsp[0].exprUnit)));
    }
  }
#line 1746 "y.tab.cpp"
    break;

  case 61: /* ExprUnit: FnCall  */
#line 487 "parser.yacc"
  {
    (yyval.exprUnit) = A_CallExprUnit((yyvsp[0].fnCall)->pos, (yyvsp[0].fnCall));
  }
#line 1754 "y.tab.cpp"
    break;

  case 62: /* ExprUnit: ArrayExpr  */
#line 491 "parser.yacc"
  {
    (yyval.exprUnit) = A_ArrayExprUnit((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
  }
#line 1762 "y.tab.cpp"
    break;

  case 63: /* ExprUnit: MemberExpr  */
#line 495 "parser.yacc"
  {
    (yyval.exprUnit) = A_MemberExprUnit((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
  }
#line 1770 "y.tab.cpp"
    break;

  case 64: /* BoolExpr: BoolExpr AND BoolExpr  */
#line 502 "parser.yacc"
  {
    (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[-2].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_and, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr)));
  }
#line 1778 "y.tab.cpp"
    break;

  case 65: /* BoolExpr: BoolExpr OR BoolExpr  */
#line 506 "parser.yacc"
  {
    (yyval.boolExpr) = A_BoolBiOp_Expr((yyvsp[-2].boolExpr)->pos, A_BoolBiOpExpr((yyvsp[-2].boolExpr)->pos, A_or, (yyvsp[-2].boolExpr), (yyvsp[0].boolExpr)));
  }
#line 1786 "y.tab.cpp"
    break;

  case 66: /* BoolExpr: BoolUnit  */
#line 510 "parser.yacc"
  {
    (yyval.boolExpr) = A_BoolExpr((yyvsp[0].boolUnit)->pos, (yyvsp[0].boolUnit));
  }
#line 1794 "y.tab.cpp"
    break;

  case 67: /* BoolUnit: BoolUOpExpr  */
#line 517 "parser.yacc"
  {
    (yyval.boolUnit) = A_BoolUOpExprUnit((yyvsp[0].boolUOpExpr)->pos, (yyvsp[0].boolUOpExpr));
  }
#line 1802 "y.tab.cpp"
    break;

  case 68: /* BoolUnit: LPARENT BoolExpr RPARENT  */
#line 521 "parser.yacc"
  {
    (yyval.boolUnit) = A_BoolExprUnit((yyvsp[-2].pos), (yyvsp[-1].boolExpr));
  }
#line 1810 "y.tab.cpp"
    break;

  case 69: /* BoolUnit: LPARENT ComExpr RPARENT  */
#line 525 "parser.yacc"
  {
    (yyval.boolUnit) = A_ComExprUnit((yyvsp[-2].pos), (yyvsp[-1].comExpr));
  }
#line 1818 "y.tab.cpp"
    break;

  case 70: /* BoolUOpExpr: NOT BoolUnit  */
#line 532 "parser.yacc"
  {
    (yyval.boolUOpExpr) = A_BoolUOpExpr((yyvsp[-1].pos), A_not, (yyvsp[0].boolUnit));
  }
#line 1826 "y.tab.cpp"
    break;

  case 71: /* ComExpr: ExprUnit LE ExprUnit  */
#line 539 "parser.yacc"
  {
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_le, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
  }
#line 1834 "y.tab.cpp"
    break;

  case 72: /* ComExpr: ExprUnit LT ExprUnit  */
#line 543 "parser.yacc"
  {
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_lt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
  }
#line 1842 "y.tab.cpp"
    break;

  case 73: /* ComExpr: ExprUnit GE ExprUnit  */
#line 547 "parser.yacc"
  {
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ge, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
  }
#line 1850 "y.tab.cpp"
    break;

  case 74: /* ComExpr: ExprUnit GT ExprUnit  */
#line 551 "parser.yacc"
  {
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_gt, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
  }
#line 1858 "y.tab.cpp"
    break;

  case 75: /* ComExpr: ExprUnit NE ExprUnit  */
#line 555 "parser.yacc"
  {
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_ne, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
  }
#line 1866 "y.tab.cpp"
    break;

  case 76: /* ComExpr: ExprUnit EQ ExprUnit  */
#line 559 "parser.yacc"
  {
    (yyval.comExpr) = A_ComExpr((yyvsp[-2].exprUnit)->pos, A_eq, (yyvsp[-2].exprUnit), (yyvsp[0].exprUnit));
  }
#line 1874 "y.tab.cpp"
    break;

  case 77: /* LeftVal: ArrayExpr  */
#line 566 "parser.yacc"
  {
    (yyval.leftVal) = A_ArrExprLVal((yyvsp[0].arrayExpr)->pos, (yyvsp[0].arrayExpr));
  }
#line 1882 "y.tab.cpp"
    break;

  case 78: /* LeftVal: MemberExpr  */
#line 570 "parser.yacc"
  {
    (yyval.leftVal) = A_MemberExprLVal((yyvsp[0].memberExpr)->pos, (yyvsp[0].memberExpr));
  }
#line 1890 "y.tab.cpp"
    break;

  case 79: /* LeftVal: ID  */
#line 574 "parser.yacc"
  {
    (yyval.leftVal) = A_IdExprLVal((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
  }
#line 1898 "y.tab.cpp"
    break;

  case 80: /* RightVal: ArithExpr  */
#line 581 "parser.yacc"
  {
    (yyval.rightVal) = A_ArithExprRVal((yyvsp[0].arithExpr)->pos, (yyvsp[0].arithExpr));
  }
#line 1906 "y.tab.cpp"
    break;

  case 81: /* RightVal: BoolExpr  */
#line 585 "parser.yacc"
  {
    (yyval.rightVal) = A_BoolExprRVal((yyvsp[0].boolExpr)->pos, (yyvsp[0].boolExpr));
  }
#line 1914 "y.tab.cpp"
    break;

  case 82: /* RightValList: RightVal COMMA RightValList  */
#line 592 "parser.yacc"
  {
    (yyval.rightValList) = A_RightValList((yyvsp[-2].rightVal), (yyvsp[0].rightValList));
  }
#line 1922 "y.tab.cpp"
    break;

  case 83: /* RightValList: RightVal  */
#line 596 "parser.yacc"
  {
    (yyval.rightValList) = A_RightValList((yyvsp[0].rightVal), nullptr);
  }
#line 1930 "y.tab.cpp"
    break;

  case 84: /* RightValList: %empty  */
#line 600 "parser.yacc"
  {
    (yyval.rightValList) = A_RightValList(nullptr, nullptr);
  }
#line 1938 "y.tab.cpp"
    break;

  case 85: /* AssignStmt: LeftVal ASSIGN RightVal SEMICOLON  */
#line 607 "parser.yacc"
  {
    (yyval.assignStmt) = A_AssignStmt((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].rightVal));
  }
#line 1946 "y.tab.cpp"
    break;

  case 86: /* ArrayExpr: LeftVal LBRACKETS IndexExpr RBRACKETS  */
#line 614 "parser.yacc"
  {
    (yyval.arrayExpr) = A_ArrayExpr((yyvsp[-3].leftVal)->pos, (yyvsp[-3].leftVal), (yyvsp[-1].indexExpr));
  }
#line 1954 "y.tab.cpp"
    break;

  case 87: /* MemberExpr: LeftVal POINT ID  */
#line 621 "parser.yacc"
  {
    (yyval.memberExpr) = A_MemberExpr((yyvsp[-2].leftVal)->pos, (yyvsp[-2].leftVal), (yyvsp[0].tokenId)->id);
  }
#line 1962 "y.tab.cpp"
    break;

  case 88: /* IndexExpr: ID  */
#line 628 "parser.yacc"
  {
    (yyval.indexExpr) = A_IdIndexExpr((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
  }
#line 1970 "y.tab.cpp"
    break;

  case 89: /* IndexExpr: NUM  */
#line 632 "parser.yacc"
  {
    (yyval.indexExpr) = A_NumIndexExpr((yyvsp[0].tokenNum)->pos, (yyvsp[0].tokenNum)->num);
  }
#line 1978 "y.tab.cpp"
    break;

  case 90: /* Type: INT  */
#line 639 "parser.yacc"
  {
    (yyval.type) = A_NativeType((yyvsp[0].type)->pos, A_intTypeKind);
  }
#line 1986 "y.tab.cpp"
    break;

  case 91: /* Type: ID  */
#line 643 "parser.yacc"
  {
    (yyval.type) = A_StructType((yyvsp[0].tokenId)->pos, (yyvsp[0].tokenId)->id);
  }
#line 1994 "y.tab.cpp"
    break;


#line 1998 "y.tab.cpp"

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

#line 647 "parser.yacc"


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


