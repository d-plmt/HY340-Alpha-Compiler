%{
    #include "decl.h"

    int total_lines = 0;
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


\n              {++total_lines; ++total_tokens;}
if              {printf("KEYWORD ");}
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
"\t"            {printf("t");}

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
/*add new token to struct alpha_token_t*/
void add_alpha_token_t(int line, char *type, char *tiexei){

    struct alpha_token_t * newtoken = (struct alpha_token_t *)malloc(sizeof(struct alpha_token_t));
    struct alpha_token_t * temp = NULL;

    newtoken->token_line = line;
    newtoken->token_number++;
    newtoken->token_type = type;
    newtoken->token_tiexeimesa = tiexei;

    if(head == NULL){
        head = newtoken;
        head->next_token = NULL;
    }else{
        for(temp=head; temp->next_token!=NULL; temp=temp->next_token){
            temp->next_token = newtoken;
            newtoken->next_token = NULL;
        }
    }

}

int main(int argc, char** argv) {
    tokens = (alpha_token_t*)malloc(sizeof(alpha_token_t));
    printf("%d",tokens->token_number);
    
    if (argc != 1) {
        yyin = fopen(argv[1], "r");
    }
    else {
        yyin = stdin;
    }
    yylex();
    free(tokens);
    return 0;
}