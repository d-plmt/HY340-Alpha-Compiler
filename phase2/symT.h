#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SIZE 1000
#define HASH_MULTIPLIER 65599

/*Structure containing info about our variables*/
typedef struct variable{
    /* data */
    char *vname;
    unsigned int vscope;
    unsigned int vline;
}var;

/*Structure containing info about our functions*/
typedef struct function{
    /* data */
    char *fname;
    unsigned int fscope;
    unsigned int fline;
}func;

/*Our Symbol Table*/
typedef struct SymTable{
    int isFull;
    var *symvar;
    func *symfunc;

    struct SymTable *next;
    
}symt;

/*Hash Table functions*/
unsigned int SymTable_hash(const char *key);
void SymTable_new(void);
unsigned int SymTable_length(SymTable oSym);
int SymTable_put(char *name, unsigned int scope, unsigned int line);