typedef struct alpha_token_t{
    int token_number;
    int token_line;
    char *token_type;
    char *token_tiexeimesa;
    struct alpha_token_t *next_token;
} alpha_token_t;

alpha_token_t *tokens;

/*adds new token to token struct*/
void add_alpha_token_t(int token_number, int line, char *type, char *tiexei);
char *string_reformatting(char *initial_string);
void nested_comment_checker(char *full_comment);

struct nested_comments{
	char *next_comment;
} nested_comments;
