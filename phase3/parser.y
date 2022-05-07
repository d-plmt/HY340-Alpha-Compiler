%{
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
%}

%start program
%union {int intVal; double realVal; char *strVal;}

%token <intVal>     INTEGER
%token <realVal>    REAL
%token <strVal>     STRING
%token <strVal>     IDENTIFIER
%token <strVal>     IF ELSE WHILE FOR FUNCTION RETURN BREAK CONTINUE AND NOT OR LOCAL TRUE FALSE NIL OP_EQUALS OP_PLUS OP_MINUS OP_ASTERISK OP_SLASH OP_PERCENTAGE OP_EQ_EQ OP_NOT_EQ OP_PLUS_PLUS OP_MINUS_MINUS OP_GREATER OP_LESSER OP_GREATER_EQ OP_LESSER_EQ LEFT_BRACE RIGHT_BRACE LEFT_BRACKET RIGHT_BRACKET LEFT_PAR RIGHT_PAR SEMICOLON COMMA COLON COL_COL DOT DOT_DOT LINE_COMM


%type stmt expr term assignexpr primary member call callsuffix normcall methodcall elist objectdef indexed indexedelem block funcdef const idlist ifstmt whilestmt forstmt returnstmt

%type <strVal> lvalue

%right OP_EQUALS
%left OR
%left AND
%nonassoc OP_EQ_EQ OP_NOT_EQ
%nonassoc OP_GREATER OP_GREATER_EQ OP_LESSER OP_LESSER_EQ
%left OP_PLUS OP_MINUS
%left OP_ASTERISK OP_SLASH OP_PERCENTAGE
%right NOT OP_PLUS_PLUS OP_MINUS_MINUS
%left DOT DOT_DOT
%left LEFT_BRACE RIGHT_BRACE
%left LEFT_PAR RIGHT_PAR

%%

program:    stmt program    
            |   {printf("\nProgram stopped\n\n");}
            ;

stmt:       expr SEMICOLON  {printf("Stmt: expr;\n");}
            |ifstmt     {printf("\tif statement\n");}
            |whilestmt  {printf("\twhile statement\n");}
            |forstmt    {printf("\tfor statement\n");}
            |returnstmt {printf("\treturn statement\n");}
            |BREAK SEMICOLON    {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"break\" can't be used without a loop.\n\033[0m", yylineno);
                }
                else {
                    printf("\tkeyword \"break\"\n");
                }
            }
            |CONTINUE SEMICOLON {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"continue\" can't be used without a loop.\n\033[0m", yylineno);
                }
                else {
                    printf("\tkeyword \"continue\"\n");
                }
            }
            |block      {printf("\tBlock\n");}
            |funcdef    {printf("\tFunction definition\n");}
            |SEMICOLON
            ;

expr:       assignexpr      {printf("Assign expression\n");}
            |expr OP_PLUS expr  {printf("Expr: expr op_plus expr\n");}
            |expr OP_MINUS expr {printf("Expr: expr op_minus expr\n");}
            |expr OP_ASTERISK expr  {printf("Expr: expr op_asterisk expr\n");}
            |expr OP_SLASH expr {printf("Expr: expr op_slash expr\n");}
            |expr OP_PERCENTAGE expr {printf("Expr: expr op_percentage expr\n");}
            |expr OP_GREATER expr {printf("Expr: expr op_greater expr\n");}
            |expr OP_GREATER_EQ expr {printf("Expr: expr op_greater_eq expr\n");}
            |expr OP_LESSER expr {printf("Expr: expr op_lesser expr\n");}
            |expr OP_LESSER_EQ expr {printf("Expr: expr op_lesser_eq expr\n");}
            |expr OP_EQ_EQ expr {printf("Expr: expr op_eq_eq expr\n");}
            |expr OP_NOT_EQ expr {printf("Expr: expr op_not_eq expr\n");}
            |expr AND expr {printf("Expr: expr and expr\n");}
            |expr OR expr {printf("Expr: expr or expr\n");}
            |term   {printf("Term expression\n");}
            ;

