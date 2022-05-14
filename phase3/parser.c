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

    //


#line 99 "parser.c"

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
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_stmt = 52,                      /* stmt  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_assignexpr = 55,                /* assignexpr  */
  YYSYMBOL_primary = 56,                   /* primary  */
  YYSYMBOL_lvalue = 57,                    /* lvalue  */
  YYSYMBOL_tableitem = 58,                 /* tableitem  */
  YYSYMBOL_member = 59,                    /* member  */
  YYSYMBOL_call = 60,                      /* call  */
  YYSYMBOL_61_2 = 61,                      /* $@2  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_callsuffix = 64,                /* callsuffix  */
  YYSYMBOL_normcall = 65,                  /* normcall  */
  YYSYMBOL_66_5 = 66,                      /* $@5  */
  YYSYMBOL_methodcall = 67,                /* methodcall  */
  YYSYMBOL_68_6 = 68,                      /* $@6  */
  YYSYMBOL_elist = 69,                     /* elist  */
  YYSYMBOL_tablemake = 70,                 /* tablemake  */
  YYSYMBOL_indexed = 71,                   /* indexed  */
  YYSYMBOL_indexedelem = 72,               /* indexedelem  */
  YYSYMBOL_func_stmt = 73,                 /* func_stmt  */
  YYSYMBOL_block = 74,                     /* block  */
  YYSYMBOL_75_7 = 75,                      /* $@7  */
  YYSYMBOL_76_8 = 76,                      /* $@8  */
  YYSYMBOL_77_9 = 77,                      /* $@9  */
  YYSYMBOL_funcname = 78,                  /* funcname  */
  YYSYMBOL_funcprefix = 79,                /* funcprefix  */
  YYSYMBOL_funcargs = 80,                  /* funcargs  */
  YYSYMBOL_funcbody = 81,                  /* funcbody  */
  YYSYMBOL_funcdef = 82,                   /* funcdef  */
  YYSYMBOL_funcblockstart = 83,            /* funcblockstart  */
  YYSYMBOL_funcblockend = 84,              /* funcblockend  */
  YYSYMBOL_const = 85,                     /* const  */
  YYSYMBOL_idlist = 86,                    /* idlist  */
  YYSYMBOL_ifprefix = 87,                  /* ifprefix  */
  YYSYMBOL_elseprefix = 88,                /* elseprefix  */
  YYSYMBOL_if_stmt = 89,                   /* if_stmt  */
  YYSYMBOL_whilestart = 90,                /* whilestart  */
  YYSYMBOL_whilecond = 91,                 /* whilecond  */
  YYSYMBOL_while = 92,                     /* while  */
  YYSYMBOL_N = 93,                         /* N  */
  YYSYMBOL_M = 94,                         /* M  */
  YYSYMBOL_forprefix = 95,                 /* forprefix  */
  YYSYMBOL_for_stmt = 96,                  /* for_stmt  */
  YYSYMBOL_returnstmt = 97                 /* returnstmt  */
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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   557

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

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
       0,   106,   106,   106,   107,   110,   111,   112,   113,   114,
     115,   123,   131,   132,   133,   143,   148,   162,   176,   190,
     204,   218,   236,   254,   272,   290,   308,   326,   341,   356,
     362,   366,   380,   392,   419,   448,   476,   504,   509,   549,
     553,   554,   557,   562,   567,   625,   649,   663,   664,   669,
     673,   681,   682,   685,   685,   690,   690,   699,   699,   708,
     712,   718,   718,   726,   726,   736,   741,   748,   753,   772,
     786,   791,   799,   808,   809,   812,   812,   821,   823,   821,
     832,   835,   842,   876,   882,   897,   906,   909,   915,   920,
     925,   930,   931,   932,   937,   940,   952,   963,   966,   973,
     979,   982,   988,   993,  1000,  1011,  1016,  1020,  1026,  1037,
    1046
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
  "COL_COL", "DOT", "DOT_DOT", "LINE_COMM", "$accept", "program", "$@1",
  "stmt", "expr", "term", "assignexpr", "primary", "lvalue", "tableitem",
  "member", "call", "$@2", "$@3", "$@4", "callsuffix", "normcall", "$@5",
  "methodcall", "$@6", "elist", "tablemake", "indexed", "indexedelem",
  "func_stmt", "block", "$@7", "$@8", "$@9", "funcname", "funcprefix",
  "funcargs", "funcbody", "funcdef", "funcblockstart", "funcblockend",
  "const", "idlist", "ifprefix", "elseprefix", "if_stmt", "whilestart",
  "whilecond", "while", "N", "M", "forprefix", "for_stmt", "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-76)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     171,  -169,  -169,  -169,  -169,   -30,  -169,   -26,    -4,   127,
     -19,   -14,   260,    37,  -169,  -169,  -169,   260,     0,     0,
      18,   214,   237,  -169,    75,    82,  -169,   305,  -169,  -169,
    -169,   -11,  -169,  -169,   -16,  -169,  -169,    44,  -169,  -169,
     171,  -169,    45,  -169,  -169,  -169,  -169,   260,   260,  -169,
      83,  -169,  -169,   326,  -169,  -169,  -169,  -169,    36,    79,
     -31,   -12,   -31,    54,   171,   260,   284,    56,    57,    50,
     368,    58,  -169,  -169,   171,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,  -169,   260,
    -169,  -169,   260,    95,    -3,   260,    97,    65,   100,    71,
     107,   260,   171,   260,   389,    74,    84,  -169,    81,  -169,
     171,    86,    85,   260,  -169,  -169,    88,  -169,    87,  -169,
      25,   509,    36,    36,  -169,  -169,  -169,   522,   522,   262,
     262,   262,   262,   494,   431,  -169,  -169,  -169,  -169,  -169,
    -169,   452,  -169,   260,    92,    96,  -169,  -169,  -169,   171,
     410,  -169,    98,  -169,  -169,   101,  -169,  -169,  -169,   260,
    -169,  -169,   102,  -169,   260,   119,  -169,    99,   100,  -169,
    -169,  -169,  -169,   260,   100,  -169,   473,   260,   103,   112,
    -169,  -169,   171,   347,   113,  -169,   115,  -169,   260,  -169,
    -169,  -169,  -169,   120,  -169,    71,  -169,  -169,  -169
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,    89,    90,    91,    44,     0,   102,     0,    81,     0,
       0,     0,     0,     0,    93,    94,    92,     0,     0,     0,
      77,    67,     0,    14,     0,     0,     2,     0,    29,    15,
      37,    39,    48,    47,    40,    41,    12,     0,    13,    43,
       0,     6,     0,     7,   105,     8,     9,     0,    67,    80,
       0,    82,   109,     0,    10,    11,    32,    45,    31,     0,
      33,    53,    35,     0,     0,     0,    65,     0,     0,    70,
       0,     0,    46,     1,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
      34,    36,     0,     0,     0,     0,     0,     0,    97,     0,
     100,     0,     0,    67,     0,     0,     0,   110,     0,    76,
      74,     0,     0,    67,    68,    69,     0,    30,    42,     3,
      27,    28,    16,    17,    18,    19,    20,    25,    26,    21,
      23,    22,    24,    38,     0,    49,    61,    63,    56,    59,
      60,     0,    51,    67,    95,     0,    84,    85,    99,     0,
       0,   104,     0,    98,   106,     0,    57,    73,    78,     0,
      66,    71,     0,    50,    67,     0,    52,     0,    97,    83,
     101,   103,   105,     0,    97,    79,     0,    67,     0,     0,
      54,    96,     0,     0,     0,    72,     0,    62,    67,   105,
     107,    87,    58,     0,   108,     0,    64,    88,    86
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,    62,  -169,   -23,    -9,  -169,  -169,  -169,    28,  -169,
    -169,    46,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
     -15,  -169,    22,  -169,    43,   -98,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,   -17,  -169,  -169,  -169,  -143,  -169,  -169,
    -169,  -169,  -169,  -169,  -168,  -169,  -169,  -169,  -169
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    74,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    97,    94,   162,   138,   139,   164,   140,   165,
      67,    35,    68,    69,   111,    36,    63,    64,   175,    51,
      37,    99,   147,    38,   195,   198,    39,   145,    40,   149,
      41,    42,   102,    43,   103,   173,    44,    45,    46
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   146,    49,    56,   182,    71,     4,    92,    58,   -55,
      47,    89,    66,    70,    48,    93,   -55,   100,    13,    90,
      91,   194,    95,    54,   -53,   181,    95,    92,    55,   -55,
      96,   184,    50,   105,    96,    93,   -55,   136,   104,    66,
      59,   110,   108,    57,   137,    24,    60,    62,    77,    78,
      79,    80,    81,    82,    83,   -75,   112,    84,    85,    86,
      87,    79,    80,    81,    61,    61,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   151,
     133,    72,    73,   134,    98,   101,   141,   110,   152,   106,
       8,   109,   150,   116,    66,   114,   115,   197,   160,   118,
      75,   135,    76,   142,    66,   143,   144,    20,    77,    78,
      79,    80,    81,    82,    83,   148,   154,    84,    85,    86,
      87,   155,   156,   158,    65,   179,   170,   -57,   167,   159,
       1,     2,     3,     4,    66,   168,   119,   169,   161,   172,
     180,   174,   177,    12,   187,    13,    14,    15,    16,   178,
     176,    17,   188,   157,   191,    66,   192,    18,    19,   189,
       0,   196,   186,     0,   183,    21,     0,    22,    66,    52,
       0,     0,    24,   193,     1,     2,     3,     4,     5,    66,
       6,     7,     8,     9,    10,    11,     0,    12,     0,    13,
      14,    15,    16,     0,     0,    17,     0,     0,     0,     0,
       0,    18,    19,     0,     0,     0,     0,    20,     0,    21,
       0,    22,     0,    23,     0,     0,    24,     1,     2,     3,
       4,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,    13,    14,    15,    16,     0,     0,    17,     0,
       1,     2,     3,     4,    18,    19,     0,     0,     8,     0,
      65,     0,    21,    12,    22,    13,    14,    15,    16,    24,
       0,    17,     0,     1,     2,     3,     4,    18,    19,     0,
       0,     0,     0,     0,     0,    21,    12,    22,    13,    14,
      15,    16,    24,     0,    17,    77,    78,    79,    80,    81,
      18,    19,     0,     0,   -76,   -76,   -76,   -76,    21,    75,
      22,    76,     0,     0,     0,    24,     0,    77,    78,    79,
      80,    81,    82,    83,     0,     0,    84,    85,    86,    87,
      75,     0,    76,     0,     0,     0,     0,   113,    77,    78,
      79,    80,    81,    82,    83,     0,     0,    84,    85,    86,
      87,    75,     0,    76,     0,     0,     0,    88,     0,    77,
      78,    79,    80,    81,    82,    83,     0,     0,    84,    85,
      86,    87,    75,     0,    76,     0,     0,     0,   107,     0,
      77,    78,    79,    80,    81,    82,    83,     0,     0,    84,
      85,    86,    87,    75,     0,    76,     0,     0,     0,   190,
       0,    77,    78,    79,    80,    81,    82,    83,     0,     0,
      84,    85,    86,    87,    75,     0,    76,     0,     0,   117,
       0,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,    84,    85,    86,    87,    75,     0,    76,     0,     0,
     153,     0,     0,    77,    78,    79,    80,    81,    82,    83,
       0,     0,    84,    85,    86,    87,    75,     0,    76,     0,
       0,   171,     0,     0,    77,    78,    79,    80,    81,    82,
      83,     0,     0,    84,    85,    86,    87,    75,     0,    76,
     163,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,     0,     0,    84,    85,    86,    87,    75,     0,
      76,   166,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,     0,     0,    84,    85,    86,    87,    75,
     185,    76,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    75,     0,    84,    85,    86,    87,
       0,     0,    77,    78,    79,    80,    81,    82,    83,     0,
       0,    84,    85,    86,    87,    77,    78,    79,    80,    81,
     -76,   -76,     0,     0,    84,    85,    86,    87
};

