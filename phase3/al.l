%{
	#include "parser.h"
    #include <stdio.h>

    char* string_reformatting(char* initial_string);

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

