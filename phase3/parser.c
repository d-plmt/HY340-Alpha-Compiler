/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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
    #include "symT.h" 
    #include <stdlib.h>

    int yyerror (char* yaccProvidedMessage);
    int yylex(void);

    extern int total_lines;
    extern char* yytext;
    extern FILE* yyin;

    SymTable *lera;
    scope_link *lista;
    char *str;

    unsigned int block = 0;
    unsigned int scope = 0;
    int scope_flag = 1;
    int nested_func_flag = 0;
    int functions = 0;
    int func_counter = 0;
    int prev_block = 0;
    int loop_scope = 0;
    int call_flag = 0;

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    REAL = 259,
    STRING = 260,
    IDENTIFIER = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    FOR = 265,
    FUNCTION = 266,
    RETURN = 267,
    BREAK = 268,
    CONTINUE = 269,
    AND = 270,
    NOT = 271,
    OR = 272,
    LOCAL = 273,
    TRUE = 274,
    FALSE = 275,
    NIL = 276,
    OP_EQUALS = 277,
    OP_PLUS = 278,
    OP_MINUS = 279,
    OP_ASTERISK = 280,
    OP_SLASH = 281,
    OP_PERCENTAGE = 282,
    OP_EQ_EQ = 283,
    OP_NOT_EQ = 284,
    OP_PLUS_PLUS = 285,
    OP_MINUS_MINUS = 286,
    OP_GREATER = 287,
    OP_LESSER = 288,
    OP_GREATER_EQ = 289,
    OP_LESSER_EQ = 290,
    LEFT_BRACE = 291,
    RIGHT_BRACE = 292,
    LEFT_BRACKET = 293,
    RIGHT_BRACKET = 294,
    LEFT_PAR = 295,
    RIGHT_PAR = 296,
    SEMICOLON = 297,
    COMMA = 298,
    COLON = 299,
    COL_COL = 300,
    DOT = 301,
    DOT_DOT = 302,
    LINE_COMM = 303
  };
#endif
/* Tokens.  */
#define INTEGER 258
#define REAL 259
#define STRING 260
#define IDENTIFIER 261
#define IF 262
#define ELSE 263
#define WHILE 264
#define FOR 265
#define FUNCTION 266
#define RETURN 267
#define BREAK 268
#define CONTINUE 269
#define AND 270
#define NOT 271
#define OR 272
#define LOCAL 273
#define TRUE 274
#define FALSE 275
#define NIL 276
#define OP_EQUALS 277
#define OP_PLUS 278
#define OP_MINUS 279
#define OP_ASTERISK 280
#define OP_SLASH 281
#define OP_PERCENTAGE 282
#define OP_EQ_EQ 283
#define OP_NOT_EQ 284
#define OP_PLUS_PLUS 285
#define OP_MINUS_MINUS 286
#define OP_GREATER 287
#define OP_LESSER 288
#define OP_GREATER_EQ 289
#define OP_LESSER_EQ 290
#define LEFT_BRACE 291
#define RIGHT_BRACE 292
#define LEFT_BRACKET 293
#define RIGHT_BRACKET 294
#define LEFT_PAR 295
#define RIGHT_PAR 296
#define SEMICOLON 297
#define COMMA 298
#define COLON 299
#define COL_COL 300
#define DOT 301
#define DOT_DOT 302
#define LINE_COMM 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "parser.y"
int intVal; double realVal; char *strVal;

#line 249 "parser.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */



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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  68
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   556

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  183

#define YYUNDEFTOK  2
#define YYMAXUTOK   303


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
       0,    65,    65,    66,    69,    70,    71,    72,    73,    74,
      82,    90,    91,    92,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   115,
     116,   117,   118,   126,   135,   143,   151,   154,   164,   165,
     166,   167,   168,   171,   196,   213,   223,   226,   227,   228,
     229,   232,   232,   233,   234,   234,   237,   238,   241,   241,
     244,   244,   247,   248,   249,   252,   253,   256,   257,   260,
     263,   264,   267,   267,   277,   280,   277,   288,   288,   316,
     318,   315,   344,   345,   346,   347,   348,   349,   352,   361,
     370,   373,   374,   377,   377,   386,   386,   395,   403
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "REAL", "STRING",
  "IDENTIFIER", "IF", "ELSE", "WHILE", "FOR", "FUNCTION", "RETURN",
  "BREAK", "CONTINUE", "AND", "NOT", "OR", "LOCAL", "TRUE", "FALSE", "NIL",
  "OP_EQUALS", "OP_PLUS", "OP_MINUS", "OP_ASTERISK", "OP_SLASH",
  "OP_PERCENTAGE", "OP_EQ_EQ", "OP_NOT_EQ", "OP_PLUS_PLUS",
  "OP_MINUS_MINUS", "OP_GREATER", "OP_LESSER", "OP_GREATER_EQ",
  "OP_LESSER_EQ", "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET",
  "RIGHT_BRACKET", "LEFT_PAR", "RIGHT_PAR", "SEMICOLON", "COMMA", "COLON",
  "COL_COL", "DOT", "DOT_DOT", "LINE_COMM", "$accept", "program", "stmt",
  "expr", "term", "assignexpr", "primary", "lvalue", "member", "call",
  "$@1", "$@2", "callsuffix", "normcall", "$@3", "methodcall", "$@4",
  "elist", "objectdef", "indexed", "indexedelem", "func_stmt", "block",
  "$@5", "$@6", "$@7", "funcdef", "$@8", "$@9", "$@10", "const", "idlist",
  "ifstmt", "whilestmt", "$@11", "forstmt", "$@12", "returnstmt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
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
# endif

