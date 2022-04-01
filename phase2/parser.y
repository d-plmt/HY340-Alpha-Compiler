%{
    #include <stdbool.h>
    #include <stdio.h>
    #include "symT.h" 

    int yyerror (char* yaccProvidedMessage);
    int yylex(void);

    extern int total_lines;
    extern char* yytext;
    extern FILE* yyin;

    Trapezi_Symvolwn *trapezaki;
    types type1;

    int scope = 0;
    int scope_flag = 1;
    int nested_func_flag = 0;
    int functions = 0;
%}

%start program
%union {int intVal; double realVal; char *strVal;}

%token <intVal>     INTEGER
%token <realVal>    REAL
%token <strVal>     STRING
%token <strVal>     IDENTIFIER
%token <strVal>     IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOCAL TRUE FALSE NIL OP_EQUALS OP_PLUS OP_MINUS OP_ASTERISK OP_SLASH OP_PERCENTAGE OP_EQ_EQ OP_NOT_EQ OP_PLUS_PLUS OP_MINUS_MINUS OP_GREATER OP_LESSER OP_GREATER_EQ OP_LESSER_EQ LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET LEFT_PAR RIGHT_PAR SEMICOLON COMMA COLON COL_COL DOT DOT_DOT


//%type stmt expr op term assignexpr primary lvalue member call callsuffix normcall methodcall elist objectdef indexed indexedelem block funcdef const idlist ifstmt whilestmt forstmt returnstmt

%type <strVal>	stmt
%type		expr
%type <strVal>	op term assignexpr
%type <strVal>	primary lvalue member
%type <strVal>	call callsuffix normcall methodcall
%type <strVal>	elist objectdef indexed indexedelem
%type <strVal>	block funcdef const idlist
%type <strVal>	ifstmt whilestmt forstmt returnstmt

%right OP_EQUALS
%left OR
%left AND
%nonassoc OP_EQ_EQ OP_NOT_EQ
%nonassoc OP_GREATER OP_GREATER_EQ OP_LESSER OP_LESSER_EQ
%left OP_PLUS OP_MINUS
%left OP_ASTERISK OP_SLASH OP_PERCENTAGE
%right NOT OP_PLUS_PLUS OP_MINUS_MINUS UMINUS
%left DOT DOT_DOT
%left LEFT_BRACE RIGHT_BRACE
%left LEFT_PAR RIGHT_PAR

%%

program:    stmt program
            |
            ;

stmt:       expr SEMICOLON
            |ifstmt
            |whilestmt
            |forstmt
            |returnstmt
            |BREAK SEMICOLON
            |CONTINUE SEMICOLON
            |block
            |funcdef
            |SEMICOLON
            ;

expr:       assignexpr      
            |expr op expr
            |term
            ;

op:         OP_PLUS | OP_MINUS | OP_ASTERISK | OP_SLASH | OP_PERCENTAGE | OP_GREATER | OP_GREATER_EQ | OP_LESSER | OP_LESSER_EQ | OP_EQ_EQ | OP_NOT_EQ | AND | OR
            ;

term:       LEFT_PAR expr RIGHT_PAR
            |OP_MINUS expr
            |NOT expr
            |OP_PLUS_PLUS lvalue
            |lvalue OP_PLUS_PLUS
            |OP_MINUS_MINUS lvalue
            |lvalue OP_MINUS_MINUS
            |primary
            ;

assignexpr: lvalue OP_EQUALS expr
            ;

primary:    lvalue
            |call
            |objectdef
            |LEFT_PAR funcdef RIGHT_PAR
            |const
            ;

lvalue:     IDENTIFIER  {SymTable_insert($$, scope, total_lines, 2);}
            |LOCAL IDENTIFIER
            |COL_COL IDENTIFIER
            |member
            ;

member:     lvalue DOT IDENTIFIER
            |lvalue LEFT_BRACKET expr RIGHT_BRACKET
            |call DOT IDENTIFIER
            |call LEFT_BRACKET expr RIGHT_BRACKET
            ;

