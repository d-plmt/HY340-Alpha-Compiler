%{

%}

%%

"if"            {printf("KEYWORD ");}
"else"          {printf("KEYWORD ");}
"while"         {printf("KEYWORD ");}
"for"           {printf("KEYWORD ");}
"function"      {printf("KEYWORD ");}
"return"        {printf("KEYWORD ");}
"break"         {printf("KEYWORD ");}
"continue"      {printf("KEYWORD ");}
"and"           {printf("KEYWORD ");}
"not"           {printf("KEYWORD ");}
"or"            {printf("KEYWORD ");}
"local"         {printf("KEYWORD ");}
"true"          {printf("KEYWORD ");}
"false"         {printf("KEYWORD ");}
"nil"           {printf("KEYWORD ");}
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
"::"             {printf("PUNCTUATION ");}
"."             {printf("PUNCTUATION ");}
".."             {printf("PUNCTUATION ");}

[0-9]+              {return printf("INT ");}
[0-9]+\.{1}[0-9]+   {return printf("REAL ");}
(\")([.\\]|[^"]|(\\\"))*(\")   {return printf("STRING ");}
[A-Za-z]{1}[A-Za-z0-9_]*    {return printf("IDENTIFIER ");}
[ ]                 {/*do nothing*/}
.                   {return printf("-1");}
(\/){1}(\/){1}[^\\\n]*[\\\n]{1}   {return printf("LINE COMMENT ");}
(\/){1}(\*){1}*.*(\*){1}(\/){1}    {return printf("COMMENT ");}
%%

yywrap() {}

int main() {

    while (1) {
        int a = yylex();
        if (a == -1) {
            return -1;
            
        }
    }
    return 1;
}