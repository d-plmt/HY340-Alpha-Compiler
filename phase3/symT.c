#include "symT.h"


void SymTable_hide(unsigned int scope) {
    scope_link *scope_temp;
    symt *entry_temp;

    scope_temp = lista;
    while (scope_temp != NULL) {
        if (scope_temp->scope_counter == scope) {
            entry_temp = scope_temp->scope_head;
            while (entry_temp != NULL) {
                if (!isLibraryFunc(getName(entry_temp))) {
                    printf("\033[0;33mHiding %s  type: %s\n\033[0m",getName(entry_temp),getType(entry_temp->type));
                    entry_temp->isActive = 0;
                }
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
                    if (!isLibraryFunc(getName(entry_temp))) {
                        printf("\033[0;33mRevealing %s  type: %s\n\033[0m",getName(entry_temp),getType(entry_temp->type));
                        entry_temp->isActive = 1;
                    }
                entry_temp = entry_temp->next_in_scope;
            }
        }
        scope_temp = scope_temp->next;
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

symt* SymTable_lookup(const char *new_symbol_name, unsigned int scope, unsigned int block, char *search_mode) {
    symt *temp = NULL;
    unsigned int index = SymTable_hash(new_symbol_name) % 499;

    temp = lera -> head[index];
    if (isLibraryFunc(new_symbol_name)) {
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
            printf("\tsymbol %s scope %u block %u\n",getName(temp),getScope(temp),temp->block);
            if (!strcmp(new_symbol_name,getName(temp)) && (getScope(temp) == 0) && (temp->block == 0)) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    return NULL;
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
            if (strcmp(getName(tmp),name) == 0) {
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
