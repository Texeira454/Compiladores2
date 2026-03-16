%{
#include <stdio.h>
#include "tokens.h"
#include "tabsimb.h"
int linha = 1;
%}
dig [0-9]
letra [a-zA-Z_]
%%
"int"  {return INT;}
"if"	{return IF;}
"else"	{return ELSE;}
"for"	{return FOR;}
"while"	{return WHILE;}
"char"	{return CHAR;}
"void"	{return VOID;}
"float"	{return FLOAT;}
"return" {return RETURN;}

">="  {return GE;}
"<="  {return GR;}  

"("	  {return '(';}
")"   {return ')';}
"{"	  {return '{';}
"}"   {return '}';}
";"   {return ';';}
"="   {return '=';}
","   {return ',';}

"+"   {return '+';}
"-"   {return '-';}
"/"   {return '/';}
"*"   {return '*';}

"."   {return '.';}
">"   {return '>';}
"<"   {return '<';}
"||"   {return 'OR';}
"!"   {return 'NOT';}
"&&"   {return 'AND';}

{dig}+("."{dig}+)?	{ return NUM;}
{letra}({letra}|{dig})*  { insere(yytext);
                           return ID;}  
[ \t\r] {}
\n	{ linha++; }
.	{printf("erro lexico na linha %d - %s\n",
             linha, yytext); }
%%
#ifndef yywrap
int yywrap() { return 1; }
#endif
void main(int argc, char **argv) {
int token,i=1;	
	yyin = fopen(argv[1],"r");
	token = yylex();
	while(token) {
		printf("%d) %d %s\n", i++, token, yytext);
		token = yylex();
	}
	imprime();
}
