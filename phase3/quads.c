#include "quads.h"

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
void emit (
    iopcode     op,
    expr*       arg1,
    expr*       arg2,
    expr*       result,
    unsigned    label,
    unsigned    line
    ) {
    if (currQuad == total)
        expand();

    quad* p     = quads + currQuad++;
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
    return "_t" + tempcounter + '\0';
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
    e->boolConst = !!b; //etsi to exei alla den katalavainw ti ennoei
    return e;
}

unsigned int istempname(const char* s){
    return *s == '_';
}

unsigned int istempexpr(expr* e){
    return e->sym && istempname(e->sym->name); //prepei na vroume pws tha pairnei to fname i to vname
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