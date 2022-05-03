#include "quads.h"

int tempcounter = 0;

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

scopespace_t currentscopespace(void){
    if (scopeSpaceCounter == 1)
        return programvar;
    else if (scopeSpaceCounter % 2 == 0)
        return formalarg;
    else
        return functionlocal;
}

unsigned currscopeoffset(void){
    switch (currscopespace()){
        case programvar     : return programVarOffset;
        case functionlocal  : return functionLocalOffset;
        case formalarg      : return formalArgOffset;
        default             : assert(0);
    }
}

void inccurrscopeoffset(void){
    switch (currscopespace()){
        case programvar     : return ++programVarOffset; break;
        case functionlocal  : return ++functionLocalOffset; break;
        case formalarg      : return ++formalArgOffset; break;
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

/*function pou paragei onomata krufwn metavlitwn 
tempcounter = eswteriki metavliti pou metraei 
tis uparxouses krufes metavlites*/
char *newtempname(void){
    return "_t" + tempcounter;
}

/*function pou midenizei ton tempcounter*/
void resettemp(void){
    tempcounter = 0;
}

symt *newtemp(void){
    char *name = newtempname();
    symt *sym = lookup(name, currscope());
    if (sym == NULL){
        return newsymbol(name);
    }else{
        return sym;
    }
}
