%{
    #include <stdbool.h>
    #include <stdio.h>
    #include "symT.h" 
    #include <stdlib.h>

    int yyerror (char* yaccProvidedMessage);
    int yylex(void);

    extern int total_lines;
    extern char* yytext;
    extern FILE* yyin;

    char *str;
    char *ourVar;

    unsigned int block = 0;
    unsigned int scope = 0;
    int scope_flag = 1;
    int functions = 0;
    int func_counter = 0;
    int prev_block = 0;
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

/* %type <strVal>	stmt
%type		expr
%type <strVal>	op term assignexpr
%type <strVal>	primary lvalue member
%type <strVal>	call callsuffix normcall methodcall
%type <strVal>	elist objectdef indexed indexedelem
%type <strVal>	block funcdef const idlist
%type <strVal>	ifstmt whilestmt forstmt returnstmt */
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
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"break\" can't be used without a loop.\n\033[0m", total_lines);
                }
                else {
                    printf("\tkeyword \"break\"\n");
                }
            }
            |CONTINUE SEMICOLON {
                if (loop_scope < 1) {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"continue\" can't be used without a loop.\n\033[0m", total_lines);
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

/* op:         OP_PLUS | OP_MINUS | OP_ASTERISK | OP_SLASH | OP_PERCENTAGE | OP_GREATER | OP_GREATER_EQ | OP_LESSER | OP_LESSER_EQ | OP_EQ_EQ | OP_NOT_EQ | AND | OR
            ; */

term:       LEFT_PAR expr RIGHT_PAR {printf("Term: (expr)\n");}
            |OP_MINUS expr  {printf("Term: -expr\n");}
            |NOT expr {printf("Term: not expr\n");}
            |OP_PLUS_PLUS lvalue {
                if (SymTable_type_lookup($2,scope) == 0) {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m",total_lines);
                }
                else {
                    printf("Term: ++lvalue\n");
                }
            }
            |lvalue OP_PLUS_PLUS {
                printf("dollar 1: %s\tscope: %d\n",$1,scope);
                if (SymTable_type_lookup($1,scope) == 0) {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m", total_lines);
                }
                else {
                    printf("Term: lvalue++\n");
                }
            }
            |OP_MINUS_MINUS lvalue {
                if (SymTable_type_lookup($2,scope) == 0) {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m", total_lines);
                }
                else {
                    printf("Term: --lvalue\n");
                }
            }
            |lvalue OP_MINUS_MINUS {                
                if (SymTable_type_lookup($1,scope) == 0) {
                    printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m", total_lines);
                }
                else {
                    printf("Term: lvalue--\n");
                }
            }
            |primary {printf("Term: primary\n");}
            ;

assignexpr: lvalue OP_EQUALS expr {
                if (!local_flag)  {
                    symt *tmp = NULL;
                    int found_flag = 0;
                    int tmp_scope = scope;
                    while (tmp_scope >= 0) { //psaxnw ta scopes apo mesa pros ta eksw
                        tmp = SymTable_lookup(ourVar, tmp_scope, "local");
                        if (tmp != NULL) {
                            if (tmp->type > 2) {
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


                    
                    // tmp = SymTable_lookup(ourVar, scope, "call_src"); //psaxnei th metavlhth mas
                    // if (tmp != NULL) {
                    //     if (tmp->type > 2) {
                    //         printf("\033[0;31mERROR. Line %d: Attempting to use function as lvalue\n\033[0m", total_lines);
                    //     }
                    //     else {
                    //         printf("Assign expression: lvalue = expr\n");
                    //     }
                    // }
                }
                else {
                    printf("Assign expression: lvalue = expr\n");
                }
                
                local_flag = 0;
                // symt *tmp = NULL;
                // tmp = SymTable_lookup($2, scope, "call_src"); 
                // printf("lvalue: %s\n",$2);          
                // if (tmp != NULL) {
                //     if (tmp->type > 2) {
                //         printf("\033[0;31mERROR. Attempting to use function as lvalue\n\033[0m");
                //     }
                //     else {
                //         printf("Assign expression: lvalue = expr\n");
                //     }
                // }
                // else {
                //     if (scope == 0) {
                //         SymTable_insert($2, scope, total_lines, 0, block);
                //     }
                //     else {
                //         SymTable_insert($2, scope, total_lines, 1, block);
                //     }
                // }
            }
            ;

primary:    lvalue  {printf("Primary: lvalue\n");}
            |call   {printf("Primary: call\n");}
            |objectdef {printf("Primary: objectdef\n");}
            |LEFT_PAR funcdef RIGHT_PAR {printf("Primary: (funcdef)\n");}
            |const {printf("Primary: const\n");}
            ;
    
lvalue:     IDENTIFIER {   
                    ourVar = (char *)malloc(sizeof($1));
                    strcpy(ourVar, $1);               
                    printf("Lvalue: identifier\n");
                    symt *tmp = NULL;
                    tmp = SymTable_lookup($1, scope, "local"); //psaxnw to diko mou scope
                    if (tmp != NULL) {
                        //fprintf(stdout, "\033[0;31mERROR: Cannot access variable %s in this scope line %d\n\033[0m",$1, total_lines);
                        // if (func_flag) {
                        //     if (tmp->type > 2){
                        //         printf("AAAAAAAAAAAAA%s",getName(tmp));
                        //         fprintf(stdout, "\033[0;31mERROR: Attempting to use function as lvalue\n\033[0m");
                        //     }
                        // }
                        // else {
                        //     fprintf(stdout, "Calling symbol %s.\n",$1);
                        // }
                    }
                    else {
                        //an eimai se synarthsh
                        if (func_flag) {
                            printf("ASDSADASDSD\n");
                            int found_flag = 0;
                            int tmp_scope = scope-1;
                            while (tmp_scope >= 0) { //psaxnw parent scopes apo mesa pros ta eksw
                                tmp = SymTable_lookup($1, tmp_scope, "local");
                                if (tmp != NULL) {
                                    if (tmp_scope != 0) {
                                        if (tmp->type < 3) {
                                            fprintf(stdout, "\033[0;31mError. Line %d: Cannot access variable %s in this scope\n\033[0m",total_lines, $1);
                                            found_flag = 1;
                                            break;
                                        }
                                        else {
                                            fprintf(stdout, "Calling symbol %s.\n",$1);
                                            found_flag = 1;
                                            break;
                                        }
                                    }
                                    else {
                                        fprintf(stdout, "Calling symbol %s.\n",$1);
                                        found_flag = 1;
                                        break;
                                    }
                                }
                                tmp_scope--;
                            }
                            if (!found_flag) {
                                SymTable_insert($1, scope, total_lines, 1, block);
                            }
                            // tmp = SymTable_lookup($1, scope, "var_src"); //koitaw parent scopes
                            // if (tmp != NULL) { //an vrw kati
                            // printf("UYTUYTUTYUTY\n");
                            //     if (getScope(tmp) != 0) { //to opoio den einai global
                            //         if (tmp->type < 2) { //kai einai variable, petaw error
                            //             fprintf(stdout, "\033[0;31mERROR: Cannot access variable %s in this scope\n\033[0m",$1);
                            //         }
                            //         else { //alliws an einai func ola gucci
                            //             fprintf(stdout, "Calling symbol %s.\n",$1);
                            //         }
                            //     }
                            //     else { //alliws an einai global ola good
                            //         fprintf(stdout, "Calling symbol %s.\n",$1);
                            //     }
                            // }
                            // else { //alliws afou de vrhka sta parent scopes ola good
                            //     SymTable_insert($1, scope, total_lines, 1, block);
                            // }
                        }
                        else { //den eimai se synarthsh
                            tmp = SymTable_lookup($1, scope, "call_src"); //koitaw ola ta scopes
                            if (tmp != NULL) { //an vrw kati ola good
                                fprintf(stdout, "Calling symbol %s in parent scope.\n", $1);
                            }
                            else { //alliws kanw eisagwgh
                                if (scope == 0) {
                                    SymTable_insert($1, scope, total_lines, 0, block);
                                }
                                else {
                                    SymTable_insert($1, scope, total_lines, 1, block);
                                }
                            }
                        }

                    }
            }

            |LOCAL IDENTIFIER {
                local_flag = 1;
                ourVar = (char *)malloc(sizeof($1));
                strcpy(ourVar, $2); 
                printf("Lvalue: local identifier\n");
                if (SymTable_lookup($2, scope, "local") == NULL) {
                    SymTable_insert($2, scope, total_lines, 1, block);
                }
                else {

                    fprintf(stdout, "Variable (%s) successfully found in this scope (%d)\n", $2, scope);
                }
            }
            |COL_COL IDENTIFIER {
                ourVar = (char *)malloc(sizeof($1));
                strcpy(ourVar, $2); 
                printf("Lvalue: ::identifier\n");
                //printf("\tscope: %u, block: %d\n",scope,block);
                if (SymTable_lookup($2, scope, "global_src") != NULL) {
                    fprintf(stdout, "Symbol %s successfully found in global scope.\n", $2);
                }
                else {
                    fprintf(stdout,"\033[0;31mERROR. Line %d: Symbol %s not global or undefined.\n\033[0m", total_lines, $2);
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
                    block = block + scope_flag;
                    scope = scope + scope_flag;
                    //printf("\t\t\tBlock: %d\tScope: %d\n",block, scope);
                } RIGHT_BRACE {
                    scope = scope - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(scope+1);
                    }
                    //printf("\t\t\tBlock: %d\tScope: %d\n",block, scope);
                    {printf("Block: {}\n");}
                }
            |LEFT_BRACE {
                    block = block + scope_flag;
                    scope = scope + scope_flag;
                    //printf("\t\t\tBlock: %d\tScope: %d\n",block, scope);
                } func_stmt RIGHT_BRACE {
                    scope = scope - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(scope+1);
                    }
                    //printf("\t\t\tBlock: %d\tScope: %d\n",block, scope);
                }
                {printf("Block: {func_stmt}\n");} 
            ;
funcdef:    FUNCTION LEFT_PAR {
                    sprintf(str, "%s%d%c","_f",func_counter+1,'\0');
                    if (SymTable_lookup(strdup(str), scope, "funcdef") == NULL) {
                        func_flag++;
                        functions++;
                        func_counter++;
                        SymTable_insert(strdup(str), scope, total_lines, 3, block);
                        scope++; 
                        scope_flag = 0; 
                        prev_block = block;
                        block++;
                        //SymTable_hide(scope-1);
                    }
                    else {
                        fprintf(stderr,"\033[0;31mERROR. Line %d: Function (%s) in scope %d cannot be defined\n\033[0m",total_lines, strdup(str),scope);
                        yyerror("");
                    }
                } 
                idlist RIGHT_PAR block {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 
                    func_flag--;
                    scope--;
                    SymTable_hide(scope+1);
                    SymTable_reveal(scope);
                    printf("Funcdef: function (idlist) {}\n");
                }
            |FUNCTION 
                IDENTIFIER {
                }
                LEFT_PAR {
                    if (SymTable_lookup($2, scope, "funcdef") == NULL) {
                        SymTable_insert($2, scope, total_lines, 3, block);
                        {func_flag++;}
                        functions++;
                        scope++; 
                        scope_flag = 0;
                        prev_block = block;
                        block++;
                        //SymTable_hide(scope-1);
                    }
                    else {
                        fprintf(stderr,"\033[0;31mERROR. Line %d: Function (%s) in scope %d cannot be defined\n\033[0m", total_lines, $2, scope);
                        yyerror("");
                    }
                } 
                idlist RIGHT_PAR block {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 
                    func_flag--;
                    scope--;
                    SymTable_hide(scope+1);
                    SymTable_reveal(scope);
                    printf("Funcdef: function identifier(idlist) {}\n");
                }
            ;

const:      INTEGER {printf("Const: integer\n");}
            | REAL {printf("Const: real\n");}
            | STRING {printf("Const: string\n");}
            | NIL {printf("Const: nil\n");}
            | TRUE {printf("Const: true\n");}
            | FALSE {printf("Const: false\n");}
            ;

idlist:     IDENTIFIER  {
                printf("Idlist: identifier\n");
                symt *tmp = NULL;
                tmp = SymTable_lookup($1, scope, "formal");
                if (tmp != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Parameter (%s) in scope %d cannot be defined\n\033[0m", total_lines, $1,scope);
                }
                else {
                    SymTable_insert ($1, scope, total_lines, 2, block);
                }
                // if (SymTable_general_lookup($1, scope, 2, block, "formal")) {
                //     SymTable_insert ($1, scope, total_lines, 2, block);
                // }
                // else {
                //     fprintf(stderr,"\033[0;31mERROR: Parameter (%s) in scope %d line %d cannot be defined\n\033[0m",$1,scope,total_lines);
                // }
            }
            | IDENTIFIER COMMA idlist {
                printf("Idlist: identifier,...,identifier\n");
                symt *tmp = NULL;
                tmp = SymTable_lookup($1, scope, "formal");
                if (tmp != NULL) {
                    fprintf(stderr,"\033[0;31mERROR. Line %d: Parameter (%s) in scope %d cannot be defined\n\033[0m", total_lines, $1,scope);
                }
                else {
                    SymTable_insert ($1, scope, total_lines, 2, block);
                }
                // if (SymTable_general_lookup($1, scope, 2, block, "formal")) {
                //     SymTable_insert ($1, scope, total_lines, 2, block);
                // }
                // else {
                //     fprintf(stderr,"\033[0;31mERROR: Parameter (%s) in scope %d line %d cannot be defined\n\033[0m",$1,scope,total_lines);
                // }
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
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",total_lines);
                }
            }
            |RETURN expr SEMICOLON {
                if (func_flag > 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "\033[0;31mERROR. Line %d: Keyword \"return\" can't be used without a function.\n\033[0m",total_lines);
                }
            }
            ;


%%

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
