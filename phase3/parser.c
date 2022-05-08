/* A Bison parser, made by GNU Bison 3.7.5.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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

    #include <stdbool.h>
    #include <stdio.h>
    #include "quads.h" 
    #include "symT.h"
    #include <stdlib.h>

    int yyerror (char* yaccProvidedMessage);
    int yylex(void);
    int lvalue_checker(const char *name);

    extern char* yytext;
    extern FILE* yyin;

    char *str;
    char *ourVar;

    int scope_flag = 1;
    int functions = 0;
    int func_counter = 0;
    int loop_scope = 0;
    int call_flag = 0;
    int func_flag = 0;
    int local_flag = 0;

#line 97 "parser.c"

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
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_REAL = 4,                       /* REAL  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_FUNCTION = 11,                  /* FUNCTION  */
  YYSYMBOL_RETURN = 12,                    /* RETURN  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_NOT = 16,                       /* NOT  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_LOCAL = 18,                     /* LOCAL  */
  YYSYMBOL_TRUE = 19,                      /* TRUE  */
  YYSYMBOL_FALSE = 20,                     /* FALSE  */
  YYSYMBOL_NIL = 21,                       /* NIL  */
  YYSYMBOL_OP_EQUALS = 22,                 /* OP_EQUALS  */
  YYSYMBOL_OP_PLUS = 23,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 24,                  /* OP_MINUS  */
  YYSYMBOL_OP_ASTERISK = 25,               /* OP_ASTERISK  */
  YYSYMBOL_OP_SLASH = 26,                  /* OP_SLASH  */
  YYSYMBOL_OP_PERCENTAGE = 27,             /* OP_PERCENTAGE  */
  YYSYMBOL_OP_EQ_EQ = 28,                  /* OP_EQ_EQ  */
  YYSYMBOL_OP_NOT_EQ = 29,                 /* OP_NOT_EQ  */
  YYSYMBOL_OP_PLUS_PLUS = 30,              /* OP_PLUS_PLUS  */
  YYSYMBOL_OP_MINUS_MINUS = 31,            /* OP_MINUS_MINUS  */
  YYSYMBOL_OP_GREATER = 32,                /* OP_GREATER  */
  YYSYMBOL_OP_LESSER = 33,                 /* OP_LESSER  */
  YYSYMBOL_OP_GREATER_EQ = 34,             /* OP_GREATER_EQ  */
  YYSYMBOL_OP_LESSER_EQ = 35,              /* OP_LESSER_EQ  */
  YYSYMBOL_LEFT_BRACE = 36,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 37,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_BRACKET = 38,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 39,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_PAR = 40,                  /* LEFT_PAR  */
  YYSYMBOL_RIGHT_PAR = 41,                 /* RIGHT_PAR  */
  YYSYMBOL_SEMICOLON = 42,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 43,                     /* COMMA  */
  YYSYMBOL_COLON = 44,                     /* COLON  */
  YYSYMBOL_COL_COL = 45,                   /* COL_COL  */
  YYSYMBOL_DOT = 46,                       /* DOT  */
  YYSYMBOL_DOT_DOT = 47,                   /* DOT_DOT  */
  YYSYMBOL_LINE_COMM = 48,                 /* LINE_COMM  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_program = 50,                   /* program  */
  YYSYMBOL_stmt = 51,                      /* stmt  */
  YYSYMBOL_expr = 52,                      /* expr  */
  YYSYMBOL_term = 53,                      /* term  */
  YYSYMBOL_assignexpr = 54,                /* assignexpr  */
  YYSYMBOL_primary = 55,                   /* primary  */
  YYSYMBOL_lvalue = 56,                    /* lvalue  */
  YYSYMBOL_member = 57,                    /* member  */
  YYSYMBOL_call = 58,                      /* call  */
  YYSYMBOL_59_1 = 59,                      /* $@1  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_61_3 = 61,                      /* $@3  */
  YYSYMBOL_callsuffix = 62,                /* callsuffix  */
  YYSYMBOL_normcall = 63,                  /* normcall  */
  YYSYMBOL_64_4 = 64,                      /* $@4  */
  YYSYMBOL_methodcall = 65,                /* methodcall  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_elist = 67,                     /* elist  */
  YYSYMBOL_objectdef = 68,                 /* objectdef  */
  YYSYMBOL_indexed = 69,                   /* indexed  */
  YYSYMBOL_indexedelem = 70,               /* indexedelem  */
  YYSYMBOL_func_stmt = 71,                 /* func_stmt  */
  YYSYMBOL_block = 72,                     /* block  */
  YYSYMBOL_73_6 = 73,                      /* $@6  */
  YYSYMBOL_74_7 = 74,                      /* $@7  */
  YYSYMBOL_75_8 = 75,                      /* $@8  */
  YYSYMBOL_funcname = 76,                  /* funcname  */
  YYSYMBOL_funcprefix = 77,                /* funcprefix  */
  YYSYMBOL_funcargs = 78,                  /* funcargs  */
  YYSYMBOL_funcbody = 79,                  /* funcbody  */
  YYSYMBOL_funcdef = 80,                   /* funcdef  */
  YYSYMBOL_const = 81,                     /* const  */
  YYSYMBOL_idlist = 82,                    /* idlist  */
  YYSYMBOL_ifstmt = 83,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 84,                 /* whilestmt  */
  YYSYMBOL_85_9 = 85,                      /* $@9  */
  YYSYMBOL_forstmt = 86,                   /* forstmt  */
  YYSYMBOL_87_10 = 87,                     /* $@10  */
  YYSYMBOL_returnstmt = 88                 /* returnstmt  */
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
#define YYFINAL  69
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   539

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    56,    59,    60,    61,    62,    63,    64,
      72,    80,    81,    82,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   102,
     103,   104,   105,   113,   121,   129,   137,   140,   173,   174,
     175,   176,   177,   180,   237,   258,   270,   273,   274,   275,
     276,   279,   279,   280,   280,   281,   281,   284,   285,   288,
     288,   291,   291,   294,   295,   296,   299,   300,   303,   304,
     307,   310,   311,   314,   314,   323,   325,   323,   334,   352,
     373,   378,   384,   395,   398,   399,   400,   401,   402,   403,
     406,   418,   429,   432,   433,   436,   436,   445,   445,   454,
     462
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
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "REAL",
  "STRING", "IDENTIFIER", "IF", "ELSE", "WHILE", "FOR", "FUNCTION",
  "RETURN", "BREAK", "CONTINUE", "AND", "NOT", "OR", "LOCAL", "TRUE",
  "FALSE", "NIL", "OP_EQUALS", "OP_PLUS", "OP_MINUS", "OP_ASTERISK",
  "OP_SLASH", "OP_PERCENTAGE", "OP_EQ_EQ", "OP_NOT_EQ", "OP_PLUS_PLUS",
  "OP_MINUS_MINUS", "OP_GREATER", "OP_LESSER", "OP_GREATER_EQ",
  "OP_LESSER_EQ", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_PAR", "RIGHT_PAR", "SEMICOLON", "COMMA", "COLON",
  "COL_COL", "DOT", "DOT_DOT", "LINE_COMM", "$accept", "program", "stmt",
  "expr", "term", "assignexpr", "primary", "lvalue", "member", "call",
  "$@1", "$@2", "$@3", "callsuffix", "normcall", "$@4", "methodcall",
  "$@5", "elist", "objectdef", "indexed", "indexedelem", "func_stmt",
  "block", "$@6", "$@7", "$@8", "funcname", "funcprefix", "funcargs",
  "funcbody", "funcdef", "const", "idlist", "ifstmt", "whilestmt", "$@9",
  "forstmt", "$@10", "returnstmt", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     161,   -59,   -59,   -59,   -59,   -30,    -3,     0,    42,     1,
      15,    16,   250,    45,   -59,   -59,   -59,   250,     5,     5,
      22,   204,   227,   -59,    54,    78,   161,   295,   -59,   -59,
     -59,    80,   -59,   -22,   -59,   -59,    40,   -59,   -59,   -59,
     -59,   -59,   -59,   250,   250,   250,   -59,   -59,   -59,   316,
     -59,   -59,   -59,   -59,     2,    86,     9,    -8,     9,    61,
     161,   250,   274,    52,    62,    57,   358,    64,   -59,   -59,
     -59,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   -59,   250,   -59,   -59,   250,    97,
     -14,   250,   101,    69,   106,    77,   379,   400,    72,   -59,
      74,   -59,   161,    79,    60,   250,   -59,   -59,    83,   -59,
      82,   491,   478,     2,     2,   -59,   -59,   -59,   504,   504,
     252,   252,   252,   252,   463,   122,   -59,   -59,   -59,   -59,
     -59,   -59,   421,   -59,   250,    87,    88,   -59,   -59,   161,
     -59,   250,   -59,   -59,   -59,   250,   -59,   -59,    91,   -59,
     250,   117,   -59,    92,   106,   -59,   126,   161,   337,   -59,
     442,   250,    94,    98,   -59,   -59,   161,   -59,   250,   -59,
      99,   -59,   250,   -59,   102,   -59,   103,   -59,   -59,   161,
     -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    84,    85,    86,    43,     0,     0,     0,    79,     0,
       0,     0,     0,     0,    88,    89,    87,     0,     0,     0,
      75,    65,     0,    13,     0,     0,     3,     0,    28,    14,
      36,    38,    46,    39,    40,    11,     0,    12,    42,     5,
       6,     7,     8,     0,     0,    65,    78,    80,    99,     0,
       9,    10,    31,    44,    30,     0,    32,    51,    34,     0,
       0,     0,    63,     0,     0,    68,     0,     0,    45,     1,
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     0,    33,    35,     0,     0,
       0,     0,     0,     0,    92,     0,     0,     0,     0,   100,
       0,    74,    72,     0,     0,    65,    66,    67,     0,    29,
      41,    26,    27,    15,    16,    17,    18,    19,    24,    25,
      20,    22,    21,    23,    37,     0,    47,    59,    61,    54,
      57,    58,     0,    49,    65,    90,     0,    82,    83,     0,
      95,     0,    55,    71,    76,     0,    64,    69,     0,    48,
      65,     0,    50,     0,    92,    81,    93,     0,     0,    77,
       0,    65,     0,     0,    52,    91,     0,    96,    65,    70,
       0,    60,    65,    94,     0,    56,     0,    97,    62,     0,
      98
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   116,   -58,    -9,   -59,   -59,   -59,    -4,   -59,    35,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -44,   -59,
      50,   -59,    51,    65,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -13,   -59,     8,   -59,   -59,   -59,   -59,   -59,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      93,    90,   148,   129,   130,   150,   131,   151,    63,    34,
      64,    65,   103,    35,    59,    60,   159,    47,    36,    95,
     138,    37,    38,   136,    39,    40,   157,    41,   179,    42
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      49,    98,   102,    52,     1,     2,     3,     4,    54,    67,
      43,     4,    62,    66,    56,    58,    91,    12,   -51,    13,
      14,    15,    16,    13,    92,    17,   127,    75,    76,    77,
      91,    18,    19,   128,    96,    97,    62,    44,    92,    21,
      45,    22,   100,    48,   102,    55,    24,    88,    46,   -53,
      24,    53,   104,    57,    57,    89,   -53,    50,    51,   -73,
      68,   146,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,    71,   124,    72,    69,   125,
      94,   156,   132,    73,    74,    75,    76,    77,    78,    79,
     153,   106,    80,    81,    82,    83,    62,     8,   101,   167,
     108,   107,    85,   126,   145,   110,   162,   133,   173,   134,
      86,    87,   135,    20,   141,   142,   144,   170,    88,    61,
     -53,   180,   -55,   163,   174,    62,    89,   -53,   176,   155,
     154,   161,   158,   164,   166,   171,   160,    71,   172,    72,
     175,    62,    70,   177,   178,    73,    74,    75,    76,    77,
      78,    79,    62,   143,    80,    81,    82,    83,   147,    62,
     137,   149,   165,    62,     1,     2,     3,     4,     5,     0,
       6,     7,     8,     9,    10,    11,     0,    12,     0,    13,
      14,    15,    16,     0,     0,    17,     0,     0,     0,     0,
       0,    18,    19,     0,     0,     0,     0,    20,     0,    21,
       0,    22,     0,    23,     0,     0,    24,     1,     2,     3,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,     0,     0,    17,     0,
       1,     2,     3,     4,    18,    19,     0,     0,     8,     0,
      61,     0,    21,    12,    22,    13,    14,    15,    16,    24,
       0,    17,     0,     1,     2,     3,     4,    18,    19,     0,
       0,     0,     0,     0,     0,    21,    12,    22,    13,    14,
      15,    16,    24,     0,    17,    73,    74,    75,    76,    77,
      18,    19,     0,     0,   -74,   -74,   -74,   -74,    21,    71,
      22,    72,     0,     0,     0,    24,     0,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,    81,    82,    83,
      71,     0,    72,     0,     0,     0,     0,   105,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    80,    81,    82,
      83,    71,     0,    72,     0,     0,     0,    84,     0,    73,
      74,    75,    76,    77,    78,    79,     0,     0,    80,    81,
      82,    83,    71,     0,    72,     0,     0,     0,    99,     0,
      73,    74,    75,    76,    77,    78,    79,     0,     0,    80,
      81,    82,    83,    71,     0,    72,     0,     0,     0,   168,
       0,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    71,     0,    72,     0,     0,   109,
       0,     0,    73,    74,    75,    76,    77,    78,    79,     0,
       0,    80,    81,    82,    83,    71,     0,    72,     0,     0,
     139,     0,     0,    73,    74,    75,    76,    77,    78,    79,
       0,     0,    80,    81,    82,    83,    71,     0,    72,     0,
       0,   140,     0,     0,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,    71,     0,    72,
     152,     0,     0,     0,     0,    73,    74,    75,    76,    77,
      78,    79,     0,     0,    80,    81,    82,    83,    71,   169,
      72,     0,     0,     0,     0,     0,    73,    74,    75,    76,
      77,    78,    79,    71,     0,    80,    81,    82,    83,     0,
       0,    73,    74,    75,    76,    77,    78,    79,     0,     0,
      80,    81,    82,    83,    73,    74,    75,    76,    77,    78,
      79,     0,     0,    80,    81,    82,    83,    73,    74,    75,
      76,    77,   -74,   -74,     0,     0,    80,    81,    82,    83
};

