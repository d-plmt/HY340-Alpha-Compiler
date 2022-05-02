#include "quads.h"

int tempcounter = 0;

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

char *newtempname(void){
    return "_t" + tempcounter;
}

void resettemp(void){
    tempcounter = 0;
}

//den eimai sigouri an einai Sym_Table i symt gt mperdeutika ligo
symt *newtemp(void){
    char *name = newtempname();
    symt *sym = lookup(name, currscope());
    if (sym == NULL){
        return newsymbol(name);
    }else{
        return sym;
    }
}
