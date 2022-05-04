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
    #include "quads.h" 
    #include <stdlib.h>

    int yyerror (char* yaccProvidedMessage);
    int yylex(void);
    int lvalue_checker(const char *name, unsigned int scope);

    extern int total_lines;
    extern char* yytext;
    extern FILE* yyin;

    char *str;
    char *ourVar;

    unsigned int scope = 0;
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
#line 29 "parser.y"
int intVal; double realVal; char *strVal;

#line 248 "parser.c"

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
#define YYLAST   560

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

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
       0,    56,    56,    57,    60,    61,    62,    63,    64,    65,
      73,    81,    82,    83,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   103,
     104,   105,   106,   114,   122,   130,   138,   141,   174,   175,
     176,   177,   178,   181,   237,   251,   263,   266,   267,   268,
     269,   272,   272,   273,   273,   274,   274,   277,   278,   281,
     281,   284,   284,   287,   288,   289,   292,   293,   296,   297,
     300,   303,   304,   307,   307,   316,   318,   316,   326,   326,
     353,   355,   352,   381,   382,   383,   384,   385,   386,   389,
     400,   411,   414,   415,   418,   418,   427,   427,   436,   444
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
  "$@1", "$@2", "$@3", "callsuffix", "normcall", "$@4", "methodcall",
  "$@5", "elist", "objectdef", "indexed", "indexedelem", "func_stmt",
  "block", "$@6", "$@7", "$@8", "funcdef", "$@9", "$@10", "$@11", "const",
  "idlist", "ifstmt", "whilestmt", "$@12", "forstmt", "$@13", "returnstmt", YY_NULLPTR
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