static const yytype_int16 yycheck[] =
{
       9,    99,     6,    12,   172,    22,     6,    38,    17,    40,
      40,    22,    21,    22,    40,    46,    47,    40,    18,    30,
      31,   189,    38,    42,    40,   168,    38,    38,    42,    40,
      46,   174,    36,    48,    46,    46,    47,    40,    47,    48,
      40,    64,    59,     6,    47,    45,    18,    19,    23,    24,
      25,    26,    27,    28,    29,    37,    65,    32,    33,    34,
      35,    25,    26,    27,    18,    19,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,   102,
      89,     6,     0,    92,    40,    40,    95,   110,   103,     6,
      11,    37,   101,    43,   103,    39,    39,   195,   113,    41,
      15,     6,    17,     6,   113,    40,     6,    36,    23,    24,
      25,    26,    27,    28,    29,     8,    42,    32,    33,    34,
      35,    37,    41,    37,    36,     6,   149,    40,   143,    44,
       3,     4,     5,     6,   143,    43,    74,    41,   116,    41,
      41,    40,    40,    16,    41,    18,    19,    20,    21,   164,
     159,    24,    40,   110,    41,   164,    41,    30,    31,   182,
      -1,    41,   177,    -1,   173,    38,    -1,    40,   177,    42,
      -1,    -1,    45,   188,     3,     4,     5,     6,     7,   188,
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
      28,    29,    -1,    -1,    32,    33,    34,    35,    15,    -1,
      17,    39,    -1,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    15,
      37,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    25,
      26,    27,    28,    29,    15,    -1,    32,    33,    34,    35,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    24,    30,    31,
      36,    38,    40,    42,    45,    50,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    70,    74,    79,    82,    85,
      87,    89,    90,    92,    95,    96,    97,    40,    40,     6,
      36,    78,    42,    53,    42,    42,    53,     6,    53,    40,
      57,    60,    57,    75,    76,    36,    53,    69,    71,    72,
      53,    82,     6,     0,    51,    15,    17,    23,    24,    25,
      26,    27,    28,    29,    32,    33,    34,    35,    42,    22,
      30,    31,    38,    46,    62,    38,    46,    61,    40,    80,
      52,    40,    91,    93,    53,    69,     6,    42,    82,    37,
      52,    73,    53,    43,    39,    39,    43,    41,    41,    50,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,     6,    40,    47,    64,    65,
      67,    53,     6,    40,     6,    86,    74,    81,     8,    88,
      53,    52,    69,    41,    42,    37,    41,    73,    37,    44,
      69,    71,    63,    39,    66,    68,    39,    69,    43,    41,
      52,    41,    41,    94,    40,    77,    53,    40,    69,     6,
      41,    86,    93,    53,    86,    37,    69,    41,    40,    52,
      42,    41,    41,    69,    93,    83,    41,    74,    84
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    51,    50,    50,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      54,    54,    54,    54,    54,    54,    54,    54,    55,    56,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    58,
      58,    59,    59,    61,    60,    62,    60,    63,    60,    64,
      64,    66,    65,    68,    67,    69,    69,    69,    70,    70,
      71,    71,    72,    73,    73,    75,    74,    76,    77,    74,
      78,    78,    79,    80,    81,    82,    82,    83,    84,    85,
      85,    85,    85,    85,    85,    86,    86,    86,    87,    88,
      89,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     3,     0,     2,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     2,     2,     2,     2,     2,     2,     1,     3,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     1,     3,
       4,     3,     4,     0,     5,     0,     3,     0,     7,     1,
       1,     0,     4,     0,     6,     1,     3,     0,     3,     3,
       1,     3,     5,     2,     1,     0,     3,     0,     0,     5,
       1,     0,     2,     3,     1,     3,    10,     0,     0,     1,
       1,     1,     1,     1,     1,     1,     3,     0,     4,     1,
       2,     4,     1,     3,     3,     0,     0,     7,     7,     2,
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
  case 2: /* $@1: %empty  */
#line 106 "parser.y"
                 {resettemp();}
#line 1407 "parser.c"
    break;

  case 4: /* program: %empty  */
#line 107 "parser.y"
                {printf("\nProgram stopped\n\n");}
#line 1413 "parser.c"
    break;

  case 5: /* stmt: expr SEMICOLON  */
#line 110 "parser.y"
                            {printf("Stmt: expr;\n");}
#line 1419 "parser.c"
    break;

  case 6: /* stmt: if_stmt  */
#line 111 "parser.y"
                         {printf("\tif statement\n");}
#line 1425 "parser.c"
    break;

  case 7: /* stmt: while  */
#line 112 "parser.y"
                    {printf("\twhile statement\n");}
#line 1431 "parser.c"
    break;

  case 8: /* stmt: for_stmt  */
#line 113 "parser.y"
                         {printf("\tfor statement\n");}
#line 1437 "parser.c"
    break;

  case 9: /* stmt: returnstmt  */
#line 114 "parser.y"
                        {printf("\treturn statement\n");}
#line 1443 "parser.c"
    break;

  case 10: /* stmt: BREAK SEMICOLON  */
#line 115 "parser.y"
                                {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"break\" can't be used without a loop.\n\033[0m", yylineno);
                }
                else {
                    printf("\tkeyword \"break\"\n");
                }
            }
