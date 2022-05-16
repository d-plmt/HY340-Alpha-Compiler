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
    int call_flag = 0;
    int func_flag = 0;
    int local_flag = 0;

    //


#line 98 "parser.c"

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
  YYSYMBOL_stmts = 52,                     /* stmts  */
  YYSYMBOL_expr = 53,                      /* expr  */
  YYSYMBOL_term = 54,                      /* term  */
  YYSYMBOL_assignexpr = 55,                /* assignexpr  */
  YYSYMBOL_primary = 56,                   /* primary  */
  YYSYMBOL_lvalue = 57,                    /* lvalue  */
  YYSYMBOL_tableitem = 58,                 /* tableitem  */
  YYSYMBOL_member = 59,                    /* member  */
  YYSYMBOL_call = 60,                      /* call  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_63_3 = 63,                      /* $@3  */
  YYSYMBOL_callsuffix = 64,                /* callsuffix  */
  YYSYMBOL_normcall = 65,                  /* normcall  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_methodcall = 67,                /* methodcall  */
  YYSYMBOL_68_5 = 68,                      /* $@5  */
  YYSYMBOL_elist = 69,                     /* elist  */
  YYSYMBOL_tablemake = 70,                 /* tablemake  */
  YYSYMBOL_indexed = 71,                   /* indexed  */
  YYSYMBOL_indexedelem = 72,               /* indexedelem  */
  YYSYMBOL_block = 73,                     /* block  */
  YYSYMBOL_74_6 = 74,                      /* $@6  */
  YYSYMBOL_75_7 = 75,                      /* $@7  */
  YYSYMBOL_funcname = 76,                  /* funcname  */
  YYSYMBOL_funcprefix = 77,                /* funcprefix  */
  YYSYMBOL_funcargs = 78,                  /* funcargs  */
  YYSYMBOL_funcbody = 79,                  /* funcbody  */
  YYSYMBOL_funcdef = 80,                   /* funcdef  */
  YYSYMBOL_funcblockstart = 81,            /* funcblockstart  */
  YYSYMBOL_funcblockend = 82,              /* funcblockend  */
  YYSYMBOL_const = 83,                     /* const  */
  YYSYMBOL_idlist = 84,                    /* idlist  */
  YYSYMBOL_ifprefix = 85,                  /* ifprefix  */
  YYSYMBOL_elseprefix = 86,                /* elseprefix  */
  YYSYMBOL_if_stmt = 87,                   /* if_stmt  */
  YYSYMBOL_whilestart = 88,                /* whilestart  */
  YYSYMBOL_whilecond = 89,                 /* whilecond  */
  YYSYMBOL_while_stmt = 90,                /* while_stmt  */
  YYSYMBOL_N = 91,                         /* N  */
  YYSYMBOL_M = 92,                         /* M  */
  YYSYMBOL_forprefix = 93,                 /* forprefix  */
  YYSYMBOL_for_stmt = 94,                  /* for_stmt  */
  YYSYMBOL_returnstmt = 95,                /* returnstmt  */
  YYSYMBOL_loopstart = 96,                 /* loopstart  */
  YYSYMBOL_loopend = 97,                   /* loopend  */
  YYSYMBOL_loopstmt = 98,                  /* loopstmt  */
  YYSYMBOL_break = 99,                     /* break  */
  YYSYMBOL_continue = 100                  /* continue  */
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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   590

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  194

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
       0,   108,   108,   109,   115,   118,   122,   126,   130,   134,
     138,   143,   147,   150,   153,   158,   165,   168,   182,   196,
     210,   224,   238,   256,   274,   292,   310,   328,   346,   361,
     376,   382,   386,   400,   412,   439,   468,   496,   524,   530,
     570,   575,   578,   582,   588,   595,   654,   678,   692,   696,
     701,   705,   713,   717,   726,   726,   731,   731,   741,   741,
     750,   754,   760,   760,   769,   769,   779,   785,   791,   796,
     815,   829,   834,   842,   851,   851,   860,   860,   872,   875,
     882,   916,   923,   940,   951,   958,   963,   968,   973,   977,
     981,   986,   992,  1006,  1019,  1022,  1029,  1035,  1039,  1046,
    1052,  1059,  1071,  1076,  1080,  1089,  1102,  1111,  1121,  1123,
    1125,  1131,  1145
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
  "stmts", "expr", "term", "assignexpr", "primary", "lvalue", "tableitem",
  "member", "call", "$@1", "$@2", "$@3", "callsuffix", "normcall", "$@4",
  "methodcall", "$@5", "elist", "tablemake", "indexed", "indexedelem",
  "block", "$@6", "$@7", "funcname", "funcprefix", "funcargs", "funcbody",
  "funcdef", "funcblockstart", "funcblockend", "const", "idlist",
  "ifprefix", "elseprefix", "if_stmt", "whilestart", "whilecond",
  "while_stmt", "N", "M", "forprefix", "for_stmt", "returnstmt",
  "loopstart", "loopend", "loopstmt", "break", "continue", YY_NULLPTR
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