#define YYPACT_NINF (-149)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     149,  -149,  -149,  -149,  -149,   -39,    -3,     0,     9,     1,
      15,    16,   215,    53,  -149,  -149,  -149,   215,     5,     5,
      23,    81,   192,  -149,    70,    79,   149,   282,  -149,  -149,
    -149,   395,  -149,   -22,  -149,  -149,  -149,  -149,  -149,  -149,
    -149,  -149,   215,   215,   215,  -149,  -149,  -149,   303,  -149,
    -149,  -149,  -149,    27,    72,    42,    -8,    42,    54,   149,
     215,   261,    51,    55,    49,   345,    52,  -149,  -149,  -149,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,  -149,   215,  -149,  -149,   215,    92,   -11,
     215,    98,    66,   366,   387,    67,    68,   104,  -149,    73,
    -149,   149,    76,   239,   215,  -149,  -149,    80,  -149,    75,
     512,   499,    27,    27,  -149,  -149,  -149,   525,   525,   217,
     217,   217,   217,   484,   421,  -149,  -149,  -149,  -149,  -149,
    -149,   442,  -149,   215,   149,  -149,   215,  -149,    77,    82,
    -149,  -149,  -149,   215,  -149,  -149,    88,  -149,   215,   116,
    -149,    90,   121,   149,   324,   104,   104,    96,  -149,   463,
     215,    94,    93,  -149,   149,  -149,   215,    97,  -149,  -149,
    -149,    99,  -149,   215,  -149,   100,    96,  -149,   101,  -149,
    -149,  -149,   149,  -149
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    83,    84,    85,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,    88,    86,     0,     0,     0,
      75,    65,     0,    13,     0,     0,     3,     0,    28,    14,
      36,    38,    46,    39,    40,    11,    12,    42,     5,     6,
       7,     8,     0,     0,    65,    80,    78,    98,     0,     9,
      10,    31,    44,    30,     0,    32,    51,    34,     0,     0,
       0,    63,     0,     0,    68,     0,     0,    45,     1,     2,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,    33,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,    99,     0,
      74,    72,     0,     0,    65,    66,    67,     0,    29,    41,
      26,    27,    15,    16,    17,    18,    19,    24,    25,    20,
      22,    21,    23,    37,     0,    47,    59,    61,    54,    57,
      58,     0,    49,    65,     0,    94,     0,    81,    89,     0,
      55,    71,    76,     0,    64,    69,     0,    48,    65,     0,
      50,     0,    92,     0,     0,    91,    91,     0,    77,     0,
      65,     0,     0,    52,     0,    95,    65,     0,    90,    79,
      70,     0,    60,    65,    93,     0,     0,    56,     0,    96,
      82,    62,     0,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -149,   111,   -57,    -9,  -149,  -149,  -149,     8,  -149,    29,
    -149,  -149,  -149,  -149,  -149,  -149,  -149,  -149,   -30,  -149,
      37,  -149,    44,  -148,  -149,  -149,  -149,   -12,  -149,  -149,
    -149,  -149,  -100,  -149,  -149,  -149,  -149,  -149,  -149
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      92,    89,   146,   128,   129,   148,   130,   149,    62,    34,
      63,    64,   102,    35,    58,    59,   158,    36,    97,    96,
     155,    37,   139,    38,    39,   153,    40,   182,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    42,   101,    51,     1,     2,     3,     4,    53,   169,
      66,     4,    61,    65,    95,    45,    90,    12,   -51,    13,
      14,    15,    16,    13,    91,    17,    55,    57,   180,   126,
      90,    18,    19,    93,    94,    61,   127,    43,    91,    21,
      44,    22,    99,    47,   101,    54,    24,    56,    56,    46,
      24,   103,    74,    75,    76,   167,   168,    49,    50,    52,
     -73,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   144,   123,    67,   152,   124,    68,
      87,   131,   -53,     8,     1,     2,     3,     4,    88,   -53,
     105,   100,   107,   109,   106,    61,   165,    12,   125,    13,
      14,    15,    16,   151,   132,    17,   133,   174,   137,   136,
     138,    18,    19,   142,   140,   -55,    60,    60,   161,    21,
     156,    22,   162,   157,    61,   183,    24,   154,   160,   164,
     171,   163,    20,   173,   159,   172,   175,    69,   176,    61,
     177,   179,   181,   178,   145,   141,     0,     0,     0,     0,
       0,    61,     1,     2,     3,     4,     5,    61,     6,     7,
       8,     9,    10,    11,    61,    12,     0,    13,    14,    15,
      16,     0,     0,    17,     0,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,    20,     0,    21,     0,    22,
       0,    23,     0,     0,    24,     1,     2,     3,     4,     0,
       0,     0,     0,     8,     0,     0,     0,     0,    12,     0,
      13,    14,    15,    16,     0,     0,    17,     0,     1,     2,
       3,     4,    18,    19,     0,     0,     0,     0,     0,     0,
      21,    12,    22,    13,    14,    15,    16,    24,     0,    17,
      72,    73,    74,    75,    76,    18,    19,     0,     0,   -74,
     -74,   -74,   -74,    21,    70,    22,    71,     0,     0,     0,
      24,     0,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    80,    81,    82,     0,    70,     0,    71,     0,
       0,     0,     0,   143,    72,    73,    74,    75,    76,    77,
      78,     0,     0,    79,    80,    81,    82,    70,     0,    71,
       0,     0,     0,     0,   104,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,    81,    82,    70,     0,
      71,     0,     0,     0,    83,     0,    72,    73,    74,    75,
      76,    77,    78,     0,     0,    79,    80,    81,    82,    70,
       0,    71,     0,     0,     0,    98,     0,    72,    73,    74,
      75,    76,    77,    78,     0,     0,    79,    80,    81,    82,
      70,     0,    71,     0,     0,     0,   166,     0,    72,    73,
      74,    75,    76,    77,    78,     0,     0,    79,    80,    81,
      82,    70,     0,    71,     0,     0,   108,     0,     0,    72,
      73,    74,    75,    76,    77,    78,     0,     0,    79,    80,
      81,    82,    70,     0,    71,     0,     0,   134,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    84,     0,    79,
      80,    81,    82,     0,     0,    85,    86,     0,   135,     0,
       0,     0,     0,    87,     0,   -53,    70,     0,    71,     0,
       0,    88,   -53,     0,    72,    73,    74,    75,    76,    77,
      78,     0,     0,    79,    80,    81,    82,    70,     0,    71,
     147,     0,     0,     0,     0,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,    81,    82,    70,     0,
      71,   150,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,    78,     0,     0,    79,    80,    81,    82,    70,
     170,    71,     0,     0,     0,     0,     0,    72,    73,    74,
      75,    76,    77,    78,    70,     0,    79,    80,    81,    82,
       0,     0,    72,    73,    74,    75,    76,    77,    78,     0,
       0,    79,    80,    81,    82,    72,    73,    74,    75,    76,
      77,    78,     0,     0,    79,    80,    81,    82,    72,    73,
      74,    75,    76,   -74,   -74,     0,     0,    79,    80,    81,
      82
};

