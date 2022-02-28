%{
    #include "decl.h"

    int total_lines = 1;
    int total_tokens = 0;
    
%}

%option yylineno


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
{STRING}        {printf("STRING ");}
{IDENTIFIER}    {printf("IDENTIFIER ");}
{LINE_COMM}     {printf("LINE COMMENT ");}
{BLOCK_COMM}    {printf("COMMENT ");}
{WHITESPACE}    {}


.               {++total_tokens;}


%%

yywrap() {}

    struct alpha_token_t *head = NULL;
    struct alpha_token_t *tail = NULL;

/*add new token to struct alpha_token_t*/
void add_alpha_token_t(int token_number, int line, char *type, char *tiexei){

    struct alpha_token_t * newtoken = (struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));

    newtoken->token_line = line;
    newtoken->token_number = token_number;
    newtoken->token_type = type;
    newtoken->token_tiexeimesa = tiexei;

    if(head == NULL){
        head = newtoken;
        tail = newtoken;
        head->next_token = NULL;
        tail->next_token = NULL;
    }else{
        tail->next_token = newtoken;
        newtoken->next_token = NULL;
        tail = newtoken;
    }

}

int main(int argc, char** argv) {
        
    if (argc != 1) {
        yyin = fopen(argv[1], "r");
    }
    else {
        yyin = stdin;
    }
    yylex();

    struct alpha_token_t *temp = head;
    while (temp != NULL) {
        printf("%s\t%d\n",temp->token_tiexeimesa, temp->token_line);
        temp = temp->next_token;
    }

    free(tokens);
    return 0;
}