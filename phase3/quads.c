#include "quads.h"

////////////SYM/////////////
unsigned int currentscope = 0;
unsigned int programVarOffset = 0;
unsigned int functionLocalOffset = 0;
unsigned int formalArgOffset = 0;
unsigned int scopeSpaceCounter = 1;
unsigned int loopcounter = 0;
quad* quads = (quad*) 0;
unsigned int total = 0;
unsigned int currQuad = 0;
scope_link *lista;
SymTable *lera;
expr *_errorexpr;
iopcode iopenum;

//scopespace shit
scopespace_t currentscopespace(void){
    if (scopeSpaceCounter == 1)
        return programvar;
    else if (scopeSpaceCounter % 2 == 0)
        return formalarg;
    else
        return functionlocal;
}

unsigned currscopeoffset(void){
    switch (currentscopespace()){
        case programvar     : return programVarOffset;
        case functionlocal  : return functionLocalOffset;
        case formalarg      : return formalArgOffset;
        default             : assert(0);
    }
}

void inccurrscopeoffset(void){
    switch (currentscopespace()){
        case programvar     : ++programVarOffset; break;
        case functionlocal  : ++functionLocalOffset; break;
        case formalarg      : ++formalArgOffset; break;
        default             : assert(0);
    }
}

void enterscopespace(void){
    ++scopeSpaceCounter;
}

void exitscopespace(void){
    assert(scopeSpaceCounter > 1);
    --scopeSpaceCounter;
} 

int currscope() {
    return currentscope;
}


void SymTable_hide(unsigned int scope) {
    scope_link *scope_temp;
    symt *entry_temp;

    if (!scope) {return;}
    scope_temp = lista;
    while ((scope_temp != NULL) && (scope_temp->scope_counter < scope)) {
        scope_temp = scope_temp->next;
    }
    if (scope_temp != NULL) {
        entry_temp = scope_temp->scope_head;
        while (entry_temp != NULL) {
            if (entry_temp->isActive) {
                //printf("\033[0;33mHiding %s  type: %s\n\033[0m",getName(entry_temp),getType(entry_temp->type));
                entry_temp->isActive = 0;
            }
            entry_temp = entry_temp->next_in_scope;
        }
    }
}

