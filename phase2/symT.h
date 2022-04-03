#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define SIZE 499
#define HASH_MULTIPLIER 65599

/*Structure containing info about our variables*/
typedef struct variable{
    /* data */
    const char *vname;
    unsigned int vscope;
    unsigned int vline;
}var;

/*Structure containing info about our functions*/
typedef struct function{
    /* data */
    const char *fname;
    unsigned int fscope;
    unsigned int fline;
}func;

typedef enum symt {
	GLOBAL, LOCAL_SYM, FORMAL, USERFUNC, LIBFUNC
} types;

typedef struct SymTableEntry{
    bool isActive;
    union {
    	var *varVal;
    	func *funcVal;
    } value;
    types type;
    struct SymTableEntry *next;
} symt;

typedef struct SymTable {
	symt *head[SIZE];
} Trapezi_Symvolwn;

symt ** symtable = NULL;

/*Hash Table functions*/
unsigned int SymTable_hash(const char *key);
const char * getName(symt *input);
unsigned int * getScope(symt *input);
unsigned int * getLine(symt *input);
void SymTable_new(void);
int SymTable_insert(const char *name, unsigned int scope, unsigned int line, types type);
int SymTable_general_lookup(const char * name);
void SymTable_hide(unsigned int scope);