term:       LEFT_PAR expr RIGHT_PAR {printf("Term: (expr)\n");}
            |OP_MINUS expr  {printf("Term: -expr\n");}
            |NOT expr {printf("Term: not expr\n");}
            |OP_PLUS_PLUS lvalue {
                if (lvalue_checker(ourVar)) {
                    printf("Term: ++lvalue\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                }
            }
            |lvalue OP_PLUS_PLUS {
                if (lvalue_checker(ourVar)) {
                    printf("Term: lvalue++\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                }
            }
            |OP_MINUS_MINUS lvalue {
                if (lvalue_checker(ourVar)) {
                    printf("Term: --lvalue\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                }
            }
            |lvalue OP_MINUS_MINUS {                
                if (lvalue_checker(ourVar)) {
                    printf("Term: lvalue--\n");
                }
                else {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",yylineno);
                }
            }
            |primary {printf("Term: primary\n");}
            ;

assignexpr: lvalue OP_EQUALS expr {
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
            ;

primary:    lvalue  {printf("Primary: lvalue\n");}
            |call   {printf("Primary: call\n");}
            |objectdef {printf("Primary: objectdef\n");}
            |LEFT_PAR funcdef RIGHT_PAR {printf("Primary: (funcdef)\n");}
            |const {printf("Primary: const\n");}
            ;
    
lvalue:     IDENTIFIER {   
                    ourVar = (char *)malloc(sizeof($IDENTIFIER));
                    strcpy(ourVar, $IDENTIFIER);               
                    printf("Lvalue: identifier\n");
                    symt *tmp_symbol = NULL;
                    tmp_symbol = SymTable_lookup($IDENTIFIER, currscope(), "local"); //psaxnw to diko mou scope
                    if (tmp_symbol == NULL) {
                        //an eimai se synarthsh
                        if (func_flag) {
                            int found_flag = 0;
                            int tmp_scope = currscope()-1;
                            while (tmp_scope >= 0) { //psaxnw parent scopes apo mesa pros ta eksw
                                tmp_symbol = SymTable_lookup($IDENTIFIER, tmp_scope, "local");
                                if (tmp_symbol != NULL) {
                                    if (tmp_scope != 0) {
                                        if (tmp_symbol->type < 3) {
                                            fprintf(stdout, "\033[0;31mError. Line %d: Cannot access variable %s in this scope\n\033[0m",yylineno, $IDENTIFIER);
                                            found_flag = 1;
                                            break;
                                        }
                                        else {
                                            fprintf(stdout, "Calling symbol %s.\n",$IDENTIFIER);
                                            found_flag = 1;
                                            break;
                                        }
                                    }
                                    else {
                                        fprintf(stdout, "Calling symbol %s.\n",$IDENTIFIER);
                                        found_flag = 1;
                                        break;
                                    }
                                }
                                tmp_scope--;
                            }
                            if (!found_flag) {
                                SymTable_insert($IDENTIFIER, yylineno, functionlocal, var_s);
                            }
                        }
                        else { //den eimai se synarthsh
                            tmp_symbol = SymTable_lookup($IDENTIFIER, currscope(), "call_src"); //koitaw ola ta scopes
                            if (tmp_symbol != NULL) { //an vrw kati ola good
                                fprintf(stdout, "Calling symbol %s in parent scope.\n", $1);
                            }
                            else { //alliws kanw eisagwgh
                                SymTable_insert($IDENTIFIER, yylineno, programvar, var_s);
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

            |LOCAL IDENTIFIER {
                local_flag = 1;
                ourVar = (char *)malloc(sizeof($IDENTIFIER));
                strcpy(ourVar, $IDENTIFIER); 
                printf("Lvalue: local identifier\n");

                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup($IDENTIFIER, currscope(), "local");
                if (tmp_symbol == NULL) {
                    if (func_flag) { //an eimaste mesa se synarthsh exw func local
                        SymTable_insert($IDENTIFIER, yylineno, functionlocal, var_s);
                    }
                    else {
                        SymTable_insert($IDENTIFIER, yylineno, programvar, var_s);
                    }
                }
                else {

                    fprintf(stdout, "Symbol %s successfully found in this scope (%d), line %d.\n", $IDENTIFIER, currscope(), getLine(tmp_symbol));
                }
            }
            |COL_COL IDENTIFIER {
                ourVar = (char *)malloc(sizeof($IDENTIFIER));
                strcpy(ourVar, $IDENTIFIER); 
                symt *tmp_symbol = NULL;
                printf("Lvalue: ::identifier\n");
                if ((tmp_symbol = SymTable_lookup($IDENTIFIER, currscope(), "global_src")) != NULL) {
                    fprintf(stdout, "Symbol %s successfully found in global scope, line %d.\n", $IDENTIFIER, getLine(tmp_symbol));
                }
                else {
                    fprintf(stdout,"\033[0;31mERROR. Line %d: Symbol %s not global or undefined.\n\033[0m", yylineno, $IDENTIFIER);
                }
            }
            |member {printf("Lvalue: member\n");}
            ;

member:     lvalue DOT IDENTIFIER {printf("Member: lvalue.identifier\n");}
            |lvalue LEFT_BRACKET expr RIGHT_BRACKET {printf("Member: lvalue[identifier]\n");}
            |call DOT IDENTIFIER {printf("Member: call.identifier\n");}
            |call LEFT_BRACKET expr RIGHT_BRACKET {printf("Member: call[identifier]\n");}
            ;

call:       call {call_flag = 1;}LEFT_PAR elist RIGHT_PAR {call_flag = 0; printf("Call: call(elist)\n");}
            | lvalue {call_flag=1;}callsuffix { printf("Call: lvalue callsuffix\n");}
            |LEFT_PAR funcdef RIGHT_PAR {call_flag = 1;} LEFT_PAR elist RIGHT_PAR {call_flag = 0; printf("Call: (funcdef)(elist)\n");}
            ;
        
callsuffix: normcall {printf("Callsuffix: normcall\n");}
            |methodcall {printf("Callsuffix: method\n");}
            ;

normcall:   LEFT_PAR {call_flag = 1;} elist RIGHT_PAR {call_flag = 0; printf("Normcall: (elist)\n");}
            ;

methodcall: DOT_DOT {call_flag = 1;} IDENTIFIER LEFT_PAR  elist RIGHT_PAR {call_flag = 0; printf("Methodcall: ..identifier(elist)\n");}
            ;

elist:      expr {printf("Elist: expr\n");}
            | expr COMMA elist {printf("Elist: expr,...,expr\n");}
            |
            ;

objectdef:  LEFT_BRACKET elist RIGHT_BRACKET  {printf("Objectdef: (elist)\n");}
            |LEFT_BRACKET indexed RIGHT_BRACKET {printf("Objectdef: (indexed)\n");}
            ;

indexed:    indexedelem {printf("Indexed: indexedelem\n");}
            | indexedelem COMMA indexed {printf("Indexed: indexedelem,...,indexedelem\n");}
            ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE {printf("Indexedelem: [expr:expr]\n");}
            ;

func_stmt: stmt func_stmt {printf("Func_stmt: stmt,...,stmt\n");}
            | stmt {printf("Func_stmt: stmt\n");}
            ;

block:      LEFT_BRACE {
                    currentscope = currscope() + scope_flag;
                } RIGHT_BRACE {
                    currentscope = currscope() - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(currscope()+1);
                    }
                    {printf("Block: {}\n");}
                }
            |LEFT_BRACE {
                    currentscope = currscope() + scope_flag;
                } func_stmt RIGHT_BRACE {
                    currentscope = currscope() - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(currscope()+1);
                    }
                }
                {printf("Block: {func_stmt}\n");} 
            ;

funcname:   IDENTIFIER /* edw apothikeush tou func name */ {
                if (SymTable_lookup($IDENTIFIER, currscope(), "funcdef") == NULL) {
                    if (func_flag > 0) {
                        SymTable_insert($IDENTIFIER, yylineno, programfunc_s, functionlocal);
                    }
                    else {
                        SymTable_insert($IDENTIFIER, yylineno, programfunc_s, programvar);
                    }
                    func_flag++;
                    // functions++;
                    currentscope++; 
                    scope_flag = 0;
                }
                else {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Function (%s) in scope %d cannot be defined\n\033[0m", yylineno, $IDENTIFIER, currscope());
                    yyerror("");
                }
            }
            |  /* EDW NEWTEMP  */ {
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
            ;

funcprefix: FUNCTION funcname {
                //TODO
            }
            ;

funcargs:  LEFT_PAR idlist RIGHT_PAR /*TODO*/ {
                enterscopespace();
                printf("\nA\n");
            }
            ;

funcbody:   block {
                if (!(--func_flag)){ //an func_flag-1=0, vghka apo ola ta functions
                    scope_flag = 1;
                }
                currentscope--;
                SymTable_hide(currscope()+1);
                SymTable_reveal(currscope());
                printf("Funcdef: function identifier(idlist) {}\n");
            }
            ;

funcdef:    funcprefix funcargs funcbody
            ;

const:      INTEGER {printf("Const: integer\n");}
            | REAL {printf("Const: real\n");}
            | STRING {printf("Const: string\n");}
            | NIL {printf("Const: nil\n");}
            | TRUE {printf("Const: true\n");}
            | FALSE {printf("Const: false\n");}
            ;

idlist:     IDENTIFIER  {
    printf("B\n");
                printf("Idlist: identifier\n");
                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup($IDENTIFIER, currscope(), "formal");
                if (tmp_symbol != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Symbol %s in scope %d cannot be defined\n\033[0m", yylineno, $IDENTIFIER,currscope());
                }
                else {
                    SymTable_insert ($IDENTIFIER, yylineno, formalarg, var_s);
                }
            }
            | IDENTIFIER COMMA idlist {
                printf("Idlist: identifier,...,identifier\n");
                symt *tmp_symbol = NULL;
                tmp_symbol = SymTable_lookup($IDENTIFIER, currscope(), "formal");
                if (tmp_symbol != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Symbol %s in scope %d cannot be defined\n\033[0m", yylineno, $IDENTIFIER,currscope());
                }
                else {
                    SymTable_insert ($IDENTIFIER, yylineno, formalarg, var_s);
                }
            }
            |
            ;

ifstmt:     IF LEFT_PAR expr RIGHT_PAR stmt {printf("Ifstmt: if (expr) stmt\n");}
            |IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt {printf("Ifstmt: if (expr) stmt else stmt\n");}
            ;

whilestmt:  WHILE LEFT_PAR expr RIGHT_PAR {
                loop_scope++;
            }
            stmt {
                loop_scope--;
                printf("Whilestmt: while (expr) stmt\n");
            }
            ;

forstmt:    FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist RIGHT_PAR {
                loop_scope++;
            }
            stmt {
                loop_scope--;
                printf("Forstmt: for (elist;expr;elist) stmt\n");
            }
            ;

returnstmt: RETURN SEMICOLON {
                if (func_flag > 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",yylineno);
                }
            }
            |RETURN expr SEMICOLON {
                if (func_flag > 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",yylineno);
                }
            }
            ;


%%

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