void SymTable_reveal(unsigned int scope) {
    scope_link *scope_temp;
    symt *entry_temp;

    if (!scope) {return;}
    scope_temp = lista;
    while ((scope_temp != NULL) && (scope_temp->scope_counter < scope)) {
        scope_temp = scope_temp->next;
    }
    if (scope_temp != NULL) {
        entry_temp = scope_temp->scope_head;
        while (entry_temp != NULL) {
                if (!entry_temp->isActive) {
                    //printf("\033[0;33mRevealing %s  type: %s\n\033[0m",getName(entry_temp),getType(entry_temp->type));
                    entry_temp->isActive = 1;
                }
            entry_temp = entry_temp->next_in_scope;
        }
    }
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

symt* SymTable_insert(const char *name, unsigned int line, scopespace_t space, symbol_t type) {
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

    new_node->isActive = 1;
    new_node->name = name;
    new_node->scope = currscope();
    new_node->line = line;
    new_node->offset = currscopeoffset();
    new_node->space = space;
    new_node->type = type;
    new_node->iaddress = 0;
    new_node->totalLocals = 0;
    new_node->next = NULL;
    new_node->next_in_scope = NULL;


    resize_pinaka(currscope());
    temp2 = lista;
    while (temp2->scope_counter != currscope()) {
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
    if (type != libraryfunc_s) inccurrscopeoffset();
    return new_node;
}

symt* SymTable_lookup(const char *new_symbol_name, unsigned int scope, char *search_mode) {
    symt *temp = NULL;
    unsigned int index = SymTable_hash(new_symbol_name) % 499;

    temp = lera -> head[index];
    if (isLibraryFunc(new_symbol_name)) {
        //printf("BBBB\n");
        while(temp != NULL) {
            if (!strcmp(new_symbol_name,getName(temp))) {
                return temp;
            }
            temp = temp->next;
        }
    }
    if (!strcmp(search_mode, "funcdef")) {
        while (temp != NULL) {
            if (!strcmp(new_symbol_name,getName(temp)) && (getScope(temp) == scope) && (temp->isActive)) {
                return temp;
            }
            temp = temp->next;
        }
    }
    else if (!strcmp(search_mode, "global_src")) {
        while (temp != NULL) {
            if (!strcmp(new_symbol_name,getName(temp)) && (getScope(temp) == 0)) {
                return temp;
            }
            temp = temp->next;
        }
    }
    else if (!strcmp(search_mode, "formal") || !strcmp(search_mode, "local")) {
        while (temp != NULL) {
            if (!strcmp(new_symbol_name,getName(temp)) && (getScope(temp) == scope) && (temp->isActive)) {
                return temp;
            }
            temp = temp->next;
        }
    }
    else if (!strcmp(search_mode, "var_src")) {
        while (temp != NULL) {
            if (!strcmp(new_symbol_name, getName(temp)) && (getScope(temp) < scope) && (temp->isActive)) {
                return temp;
            }
            temp = temp->next;
        }
    }
    else if (!strcmp(search_mode, "call_src")) {
        while (temp != NULL) {
            if (!strcmp(new_symbol_name, getName(temp)) && (temp->isActive)) {
                return temp;
            }
            temp = temp->next;
        }
    }
    return NULL;
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

const char * getName(symt * input){
    return (input->name);
}

unsigned int getScope(symt * input){
    return (input->scope);
}

unsigned int getLine(symt * input){
    return (input->line);
}

char *getType(symbol_t type) {
    if (type == 0) {
        return "var_s";
    }
    if (type == 1) {
        return "programfunc_s";
    }
    return "libraryfunc_s";
}

char *getScopeSpace(scopespace_t space) {
    if (space == 0) {
        return "programvar";
    }
    if (space == 1) {
        return "functionlocal";
    }
    return "formalarg";
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

//////////////STACK////////////////

void pushOffsetStack(int offset) {
    offsetStack *new_node = malloc(sizeof(offsetStack));
    new_node -> offset = offset;
    if (offsetTop == NULL) {
        new_node->next = NULL;
    }
    else {
        new_node->next = offsetTop;
    }
    offsetTop = new_node;
}

int popOffsetStack() {
    if (offsetTop == NULL) {
        return -1;
    }
    int to_return = offsetTop->offset;
    if (offsetTop->next == NULL) {
        free(offsetTop);
        offsetTop = NULL;
    }
    else {
        offsetStack *temp = offsetTop;
        offsetTop = offsetTop->next;
        free(temp);
    }
    return to_return;
}

void pushLoopStack(int loopCounter){
    loopStack *temp_node = malloc(sizeof(loopStack));
    temp_node->loopCounter = loopCounter;
    if(loopCounterTop == NULL){
        temp_node->next = NULL;
    }else{
        temp_node->next = loopCounterTop;
    }
    loopCounterTop = temp_node;
}

int popLoopStack(){
    if(loopCounterTop == NULL) {
        return -1;
    }
    int to_return = loopCounterTop->loopCounter;
    if(loopCounterTop->next == NULL) {
        free(loopCounterTop);
        loopCounterTop = NULL;
    }else{
        loopStack *temp = loopCounterTop;
        loopCounterTop = loopCounterTop->next;
        free(temp);
    }
    return to_return;
}

offsetStack *offsetTop = NULL;
loopStack *loopCounterTop = NULL;

//////////////QUADS////////////////
int tempcounter = 0;
int scopecounter = 0;

/*expands quad table*/
void expand (void){
    assert (total == currQuad);
    quad* p = (quad*)malloc(NEW_SIZE);
    if (quads){
        memcpy(p, quads, CURR_SIZE);
        free (quads);
    }
    quads = p;
    total += EXPAND_SIZE;
}

/*function produces a new instruction*/
void emit (iopcode op, expr* arg1, expr* arg2, expr* result, unsigned label, unsigned line) {
    if (currQuad == total) expand();
    quad* p     = quads + currQuad++;
    p -> op       = op;
    p -> arg1   = arg1;
    p -> arg2   = arg2;
    p -> result = result;
    p -> label  = label;
    p -> line   = line;
}



/*function */
expr* emit_iftableitem(expr* e){
    if (e->type != tableitem_e) 
        return e;
    else{
        expr* result = newexpr (var_e);
        result->sym = newtemp();
        emit(tablegetelem,e,e->index,result,currQuad,yylineno);
        return result; 
    }
}

expr* newexpr(expr_t t){
    expr* e = (expr*)malloc(sizeof(expr));
    memset(e, 0, sizeof(expr));
    e->type = t;
    return e;
}

expr* newexpr_conststring(char* s){
    expr* e = newexpr(conststring_e);
    e->strConst = strdup(s);
    return e;
}

/*function pou paragei onomata krufwn metavlitwn 
tempcounter = eswteriki metavliti pou metraei 
tis uparxouses krufes metavlites*/
char *newtempname(void){
    char *str = malloc(sizeof(1000));
    sprintf(str, "%s%d%c", "_t", tempcounter++, '\0');
    return (strdup(str));
}

/*function pou midenizei ton tempcounter*/
void resettemp(void){
    tempcounter = 0;
}

symt *newtemp(void){
    char *name = newtempname();
    symt *sym = SymTable_lookup(name, currscope(), "local");    //EDW CHECK
    if (sym == NULL){
        return SymTable_insert(name, yylineno, programvar, var_s); //edw logika theloume func_flag check
    }else{
        return sym;
    }
}

void resetformalargsoffset(void){
    formalArgOffset = 0;
}

void resetfunctionlocalsoffset(void){
    functionLocalOffset = 0;
}

void restorecurrscopeoffset(unsigned n){
    switch (currentscopespace()){
        case programvar     : programVarOffset = n; break;
        case functionlocal  : functionLocalOffset = n; break;
        case formalarg      : formalArgOffset = n; break;
        default             : assert(0);
    }
}

unsigned nextquadlabel(void){
    return currQuad;
}

void patchlabel(unsigned quadNo, unsigned label){
    assert(quadNo < currQuad);
    quads[quadNo].label = label;
}

expr* lvalue_expr (symt* sym){
    assert(sym);
    expr* e = (expr*)malloc(sizeof(expr));
    memset(e, 0, sizeof(expr));

    e->next = (expr*) 0;
    e->sym = sym;

    switch (sym->type){
        case var_s          : e->type = var_e; break;
        case programfunc_s  : e->type = programfunc_e; break;
        case libraryfunc_s  : e->type = libraryfunc_e; break;
        default             : assert(0);
    }
    return e;
}

expr* make_call(expr* lv, expr* reversed_elist){
    expr* func = emit_iftableitem(lv);
    while (reversed_elist) {
        printf("AAAAAA\n");
        emit(param, reversed_elist, NULL, NULL, currQuad, yylineno); 
        reversed_elist = reversed_elist->next;
    }
    emit(call, func, NULL, NULL, currQuad, yylineno); 
    expr* result = newexpr(var_e);
    result->sym = newtemp();
    emit(getretval, NULL,NULL, result, currQuad, yylineno); 
    return result;
}

expr* newexpr_constnum(double i){
    expr* e = newexpr(constnum_e);
    e->numConst = i;
    return e;
}

expr* newexpr_constbool(unsigned int b){
    expr* e = newexpr(constbool_e);
    e->boolConst = !!b; //estw oti b=5. (!b)= 0. (!!b) = 1. gi auto xrhsimopoiei !!.
    return e;
}

expr* member_item(expr *lvalue, char *id) {
    lvalue = emit_iftableitem(lvalue);
    expr *ti = newexpr(tableitem_e);
    ti->sym = lvalue->sym;
    ti->index = newexpr_conststring(id);
    return ti;
}

unsigned int istempname(const char* s){
    char *dest = malloc(sizeof(2));
    strncpy(dest, s, 2);
    return (!strcmp("_t",dest));        //exoume _f gia temp functions kai _t gia temp variables
                                        //opote tsekaroume an _t anti gia sketo _
}

unsigned int istempexpr(expr* e){
    return e->sym && istempname(e->sym->name);
}

void check_arith(expr* e, const char* context){
    if( e->type == constbool_e      ||
        e->type == conststring_e    ||
        e->type == nil_e            ||
        e->type == newtable_e       ||
        e->type == programfunc_e    ||
        e->type == libraryfunc_e    ||
        e->type == boolexpr_e)
        fprintf(stderr, "Illegal expr used in %s!", context);
} 

void make_stmt(stmt_t* s){
    s->breaklist = s->contlist = 0;
}
int newlist(int i){
    quads[1].label = 0;
    return i;
}
int mergelist(int l1, int l2){ //den eimai sigouri oti tin katalava prepei na tin ksanadoume!!!
    if(!l1) return l2;
    else {
        if (!l2) return l1;
        else{
            int i = l1;
            while(quads[i].label){
                i = quads[i].label;
                quads[i].label = l2;
                return l1;
            }
        }
    }
}
void patchlist(int list, int label){
    while (list){
        int next = quads[list].label;
        quads[list].label = label;
        list = next;
    }
}


/////////////////PRINT/////////////////////

char *iop_to_str(int iop) {
    if (iop == 0) return "assign";
    if (iop == 1) return "add";
    if (iop == 2) return "sub";
    if (iop == 3) return "mul";
    if (iop == 4) return "div_iop";
    if (iop == 5) return "mod";
    if (iop == 6) return "uminus";
    if (iop == 7) return "and";
    if (iop == 8) return "or";
    if (iop == 9) return "not";
    if (iop == 10) return "if_eq";
    if (iop == 11) return "if_noteq";
    if (iop == 12) return "if_lesseq";
    if (iop == 13) return "if_greatereq";
    if (iop == 14) return "if_less";
    if (iop == 15) return "if_greater";
    if (iop == 16) return "jump";
    if (iop == 17) return "call";
    if (iop == 18) return "param";
    if (iop == 19) return "ret";
    if (iop == 20) return "getretval";
    if (iop == 21) return "funcstart";
    if (iop == 22) return "funcend";
    if (iop == 23) return "tablecreate";
    if (iop == 24) return "tablegetelem";
    if (iop == 25) return "tablesetelem";
}

void printargstuff(expr *arg) {
    if (arg == NULL) {
        printf("            ");
    }
    else if (arg->sym != NULL) {
        printf("%8s    ",arg->sym->name);
    }
    else if (arg->type == constnum_e) {
        printf("%8.3f    ",arg->numConst);
    }
    else if (arg->type == constbool_e) {
        //printf("%8c    ",arg->boolConst);
        if (arg->boolConst) {
            printf("'true'  ");
        }
        else {
            printf("'false'   ");
        }
    }
    else if (arg->type == conststring_e) {
        printf("%8s    ",arg->strConst);
    }
    else {
        printf("%c(null)    ",' ');
    }
 }
 

void printquads() {
    int i = 0;
    printf("-----------------------------------------------------------\n");
    while (i < currQuad) {

        printf("quad: %d  \t  ",i);
        printf("op: %s\t",iop_to_str(quads[i].op));
        printf("arg1: ");
        printargstuff(quads[i].arg1);
        printf("arg2: ");
        printargstuff(quads[i].arg2);
        printf("result: ");
        printargstuff(quads[i].result);
        printf("label: ");
        printf("%d\n",quads[i].label);
        i++;
    }
    printf("-----------------------------------------------------------\n");
}