#include "symT.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE   (total*sizeof(quad))
#define NEW_SIZE    (EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

unsigned programVarOffset       = 0;
unsigned functionLocalOffset    = 0;
unsigned formalArgOffset        = 0;
unsigned scopeSpaceCounter      = 1;
extern int total_lines;

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

quad*           quads = (quad*) 0;
unsigned        total = 0;
unsigned int    currQuad = 0;

typedef enum symbol_t  {
    var_s, 
    programfunc_s, 
    libraryfunc_s
}symbol_t;

typedef struct symbol {
    enum symbol_t   type;
    char*           name;
    scopespace_t    space;
    unsigned        offset;
    unsigned        scope;
    unsigned        line;
}symbol;

scopespace_t currentscopespace(void);
unsigned currscopeoffset (void);
void inccurrscopeoffset (void);
void enterscopespace (void);
void exitscopespace (void);
void resetformalargsoffset(void); //midenizei to offset twn formal args
void resetfunctionlocalsoffset(void); //midenizei to offset twn local functions
void restorecurrscopeoffset(unsigned n);

expr* emit_iftableitem(expr* e); //paragei tin entoli pou lamvanei ena stoixeio otan exoume lvalue.id kai to lvalue einai stoixeio pinaka
expr* lvalue_expr (symbol* sym);
expr* make_call(expr* lv, expr* reversed_elist);
expr* newexpr(expr_t t);
expr* newexpr_conststring(char* s);
expr* newexpr_constnum(double i);
expr* newexpr_constbool(unsigned int b);

int currscope(){return }; //epistrefei to scope
symt *newsymbol(const char *name);

char *newtempname(void); //paragei kai epistrefei ena neo onoma gia mia proswrini metavliti xrisimopoiontas mia metavliti tempcounter
symt *newtemp(void); //epistrefei mia nea krufi metavliti sto scope i mia diathesimi metavliti
void resettemp(void); //midenizei ton tempcounter
unsigned int istempname(char* s); //anagnwrizei an einai krufi metavliti
unsigned int istempexpr(expr* e); //

unsigned nextquadlabel(void);
void patchlabel(unsigned quadNo, unsigned label); //sumplirwnei ena arxika undefined label enos quad


void check_arith(expr* e, const char* context); //sunartisi pou tsekarei an xrisimopoieitai swsta to expr se ariumhtiko 