/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER = 258,                 /* INTEGER  */
    REAL = 259,                    /* REAL  */
    STRING = 260,                  /* STRING  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    IF = 262,                      /* IF  */
    ELSE = 263,                    /* ELSE  */
    WHILE = 264,                   /* WHILE  */
    FOR = 265,                     /* FOR  */
    FUNCTION = 266,                /* FUNCTION  */
    RETURN = 267,                  /* RETURN  */
    BREAK = 268,                   /* BREAK  */
    CONTINUE = 269,                /* CONTINUE  */
    AND = 270,                     /* AND  */
    NOT = 271,                     /* NOT  */
    OR = 272,                      /* OR  */
    LOCAL = 273,                   /* LOCAL  */
    TRUE = 274,                    /* TRUE  */
    FALSE = 275,                   /* FALSE  */
    NIL = 276,                     /* NIL  */
    OP_EQUALS = 277,               /* OP_EQUALS  */
    OP_PLUS = 278,                 /* OP_PLUS  */
    OP_MINUS = 279,                /* OP_MINUS  */
    OP_ASTERISK = 280,             /* OP_ASTERISK  */
    OP_SLASH = 281,                /* OP_SLASH  */
    OP_PERCENTAGE = 282,           /* OP_PERCENTAGE  */
    OP_EQ_EQ = 283,                /* OP_EQ_EQ  */
    OP_NOT_EQ = 284,               /* OP_NOT_EQ  */
    OP_PLUS_PLUS = 285,            /* OP_PLUS_PLUS  */
    OP_MINUS_MINUS = 286,          /* OP_MINUS_MINUS  */
    OP_GREATER = 287,              /* OP_GREATER  */
    OP_LESSER = 288,               /* OP_LESSER  */
    OP_GREATER_EQ = 289,           /* OP_GREATER_EQ  */
    OP_LESSER_EQ = 290,            /* OP_LESSER_EQ  */
    LEFT_BRACE = 291,              /* LEFT_BRACE  */
    RIGHT_BRACE = 292,             /* RIGHT_BRACE  */
    LEFT_BRACKET = 293,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 294,           /* RIGHT_BRACKET  */
    LEFT_PAR = 295,                /* LEFT_PAR  */
    RIGHT_PAR = 296,               /* RIGHT_PAR  */
    SEMICOLON = 297,               /* SEMICOLON  */
    COMMA = 298,                   /* COMMA  */
    COLON = 299,                   /* COLON  */
    COL_COL = 300,                 /* COL_COL  */
    DOT = 301,                     /* DOT  */
    DOT_DOT = 302,                 /* DOT_DOT  */
    LINE_COMM = 303                /* LINE_COMM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#line 27 "parser.y"
int intVal; double realVal; char *strVal;

#line 166 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
