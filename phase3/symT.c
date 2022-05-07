#include "symT.h"

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
                printf("\033[0;33mHiding %s  type: %s\n\033[0m",getName(entry_temp),getType(entry_temp->type));
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
                    printf("\033[0;33mRevealing %s  type: %s\n\033[0m",getName(entry_temp),getType(entry_temp->type));
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
    return temp;
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
