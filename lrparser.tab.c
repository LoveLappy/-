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
#line 1 "lrparser.y"


#include "ast.h"
#include <stdio.h>

void yyerror(char *);
int yylex(void);
extern char* yytext;
extern past astRoot;

#line 82 "lrparser.tab.c"

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

#include "lrparser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_LESSEQ = 12,                    /* LESSEQ  */
  YYSYMBOL_GREATEQ = 13,                   /* GREATEQ  */
  YYSYMBOL_NOTEQ = 14,                     /* NOTEQ  */
  YYSYMBOL_EQ = 15,                        /* EQ  */
  YYSYMBOL_AND = 16,                       /* AND  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_ID = 18,                        /* ID  */
  YYSYMBOL_NUMBER = 19,                    /* NUMBER  */
  YYSYMBOL_20_ = 20,                       /* ','  */
  YYSYMBOL_21_ = 21,                       /* ';'  */
  YYSYMBOL_22_ = 22,                       /* '['  */
  YYSYMBOL_23_ = 23,                       /* ']'  */
  YYSYMBOL_24_ = 24,                       /* '='  */
  YYSYMBOL_25_ = 25,                       /* '{'  */
  YYSYMBOL_26_ = 26,                       /* '}'  */
  YYSYMBOL_27_ = 27,                       /* '('  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '!'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_35_ = 35,                       /* '<'  */
  YYSYMBOL_36_ = 36,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_CompUnits = 38,                 /* CompUnits  */
  YYSYMBOL_CompUnit = 39,                  /* CompUnit  */
  YYSYMBOL_Decl = 40,                      /* Decl  */
  YYSYMBOL_ConstDeclMul = 41,              /* ConstDeclMul  */
  YYSYMBOL_ConstDecl = 42,                 /* ConstDecl  */
  YYSYMBOL_ConstDefMul = 43,               /* ConstDefMul  */
  YYSYMBOL_ConstDef = 44,                  /* ConstDef  */
  YYSYMBOL_ConstInitValMul = 45,           /* ConstInitValMul  */
  YYSYMBOL_ConstInitVal = 46,              /* ConstInitVal  */
  YYSYMBOL_VarDeclMul = 47,                /* VarDeclMul  */
  YYSYMBOL_VarDecl = 48,                   /* VarDecl  */
  YYSYMBOL_VarDefMul = 49,                 /* VarDefMul  */
  YYSYMBOL_VarDef = 50,                    /* VarDef  */
  YYSYMBOL_InitValMul = 51,                /* InitValMul  */
  YYSYMBOL_InitVal = 52,                   /* InitVal  */
  YYSYMBOL_FuncDef = 53,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 54,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 55,                /* FuncFParam  */
  YYSYMBOL_BlockMul = 56,                  /* BlockMul  */
  YYSYMBOL_Block = 57,                     /* Block  */
  YYSYMBOL_BlockItem = 58,                 /* BlockItem  */
  YYSYMBOL_Stmt = 59,                      /* Stmt  */
  YYSYMBOL_Exp = 60,                       /* Exp  */
  YYSYMBOL_Cond = 61,                      /* Cond  */
  YYSYMBOL_LValMul = 62,                   /* LValMul  */
  YYSYMBOL_LVal = 63,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 64,                /* PrimaryExp  */
  YYSYMBOL_Number = 65,                    /* Number  */
  YYSYMBOL_UnaryExp = 66,                  /* UnaryExp  */
  YYSYMBOL_FuncRParams = 67,               /* FuncRParams  */
  YYSYMBOL_MulExp = 68,                    /* MulExp  */
  YYSYMBOL_AddExp = 69,                    /* AddExp  */
  YYSYMBOL_RelExp = 70,                    /* RelExp  */
  YYSYMBOL_EqExp = 71,                     /* EqExp  */
  YYSYMBOL_LAndExp = 72,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 73,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 74                   /* ConstExp  */
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   274


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
       2,     2,     2,    31,     2,     2,     2,    34,     2,     2,
      27,    28,    32,    29,    20,    30,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    21,
      35,    24,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    25,     2,    26,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    39,    39,    40,    43,    44,    47,    48,    51,    52,
      55,    58,    59,    62,    63,    66,    67,    70,    71,    72,
      75,    76,    79,    82,    83,    86,    87,    88,    89,    92,
      93,    96,    97,    98,   101,   102,   103,   105,   109,   110,
     113,   114,   115,   118,   119,   122,   123,   126,   127,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     143,   146,   149,   150,   153,   154,   157,   158,   159,   162,
     165,   166,   167,   168,   169,   170,   173,   174,   177,   178,
     179,   180,   183,   184,   185,   188,   189,   190,   191,   192,
     195,   196,   197,   200,   201,   204,   205,   208
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "INT",
  "VOID", "CONST", "WHILE", "BREAK", "RETURN", "CONTINUE", "LESSEQ",
  "GREATEQ", "NOTEQ", "EQ", "AND", "OR", "ID", "NUMBER", "','", "';'",
  "'['", "']'", "'='", "'{'", "'}'", "'('", "')'", "'+'", "'-'", "'!'",
  "'*'", "'/'", "'%'", "'<'", "'>'", "$accept", "CompUnits", "CompUnit",
  "Decl", "ConstDeclMul", "ConstDecl", "ConstDefMul", "ConstDef",
  "ConstInitValMul", "ConstInitVal", "VarDeclMul", "VarDecl", "VarDefMul",
  "VarDef", "InitValMul", "InitVal", "FuncDef", "FuncFParams",
  "FuncFParam", "BlockMul", "Block", "BlockItem", "Stmt", "Exp", "Cond",
  "LValMul", "LVal", "PrimaryExp", "Number", "UnaryExp", "FuncRParams",
  "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-111)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,    60,    68,    14,    51,  -111,  -111,  -111,  -111,  -111,
      38,     1,  -111,    43,    80,  -111,  -111,   231,   193,    15,
      31,    90,  -111,    22,    45,    86,  -111,    37,  -111,   231,
     231,   231,   231,  -111,  -111,  -111,  -111,    78,    97,    73,
     165,  -111,  -111,    97,    96,    77,    -2,  -111,   231,   193,
      52,  -111,    77,     4,   231,   207,    91,    80,  -111,   231,
     212,    99,   100,  -111,  -111,  -111,   231,   231,   231,   231,
     231,  -111,  -111,    -3,  -111,   109,    74,  -111,   113,    77,
     111,  -111,  -111,    77,   115,   179,  -111,  -111,   231,   207,
    -111,   117,  -111,  -111,     8,   231,  -111,  -111,  -111,  -111,
      78,    78,   193,  -111,   119,   128,    90,   130,   144,   226,
     147,  -111,  -111,  -111,   151,  -111,  -111,  -111,   150,   149,
    -111,  -111,  -111,  -111,  -111,  -111,    13,  -111,   152,  -111,
    -111,   231,  -111,   156,  -111,   163,   231,   231,  -111,  -111,
     153,  -111,  -111,  -111,  -111,   231,   207,  -111,  -111,  -111,
    -111,    99,   158,    97,    -6,   122,   171,   172,   160,  -111,
     178,  -111,   114,   231,   231,   231,   231,   231,   231,   231,
     231,   114,  -111,   189,    97,    97,    97,    97,    -6,    -6,
     122,   171,  -111,   114,  -111
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     4,     6,     7,     5,
      25,     0,    20,     0,     0,     1,     3,     0,     0,     0,
      27,     0,    22,     0,     0,     0,     8,    64,    69,     0,
       0,     0,     0,    67,    70,    68,    78,    82,    97,     0,
       0,    26,    31,    60,     0,     0,     0,    38,     0,     0,
      25,    21,     0,     0,     0,     0,     0,     0,    10,     0,
       0,    65,     0,    73,    74,    75,     0,     0,     0,     0,
       0,    23,    32,     0,    29,    40,     0,    35,     0,     0,
       0,    28,    34,     0,     0,     0,    13,    17,     0,     0,
       9,     0,    71,    76,     0,     0,    66,    79,    80,    81,
      83,    84,     0,    33,     0,     0,     0,     0,     0,     0,
       0,    51,    45,    47,     0,    52,    43,    48,     0,    67,
      39,    37,    24,    36,    11,    18,     0,    15,     0,    14,
      62,     0,    72,     0,    30,    41,     0,     0,    56,    59,
       0,    57,    46,    44,    50,     0,     0,    19,    12,    77,
      63,    42,     0,    85,    90,    93,    95,    61,     0,    58,
       0,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    53,    87,    88,    86,    89,    92,    91,
      94,    96,    55,     0,    54
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,   196,   -60,  -111,  -111,  -111,   145,  -111,   -80,
    -111,  -111,  -111,   180,  -111,   -39,  -111,   184,   125,  -111,
     -37,   101,  -110,   -15,    76,    79,   -74,  -111,  -111,   -19,
    -111,    94,   -17,    -1,    47,    49,  -111,   -13
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,    25,     7,    56,    26,   126,    86,
      11,     8,    20,    12,    73,    41,     9,    46,    47,   114,
     115,   116,   117,   118,   152,    61,    33,    34,    35,    36,
      94,    37,    43,   154,   155,   156,   157,    87
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      38,    74,   119,    42,    39,   127,   163,   164,    77,   129,
      81,    63,    64,    65,    62,    82,   113,   102,    78,    14,
      44,    21,    22,   103,    78,    42,    79,    44,   131,   165,
     166,    38,    83,   146,    42,    80,   132,    38,    38,   147,
     119,    84,   121,    45,    91,    93,   123,    97,    98,    99,
      52,    15,   173,    48,   113,    49,     1,     2,     3,    59,
      17,   182,    18,   134,    60,    19,   161,    54,    38,    55,
      23,    38,    38,   184,    17,   128,    18,   105,    10,   106,
     133,     3,   107,   108,   109,   110,    13,    42,   119,     1,
       2,     3,    27,    28,   140,   111,    71,   119,    24,    76,
     112,    29,    76,    30,    31,    32,    57,    58,    50,   119,
      66,    67,    68,    88,    75,    89,   149,   105,    44,   153,
     153,    95,   107,   108,   109,   110,    69,    70,    96,    38,
     160,   104,    27,    28,   122,   111,   167,   168,   124,    76,
     130,    29,   135,    30,    31,    32,   174,   175,   176,   177,
     153,   153,   153,   153,   105,   136,   106,   137,     3,   107,
     108,   109,   110,   100,   101,   138,   178,   179,   141,    27,
      28,   144,   111,   145,   159,   148,    76,   142,    29,   150,
      30,    31,    32,    27,    28,    59,   162,   169,   171,   170,
      40,    72,    29,   183,    30,    31,    32,    27,    28,   172,
      16,    51,    90,   120,    85,   125,    29,    53,    30,    31,
      32,    27,    28,   158,   151,   143,   180,     0,    40,   181,
      29,     0,    30,    31,    32,    27,    28,     0,     0,     0,
      27,    28,    85,     0,    29,     0,    30,    31,    32,    29,
      92,    30,    31,    32,    27,    28,     0,   139,     0,    27,
      28,     0,     0,    29,     0,    30,    31,    32,    29,     0,
      30,    31,    32
};