#line 1456 "parser.c"
    break;

  case 11: /* stmt: CONTINUE SEMICOLON  */
#line 123 "parser.y"
                                {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"continue\" can't be used without a loop.\n\033[0m", yylineno);
                }
                else {
                    printf("\tkeyword \"continue\"\n");
                }
            }
#line 1469 "parser.c"
    break;

  case 12: /* stmt: block  */
#line 131 "parser.y"
                        {printf("\tBlock\n");}
#line 1475 "parser.c"
    break;

  case 13: /* stmt: funcdef  */
#line 132 "parser.y"
                        {printf("\tFunction definition\n");}
#line 1481 "parser.c"
    break;

  case 15: /* expr: assignexpr  */
#line 143 "parser.y"
                            {
                printf("Assign expression\n");

                (yyval.exprVal) = (yyvsp[0].exprVal);
            }
#line 1491 "parser.c"
    break;

  case 16: /* expr: expr OP_PLUS expr  */
#line 148 "parser.y"
                                {
                printf("Expr: expr op_plus expr\n");

                (yyval.exprVal) = newexpr(arithexpr_e);

                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }
                emit(add, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1510 "parser.c"
    break;

  case 17: /* expr: expr OP_MINUS expr  */
#line 162 "parser.y"
                                {
                printf("Expr: expr op_minus expr\n");

                (yyval.exprVal) = newexpr(arithexpr_e);

                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }
                emit(sub, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1529 "parser.c"
    break;

  case 18: /* expr: expr OP_ASTERISK expr  */
#line 176 "parser.y"
                                    {
                printf("Expr: expr op_asterisk expr\n");

                (yyval.exprVal) = newexpr(arithexpr_e);

                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }
                emit(mul, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1548 "parser.c"
    break;

  case 19: /* expr: expr OP_SLASH expr  */
#line 190 "parser.y"
                                {
                printf("Expr: expr op_slash expr\n");

                (yyval.exprVal) = newexpr(arithexpr_e);

                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }
                emit(div_iop, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1567 "parser.c"
    break;

  case 20: /* expr: expr OP_PERCENTAGE expr  */
#line 204 "parser.y"
                                     {
                printf("Expr: expr op_percentage expr\n");

                (yyval.exprVal) = newexpr(arithexpr_e);

                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }
                emit(mod, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1586 "parser.c"
    break;

  case 21: /* expr: expr OP_GREATER expr  */
#line 218 "parser.y"
                                  {
                printf("Expr: expr op_greater expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);
                
                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(if_greater, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel()+3, yylineno);
                emit(assign, newexpr_constbool(0), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
                emit(jump, NULL, NULL, NULL, nextquadlabel()+2, yylineno);
                emit(assign, newexpr_constbool(1), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1609 "parser.c"
    break;

  case 22: /* expr: expr OP_GREATER_EQ expr  */
#line 236 "parser.y"
                                     {
                printf("Expr: expr op_greater_eq expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);
                
                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(if_greatereq, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel()+3, yylineno);
                emit(assign, newexpr_constbool(0), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
                emit(jump, NULL, NULL, NULL, nextquadlabel()+2, yylineno);
                emit(assign, newexpr_constbool(1), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1632 "parser.c"
    break;

  case 23: /* expr: expr OP_LESSER expr  */
#line 254 "parser.y"
                                 {
                printf("Expr: expr op_lesser expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);
                
                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(if_less, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel()+3, yylineno);
                emit(assign, newexpr_constbool(0), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
                emit(jump, NULL, NULL, NULL, nextquadlabel()+2, yylineno);
                emit(assign, newexpr_constbool(1), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1655 "parser.c"
    break;

  case 24: /* expr: expr OP_LESSER_EQ expr  */
#line 272 "parser.y"
                                    {
                printf("Expr: expr op_lesser_eq expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);
                
                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(if_lesseq, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel()+3, yylineno);
                emit(assign, newexpr_constbool(0), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
                emit(jump, NULL, NULL, NULL, nextquadlabel()+2, yylineno);
                emit(assign, newexpr_constbool(1), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1678 "parser.c"
    break;

  case 25: /* expr: expr OP_EQ_EQ expr  */
#line 290 "parser.y"
                                {
                printf("Expr: expr op_eq_eq expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);
                
                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(if_eq, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel()+3, yylineno);
                emit(assign, newexpr_constbool(0), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
                emit(jump, NULL, NULL, NULL, nextquadlabel()+2, yylineno);
                emit(assign, newexpr_constbool(1), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1701 "parser.c"
    break;

  case 26: /* expr: expr OP_NOT_EQ expr  */
#line 308 "parser.y"
                                 {
                printf("Expr: expr op_not_eq expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);
                
                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(if_noteq, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel()+3, yylineno);
                emit(assign, newexpr_constbool(0), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
                emit(jump, NULL, NULL, NULL, nextquadlabel()+2, yylineno);
                emit(assign, newexpr_constbool(1), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1724 "parser.c"
    break;

  case 27: /* expr: expr AND expr  */
#line 326 "parser.y"
                           {
                printf("Expr: expr and expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);
                
                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(and, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1744 "parser.c"
    break;

  case 28: /* expr: expr OR expr  */
#line 341 "parser.y"
                          {
                printf("Expr: expr or expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);

                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(or, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1764 "parser.c"
    break;

  case 29: /* expr: term  */
#line 356 "parser.y"
                    {
                (yyval.exprVal) = (yyvsp[0].exprVal);
                printf("Term expression\n");
            }
#line 1773 "parser.c"
    break;

  case 30: /* term: LEFT_PAR expr RIGHT_PAR  */
#line 362 "parser.y"
                                    {
                printf("Term: (expr)\n");
                (yyval.exprVal) = (yyvsp[-1].exprVal);
            }
#line 1782 "parser.c"
    break;

  case 31: /* term: OP_MINUS expr  */
#line 366 "parser.y"
                            {
                printf("Term: -expr\n");

                check_arith((yyvsp[0].exprVal), "-expr");
                (yyval.exprVal) = newexpr(arithexpr_e);

                if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(uminus, (yyvsp[0].exprVal), NULL, (yyval.exprVal));
            }
#line 1801 "parser.c"
    break;

  case 32: /* term: NOT expr  */
#line 380 "parser.y"
                      {
                printf("Term: not expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);

                if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }
                emit(not, (yyvsp[0].exprVal), NULL, (yyval.exprVal));
            }
#line 1818 "parser.c"
    break;

  case 33: /* term: OP_PLUS_PLUS lvalue  */
#line 392 "parser.y"
                                 {
                if (lvalue_checker(ourVar)) {
                    printf("Term: ++lvalue\n");

                    check_arith((yyvsp[0].exprVal), "++lvalue");
                    if ((yyvsp[0].exprVal)->type == tableitem_e) {
                        (yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal));
                        emit(add, (yyval.exprVal), newexpr_constnum(1), (yyval.exprVal), currQuad, yylineno);
                        emit(tablesetelem, (yyvsp[0].exprVal), (yyvsp[0].exprVal)->index, (yyval.exprVal), currQuad, yylineno);
                    }
                    else {
                        emit(add, (yyvsp[0].exprVal), newexpr_constnum(1), (yyvsp[0].exprVal), currQuad, yylineno);
                        (yyval.exprVal) = newexpr(arithexpr_e);

                        if (istempexpr((yyvsp[0].exprVal))) {
                            (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                        } else {
                            (yyval.exprVal)->sym = newtemp();
                        }
                        emit(assign, (yyvsp[0].exprVal), NULL, (yyval.exprVal), currQuad, yylineno);
                    }
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                    (yyval.exprVal) = _errorexpr;
                }
            }
#line 1850 "parser.c"
    break;

  case 34: /* term: lvalue OP_PLUS_PLUS  */
#line 419 "parser.y"
                                 {
                if (lvalue_checker(ourVar)) {
                    printf("Term: lvalue++\n");

                    check_arith((yyvsp[-1].exprVal), "lvalue++");
                    (yyval.exprVal) = newexpr(var_e);

                    if (istempexpr((yyvsp[-1].exprVal))) {
                        (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
                    } else {
                        (yyval.exprVal)->sym = newtemp();
                    }

                    if ((yyvsp[-1].exprVal)->type == tableitem_e) {
                        expr *val = emit_iftableitem((yyvsp[-1].exprVal));
                        emit(assign, val, NULL, (yyval.exprVal), currQuad, yylineno);
                        emit(add, val, newexpr_constnum(1), val, currQuad, yylineno);
                        emit(tablesetelem, (yyvsp[-1].exprVal), (yyvsp[-1].exprVal)->index, val);
                    }
                    else {
                        emit(assign, (yyvsp[-1].exprVal), NULL, (yyval.exprVal));
                        emit(add, (yyvsp[-1].exprVal), newexpr_constnum(1), (yyvsp[-1].exprVal), currQuad, yylineno);
                    }
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                    (yyval.exprVal) = _errorexpr;
                }
            }
#line 1884 "parser.c"
    break;

  case 35: /* term: OP_MINUS_MINUS lvalue  */
#line 448 "parser.y"
                                   {
                if (lvalue_checker(ourVar)) {
                    printf("Term: --lvalue\n");

                    check_arith((yyvsp[0].exprVal), "++lvalue");
                    if ((yyvsp[0].exprVal)->type == tableitem_e) {
                        (yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal));
                        emit(sub, (yyval.exprVal), newexpr_constnum(1), (yyval.exprVal), currQuad, yylineno);
                        emit(tablesetelem, (yyvsp[0].exprVal), (yyvsp[0].exprVal)->index, (yyval.exprVal), currQuad, yylineno);
                    }
                    else {
                        emit(sub, (yyvsp[0].exprVal), newexpr_constnum(1), (yyvsp[0].exprVal), currQuad, yylineno);
                        (yyval.exprVal) = newexpr(arithexpr_e);

                        if (istempexpr((yyvsp[0].exprVal))) {
                            (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                        } else {
                            (yyval.exprVal)->sym = newtemp();
                        }
                        
                        emit(assign, (yyvsp[0].exprVal), NULL, (yyval.exprVal), currQuad, yylineno);
                    }
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                    (yyval.exprVal) = _errorexpr;
                }
            }
#line 1917 "parser.c"
    break;

  case 36: /* term: lvalue OP_MINUS_MINUS  */
#line 476 "parser.y"
                                   {                
                if (lvalue_checker(ourVar)) {
                    printf("Term: lvalue--\n");

                    check_arith((yyvsp[-1].exprVal), "lvalue--");
                    (yyval.exprVal) = newexpr(var_e);
                    //$term->sym = newtemp();
                    if (istempexpr((yyvsp[-1].exprVal))) {
                        (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
                    } else {
                        (yyval.exprVal)->sym = newtemp();
                    }
                    if ((yyvsp[-1].exprVal)->type == tableitem_e) {
                        expr *val = emit_iftableitem((yyvsp[-1].exprVal));
                        emit(assign, val, NULL, (yyval.exprVal), currQuad, yylineno);
                        emit(sub, val, newexpr_constnum(1), val, currQuad, yylineno);
                        emit(tablesetelem, (yyvsp[-1].exprVal), (yyvsp[-1].exprVal)->index, val);
                    }
                    else {
                        emit(assign, (yyvsp[-1].exprVal), NULL, (yyval.exprVal));
                        emit(sub, (yyvsp[-1].exprVal), newexpr_constnum(1), (yyvsp[-1].exprVal), currQuad, yylineno);
                    }
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                    (yyval.exprVal) = _errorexpr;
                }
            }
#line 1950 "parser.c"
    break;

  case 37: /* term: primary  */
#line 504 "parser.y"
                     {
                (yyval.exprVal) = (yyvsp[0].exprVal);
                printf("Term: primary\n");}
#line 1958 "parser.c"
    break;

  case 38: /* assignexpr: lvalue OP_EQUALS expr  */
#line 509 "parser.y"
                                  {
                int found_flag = 0;
                if (!local_flag)  {
                    symt *tmp_symbol = NULL;
                    
                    int tmp_scope = currscope();
                    while (tmp_scope >= 0) { //psaxnw ta scopes apo mesa pros ta eksw
                        tmp_symbol = SymTable_lookup(ourVar, tmp_scope, "local");
                        if (tmp_symbol != NULL) {
                            if (tmp_symbol->type > 2) {
                                fprintf(stdout, "\033[0;31mError. Line %d: Attempting to use function  %s as lvalue\n\033[0m",yylineno, ourVar);
                                found_flag = 1;
                                break;
                            }
                        }
                        tmp_scope--;
                    }
                    fprintf(stdout, "Assign expression: lvalue = expr\n");
                }
                else {
                    printf("Assign expression: lvalue = expr\n");
                }
                if (!found_flag) {
                    if ((yyvsp[-2].exprVal)->type = tableitem_e) { //lvalue[index] = expr
                        //printf("AAAAAAAAAAAAAA");
                        emit(tablesetelem, (yyvsp[-2].exprVal), (yyvsp[-2].exprVal)->index, (yyvsp[0].exprVal), currQuad, yylineno);
                        (yyval.exprVal) = emit_iftableitem((yyvsp[-2].exprVal));
                        (yyval.exprVal)->type = assignexpr_e;
                    }
                    else { //lvalue = expr;
                        emit(assign, (yyvsp[0].exprVal), NULL, (yyvsp[-2].exprVal), currQuad, yylineno);
                        (yyval.exprVal) = newexpr(assignexpr_e);
                        (yyval.exprVal)->sym = newtemp();
                        emit(assign, (yyvsp[-2].exprVal), NULL, (yyval.exprVal));
                    }
                }
                 local_flag = 0;
            }
#line 2001 "parser.c"
    break;

  case 39: /* primary: lvalue  */
#line 549 "parser.y"
                    {
                (yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal));
                printf("Primary: lvalue\n");
            }
#line 2010 "parser.c"
    break;

  case 40: /* primary: call  */
#line 553 "parser.y"
                    {printf("Primary: call\n");}
#line 2016 "parser.c"
    break;

  case 41: /* primary: tablemake  */
#line 554 "parser.y"
                       {
                (yyval.exprVal) = (yyvsp[0].exprVal);
                printf("Primary: tableitem\n");}
#line 2024 "parser.c"
    break;

  case 42: /* primary: LEFT_PAR funcdef RIGHT_PAR  */
#line 557 "parser.y"
                                        {
                printf("Primary: (funcdef)\n");
                (yyval.exprVal) = newexpr(programfunc_e);
                (yyval.exprVal)->sym = (yyvsp[-1].symtVal);
            }
#line 2034 "parser.c"
    break;

  case 43: /* primary: const  */
#line 562 "parser.y"
                   {
                (yyval.exprVal) = (yyvsp[0].exprVal);
                printf("Primary: const\n");}
#line 2042 "parser.c"
    break;

  case 44: /* lvalue: IDENTIFIER  */
#line 567 "parser.y"
                       {   
                    ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                    strcpy(ourVar, (yyvsp[0].strVal));               
                    printf("Lvalue: identifier\n");
                    symt *tmp_symbol = NULL;
                    tmp_symbol = SymTable_lookup(ourVar, currscope(), "local"); //psaxnw to diko mou scope
                    if (tmp_symbol == NULL) {
                        //an eimai se synarthsh
                        if (func_flag > 0) {
                            int found_flag = 0;
                            int tmp_scope = currscope()-1;
                            while (tmp_scope >= 0) { //psaxnw parent scopes apo mesa pros ta eksw
                                tmp_symbol = SymTable_lookup(ourVar, tmp_scope, "local");
                                if (tmp_symbol != NULL) {
                                    if (tmp_scope != 0) {
                                        if (tmp_symbol->type < 3) {
                                            fprintf(stdout, "\033[0;31mError. Line %d: Cannot access variable %s in this scope\n\033[0m",yylineno, (yyvsp[0].strVal));
                                            found_flag = 1;
                                            (yyval.exprVal) = _errorexpr;
                                            break;
                                        }
                                        else {
                                            fprintf(stdout, "Calling symbol %s.\n",ourVar);
                                            found_flag = 1;
                                            (yyval.exprVal) = lvalue_expr(tmp_symbol);
                                            break;
                                        }
                                    }
                                    else {
                                        fprintf(stdout, "Calling symbol %s.\n",ourVar);
                                        found_flag = 1;
                                        (yyval.exprVal) = lvalue_expr(tmp_symbol);
                                        break;
                                    }
                                }
                                tmp_scope--;
                            }
                            if (!found_flag) {

                                
                                tmp_symbol = SymTable_insert(ourVar, yylineno, functionlocal, var_s);
                                (yyval.exprVal) = lvalue_expr(tmp_symbol);
                            }
                        }
                        else { //den eimai se synarthsh
                            tmp_symbol = SymTable_lookup(ourVar, currscope(), "call_src"); //koitaw ola ta scopes
                            if (tmp_symbol != NULL) { //an vrw kati ola good
                                fprintf(stdout, "Calling symbol %s in parent scope.\n", (yyvsp[0].strVal));
                            }
                            else { //alliws kanw eisagwgh
                                tmp_symbol = SymTable_insert(ourVar, yylineno, programvar, var_s);
                            }
                            (yyval.exprVal) = lvalue_expr(tmp_symbol);
                        }

                    }
            }
#line 2104 "parser.c"
    break;

  case 45: /* lvalue: LOCAL IDENTIFIER  */
#line 625 "parser.y"
                              {
                local_flag = 1;
                ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                strcpy(ourVar, (yyvsp[0].strVal)); 
                printf("Lvalue: local identifier\n");

                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "local");
                
                if (tmp_symbol == NULL) {
                    if (func_flag > 0) { //an eimaste mesa se synarthsh exw func local
                    
                        tmp_symbol = SymTable_insert((yyvsp[0].strVal), yylineno, functionlocal, var_s);
                    }
                    else {
                        tmp_symbol = SymTable_insert((yyvsp[0].strVal), yylineno, programvar, var_s);
                    }
                }
                else {

                    fprintf(stdout, "Symbol %s successfully found in this scope (%d), line %d.\n", (yyvsp[0].strVal), currscope(), getLine(tmp_symbol));
                }
                (yyval.exprVal) = lvalue_expr(tmp_symbol);
            }
#line 2133 "parser.c"
    break;

  case 46: /* lvalue: COL_COL IDENTIFIER  */
#line 649 "parser.y"
                                {
                ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                strcpy(ourVar, (yyvsp[0].strVal)); 
                symt *tmp_symbol = NULL;
                printf("Lvalue: ::identifier\n");
                if ((tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "global_src")) != NULL) {
                    fprintf(stdout, "Symbol %s successfully found in global scope, line %d.\n", (yyvsp[0].strVal), getLine(tmp_symbol));
                    (yyval.exprVal) = lvalue_expr(tmp_symbol);
                }
                else {
                    fprintf(stdout,"\033[0;31mERROR. Line %d: Symbol %s not global or undefined.\n\033[0m", yylineno, (yyvsp[0].strVal));
                    (yyval.exprVal) = _errorexpr;
                }
            }
#line 2152 "parser.c"
    break;

  case 47: /* lvalue: member  */
#line 663 "parser.y"
                    {printf("Lvalue: member\n");}
#line 2158 "parser.c"
    break;

  case 48: /* lvalue: tableitem  */
#line 664 "parser.y"
                       {
                (yyval.exprVal) = (yyvsp[0].exprVal);
            }
#line 2166 "parser.c"
    break;

  case 49: /* tableitem: lvalue DOT IDENTIFIER  */
#line 669 "parser.y"
                                  {
                (yyval.exprVal) = member_item((yyvsp[-2].exprVal), (yyvsp[0].strVal));
                printf("Tableitem: lvalue.identifier\n");
            }
#line 2175 "parser.c"
    break;

  case 50: /* tableitem: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 673 "parser.y"
                                                     {
                (yyvsp[-3].exprVal) = emit_iftableitem((yyvsp[-3].exprVal));
                (yyval.exprVal) = newexpr(tableitem_e);
                (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
                (yyval.exprVal)->index = (yyvsp[-1].exprVal);
                printf("Tableitem: lvalue[identifier]\n");
            }
#line 2187 "parser.c"
    break;

  case 51: /* member: call DOT IDENTIFIER  */
#line 681 "parser.y"
                                {printf("Member: call.identifier\n");}
#line 2193 "parser.c"
    break;

  case 52: /* member: call LEFT_BRACKET expr RIGHT_BRACKET  */
#line 682 "parser.y"
                                                  {printf("Member: call[identifier]\n");}
#line 2199 "parser.c"
    break;

  case 53: /* $@2: %empty  */
#line 685 "parser.y"
                 {call_flag = 1;}
#line 2205 "parser.c"
    break;

  case 54: /* call: call $@2 LEFT_PAR elist RIGHT_PAR  */
#line 685 "parser.y"
                                                          {
                call_flag = 0;
                (yyval.exprVal) = make_call((yyvsp[-4].exprVal), (yyvsp[-1].exprVal));
                printf("Call: call(elist)\n");
             }
#line 2215 "parser.c"
    break;

  case 55: /* $@3: %empty  */
#line 690 "parser.y"
                    {call_flag=1;}
#line 2221 "parser.c"
    break;

  case 56: /* call: lvalue $@3 callsuffix  */
#line 690 "parser.y"
                                             {
                (yyvsp[-2].exprVal) = emit_iftableitem((yyvsp[-2].exprVal)); //se periptwsi pou itan table item
                if ((yyvsp[0].callVal)->method){
                    expr *t = (yyvsp[-2].exprVal);
                    (yyvsp[-2].exprVal) = emit_iftableitem(member_item(t, (yyvsp[0].callVal)->name));
                    (yyvsp[0].callVal)->elist->next = t; //insert san prwto argument antestrameno ara teleutaio
                }
                (yyval.exprVal) = make_call((yyvsp[-2].exprVal), (yyvsp[0].callVal)->elist); 
                printf("Call: lvalue callsuffix\n");}
#line 2235 "parser.c"
    break;

  case 57: /* $@4: %empty  */
#line 699 "parser.y"
                                        {call_flag = 1;}
#line 2241 "parser.c"
    break;

  case 58: /* call: LEFT_PAR funcdef RIGHT_PAR $@4 LEFT_PAR elist RIGHT_PAR  */
#line 699 "parser.y"
                                                                                  {
                call_flag = 0; 
                expr *func = newexpr(programfunc_e);
                func->sym = (yyvsp[-5].symtVal);
                (yyval.exprVal) = make_call(func, (yyvsp[-1].exprVal));
                printf("Call: (funcdef)(elist)\n");
            }
#line 2253 "parser.c"
    break;

  case 59: /* callsuffix: normcall  */
#line 708 "parser.y"
                     {
                (yyval.callVal) = (yyvsp[0].callVal);
                printf("Callsuffix: normcall\n");
            }
#line 2262 "parser.c"
    break;

  case 60: /* callsuffix: methodcall  */
#line 712 "parser.y"
                        {
                (yyval.callVal) = (yyvsp[0].callVal);
                printf("Callsuffix: method\n");
            }
#line 2271 "parser.c"
    break;

  case 61: /* $@5: %empty  */
#line 718 "parser.y"
                     {call_flag = 1;}
#line 2277 "parser.c"
    break;

  case 62: /* normcall: LEFT_PAR $@5 elist RIGHT_PAR  */
#line 718 "parser.y"
                                                      {
                call_flag = 0; 
                (yyval.callVal)->elist     = (yyvsp[-1].exprVal);
                (yyval.callVal)->method    = 0;
                (yyval.callVal)->name      = NULL; 
                printf("Normcall: (elist)\n");}
#line 2288 "parser.c"
    break;

  case 63: /* $@6: %empty  */
#line 726 "parser.y"
                    {call_flag = 1;}
#line 2294 "parser.c"
    break;

  case 64: /* methodcall: DOT_DOT $@6 IDENTIFIER LEFT_PAR elist RIGHT_PAR  */
#line 726 "parser.y"
                                                                          {
                call_flag = 0; 
                (yyval.callVal)->elist    = (yyvsp[-1].exprVal);
                (yyval.callVal)->method   = 1;
                (yyval.callVal)->name     = (yyvsp[-3].strVal);

                printf("Methodcall: ..identifier(elist) in line %u\n", yylineno);
            }
#line 2307 "parser.c"
    break;

  case 65: /* elist: expr  */
#line 736 "parser.y"
                 {
                (yyvsp[0].exprVal)->next = NULL;
                (yyval.exprVal) = (yyvsp[0].exprVal);
                printf("Elist: expr\n");
            }
#line 2317 "parser.c"
    break;

  case 66: /* elist: expr COMMA elist  */
#line 741 "parser.y"
                              {

                (yyvsp[-2].exprVal)->next = (yyvsp[0].exprVal);
                (yyval.exprVal) = (yyvsp[-2].exprVal);
                
                printf("Elist: expr,...,expr\n");
            }
#line 2329 "parser.c"
    break;

  case 67: /* elist: %empty  */
#line 748 "parser.y"
             {
                (yyval.exprVal) = NULL;
            }
#line 2337 "parser.c"
    break;

  case 68: /* tablemake: LEFT_BRACKET elist RIGHT_BRACKET  */
#line 753 "parser.y"
                                              { //dhmiourgia pinakwn [elist]
                
                expr *t = newexpr(newtable_e);
                t->sym = newtemp();

                emit(tablecreate, t, NULL, NULL, currQuad, yylineno);
                int i = 0;
                printf("tablemake\n");

                expr *temp = (yyvsp[-1].exprVal);
                while (temp != NULL) {
                    emit(tablesetelem, t, newexpr_constnum(i++), temp, currQuad, yylineno);
                    temp = temp->next;
                }
                
                (yyval.exprVal) = t;

                printf("Tablemake: (elist)\n");
            }
#line 2361 "parser.c"
    break;

  case 69: /* tablemake: LEFT_BRACKET indexed RIGHT_BRACKET  */
#line 772 "parser.y"
                                                { //dhmiourgia pinakwn [{x:y}, ...]
                expr *t = newexpr(newtable_e);
                t->sym = newtemp();
                emit(tablecreate, t, NULL, NULL, currQuad, yylineno);
                indexedpairs *temp = (yyvsp[-1].indexedVal);
                while (temp != NULL) {
                    emit(tablesetelem, t, temp->key, temp->value, currQuad, yylineno);
                    temp = temp->next;
                }
                (yyval.exprVal) = t;
                printf("Tablemake: (indexed)\n");
            }
#line 2378 "parser.c"
    break;

  case 70: /* indexed: indexedelem  */
#line 786 "parser.y"
                        {
                printf("Indexed: indexedelem\n");
                (yyvsp[0].indexedVal)->next = NULL;
                (yyval.indexedVal) = (yyvsp[0].indexedVal);
            }
#line 2388 "parser.c"
    break;

  case 71: /* indexed: indexedelem COMMA indexed  */
#line 791 "parser.y"
                                        {
                printf("Indexed: indexedelem,...,indexedelem\n");

                (yyvsp[-2].indexedVal)->next = (yyvsp[0].indexedVal);
                (yyval.indexedVal) = (yyvsp[-2].indexedVal);
            }
#line 2399 "parser.c"
    break;

  case 72: /* indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE  */
#line 799 "parser.y"
                                                    {
                printf("Indexedelem: [expr:expr]\n");
                indexedpairs *temp = malloc(sizeof(indexedpairs));
                temp->key = (yyvsp[-3].exprVal);
                temp->value = (yyvsp[-1].exprVal);
                (yyval.indexedVal) = temp;
            }
#line 2411 "parser.c"
    break;

  case 73: /* func_stmt: stmt func_stmt  */
#line 808 "parser.y"
                          {printf("Func_stmt: stmt,...,stmt\n");}
#line 2417 "parser.c"
    break;

  case 74: /* func_stmt: stmt  */
#line 809 "parser.y"
                   {printf("Func_stmt: stmt\n");}
#line 2423 "parser.c"
    break;

  case 75: /* $@7: %empty  */
#line 812 "parser.y"
                       {
                    currentscope = currscope() + scope_flag;
                }
#line 2431 "parser.c"
    break;

  case 76: /* block: LEFT_BRACE $@7 RIGHT_BRACE  */
#line 814 "parser.y"
                              {
                    currentscope = currscope() - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(currscope()+1);
                    }
                    {printf("Block: {}\n");}
                }
#line 2443 "parser.c"
    break;

  case 77: /* $@8: %empty  */
#line 821 "parser.y"
                        {
                    currentscope = currscope() + scope_flag;
                }
#line 2451 "parser.c"
    break;

  case 78: /* $@9: %empty  */
#line 823 "parser.y"
                                        {
                    currentscope = currscope() - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(currscope()+1);
                    }
                }
#line 2462 "parser.c"
    break;

  case 79: /* block: LEFT_BRACE $@8 func_stmt RIGHT_BRACE $@9  */
#line 829 "parser.y"
                {printf("Block: {func_stmt}\n");}
#line 2468 "parser.c"
    break;

  case 80: /* funcname: IDENTIFIER  */
#line 832 "parser.y"
                                                           {
                (yyval.strVal) = (yyvsp[0].strVal);
            }
#line 2476 "parser.c"
    break;

  case 81: /* funcname: %empty  */
#line 835 "parser.y"
              {
                sprintf(str, "%s%d%c","_f",func_counter+1,'\0');
                func_counter++;
                (yyval.strVal) = strdup(str);
            }
#line 2486 "parser.c"
    break;

  case 82: /* funcprefix: FUNCTION funcname  */
#line 842 "parser.y"
                              {
                printf("funcname: %s\n",(yyvsp[0].strVal));
                symt *temp = NULL;
                if (SymTable_lookup((yyvsp[0].strVal), currscope(), "funcdef") == NULL) {
                    if (func_flag > 0) {
                        temp = SymTable_insert((yyvsp[0].strVal), yylineno, functionlocal, programfunc_s);
                    }
                    else {
                        temp = SymTable_insert((yyvsp[0].strVal), yylineno, programvar, programfunc_s);
                    }
                    func_flag++;
                    currentscope++;   
                    scope_flag = 0;
                    
                    (yyval.symtVal) = temp;
                    (yyval.symtVal)->iaddress = nextquadlabel();
                    expr *tmp = lvalue_expr((yyval.symtVal));
                    emit(funcstart, NULL, NULL, tmp, currQuad, yylineno);
                    pushOffsetStack(currscopeoffset());
                    enterscopespace();
                    resetformalargsoffset();
                }
                else {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Function (%s) in scope %d cannot be defined\n\033[0m", yylineno, (yyvsp[0].strVal), currscope());
                    yyerror("");
                }
                


                //edw thelei $$.iaddress = nextquadlabel();
  
            }
#line 2523 "parser.c"
    break;

  case 83: /* funcargs: LEFT_PAR idlist RIGHT_PAR  */
#line 876 "parser.y"
                                     {
                enterscopespace(); //enter function locals space
                resetfunctionlocalsoffset(); //start counting locals from zero
            }
#line 2532 "parser.c"
    break;

  case 84: /* funcbody: block  */
#line 882 "parser.y"
                  {
                if (!(--func_flag)){ //an func_flag-1=0, vghka apo ola ta functions
                    scope_flag = 1;
                }
                currentscope--;
                
                SymTable_hide(currscope()+1);
                SymTable_reveal(currscope());
                printf("Funcdef: function identifier(idlist) {}\n");
                
                (yyval.uintVal) = currscopeoffset();
                exitscopespace();
            }
#line 2550 "parser.c"
    break;

  case 85: /* funcdef: funcprefix funcargs funcbody  */
#line 897 "parser.y"
                                         {
                exitscopespace();
                (yyvsp[-2].symtVal)->totalLocals = (yyvsp[0].uintVal);
                int offset = popOffsetStack();
                restorecurrscopeoffset(offset);
                (yyval.symtVal) = (yyvsp[-2].symtVal);
                expr *temp = lvalue_expr((yyvsp[-2].symtVal));
                emit(funcend, NULL, NULL, temp, currQuad, yylineno);
            }
#line 2564 "parser.c"
    break;

  case 87: /* funcblockstart: %empty  */
#line 909 "parser.y"
                {
                pushLoopStack(loopstack->loopCounter);
                loopstack->loopCounter = 0;    
            }
#line 2573 "parser.c"
    break;

  case 88: /* funcblockend: %empty  */
#line 915 "parser.y"
                {
                loopstack->loopCounter = popLoopStack();
            }
#line 2581 "parser.c"
    break;

  case 89: /* const: INTEGER  */
#line 920 "parser.y"
                    {
                printf("Const: integer\n");

                (yyval.exprVal) = newexpr_constnum((yyvsp[0].intVal));
            }
#line 2591 "parser.c"
    break;

  case 90: /* const: REAL  */
#line 925 "parser.y"
                   {
                printf("Const: real\n");

                (yyval.exprVal) = newexpr_constnum((yyvsp[0].realVal));
            }
#line 2601 "parser.c"
    break;

  case 91: /* const: STRING  */
#line 930 "parser.y"
                     {printf("Const: string\n");}
#line 2607 "parser.c"
    break;

  case 92: /* const: NIL  */
#line 931 "parser.y"
                  {printf("Const: nil\n");}
#line 2613 "parser.c"
    break;

  case 93: /* const: TRUE  */
#line 932 "parser.y"
                   {
                printf("Const: true\n");

                (yyval.exprVal) = newexpr_constbool(1);
            }
#line 2623 "parser.c"
    break;

  case 94: /* const: FALSE  */
#line 937 "parser.y"
                    {printf("Const: false\n");}
#line 2629 "parser.c"
    break;

  case 95: /* idlist: IDENTIFIER  */
#line 940 "parser.y"
                        {
    //printf("B\n");
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
#line 2646 "parser.c"
    break;

  case 96: /* idlist: IDENTIFIER COMMA idlist  */
#line 952 "parser.y"
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
#line 2662 "parser.c"
    break;

  case 98: /* ifprefix: IF LEFT_PAR expr RIGHT_PAR  */
#line 966 "parser.y"
                                       {
                emit(if_eq, (yyvsp[-1].exprVal), newexpr_constbool(1), NULL, nextquadlabel()+2, yylineno);
                (yyval.intVal) = nextquadlabel();
                emit(jump, NULL, NULL, NULL, 0, yylineno);
            }
#line 2672 "parser.c"
    break;

  case 99: /* elseprefix: ELSE  */
#line 973 "parser.y"
                 {
                (yyval.intVal) = nextquadlabel();
                emit(jump, NULL, NULL, NULL, 0, yylineno);
            }
#line 2681 "parser.c"
    break;

  case 100: /* if_stmt: ifprefix stmt  */
#line 979 "parser.y"
                          {
                patchlabel((yyvsp[-1].intVal), nextquadlabel());
            }
#line 2689 "parser.c"
    break;

  case 101: /* if_stmt: ifprefix stmt elseprefix stmt  */
#line 982 "parser.y"
                                            {
                patchlabel((yyvsp[-3].intVal), (yyvsp[-1].intVal)+1);
                patchlabel((yyvsp[-1].intVal), nextquadlabel());
            }
#line 2698 "parser.c"
    break;

  case 102: /* whilestart: WHILE  */
#line 988 "parser.y"
                  {
                (yyval.intVal) = nextquadlabel();
            }
#line 2706 "parser.c"
    break;

  case 103: /* whilecond: LEFT_PAR expr RIGHT_PAR  */
#line 993 "parser.y"
                                    {
                emit(if_eq, (yyvsp[-1].exprVal), newexpr_constbool(1), NULL, nextquadlabel()+2, yylineno);
                (yyval.intVal) = nextquadlabel();
                emit(jump, NULL, NULL, NULL, 0, yylineno);
            }
#line 2716 "parser.c"
    break;

  case 104: /* while: whilestart whilecond stmt  */
#line 1000 "parser.y"
                                      {
                emit(jump, NULL, NULL, NULL, (yyvsp[-2].intVal), yylineno);
                patchlabel((yyvsp[-1].intVal), nextquadlabel());
                patchlist((yyvsp[0].stmtVal)->breaklist, nextquadlabel());
                patchlist((yyvsp[0].stmtVal)->contlist, (yyvsp[-2].intVal));
            }
#line 2727 "parser.c"
    break;

  case 105: /* N: %empty  */
#line 1011 "parser.y"
            {
                (yyval.intVal) = nextquadlabel();
                emit(jump, NULL, NULL, NULL, nextquadlabel(), yylineno);
            }
#line 2736 "parser.c"
    break;

  case 106: /* M: %empty  */
#line 1016 "parser.y"
            {
                (yyval.intVal) = nextquadlabel();
            }
#line 2744 "parser.c"
    break;

  case 107: /* forprefix: FOR LEFT_PAR elist SEMICOLON M expr SEMICOLON  */
#line 1020 "parser.y"
                                                          {
                (yyval.forprefixVal)->test = (yyvsp[-2].intVal);
                (yyval.forprefixVal)->enter = nextquadlabel();
                emit(if_eq, (yyvsp[-1].exprVal), newexpr_constbool(1), NULL, nextquadlabel(), yylineno);
            }
#line 2754 "parser.c"
    break;

  case 108: /* for_stmt: forprefix N elist RIGHT_PAR N stmt N  */
#line 1026 "parser.y"
                                                 {
                patchlabel((yyvsp[-6].forprefixVal)->enter, (yyvsp[-2].intVal) + 1);
                patchlabel((yyvsp[-5].intVal), nextQuadlabel());
                patchlabel((yyvsp[-2].intVal), (yyvsp[-6].forprefixVal)->test);
                patchlabel((yyvsp[0].intVal), (yyvsp[-5].intVal) + 1);

                patchlist((yyvsp[-1].stmtVal)->breaklist, nextQuadlabel());
                patchlist((yyvsp[-1].stmtVal)->contlist, (yyvsp[-5].intVal) + 1);
                
            }
#line 2769 "parser.c"
    break;

  case 109: /* returnstmt: RETURN SEMICOLON  */
#line 1037 "parser.y"
                             {
                if (func_flag > 0) {
                    emit(ret, NULL, NULL, NULL, nextQuadlabel(), yylineno);
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",yylineno);
                }
            }
#line 2783 "parser.c"
    break;

  case 110: /* returnstmt: RETURN expr SEMICOLON  */
#line 1046 "parser.y"
                                   {
                if (func_flag > 0) {
                    emit(ret, NULL, NULL, (yyvsp[-1].exprVal), nextQuadlabel(), yylineno);
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",yylineno);
                }
            }
#line 2797 "parser.c"
    break;


#line 2801 "parser.c"

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

#line 1078 "parser.y"


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

    _errorexpr = malloc(sizeof(expr));

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