static const yytype_int16 yycheck[] =
{
       9,    45,    60,    12,     3,     4,     5,     6,    17,    22,
      40,     6,    21,    22,    18,    19,    38,    16,    40,    18,
      19,    20,    21,    18,    46,    24,    40,    25,    26,    27,
      38,    30,    31,    47,    43,    44,    45,    40,    46,    38,
      40,    40,    55,    42,   102,    40,    45,    38,     6,    40,
      45,     6,    61,    18,    19,    46,    47,    42,    42,    37,
       6,   105,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    15,    85,    17,     0,    88,
      40,   139,    91,    23,    24,    25,    26,    27,    28,    29,
     134,    39,    32,    33,    34,    35,   105,    11,    37,   157,
      43,    39,    22,     6,    44,    41,   150,     6,   166,    40,
      30,    31,     6,    36,    42,    41,    37,   161,    38,    36,
      40,   179,    40,     6,   168,   134,    46,    47,   172,    41,
      43,    40,   141,    41,     8,    41,   145,    15,    40,    17,
      41,   150,    26,    41,    41,    23,    24,    25,    26,    27,
      28,    29,   161,   102,    32,    33,    34,    35,   108,   168,
      95,    39,   154,   172,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    -1,    16,    -1,    18,
      19,    20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    -1,    -1,    -1,    36,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    45,     3,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    -1,    -1,    24,    -1,
       3,     4,     5,     6,    30,    31,    -1,    -1,    11,    -1,
      36,    -1,    38,    16,    40,    18,    19,    20,    21,    45,
      -1,    24,    -1,     3,     4,     5,     6,    30,    31,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    16,    40,    18,    19,
      20,    21,    45,    -1,    24,    23,    24,    25,    26,    27,
      30,    31,    -1,    -1,    32,    33,    34,    35,    38,    15,
      40,    17,    -1,    -1,    -1,    45,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      15,    -1,    17,    -1,    -1,    -1,    -1,    43,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    15,    -1,    17,    -1,    -1,    -1,    42,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    15,    -1,    17,    -1,    -1,    -1,    42,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    15,    -1,    17,    -1,    -1,    -1,    42,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    15,    -1,    17,    -1,    -1,    41,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    15,    -1,    17,    -1,    -1,
      41,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    32,    33,    34,    35,    15,    -1,    17,    -1,
      -1,    41,    -1,    -1,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    15,    -1,    17,
      39,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    15,    37,
      17,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    15,    -1,    32,    33,    34,    35,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    24,    30,    31,
      36,    38,    40,    42,    45,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    68,    72,    77,    80,    81,    83,
      84,    86,    88,    40,    40,    40,     6,    76,    42,    52,
      42,    42,    52,     6,    52,    40,    56,    58,    56,    73,
      74,    36,    52,    67,    69,    70,    52,    80,     6,     0,
      50,    15,    17,    23,    24,    25,    26,    27,    28,    29,
      32,    33,    34,    35,    42,    22,    30,    31,    38,    46,
      60,    38,    46,    59,    40,    78,    52,    52,    67,    42,
      80,    37,    51,    71,    52,    43,    39,    39,    43,    41,
      41,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,     6,    40,    47,    62,
      63,    65,    52,     6,    40,     6,    82,    72,    79,    41,
      41,    42,    41,    71,    37,    44,    67,    69,    61,    39,
      64,    66,    39,    67,    43,    41,    51,    85,    52,    75,
      52,    40,    67,     6,    41,    82,     8,    51,    42,    37,
      67,    41,    40,    51,    67,    41,    67,    41,    41,    87,
      51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    59,    58,    60,    58,    61,    58,    62,    62,    64,
      63,    66,    65,    67,    67,    67,    68,    68,    69,    69,
      70,    71,    71,    73,    72,    74,    75,    72,    76,    76,
      77,    78,    79,    80,    81,    81,    81,    81,    81,    81,
      82,    82,    82,    83,    83,    85,    84,    87,    86,    88,
      88
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     0,     5,     0,     3,     0,     7,     1,     1,     0,
       4,     0,     6,     1,     3,     0,     3,     3,     1,     3,
       5,     2,     1,     0,     3,     0,     0,     5,     1,     0,
       2,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     5,     7,     0,     6,     0,    10,     2,
       3
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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
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
  case 3: /* program: %empty  */
#line 56 "parser.y"
                {printf("\nProgram stopped\n\n");}
#line 1383 "parser.c"
    break;

  case 4: /* stmt: expr SEMICOLON  */
#line 59 "parser.y"
                            {printf("Stmt: expr;\n");}
#line 1389 "parser.c"
    break;

  case 5: /* stmt: ifstmt  */
#line 60 "parser.y"
                        {printf("\tif statement\n");}
#line 1395 "parser.c"
    break;

  case 6: /* stmt: whilestmt  */
#line 61 "parser.y"
                        {printf("\twhile statement\n");}
#line 1401 "parser.c"
    break;

  case 7: /* stmt: forstmt  */
#line 62 "parser.y"
                        {printf("\tfor statement\n");}
#line 1407 "parser.c"
    break;

  case 8: /* stmt: returnstmt  */
#line 63 "parser.y"
                        {printf("\treturn statement\n");}
#line 1413 "parser.c"
    break;

  case 9: /* stmt: BREAK SEMICOLON  */
#line 64 "parser.y"
                                {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"break\" can't be used without a loop.\n\033[0m", yylineno);
                }
                else {
                    printf("\tkeyword \"break\"\n");
                }
            }
