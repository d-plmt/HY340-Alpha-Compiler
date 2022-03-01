%{
    #include "decl.h"

    #define YY_DECL int alpha_yylex(void *yyval)

    int total_lines = 1;
    int total_tokens = 0;
    
%}

%option yylineno
%option noyywrap


INT         [0-9]+  
REAL        {INT}\.{1}{INT}
STRING      (\")([.\\]|[^"]|(\\\"))*(\")
IDENTIFIER  [A-Za-z]{1}[0-9A-Za-z_]*
LINE_COMM   (\/){1}(\/){1}[^\\\n]*[\\\n]{1}
BLOCK_COMM  (\/){1}(\*){1}*.*(\*){1}(\/){1}
WHITESPACE  [ ]|"\t"|"\n"
%%


\n              {++total_lines;}
if              {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD", strdup(yytext));}
else            {printf("KEYWORD ");}
while           {printf("KEYWORD ");}
for             {printf("KEYWORD ");}
function        {printf("KEYWORD ");}
return          {printf("KEYWORD ");}
break           {printf("KEYWORD ");}
continue        {printf("KEYWORD ");}
and             {printf("KEYWORD ");}
not             {printf("KEYWORD ");}
or              {printf("KEYWORD ");}
local           {printf("KEYWORD ");}
true            {printf("KEYWORD ");}
false           {printf("KEYWORD ");}
nil             {printf("KEYWORD ");}
"="             {printf("OPERATOR ");}
"+"             {printf("OPERATOR ");}
"-"             {printf("OPERATOR ");}
"*"             {printf("OPERATOR ");}
"/"             {printf("OPERATOR ");}
"%"             {printf("OPERATOR ");}
"=="            {printf("OPERATOR ");}
"!="            {printf("OPERATOR ");}
"++"            {printf("OPERATOR ");}
"--"            {printf("OPERATOR ");}
">"             {printf("OPERATOR ");}
"<"             {printf("OPERATOR ");}
">="            {printf("OPERATOR ");}
"<="            {printf("OPERATOR ");}
"{"             {printf("PUNCTUATION ");}
"}"             {printf("PUNCTUATION ");}
"["             {printf("PUNCTUATION ");}
"]"             {printf("PUNCTUATION ");}
"("             {printf("PUNCTUATION ");}
")"             {printf("PUNCTUATION ");}
";"             {printf("PUNCTUATION ");}
","             {printf("PUNCTUATION ");}
":"             {printf("PUNCTUATION ");}
"::"            {printf("PUNCTUATION ");}
"."             {printf("PUNCTUATION ");}
".."            {printf("PUNCTUATION ");}

{INT}           {printf("INT ");}
{REAL}          {printf("REAL ");}
{STRING}        {add_alpha_token_t(++total_tokens, total_lines, "STRING", string_reformatting(strdup(yytext)));}
{IDENTIFIER}    {printf("IDENTIFIER ");}
{LINE_COMM}     {printf("LINE COMMENT ");}
{BLOCK_COMM}    {nested_comment_checker(strdup(yytext));}
{WHITESPACE}    {}


.               {++total_tokens; printf("Undefined input %s line %d\n",strdup(yytext),total_lines);}


%%

struct alpha_token_t *head = NULL;
struct alpha_token_t *tail = NULL;

void nested_comment_checker(char *full_comment) {
    int opening_comments = 0;
    int closing_comments = 0;
    int i;
    char *current;

    current = full_comment+2;   //ksekiname meta to 1o /*
    for (i=2; i<strlen(full_comment)-2; i++) {  //pame mexri prin to teleutaio */
        printf("%c", *current);
        *(current++);
    }
}

char *string_reformatting(char *initial_string) {
    char *formatted_string;
    char *current;
    int i,j;
    
    j=0;
    formatted_string = malloc(sizeof(char)); //tha to xrhsimopoihsoume sto telos gia to \0
    current = initial_string;
    for (i=0; i<strlen(initial_string);i++) {
        
        formatted_string = realloc(formatted_string, sizeof(char));
        if (*current == '\\') {
            if (*(current+1) == 'n') {
                formatted_string[j] = '\n';
            }
            else if (*(current+1) == 't') {
                formatted_string[j] = '\t';
            }
            else if (*(current+1) == '\\') {
                formatted_string[j] = '\\';
            }
            else {
                formatted_string = realloc(formatted_string, sizeof(char));
                formatted_string[j] = *current;
                formatted_string[++j] = *(current+1);
                printf("Warning: Invalid escape character %c\n",formatted_string[j]);
            }
            *(current++);
        }
        else {
            formatted_string[j] = *current;
        }
        j++;
        *(current++);
    }
    formatted_string[j] = '\0';

    return formatted_string;
}

/*add new token to struct alpha_token_t*/
void add_alpha_token_t(int token_number, int line, char *type, char *tiexei){

    struct alpha_token_t * newtoken = (struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));

    newtoken->token_line = line;
    newtoken->token_number = token_number;
    newtoken->token_type = type;
    newtoken->token_tiexeimesa = tiexei;
    newtoken->next_token = NULL;

    if(head == NULL){
        head = newtoken;
        tail = newtoken;
    }else{
        tail->next_token = newtoken;
        tail = newtoken;
    }

}


int main(int argc, char** argv) {
    if (argc > 0) {
        yyin = fopen(argv[1], "r");
    }
    else {
        printf("ERROR. No input file specified\n");
    }
    alpha_yylex(head);

    //edw allagh me stdout

    struct alpha_token_t *temp = head;
    
    printf("\n  Line\tToken#\t  Content\tCategory\n");
    while (temp != NULL) {
        printf("  %d\t#%d\t  %s\t\t%s\n",temp->token_line,temp->token_number,temp->token_tiexeimesa, temp->token_type);
        temp = temp->next_token;
    }

    return 0;
}