#define YYPACT_NINF (-171)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     213,  -171,  -171,  -171,  -171,   -30,  -171,   -23,    14,    19,
       5,     9,   279,    48,  -171,  -171,  -171,   279,     8,     8,
      23,   111,   256,  -171,    56,    87,  -171,   213,   325,  -171,
    -171,  -171,    73,  -171,  -171,   -10,  -171,  -171,    62,  -171,
    -171,   213,  -171,    70,  -171,  -171,  -171,  -171,  -171,  -171,
     279,   279,  -171,  -171,  -171,   346,  -171,  -171,  -171,  -171,
       7,    79,   -31,   -17,   -31,    81,   213,   279,   514,   -12,
      13,  -171,   388,    83,  -171,  -171,  -171,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
    -171,   279,  -171,  -171,   279,   116,   -36,   279,   128,    96,
     134,  -171,   137,   279,  -171,   279,   409,    24,  -171,   105,
    -171,   170,   303,  -171,   279,  -171,   114,  -171,   112,   542,
     529,     7,     7,  -171,  -171,  -171,   555,   555,    74,    74,
      74,    74,   514,   451,  -171,  -171,  -171,  -171,  -171,  -171,
     472,  -171,   279,  -171,     3,  -171,   118,  -171,   213,   430,
     213,  -171,    22,  -171,  -171,  -171,  -171,   279,   514,  -171,
     115,  -171,   279,   151,  -171,    40,  -171,   152,  -171,  -171,
    -171,  -171,  -171,   279,   493,   279,    43,   119,  -171,  -171,
    -171,  -171,  -171,   367,  -171,    50,  -171,   279,  -171,  -171,
    -171,    80,  -171,  -171
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    86,    87,    88,    45,     0,    99,     0,    79,     0,
       0,     0,     0,     0,    90,    91,    89,     0,     0,     0,
      76,    68,     0,    13,     0,     0,    15,     2,     0,    30,
      16,    38,    40,    49,    48,    41,    42,    11,     0,    12,
      44,     0,     5,     0,     6,   102,     7,     8,     9,    10,
       0,    68,    78,    80,   106,     0,   111,   112,    33,    46,
      32,     0,    34,    54,    36,     0,     0,     0,    66,     0,
       0,    71,     0,     0,    47,     1,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,    35,    37,     0,     0,     0,     0,     0,     0,
      94,    84,    97,     0,   108,    68,     0,     0,   107,     0,
      75,     0,     0,    69,     0,    70,     0,    31,    43,    28,
      29,    17,    18,    19,    20,    21,    26,    27,    22,    24,
      23,    25,    39,     0,    50,    62,    64,    57,    60,    61,
       0,    52,    68,    92,     0,    83,     0,    96,     0,     0,
       0,   101,     0,    95,   103,    58,    77,     0,    67,    72,
       0,    51,    68,     0,    53,     0,    81,     0,    85,    98,
     100,   109,   102,     0,     0,    68,     0,     0,    55,    93,
      82,   110,   108,     0,    73,     0,    63,    68,   102,   104,
      59,     0,   105,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,   -22,    94,    -9,  -171,  -171,  -171,   120,  -171,
    -171,   125,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
     -50,  -171,  -171,    45,    16,  -171,  -171,  -171,  -171,  -171,
    -171,   -16,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -170,  -171,  -171,  -171,  -171,  -171,  -171,   -19,
    -171,  -171
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    99,    96,   160,   137,   138,   162,   139,   163,
      69,    36,    70,    71,    37,    65,    66,    53,    38,   101,
     145,    39,   146,   180,    40,   144,    41,   148,    42,    43,
     104,    44,   105,   173,    45,    46,    47,   150,   181,   151,
      48,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,   107,   182,    58,   135,    76,    73,    94,    60,   -56,
      50,   136,    68,    72,     4,    95,   -56,    51,   192,   102,
      52,    97,     1,     2,     3,     4,    13,   113,    97,    98,
     -54,   114,    81,    82,    83,    12,    98,    13,    14,    15,
      16,   106,    68,    17,   166,   109,   167,    56,    61,    18,
      19,    57,   115,    24,    59,   152,   116,    21,   112,    22,
     -74,    54,    74,   172,    24,   114,   154,   114,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   178,   132,   114,   186,   133,   114,    75,   140,    76,
       8,   190,   165,   114,   149,    91,    68,    79,    80,    81,
      82,    83,   100,    92,    93,   158,   -75,   -75,   -75,   -75,
     103,    94,   176,   -56,     1,     2,     3,     4,   110,    95,
     -56,   193,   134,   114,   118,   185,   169,    12,   171,    13,
      14,    15,    16,    68,   141,    17,   142,   191,    62,    64,
     143,    18,    19,    63,    63,   147,   155,    67,   174,    21,
      67,    22,   -58,    68,    20,   175,    24,   177,   179,   187,
     111,   159,   168,   188,   183,     0,    68,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     5,    68,     6,
       7,     8,     9,    10,    11,     0,    12,     0,    13,    14,
      15,    16,     0,     0,    17,     0,     0,     0,     0,     0,
      18,    19,     0,     0,     0,     0,    20,   156,    21,     0,
      22,     0,    23,     0,     0,    24,     1,     2,     3,     4,
       5,     0,     6,     7,     8,     9,    10,    11,     0,    12,
       0,    13,    14,    15,    16,     0,     0,    17,     0,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,    20,
       0,    21,     0,    22,     0,    23,     0,     0,    24,     1,
       2,     3,     4,     0,     0,     0,     0,     8,     0,     0,
       0,     0,    12,     0,    13,    14,    15,    16,     0,     0,
      17,     0,     1,     2,     3,     4,    18,    19,     0,     0,
       0,     0,     0,     0,    21,    12,    22,    13,    14,    15,
      16,    24,     0,    17,     0,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,     0,     0,    21,    77,    22,
      78,     0,     0,     0,    24,     0,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    86,    87,    88,    89,     0,
      77,     0,    78,     0,     0,     0,     0,   157,    79,    80,
      81,    82,    83,    84,    85,     0,     0,    86,    87,    88,
      89,    77,     0,    78,     0,     0,     0,    90,     0,    79,
      80,    81,    82,    83,    84,    85,     0,     0,    86,    87,
      88,    89,    77,     0,    78,     0,     0,     0,   108,     0,
      79,    80,    81,    82,    83,    84,    85,     0,     0,    86,
      87,    88,    89,    77,     0,    78,     0,     0,     0,   189,
       0,    79,    80,    81,    82,    83,    84,    85,     0,     0,
      86,    87,    88,    89,    77,     0,    78,     0,     0,   117,
       0,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,    87,    88,    89,    77,     0,    78,     0,     0,
     153,     0,     0,    79,    80,    81,    82,    83,    84,    85,
       0,     0,    86,    87,    88,    89,    77,     0,    78,     0,
       0,   170,     0,     0,    79,    80,    81,    82,    83,    84,
      85,     0,     0,    86,    87,    88,    89,    77,     0,    78,
     161,     0,     0,     0,     0,    79,    80,    81,    82,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    77,     0,
      78,   164,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,     0,     0,    86,    87,    88,    89,    77,
     184,    78,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,    77,     0,    86,    87,    88,    89,
       0,     0,    79,    80,    81,    82,    83,    84,    85,     0,
       0,    86,    87,    88,    89,    79,    80,    81,    82,    83,
      84,    85,     0,     0,    86,    87,    88,    89,    79,    80,
      81,    82,    83,   -75,   -75,     0,     0,    86,    87,    88,
      89
};

