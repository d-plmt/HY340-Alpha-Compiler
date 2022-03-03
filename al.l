%{
    #include "decl.h"
    #include <stdio.h>

    #define YY_DECL int alpha_yylex(void *yyval)

    int total_lines = 1;
    int total_tokens = 0;
  
    int flag=0;
    int opening = 0;
    int line123 = 0;
%}

%option yylineno
%option noyywrap



INT         [0-9]+  
REAL        {INT}\.{1}{INT}
STRING      (\")([.\\]|[^"]|(\\\"))*(\")
IDENTIFIER  [A-Za-z]{1}[0-9A-Za-z_]*
LINE_COMM   (\/\/)+.+
BLOCK_START (\/\*)
WHITESPACE  [ ]|"\t"|"\n"

%x FIND_NESTED_COMMENT FIND_NESTED_END FIND_BLOCK_END

%%


\n              {++total_lines;}
if              {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   IF", strdup(yytext));}
else            {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   ELSE", strdup(yytext));}
while           {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   WHILE", strdup(yytext));}
for             {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   FOR", strdup(yytext));}
function        {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   FUNCTION", strdup(yytext));}
return          {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   RETURN", strdup(yytext));}
break           {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   BREAK", strdup(yytext));}
continue        {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   CONTINUE", strdup(yytext));}
and             {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   AND", strdup(yytext));}
not             {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   NOT", strdup(yytext));}
or              {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   OR", strdup(yytext));}
local           {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   LOCAL", strdup(yytext));}
true            {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   TRUE", strdup(yytext));}
false           {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   FALSE", strdup(yytext));}
nil             {add_alpha_token_t(++total_tokens, total_lines, "KEYWORD   NIL", strdup(yytext));}
"="             {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   EQUALS", strdup(yytext));}
"+"             {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   PLUS", strdup(yytext));}
"-"             {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   MINUS", strdup(yytext));}
"*"             {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   ASTERISK", strdup(yytext));}
"/"             {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   SLASH", strdup(yytext));}
"%"             {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   PERCENTAGE", strdup(yytext));}
"=="            {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   EQUALS EQUALS", strdup(yytext));}
"!="            {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   EXCLAMATION EQUALS", strdup(yytext));}
"++"            {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   PLUS PLUS", strdup(yytext));}
"--"            {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   MINUS MINUS", strdup(yytext));}
">"             {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   GREATER", strdup(yytext));}
"<"             {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   LESSER", strdup(yytext));}
">="            {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   GREATER EQUALS", strdup(yytext));}
"<="            {add_alpha_token_t(++total_tokens, total_lines, "OPERATOR   LESSER EQUALS", strdup(yytext));}
"{"             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION LEFT BRACE", strdup(yytext));}
"}"             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION RIGHT BRACE", strdup(yytext));}
"["             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION LEFT BRACKET", strdup(yytext));}
"]"             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION RIGHT BRACKET", strdup(yytext));}
"("             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION LEFT PARENTHESIS", strdup(yytext));}
")"             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION RIGHT PARENTHESIS", strdup(yytext));}
";"             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION SEMICOLON", strdup(yytext));}
","             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION COMMA", strdup(yytext));}
":"             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION COLON", strdup(yytext));}
"::"            {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION COLON COLON", strdup(yytext));}
"."             {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION DOT", strdup(yytext));}
".."            {add_alpha_token_t(++total_tokens, total_lines, "PANCTUATION DOT DOT", strdup(yytext));}

{INT}           {add_alpha_token_t(++total_tokens, total_lines, "INTCONST", strdup(yytext));}
{REAL}          {add_alpha_token_t(++total_tokens, total_lines, "DOUBLECONST", strdup(yytext));}
{STRING}        {string_reformatting(strdup(yytext));}
{IDENTIFIER}    {add_alpha_token_t(++total_tokens, total_lines, "IDENTIFIER", strdup(yytext));}
{LINE_COMM}     {add_alpha_token_t(++total_tokens, total_lines, "LINE COMMENT", strdup(yytext));}
{WHITESPACE}    {;}
.               {++total_tokens; printf("Undefined input %s line %d\n",strdup(yytext),total_lines);}

(\")([.\\]|[^"]|(\\\"))* {printf("Warning.\n");}

{BLOCK_START} {
    opening = 1;
    line123 = 0;

    BEGIN(FIND_NESTED_COMMENT);
}
<FIND_NESTED_COMMENT>"\n" {
    ++total_lines;
    ++line123;
}

<FIND_NESTED_COMMENT>"/*" {
    opening++;
}

<FIND_NESTED_COMMENT>"*/" {
    opening--;

    if (opening > 0) {
        add_alpha_token_t(++total_tokens, total_lines-line123, "NESTED COMMENT", "");
    }
    else {
        add_alpha_token_t(++total_tokens, total_lines-line123, "BLOCK COMMENT", "");
        BEGIN(INITIAL);
    }
}


%%
char *tmp;


void nested_comment_checker(char *full_comment) {
    int opening_nested = 0;
    int closing_nested = 0;
    char *current;
    int i, nested_flag;

    nested_flag = 0;
    add_alpha_token_t(++total_tokens, total_lines, "BLOCK COMMENT", strdup(yytext));
    tmp = (char *)realloc(tmp,sizeof(strlen(full_comment)));
    strncpy(tmp,(full_comment+2),strlen(full_comment)-4);

    current = tmp;
    while (*(current+1)) {
        if (*current == '\n') {
            total_lines++;
        }
        else if (*current == '/' && (*(current+1) == '*')) {
            opening_nested++;
            nested_flag = total_lines;
        }
        else if (*current == '*' && (*(current+1) == '/')) {
            closing_nested++;
        }
        *(current++);
    }
    free(tmp);

    if (opening_nested > closing_nested) {
        printf("Warning: Unclosed block comment\n");
    }
    else if (opening_nested == closing_nested && (opening_nested>0)) {
        add_alpha_token_t(++total_tokens, nested_flag, "NESTED COMMENT", "");
    }
    
}

void string_reformatting(char *initial_string) {
    char *formatted_string;
    char *current;
    int i,j, starting_line;
    
    j=0;
    starting_line = total_lines;
    formatted_string = malloc(sizeof(char*)); //tha to xrhsimopoihsoume sto telos gia to \0
    current = initial_string;
    for (i=0; i<strlen(initial_string);i++) {
        
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
            else {
                formatted_string = realloc(formatted_string, (strlen(formatted_string)+1)*sizeof(char*));
                formatted_string[j] = *current;
                formatted_string[++j] = *(current+1);
                printf("Warning: Invalid escape character %c\n",formatted_string[j]);
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

    add_alpha_token_t(++total_tokens, starting_line, "STRING", formatted_string);
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
    }else{
        tail->next_token = newtoken;
        tail = newtoken;
    }

}


int main(int argc, char** argv) {
    tmp = (char *)malloc(sizeof(char));
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        printf("Reading from input file \"%s\"\n",argv[1]);
    }
    else {
        printf("ERROR. No input file specified\n");
    }
    alpha_yylex(head);

    
    struct alpha_token_t *temp = head;
    if (argc > 2) {
        FILE *fp;

        fp = fopen(argv[2], "w+");
        fprintf(fp, "\n  Line\tToken#\t  Content\tCategory\n");
        while (temp != NULL) {
            fprintf(fp, "  %d\t#%d\t  %s\t\t%s\n",temp->token_line,temp->token_number,temp->token_tiexeimesa, temp->token_type);
            temp = temp->next_token;
        }
        if (opening > 0) {
            fprintf(fp, "Warning: Unclosed block comment.\n");
        }
        fclose(fp);
        printf("Output saved to file \"%s\"\n",argv[2]);
    }
    else {
        printf("\n  Line\tToken#\t  Content\tCategory\n");
        while (temp != NULL) {
            printf("  %d\t#%d\t  %s\t\t%s\n",temp->token_line,temp->token_number,temp->token_tiexeimesa, temp->token_type);
            temp = temp->next_token;
        }
        if (opening > 0) {
            printf("Warning: Unclosed block comment.\n");
        }
    }

    return 0;
}