static const yytype_int16 yycheck[] =
{
      17,    40,    76,    18,    17,    85,    12,    13,    45,    89,
      49,    30,    31,    32,    29,    52,    76,    20,    20,     5,
       5,    20,    21,    26,    20,    40,    28,     5,    20,    35,
      36,    48,    28,    20,    49,    48,    28,    54,    55,    26,
     114,    54,    79,    28,    59,    60,    83,    66,    67,    68,
      28,     0,   162,    22,   114,    24,     5,     6,     7,    22,
      22,   171,    24,   102,    27,    27,   146,    22,    85,    24,
      27,    88,    89,   183,    22,    88,    24,     3,    18,     5,
      95,     7,     8,     9,    10,    11,    18,   102,   162,     5,
       6,     7,    18,    19,   109,    21,    23,   171,    18,    25,
      26,    27,    25,    29,    30,    31,    20,    21,    18,   183,
      32,    33,    34,    22,    18,    24,   131,     3,     5,   136,
     137,    22,     8,     9,    10,    11,    29,    30,    28,   146,
     145,    22,    18,    19,    23,    21,    14,    15,    23,    25,
      23,    27,    23,    29,    30,    31,   163,   164,   165,   166,
     167,   168,   169,   170,     3,    27,     5,    27,     7,     8,
       9,    10,    11,    69,    70,    21,   167,   168,    21,    18,
      19,    21,    21,    24,    21,    23,    25,    26,    27,    23,
      29,    30,    31,    18,    19,    22,    28,    16,    28,    17,
      25,    26,    27,     4,    29,    30,    31,    18,    19,    21,
       4,    21,    57,    78,    25,    26,    27,    23,    29,    30,
      31,    18,    19,   137,   135,   114,   169,    -1,    25,   170,
      27,    -1,    29,    30,    31,    18,    19,    -1,    -1,    -1,
      18,    19,    25,    -1,    27,    -1,    29,    30,    31,    27,
      28,    29,    30,    31,    18,    19,    -1,    21,    -1,    18,
      19,    -1,    -1,    27,    -1,    29,    30,    31,    27,    -1,
      29,    30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,    38,    39,    40,    42,    48,    53,
      18,    47,    50,    18,     5,     0,    39,    22,    24,    27,
      49,    20,    21,    27,    18,    41,    44,    18,    19,    27,
      29,    30,    31,    63,    64,    65,    66,    68,    69,    74,
      25,    52,    60,    69,     5,    28,    54,    55,    22,    24,
      18,    50,    28,    54,    22,    24,    43,    20,    21,    22,
      27,    62,    60,    66,    66,    66,    32,    33,    34,    29,
      30,    23,    26,    51,    52,    18,    25,    57,    20,    28,
      74,    52,    57,    28,    74,    25,    46,    74,    22,    24,
      44,    60,    28,    60,    67,    22,    28,    66,    66,    66,
      68,    68,    20,    26,    22,     3,     5,     8,     9,    10,
      11,    21,    26,    40,    56,    57,    58,    59,    60,    63,
      55,    57,    23,    57,    23,    26,    45,    46,    74,    46,
      23,    20,    28,    60,    52,    23,    27,    27,    21,    21,
      60,    21,    26,    58,    21,    24,    20,    26,    23,    60,
      23,    62,    61,    69,    70,    71,    72,    73,    61,    21,
      60,    46,    28,    12,    13,    35,    36,    14,    15,    16,
      17,    28,    21,    59,    69,    69,    69,    69,    70,    70,
      71,    72,    59,     4,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    41,    41,
      42,    43,    43,    44,    44,    45,    45,    46,    46,    46,
      47,    47,    48,    49,    49,    50,    50,    50,    50,    51,
      51,    52,    52,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      60,    61,    62,    62,    63,    63,    64,    64,    64,    65,
      66,    66,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    68,    69,    69,    69,    70,    70,    70,    70,    70,
      71,    71,    71,    72,    72,    73,    73,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       4,     3,     4,     3,     4,     1,     3,     1,     2,     3,
       1,     3,     3,     3,     4,     1,     3,     2,     4,     1,
       3,     1,     2,     3,     5,     5,     6,     6,     1,     3,
       2,     4,     5,     1,     2,     2,     3,     1,     1,     4,
       2,     1,     1,     5,     7,     5,     2,     2,     3,     2,
       1,     1,     3,     4,     1,     2,     3,     1,     1,     1,
       1,     3,     4,     2,     2,     2,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1
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
  case 2: /* CompUnits: CompUnit  */
#line 39 "lrparser.y"
                                         {(yyval.pAst) = newNextNode("CompUnit", (yyvsp[0].pAst), NULL); astRoot = (yyval.pAst);}
#line 1279 "lrparser.tab.c"
    break;

  case 3: /* CompUnits: CompUnits CompUnit  */
#line 40 "lrparser.y"
                                         {(yyval.pAst) = newNextNode("CompUnit", (yyvsp[-1].pAst), (yyvsp[0].pAst)); astRoot = (yyval.pAst);}
#line 1285 "lrparser.tab.c"
    break;

  case 4: /* CompUnit: Decl  */
#line 43 "lrparser.y"
                                    {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1291 "lrparser.tab.c"
    break;

  case 5: /* CompUnit: FuncDef  */
#line 44 "lrparser.y"
                                    {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1297 "lrparser.tab.c"
    break;

  case 6: /* Decl: ConstDecl  */
#line 47 "lrparser.y"
                              {(yyval.pAst) = newBasicNode("Decl", (yyvsp[0].pAst), NULL, NULL);}
#line 1303 "lrparser.tab.c"
    break;

  case 7: /* Decl: VarDecl  */
#line 48 "lrparser.y"
                              {(yyval.pAst) = newBasicNode("Decl", (yyvsp[0].pAst), NULL, NULL);}
#line 1309 "lrparser.tab.c"
    break;

  case 8: /* ConstDeclMul: ConstDef  */
#line 51 "lrparser.y"
                                          {(yyval.pAst) = newNextNode("ConstDecl_list", (yyvsp[0].pAst), NULL);}
#line 1315 "lrparser.tab.c"
    break;

  case 9: /* ConstDeclMul: ConstDeclMul ',' ConstDef  */
#line 52 "lrparser.y"
                                          {(yyval.pAst) = newNextNode("ConstDecl_list", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1321 "lrparser.tab.c"
    break;

  case 10: /* ConstDecl: CONST INT ConstDeclMul ';'  */
#line 55 "lrparser.y"
                                                   {(yyval.pAst) = newBasicNode("ConstDecl",newTypeNode("const_int"), (yyvsp[-1].pAst), NULL);}
#line 1327 "lrparser.tab.c"
    break;

  case 11: /* ConstDefMul: '[' ConstExp ']'  */
#line 58 "lrparser.y"
                                                {(yyval.pAst) = newNextNode("ConstDef_list", (yyvsp[-1].pAst), NULL);}
#line 1333 "lrparser.tab.c"
    break;

  case 12: /* ConstDefMul: ConstDefMul '[' ConstExp ']'  */
#line 59 "lrparser.y"
                                                {(yyval.pAst) = newNextNode("ConstDef_list", (yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1339 "lrparser.tab.c"
    break;

  case 13: /* ConstDef: ID '=' ConstInitVal  */
#line 62 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("ConstDef",newIDNode((yyvsp[-2].strValue)),(yyvsp[0].pAst),NULL);}
#line 1345 "lrparser.tab.c"
    break;

  case 14: /* ConstDef: ID ConstDefMul '=' ConstInitVal  */
#line 63 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("ConstDef",newNextNode("ConstDef_para", newIDNode((yyvsp[-3].strValue)), (yyvsp[-2].pAst)), (yyvsp[0].pAst), NULL);}
#line 1351 "lrparser.tab.c"
    break;

  case 15: /* ConstInitValMul: ConstInitVal  */
#line 66 "lrparser.y"
                                                {(yyval.pAst) = newNextNode("ConstInitVal_list", (yyvsp[0].pAst), NULL);}
#line 1357 "lrparser.tab.c"
    break;

  case 16: /* ConstInitValMul: ConstInitValMul ',' ConstInitVal  */
#line 67 "lrparser.y"
                                                {(yyval.pAst) = newNextNode("ConstInitVal_list", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1363 "lrparser.tab.c"
    break;

  case 17: /* ConstInitVal: ConstExp  */
#line 70 "lrparser.y"
                                         {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1369 "lrparser.tab.c"
    break;

  case 18: /* ConstInitVal: '{' '}'  */
#line 71 "lrparser.y"
                                         {(yyval.pAst) = newBasicNode("ConstInitVal_empty",NULL, NULL, NULL);}
#line 1375 "lrparser.tab.c"
    break;

  case 19: /* ConstInitVal: '{' ConstInitValMul '}'  */
#line 72 "lrparser.y"
                                         {(yyval.pAst) = (yyvsp[-1].pAst);}
#line 1381 "lrparser.tab.c"
    break;

  case 20: /* VarDeclMul: VarDef  */
#line 75 "lrparser.y"
                                         {(yyval.pAst) = newNextNode("VarDecl_list", (yyvsp[0].pAst), NULL);}
#line 1387 "lrparser.tab.c"
    break;

  case 21: /* VarDeclMul: VarDeclMul ',' VarDef  */
#line 76 "lrparser.y"
                                         {(yyval.pAst) = newNextNode("VarDecl_list", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1393 "lrparser.tab.c"
    break;

  case 22: /* VarDecl: INT VarDeclMul ';'  */
#line 79 "lrparser.y"
                                       {(yyval.pAst) = newBasicNode("VarDecl", newTypeNode("int"), (yyvsp[-1].pAst), NULL);}
#line 1399 "lrparser.tab.c"
    break;

  case 23: /* VarDefMul: '[' ConstExp ']'  */
#line 82 "lrparser.y"
                                         {(yyval.pAst) = newNextNode("VarDef_list", (yyvsp[-1].pAst), NULL);}
#line 1405 "lrparser.tab.c"
    break;

  case 24: /* VarDefMul: VarDefMul '[' ConstExp ']'  */
#line 83 "lrparser.y"
                                         {(yyval.pAst) = newNextNode("VarDef_list", (yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1411 "lrparser.tab.c"
    break;

  case 25: /* VarDef: ID  */
#line 86 "lrparser.y"
                                         {(yyval.pAst) = newBasicNode("VarDef", newIDNode((yyvsp[0].strValue)), NULL,NULL);}
#line 1417 "lrparser.tab.c"
    break;

  case 26: /* VarDef: ID '=' InitVal  */
#line 87 "lrparser.y"
                                         {(yyval.pAst) = newBasicNode("VarDef", newIDNode((yyvsp[-2].strValue)), (yyvsp[0].pAst), NULL);}
#line 1423 "lrparser.tab.c"
    break;

  case 27: /* VarDef: ID VarDefMul  */
#line 88 "lrparser.y"
                                         {(yyval.pAst) = newBasicNode("VarDef",newNextNode("VarDef_para", newIDNode((yyvsp[-1].strValue)), (yyvsp[0].pAst)), NULL, NULL);}
#line 1429 "lrparser.tab.c"
    break;

  case 28: /* VarDef: ID VarDefMul '=' InitVal  */
#line 89 "lrparser.y"
                                         {(yyval.pAst) = newBasicNode("VarDef",newNextNode("VarDef_para", newIDNode((yyvsp[-3].strValue)), (yyvsp[-2].pAst)), (yyvsp[0].pAst), NULL);}
#line 1435 "lrparser.tab.c"
    break;

  case 29: /* InitValMul: InitVal  */
#line 92 "lrparser.y"
                                         {(yyval.pAst) = newNextNode("InitVal_list", (yyvsp[0].pAst), NULL);}
#line 1441 "lrparser.tab.c"
    break;

  case 30: /* InitValMul: InitValMul ',' InitVal  */
#line 93 "lrparser.y"
                                         {(yyval.pAst) = newNextNode("InitVal_list", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1447 "lrparser.tab.c"
    break;

  case 31: /* InitVal: Exp  */
#line 96 "lrparser.y"
                                         {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1453 "lrparser.tab.c"
    break;

  case 32: /* InitVal: '{' '}'  */
#line 97 "lrparser.y"
                                         {(yyval.pAst) = newBasicNode("InitVal_empty", NULL, NULL, NULL);}
#line 1459 "lrparser.tab.c"
    break;

  case 33: /* InitVal: '{' InitValMul '}'  */
#line 98 "lrparser.y"
                                         {(yyval.pAst) = (yyvsp[-1].pAst);}
#line 1465 "lrparser.tab.c"
    break;

  case 34: /* FuncDef: VOID ID '(' ')' Block  */
#line 101 "lrparser.y"
                                                  {(yyval.pAst) = newBasicNode("FuncDef",newNextNode("FuncDef_para", newTypeNode("void"), newIDNode((yyvsp[-3].strValue))), (yyvsp[0].pAst), NULL);}
#line 1471 "lrparser.tab.c"
    break;

  case 35: /* FuncDef: INT ID '(' ')' Block  */
#line 102 "lrparser.y"
                                                  {(yyval.pAst) = newBasicNode("FuncDef",newNextNode("FuncDef_para", newTypeNode("int"), newIDNode((yyvsp[-3].strValue))), (yyvsp[0].pAst), NULL);}
#line 1477 "lrparser.tab.c"
    break;

  case 36: /* FuncDef: VOID ID '(' FuncFParams ')' Block  */
#line 103 "lrparser.y"
                                                  {past id = newIDNode((yyvsp[-4].strValue)); id -> left = (yyvsp[-2].pAst);
                                                   (yyval.pAst) = newBasicNode("FuncDef",newNextNode("FuncDef_para", newTypeNode("void"), id), (yyvsp[0].pAst), NULL);}
#line 1484 "lrparser.tab.c"
    break;

  case 37: /* FuncDef: INT ID '(' FuncFParams ')' Block  */
#line 105 "lrparser.y"
                                                  {past id = newIDNode((yyvsp[-4].strValue)); id -> left = (yyvsp[-2].pAst);
                                                   (yyval.pAst) = newBasicNode("FuncDef",newNextNode("FuncDef_para", newTypeNode("int"), id), (yyvsp[0].pAst), NULL);}
#line 1491 "lrparser.tab.c"
    break;

  case 38: /* FuncFParams: FuncFParam  */
#line 109 "lrparser.y"
                                                {(yyval.pAst) = newNextNode("FuncFParams_list", (yyvsp[0].pAst), NULL);}
#line 1497 "lrparser.tab.c"
    break;

  case 39: /* FuncFParams: FuncFParams ',' FuncFParam  */
#line 110 "lrparser.y"
                                                {(yyval.pAst) = newNextNode("FuncFParams_list", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1503 "lrparser.tab.c"
    break;

  case 40: /* FuncFParam: INT ID  */
#line 113 "lrparser.y"
                                        {(yyval.pAst) = newBasicNode("FuncFParam",newNextNode("FuncFParam_para", newTypeNode("int"), newIDNode((yyvsp[0].strValue))), NULL, NULL);}
#line 1509 "lrparser.tab.c"
    break;

  case 41: /* FuncFParam: INT ID '[' ']'  */
#line 114 "lrparser.y"
                                        {(yyval.pAst) = newBasicNode("FuncFParam",newNextNode("FuncFParam_para", newTypeNode("int"), newIDNode((yyvsp[-2].strValue))), NULL, NULL);}
#line 1515 "lrparser.tab.c"
    break;

  case 42: /* FuncFParam: INT ID '[' ']' LValMul  */
#line 115 "lrparser.y"
                                        {(yyval.pAst) = newBasicNode("FuncFParam",newNextNode("FuncFParam_para", newTypeNode("int"), newIDNode((yyvsp[-3].strValue))), (yyvsp[0].pAst), NULL);}
#line 1521 "lrparser.tab.c"
    break;

  case 43: /* BlockMul: BlockItem  */
#line 118 "lrparser.y"
                                    {(yyval.pAst) = newNextNode("Block_list", (yyvsp[0].pAst), NULL);}
#line 1527 "lrparser.tab.c"
    break;

  case 44: /* BlockMul: BlockMul BlockItem  */
#line 119 "lrparser.y"
                                    {(yyval.pAst) = newNextNode("Block_list", (yyvsp[-1].pAst), (yyvsp[0].pAst));}
#line 1533 "lrparser.tab.c"
    break;

  case 45: /* Block: '{' '}'  */
#line 122 "lrparser.y"
                                    {(yyval.pAst) = newBasicNode("Block_empty", NULL, NULL, NULL);}
#line 1539 "lrparser.tab.c"
    break;

  case 46: /* Block: '{' BlockMul '}'  */
#line 123 "lrparser.y"
                                    {(yyval.pAst) = (yyvsp[-1].pAst);}
#line 1545 "lrparser.tab.c"
    break;

  case 47: /* BlockItem: Decl  */
#line 126 "lrparser.y"
                        {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1551 "lrparser.tab.c"
    break;

  case 48: /* BlockItem: Stmt  */
#line 127 "lrparser.y"
                        {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1557 "lrparser.tab.c"
    break;

  case 49: /* Stmt: LVal '=' Exp ';'  */
#line 130 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("Assign_Stmt", (yyvsp[-3].pAst), (yyvsp[-1].pAst), NULL);}
#line 1563 "lrparser.tab.c"
    break;

  case 50: /* Stmt: Exp ';'  */
#line 131 "lrparser.y"
                                                {(yyval.pAst) = (yyvsp[-1].pAst);}
#line 1569 "lrparser.tab.c"
    break;

  case 51: /* Stmt: ';'  */
#line 132 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("Stmt_empty", NULL, NULL, NULL);}
#line 1575 "lrparser.tab.c"
    break;

  case 52: /* Stmt: Block  */
#line 133 "lrparser.y"
                                                {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1581 "lrparser.tab.c"
    break;

  case 53: /* Stmt: IF '(' Cond ')' Stmt  */
#line 134 "lrparser.y"
                                                 {(yyval.pAst) = newBasicNode("If_Stmt", (yyvsp[-2].pAst), (yyvsp[0].pAst), NULL);}
#line 1587 "lrparser.tab.c"
    break;

  case 54: /* Stmt: IF '(' Cond ')' Stmt ELSE Stmt  */
#line 135 "lrparser.y"
                                                 {(yyval.pAst) = newBasicNode("IfElse_Stmt", (yyvsp[-4].pAst), newNextNode("If_Else", (yyvsp[-2].pAst), (yyvsp[0].pAst)), NULL);}
#line 1593 "lrparser.tab.c"
    break;

  case 55: /* Stmt: WHILE '(' Cond ')' Stmt  */
#line 136 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("While_Stmt", (yyvsp[-2].pAst), (yyvsp[0].pAst), NULL);}
#line 1599 "lrparser.tab.c"
    break;

  case 56: /* Stmt: BREAK ';'  */
#line 137 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("Break_Stmt",NULL,NULL,NULL);}
#line 1605 "lrparser.tab.c"
    break;

  case 57: /* Stmt: CONTINUE ';'  */
#line 138 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("Continue_Stmt",NULL,NULL,NULL);}
#line 1611 "lrparser.tab.c"
    break;

  case 58: /* Stmt: RETURN Exp ';'  */
#line 139 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("Return_Stmt",(yyvsp[-1].pAst),NULL,NULL);}
#line 1617 "lrparser.tab.c"
    break;

  case 59: /* Stmt: RETURN ';'  */
#line 140 "lrparser.y"
                                                {(yyval.pAst) = newBasicNode("Return_Stmt",NULL,NULL,NULL);}
#line 1623 "lrparser.tab.c"
    break;

  case 60: /* Exp: AddExp  */
#line 143 "lrparser.y"
                        {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1629 "lrparser.tab.c"
    break;

  case 61: /* Cond: LOrExp  */
#line 146 "lrparser.y"
                         {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1635 "lrparser.tab.c"
    break;

  case 62: /* LValMul: '[' Exp ']'  */
#line 149 "lrparser.y"
                                    {(yyval.pAst) = newNextNode("Exp_list", (yyvsp[-1].pAst), NULL);}
#line 1641 "lrparser.tab.c"
    break;

  case 63: /* LValMul: LValMul '[' Exp ']'  */
#line 150 "lrparser.y"
                                    {(yyval.pAst) = newNextNode("Exp_list", (yyvsp[-3].pAst), (yyvsp[-1].pAst));}
#line 1647 "lrparser.tab.c"
    break;

  case 64: /* LVal: ID  */
#line 153 "lrparser.y"
                        {(yyval.pAst) = newIDNode((yyvsp[0].strValue));}
#line 1653 "lrparser.tab.c"
    break;

  case 65: /* LVal: ID LValMul  */
#line 154 "lrparser.y"
                        {(yyval.pAst) = newBasicNode("LVal_SEG", newIDNode((yyvsp[-1].strValue)), (yyvsp[0].pAst), NULL);}
#line 1659 "lrparser.tab.c"
    break;

  case 66: /* PrimaryExp: '(' Exp ')'  */
#line 157 "lrparser.y"
                              {(yyval.pAst) = (yyvsp[-1].pAst);}
#line 1665 "lrparser.tab.c"
    break;

  case 67: /* PrimaryExp: LVal  */
#line 158 "lrparser.y"
                              {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1671 "lrparser.tab.c"
    break;

  case 68: /* PrimaryExp: Number  */
#line 159 "lrparser.y"
                              {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1677 "lrparser.tab.c"
    break;

  case 69: /* Number: NUMBER  */
#line 162 "lrparser.y"
                              {(yyval.pAst) = newNum((yyvsp[0].number));}
#line 1683 "lrparser.tab.c"
    break;

  case 70: /* UnaryExp: PrimaryExp  */
#line 165 "lrparser.y"
                                    {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1689 "lrparser.tab.c"
    break;

  case 71: /* UnaryExp: ID '(' ')'  */
#line 166 "lrparser.y"
                                    {(yyval.pAst) = newBasicNode("UnaryExp", newIDNode((yyvsp[-2].strValue)), NULL, NULL);}
#line 1695 "lrparser.tab.c"
    break;

  case 72: /* UnaryExp: ID '(' FuncRParams ')'  */
#line 167 "lrparser.y"
                                    {(yyval.pAst) = newBasicNode("UnaryExp", newIDNode((yyvsp[-3].strValue)), (yyvsp[-1].pAst), NULL);}
#line 1701 "lrparser.tab.c"
    break;

  case 73: /* UnaryExp: '+' UnaryExp  */
#line 168 "lrparser.y"
                                    {(yyval.pAst) = newBasicNode("UnaryExp", newExpr('+', NULL, (yyvsp[0].pAst)), NULL, NULL);}
#line 1707 "lrparser.tab.c"
    break;

  case 74: /* UnaryExp: '-' UnaryExp  */
#line 169 "lrparser.y"
                                    {(yyval.pAst) = newBasicNode("UnaryExp", newExpr('-', NULL, (yyvsp[0].pAst)), NULL, NULL);}
#line 1713 "lrparser.tab.c"
    break;

  case 75: /* UnaryExp: '!' UnaryExp  */
#line 170 "lrparser.y"
                                    {(yyval.pAst) = newBasicNode("UnaryExp", newExpr('!', NULL, (yyvsp[0].pAst)), NULL, NULL);}
#line 1719 "lrparser.tab.c"
    break;

  case 76: /* FuncRParams: Exp  */
#line 173 "lrparser.y"
                                          {(yyval.pAst) = newNextNode("FuncRParams_list", (yyvsp[0].pAst), NULL);}
#line 1725 "lrparser.tab.c"
    break;

  case 77: /* FuncRParams: FuncRParams ',' Exp  */
#line 174 "lrparser.y"
                                          {(yyval.pAst) = newNextNode("FuncRParams_list", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1731 "lrparser.tab.c"
    break;

  case 78: /* MulExp: UnaryExp  */
#line 177 "lrparser.y"
                                          {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1737 "lrparser.tab.c"
    break;

  case 79: /* MulExp: MulExp '*' UnaryExp  */
#line 178 "lrparser.y"
                                          {(yyval.pAst) = newExpr('*', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1743 "lrparser.tab.c"
    break;

  case 80: /* MulExp: MulExp '/' UnaryExp  */
#line 179 "lrparser.y"
                                          {(yyval.pAst) = newExpr('/', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1749 "lrparser.tab.c"
    break;

  case 81: /* MulExp: MulExp '%' UnaryExp  */
#line 180 "lrparser.y"
                                          {(yyval.pAst) = newExpr('%', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1755 "lrparser.tab.c"
    break;

  case 82: /* AddExp: MulExp  */
#line 183 "lrparser.y"
                                         {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1761 "lrparser.tab.c"
    break;

  case 83: /* AddExp: AddExp '+' MulExp  */
#line 184 "lrparser.y"
                                         {(yyval.pAst) = newExpr('+', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1767 "lrparser.tab.c"
    break;

  case 84: /* AddExp: AddExp '-' MulExp  */
#line 185 "lrparser.y"
                                         {(yyval.pAst) = newExpr('-', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1773 "lrparser.tab.c"
    break;

  case 85: /* RelExp: AddExp  */
#line 188 "lrparser.y"
                                          {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1779 "lrparser.tab.c"
    break;

  case 86: /* RelExp: RelExp '<' AddExp  */
#line 189 "lrparser.y"
                                          {(yyval.pAst) = newExpr('<', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1785 "lrparser.tab.c"
    break;

  case 87: /* RelExp: RelExp LESSEQ AddExp  */
#line 190 "lrparser.y"
                                          {(yyval.pAst) = newDoubleExpr("<=", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1791 "lrparser.tab.c"
    break;

  case 88: /* RelExp: RelExp GREATEQ AddExp  */
#line 191 "lrparser.y"
                                          {(yyval.pAst) = newDoubleExpr(">=", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1797 "lrparser.tab.c"
    break;

  case 89: /* RelExp: RelExp '>' AddExp  */
#line 192 "lrparser.y"
                                          {(yyval.pAst) = newExpr('>', (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1803 "lrparser.tab.c"
    break;

  case 90: /* EqExp: RelExp  */
#line 195 "lrparser.y"
                                    {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1809 "lrparser.tab.c"
    break;

  case 91: /* EqExp: EqExp EQ RelExp  */
#line 196 "lrparser.y"
                                    {(yyval.pAst) = newDoubleExpr("==", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1815 "lrparser.tab.c"
    break;

  case 92: /* EqExp: EqExp NOTEQ RelExp  */
#line 197 "lrparser.y"
                                    {(yyval.pAst) = newDoubleExpr("!=", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1821 "lrparser.tab.c"
    break;

  case 93: /* LAndExp: EqExp  */
#line 200 "lrparser.y"
                                         {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1827 "lrparser.tab.c"
    break;

  case 94: /* LAndExp: LAndExp AND EqExp  */
#line 201 "lrparser.y"
                                         {(yyval.pAst) = newDoubleExpr("&&", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1833 "lrparser.tab.c"
    break;

  case 95: /* LOrExp: LAndExp  */
#line 204 "lrparser.y"
                                        {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1839 "lrparser.tab.c"
    break;

  case 96: /* LOrExp: LOrExp OR LAndExp  */
#line 205 "lrparser.y"
                                        {(yyval.pAst) = newDoubleExpr("||", (yyvsp[-2].pAst), (yyvsp[0].pAst));}
#line 1845 "lrparser.tab.c"
    break;

  case 97: /* ConstExp: AddExp  */
#line 208 "lrparser.y"
                              {(yyval.pAst) = (yyvsp[0].pAst);}
#line 1851 "lrparser.tab.c"
    break;


#line 1855 "lrparser.tab.c"

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

#line 211 "lrparser.y"


