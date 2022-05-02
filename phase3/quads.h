#include "symT.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE   (total*sizeof(quad))
#define NEW_SIZE    (EXPAND_SIZE*sizeof(quad)+CURR_SIZE)

typedef enum iopcode {
    assign,         add,            sub,
    mul,            div_iop,            mod,
    uminus,         and,            or,
    not,            if_eq,          if_noteq,
    if_lesseq,      if_greatereq,   if_less,
    if_greater,     call,           param,
    ret,            getretval,      funcstart,
    funcend,        tablecreate,    tablegetelem,
    tablesetelem
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

int currscope(){return }; //epistrefei to scope
symt *lookup(const char *name, unsigned int scope); //epistrefei to sumvolo se sugkekrimeno scope
symt *newsymbol(const char *name);

char *newtempname(void); //paragei kai epistrefei ena neo onoma gia mia proswrini metavliti xrisimopoiontas mia metavliti tempcounter
symt *newtemp(void); //epistrefei mia nea krufi metavliti sto scope i mia diathesimi metavliti
void resettemp(void); //midenizei ton tempcounter