#line 1426 "parser.c"
    break;

  case 10: /* stmt: CONTINUE SEMICOLON  */
#line 72 "parser.y"
                                {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"continue\" can't be used without a loop.\n\033[0m", yylineno);
                }
                else {
                    printf("\tkeyword \"continue\"\n");
                }
            }
#line 1439 "parser.c"
    break;

  case 11: /* stmt: block  */
#line 80 "parser.y"
                        {printf("\tBlock\n");}
#line 1445 "parser.c"
    break;

  case 12: /* stmt: funcdef  */
#line 81 "parser.y"
                        {printf("\tFunction definition\n");}
#line 1451 "parser.c"
    break;

  case 14: /* expr: assignexpr  */
#line 85 "parser.y"
                            {printf("Assign expression\n");}
#line 1457 "parser.c"
    break;

  case 15: /* expr: expr OP_PLUS expr  */
#line 86 "parser.y"
                                {printf("Expr: expr op_plus expr\n");}
#line 1463 "parser.c"
    break;

  case 16: /* expr: expr OP_MINUS expr  */
#line 87 "parser.y"
                                {printf("Expr: expr op_minus expr\n");}
#line 1469 "parser.c"
    break;

  case 17: /* expr: expr OP_ASTERISK expr  */
#line 88 "parser.y"
                                    {printf("Expr: expr op_asterisk expr\n");}
