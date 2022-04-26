%{
	#include "parser.h"
    #include "decl.h"
    #include <stdio.h>

    int total_lines = 1;
    int total_tokens = 0;
    int opened_block = 0;
    int block_starting_line = 0;
%}

%option noyywrap

INT         [0-9]+  
REAL        {INT}\.{1}{INT}
STRING      (\")([.\\]|[^"]|(\\\"))*(\")
IDENTIFIER  [A-Za-z]{1}[0-9A-Za-z_]*
LINE_COMM   "//".*
BLOCK_START (\/\*)
WHITESPACE  [ ]|"\t"|"\n"
UNCLOSED_STRING (\")([.\\]|[^"]|(\\\"))*

%x FIND_NESTED_COMMENT

%%


\n              {++total_lines;}
if              {return IF;}
else            {return ELSE;}
while           {return WHILE;}
for             {return FOR;}
function        {return FUNCTION;}
return          {return RETURN;}
break           {return BREAK;}
continue        {return CONTINUE;}
and             {return AND;}
not             {return NOT;}
or              {return OR;}
local           {return LOCAL;}
true            {return TRUE;}
false           {return FALSE;}
nil             {return NIL;}
"="             {return OP_EQUALS;}
"+"             {return OP_PLUS;}
"-"             {return OP_MINUS;}
"*"             {return OP_ASTERISK;}
"/"             {return OP_SLASH;}
"%"             {return OP_PERCENTAGE;}
"=="            {return OP_EQ_EQ;}
"!="            {return OP_NOT_EQ;}
"++"            {return OP_PLUS_PLUS;}
"--"            {return OP_MINUS_MINUS;}
">"             {return OP_GREATER;}
"<"             {return OP_LESSER;}
">="            {return OP_GREATER_EQ;}
"<="            {return OP_LESSER_EQ;}
"{"             {return LEFT_BRACE;}
"}"             {return RIGHT_BRACE;}
"["             {return LEFT_BRACKET;}
"]"             {return RIGHT_BRACKET;}
"("             {return LEFT_PAR;}
")"             {return RIGHT_PAR;}
";"             {return SEMICOLON;}
","             {return COMMA;}
":"             {return COLON;}
"::"            {return COL_COL;}
"."             {return DOT;}
".."            {return DOT_DOT;}

{INT}           {yylval.intVal = atoi(yytext); return INTEGER;}
{REAL}          {yylval.realVal = atof(yytext); return REAL;}
{STRING}        {yylval.strVal = strdup(string_reformatting(strdup(yytext))); return STRING;}
{IDENTIFIER}    {yylval.strVal = yylval.strVal = strdup(yytext); return IDENTIFIER;}
{LINE_COMM}     {;}
{WHITESPACE}    {;}
{UNCLOSED_STRING} {fprintf(stderr,"Warning: Unclosed string literal at line %d\n",total_lines);}
.               {++total_tokens; fprintf(stderr,"Undefined input %s line %d\n",strdup(yytext),total_lines);}


{BLOCK_START} {
    opened_block = 1;
    block_starting_line = 0;

    BEGIN(FIND_NESTED_COMMENT);
}

<FIND_NESTED_COMMENT>"\n" {
    ++total_lines;
    ++block_starting_line;
}

<FIND_NESTED_COMMENT>"/*" {
    opened_block++;
}

<FIND_NESTED_COMMENT>"*/" {
    opened_block--;

    if (opened_block > 0) {
        //xreiazetai na grapsoume kati edw?
    }
    else {
        BEGIN(INITIAL);
    }
}


%%

char* string_reformatting(char *initial_string) {
    char *formatted_string;
    char *current;
    int i,j, starting_line;

    *(initial_string++);    
    j=0;
    starting_line = total_lines;
    formatted_string = malloc(sizeof(char*)); //tha to xrhsimopoihsoume sto telos gia to \0
    current = initial_string;
    for (i=0; i<strlen(initial_string)-1;i++) {
        
        formatted_string = realloc(formatted_string, (strlen(formatted_string)+1)*sizeof(char*));
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
            else if (*(current+1) == '"') {
                formatted_string[j] = '\"';
            }
            else {
                formatted_string = realloc(formatted_string, (strlen(formatted_string)+1)*sizeof(char*));
                formatted_string[j] = *current;
                formatted_string[++j] = *(current+1);
                fprintf(stderr,"Warning: Invalid escape character %c\n",formatted_string[j]);
            }
            *(current++);
        }
        else if (*current == '\n'){
            ++total_lines;
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
struct alpha_token_t *head = NULL;
struct alpha_token_t *tail = NULL;

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
    }
    else {
        tail->next_token = newtoken;
        tail = newtoken;
    }

}


/* int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        printf("Reading from input file \"%s\"\n",argv[1]);
    }
    else {
        fprintf(stderr,"ERROR. No input file specified\n");
    }
    alpha_yylex(head);

    
    struct alpha_token_t *temp = head;
    if (argc > 2) {
        FILE *fp;

        fp = fopen(argv[2], "w+");
        fprintf(fp, "\n  Line\tToken#\t  Content\tCategory\n");
        while (temp != NULL) {
            fprintf(fp, "  %d\t#%d\t  \"%s\"\t\t%s\n",temp->token_line,temp->token_number,temp->token_tiexeimesa, temp->token_type);
            temp = temp->next_token;
        }
        if (opened_block > 0) {
            fprintf(fp, "Warning: Unclosed block comment.\n");
        }
        fclose(fp);
        printf("Output saved to file \"%s\"\n",argv[2]);
    }
    else {
        printf("\n  Line\tToken#\t  Content\tCategory\n");
        while (temp != NULL) {
            printf("  %d\t#%d\t  \"%s\"\t\t%s\n",temp->token_line,temp->token_number,temp->token_tiexeimesa, temp->token_type);
            temp = temp->next_token;
        }
        if (opened_block > 0) {
            fprintf(stderr,"Warning: Unclosed block comment.\n");
        }
    }

    return 0;
} */