#define YYPACT_NINF (-150)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-73)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     156,  -150,  -150,  -150,  -150,   -16,     0,     2,    -4,     1,
       7,    11,   245,    38,  -150,  -150,  -150,   245,     5,     5,
      20,   199,   222,  -150,    52,    59,   156,   115,  -150,  -150,
    -150,    71,  -150,    14,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,   245,   245,   245,  -150,  -150,  -150,   312,  -150,
    -150,  -150,  -150,     3,    65,    66,   -20,    66,    47,   156,
     245,   291,    48,    53,    43,   354,    57,  -150,  -150,  -150,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,  -150,   245,  -150,  -150,   245,  -150,    88,
      91,  -150,  -150,  -150,   245,    97,    68,   375,   396,    63,
      70,   108,  -150,    74,  -150,   156,    79,   269,   245,  -150,
    -150,    83,  -150,    81,   508,   495,     3,     3,  -150,  -150,
    -150,   521,   521,    56,    56,    56,    56,   480,   417,   245,
    -150,    82,   438,  -150,   245,   156,  -150,   245,  -150,    93,
      85,  -150,  -150,  -150,   245,  -150,  -150,    84,  -150,    90,
    -150,  -150,    96,   126,   156,   333,   108,   108,   109,  -150,
     459,   245,  -150,   245,  -150,   156,  -150,   245,   105,  -150,
    -150,  -150,   110,   112,  -150,   114,   109,  -150,  -150,  -150,
    -150,   156,  -150
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    82,    83,    84,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    85,     0,     0,     0,
      74,    64,     0,    13,     0,     0,     3,     0,    28,    14,
      36,    38,    46,    39,    40,    11,    12,    42,     5,     6,
       7,     8,     0,     0,    64,    79,    77,    97,     0,     9,
      10,    31,    44,    30,     0,    32,    51,    34,     0,     0,
       0,    62,     0,     0,    67,     0,     0,    45,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,    33,    35,     0,    58,     0,
       0,    53,    56,    57,     0,     0,     0,     0,     0,     0,
       0,    90,    98,     0,    73,    71,     0,     0,    64,    65,
      66,     0,    29,    41,    26,    27,    15,    16,    17,    18,
      19,    24,    25,    20,    22,    21,    23,    37,     0,    64,
      47,     0,     0,    49,    64,     0,    93,     0,    80,    88,
       0,    54,    70,    75,     0,    63,    68,     0,    48,     0,
      60,    50,     0,    91,     0,     0,    90,    90,     0,    76,
       0,    64,    59,    64,    52,     0,    94,    64,     0,    89,
      78,    69,     0,     0,    92,     0,     0,    55,    61,    95,
      81,     0,    96
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,   130,   -58,    -9,  -150,  -150,  -150,    19,  -150,    37,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,   -34,  -150,    60,
    -150,    73,  -149,  -150,  -150,  -150,    -6,  -150,  -150,  -150,
    -150,  -142,  -150,  -150,  -150,  -150,  -150,  -150
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      96,   147,    91,    92,   129,    93,   163,    62,    34,    63,
      64,   106,    35,    58,    59,   159,    36,   101,   100,   156,
      37,   140,    38,    39,   154,    40,   181,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,   105,    45,    51,     1,     2,     3,     4,    53,   170,
      99,     4,    61,    65,   168,   169,    66,    12,    94,    13,
      14,    15,    16,    13,    42,    17,    95,   180,    74,    75,
      76,    18,    19,    97,    98,    61,    46,    55,    57,    21,
      43,    22,    44,    47,    52,    54,    24,   105,   103,    49,
      24,   107,    94,    50,   -51,    56,    56,   -72,    67,    68,
      95,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   145,   127,     8,   153,   128,    72,
      73,    74,    75,    76,   104,   132,   111,   109,   -73,   -73,
     -73,   -73,   110,    84,   130,   149,   166,   131,   113,    61,
     152,    85,    86,   133,    87,   137,    88,   174,   134,    87,
     138,    88,    89,    90,   139,   141,   143,    89,    90,    60,
      61,   -54,   150,   182,   161,    61,   158,   172,   155,   173,
      70,   162,    71,   175,   165,   160,   157,   164,    72,    73,
      74,    75,    76,    77,    78,    20,   176,    79,    80,    81,
      82,   177,    61,   178,    61,   179,    69,    83,    61,     1,
       2,     3,     4,     5,     0,     6,     7,     8,     9,    10,
      11,   146,    12,     0,    13,    14,    15,    16,   142,     0,
      17,     0,     0,     0,     0,     0,    18,    19,     0,     0,
       0,     0,    20,     0,    21,     0,    22,     0,    23,     0,
       0,    24,     1,     2,     3,     4,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,     0,    13,    14,    15,
      16,     0,     0,    17,     0,     1,     2,     3,     4,    18,
      19,     0,     0,     8,     0,    60,     0,    21,    12,    22,
      13,    14,    15,    16,    24,     0,    17,     0,     1,     2,
       3,     4,    18,    19,     0,     0,     0,     0,     0,     0,
      21,    12,    22,    13,    14,    15,    16,    24,     0,    17,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,     0,     0,    21,    70,    22,    71,     0,     0,     0,
      24,     0,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    80,    81,    82,     0,    70,     0,    71,     0,
       0,     0,     0,   144,    72,    73,    74,    75,    76,    77,
      78,     0,     0,    79,    80,    81,    82,    70,     0,    71,
       0,     0,     0,     0,   108,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,    81,    82,    70,     0,
      71,     0,     0,     0,   102,     0,    72,    73,    74,    75,
      76,    77,    78,     0,     0,    79,    80,    81,    82,    70,
       0,    71,     0,     0,     0,   167,     0,    72,    73,    74,
      75,    76,    77,    78,     0,     0,    79,    80,    81,    82,
      70,     0,    71,     0,     0,   112,     0,     0,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    81,
      82,    70,     0,    71,     0,     0,   135,     0,     0,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
      81,    82,    70,     0,    71,     0,     0,   136,     0,     0,
      72,    73,    74,    75,    76,    77,    78,     0,     0,    79,
      80,    81,    82,    70,     0,    71,   148,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,    81,    82,    70,     0,    71,   151,     0,     0,
       0,     0,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    80,    81,    82,    70,   171,    71,     0,     0,
       0,     0,     0,    72,    73,    74,    75,    76,    77,    78,
      70,     0,    79,    80,    81,    82,     0,     0,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    81,
      82,    72,    73,    74,    75,    76,    77,    78,     0,     0,
      79,    80,    81,    82,    72,    73,    74,    75,    76,   -73,
     -73,     0,     0,    79,    80,    81,    82
};