static const yytype_int16 yycheck[] =
{
       9,    51,   172,    12,    40,    27,    22,    38,    17,    40,
      40,    47,    21,    22,     6,    46,    47,    40,   188,    41,
       6,    38,     3,     4,     5,     6,    18,    39,    38,    46,
      40,    43,    25,    26,    27,    16,    46,    18,    19,    20,
      21,    50,    51,    24,    41,    61,    43,    42,    40,    30,
      31,    42,    39,    45,     6,   105,    43,    38,    67,    40,
      37,    42,     6,    41,    45,    43,    42,    43,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    41,    91,    43,    41,    94,    43,     0,    97,   111,
      11,    41,   142,    43,   103,    22,   105,    23,    24,    25,
      26,    27,    40,    30,    31,   114,    32,    33,    34,    35,
      40,    38,   162,    40,     3,     4,     5,     6,    37,    46,
      47,    41,     6,    43,    41,   175,   148,    16,   150,    18,
      19,    20,    21,   142,     6,    24,    40,   187,    18,    19,
       6,    30,    31,    18,    19,     8,    41,    36,   157,    38,
      36,    40,    40,   162,    36,    40,    45,     6,     6,    40,
      66,   116,   146,   182,   173,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,   187,     9,
      10,    11,    12,    13,    14,    -1,    16,    -1,    18,    19,
      20,    21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    -1,    -1,    36,    37,    38,    -1,
      40,    -1,    42,    -1,    -1,    45,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    -1,    16,
      -1,    18,    19,    20,    21,    -1,    -1,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    45,     3,
       4,     5,     6,    -1,    -1,    -1,    -1,    11,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    21,    -1,    -1,
      24,    -1,     3,     4,     5,     6,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    16,    40,    18,    19,    20,
      21,    45,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    38,    15,    40,
      17,    -1,    -1,    -1,    45,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    -1,
      15,    -1,    17,    -1,    -1,    -1,    -1,    44,    23,    24,
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
      28,    29,    -1,    -1,    32,    33,    34,    35,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    24,    30,    31,
      36,    38,    40,    42,    45,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    70,    73,    77,    80,
      83,    85,    87,    88,    90,    93,    94,    95,    99,   100,
      40,    40,     6,    76,    42,    53,    42,    42,    53,     6,
      53,    40,    57,    60,    57,    74,    75,    36,    53,    69,
      71,    72,    53,    80,     6,     0,    51,    15,    17,    23,
      24,    25,    26,    27,    28,    29,    32,    33,    34,    35,
      42,    22,    30,    31,    38,    46,    62,    38,    46,    61,
      40,    78,    51,    40,    89,    91,    53,    69,    42,    80,
      37,    52,    53,    39,    43,    39,    43,    41,    41,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,     6,    40,    47,    64,    65,    67,
      53,     6,    40,     6,    84,    79,    81,     8,    86,    53,
      96,    98,    69,    41,    42,    41,    37,    44,    53,    72,
      63,    39,    66,    68,    39,    69,    41,    43,    73,    51,
      41,    51,    41,    92,    53,    40,    69,     6,    41,     6,
      82,    97,    91,    53,    37,    69,    41,    40,    98,    42,
      41,    69,    91,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    54,    55,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      58,    58,    59,    59,    61,    60,    62,    60,    63,    60,
      64,    64,    66,    65,    68,    67,    69,    69,    69,    70,
      70,    71,    71,    72,    74,    73,    75,    73,    76,    76,
      77,    78,    79,    80,    81,    82,    83,    83,    83,    83,
      83,    83,    84,    84,    84,    85,    86,    87,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    95,    96,    97,
      98,    99,   100
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     2,     2,     1,     3,
       1,     1,     1,     3,     1,     1,     2,     2,     1,     1,
       3,     4,     3,     4,     0,     5,     0,     3,     0,     7,
       1,     1,     0,     4,     0,     6,     1,     3,     0,     3,
       3,     1,     3,     5,     0,     3,     0,     4,     1,     0,
       2,     3,     3,     3,     0,     0,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     4,     1,     2,     4,     1,
       3,     3,     0,     0,     7,     7,     2,     3,     0,     0,
       3,     2,     2
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
#line 109 "parser.y"
                {
                // printf("\nProgram stopped\n\n");
            }
#line 1422 "parser.c"
    break;

  case 4: /* stmt: expr SEMICOLON  */
#line 115 "parser.y"
                            {
                 printf("Stmt: expr;\n");
            }
#line 1430 "parser.c"
    break;

  case 5: /* stmt: if_stmt  */
#line 118 "parser.y"
                         {
                 printf("\tif statement\n");
                 (yyval.stmtVal) = (yyvsp[0].stmtVal);
            }
#line 1439 "parser.c"
    break;

  case 6: /* stmt: while_stmt  */
#line 122 "parser.y"
                         {
                 printf("\twhile statement\n");
                 (yyval.stmtVal) = (yyvsp[0].stmtVal);
            }
#line 1448 "parser.c"
    break;

  case 7: /* stmt: for_stmt  */
#line 126 "parser.y"
                         {
                printf("\tfor statement\n");
                (yyval.stmtVal) = (yyvsp[0].stmtVal);
                }
#line 1457 "parser.c"
    break;

  case 8: /* stmt: returnstmt  */
#line 130 "parser.y"
                        {
                printf("\treturn statement\n");
                (yyval.stmtVal) = (yyvsp[0].stmtVal);
            }
#line 1466 "parser.c"
    break;

  case 9: /* stmt: break  */
#line 134 "parser.y"
                      {
                printf("\tbreak stmt\n");
                (yyval.stmtVal) = (yyvsp[0].stmtVal);
            }
#line 1475 "parser.c"
    break;

  case 10: /* stmt: continue  */
#line 138 "parser.y"
                      {
                printf("\tcontinue stmt\n");
                (yyval.stmtVal) = (yyvsp[0].stmtVal);

            }
#line 1485 "parser.c"
    break;

  case 11: /* stmt: block  */
#line 143 "parser.y"
                        {
                printf("\tBlock %p\n", (yyval.stmtVal));
                (yyval.stmtVal)=(yyvsp[0].stmtVal);
            }
#line 1494 "parser.c"
    break;

  case 12: /* stmt: funcdef  */
#line 147 "parser.y"
                        {
                printf("\tFunction definition\n");
                }
#line 1502 "parser.c"
    break;

  case 13: /* stmt: SEMICOLON  */
#line 150 "parser.y"
                        {}
#line 1508 "parser.c"
    break;

  case 14: /* stmts: stmts stmt  */
#line 153 "parser.y"
                       {
                resettemp();
                (yyval.stmtVal)->breaklist = mergelist((yyvsp[-1].stmtVal)->breaklist, (yyvsp[0].stmtVal)->breaklist);
                (yyval.stmtVal)->contlist = mergelist((yyvsp[-1].stmtVal)->contlist, (yyvsp[0].stmtVal)->contlist);
            }
#line 1518 "parser.c"
    break;

  case 15: /* stmts: stmt  */
#line 158 "parser.y"
                  {
                (yyval.stmtVal) = (yyvsp[0].stmtVal);
                resettemp();
                }
#line 1527 "parser.c"
    break;

  case 16: /* expr: assignexpr  */
#line 165 "parser.y"
                            {
                (yyval.exprVal) = (yyvsp[0].exprVal);
            }
#line 1535 "parser.c"
    break;

  case 17: /* expr: expr OP_PLUS expr  */
#line 168 "parser.y"
                                {
                //printf("Expr: expr op_plus expr\n");

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
#line 1554 "parser.c"
    break;

  case 18: /* expr: expr OP_MINUS expr  */
#line 182 "parser.y"
                                {
                //printf("Expr: expr op_minus expr\n");

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
#line 1573 "parser.c"
    break;

  case 19: /* expr: expr OP_ASTERISK expr  */
#line 196 "parser.y"
                                    {
                //printf("Expr: expr op_asterisk expr\n");

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
#line 1592 "parser.c"
    break;

  case 20: /* expr: expr OP_SLASH expr  */
#line 210 "parser.y"
                                {
                //printf("Expr: expr op_slash expr\n");

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
#line 1611 "parser.c"
    break;

  case 21: /* expr: expr OP_PERCENTAGE expr  */
#line 224 "parser.y"
                                     {
                //printf("Expr: expr op_percentage expr\n");

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
#line 1630 "parser.c"
    break;

  case 22: /* expr: expr OP_GREATER expr  */
#line 238 "parser.y"
                                  {
                //printf("Expr: expr op_greater expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);
                
                if (istempexpr((yyvsp[-2].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
                } else if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }
                
                emit(if_greater, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), nextquadlabel()+3, yylineno);
                emit(assign, newexpr_constbool(1), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
                emit(jump, NULL, NULL, NULL, nextquadlabel()+2, yylineno);
                emit(assign, newexpr_constbool(0), NULL, (yyval.exprVal), nextquadlabel(), yylineno);
            }
#line 1653 "parser.c"
    break;

  case 23: /* expr: expr OP_GREATER_EQ expr  */
#line 256 "parser.y"
                                     {
                //printf("Expr: expr op_greater_eq expr\n");

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
#line 1676 "parser.c"
    break;

  case 24: /* expr: expr OP_LESSER expr  */
#line 274 "parser.y"
                                 {
                //printf("Expr: expr op_lesser expr\n");

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
#line 1699 "parser.c"
    break;

  case 25: /* expr: expr OP_LESSER_EQ expr  */
#line 292 "parser.y"
                                    {
                //printf("Expr: expr op_lesser_eq expr\n");

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
#line 1722 "parser.c"
    break;

  case 26: /* expr: expr OP_EQ_EQ expr  */
#line 310 "parser.y"
                                {
                //printf("Expr: expr op_eq_eq expr\n");

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
#line 1745 "parser.c"
    break;

  case 27: /* expr: expr OP_NOT_EQ expr  */
#line 328 "parser.y"
                                 {
                //printf("Expr: expr op_not_eq expr\n");

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
#line 1768 "parser.c"
    break;

  case 28: /* expr: expr AND expr  */
#line 346 "parser.y"
                           {
                //printf("Expr: expr and expr\n");

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
#line 1788 "parser.c"
    break;

  case 29: /* expr: expr OR expr  */
#line 361 "parser.y"
                          {
                //printf("Expr: expr or expr\n");

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
#line 1808 "parser.c"
    break;

  case 30: /* expr: term  */
#line 376 "parser.y"
                    {
                (yyval.exprVal) = (yyvsp[0].exprVal);
                printf("Term expression %p %f\n",(yyval.exprVal), (yyval.exprVal)->numConst);
            }
#line 1817 "parser.c"
    break;

  case 31: /* term: LEFT_PAR expr RIGHT_PAR  */
#line 382 "parser.y"
                                    {
                printf("Term: (expr)\n");
                (yyval.exprVal) = (yyvsp[-1].exprVal);
            }
#line 1826 "parser.c"
    break;

  case 32: /* term: OP_MINUS expr  */
#line 386 "parser.y"
                            {
                //printf("Term: -expr\n");

                check_arith((yyvsp[0].exprVal), "-expr");
                (yyval.exprVal) = newexpr(arithexpr_e);

                if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }

                emit(uminus, (yyvsp[0].exprVal), NULL, (yyval.exprVal), currQuad, yylineno);
            }
#line 1845 "parser.c"
    break;

  case 33: /* term: NOT expr  */
#line 400 "parser.y"
                      {
                //printf("Term: not expr\n");

                (yyval.exprVal) = newexpr(boolexpr_e);

                if (istempexpr((yyvsp[0].exprVal))) {
                    (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
                } else {
                    (yyval.exprVal)->sym = newtemp();
                }
                emit(not, (yyvsp[0].exprVal), NULL, (yyval.exprVal), currQuad, yylineno);
            }
#line 1862 "parser.c"
    break;

  case 34: /* term: OP_PLUS_PLUS lvalue  */
#line 412 "parser.y"
                                 {
                if (lvalue_checker(ourVar)) {
                    //printf("Term: ++lvalue\n");

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
#line 1894 "parser.c"
    break;

  case 35: /* term: lvalue OP_PLUS_PLUS  */
#line 439 "parser.y"
                                 {
                if (lvalue_checker(ourVar)) {
                    //printf("Term: lvalue++\n");

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
                        emit(tablesetelem, (yyvsp[-1].exprVal), (yyvsp[-1].exprVal)->index, val, currQuad, yylineno);
                    }
                    else {
                        emit(assign, (yyvsp[-1].exprVal), NULL, (yyval.exprVal), currQuad, yylineno);
                        emit(add, (yyvsp[-1].exprVal), newexpr_constnum(1), (yyvsp[-1].exprVal), currQuad, yylineno);
                    }
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                    (yyval.exprVal) = _errorexpr;
                }
            }
#line 1928 "parser.c"
    break;

  case 36: /* term: OP_MINUS_MINUS lvalue  */
#line 468 "parser.y"
                                   {
                if (lvalue_checker(ourVar)) {
                    //printf("Term: --lvalue\n");

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
#line 1961 "parser.c"
    break;

  case 37: /* term: lvalue OP_MINUS_MINUS  */
#line 496 "parser.y"
                                   {                
                if (lvalue_checker(ourVar)) {
                    //printf("Term: lvalue--\n");

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
                        emit(tablesetelem, (yyvsp[-1].exprVal), (yyvsp[-1].exprVal)->index, val, currQuad, yylineno);
                    }
                    else {
                        emit(assign, (yyvsp[-1].exprVal), NULL, (yyval.exprVal), currQuad, yylineno);
                        emit(sub, (yyvsp[-1].exprVal), newexpr_constnum(1), (yyvsp[-1].exprVal), currQuad, yylineno);
                    }
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                    (yyval.exprVal) = _errorexpr;
                }
            }
#line 1994 "parser.c"
    break;

  case 38: /* term: primary  */
#line 524 "parser.y"
                     {
                (yyval.exprVal) = (yyvsp[0].exprVal);
                printf("Term: primary %p %f\n", (yyval.exprVal), (yyval.exprVal)->numConst);
                }
#line 2003 "parser.c"
    break;

  case 39: /* assignexpr: lvalue OP_EQUALS expr  */
#line 530 "parser.y"
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
                    //fprintf(stdout, "Assign expression: lvalue = expr\n");
                }
                else {
                    //printf("Assign expression: lvalue = expr\n");
                }
                if (!found_flag) {
                    if ((yyvsp[-2].exprVal)->type == tableitem_e) { //lvalue[index] = expr
                        //printf("AAAAAAAAAAAAAA");
                        emit(tablesetelem, (yyvsp[-2].exprVal), (yyvsp[-2].exprVal)->index, (yyvsp[0].exprVal), currQuad, yylineno);
                        (yyval.exprVal) = emit_iftableitem((yyvsp[-2].exprVal));
                        (yyval.exprVal)->type = assignexpr_e;
                    }
                    else { //lvalue = expr;
                        emit(assign, (yyvsp[0].exprVal), NULL, (yyvsp[-2].exprVal), currQuad, yylineno);
                        (yyval.exprVal) = newexpr(assignexpr_e);
                        (yyval.exprVal)->sym = newtemp();
                        emit(assign, (yyvsp[-2].exprVal), NULL, (yyval.exprVal), currQuad, yylineno);
                    }
                }
                 local_flag = 0;
            }
#line 2046 "parser.c"
    break;

  case 40: /* primary: lvalue  */
#line 570 "parser.y"
                    {
                (yyval.exprVal) = emit_iftableitem((yyvsp[0].exprVal));

                //printf("Primary: lvalue\n");
            }
#line 2056 "parser.c"
    break;

  case 41: /* primary: call  */
#line 575 "parser.y"
                    {
                printf("Primary: call\n");
                }
#line 2064 "parser.c"
    break;

  case 42: /* primary: tablemake  */
#line 578 "parser.y"
                       {
                (yyval.exprVal) = (yyvsp[0].exprVal);
                //printf("Primary: tableitem\n");
                }
#line 2073 "parser.c"
    break;

  case 43: /* primary: LEFT_PAR funcdef RIGHT_PAR  */
#line 582 "parser.y"
                                        {
                //printf("Primary: (funcdef)\n");
                (yyval.exprVal) = newexpr(programfunc_e);
                (yyval.exprVal)->sym = (yyvsp[-1].symtVal);
                printf("primary->sym: %s", (yyval.exprVal)->sym->name);
            }
#line 2084 "parser.c"
    break;

  case 44: /* primary: const  */
#line 588 "parser.y"
                   {
                (yyval.exprVal) = (yyvsp[0].exprVal);
                printf("Primary = %p %f\n", (yyval.exprVal), (yyval.exprVal)->numConst);
                //printf("Primary: const\n");
                }
#line 2094 "parser.c"
    break;

  case 45: /* lvalue: IDENTIFIER  */
#line 595 "parser.y"
                       {   
                    ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                    strcpy(ourVar, (yyvsp[0].strVal));               
                    //printf("Lvalue: identifier\n");
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
                                            //fprintf(stdout, "Calling symbol %s.\n",ourVar);
                                            found_flag = 1;
                                            (yyval.exprVal) = lvalue_expr(tmp_symbol);
                                            break;
                                        }
                                    }
                                    else {
                                        //fprintf(stdout, "Calling symbol %s.\n",ourVar);
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
                                //fprintf(stdout, "Calling symbol %s in parent scope.\n", $1);
                            }
                            else { //alliws kanw eisagwgh
                                tmp_symbol = SymTable_insert(ourVar, yylineno, programvar, var_s);
                            }
                            (yyval.exprVal) = lvalue_expr(tmp_symbol);
                        }

                    }
                    else {
                        (yyval.exprVal) = lvalue_expr(tmp_symbol);
                    }
            }
#line 2157 "parser.c"
    break;

  case 46: /* lvalue: LOCAL IDENTIFIER  */
#line 654 "parser.y"
                              {
                local_flag = 1;
                ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                strcpy(ourVar, (yyvsp[0].strVal)); 
                //printf("Lvalue: local identifier\n");

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
#line 2186 "parser.c"
    break;

  case 47: /* lvalue: COL_COL IDENTIFIER  */
#line 678 "parser.y"
                                {
                ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                strcpy(ourVar, (yyvsp[0].strVal)); 
                symt *tmp_symbol = NULL;
                //printf("Lvalue: ::identifier\n");
                if ((tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "global_src")) != NULL) {
                    //fprintf(stdout, "Symbol %s successfully found in global scope, line %d.\n", $IDENTIFIER, getLine(tmp_symbol));
                    (yyval.exprVal) = lvalue_expr(tmp_symbol);
                }
                else {
                    fprintf(stdout,"\033[0;31mERROR. Line %d: Symbol %s not global or undefined.\n\033[0m", yylineno, (yyvsp[0].strVal));
                    (yyval.exprVal) = _errorexpr;
                }
            }
#line 2205 "parser.c"
    break;

  case 48: /* lvalue: member  */
#line 692 "parser.y"
                    {
                //printf("Lvalue: member\n");
                (yyval.exprVal) = (yyvsp[0].exprVal);
                }
#line 2214 "parser.c"
    break;

  case 49: /* lvalue: tableitem  */
#line 696 "parser.y"
                       {
                (yyval.exprVal) = (yyvsp[0].exprVal);
            }
#line 2222 "parser.c"
    break;

  case 50: /* tableitem: lvalue DOT IDENTIFIER  */
#line 701 "parser.y"
                                  {
                (yyval.exprVal) = member_item((yyvsp[-2].exprVal), (yyvsp[0].strVal));
                //printf("Tableitem: lvalue.identifier\n");
            }
#line 2231 "parser.c"
    break;

  case 51: /* tableitem: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 705 "parser.y"
                                                     {
                (yyvsp[-3].exprVal) = emit_iftableitem((yyvsp[-3].exprVal));
                (yyval.exprVal) = newexpr(tableitem_e);
                (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
                (yyval.exprVal)->index = (yyvsp[-1].exprVal);
                //printf("Tableitem: lvalue[identifier]\n");
            }
#line 2243 "parser.c"
    break;

  case 52: /* member: call DOT IDENTIFIER  */
#line 713 "parser.y"
                                {
                //printf("Member: call.identifier\n");
                (yyval.exprVal) = member_item((yyvsp[-2].exprVal), (yyvsp[0].strVal));
            }
#line 2252 "parser.c"
    break;

  case 53: /* member: call LEFT_BRACKET expr RIGHT_BRACKET  */
#line 717 "parser.y"
                                                  { 
                //printf("Member: call[identifier]\n");
                (yyvsp[-3].exprVal) = emit_iftableitem((yyvsp[-3].exprVal));
                (yyval.exprVal) = newexpr(tableitem_e);
                (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
                (yyval.exprVal)->index = (yyvsp[-1].exprVal);
            }
#line 2264 "parser.c"
    break;

  case 54: /* $@1: %empty  */
#line 726 "parser.y"
                 {call_flag = 1;}
#line 2270 "parser.c"
    break;

  case 55: /* call: call $@1 LEFT_PAR elist RIGHT_PAR  */
#line 726 "parser.y"
                                                          {
                call_flag = 0;
                (yyval.exprVal) = make_call((yyvsp[-4].exprVal), (yyvsp[-1].exprVal));
                //printf("Call: call(elist)\n");
             }
#line 2280 "parser.c"
    break;

  case 56: /* $@2: %empty  */
#line 731 "parser.y"
                    {call_flag=1;}
#line 2286 "parser.c"
    break;

  case 57: /* call: lvalue $@2 callsuffix  */
#line 731 "parser.y"
                                             {
                (yyvsp[-2].exprVal) = emit_iftableitem((yyvsp[-2].exprVal)); //se periptwsi pou itan table item
                if ((yyvsp[0].callVal)->method){
                    expr *t = (yyvsp[-2].exprVal);
                    (yyvsp[-2].exprVal) = emit_iftableitem(member_item(t, (yyvsp[0].callVal)->name));
                    (yyvsp[0].callVal)->elist->next = t; //insert san prwto argument antestrameno ara teleutaio
                }
                (yyval.exprVal) = make_call((yyvsp[-2].exprVal), (yyvsp[0].callVal)->elist); 
                //printf("Call: lvalue callsuffix\n");
                }
#line 2301 "parser.c"
    break;

  case 58: /* $@3: %empty  */
#line 741 "parser.y"
                                        {call_flag = 1;}
#line 2307 "parser.c"
    break;

  case 59: /* call: LEFT_PAR funcdef RIGHT_PAR $@3 LEFT_PAR elist RIGHT_PAR  */
#line 741 "parser.y"
                                                                                  {
                call_flag = 0; 
                expr *func = newexpr(programfunc_e);
                func->sym = (yyvsp[-5].symtVal);
                (yyval.exprVal) = make_call(func, (yyvsp[-1].exprVal));
                //printf("Call: (funcdef)(elist)\n");
            }
#line 2319 "parser.c"
    break;

  case 60: /* callsuffix: normcall  */
#line 750 "parser.y"
                     {
                (yyval.callVal) = (yyvsp[0].callVal);
                //printf("Callsuffix: normcall\n");
            }
#line 2328 "parser.c"
    break;

  case 61: /* callsuffix: methodcall  */
#line 754 "parser.y"
                        {
                (yyval.callVal) = (yyvsp[0].callVal);
                //printf("Callsuffix: method\n");
            }
#line 2337 "parser.c"
    break;

  case 62: /* $@4: %empty  */
#line 760 "parser.y"
                     {call_flag = 1;}
#line 2343 "parser.c"
    break;

  case 63: /* normcall: LEFT_PAR $@4 elist RIGHT_PAR  */
#line 760 "parser.y"
                                                      {
                call_flag = 0; 
                (yyval.callVal)->elist     = (yyvsp[-1].exprVal);
                (yyval.callVal)->method    = 0;
                (yyval.callVal)->name      = NULL; 
                //printf("Normcall: (elist)\n");
                }
#line 2355 "parser.c"
    break;

  case 64: /* $@5: %empty  */
#line 769 "parser.y"
                    {call_flag = 1;}
#line 2361 "parser.c"
    break;

  case 65: /* methodcall: DOT_DOT $@5 IDENTIFIER LEFT_PAR elist RIGHT_PAR  */
#line 769 "parser.y"
                                                                          {
                call_flag = 0; 
                (yyval.callVal)->elist    = (yyvsp[-1].exprVal);
                (yyval.callVal)->method   = 1;
                (yyval.callVal)->name     = (yyvsp[-3].strVal);

                //printf("Methodcall: ..identifier(elist) in line %u\n", yylineno);
            }
#line 2374 "parser.c"
    break;

  case 66: /* elist: expr  */
#line 779 "parser.y"
                 {
                //printf("elist expr: %s\n",$expr->sym->name);
                (yyvsp[0].exprVal)->next = NULL;
                (yyval.exprVal) = (yyvsp[0].exprVal);
                //printf("Elist: expr\n");
            }
#line 2385 "parser.c"
    break;

  case 67: /* elist: elist COMMA expr  */
#line 785 "parser.y"
                              {
                printf("elist: %s\n",(yyvsp[0].exprVal)->sym->name);
                (yyvsp[0].exprVal)->next = (yyvsp[-2].exprVal);
                (yyval.exprVal) = (yyvsp[0].exprVal);
                //printf("Elist: expr,...,expr\n");
            }
#line 2396 "parser.c"
    break;

  case 68: /* elist: %empty  */
#line 791 "parser.y"
             {
                (yyval.exprVal) = NULL;
            }
#line 2404 "parser.c"
    break;

  case 69: /* tablemake: LEFT_BRACKET elist RIGHT_BRACKET  */
#line 796 "parser.y"
                                              { //dhmiourgia pinakwn [elist]
                
                expr *t = newexpr(newtable_e);
                t->sym = newtemp();

                emit(tablecreate, t, NULL, NULL, currQuad, yylineno);
                int i = 0;
                //printf("tablemake\n");

                expr *temp = (yyvsp[-1].exprVal);
                while (temp != NULL) {
                    emit(tablesetelem, t, newexpr_constnum(i++), temp, currQuad, yylineno);
                    temp = temp->next;
                }
                
                (yyval.exprVal) = t;

                //printf("Tablemake: (elist)\n");
            }
#line 2428 "parser.c"
    break;

  case 70: /* tablemake: LEFT_BRACKET indexed RIGHT_BRACKET  */
#line 815 "parser.y"
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
                //printf("Tablemake: (indexed)\n");
            }
#line 2445 "parser.c"
    break;

  case 71: /* indexed: indexedelem  */
#line 829 "parser.y"
                        {
                //printf("Indexed: indexedelem\n");
                (yyvsp[0].indexedVal)->next = NULL;
                (yyval.indexedVal) = (yyvsp[0].indexedVal);
            }
#line 2455 "parser.c"
    break;

  case 72: /* indexed: indexed COMMA indexedelem  */
#line 834 "parser.y"
                                        {
                //printf("Indexed: indexedelem,...,indexedelem\n");

                (yyvsp[0].indexedVal)->next = (yyvsp[0].indexedVal);
                (yyval.indexedVal) = (yyvsp[0].indexedVal);
            }
#line 2466 "parser.c"
    break;

  case 73: /* indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE  */
#line 842 "parser.y"
                                                    {
                //printf("Indexedelem: [expr:expr]\n");
                indexedpairs *temp = malloc(sizeof(indexedpairs));
                temp->key = (yyvsp[-3].exprVal);
                temp->value = (yyvsp[-1].exprVal);
                (yyval.indexedVal) = temp;
            }
#line 2478 "parser.c"
    break;

  case 74: /* $@6: %empty  */
#line 851 "parser.y"
                       {
                    currentscope = currscope() + scope_flag;
                }
#line 2486 "parser.c"
    break;

  case 75: /* block: LEFT_BRACE $@6 RIGHT_BRACE  */
#line 853 "parser.y"
                              {
                    currentscope = currscope() - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(currscope()+1);
                    }
                    (yyval.stmtVal) = calloc(1, sizeof(struct stmt_t));
                }
#line 2498 "parser.c"
    break;

  case 76: /* $@7: %empty  */
#line 860 "parser.y"
                        {
                    currentscope = currscope() + scope_flag;
                }
#line 2506 "parser.c"
    break;

  case 77: /* block: LEFT_BRACE $@7 stmts RIGHT_BRACE  */
#line 862 "parser.y"
                                    {
                    currentscope = currscope() - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(currscope()+1);
                    }
                (yyval.stmtVal) = (yyvsp[-1].stmtVal);
                }
#line 2518 "parser.c"
    break;

  case 78: /* funcname: IDENTIFIER  */
#line 872 "parser.y"
                                                           {
                (yyval.strVal) = (yyvsp[0].strVal);
            }
#line 2526 "parser.c"
    break;

  case 79: /* funcname: %empty  */
#line 875 "parser.y"
              {
                sprintf(str, "%s%d%c","_f",func_counter+1,'\0');
                func_counter++;
                (yyval.strVal) = strdup(str);
            }
#line 2536 "parser.c"
    break;

  case 80: /* funcprefix: FUNCTION funcname  */
#line 882 "parser.y"
                              {
                //printf("funcname: %s\n",$funcname);
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
#line 2573 "parser.c"
    break;

  case 81: /* funcargs: LEFT_PAR idlist RIGHT_PAR  */
#line 916 "parser.y"
                                     {
                enterscopespace(); //enter function locals space
                resetfunctionlocalsoffset(); //start counting locals from zero
                (yyval.exprVal) = (yyvsp[-1].exprVal);
            }
#line 2583 "parser.c"
    break;

  case 82: /* funcbody: funcblockstart block funcblockend  */
#line 923 "parser.y"
                                             {
                if (!(--func_flag)){ //an func_flag-1=0, vghka apo ola ta functions
                    scope_flag = 1;
                }
                currentscope--;
                
                SymTable_hide(currscope()+1);
                
                SymTable_reveal(currscope());
                //printf("Funcdef: function identifier(idlist) {}\n");
                
                (yyval.uintVal) = currscopeoffset();
                exitscopespace();
                
            }
#line 2603 "parser.c"
    break;

  case 83: /* funcdef: funcprefix funcargs funcbody  */
#line 940 "parser.y"
                                         {
                exitscopespace();
                (yyvsp[-2].symtVal)->totalLocals = (yyvsp[0].uintVal);
                int offset = popOffsetStack();
                restorecurrscopeoffset(offset);
                (yyval.symtVal) = (yyvsp[-2].symtVal);
                expr *temp = lvalue_expr((yyvsp[-2].symtVal));
                emit(funcend, NULL, NULL, temp, currQuad, yylineno);
            }
#line 2617 "parser.c"
    break;

  case 84: /* funcblockstart: %empty  */
#line 951 "parser.y"
                {
    //printf("AAAAAAAAAAAAAAAA\n");
                pushLoopStack(loopcounter);
                loopcounter = 0;   
            }
#line 2627 "parser.c"
    break;

  case 85: /* funcblockend: %empty  */
#line 958 "parser.y"
                {
                loopcounter = popLoopStack();
            }
#line 2635 "parser.c"
    break;

  case 86: /* const: INTEGER  */
#line 963 "parser.y"
                    {
                //printf("Const: integer\n");

                (yyval.exprVal) = newexpr_constnum((yyvsp[0].intVal));
            }
#line 2645 "parser.c"
    break;

  case 87: /* const: REAL  */
#line 968 "parser.y"
                   {
                //printf("Const: real\n");

                (yyval.exprVal) = newexpr_constnum((yyvsp[0].realVal));
            }
#line 2655 "parser.c"
    break;

  case 88: /* const: STRING  */
#line 973 "parser.y"
                     {
                //printf("Const: string\n");
                (yyval.exprVal) = newexpr_conststring((yyvsp[0].strVal));
                }
#line 2664 "parser.c"
    break;

  case 89: /* const: NIL  */
#line 977 "parser.y"
                  {
                //printf("Const: nil\n");
                (yyval.exprVal) = newexpr(nil_e);
                }
#line 2673 "parser.c"
    break;

  case 90: /* const: TRUE  */
#line 981 "parser.y"
                   {
                //printf("Const: true\n");

                (yyval.exprVal) = newexpr_constbool(1);
            }
#line 2683 "parser.c"
    break;

  case 91: /* const: FALSE  */
#line 986 "parser.y"
                    {
                //printf("Const: false\n");
                (yyval.exprVal) = newexpr_constbool(0);
            }
#line 2692 "parser.c"
    break;

  case 92: /* idlist: IDENTIFIER  */
#line 992 "parser.y"
                        {
    //printf("B\n");
                //printf("Idlist: identifier\n");
                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "formal");
                if (tmp_symbol != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Symbol %s in scope %d cannot be defined\n\033[0m", yylineno, (yyvsp[0].strVal),currscope());
                    (yyval.exprVal) = _errorexpr;
                }
                else {
                    symt *tmp = SymTable_insert ((yyvsp[0].strVal), yylineno, formalarg, var_s);
                    (yyval.exprVal) = lvalue_expr(tmp);
                }
            }
#line 2711 "parser.c"
    break;

  case 93: /* idlist: idlist COMMA IDENTIFIER  */
#line 1006 "parser.y"
                                      {
                //printf("Idlist: identifier,...,identifier\n");
                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup((yyvsp[0].strVal), currscope(), "formal");
                if (tmp_symbol != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Symbol %s in scope %d cannot be defined\n\033[0m", yylineno, (yyvsp[0].strVal),currscope());
                    (yyval.exprVal) = _errorexpr;
                }
                else {
                    symt *tmp = SymTable_insert ((yyvsp[0].strVal), yylineno, formalarg, var_s);
                    (yyval.exprVal) = lvalue_expr(tmp);
                }
            }
#line 2729 "parser.c"
    break;

  case 94: /* idlist: %empty  */
#line 1019 "parser.y"
              {(yyval.exprVal) = NULL;}
#line 2735 "parser.c"
    break;

  case 95: /* ifprefix: IF LEFT_PAR expr RIGHT_PAR  */
#line 1022 "parser.y"
                                       {
                emit(if_eq, (yyvsp[-1].exprVal), newexpr_constbool(1), NULL, nextquadlabel()+2, yylineno);
                (yyval.intVal) = nextquadlabel();
                emit(jump, NULL, NULL, NULL, 0, yylineno);
            }
#line 2745 "parser.c"
    break;

  case 96: /* elseprefix: ELSE  */
#line 1029 "parser.y"
                 {
                (yyval.intVal) = nextquadlabel();
                emit(jump, NULL, NULL, NULL, 0, yylineno);
            }
#line 2754 "parser.c"
    break;

  case 97: /* if_stmt: ifprefix stmt  */
#line 1035 "parser.y"
                          {
                patchlabel((yyvsp[-1].intVal), nextquadlabel());
                (yyval.stmtVal) = (yyvsp[0].stmtVal);
            }
#line 2763 "parser.c"
    break;

  case 98: /* if_stmt: ifprefix stmt elseprefix stmt  */
#line 1039 "parser.y"
                                            {
                patchlabel((yyvsp[-3].intVal), (yyvsp[-1].intVal)+1);
                patchlabel((yyvsp[-1].intVal), nextquadlabel());
                (yyval.stmtVal) = (yyvsp[-2].stmtVal);
            }
#line 2773 "parser.c"
    break;

  case 99: /* whilestart: WHILE  */
#line 1046 "parser.y"
                  {
                (yyval.intVal) = nextquadlabel();
                printf("Quad: %d\n", (yyval.intVal));
            }
#line 2782 "parser.c"
    break;

  case 100: /* whilecond: LEFT_PAR expr RIGHT_PAR  */
#line 1052 "parser.y"
                                    {
                emit(if_eq, (yyvsp[-1].exprVal), newexpr_constbool(1), NULL, nextquadlabel()+2, yylineno);
                (yyval.intVal) = nextquadlabel();
                emit(jump, NULL, NULL, NULL, 0, yylineno);
            }
#line 2792 "parser.c"
    break;

  case 101: /* while_stmt: whilestart whilecond loopstmt  */
#line 1059 "parser.y"
                                               {
                
                emit(jump, NULL, NULL, NULL, (yyvsp[-2].intVal), yylineno);
                patchlabel((yyvsp[-1].intVal), nextquadlabel());
                printf("--------->%d\n", (yyvsp[-1].intVal));
                    patchlist((yyvsp[0].stmtVal)->breaklist, nextquadlabel());
                    patchlist((yyvsp[0].stmtVal)->contlist, (yyvsp[-2].intVal));
                    (yyval.stmtVal) = (yyvsp[0].stmtVal);
            }
#line 2806 "parser.c"
    break;

  case 102: /* N: %empty  */
#line 1071 "parser.y"
            {
                (yyval.intVal) = nextquadlabel();
                emit(jump, NULL, NULL, NULL, nextquadlabel(), yylineno);
            }
#line 2815 "parser.c"
    break;

  case 103: /* M: %empty  */
#line 1076 "parser.y"
            {
                (yyval.intVal) = nextquadlabel();
            }
#line 2823 "parser.c"
    break;

  case 104: /* forprefix: FOR LEFT_PAR elist SEMICOLON M expr SEMICOLON  */
#line 1080 "parser.y"
                                                          {
                (yyval.exprVal) = (yyvsp[-1].exprVal);
                (yyval.exprVal)->test = (yyvsp[-2].intVal);
                (yyval.exprVal)->enter = nextquadlabel();
                
                emit(if_eq, (yyvsp[-1].exprVal), newexpr_constbool(1), NULL, nextquadlabel(), yylineno);
                
            }
#line 2836 "parser.c"
    break;

  case 105: /* for_stmt: forprefix N elist RIGHT_PAR N loopstmt N  */
#line 1089 "parser.y"
                                                     {
                
                patchlabel((yyvsp[-6].exprVal)->enter, (yyvsp[-2].intVal) + 1);
                patchlabel((yyvsp[-5].intVal), nextquadlabel());
                patchlabel((yyvsp[-2].intVal), (yyvsp[-6].exprVal)->test);
                patchlabel((yyvsp[0].intVal), (yyvsp[-5].intVal) + 1);

                patchlist((yyvsp[-1].stmtVal)->breaklist, nextquadlabel());
                patchlist((yyvsp[-1].stmtVal)->contlist, (yyvsp[-5].intVal) + 1);
                
                (yyval.stmtVal) = (yyvsp[-1].stmtVal);
            }
#line 2853 "parser.c"
    break;

  case 106: /* returnstmt: RETURN SEMICOLON  */
#line 1102 "parser.y"
                             {
                if (func_flag > 0) {
                    emit(ret, NULL, NULL, NULL, nextquadlabel(), yylineno);
                    //printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",yylineno);
                }
            }
#line 2867 "parser.c"
    break;

  case 107: /* returnstmt: RETURN expr SEMICOLON  */
#line 1111 "parser.y"
                                   {
                if (func_flag > 0) {
                    emit(ret, NULL, NULL, (yyvsp[-1].exprVal), nextquadlabel(), yylineno);
                    //printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",yylineno);
                }
            }
#line 2881 "parser.c"
    break;

  case 108: /* loopstart: %empty  */
#line 1121 "parser.y"
             {++loopcounter;}
#line 2887 "parser.c"
    break;

  case 109: /* loopend: %empty  */
#line 1123 "parser.y"
             {loopcounter--;}
#line 2893 "parser.c"
    break;

  case 110: /* loopstmt: loopstart stmt loopend  */
#line 1125 "parser.y"
                                   {
                (yyval.stmtVal) = (yyvsp[-1].stmtVal);
                printf("loopstmt %p\n", (yyvsp[-1].stmtVal));
            }
#line 2902 "parser.c"
    break;

  case 111: /* break: BREAK SEMICOLON  */
#line 1131 "parser.y"
                            {
                if (loopcounter < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"break\" can't be used without a loop.\n\033[0m", yylineno);
                    (yyval.stmtVal) = NULL;
                }
                else {
                    //printf("\tkeyword \"break\"\n");
                    make_stmt((yyval.stmtVal));
                    (yyval.stmtVal)->breaklist = newlist(nextquadlabel());
                    emit(jump, NULL, NULL, 0, nextquadlabel(), yylineno);
                }
            }
#line 2919 "parser.c"
    break;

  case 112: /* continue: CONTINUE SEMICOLON  */
#line 1145 "parser.y"
                               {
                if (loopcounter < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"continue\" can't be used without a loop.\n\033[0m", yylineno);
                    (yyval.stmtVal) = NULL;
                }
                else {
                    //printf("\tkeyword \"continue\"\n");
                    make_stmt((yyval.stmtVal));
                    (yyval.stmtVal)->contlist = newlist(nextquadlabel());
                    emit(jump, NULL, NULL, 0, nextquadlabel(), yylineno);
                }
            }
#line 2936 "parser.c"
    break;


#line 2940 "parser.c"

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

#line 1158 "parser.y"


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
                    //fprintf(stdout, "Term: ++lvalue\n");
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
                //fprintf(stdout, "Term: ++lvalue\n");
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
    printquads();
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
    printquads();
    return 0;
}


