%{
    #include <stdio.h>
    int yyerror (char* yaccProvidedMessage);
    int yylex(void);

    extern int total_lines;
    extern char* yytext;
    extern FILE* yyin;
%}

%start program
%token ID INTEGER

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

expression:     INTEGER
                | ID
                | expression '+' expression
                | expression '-' expression
                | expression '*' expression
                | expression '/' expression
                | '(' expression ')'
                | '-' expression %prec UMINUS

expr:           expression '\n'

expressions:    expressions expr
                | expr
                ;

assignment:     ID '=' expression '\n'
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
    printf("ektelw pragmata");
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