static const yytype_int16 yycheck[] =
{
       9,    59,     6,    12,     3,     4,     5,     6,    17,   158,
      44,     6,    21,    22,   156,   157,    22,    16,    38,    18,
      19,    20,    21,    18,    40,    24,    46,   176,    25,    26,
      27,    30,    31,    42,    43,    44,    40,    18,    19,    38,
      40,    40,    40,    42,     6,    40,    45,   105,    54,    42,
      45,    60,    38,    42,    40,    18,    19,    37,     6,     0,
      46,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   108,    84,    11,   135,    87,    23,
      24,    25,    26,    27,    37,    94,    43,    39,    32,    33,
      34,    35,    39,    22,     6,   129,   154,     6,    41,   108,
     134,    30,    31,     6,    38,    42,    40,   165,    40,    38,
      40,    40,    46,    47,     6,    41,    37,    46,    47,    36,
     129,    40,    40,   181,    40,   134,    41,   161,   137,   163,
      15,    41,    17,   167,     8,   144,    43,    41,    23,    24,
      25,    26,    27,    28,    29,    36,    41,    32,    33,    34,
      35,    41,   161,    41,   163,    41,    26,    42,   167,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,   111,    16,    -1,    18,    19,    20,    21,   105,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,
      -1,    -1,    36,    -1,    38,    -1,    40,    -1,    42,    -1,
      -1,    45,     3,     4,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
      21,    -1,    -1,    24,    -1,     3,     4,     5,     6,    30,
      31,    -1,    -1,    11,    -1,    36,    -1,    38,    16,    40,
      18,    19,    20,    21,    45,    -1,    24,    -1,     3,     4,
       5,     6,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    16,    40,    18,    19,    20,    21,    45,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    15,    40,    17,    -1,    -1,    -1,
      45,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    -1,    15,    -1,    17,    -1,
      -1,    -1,    -1,    44,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35,    15,    -1,    17,
      -1,    -1,    -1,    -1,    43,    23,    24,    25,    26,    27,
      28,    29,    -1,    -1,    32,    33,    34,    35,    15,    -1,
      17,    -1,    -1,    -1,    42,    -1,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    32,    33,    34,    35,    15,
      -1,    17,    -1,    -1,    -1,    42,    -1,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    32,    33,    34,    35,
      15,    -1,    17,    -1,    -1,    41,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    15,    -1,    17,    -1,    -1,    41,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    15,    -1,    17,    -1,    -1,    41,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    32,
      33,    34,    35,    15,    -1,    17,    39,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    15,    -1,    17,    39,    -1,    -1,
      -1,    -1,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    32,    33,    34,    35,    15,    37,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,    28,    29,
      15,    -1,    32,    33,    34,    35,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      32,    33,    34,    35,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    32,    33,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      13,    14,    16,    18,    19,    20,    21,    24,    30,    31,
      36,    38,    40,    42,    45,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    67,    71,    75,    79,    81,    82,
      84,    86,    40,    40,    40,     6,    40,    42,    52,    42,
      42,    52,     6,    52,    40,    56,    58,    56,    72,    73,
      36,    52,    66,    68,    69,    52,    75,     6,     0,    50,
      15,    17,    23,    24,    25,    26,    27,    28,    29,    32,
      33,    34,    35,    42,    22,    30,    31,    38,    40,    46,
      47,    61,    62,    64,    38,    46,    59,    52,    52,    66,
      77,    76,    42,    75,    37,    51,    70,    52,    43,    39,
      39,    43,    41,    41,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    63,
       6,     6,    52,     6,    40,    41,    41,    42,    40,     6,
      80,    41,    70,    37,    44,    66,    68,    60,    39,    66,
      40,    39,    66,    51,    83,    52,    78,    43,    41,    74,
      52,    40,    41,    65,    41,     8,    51,    42,    80,    80,
      71,    37,    66,    66,    51,    66,    41,    41,    41,    41,
      71,    85,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      55,    55,    55,    56,    56,    56,    56,    57,    57,    57,
      57,    59,    58,    58,    60,    58,    61,    61,    63,    62,
      65,    64,    66,    66,    66,    67,    67,    68,    68,    69,
      70,    70,    72,    71,    73,    74,    71,    76,    75,    77,
      78,    75,    79,    79,    79,    79,    79,    79,    80,    80,
      80,    81,    81,    83,    82,    85,    84,    86,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       2,     2,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     3,     1,     1,     2,     2,     1,     3,     4,     3,
       4,     0,     5,     2,     0,     7,     1,     1,     0,     4,
       0,     6,     1,     3,     0,     3,     3,     1,     3,     5,
       2,     1,     0,     3,     0,     0,     5,     0,     6,     0,
       0,     8,     1,     1,     1,     1,     1,     1,     1,     3,
       0,     5,     7,     0,     6,     0,    10,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 3:
#line 66 "parser.y"
                {printf("\nProgram stopped\n\n");}
#line 1629 "parser.c"
    break;

  case 4:
#line 69 "parser.y"
                            {printf("Stmt: expr;\n");}
#line 1635 "parser.c"
    break;

  case 5:
#line 70 "parser.y"
                        {printf("\tif statement\n");}
#line 1641 "parser.c"
    break;

  case 6:
#line 71 "parser.y"
                        {printf("\twhile statement\n");}
#line 1647 "parser.c"
    break;

  case 7:
#line 72 "parser.y"
                        {printf("\tfor statement\n");}
#line 1653 "parser.c"
    break;

  case 8:
#line 73 "parser.y"
                        {printf("\treturn statement\n");}
#line 1659 "parser.c"
    break;

  case 9:
#line 74 "parser.y"
                                {
                if (loop_scope < 1) {
                    fprintf(stderr, "ERROR: Keyword \"break\" can't be used without a loop.\n");
                }
                else {
                    printf("\tkeyword \"break\"\n");
                }
            }
#line 1672 "parser.c"
    break;

  case 10:
#line 82 "parser.y"
                                {
                if (loop_scope < 1) {
                    fprintf(stderr, "ERROR: Keyword \"continue\" can't be used without a loop.\n");
                }
                else {
                    printf("\tkeyword \"continue\"\n");
                }
            }
#line 1685 "parser.c"
    break;

  case 11:
#line 90 "parser.y"
                        {printf("\tBlock\n");}
#line 1691 "parser.c"
    break;

  case 12:
#line 91 "parser.y"
                        {printf("\tFunction definition\n");}
#line 1697 "parser.c"
    break;

  case 14:
#line 95 "parser.y"
                            {printf("Assign expression\n");}
#line 1703 "parser.c"
    break;

  case 15:
#line 96 "parser.y"
                                {printf("Expr: expr op_plus expr\n");}
#line 1709 "parser.c"
    break;

  case 16:
#line 97 "parser.y"
                                {printf("Expr: expr op_minus expr\n");}
#line 1715 "parser.c"
    break;

  case 17:
#line 98 "parser.y"
                                    {printf("Expr: expr op_asterisk expr\n");}
#line 1721 "parser.c"
    break;

  case 18:
#line 99 "parser.y"
                                {printf("Expr: expr op_slash expr\n");}
#line 1727 "parser.c"
    break;

  case 19:
#line 100 "parser.y"
                                     {printf("Expr: expr op_percentage expr\n");}
#line 1733 "parser.c"
    break;

  case 20:
#line 101 "parser.y"
                                  {printf("Expr: expr op_greater expr\n");}
#line 1739 "parser.c"
    break;

  case 21:
#line 102 "parser.y"
                                     {printf("Expr: expr op_greater_eq expr\n");}
#line 1745 "parser.c"
    break;

  case 22:
#line 103 "parser.y"
                                 {printf("Expr: expr op_lesser expr\n");}
#line 1751 "parser.c"
    break;

  case 23:
#line 104 "parser.y"
                                    {printf("Expr: expr op_lesser_eq expr\n");}
#line 1757 "parser.c"
    break;

  case 24:
#line 105 "parser.y"
                                {printf("Expr: expr op_eq_eq expr\n");}
#line 1763 "parser.c"
    break;

  case 25:
#line 106 "parser.y"
                                 {printf("Expr: expr op_not_eq expr\n");}
#line 1769 "parser.c"
    break;

  case 26:
#line 107 "parser.y"
                           {printf("Expr: expr and expr\n");}
#line 1775 "parser.c"
    break;

  case 27:
#line 108 "parser.y"
                          {printf("Expr: expr or expr\n");}
#line 1781 "parser.c"
    break;

  case 28:
#line 109 "parser.y"
                    {printf("Term expression\n");}
#line 1787 "parser.c"
    break;

  case 29:
#line 115 "parser.y"
                                    {printf("Term: (expr)\n");}
#line 1793 "parser.c"
    break;

  case 30:
#line 116 "parser.y"
                            {printf("Term: -expr\n");}
#line 1799 "parser.c"
    break;

  case 31:
#line 117 "parser.y"
                      {printf("Term: not expr\n");}
#line 1805 "parser.c"
    break;

  case 32:
#line 118 "parser.y"
                                 {
                if (SymTable_type_lookup((yyvsp[0].strVal),scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Term: ++lvalue\n");
                }
            }
#line 1818 "parser.c"
    break;

  case 33:
#line 126 "parser.y"
                                 {
                printf("dollar 1: %s\tscope: %d\n",(yyvsp[-1].strVal),scope);
                if (SymTable_type_lookup((yyvsp[-1].strVal),scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Term: lvalue++\n");
                }
            }
#line 1832 "parser.c"
    break;

  case 34:
#line 135 "parser.y"
                                   {
                if (SymTable_type_lookup((yyvsp[0].strVal),scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Term: --lvalue\n");
                }
            }
#line 1845 "parser.c"
    break;

  case 35:
#line 143 "parser.y"
                                   {                
                if (SymTable_type_lookup((yyvsp[-1].strVal),scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Term: lvalue--\n");
                }
            }
#line 1858 "parser.c"
    break;

  case 36:
#line 151 "parser.y"
                     {printf("Term: primary\n");}
#line 1864 "parser.c"
    break;

  case 37:
#line 154 "parser.y"
                                  {                
                if (SymTable_type_lookup((yyvsp[-2].strVal),scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Assign expression: lvalue = expr\n");
                }
            }
#line 1877 "parser.c"
    break;

  case 38:
#line 164 "parser.y"
                    {printf("Primary: lvalue\n");}
#line 1883 "parser.c"
    break;

  case 39:
#line 165 "parser.y"
                    {printf("Primary: call\n");}
#line 1889 "parser.c"
    break;

  case 40:
#line 166 "parser.y"
                       {printf("Primary: objectdef\n");}
#line 1895 "parser.c"
    break;

  case 41:
#line 167 "parser.y"
                                        {printf("Primary: (funcdef)\n");}
#line 1901 "parser.c"
    break;

  case 42:
#line 168 "parser.y"
                   {printf("Primary: const\n");}
#line 1907 "parser.c"
    break;

  case 43:
#line 171 "parser.y"
                       {
                if (call_flag == 0) {                     
                    printf("Lvalue: identifier\n");
                    int returned = SymTable_general_lookup((yyvsp[0].strVal), scope, 1, block, "new_var");
                    if (returned == 2) {
                        //fprintf(stdout, "%s refers to another symbol in the same scope.\n",$1);
                    }
                    else if (returned == 0) {
                        //fprintf(stdout, "%s refers to another symbol in a parent scope.\n", $1);
                    }
                    else if (returned == 1) {
                        if (scope == 0) {
                            SymTable_insert((yyvsp[0].strVal), scope, total_lines, 0, block);
                        }
                        else {
                            SymTable_insert((yyvsp[0].strVal), scope, total_lines, 1, block);
                        }
                    }
                    else if (returned == -1) {
                        fprintf(stdout, "\nERROR: Cannot access (%s) in scope %d \n", (yyvsp[0].strVal), scope);
                    }
                }

            }
#line 1936 "parser.c"
    break;

  case 44:
#line 196 "parser.y"
                              {
                printf("Lvalue: local identifier\n");
                int returned = SymTable_general_lookup((yyvsp[0].strVal), scope, 1, block, "local");
                int realtype = 1;
                if (scope == 0) {
                    realtype = 0;
                }
                if (returned == 1) {
                    SymTable_insert ((yyvsp[0].strVal), scope, total_lines, realtype, block);
                }
                else if (returned == 2) {
                    //fprintf(stdout, "Local variable %s already defined.\n", $2);
                }
                else {
                    fprintf(stdout, "\nERROR: Variable (%s) cannot be defined in scope %d line %d\n", (yyvsp[0].strVal), scope, total_lines);
                }
            }
#line 1958 "parser.c"
    break;

  case 45:
#line 213 "parser.y"
                                {
                printf("Lvalue: ::identifier\n");
                int returned = SymTable_general_lookup((yyvsp[0].strVal), 0, 0, block, "global_src");
                if (returned == 2) {
                    //fprintf(stdout, "Symbol %s successfully found in global scope.\n", $2);
                }
                else {
                    fprintf(stdout,"\nERROR: Symbol %s in line %d not global or undefined.\n", (yyvsp[0].strVal), total_lines);
                }
            }
#line 1973 "parser.c"
    break;

  case 46:
#line 223 "parser.y"
                    {printf("Lvalue: member\n");}
#line 1979 "parser.c"
    break;

  case 47:
#line 226 "parser.y"
                                  {printf("Member: lvalue.identifier\n");}
#line 1985 "parser.c"
    break;

  case 48:
#line 227 "parser.y"
                                                    {printf("Member: lvalue[identifier]\n");}
#line 1991 "parser.c"
    break;

  case 49:
#line 228 "parser.y"
                                 {printf("Member: call.identifier\n");}
#line 1997 "parser.c"
    break;

  case 50:
#line 229 "parser.y"
                                                  {printf("Member: call[identifier]\n");}
#line 2003 "parser.c"
    break;

  case 51:
#line 232 "parser.y"
                 {call_flag = 1;}
#line 2009 "parser.c"
    break;

  case 52:
#line 232 "parser.y"
                                                          {call_flag = 0; printf("Call: call(elist)\n");}
#line 2015 "parser.c"
    break;

  case 53:
#line 233 "parser.y"
                                { printf("Call: lvalue callsuffix\n");}
#line 2021 "parser.c"
    break;

  case 54:
#line 234 "parser.y"
                                        {call_flag = 1;}
#line 2027 "parser.c"
    break;

  case 55:
#line 234 "parser.y"
                                                                                  {call_flag = 0; printf("Call: (funcdef)(elist)\n");}
#line 2033 "parser.c"
    break;

  case 56:
#line 237 "parser.y"
                     {printf("Callsuffix: normcall\n");}
#line 2039 "parser.c"
    break;

  case 57:
#line 238 "parser.y"
                        {printf("Callsuffix: method\n");}
#line 2045 "parser.c"
    break;

  case 58:
#line 241 "parser.y"
                     {call_flag = 1;}
#line 2051 "parser.c"
    break;

  case 59:
#line 241 "parser.y"
                                                      {call_flag = 0; printf("Normcall: (elist)\n");}
#line 2057 "parser.c"
    break;

  case 60:
#line 244 "parser.y"
                                        {call_flag = 1;}
#line 2063 "parser.c"
    break;

  case 61:
#line 244 "parser.y"
                                                                         {call_flag = 0; printf("Methodcall: ..identifier(elist)\n");}
#line 2069 "parser.c"
    break;

  case 62:
#line 247 "parser.y"
                 {printf("Elist: expr\n");}
#line 2075 "parser.c"
    break;

  case 63:
#line 248 "parser.y"
                               {printf("Elist: expr,...,expr\n");}
#line 2081 "parser.c"
    break;

  case 65:
#line 252 "parser.y"
                                              {printf("Objectdef: (elist)\n");}
#line 2087 "parser.c"
    break;

  case 66:
#line 253 "parser.y"
                                                {printf("Objectdef: (indexed)\n");}
#line 2093 "parser.c"
    break;

  case 67:
#line 256 "parser.y"
                        {printf("Indexed: indexedelem\n");}
#line 2099 "parser.c"
    break;

  case 68:
#line 257 "parser.y"
                                        {printf("Indexed: indexedelem,...,indexedelem\n");}
#line 2105 "parser.c"
    break;

  case 69:
#line 260 "parser.y"
                                                    {printf("Indexedelem: [expr:expr]\n");}
#line 2111 "parser.c"
    break;

  case 70:
#line 263 "parser.y"
                          {printf("Func_stmt: stmt,...,stmt\n");}
#line 2117 "parser.c"
    break;

  case 71:
#line 264 "parser.y"
                   {printf("Func_stmt: stmt\n");}
#line 2123 "parser.c"
    break;

  case 72:
#line 267 "parser.y"
                       {
                    block = block + scope_flag;
                    scope = scope + scope_flag;
                }
#line 2132 "parser.c"
    break;

  case 73:
#line 270 "parser.y"
                              {
                    scope = scope - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(scope+1);
                    }
                    {printf("Block: {}\n");}
                }
#line 2144 "parser.c"
    break;

  case 74:
#line 277 "parser.y"
                        {
                    block = block + scope_flag;
                    scope = scope + scope_flag;
                }
#line 2153 "parser.c"
    break;

  case 75:
#line 280 "parser.y"
                                        {
                    scope = scope - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(scope+1);
                    }
                }
#line 2164 "parser.c"
    break;

  case 76:
#line 286 "parser.y"
                {printf("Block: {func_stmt}\n");}
#line 2170 "parser.c"
    break;

  case 77:
#line 288 "parser.y"
                              {
                    sprintf(str, "%s%d%c","_f",func_counter+1,'\0');
                    if (SymTable_general_lookup(strdup(str), scope, 3, block, "funcdef")) {
                        functions++;
                        func_counter++;
                        SymTable_insert(strdup(str), scope, total_lines, 3, block);
                        scope++; 
                        scope_flag = 0; 
                        prev_block = block;
                        block++;
                        SymTable_hide(scope-1);
                    }
                    else {
                        fprintf(stderr,"\nERROR: Function (%s) in scope %d line %d cannot be defined\n",strdup(str),scope,total_lines);
                        yyerror("");
                    }
                }
#line 2192 "parser.c"
    break;

  case 78:
#line 305 "parser.y"
                                       {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 

                    scope--;
                    SymTable_hide(scope+1);
                    SymTable_reveal(scope);
                    printf("Funcdef: function (idlist) {}\n");
                }
#line 2207 "parser.c"
    break;

  case 79:
#line 316 "parser.y"
                           {
                }
#line 2214 "parser.c"
    break;

  case 80:
#line 318 "parser.y"
                         {
                    if (SymTable_general_lookup((yyvsp[-2].strVal), scope, 3, block, "funcdef")) {
                        SymTable_insert((yyvsp[-2].strVal), scope, total_lines, 3, block);
                        functions++;
                        scope++; 
                        scope_flag = 0;
                        prev_block = block;
                        block++;
                        SymTable_hide(scope-1);
                    }
                    else {
                        fprintf(stderr,"\nERROR: Function (%s) in scope %d line %d cannot be defined\n",(yyvsp[-2].strVal),scope,total_lines);
                        yyerror("");
                    }
                }
#line 2234 "parser.c"
    break;

  case 81:
#line 333 "parser.y"
                                       {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 
                    scope--;
                    SymTable_hide(scope+1);
                    SymTable_reveal(scope);
                    printf("Funcdef: function identifier(idlist) {}\n");
                }
#line 2248 "parser.c"
    break;

  case 82:
#line 344 "parser.y"
                    {printf("Const: integer\n");}
#line 2254 "parser.c"
    break;

  case 83:
#line 345 "parser.y"
                   {printf("Const: real\n");}
#line 2260 "parser.c"
    break;

  case 84:
#line 346 "parser.y"
                     {printf("Const: string\n");}
#line 2266 "parser.c"
    break;

  case 85:
#line 347 "parser.y"
                  {printf("Const: nil\n");}
#line 2272 "parser.c"
    break;

  case 86:
#line 348 "parser.y"
                   {printf("Const: true\n");}
#line 2278 "parser.c"
    break;

  case 87:
#line 349 "parser.y"
                    {printf("Const: false\n");}
#line 2284 "parser.c"
    break;

  case 88:
#line 352 "parser.y"
                        {
                {printf("Idlist: identifier\n");}
                if (SymTable_general_lookup((yyvsp[0].strVal), scope, 2, block, "formal")) {
                    SymTable_insert ((yyvsp[0].strVal), scope, total_lines, 2, block);
                }
                else {
                    fprintf(stderr,"ERROR: Parameter (%s) in scope %d line %d cannot be defined\n",(yyvsp[0].strVal),scope,total_lines);
                }
            }
#line 2298 "parser.c"
    break;

  case 89:
#line 361 "parser.y"
                                      {
                {printf("Idlist: identifier,...,identifier\n");}
                if (SymTable_general_lookup((yyvsp[-2].strVal), scope, 2, block, "formal")) {
                    SymTable_insert ((yyvsp[-2].strVal), scope, total_lines, 2, block);
                }
                else {
                    fprintf(stderr,"ERROR: Parameter (%s) in scope %d line %d cannot be defined\n",(yyvsp[-2].strVal),scope,total_lines);
                }
            }
#line 2312 "parser.c"
    break;

  case 91:
#line 373 "parser.y"
                                            {printf("Ifstmt: if (expr) stmt\n");}
#line 2318 "parser.c"
    break;

  case 92:
#line 374 "parser.y"
                                                       {printf("Ifstmt: if (expr) stmt else stmt\n");}
#line 2324 "parser.c"
    break;

  case 93:
#line 377 "parser.y"
                                          {
                loop_scope++;
            }
#line 2332 "parser.c"
    break;

  case 94:
#line 380 "parser.y"
                 {
                loop_scope--;
                printf("Whilestmt: while (expr) stmt\n");
            }
#line 2341 "parser.c"
    break;

  case 95:
#line 386 "parser.y"
                                                                        {
                loop_scope++;
            }
#line 2349 "parser.c"
    break;

  case 96:
#line 389 "parser.y"
                 {
                loop_scope--;
                printf("Forstmt: for (elist;expr;elist) stmt\n");
            }
#line 2358 "parser.c"
    break;

  case 97:
#line 395 "parser.y"
                             {
                if (scope_flag == 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "ERROR: Keyword \"return\" in line %d can't be used without a function.\n",total_lines);
                }
            }
#line 2371 "parser.c"
    break;

  case 98:
#line 403 "parser.y"
                                   {
                if (scope_flag == 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "ERROR: Keyword \"return\" in line %d can't be used without a function.\n",total_lines);
                }
            }
#line 2384 "parser.c"
    break;


#line 2388 "parser.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 414 "parser.y"


const char * getName(symt * input){
    if(input->type == 4 || 5){
        return input->value.funcVal->fname;
    }else{
        return input->value.varVal->vname;
    }
}

unsigned int getScope(symt * input){
    if(input->type == 4 || 5){
        return input->value.funcVal->fscope;
    }else{
        return input->value.varVal->vscope;
    }
}

unsigned int getLine(symt * input){
    if(input->type == 4 || 5){
        return input->value.funcVal->fline;
    }else{
        return input->value.varVal->vline;
    }
}

char *getType(types type) {
    if (type == 0) {
        return "global variable";
    }
    if (type == 1) {
        return "local variable";
    }
    if (type == 2) {
        return "formal argument";
    }
    if (type == 3) {
        return "user function";
    }
    return "library function";
}

void resize_pinaka(unsigned int scope) {
    scope_link *temp;
    int i;
    temp = lista;

    while ((temp->scope_counter < scope) && (temp->next != NULL)) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        for (i = temp->scope_counter; i < scope; i++) {
            scope_link *new_node = malloc(sizeof(scope_link));
            new_node->scope_counter = i+1;
            new_node->scope_head = NULL;
            new_node->next = NULL;
            temp->next = new_node;
            temp = temp->next;
        } 
    }
}

void SymTable_hide(unsigned int scope) {
    scope_link *scope_temp;
    symt *entry_temp;

    scope_temp = lista;
    while (scope_temp != NULL) {
        if (scope_temp->scope_counter == scope) {
            entry_temp = scope_temp->scope_head;
            while (entry_temp != NULL) {
                entry_temp->isActive = 0;
                entry_temp = entry_temp->next_in_scope;
            }
        }
        scope_temp = scope_temp->next;
    }
}

void SymTable_reveal(unsigned int scope) {
    scope_link *scope_temp;
    symt *entry_temp;

    scope_temp = lista;
    while (scope_temp != NULL) {
        if (scope_temp->scope_counter == scope) {
            entry_temp = scope_temp->scope_head;
            while (entry_temp != NULL) {
                entry_temp->isActive = 1;
                entry_temp = entry_temp->next_in_scope;
            }
        }
        scope_temp = scope_temp->next;
    }
}

int SymTable_insert(const char *name, unsigned int scope, unsigned int line, types type, unsigned int block) {
    symt *new_node, *temp;
    scope_link *temp2;
    unsigned int index = SymTable_hash(name) % 499;
    int i;

    new_node = malloc(sizeof(symt));
    if (lera->head[index] != NULL) {
        temp = lera->head[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    else {
        lera->head[index] = new_node;
    }
    new_node->next = NULL;
    new_node->next_in_scope = NULL;
    new_node->isActive = 1;
    new_node->type = type;
    new_node->block = block;
    if (type < 3) {
        new_node->value.varVal = malloc(sizeof(var));
        new_node->value.varVal->vname = name;
        new_node->value.varVal->vscope = scope;
        new_node->value.varVal->vline = line;
    }
    else {
        new_node->value.funcVal = malloc(sizeof(func));
        new_node->value.funcVal->fname = name;
        new_node->value.funcVal->fscope = scope;
        new_node->value.funcVal->fline = line;
    }
    resize_pinaka(scope);
    temp2 = lista;
    while (temp2->scope_counter != scope) {
        temp2 = temp2 -> next;
    }
    if (temp2->scope_head == NULL) {
        temp2->scope_head = new_node;
    }
    else {
        temp = temp2->scope_head;
        while (temp->next_in_scope != NULL) {
            temp = temp->next_in_scope;
        }
        temp->next_in_scope = new_node;
    }
}

int SymTable_type_lookup(const char *name, unsigned int scope) {
    symt *temp = NULL;
    unsigned int index = SymTable_hash(name) % 499;
    temp = lera->head[index];
    while (temp != NULL) {
        if (strcmp(getName(temp),name) == 0) {
            if (temp->isActive) {
                if (temp->type < 3) {
                    return 1;
                }
                return 0;
            }
        }
        temp = temp->next;
    }
    return 1;
}

int SymTable_smol_lookup(const char *name, unsigned int scope) {
    symt *tmp = NULL;
    unsigned int index = SymTable_hash(name) % 499;
    tmp = lera->head[index];

    while (tmp != NULL) {
        if (getScope(tmp) == scope) {
            if (strcmp(getName(tmp), name) == 0) {
                if (scope == 0) {
                    return 0;
                }
                else {
                    return -1;
                }
            }
        }
                        if (strcmp("f",getName(tmp))==0) {
                    //printf("\n\n\t\t\t\t\tf active: %d\tscope: %u\n",tmp->isActive, getScope(tmp));
                }
        tmp = tmp -> next;
    }
    return 1;
}

int SymTable_smoller_lookup(const char *name, unsigned int scope, unsigned int block) {
    symt *tmp = NULL;
    unsigned int index = SymTable_hash(name) % 499;
    tmp = lera->head[index];

    while(tmp != NULL) {
        if (strcmp(getName(tmp), name) == 0) {
            if (tmp->isActive) {
                return 2;
            }
        }
        if (strcmp("InitCircle",getName(tmp))==0) {
            //printf("\n\n\t\t\t\t\tInitCircle active: %d\n",tmp->isActive);
        }
        tmp = tmp -> next;
    }
    return 1;
}
int SymTable_general_lookup(const char * name, unsigned int scope, types type, unsigned int block, char *search_mode) {
    if (isLibraryFunc(name) && (strcmp("global_src",search_mode))) {
        return 0;
    }

    symt * tmp = NULL;
    int flag = 1;

    unsigned int index = SymTable_hash(name) % 499;
    tmp = lera->head[index];
    
    if (strcmp(search_mode,"funcdef") == 0) {
        while (tmp != NULL) {
            if (strcmp(getName(tmp),name) == 0) {
                if (tmp->isActive) {
                    return 0;
                }
            }
            tmp = tmp -> next;
        }
        return 1;
    }
    else if (strcmp(search_mode, "formal") == 0) {
        
        while (tmp != NULL) {
            if (strcmp(getName(tmp),name) == 0) {
                if (tmp->isActive) {
                    return 0;
                }
            }
            tmp = tmp -> next;
        }
        return 1;
    }
    else if (strcmp(search_mode, "local") == 0) {
        while (tmp != NULL) {
            if (strcmp(getName(tmp),name) == 0) {
                if (strcmp("a1",getName(tmp))==0) {
                }
                if ((getScope(tmp) == scope) && tmp->isActive) {
                    return 2;
                }
            }
            tmp = tmp -> next;
        }
        return 1;
    }
    else if (strcmp(search_mode, "global_src") == 0) {
        if (isLibraryFunc(name)) {return 2;}
        while (tmp != NULL) {
            if (strcmp(getName(tmp),name) == 0) {
                return 2;
            }
            tmp = tmp -> next;
        }
        return 0;
    }
    else if (strcmp(search_mode, "new_var") == 0) {
        int current_scope;
        int mafaka = SymTable_smoller_lookup(name, scope, block);
        if (mafaka == 2) {  //2: found same variable in same block & scope
            return 2;
        }
        if (scope > 0) {
            for (current_scope = scope-1; current_scope >= 0; current_scope--) {
                flag = SymTable_smol_lookup(name, current_scope);
                if (flag == -1) {
                    return -1;   //0: found same var in parent scope
                }
            }
            return flag;
        }
        return mafaka;  //found nothing
    }
    return -1;
}

unsigned int SymTable_hash(const char *key) {
    size_t i;
    unsigned int hash = 0U;
    for (i = 0U; key[i] != '\0'; key++) {
        hash = hash * HASH_MULTIPLIER + key[i];
    }
    return hash;
}

void SymTable_new() {
    lera = malloc(sizeof(SymTable));
    int i;
    for (i=0; i<SIZE; i++) {
        lera->head[i] = NULL;
    }
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

    SymTable_insert("print", 0, 0, 4, 0);
    SymTable_insert("input", 0, 0, 4, 0);
    SymTable_insert("objectmemberkeys", 0, 0, 4, 0);
    SymTable_insert("objecttotalmembers", 0, 0, 4, 0);
    SymTable_insert("objectcopy", 0, 0, 4, 0);
    SymTable_insert("totalarguments", 0, 0, 4, 0);
    SymTable_insert("argument", 0, 0, 4, 0);
    SymTable_insert("typeof", 0, 0, 4, 0);
    SymTable_insert("strtonum", 0, 0, 4, 0);
    SymTable_insert("sqrt", 0, 0, 4, 0);
    SymTable_insert("cos", 0, 0, 4, 0);
    SymTable_insert("sin", 0, 0, 4, 0);
}

bool isLibraryFunc(const char * funct){
    if( !strcmp(funct,"print") ||
    !strcmp(funct,"input") ||
    !strcmp(funct,"objectmemberkeys") ||
    !strcmp(funct,"objecttotalmembers") ||
    !strcmp(funct,"objectcopy") ||
    !strcmp(funct,"totalarguments") ||
    !strcmp(funct,"argument") ||
    !strcmp(funct,"typeof") ||
    !strcmp(funct,"strtonum") ||
    !strcmp(funct,"sqrt") ||
    !strcmp(funct,"cos") ||
    !strcmp(funct,"sin") )
  {
    return true;
  }else{
    return false;
  }
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
    fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, total_lines, yytext);
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
