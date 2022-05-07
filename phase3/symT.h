#ifndef SYMT_H_INCLUDED
#define SYMT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define SIZE 499
#define HASH_MULTIPLIER 65599

unsigned int currentscope = 0;
unsigned scopeSpaceCounter      = 1;

typedef enum symbol_t  {
    var_s, 
    programfunc_s, 
    libraryfunc_s
}symbol_t;

typedef enum scopespace_t{
    programvar,
    functionlocal,
    formalarg
} scopespace_t;

typedef struct SymTableEntry
{
    bool isActive;
    const char *name;
    unsigned scope;
    unsigned line;
    unsigned offset;
    scopespace_t space;
    symbol_t type;
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

symt* SymTable_insert(const char *name, unsigned int line, scopespace_t space, symbol_t type);
symt* SymTable_lookup(const char *new_symbol_name, unsigned int scope, char *search_mode); 
void SymTable_hide(unsigned int scope);
void SymTable_reveal(unsigned int scope);

int currscope(); //epistrefei to scope
int currline();

bool isLibraryFunc(const char *funct);
void resize_pinaka(unsigned int scope);

const char *getName(symt *input);
unsigned int getScope(symt *input);
unsigned int getLine(symt *input);
scope_link *lista;
SymTable *lera;

//scopespace shit
scopespace_t currentscopespace(void);

unsigned currscopeoffset (void);
void inccurrscopeoffset (void);
void enterscopespace (void);
void exitscopespace (void);

#endif