static const yytype_int16 yycheck[] =
{
       9,    40,    59,    12,     3,     4,     5,     6,    17,   157,
      22,     6,    21,    22,    44,     6,    38,    16,    40,    18,
      19,    20,    21,    18,    46,    24,    18,    19,   176,    40,
      38,    30,    31,    42,    43,    44,    47,    40,    46,    38,
      40,    40,    54,    42,   101,    40,    45,    18,    19,    40,
      45,    60,    25,    26,    27,   155,   156,    42,    42,     6,
      37,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   104,    84,     6,   134,    87,     0,
      38,    90,    40,    11,     3,     4,     5,     6,    46,    47,
      39,    37,    43,    41,    39,   104,   153,    16,     6,    18,
      19,    20,    21,   133,     6,    24,    40,   164,    40,    42,
       6,    30,    31,    37,    41,    40,    36,    36,   148,    38,
      43,    40,     6,    41,   133,   182,    45,   136,    40,     8,
     160,    41,    36,    40,   143,    41,   166,    26,    41,   148,
      41,    41,    41,   173,   107,   101,    -1,    -1,    -1,    -1,
      -1,   160,     3,     4,     5,     6,     7,   166,     9,    10,
      11,    12,    13,    14,   173,    16,    -1,    18,    19,    20,
      21,    -1,    -1,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    40,
      -1,    42,    -1,    -1,    45,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,
      18,    19,    20,    21,    -1,    -1,    24,    -1,     3,     4,
       5,     6,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    16,    40,    18,    19,    20,    21,    45,    -1,    24,
      23,    24,    25,    26,    27,    30,    31,    -1,    -1,    32,
      33,    34,    35,    38,    15,    40,    17,    -1,    -1,    -1,
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
      15,    -1,    17,    -1,    -1,    -1,    42,    -1,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    32,    33,    34,
      35,    15,    -1,    17,    -1,    -1,    41,    -1,    -1,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    32,    33,
      34,    35,    15,    -1,    17,    -1,    -1,    41,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    22,    -1,    32,
      33,    34,    35,    -1,    -1,    30,    31,    -1,    41,    -1,
      -1,    -1,    -1,    38,    -1,    40,    15,    -1,    17,    -1,
      -1,    46,    47,    -1,    23,    24,    25,    26,    27,    28,
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
      55,    56,    57,    58,    68,    72,    76,    80,    82,    83,
      85,    87,    40,    40,    40,     6,    40,    42,    52,    42,
      42,    52,     6,    52,    40,    56,    58,    56,    73,    74,
      36,    52,    67,    69,    70,    52,    76,     6,     0,    50,
      15,    17,    23,    24,    25,    26,    27,    28,    29,    32,
      33,    34,    35,    42,    22,    30,    31,    38,    46,    60,
      38,    46,    59,    52,    52,    67,    78,    77,    42,    76,
      37,    51,    71,    52,    43,    39,    39,    43,    41,    41,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,     6,    40,    47,    62,    63,
      65,    52,     6,    40,    41,    41,    42,    40,     6,    81,
      41,    71,    37,    44,    67,    69,    61,    39,    64,    66,
      39,    67,    51,    84,    52,    79,    43,    41,    75,    52,
      40,    67,     6,    41,     8,    51,    42,    81,    81,    72,
      37,    67,    41,    40,    51,    67,    41,    41,    67,    41,
      72,    41,    86,    51
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
      70,    71,    71,    73,    72,    74,    75,    72,    77,    76,
      78,    79,    76,    80,    80,    80,    80,    80,    80,    81,
      81,    81,    82,    82,    84,    83,    86,    85,    87,    87
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
       5,     2,     1,     0,     3,     0,     0,     5,     0,     6,
       0,     0,     8,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     5,     7,     0,     6,     0,    10,     2,     3
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
#line 57 "parser.y"
                {printf("\nProgram stopped\n\n");}
#line 1630 "parser.c"
    break;

  case 4:
#line 60 "parser.y"
                            {printf("Stmt: expr;\n");}
#line 1636 "parser.c"
    break;

  case 5:
#line 61 "parser.y"
                        {printf("\tif statement\n");}
#line 1642 "parser.c"
    break;

  case 6:
#line 62 "parser.y"
                        {printf("\twhile statement\n");}
#line 1648 "parser.c"
    break;

  case 7:
#line 63 "parser.y"
                        {printf("\tfor statement\n");}
#line 1654 "parser.c"
    break;

  case 8:
#line 64 "parser.y"
                        {printf("\treturn statement\n");}
#line 1660 "parser.c"
    break;

  case 9:
#line 65 "parser.y"
                                {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"break\" can't be used without a loop.\n\033[0m", total_lines);
                }
                else {
                    printf("\tkeyword \"break\"\n");
                }
            }