#line 1475 "parser.c"
    break;

  case 18: /* expr: expr OP_SLASH expr  */
#line 89 "parser.y"
                                {printf("Expr: expr op_slash expr\n");}
#line 1481 "parser.c"
    break;

  case 19: /* expr: expr OP_PERCENTAGE expr  */
#line 90 "parser.y"
                                     {printf("Expr: expr op_percentage expr\n");}
#line 1487 "parser.c"
    break;

  case 20: /* expr: expr OP_GREATER expr  */
#line 91 "parser.y"
                                  {printf("Expr: expr op_greater expr\n");}
#line 1493 "parser.c"
    break;

  case 21: /* expr: expr OP_GREATER_EQ expr  */
#line 92 "parser.y"
                                     {printf("Expr: expr op_greater_eq expr\n");}
#line 1499 "parser.c"
    break;

  case 22: /* expr: expr OP_LESSER expr  */
#line 93 "parser.y"
                                 {printf("Expr: expr op_lesser expr\n");}
#line 1505 "parser.c"
    break;

  case 23: /* expr: expr OP_LESSER_EQ expr  */
#line 94 "parser.y"
                                    {printf("Expr: expr op_lesser_eq expr\n");}
#line 1511 "parser.c"
    break;

  case 24: /* expr: expr OP_EQ_EQ expr  */
#line 95 "parser.y"
                                {printf("Expr: expr op_eq_eq expr\n");}
#line 1517 "parser.c"
    break;

  case 25: /* expr: expr OP_NOT_EQ expr  */
#line 96 "parser.y"
                                 {printf("Expr: expr op_not_eq expr\n");}
#line 1523 "parser.c"
    break;

  case 26: /* expr: expr AND expr  */
#line 97 "parser.y"
                           {printf("Expr: expr and expr\n");}
#line 1529 "parser.c"
    break;

  case 27: /* expr: expr OR expr  */
#line 98 "parser.y"
                          {printf("Expr: expr or expr\n");}
#line 1535 "parser.c"
    break;

  case 28: /* expr: term  */
#line 99 "parser.y"
                    {printf("Term expression\n");}
#line 1541 "parser.c"
    break;

  case 29: /* term: LEFT_PAR expr RIGHT_PAR  */
#line 102 "parser.y"
                                    {printf("Term: (expr)\n");}
#line 1547 "parser.c"
    break;

  case 30: /* term: OP_MINUS expr  */
#line 103 "parser.y"
                            {printf("Term: -expr\n");}
