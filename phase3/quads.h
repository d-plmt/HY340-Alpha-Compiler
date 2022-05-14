#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


#define SIZE 499
#define HASH_MULTIPLIER 65599
#define EXPAND_SIZE 1024
#define CURR_SIZE   (total*sizeof(quad))
#define NEW_SIZE    (EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

extern int yylineno;
extern unsigned int currentscope;
extern unsigned int programVarOffset;
extern unsigned int functionLocalOffset;
extern unsigned int formalArgOffset;
extern unsigned int scopeSpaceCounter;
extern unsigned int loopcounter;

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

typedef enum iopcode {
    assign,         add,            sub,
    mul,            div_iop,        mod,
    uminus,         and,            or,
    not,            if_eq,          if_noteq,
    if_lesseq,      if_greatereq,   if_less,
    if_greater,     jump,           call,           
    param,          ret,            getretval,      
    funcstart,      funcend,        tablecreate,    
    tablegetelem,   tablesetelem
} iopcode;

typedef enum expr_t {
    var_e,
    tableitem_e,
    programfunc_e,
    libraryfunc_e,
    arithexpr_e,
    boolexpr_e,
    assignexpr_e,
    newtable_e,
    constnum_e,
    constbool_e,
    conststring_e,
    nil_e
} expr_t;

typedef struct SymTableEntry
{
    bool isActive;
    const char *name;
    unsigned scope;
    unsigned line;
    unsigned offset;
    unsigned iaddress;
    unsigned totalLocals;
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

typedef struct expr {
    expr_t          type;
    symt*           sym;
    struct expr*    index;
    double          numConst;
    char*           strConst;
    unsigned char   boolConst;
    struct expr*    next;
} expr;

typedef struct quad {
    iopcode         op;
    expr*           result;
    expr*           arg1;
    expr*           arg2;
    unsigned        label;
    unsigned        line;
} quad;

typedef struct callstruct {
    struct expr *elist;
    unsigned char method;
    char *name;
} callstruct;

typedef struct indexedpairs {
    struct expr *key;
    struct expr *value;
    struct indexedpairs *next;
} indexedpairs;

typedef struct stmt_t{
    int breaklist;
    int contlist;
}stmt_t;

typedef struct forprefix{
    int enter;
    int test;
}forprefix;

extern quad*           quads;
extern unsigned        total;
extern unsigned int    currQuad;
extern expr *_errorexpr;

/* Scope Offset Stack */
typedef struct scopeOffsetStack {
    int offset;
    struct scopeOffsetStack *next;
} offsetStack;

typedef struct loopCounterStack {
    int loopCounter;
    struct loopCounterStack *next;
}loopStack;

void pushOffsetStack(int offset);
int popOffsetStack();
void pushLoopStack(int loopCounter);
int popLoopStack();

extern offsetStack *offsetTop;
extern loopStack *loopCounterTop;

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
char *getType(symbol_t type);

extern scope_link *lista;
extern SymTable *lera;

//scopespace shit
scopespace_t currentscopespace(void);

unsigned currscopeoffset (void);
void inccurrscopeoffset (void);
void enterscopespace (void);
void exitscopespace (void);


void resetformalargsoffset(void); //midenizei to offset twn formal args
void resetfunctionlocalsoffset(void); //midenizei to offset twn local functions
void restorecurrscopeoffset(unsigned n);

void emit();

expr* emit_iftableitem(expr* e); //paragei tin entoli pou lamvanei ena stoixeio otan exoume lvalue.id kai to lvalue einai stoixeio pinaka
expr* lvalue_expr (symt* sym);
expr* make_call(expr* lv, expr* reversed_elist);
expr* newexpr(expr_t t);
expr* newexpr_conststring(char* s);
expr* newexpr_constnum(double i);
expr* newexpr_constbool(unsigned int b);
expr* member_item(expr *lvalue, char *name);


symt *newsymbol(const char *name); //auto de to xreiazomaste, exoume thn symtable_insert

char *newtempname(void); //paragei kai epistrefei ena neo onoma gia mia proswrini metavliti xrisimopoiontas mia metavliti tempcounter
symt *newtemp(void); //epistrefei mia nea krufi metavliti sto scope i mia diathesimi metavliti
void resettemp(void); //midenizei ton tempcounter
unsigned int istempname(const char* s); //anagnwrizei an einai krufi metavliti
unsigned int istempexpr(expr* e); //

unsigned nextquadlabel(void);
void patchlabel(unsigned quadNo, unsigned label); //sumplirwnei ena arxika undefined label enos quad

void check_arith(expr* e, const char* context); //sunartisi pou tsekarei an xrisimopoieitai swsta to expr se ariumhtiko 

void make_stmt(stmt_t* s);
int newlist(int i);
int mergelist(int l1, int l2);
void patchlist(int list, int label);
void printquads();