call:       call LEFT_PAR elist RIGHT_PAR
            |lvalue callsuffix
            |LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR
            ;
        
callsuffix: normcall
            |methodcall
            ;

normcall:   LEFT_PAR elist RIGHT_PAR
            ;

methodcall: DOT_DOT IDENTIFIER LEFT_PAR elist RIGHT_PAR
            ;

elist:      expr
            | expr COMMA elist
            |
            ;

objectdef:  LEFT_BRACKET elist RIGHT_BRACKET
            |LEFT_BRACKET indexed RIGHT_BRACKET
            |LEFT_BRACKET RIGHT_BRACKET
            ;

indexed:    indexedelem
            | indexedelem COMMA indexed
            |
            ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE
            ;

func_stmt: stmt func_stmt
            | stmt
            ;

block:      LEFT_BRACE {
                    scope = scope + scope_flag;
                } RIGHT_BRACE {
                    scope = scope - scope_flag;
                }
            |LEFT_BRACE {
                    scope = scope + scope_flag;
                } func_stmt RIGHT_BRACE {
                    scope = scope - scope_flag;
                } 
            ;

funcdef:    FUNCTION  LEFT_PAR {
                    scope++; 
                    scope_flag = 0; 
                    functions++;
                } 
                idlist RIGHT_PAR block {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 
                    scope--;
                }
            |FUNCTION IDENTIFIER LEFT_PAR {
                    scope++; 
                    scope_flag = 0; 
                    functions++;
                } 
                idlist RIGHT_PAR block {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 
                    scope--;
                }
            ;

const:      INTEGER | REAL | STRING | NIL | TRUE | FALSE
            ;

idlist:     IDENTIFIER
            | IDENTIFIER COMMA idlist
            |
            ;

ifstmt:     IF LEFT_PAR expr RIGHT_PAR stmt 
            |IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt
            ;

whilestmt:  WHILE LEFT_PAR expr RIGHT_PAR stmt
            ;

forstmt:    FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist RIGHT_PAR stmt
            ;

returnstmt: RETURN SEMICOLON
            |RETURN expr SEMICOLON
            ;


%%

int SymTable_insert(const char *name, unsigned int scope, unsigned int line, types type) {
    kremastra *new_node, *temp;
    unsigned int index = SymTable_hash(name) % 499;
    int i;

    if (SymTable_lookup(strdup(name), scope, type)) {
        new_node = malloc(sizeof(kremastra));
        if (trapezaki->head[index] != NULL) {
            temp = trapezaki->head[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        else {
            trapezaki->head[index] = new_node;
        }
        new_node->next = NULL;
        new_node->isActive = 1;
        new_node->type = type;
        if (new_node->type <= 2) {
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
        //edw prepei na enwsoume k ta scope lists
    }
    else {
        yyerror("Illegal variable or function.\n");
    }
}

int SymTable_lookup(char *name, unsigned int scope, types type) {
    unsigned int hash = SymTable_hash(name);
    hash = hash % 499;

    //check an einai null
    kremastra *temp = trapezaki->head[hash];

    while (temp != NULL) {
        if ((type == 1) && (temp->type == 1)){
            if (temp->value.varVal->vscope == scope) {
                if (strcmp(name,temp->value.varVal->vname)) {
                    return 1;
                }
            }
        }
        temp = temp->next;
    }
    return 1;
    
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
    trapezaki = malloc(sizeof(Trapezi_Symvolwn));
    int i;
    for (i=0; i<SIZE; i++) {
        trapezaki->head[i] = NULL;
    }
}

int yyerror (char* yaccProvidedMessage) {
    fprintf(stderr, "%s: at line %d, before token: %s\n", yaccProvidedMessage, total_lines, yytext);
    fprintf(stderr, "INPUT NOT VALID\n");
    yyparse(); //mporei k na einai lathos auto
}

int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        printf("Reading from input file \"%s\"\n",argv[1]);
    }
    else {
        yyin = stdin;
    }
    SymTable_new();
    yyparse();
    return 0;
}
