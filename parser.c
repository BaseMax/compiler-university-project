/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "sds.h"

	#define YYERROR_VERBOSE 1

	extern FILE *yyin;
	extern int yylex();
	extern void yyerror(char const* msg);
	extern int line;
	#define BUFER_SIZE 1024
	char buffer[BUFER_SIZE];

	typedef struct str {
		char * val;
		size_t cap;
		size_t len;
	} str;


#line 94 "parser.c"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_DATA = 4,                       /* DATA  */
  YYSYMBOL_PROCEDURE = 5,                  /* PROCEDURE  */
  YYSYMBOL_DIVISION = 6,                   /* DIVISION  */
  YYSYMBOL_GET = 7,                        /* GET  */
  YYSYMBOL_PUT = 8,                        /* PUT  */
  YYSYMBOL_TO = 9,                         /* TO  */
  YYSYMBOL_EXECUTE = 10,                   /* EXECUTE  */
  YYSYMBOL_REPEAT = 11,                    /* REPEAT  */
  YYSYMBOL_EITHER = 12,                    /* EITHER  */
  YYSYMBOL_BOTH = 13,                      /* BOTH  */
  YYSYMBOL_NEITHER = 14,                   /* NEITHER  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_GT = 17,                        /* GT  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_NE = 19,                        /* NE  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_NOR = 24,                       /* NOR  */
  YYSYMBOL_ADD = 25,                       /* ADD  */
  YYSYMBOL_SUB = 26,                       /* SUB  */
  YYSYMBOL_MUL = 27,                       /* MUL  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_SET = 29,                       /* SET  */
  YYSYMBOL_LEFTPAREN = 30,                 /* LEFTPAREN  */
  YYSYMBOL_RIGHTPAREN = 31,                /* RIGHTPAREN  */
  YYSYMBOL_SECTION_OPEN = 32,              /* SECTION_OPEN  */
  YYSYMBOL_SECTION_CLOSE = 33,             /* SECTION_CLOSE  */
  YYSYMBOL_INTEGER = 34,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_CHAR = 36,                      /* CHAR  */
  YYSYMBOL_END = 37,                       /* END  */
  YYSYMBOL_SEMICOLON = 38,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 39,                     /* COLON  */
  YYSYMBOL_COMMANDEND = 40,                /* COMMANDEND  */
  YYSYMBOL_ID = 41,                        /* ID  */
  YYSYMBOL_NUMBER = 42,                    /* NUMBER  */
  YYSYMBOL_STRING = 43,                    /* STRING  */
  YYSYMBOL_UNSIGNED = 44,                  /* UNSIGNED  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_structure = 47,                 /* structure  */
  YYSYMBOL_heading = 48,                   /* heading  */
  YYSYMBOL_data_part = 49,                 /* data_part  */
  YYSYMBOL_data_body = 50,                 /* data_body  */
  YYSYMBOL_data_stmt = 51,                 /* data_stmt  */
  YYSYMBOL_id_list = 52,                   /* id_list  */
  YYSYMBOL_type = 53,                      /* type  */
  YYSYMBOL_exe_part = 54,                  /* exe_part  */
  YYSYMBOL_stmt_list_or_no = 55,           /* stmt_list_or_no  */
  YYSYMBOL_stmt_list = 56,                 /* stmt_list  */
  YYSYMBOL_stmt = 57,                      /* stmt  */
  YYSYMBOL_assgn_stmt = 58,                /* assgn_stmt  */
  YYSYMBOL_in_stmt = 59,                   /* in_stmt  */
  YYSYMBOL_in_list = 60,                   /* in_list  */
  YYSYMBOL_out_stmt = 61,                  /* out_stmt  */
  YYSYMBOL_out_list = 62,                  /* out_list  */
  YYSYMBOL_loop_stmt = 63,                 /* loop_stmt  */
  YYSYMBOL_cond1_stmt = 64,                /* cond1_stmt  */
  YYSYMBOL_condition = 65,                 /* condition  */
  YYSYMBOL_expression = 66                 /* expression  */
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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  109

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   122,   122,   128,   140,   145,   150,   155,   158,   163,
     166,   172,   180,   183,   190,   193,   196,   201,   209,   212,
     217,   220,   226,   227,   228,   229,   230,   233,   248,   255,
     258,   265,   271,   278,   283,   288,   297,   308,   317,   326,
     338,   342,   346,   351,   356,   361,   366,   371,   376,   379,
     382,   385,   391,   396,   401,   406
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "DATA",
  "PROCEDURE", "DIVISION", "GET", "PUT", "TO", "EXECUTE", "REPEAT",
  "EITHER", "BOTH", "NEITHER", "LT", "LE", "GT", "GE", "NE", "EQ", "NOT",
  "AND", "OR", "NOR", "ADD", "SUB", "MUL", "DIV", "SET", "LEFTPAREN",
  "RIGHTPAREN", "SECTION_OPEN", "SECTION_CLOSE", "INTEGER", "FLOAT",
  "CHAR", "END", "SEMICOLON", "COLON", "COMMANDEND", "ID", "NUMBER",
  "STRING", "UNSIGNED", "$accept", "program", "structure", "heading",
  "data_part", "data_body", "data_stmt", "id_list", "type", "exe_part",
  "stmt_list_or_no", "stmt_list", "stmt", "assgn_stmt", "in_stmt",
  "in_list", "out_stmt", "out_list", "loop_stmt", "cond1_stmt",
  "condition", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-5)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,     5,    47,   -37,    65,    35,   -37,    69,    71,   -37,
      48,    95,   -37,    61,    49,    79,    81,    61,    84,    83,
      61,    85,   -37,   -14,    87,   -36,    92,   103,    96,    99,
     -37,    83,   -37,   -37,   -37,   -37,   -37,   -37,   -37,   -37,
     -37,   -37,   100,   108,   107,   -37,   110,   111,    83,    83,
     149,   123,   -37,   -37,    87,   -37,   124,   -37,   131,   133,
      66,   -37,   -37,   -37,   128,    24,    66,    66,    66,   -37,
     -37,   -37,   -15,   -37,    66,    66,    66,   -37,   134,   -13,
      88,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,   -37,     1,    17,    33,   -37,   104,   116,   127,   134,
      72,    40,    26,   -13,   139,   -37,   -37,   -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     0,     2,     8,     0,     1,     0,     0,     5,
       0,     0,     3,     0,     0,    12,     0,     9,     0,    19,
       0,     0,    10,     0,     0,     0,     0,     0,     0,     0,
      18,    20,    22,    23,    24,    25,    26,    13,     7,    14,
      15,    16,     0,    29,     0,    32,    34,     0,    19,    19,
       0,     0,    21,    11,     0,    28,     0,    31,     0,     0,
       0,    17,    30,    33,     0,     0,     0,     0,     0,    48,
      50,    49,     0,    36,     0,     0,     0,    35,    41,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,    53,    44,    45,    42,    43,
      46,    47,    54,    55,    52,    51,    37,    39,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -37,   -37,   -37,   -37,   -37,   152,   -37,   150,   -37,   -37,
     -18,   140,   -37,   -37,   -37,   118,   -37,   117,   -37,   -37,
     -37,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     8,    16,    17,    18,    42,    12,
      29,    30,    31,    32,    33,    44,    34,    47,    35,    36,
      77,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      81,    82,    83,    84,    45,    46,    -4,    85,    86,     1,
      87,    88,    89,    90,    89,    90,    81,    82,    83,    84,
      39,    40,    41,    85,    86,    91,    87,    88,    89,    90,
      58,    59,    81,    82,    83,    84,    74,    75,    76,    85,
      86,   106,    87,    88,    89,    90,     5,     6,    81,    82,
      83,    84,    88,    89,    90,    85,    86,   107,    87,    88,
      89,    90,    78,    79,    80,    87,    88,    89,    90,     7,
      92,    93,    94,   108,     9,    10,    11,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    66,    13,    19,
      24,    25,    67,    26,    27,    86,    68,    87,    88,    89,
      90,    14,    15,    81,    82,    83,    84,    69,    70,    71,
      85,    86,    28,    87,    88,    89,    90,    20,    21,    95,
      82,    83,    84,    23,    48,    38,    85,    86,    43,    87,
      88,    89,    90,    83,    84,    49,    51,    50,    85,    86,
      53,    87,    88,    89,    90,    84,    54,    55,    56,    85,
      86,    57,    87,    88,    89,    90,    85,    86,    60,    87,
      88,    89,    90,    61,    64,    46,    65,    90,    73,    22,
      37,    52,    62,    63
};

