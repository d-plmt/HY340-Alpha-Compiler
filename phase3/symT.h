#ifndef SYMT_H_INCLUDED
#define SYMT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define SIZE 499
#define HASH_MULTIPLIER 65599

/*Structure containing info about our variables*/
typedef struct variable
{
    /* data */
    const char *vname;
    unsigned int vscope;
    unsigned int vline;
} var;

/*Structure containing info about our functions*/
typedef struct function
{
    /* data */
    const char *fname;
    unsigned int fscope;
    unsigned int fline;
} func;

typedef enum symt
{
    GLOBAL,
    LOCAL_SYM,
    FORMAL,
    USERFUNC,
    LIBFUNC
} types;

typedef struct SymTableEntry
{
    bool isActive;
    union
    {
        var *varVal;
        func *funcVal;
    } value;
    types type;
    unsigned int block;
    struct SymTableEntry *next;
    struct SymTableEntry *next_in_scope;
} symt;

typedef struct SymTable
{
    symt *head[SIZE];
} SymTable;

typedef struct scope_link
{
    int scope_counter;
    symt *scope_head;
    struct scope_link *next;
} scope_link;

/*Hash Table functions*/
unsigned int SymTable_hash(const char *key);

void SymTable_new(void);
int SymTable_insert(const char *name, unsigned int scope, unsigned int line, types type, unsigned int block);
int SymTable_general_lookup(const char *name, unsigned int scope, types type, unsigned int block, char *search_mode);
int SymTable_smol_lookup(const char *name, unsigned int scope);
int SymTable_smoller_lookup(const char *name, unsigned int scope, unsigned int block);
int SymTable_type_lookup(const char *name, unsigned int scope);
symt* SymTable_lookup(const char *new_symbol_name, unsigned int scope, unsigned int block, char *search_mode); 
void SymTable_hide(unsigned int scope);
void SymTable_reveal(unsigned int scope);

bool isLibraryFunc(const char *funct);
void resize_pinaka(unsigned int scope);

const char *getName(symt *input);
unsigned int getScope(symt *input);
unsigned int getLine(symt *input);
char *getType(types type);
scope_link *lista;
SymTable *lera;

#endif
