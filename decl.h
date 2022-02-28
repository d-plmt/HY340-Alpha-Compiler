typedef struct alpha_token_t{
    int token_number;
    int token_line;
    char *token_type;
    char *token_tiexeimesa;
    struct alpha_token_t *next_token;
} alpha_token_t;

alpha_token_t *tokens;

/*adds new token to token struct*/
void add_alpha_token_t(int line, char *type, char *tiexei);