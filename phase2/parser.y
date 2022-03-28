%{
    #include <stdio.h>
    int yyerror (char* yaccProvidedMessage);
    int yylex(void);

    extern int total_lines;
    extern char* yytext;
    extern FILE* yyin;
%}

%start program
%union {int intVal; double realVal; char *strVal;}

%token <intVal>     INTEGER
%token <realVal>    REAL
%token <strVal>     STRING
%token <strVal>     IDENTIFIER
%token <strVal>     IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOCAL TRUE FALSE NIL OP_EQUALS OP_PLUS OP_MINUS OP_ASTERISK OP_SLASH OP_PERCENTAGE OP_EQ_EQ OP_NOT_EQ OP_PLUS_PLUS OP_MINUS_MINUS OP_GREATER OP_LESSER OP_GREATER_EQ OP_LESSER_EQ LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET LEFT_PAR RIGHT_PAR SEMICOLON COMMA COLON COL_COL DOT DOT_DOT


%type <intVal>      expression

%right '='
%left ','
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS
%left '(' ')'


%%

program:        assignments expressions
                |
                ;

expression:     INTEGER                         { $$ = $1; }
                | IDENTIFIER                    { free($1);}
                | expression '+' expression     { $$ = $1 + $3;}
                | expression '-' expression     { $$ = $1 - $3;}
                | expression '*' expression     { $$ = $1 * $3;}
                | expression '/' expression     { $$ = $1 / $3;}
                | '(' expression ')'            { $$ = $2;}
                | '-' expression %prec UMINUS   { $$ = -$2;}

expr:           expression ';'                  {fprintf(stdout, "Result is: %d\n", $1);}

expressions:    expressions expr                {;}
                | expr                          {;}
                ;

assignment:     IDENTIFIER '=' expression ';' { ;}
                ;

assignments:    assignments assignment
                |
                ;

%%

int yyerror (char* yaccProvidedMessage) {
    fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, total_lines, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        printf("Reading from input file \"%s\"\n",argv[1]);
    }
    else {
        yyin = stdin;
    }
    yyparse();
    return 0;
}
