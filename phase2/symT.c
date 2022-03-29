#include "symT.h"

symt **sym_head = NULL;
/*hash function*/
unsigned int SymTable_hash(const char *key){
    size_t ui;
    unsigned int uiHash = 0U;

    for (ui = 0U; key[ui] != '\0'; ui++){
        uiHash = uiHash * HASH_MULTIPLIER + key[ui];
     }

  return uiHash%SIZE;
}

/*SymTable_new
 *Initializes our Symbol Table*/
void SymTable_new(void){
    sym_head = (SymTable *)malloc(sizeof(SymTable)*SIZE);
}