static const yytype_int8 yycheck[] =
{
      15,    16,    17,    18,    40,    41,     0,    22,    23,     3,
      25,    26,    27,    28,    27,    28,    15,    16,    17,    18,
      34,    35,    36,    22,    23,    40,    25,    26,    27,    28,
      48,    49,    15,    16,    17,    18,    12,    13,    14,    22,
      23,    40,    25,    26,    27,    28,    41,     0,    15,    16,
      17,    18,    26,    27,    28,    22,    23,    40,    25,    26,
      27,    28,    66,    67,    68,    25,    26,    27,    28,     4,
      74,    75,    76,    40,    39,     6,     5,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    21,    40,    40,
       7,     8,    26,    10,    11,    23,    30,    25,    26,    27,
      28,     6,    41,    15,    16,    17,    18,    41,    42,    43,
      22,    23,    29,    25,    26,    27,    28,    38,    37,    31,
      16,    17,    18,    39,    32,    40,    22,    23,    41,    25,
      26,    27,    28,    17,    18,    32,    37,    41,    22,    23,
      40,    25,    26,    27,    28,    18,    38,    40,    38,    22,
      23,    40,    25,    26,    27,    28,    22,    23,     9,    25,
      26,    27,    28,    40,    33,    41,    33,    28,    40,    17,
      20,    31,    54,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    46,    47,    48,    41,     0,     4,    49,    39,
       6,     5,    54,    40,     6,    41,    50,    51,    52,    40,
      38,    37,    50,    39,     7,     8,    10,    11,    29,    55,
      56,    57,    58,    59,    61,    63,    64,    52,    40,    34,
      35,    36,    53,    41,    60,    40,    41,    62,    32,    32,
      41,    37,    56,    40,    38,    40,    38,    40,    55,    55,
       9,    40,    60,    62,    33,    33,    21,    26,    30,    41,
      42,    43,    66,    40,    12,    13,    14,    65,    66,    66,
      66,    15,    16,    17,    18,    22,    23,    25,    26,    27,
      28,    40,    66,    66,    66,    31,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    40,    40,    40
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    52,    52,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    57,    57,    58,    59,    60,
      60,    61,    61,    62,    62,    63,    64,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     0,     3,     0,     6,     0,     1,
       2,     4,     1,     3,     1,     1,     1,     6,     1,     0,
       1,     2,     1,     1,     1,     1,     1,     5,     3,     1,
       3,     3,     2,     3,     1,     5,     5,     3,     3,     3,
       2,     2,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     3,     3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* program: structure  */
#line 122 "parser.y"
                   {
		// INIT
		// printf("%s", $1);
	}
#line 1231 "parser.c"
    break;

  case 3: /* structure: heading data_part exe_part  */
#line 128 "parser.y"
                                      {
		// $$ = sdsnew("#include <iostream>\n\nusing namespace std;\n\n");
		// sdscat($$, $2);
		// sdscat($$, $3);

		printf("%s", (yyvsp[-2].string));
		printf("#include <iostream>\n\nusing namespace std;\n\n");
		printf("%s", (yyvsp[-1].string));
		printf("int main()\n{\n");
		printf("%s", (yyvsp[0].string));
		printf("return 0;\n}\n");
	}
#line 1248 "parser.c"
    break;

  case 4: /* structure: %empty  */
#line 140 "parser.y"
          {
		(yyval.string) = sdsnew("// empty program\n");
	}
#line 1256 "parser.c"
    break;

  case 5: /* heading: PROGRAM ID COLON  */
#line 145 "parser.y"
                          {
		(yyval.string) = sdsnew("// Program ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[-1].string));
		(yyval.string) = sdscat((yyval.string), "\n");
	}
#line 1266 "parser.c"
    break;

  case 6: /* heading: %empty  */
#line 150 "parser.y"
          {
		(yyval.string) = sdsempty();
	}
#line 1274 "parser.c"
    break;

  case 7: /* data_part: DATA DIVISION COMMANDEND data_body END COMMANDEND  */
#line 155 "parser.y"
                                                             {
		(yyval.string) = sdsnew((yyvsp[-2].string));
	}
#line 1282 "parser.c"
    break;

  case 8: /* data_part: %empty  */
#line 158 "parser.y"
          {
		(yyval.string) = sdsempty();
	}
#line 1290 "parser.c"
    break;

  case 9: /* data_body: data_stmt  */
#line 163 "parser.y"
                     {
		(yyval.string) = sdsnew((yyvsp[0].string));
	}
#line 1298 "parser.c"
    break;

  case 10: /* data_body: data_stmt data_body  */
#line 166 "parser.y"
                              {
		(yyval.string) = sdsnew((yyvsp[-1].string));
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1307 "parser.c"
    break;

  case 11: /* data_stmt: id_list COLON type COMMANDEND  */
#line 172 "parser.y"
                                         {
		(yyval.string) = sdsnew((yyvsp[-1].string));
		(yyval.string) = sdscat((yyval.string), " ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[-3].string));
		(yyval.string) = sdscat((yyval.string), ";\n");
	}
#line 1318 "parser.c"
    break;

  case 12: /* id_list: ID  */
#line 180 "parser.y"
            {
		(yyval.string) = sdsnew((yyvsp[0].string));
	}
#line 1326 "parser.c"
    break;

  case 13: /* id_list: ID SEMICOLON id_list  */
#line 183 "parser.y"
                               {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), ",");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1336 "parser.c"
    break;

  case 14: /* type: INTEGER  */
#line 190 "parser.y"
              {
		(yyval.string) = sdsnew("int");
	}
#line 1344 "parser.c"
    break;

  case 15: /* type: FLOAT  */
#line 193 "parser.y"
                {
		(yyval.string) = sdsnew("float");
	}
#line 1352 "parser.c"
    break;

  case 16: /* type: CHAR  */
#line 196 "parser.y"
               {
		(yyval.string) = sdsnew("char");
	}
#line 1360 "parser.c"
    break;

  case 17: /* exe_part: PROCEDURE DIVISION COMMANDEND stmt_list_or_no END COMMANDEND  */
#line 201 "parser.y"
                                                                       {
		// $$ = sdsnew("int main()\n{\n");
		// $$ = sdscat($$, $4);
		// $$ = sdscat($$, "return 0;\n}\n");
		(yyval.string) = sdsnew((yyvsp[-2].string));
	}
#line 1371 "parser.c"
    break;

  case 18: /* stmt_list_or_no: stmt_list  */
#line 209 "parser.y"
                           {
		(yyval.string) = sdsnew((yyvsp[0].string));
	}
#line 1379 "parser.c"
    break;

  case 19: /* stmt_list_or_no: %empty  */
#line 212 "parser.y"
          {
		(yyval.string) = sdsnew("// empty stmts\n");
	}
#line 1387 "parser.c"
    break;

  case 20: /* stmt_list: stmt  */
#line 217 "parser.y"
                {
		(yyval.string) = (yyvsp[0].string);
	}
#line 1395 "parser.c"
    break;

  case 21: /* stmt_list: stmt stmt_list  */
#line 220 "parser.y"
                         {
		(yyval.string) = sdsnew((yyvsp[-1].string));
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1404 "parser.c"
    break;

  case 22: /* stmt: assgn_stmt  */
#line 226 "parser.y"
                 { (yyval.string) = (yyvsp[0].string); }
#line 1410 "parser.c"
    break;

  case 23: /* stmt: in_stmt  */
#line 227 "parser.y"
                  { (yyval.string) = (yyvsp[0].string); }
#line 1416 "parser.c"
    break;

  case 24: /* stmt: out_stmt  */
#line 228 "parser.y"
                   { (yyval.string) = (yyvsp[0].string); }
#line 1422 "parser.c"
    break;

  case 25: /* stmt: loop_stmt  */
#line 229 "parser.y"
                    { (yyval.string) = (yyvsp[0].string); }
#line 1428 "parser.c"
    break;

  case 26: /* stmt: cond1_stmt  */
#line 230 "parser.y"
                     { (yyval.string) = (yyvsp[0].string); }
#line 1434 "parser.c"
    break;

  case 27: /* assgn_stmt: SET ID TO expression COMMANDEND  */
#line 233 "parser.y"
                                            {
		(yyval.string) = sdsnew((yyvsp[-3].string));
		(yyval.string) = sdscat((yyval.string), " = ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[-1].string));
		(yyval.string) = sdscat((yyval.string), ";\n");
	}
#line 1445 "parser.c"
    break;

  case 28: /* in_stmt: GET in_list COMMANDEND  */
#line 248 "parser.y"
                                {
		(yyval.string) = sdsnew("cin >> ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[-1].string));
		(yyval.string) = sdscat((yyval.string), ";\n");
	}
#line 1455 "parser.c"
    break;

  case 29: /* in_list: ID  */
#line 255 "parser.y"
            {
		(yyval.string) = sdsnew((yyvsp[0].string));
	}
#line 1463 "parser.c"
    break;

  case 30: /* in_list: ID SEMICOLON in_list  */
#line 258 "parser.y"
                               {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " >> ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1473 "parser.c"
    break;

  case 31: /* out_stmt: PUT out_list COMMANDEND  */
#line 265 "parser.y"
                                  {
		(yyval.string) = sdsnew("cout << ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[-1].string));
		(yyval.string) = sdscat((yyval.string), " << \"\\n\"");
		(yyval.string) = sdscat((yyval.string), ";\n");
	}
#line 1484 "parser.c"
    break;

  case 32: /* out_stmt: PUT COMMANDEND  */
#line 271 "parser.y"
                         {
		(yyval.string) = sdsnew("cout << ");
		(yyval.string) = sdscat((yyval.string), " \"\\n\"");
		(yyval.string) = sdscat((yyval.string), ";\n");
	}
#line 1494 "parser.c"
    break;

  case 33: /* out_list: ID SEMICOLON out_list  */
#line 278 "parser.y"
                                {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " << ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1504 "parser.c"
    break;

  case 34: /* out_list: ID  */
#line 283 "parser.y"
             {
		(yyval.string) = sdsnew((yyvsp[0].string));
	}
#line 1512 "parser.c"
    break;

  case 35: /* loop_stmt: REPEAT SECTION_OPEN stmt_list_or_no SECTION_CLOSE condition  */
#line 288 "parser.y"
                                                                       {
		(yyval.string) = sdsnew("while( ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
		(yyval.string) = sdscat((yyval.string), " ) {\n");
		(yyval.string) = sdscat((yyval.string), (yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), "}\n");
	}
#line 1524 "parser.c"
    break;

  case 36: /* cond1_stmt: EXECUTE SECTION_OPEN stmt_list_or_no SECTION_CLOSE COMMANDEND  */
#line 297 "parser.y"
                                                                          {
		(yyval.string) = sdsnew("// execute ");
		 (yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
		 //$$ = sdscat($$, " ) {\n");
		 (yyval.string) = sdscat((yyval.string), "\n");
		//$$ = sdscat($$, "{\n");
		(yyval.string) = sdscat((yyval.string), (yyvsp[-2].string));
		//$$ = sdscat($$, "}\n");
	}
#line 1538 "parser.c"
    break;

  case 37: /* condition: EITHER expression COMMANDEND  */
#line 308 "parser.y"
                                        {
		(yyval.string) = sdsnew((yyvsp[-1].string));

		//$$ = sdsnew($1);
		//$$ = sdscat($$, $2);

		// $$ = sdscat($$, " OR ");
		// $$ = sdscat($$, $3);
	}
#line 1552 "parser.c"
    break;

  case 38: /* condition: NEITHER expression COMMANDEND  */
#line 317 "parser.y"
                                        {
		(yyval.string) = sdsnew((yyvsp[-1].string));

		//$$ = sdsnew($1);
		//$$ = sdscat($$, $2);

		// $$ = sdscat($$, " NOR ");
		// $$ = sdscat($$, $3);
	}
#line 1566 "parser.c"
    break;

  case 39: /* condition: BOTH expression COMMANDEND  */
#line 326 "parser.y"
                                     {
		(yyval.string) = sdsnew((yyvsp[-1].string));

		//$$ = sdsnew($1);
		//$$ = sdscat($$, $2);

		// $$ = sdscat($$, " AND ");
		// $$ = sdscat($$, $3);
	}
#line 1580 "parser.c"
    break;

  case 40: /* expression: SUB expression  */
#line 338 "parser.y"
                        {
		(yyval.string) = sdsnew("- ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1589 "parser.c"
    break;

  case 41: /* expression: NOT expression  */
#line 342 "parser.y"
                         {
		(yyval.string) = sdsnew("! ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1598 "parser.c"
    break;

  case 42: /* expression: expression GT expression  */
#line 346 "parser.y"
                                   {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " > ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1608 "parser.c"
    break;

  case 43: /* expression: expression GE expression  */
#line 351 "parser.y"
                                   {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " >= ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1618 "parser.c"
    break;

  case 44: /* expression: expression LT expression  */
#line 356 "parser.y"
                                   {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " < ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1628 "parser.c"
    break;

  case 45: /* expression: expression LE expression  */
#line 361 "parser.y"
                                   {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " <= ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1638 "parser.c"
    break;

  case 46: /* expression: expression AND expression  */
#line 366 "parser.y"
                                    {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " && ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1648 "parser.c"
    break;

  case 47: /* expression: expression OR expression  */
#line 371 "parser.y"
                                   {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " || ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1658 "parser.c"
    break;

  case 48: /* expression: ID  */
#line 376 "parser.y"
             {
		(yyval.string) = (yyvsp[0].string);
	}
#line 1666 "parser.c"
    break;

  case 49: /* expression: STRING  */
#line 379 "parser.y"
                 {
		(yyval.string) = (yyvsp[0].string);
	}
#line 1674 "parser.c"
    break;

  case 50: /* expression: NUMBER  */
#line 382 "parser.y"
                 {
		(yyval.string) = (yyvsp[0].string);
	}
#line 1682 "parser.c"
    break;

  case 51: /* expression: expression DIV expression  */
#line 385 "parser.y"
                                    {
		// if ($3 == 0) { yyerror("Cannot divide by zero"); exit(1); } else {}
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " / ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1693 "parser.c"
    break;

  case 52: /* expression: expression MUL expression  */
#line 391 "parser.y"
                                    {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " * ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1703 "parser.c"
    break;

  case 53: /* expression: LEFTPAREN expression RIGHTPAREN  */
#line 396 "parser.y"
                                          {
		(yyval.string) = sdsnew("( ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[-1].string));
		(yyval.string) = sdscat((yyval.string), " )");
	}
#line 1713 "parser.c"
    break;

  case 54: /* expression: expression ADD expression  */
#line 401 "parser.y"
                                    {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " + ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1723 "parser.c"
    break;

  case 55: /* expression: expression SUB expression  */
#line 406 "parser.y"
                                    {
		(yyval.string) = sdsnew((yyvsp[-2].string));
		(yyval.string) = sdscat((yyval.string), " - ");
		(yyval.string) = sdscat((yyval.string), (yyvsp[0].string));
	}
#line 1733 "parser.c"
    break;


#line 1737 "parser.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 413 "parser.y"


int yywrap()
{
	return 1;
}

void yyerror(char const* msg)
{
	// fprintf(stderr, "[%d]:%s\n", line, msg);
}

int main(int argc, char *argv[])
{
	// Read a file
	if(argc > 1)
		yyin = fopen(argv[1], "r");

	// Parse
	yyparse();

	return 0;
}