#line 1673 "parser.c"
    break;

  case 10:
#line 73 "parser.y"
                                {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"continue\" can't be used without a loop.\n\033[0m", total_lines);
                }
                else {
                    printf("\tkeyword \"continue\"\n");
                }
            }
#line 1686 "parser.c"
    break;

  case 11:
#line 81 "parser.y"
                        {printf("\tBlock\n");}
#line 1692 "parser.c"
    break;

  case 12:
#line 82 "parser.y"
                        {printf("\tFunction definition\n");}
#line 1698 "parser.c"
    break;

  case 14:
#line 86 "parser.y"
                            {printf("Assign expression\n");}
#line 1704 "parser.c"
    break;

  case 15:
#line 87 "parser.y"
                                {printf("Expr: expr op_plus expr\n");}
#line 1710 "parser.c"
    break;

  case 16:
#line 88 "parser.y"
                                {printf("Expr: expr op_minus expr\n");}
#line 1716 "parser.c"
    break;

  case 17:
#line 89 "parser.y"
                                    {printf("Expr: expr op_asterisk expr\n");}
#line 1722 "parser.c"
    break;

  case 18:
#line 90 "parser.y"
                                {printf("Expr: expr op_slash expr\n");}
#line 1728 "parser.c"
    break;

  case 19:
#line 91 "parser.y"
                                     {printf("Expr: expr op_percentage expr\n");}
#line 1734 "parser.c"
    break;

  case 20:
#line 92 "parser.y"
                                  {printf("Expr: expr op_greater expr\n");}
#line 1740 "parser.c"
    break;

  case 21:
#line 93 "parser.y"
                                     {printf("Expr: expr op_greater_eq expr\n");}
#line 1746 "parser.c"
    break;

  case 22:
#line 94 "parser.y"
                                 {printf("Expr: expr op_lesser expr\n");}
#line 1752 "parser.c"
    break;

  case 23:
#line 95 "parser.y"
                                    {printf("Expr: expr op_lesser_eq expr\n");}
#line 1758 "parser.c"
    break;

  case 24:
#line 96 "parser.y"
                                {printf("Expr: expr op_eq_eq expr\n");}
#line 1764 "parser.c"
    break;

  case 25:
#line 97 "parser.y"
                                 {printf("Expr: expr op_not_eq expr\n");}
#line 1770 "parser.c"
    break;

  case 26:
#line 98 "parser.y"
                           {printf("Expr: expr and expr\n");}
#line 1776 "parser.c"
    break;

  case 27:
#line 99 "parser.y"
                          {printf("Expr: expr or expr\n");}
#line 1782 "parser.c"
    break;

  case 28:
#line 100 "parser.y"
                    {printf("Term expression\n");}
#line 1788 "parser.c"
    break;

  case 29:
#line 103 "parser.y"
                                    {printf("Term: (expr)\n");}
#line 1794 "parser.c"
    break;

  case 30:
#line 104 "parser.y"
                            {printf("Term: -expr\n");}
#line 1800 "parser.c"
    break;

  case 31:
#line 105 "parser.y"
                      {printf("Term: not expr\n");}
#line 1806 "parser.c"
    break;

  case 32:
#line 106 "parser.y"
                                 {
                if (lvalue_checker(ourVar, scope)) {
                    printf("Term: ++lvalue\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",total_lines);
                }
            }
#line 1819 "parser.c"
    break;

  case 33:
#line 114 "parser.y"
                                 {
                if (lvalue_checker(ourVar, scope)) {
                    printf("Term: lvalue++\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",total_lines);
                }
            }
#line 1832 "parser.c"
    break;

  case 34:
#line 122 "parser.y"
                                   {
                if (lvalue_checker(ourVar, scope)) {
                    printf("Term: --lvalue\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",total_lines);
                }
            }
#line 1845 "parser.c"
    break;

  case 35:
#line 130 "parser.y"
                                   {                
                if (lvalue_checker(ourVar, scope)) {
                    printf("Term: lvalue--\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",total_lines);
                }
            }
#line 1858 "parser.c"
    break;

  case 36:
#line 138 "parser.y"
                     {printf("Term: primary\n");}
#line 1864 "parser.c"
    break;

  case 37:
#line 141 "parser.y"
                                  {
                if (!local_flag)  {
                    symt *tmp_symbol = NULL;
                    int found_flag = 0;
                    int tmp_scope = scope;
                    while (tmp_scope >= 0) { //psaxnw ta scopes apo mesa pros ta eksw
                        tmp_symbol = SymTable_lookup(ourVar, tmp_scope, "local");
                        if (tmp_symbol != NULL) {
                            if (tmp_symbol->type > 2) {
                                fprintf(stdout, "\033[0;31mError. Line %d: Attempting to use function  %s as lvalue\n\033[0m",total_lines, ourVar);
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
#line 1900 "parser.c"
    break;

  case 38:
#line 174 "parser.y"
                    {printf("Primary: lvalue\n");}
#line 1906 "parser.c"
    break;

  case 39:
#line 175 "parser.y"
                    {printf("Primary: call\n");}
#line 1912 "parser.c"
    break;

  case 40:
#line 176 "parser.y"
                       {printf("Primary: objectdef\n");}
#line 1918 "parser.c"
    break;

  case 41:
#line 177 "parser.y"
                                        {printf("Primary: (funcdef)\n");}
#line 1924 "parser.c"
    break;

  case 42:
#line 178 "parser.y"
                   {printf("Primary: const\n");}
#line 1930 "parser.c"
    break;

  case 43:
#line 181 "parser.y"
                       {   
                    ourVar = (char *)malloc(sizeof((yyvsp[0].strVal)));
                    strcpy(ourVar, (yyvsp[0].strVal));               
                    printf("Lvalue: identifier\n");
                    symt *tmp_symbol = NULL;
                    tmp_symbol = SymTable_lookup((yyvsp[0].strVal), scope, "local"); //psaxnw to diko mou scope
                    if (tmp_symbol == NULL) {
                        //an eimai se synarthsh
                        if (func_flag) {
                            int found_flag = 0;
                            int tmp_scope = scope-1;
                            while (tmp_scope >= 0) { //psaxnw parent scopes apo mesa pros ta eksw
                                tmp_symbol = SymTable_lookup((yyvsp[0].strVal), tmp_scope, "local");
                                if (tmp_symbol != NULL) {
                                    if (tmp_scope != 0) {
                                        if (tmp_symbol->type < 3) {
                                            fprintf(stdout, "\033[0;31mError. Line %d: Cannot access variable %s in this scope\n\033[0m",total_lines, (yyvsp[0].strVal));
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
                                SymTable_insert((yyvsp[0].strVal), scope, total_lines, 1);
                            }
                        }
                        else { //den eimai se synarthsh
                            tmp_symbol = SymTable_lookup((yyvsp[0].strVal), scope, "call_src"); //koitaw ola ta scopes
                            if (tmp_symbol != NULL) { //an vrw kati ola good
                                fprintf(stdout, "Calling symbol %s in parent scope.\n", (yyvsp[0].strVal));
                            }
                            else { //alliws kanw eisagwgh
                                if (scope == 0) {
                                    SymTable_insert((yyvsp[0].strVal), scope, total_lines, 0);
                                }
                                else {
                                    SymTable_insert((yyvsp[0].strVal), scope, total_lines, 1);
                                }
                            }
                        }

                    }
            }
#line 1990 "parser.c"
    break;

  case 44:
#line 237 "parser.y"
                              {
                local_flag = 1;
                ourVar = (char *)malloc(sizeof((yyvsp[-1].strVal)));
                strcpy(ourVar, (yyvsp[0].strVal)); 
                symt *tmp_symbol = NULL;
                printf("Lvalue: local identifier\n");
                if ((tmp_symbol = SymTable_lookup((yyvsp[0].strVal), scope, "local")) == NULL) {
                    SymTable_insert((yyvsp[0].strVal), scope, total_lines, 1);
                }
                else {

                    fprintf(stdout, "Symbol %s successfully found in this scope (%d), line %d.\n", (yyvsp[0].strVal), scope, getLine(tmp_symbol));
                }
            }
#line 2009 "parser.c"
    break;

  case 45:
#line 251 "parser.y"
                                {
                ourVar = (char *)malloc(sizeof((yyvsp[-1].strVal)));
                strcpy(ourVar, (yyvsp[0].strVal)); 
                symt *tmp_symbol = NULL;
                printf("Lvalue: ::identifier\n");
                if ((tmp_symbol = SymTable_lookup((yyvsp[0].strVal), scope, "global_src")) != NULL) {
                    fprintf(stdout, "Symbol %s successfully found in global scope, line %d.\n", (yyvsp[0].strVal), getLine(tmp_symbol));
                }
                else {
                    fprintf(stdout,"\033[0;31mERROR. Line %d: Symbol %s not global or undefined.\n\033[0m", total_lines, (yyvsp[0].strVal));
                }
            }
#line 2026 "parser.c"
    break;

  case 46:
#line 263 "parser.y"
                    {printf("Lvalue: member\n");}
#line 2032 "parser.c"
    break;

  case 47:
#line 266 "parser.y"
                                  {printf("Member: lvalue.identifier\n");}
#line 2038 "parser.c"
    break;

  case 48:
#line 267 "parser.y"
                                                    {printf("Member: lvalue[identifier]\n");}
#line 2044 "parser.c"
    break;

  case 49:
#line 268 "parser.y"
                                 {printf("Member: call.identifier\n");}
#line 2050 "parser.c"
    break;

  case 50:
#line 269 "parser.y"
                                                  {printf("Member: call[identifier]\n");}
#line 2056 "parser.c"
    break;

  case 51:
#line 272 "parser.y"
                 {call_flag = 1;}
#line 2062 "parser.c"
    break;

  case 52:
#line 272 "parser.y"
                                                          {call_flag = 0; printf("Call: call(elist)\n");}
#line 2068 "parser.c"
    break;

  case 53:
#line 273 "parser.y"
                     {call_flag=1;}
#line 2074 "parser.c"
    break;

  case 54:
#line 273 "parser.y"
                                              { printf("Call: lvalue callsuffix\n");}
#line 2080 "parser.c"
    break;

  case 55:
#line 274 "parser.y"
                                        {call_flag = 1;}
#line 2086 "parser.c"
    break;

  case 56:
#line 274 "parser.y"
                                                                                  {call_flag = 0; printf("Call: (funcdef)(elist)\n");}
#line 2092 "parser.c"
    break;

  case 57:
#line 277 "parser.y"
                     {printf("Callsuffix: normcall\n");}
#line 2098 "parser.c"
    break;

  case 58:
#line 278 "parser.y"
                        {printf("Callsuffix: method\n");}
#line 2104 "parser.c"
    break;

  case 59:
#line 281 "parser.y"
                     {call_flag = 1;}
#line 2110 "parser.c"
    break;

  case 60:
#line 281 "parser.y"
                                                      {call_flag = 0; printf("Normcall: (elist)\n");}
#line 2116 "parser.c"
    break;

  case 61:
#line 284 "parser.y"
                    {call_flag = 1;}
#line 2122 "parser.c"
    break;

  case 62:
#line 284 "parser.y"
                                                                          {call_flag = 0; printf("Methodcall: ..identifier(elist)\n");}
#line 2128 "parser.c"
    break;

  case 63:
#line 287 "parser.y"
                 {printf("Elist: expr\n");}
#line 2134 "parser.c"
    break;

  case 64:
#line 288 "parser.y"
                               {printf("Elist: expr,...,expr\n");}
#line 2140 "parser.c"
    break;

  case 66:
#line 292 "parser.y"
                                              {printf("Objectdef: (elist)\n");}
#line 2146 "parser.c"
    break;

  case 67:
#line 293 "parser.y"
                                                {printf("Objectdef: (indexed)\n");}
#line 2152 "parser.c"
    break;

  case 68:
#line 296 "parser.y"
                        {printf("Indexed: indexedelem\n");}
#line 2158 "parser.c"
    break;

  case 69:
#line 297 "parser.y"
                                        {printf("Indexed: indexedelem,...,indexedelem\n");}
#line 2164 "parser.c"
    break;

  case 70:
#line 300 "parser.y"
                                                    {printf("Indexedelem: [expr:expr]\n");}
#line 2170 "parser.c"
    break;

  case 71:
#line 303 "parser.y"
                          {printf("Func_stmt: stmt,...,stmt\n");}
#line 2176 "parser.c"
    break;

  case 72:
#line 304 "parser.y"
                   {printf("Func_stmt: stmt\n");}
#line 2182 "parser.c"
    break;

  case 73:
#line 307 "parser.y"
                       {
                    scope = scope + scope_flag;
                }
#line 2190 "parser.c"
    break;

  case 74:
#line 309 "parser.y"
                              {
                    scope = scope - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(scope+1);
                    }
                    {printf("Block: {}\n");}
                }
#line 2202 "parser.c"
    break;

  case 75:
#line 316 "parser.y"
                        {
                    scope = scope + scope_flag;
                }
#line 2210 "parser.c"
    break;

  case 76:
#line 318 "parser.y"
                                        {
                    scope = scope - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(scope+1);
                    }
                }
#line 2221 "parser.c"
    break;

  case 77:
#line 324 "parser.y"
                {printf("Block: {func_stmt}\n");}
#line 2227 "parser.c"
    break;

  case 78:
#line 326 "parser.y"
                              {
                    sprintf(str, "%s%d%c","_f",func_counter+1,'\0');
                    if (SymTable_lookup(strdup(str), scope, "funcdef") == NULL) {
                        func_flag++;
                        functions++;
                        func_counter++;
                        SymTable_insert(strdup(str), scope, total_lines, 3);
                        scope++; 
                        scope_flag = 0; //scope flag = 0 gia na mhn auksithei to scope sto block
                        //SymTable_hide(scope-1);
                    }
                    else {
                        fprintf(stderr,"\033[0;31mERROR. Line %d: Function (%s) in scope %d cannot be defined\n\033[0m",total_lines, strdup(str),scope);
                        yyerror("");
                    }
                }
#line 2248 "parser.c"
    break;

  case 79:
#line 342 "parser.y"
                                       {
                    if (!(--functions)){  //kanw to scope flag 1
                        scope_flag = 1; //vgainontas apo ta emfwleumena funcs
                    } 
                    func_flag--;
                    scope--;
                    SymTable_hide(scope+1);
                    SymTable_reveal(scope);
                    printf("Funcdef: function (idlist) {}\n");
                }
#line 2263 "parser.c"
    break;

  case 80:
#line 353 "parser.y"
                           {
                }
#line 2270 "parser.c"
    break;

  case 81:
#line 355 "parser.y"
                         {
                    if (SymTable_lookup((yyvsp[-2].strVal), scope, "funcdef") == NULL) {
                        SymTable_insert((yyvsp[-2].strVal), scope, total_lines, 3);
                        {func_flag++;}
                        functions++;
                        scope++; 
                        scope_flag = 0;
                        //SymTable_hide(scope-1);
                    }
                    else {
                        fprintf(stderr,"\033[0;31mERROR. Line %d: Function (%s) in scope %d cannot be defined\n\033[0m", total_lines, (yyvsp[-2].strVal), scope);
                        yyerror("");
                    }
                }
#line 2289 "parser.c"
    break;

  case 82:
#line 369 "parser.y"
                                       {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 
                    func_flag--;
                    scope--;
                    SymTable_hide(scope+1);
                    SymTable_reveal(scope);
                    printf("Funcdef: function identifier(idlist) {}\n");
                }
#line 2304 "parser.c"
    break;

  case 83:
#line 381 "parser.y"
                    {printf("Const: integer\n");}
#line 2310 "parser.c"
    break;

  case 84:
#line 382 "parser.y"
                   {printf("Const: real\n");}
#line 2316 "parser.c"
    break;

  case 85:
#line 383 "parser.y"
                     {printf("Const: string\n");}
#line 2322 "parser.c"
    break;

  case 86:
#line 384 "parser.y"
                  {printf("Const: nil\n");}
#line 2328 "parser.c"
    break;

  case 87:
#line 385 "parser.y"
                   {printf("Const: true\n");}
#line 2334 "parser.c"
    break;

  case 88:
#line 386 "parser.y"
                    {printf("Const: false\n");}
#line 2340 "parser.c"
    break;

  case 89:
#line 389 "parser.y"
                        {
                printf("Idlist: identifier\n");
                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup((yyvsp[0].strVal), scope, "formal");
                if (tmp_symbol != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Symbol %s in scope %d cannot be defined\n\033[0m", total_lines, (yyvsp[0].strVal),scope);
                }
                else {
                    SymTable_insert ((yyvsp[0].strVal), scope, total_lines, 2);
                }
            }
#line 2356 "parser.c"
    break;

  case 90:
#line 400 "parser.y"
                                      {
                printf("Idlist: identifier,...,identifier\n");
                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup((yyvsp[-2].strVal), scope, "formal");
                if (tmp_symbol != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Symbol %s in scope %d cannot be defined\n\033[0m", total_lines, (yyvsp[-2].strVal),scope);
                }
                else {
                    SymTable_insert ((yyvsp[-2].strVal), scope, total_lines, 2);
                }
            }
#line 2372 "parser.c"
    break;

  case 92:
#line 414 "parser.y"
                                            {printf("Ifstmt: if (expr) stmt\n");}
#line 2378 "parser.c"
    break;

  case 93:
#line 415 "parser.y"
                                                       {printf("Ifstmt: if (expr) stmt else stmt\n");}
#line 2384 "parser.c"
    break;

  case 94:
#line 418 "parser.y"
                                          {
                loop_scope++;
            }
#line 2392 "parser.c"
    break;

  case 95:
#line 421 "parser.y"
                 {
                loop_scope--;
                printf("Whilestmt: while (expr) stmt\n");
            }
#line 2401 "parser.c"
    break;

  case 96:
#line 427 "parser.y"
                                                                        {
                loop_scope++;
            }
#line 2409 "parser.c"
    break;

  case 97:
#line 430 "parser.y"
                 {
                loop_scope--;
                printf("Forstmt: for (elist;expr;elist) stmt\n");
            }
#line 2418 "parser.c"
    break;

  case 98:
#line 436 "parser.y"
                             {
                if (func_flag > 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",total_lines);
                }
            }
#line 2431 "parser.c"
    break;

  case 99:
#line 444 "parser.y"
                                   {
                if (func_flag > 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",total_lines);
                }
            }
#line 2444 "parser.c"
    break;


#line 2448 "parser.c"

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
#line 455 "parser.y"


int lvalue_checker(const char *name, unsigned int scope) {
    symt *tmp_symbol = NULL;
        int found_flag = 0;
        int tmp_scope = scope;
    if (!local_flag)  {
        while (tmp_scope >= 0) { //psaxnw ta scopes apo mesa pros ta eksw
            tmp_symbol = SymTable_lookup(ourVar, tmp_scope, "local");
            if (tmp_symbol != NULL) {
                if (tmp_symbol->type > 2) {
                    return 0;
                    //fprintf(stdout, "\033[0;31mError. Line %d: Attempting to use function  %s as lvalue\n\033[0m",total_lines, ourVar);
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
                //fprintf(stdout, "\033[0;31mError. Line %d: Attempting to use function  %s as lvalue\n\033[0m",total_lines, ourVar);
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

    SymTable_insert("print", 0, 0, 4);
    SymTable_insert("input", 0, 0, 4);
    SymTable_insert("objectmemberkeys", 0, 0, 4);
    SymTable_insert("objecttotalmembers", 0, 0, 4);
    SymTable_insert("objectcopy", 0, 0, 4);
    SymTable_insert("totalarguments", 0, 0, 4);
    SymTable_insert("argument", 0, 0, 4);
    SymTable_insert("typeof", 0, 0, 4);
    SymTable_insert("strtonum", 0, 0, 4);
    SymTable_insert("sqrt", 0, 0, 4);
    SymTable_insert("cos", 0, 0, 4);
    SymTable_insert("sin", 0, 0, 4);
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