#line 1553 "parser.c"
    break;

  case 31: /* term: NOT expr  */
#line 104 "parser.y"
                      {printf("Term: not expr\n");}
#line 1559 "parser.c"
    break;

  case 32: /* term: OP_PLUS_PLUS lvalue  */
#line 105 "parser.y"
                                 {
                if (lvalue_checker(ourVar)) {
                    printf("Term: ++lvalue\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                }
            }
#line 1572 "parser.c"
    break;

  case 33: /* term: lvalue OP_PLUS_PLUS  */
#line 113 "parser.y"
                                 {
                if (lvalue_checker(ourVar)) {
                    printf("Term: lvalue++\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                }
            }
#line 1585 "parser.c"
    break;

  case 34: /* term: OP_MINUS_MINUS lvalue  */
#line 121 "parser.y"
                                   {
                if (lvalue_checker(ourVar)) {
                    printf("Term: --lvalue\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                }
            }
#line 1598 "parser.c"
    break;

  case 35: /* term: lvalue OP_MINUS_MINUS  */
#line 129 "parser.y"
                                   {                
                if (lvalue_checker(ourVar)) {
                    printf("Term: lvalue--\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                }
            }
#line 1611 "parser.c"
    break;

  case 36: /* term: primary  */
#line 137 "parser.y"
                     {printf("Term: primary\n");}
#line 1617 "parser.c"
    break;

  case 37: /* assignexpr: lvalue OP_EQUALS expr  */
#line 140 "parser.y"
                                  {
                if (!local_flag)  {
                    symt *tmp_symbol = NULL;
                    int found_flag = 0;
                    int tmp_scope = currscope();
                    while (tmp_scope >= 0) { //psaxnw ta scopes apo mesa pros ta eksw
                        tmp_symbol = SymTable_lookup(ourVar, tmp_scope, "local");
                        if (tmp_symbol != NULL) {
                            if (tmp_symbol->type > 2) {
                                fprintf(stdout, "\033[0;31mError. Line %d: Attempting to use function  %s as lvalue\n\033[0m",yylineno, ourVar);
                                found_flag = 1;
                                break;
                            }
                            else {
                                fprintf(stdout, "Assign expression: lvalue = expr\n");
                                found_flag = 1;
                                break;
                            }
                        }
                        tmp_scope--;
                    }
                    if (!found_flag) {
                        fprintf(stdout, "Assign expression: lvalue = expr\n");
                    }
                }
                else {
                    printf("Assign expression: lvalue = expr\n");
                }
                
                local_flag = 0;
            }
#line 1653 "parser.c"
    break;

  case 38: /* primary: lvalue  */
#line 173 "parser.y"
                    {printf("Primary: lvalue\n");}
#line 1659 "parser.c"
    break;

  case 39: /* primary: call  */
#line 174 "parser.y"
                    {printf("Primary: call\n");}
#line 1665 "parser.c"
    break;

  case 40: /* primary: objectdef  */
#line 175 "parser.y"
                       {printf("Primary: objectdef\n");}
#line 1671 "parser.c"
    break;

  case 41: /* primary: LEFT_PAR funcdef RIGHT_PAR  */
#line 176 "parser.y"
                                        {printf("Primary: (funcdef)\n");}
#line 1677 "parser.c"
    break;

  case 42: /* primary: const  */
#line 177 "parser.y"
                   {printf("Primary: const\n");}
#line 1683 "parser.c"
    break;

  case 43: /* lvalue: IDENTIFIER  */
#line 180 "parser.y"
                       {   
                    ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                    strcpy(ourVar, (yyvsp[0].strVal));               
                    printf("Lvalue: identifier\n");
                    symt *tmp_symbol = NULL;
                    tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "local"); //psaxnw to diko mou scope
                    if (tmp_symbol == NULL) {
                        //an eimai se synarthsh
                        if (func_flag) {
                            int found_flag = 0;
                            int tmp_scope = currscope()-1;
                            while (tmp_scope >= 0) { //psaxnw parent scopes apo mesa pros ta eksw
                                tmp_symbol = SymTable_lookup((yyvsp[0].strVal), tmp_scope, "local");
                                if (tmp_symbol != NULL) {
                                    if (tmp_scope != 0) {
                                        if (tmp_symbol->type < 3) {
                                            fprintf(stdout, "\033[0;31mError. Line %d: Cannot access variable %s in this scope\n\033[0m",yylineno, (yyvsp[0].strVal));
                                            found_flag = 1;
                                            break;
                                        }
                                        else {
                                            fprintf(stdout, "Calling symbol %s.\n",(yyvsp[0].strVal));
                                            found_flag = 1;
                                            break;
                                        }
                                    }
                                    else {
                                        fprintf(stdout, "Calling symbol %s.\n",(yyvsp[0].strVal));
                                        found_flag = 1;
                                        break;
                                    }
                                }
                                tmp_scope--;
                            }
                            if (!found_flag) {
                                SymTable_insert((yyvsp[0].strVal), yylineno, functionlocal, var_s);
                            }
                        }
                        else { //den eimai se synarthsh
                            tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "call_src"); //koitaw ola ta scopes
                            if (tmp_symbol != NULL) { //an vrw kati ola good
                                fprintf(stdout, "Calling symbol %s in parent scope.\n", (yyvsp[0].strVal));
                            }
                            else { //alliws kanw eisagwgh
                                SymTable_insert((yyvsp[0].strVal), yylineno, programvar, var_s);
                                /* if (currscope() == 0) {
                                    SymTable_insert($IDENTIFIER, yylineno, programvar, var_s);
                                }
                                else {
                                    SymTable_insert($IDENTIFIER, yylineno, programvar, var_s);
                                } */
                            }
                        }

                    }
            }
#line 1744 "parser.c"
    break;

  case 44: /* lvalue: LOCAL IDENTIFIER  */
#line 237 "parser.y"
                              {
                local_flag = 1;
                ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                strcpy(ourVar, (yyvsp[0].strVal)); 
                printf("Lvalue: local identifier\n");

                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "local");
                if (tmp_symbol == NULL) {
                    if (func_flag) { //an eimaste mesa se synarthsh exw func local
                        SymTable_insert((yyvsp[0].strVal), yylineno, functionlocal, var_s);
                    }
                    else {
                        SymTable_insert((yyvsp[0].strVal), yylineno, programvar, var_s);
                    }
                }
                else {

                    fprintf(stdout, "Symbol %s successfully found in this scope (%d), line %d.\n", (yyvsp[0].strVal), currscope(), getLine(tmp_symbol));
                }
            }
#line 1770 "parser.c"
    break;

  case 45: /* lvalue: COL_COL IDENTIFIER  */
#line 258 "parser.y"
                                {
                ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                strcpy(ourVar, (yyvsp[0].strVal)); 
                symt *tmp_symbol = NULL;
                printf("Lvalue: ::identifier\n");
                if ((tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "global_src")) != NULL) {
                    fprintf(stdout, "Symbol %s successfully found in global scope, line %d.\n", (yyvsp[0].strVal), getLine(tmp_symbol));
                }
                else {
                    fprintf(stdout,"\033[0;31mERROR. Line %d: Symbol %s not global or undefined.\n\033[0m", yylineno, (yyvsp[0].strVal));
                }
            }
#line 1787 "parser.c"
    break;

  case 46: /* lvalue: member  */
#line 270 "parser.y"
                    {printf("Lvalue: member\n");}
#line 1793 "parser.c"
    break;

  case 47: /* member: lvalue DOT IDENTIFIER  */
#line 273 "parser.y"
                                  {printf("Member: lvalue.identifier\n");}
#line 1799 "parser.c"
    break;

  case 48: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 274 "parser.y"
                                                    {printf("Member: lvalue[identifier]\n");}
#line 1805 "parser.c"
    break;

  case 49: /* member: call DOT IDENTIFIER  */
#line 275 "parser.y"
                                 {printf("Member: call.identifier\n");}
#line 1811 "parser.c"
    break;

  case 50: /* member: call LEFT_BRACKET expr RIGHT_BRACKET  */
#line 276 "parser.y"
                                                  {printf("Member: call[identifier]\n");}
#line 1817 "parser.c"
    break;

  case 51: /* $@1: %empty  */
#line 279 "parser.y"
                 {call_flag = 1;}
#line 1823 "parser.c"
    break;

  case 52: /* call: call $@1 LEFT_PAR elist RIGHT_PAR  */
#line 279 "parser.y"
                                                          {call_flag = 0; printf("Call: call(elist)\n");}
#line 1829 "parser.c"
    break;

  case 53: /* $@2: %empty  */
#line 280 "parser.y"
                     {call_flag=1;}
#line 1835 "parser.c"
    break;

  case 54: /* call: lvalue $@2 callsuffix  */
#line 280 "parser.y"
                                              { printf("Call: lvalue callsuffix\n");}
#line 1841 "parser.c"
    break;

  case 55: /* $@3: %empty  */
#line 281 "parser.y"
                                        {call_flag = 1;}
#line 1847 "parser.c"
    break;

  case 56: /* call: LEFT_PAR funcdef RIGHT_PAR $@3 LEFT_PAR elist RIGHT_PAR  */
#line 281 "parser.y"
                                                                                  {call_flag = 0; printf("Call: (funcdef)(elist)\n");}
#line 1853 "parser.c"
    break;

  case 57: /* callsuffix: normcall  */
#line 284 "parser.y"
                     {printf("Callsuffix: normcall\n");}
#line 1859 "parser.c"
    break;

  case 58: /* callsuffix: methodcall  */
#line 285 "parser.y"
                        {printf("Callsuffix: method\n");}
#line 1865 "parser.c"
    break;

  case 59: /* $@4: %empty  */
#line 288 "parser.y"
                     {call_flag = 1;}
#line 1871 "parser.c"
    break;

  case 60: /* normcall: LEFT_PAR $@4 elist RIGHT_PAR  */
#line 288 "parser.y"
                                                      {call_flag = 0; printf("Normcall: (elist)\n");}
#line 1877 "parser.c"
    break;

  case 61: /* $@5: %empty  */
#line 291 "parser.y"
                    {call_flag = 1;}
#line 1883 "parser.c"
    break;

  case 62: /* methodcall: DOT_DOT $@5 IDENTIFIER LEFT_PAR elist RIGHT_PAR  */
#line 291 "parser.y"
                                                                          {call_flag = 0; printf("Methodcall: ..identifier(elist)\n");}
#line 1889 "parser.c"
    break;

  case 63: /* elist: expr  */
#line 294 "parser.y"
                 {printf("Elist: expr\n");}
#line 1895 "parser.c"
    break;

  case 64: /* elist: expr COMMA elist  */
#line 295 "parser.y"
                               {printf("Elist: expr,...,expr\n");}
#line 1901 "parser.c"
    break;

  case 66: /* objectdef: LEFT_BRACKET elist RIGHT_BRACKET  */
#line 299 "parser.y"
                                              {printf("Objectdef: (elist)\n");}
#line 1907 "parser.c"
    break;

  case 67: /* objectdef: LEFT_BRACKET indexed RIGHT_BRACKET  */
#line 300 "parser.y"
                                                {printf("Objectdef: (indexed)\n");}
#line 1913 "parser.c"
    break;

  case 68: /* indexed: indexedelem  */
#line 303 "parser.y"
                        {printf("Indexed: indexedelem\n");}
#line 1919 "parser.c"
    break;

  case 69: /* indexed: indexedelem COMMA indexed  */
#line 304 "parser.y"
                                        {printf("Indexed: indexedelem,...,indexedelem\n");}
#line 1925 "parser.c"
    break;

  case 70: /* indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE  */
#line 307 "parser.y"
                                                    {printf("Indexedelem: [expr:expr]\n");}
#line 1931 "parser.c"
    break;

  case 71: /* func_stmt: stmt func_stmt  */
#line 310 "parser.y"
                          {printf("Func_stmt: stmt,...,stmt\n");}
#line 1937 "parser.c"
    break;

  case 72: /* func_stmt: stmt  */
#line 311 "parser.y"
                   {printf("Func_stmt: stmt\n");}
#line 1943 "parser.c"
    break;

  case 73: /* $@6: %empty  */
#line 314 "parser.y"
                       {
                    currentscope = currscope() + scope_flag;
                }
#line 1951 "parser.c"
    break;

  case 74: /* block: LEFT_BRACE $@6 RIGHT_BRACE  */
#line 316 "parser.y"
                              {
                    currentscope = currscope() - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(currscope()+1);
                    }
                    {printf("Block: {}\n");}
                }
#line 1963 "parser.c"
    break;

  case 75: /* $@7: %empty  */
#line 323 "parser.y"
                        {
                    currentscope = currscope() + scope_flag;
                }
#line 1971 "parser.c"
    break;

  case 76: /* $@8: %empty  */
#line 325 "parser.y"
                                        {
                    currentscope = currscope() - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(currscope()+1);
                    }
                }
#line 1982 "parser.c"
    break;

  case 77: /* block: LEFT_BRACE $@7 func_stmt RIGHT_BRACE $@8  */
#line 331 "parser.y"
                {printf("Block: {func_stmt}\n");}
#line 1988 "parser.c"
    break;

  case 78: /* funcname: IDENTIFIER  */
#line 334 "parser.y"
                                                           {
                if (SymTable_lookup((yyvsp[0].strVal), currscope(), "funcdef") == NULL) {
                    if (func_flag > 0) {
                        SymTable_insert((yyvsp[0].strVal), yylineno, programfunc_s, functionlocal);
                    }
                    else {
                        SymTable_insert((yyvsp[0].strVal), yylineno, programfunc_s, programvar);
                    }
                    func_flag++;
                    // functions++;
                    currentscope++; 
                    scope_flag = 0;
                }
                else {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Function (%s) in scope %d cannot be defined\n\033[0m", yylineno, (yyvsp[0].strVal), currscope());
                    yyerror("");
                }
            }
#line 2011 "parser.c"
    break;

  case 79: /* funcname: %empty  */
#line 352 "parser.y"
                                  {
                sprintf(str, "%s%d%c","_f",func_counter+1,'\0');
                if (SymTable_lookup(strdup(str), currscope(), "funcdef") == NULL) {
                    if (func_flag > 0) {
                        SymTable_insert(strdup(str), yylineno, programfunc_s, functionlocal);
                    }
                    else {
                        SymTable_insert(strdup(str), yylineno, programfunc_s, programvar);
                    }
                    func_counter++; //auto einai gia ta funcnames
                    func_flag++;
                    currentscope++; 
                    scope_flag = 0; //scope flag = 0 gia na mhn auksithei to scope sto block
                }
                else {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Function (%s) in scope %d cannot be defined\n\033[0m",yylineno, strdup(str),currscope());
                    yyerror("");
                }
            }
#line 2035 "parser.c"
    break;

  case 80: /* funcprefix: FUNCTION funcname  */
#line 373 "parser.y"
                              {
                //TODO
            }
#line 2043 "parser.c"
    break;

  case 81: /* funcargs: LEFT_PAR idlist RIGHT_PAR  */
#line 378 "parser.y"
                                              {
                enterscopespace();
                printf("\nA\n");
            }
#line 2052 "parser.c"
    break;

  case 82: /* funcbody: block  */
#line 384 "parser.y"
                  {
                if (!(--func_flag)){ //an func_flag-1=0, vghka apo ola ta functions
                    scope_flag = 1;
                }
                currentscope--;
                SymTable_hide(currscope()+1);
                SymTable_reveal(currscope());
                printf("Funcdef: function identifier(idlist) {}\n");
            }
#line 2066 "parser.c"
    break;

  case 84: /* const: INTEGER  */
#line 398 "parser.y"
                    {printf("Const: integer\n");}
#line 2072 "parser.c"
    break;

  case 85: /* const: REAL  */
#line 399 "parser.y"
                   {printf("Const: real\n");}
#line 2078 "parser.c"
    break;

  case 86: /* const: STRING  */
#line 400 "parser.y"
                     {printf("Const: string\n");}
#line 2084 "parser.c"
    break;

  case 87: /* const: NIL  */
#line 401 "parser.y"
                  {printf("Const: nil\n");}
#line 2090 "parser.c"
    break;

  case 88: /* const: TRUE  */
#line 402 "parser.y"
                   {printf("Const: true\n");}
#line 2096 "parser.c"
    break;

  case 89: /* const: FALSE  */
#line 403 "parser.y"
                    {printf("Const: false\n");}
#line 2102 "parser.c"
    break;

  case 90: /* idlist: IDENTIFIER  */
#line 406 "parser.y"
                        {
    printf("B\n");
                printf("Idlist: identifier\n");
                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "formal");
                if (tmp_symbol != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Symbol %s in scope %d cannot be defined\n\033[0m", yylineno, (yyvsp[0].strVal),currscope());
                }
                else {
                    SymTable_insert ((yyvsp[0].strVal), yylineno, formalarg, var_s);
                }
            }
#line 2119 "parser.c"
    break;

  case 91: /* idlist: IDENTIFIER COMMA idlist  */
#line 418 "parser.y"
                                      {
                printf("Idlist: identifier,...,identifier\n");
                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup((yyvsp[-2].strVal), currscope(), "formal");
                if (tmp_symbol != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Symbol %s in scope %d cannot be defined\n\033[0m", yylineno, (yyvsp[-2].strVal),currscope());
                }
                else {
                    SymTable_insert ((yyvsp[-2].strVal), yylineno, formalarg, var_s);
                }
            }
#line 2135 "parser.c"
    break;

  case 93: /* ifstmt: IF LEFT_PAR expr RIGHT_PAR stmt  */
#line 432 "parser.y"
                                            {printf("Ifstmt: if (expr) stmt\n");}
#line 2141 "parser.c"
    break;

  case 94: /* ifstmt: IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt  */
#line 433 "parser.y"
                                                       {printf("Ifstmt: if (expr) stmt else stmt\n");}
#line 2147 "parser.c"
    break;

  case 95: /* $@9: %empty  */
#line 436 "parser.y"
                                          {
                loop_scope++;
            }
#line 2155 "parser.c"
    break;

  case 96: /* whilestmt: WHILE LEFT_PAR expr RIGHT_PAR $@9 stmt  */
#line 439 "parser.y"
                 {
                loop_scope--;
                printf("Whilestmt: while (expr) stmt\n");
            }
#line 2164 "parser.c"
    break;

  case 97: /* $@10: %empty  */
#line 445 "parser.y"
                                                                        {
                loop_scope++;
            }
#line 2172 "parser.c"
    break;

  case 98: /* forstmt: FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist RIGHT_PAR $@10 stmt  */
#line 448 "parser.y"
                 {
                loop_scope--;
                printf("Forstmt: for (elist;expr;elist) stmt\n");
            }
#line 2181 "parser.c"
    break;

  case 99: /* returnstmt: RETURN SEMICOLON  */
#line 454 "parser.y"
                             {
                if (func_flag > 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",yylineno);
                }
            }
#line 2194 "parser.c"
    break;

  case 100: /* returnstmt: RETURN expr SEMICOLON  */
#line 462 "parser.y"
                                   {
                if (func_flag > 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",yylineno);
                }
            }
#line 2207 "parser.c"
    break;


#line 2211 "parser.c"

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

#line 473 "parser.y"


int lvalue_checker(const char *name) {
    symt *tmp_symbol = NULL;
        int found_flag = 0;
        int tmp_scope = currscope();
    if (!local_flag)  {
        while (tmp_scope >= 0) { //psaxnw ta scopes apo mesa pros ta eksw
            tmp_symbol = SymTable_lookup(ourVar, tmp_scope, "local");
            if (tmp_symbol != NULL) {
                if (tmp_symbol->type > 2) {
                    return 0;
                    //fprintf(stdout, "\033[0;31mError. Line %d: Attempting to use function  %s as lvalue\n\033[0m",yylineno, ourVar);
                    found_flag = 1;
                    break;
                }
                else {
                    return 1;
                    fprintf(stdout, "Term: ++lvalue\n");
                    found_flag = 1;
                    break;
                }
            }
            tmp_scope--;
        }
    }
    else {
        tmp_symbol = SymTable_lookup(ourVar, tmp_scope, "local");
        if (tmp_symbol != NULL) {
            if (tmp_symbol->type > 2) {
                return 0;
                //fprintf(stdout, "\033[0;31mError. Line %d: Attempting to use function  %s as lvalue\n\033[0m",yylineno, ourVar);
                found_flag = 1;
                //break;
            }
            else {
                return 1;
                fprintf(stdout, "Term: ++lvalue\n");
                found_flag = 1;
                //break;
            }
        }
    }
    return 1;
    /* if (!found_flag) {
        fprintf(stdout, "Assign expression: lvalue = expr\n");
    } */
}

void initialize() {
    int i;
    str = (char *)calloc(1,strlen("_f")+10+1);
    memset(str, '\0', strlen("_f")+11);

    SymTable_new();

    for (i=0; i < 499; i++) {
        lera->head[i] = NULL;
    }

    lista = malloc(sizeof(scope_link));
    lista->scope_counter = 0;
    lista->scope_head = NULL;
    lista->next = NULL;

    SymTable_insert("print", 0, programvar, libraryfunc_s);
    SymTable_insert("input", 0, programvar, libraryfunc_s);
    SymTable_insert("objectmemberkeys", 0, programvar, libraryfunc_s);
    SymTable_insert("objecttotalmembers", 0, programvar, libraryfunc_s);
    SymTable_insert("objectcopy", 0, programvar, libraryfunc_s);
    SymTable_insert("totalarguments", 0, programvar, libraryfunc_s);
    SymTable_insert("argument", 0, programvar, libraryfunc_s);
    SymTable_insert("typeof", 0, programvar, libraryfunc_s);
    SymTable_insert("strtonum", 0, programvar, libraryfunc_s);
    SymTable_insert("sqrt", 0, programvar, libraryfunc_s);
    SymTable_insert("cos", 0, programvar, libraryfunc_s);
    SymTable_insert("sin", 0, programvar, libraryfunc_s);
}

void print_scopes() {
    symt *temp;
    scope_link *temp2;

    temp2 = lista;
    while (temp2 != NULL) {
        temp = temp2->scope_head;
        printf("---------\tscope: %d\t---------\n\n",temp2->scope_counter);
        while (temp != NULL) {
            printf("\"%s\"\t[%s]\t(line: %u)\t(scope: %u)\n",getName(temp),getType(temp->type),getLine(temp), getScope(temp));
            temp = temp->next_in_scope;
        }
        temp2 = temp2 -> next;
        printf("\n");
    }
}

void print_hash() {
    SymTable *temp = lera;
    symt *temp2;
    int i;

    for (i = 0; i < SIZE; i++) {
        if (temp->head[i] != NULL) {
            temp2 = temp->head[i];
            printf("bucket: %d\n",i);
            while (temp2 != NULL) {
                printf("\t\"%s\"\t[%s]\t(line: %u)\t(scope: %u)\n",getName(temp2),getType(temp2->type),getLine(temp2), getScope(temp2));
                temp2 = temp2->next;
            }
            printf("\n");
        }
    }
    printf("\n_____________________________________________\n");
}

int yyerror (char* yaccProvidedMessage) {
    fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, yylineno, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
    print_scopes();
    exit(0);
}

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        printf("Reading from input file \"%s\"\n",argv[1]);
    }
    else {
        yyin = stdin;
    }
    initialize();
    yyparse();
    //print_hash();
    print_scopes();
    return 0;
}
