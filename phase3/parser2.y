%{
    #include <stdbool.h>
    #include <stdio.h>
    #include "quads.h"
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
                    fprintf(stderr, "ERROR: Keyword \"break\" can't be used without a loop.\n");
                }
                else {
                    printf("\tkeyword \"break\"\n");
                }
            }
            |CONTINUE SEMICOLON {
                if (loop_scope < 1) {
                    fprintf(stderr, "ERROR: Keyword \"continue\" can't be used without a loop.\n");
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
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Term: ++lvalue\n");
                }
            }
            |lvalue OP_PLUS_PLUS {
                printf("dollar 1: %s\tscope: %d\n",$1,scope);
                if (SymTable_type_lookup($1,scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Term: lvalue++\n");
                }
            }
            |OP_MINUS_MINUS lvalue {
                if (SymTable_type_lookup($2,scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Term: --lvalue\n");
                }
            }
            |lvalue OP_MINUS_MINUS {                
                if (SymTable_type_lookup($1,scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Term: lvalue--\n");
                }
            }
            |primary {printf("Term: primary\n");}
            ;

assignexpr: lvalue OP_EQUALS expr {                
                if (SymTable_type_lookup($1,scope) == 0) {
                    printf("ERROR. Attempting to use function as lvalue\n");
                }
                else {
                    printf("Assign expression: lvalue = expr\n");
                }
            }
            ;

primary:    lvalue  {printf("Primary: lvalue\n");}
            |call   {printf("Primary: call\n");}
            |objectdef {printf("Primary: objectdef\n");}
            |LEFT_PAR funcdef RIGHT_PAR {printf("Primary: (funcdef)\n");}
            |const {printf("Primary: const\n");}
            ;
    
lvalue:     IDENTIFIER {
                if (call_flag == 0) {                     
                    printf("Lvalue: identifier\n");
                    int returned = SymTable_general_lookup($1, scope, 1, block, "new_var");
                    if (returned == 2) {
                        //fprintf(stdout, "%s refers to another symbol in the same scope.\n",$1);
                    }
                    else if (returned == 0) {
                        //fprintf(stdout, "%s refers to another symbol in a parent scope.\n", $1);
                    }
                    else if (returned == 1) {
                        if (scope == 0 && block == 0) {
                            SymTable_insert($1, scope, total_lines, 0, block);
                        }
                        else {
                            SymTable_insert($1, scope, total_lines, 1, block);
                        }
                    }
                    else if (returned == -1) {
                        fprintf(stdout, "\nERROR: Cannot access (%s) in scope %d \n", $1, scope);
                    }
                }

            }

            |LOCAL IDENTIFIER {
                printf("Lvalue: local identifier\n");
                int returned = SymTable_general_lookup($2, scope, 1, block, "local");
                int realtype = 1;
                if (scope == 0) {
                    realtype = 0;
                }
                if (returned == 1) {
                    SymTable_insert ($2, scope, total_lines, realtype, block);
                }
                else if (returned == 2) {
                    //fprintf(stdout, "Local variable %s already defined.\n", $2);
                }
                else {
                    fprintf(stdout, "\nERROR: Variable (%s) cannot be defined in scope %d line %d\n", $2, scope, total_lines);
                }
            }
            |COL_COL IDENTIFIER {
                printf("Lvalue: ::identifier\n");
                int returned = SymTable_general_lookup($2, 0, 0, block, "global_src");
                if (returned == 2) {
                    fprintf(stdout, "Symbol %s successfully found in global scope.\n", $2);
                }
                else {
                    fprintf(stdout,"\nERROR: Symbol %s in line %d not global or undefined.\n", $2, total_lines);
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
            | lvalue callsuffix { printf("Call: lvalue callsuffix\n");}
            |LEFT_PAR funcdef RIGHT_PAR {call_flag = 1;} LEFT_PAR elist RIGHT_PAR {call_flag = 0; printf("Call: (funcdef)(elist)\n");}
            ;
        
callsuffix: normcall {printf("Callsuffix: normcall\n");}
            |methodcall {printf("Callsuffix: method\n");}
            ;

normcall:   LEFT_PAR {call_flag = 1;} elist RIGHT_PAR {call_flag = 0; printf("Normcall: (elist)\n");}
            ;

methodcall: DOT_DOT IDENTIFIER LEFT_PAR {call_flag = 1;} elist RIGHT_PAR {call_flag = 0; printf("Methodcall: ..identifier(elist)\n");}
            ;

elist:      expr {printf("Elist: expr\n");}
            | expr COMMA elist {printf("Elist: expr,...,expr\n");}
            | {printf("Empty Elist\n");}
            ;

objectdef:  LEFT_BRACKET elist RIGHT_BRACKET  {printf("Objectdef: [elist]\n");}
            |LEFT_BRACKET indexed RIGHT_BRACKET {printf("Objectdef: [indexed]\n");}
            ;

indexed:    indexedelem {printf("Indexed: indexedelem\n");}
            | indexedelem COMMA indexed {printf("Indexed: indexedelem,...,indexedelem\n");}
            ;

indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE {printf("Indexedelem: {expr:expr}\n");}
            ;

func_stmt: stmt func_stmt {printf("Func_stmt: stmt,...,stmt\n");}
            | stmt {printf("Func_stmt: stmt\n");}
            ;

block:      LEFT_BRACE {
                    block = block + scope_flag;
                    scope = scope + scope_flag;
                } RIGHT_BRACE {
                    scope = scope - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(scope+1);
                    }
                    {printf("Block: {}\n");}
                }
            |LEFT_BRACE {
                    block = block + scope_flag;
                    scope = scope + scope_flag;
                } func_stmt RIGHT_BRACE {
                    scope = scope - scope_flag;
                    if (scope_flag == 1) {
                        SymTable_hide(scope+1);
                    }
                }
                {printf("Block: {func_stmt}\n");} 
            ;
funcdef:    FUNCTION LEFT_PAR {
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
                idlist RIGHT_PAR block {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 

                    scope--;
                    SymTable_hide(scope+1);
                    SymTable_reveal(scope);
                    printf("Funcdef: function (idlist) {}\n");
                }
            |FUNCTION 
                IDENTIFIER {
                }
                LEFT_PAR {
                    if (SymTable_general_lookup($2, scope, 3, block, "funcdef")) {
                        SymTable_insert($2, scope, total_lines, 3, block);
                        functions++;
                        scope++; 
                        scope_flag = 0;
                        prev_block = block;
                        block++;
                        SymTable_hide(scope-1);
                    }
                    else {
                        fprintf(stderr,"\nERROR: Function (%s) in scope %d line %d cannot be defined\n",$2,scope,total_lines);
                        yyerror("");
                    }
                } 
                idlist RIGHT_PAR block {
                    if (!(--functions)){
                        scope_flag = 1;
                    } 
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
                {printf("Idlist: identifier\n");}
                if (SymTable_general_lookup($1, scope, 2, block, "formal")) {
                    SymTable_insert ($1, scope, total_lines, 2, block);
                }
                else {
                    fprintf(stderr,"ERROR: Parameter (%s) in scope %d line %d cannot be defined\n",$1,scope,total_lines);
                }
            }
            | IDENTIFIER COMMA idlist {
                {printf("Idlist: identifier,...,identifier\n");}
                if (SymTable_general_lookup($1, scope, 2, block, "formal")) {
                    SymTable_insert ($1, scope, total_lines, 2, block);
                }
                else {
                    fprintf(stderr,"ERROR: Parameter (%s) in scope %d line %d cannot be defined\n",$1,scope,total_lines);
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
                if (scope_flag == 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "ERROR: Keyword \"return\" in line %d can't be used without a function.\n",total_lines);
                }
            }
            |RETURN expr SEMICOLON {
                if (scope_flag == 0) {
                    printf("Returnstmt: return;\n");
                }
                else {
                    fprintf(stderr, "ERROR: Keyword \"return\" in line %d can't be used without a function.\n",total_lines);
                }
            }
            ;


%%

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
            if ((strcmp(getName(tmp),name) == 0)) {
                printf("\t\tVAR %s, scope %d, block %u, active %d\n",getName(tmp),getScope(tmp),tmp->block, tmp->isActive);
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
