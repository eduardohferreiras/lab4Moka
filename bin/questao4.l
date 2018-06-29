%{
#include 	<string.h>
#define		ID		1
#define		CTINT	2
#define		CTHEX	3
#define		CTREAL	4
#define		OPREL	5
#define		OPAD	6
#define		OPMULT	7
#define		ABPAR	8
#define		FPAR	9
#define		INVAL	10
union {
	char string[50];
	int atr, valor;
	float real;
	char carac;
} yylval;
%}
delim		[ \t\n\r]
ws			{delim}+
digito		[0-9]
letra		[A-Za-z]
digitoHex 	[0123456789abcdef]
cthex 		H{digitoHex}+
underMasc	\_[A-Z]
letDig		{letra}|{digito}
masc 		[A-Z]
id			({masc}({letDig}*{underMasc}*{letDig}*)*[a-z123456789])|masc
ctreal 		{digito}+\.{digito}*
ctint		{digito}+
stringMin	[a-z_]*
invalido	[^a-zA-Z0-9<>=!+\-*/()\.\_]
%%
{ws}		{ ;}
"(" 		{return ABPAR;}
")" 		{return FPAR;}
{cthex}		{strcpy (yylval.string, yytext); memmove(yylval.string, yylval.string+1, strlen(yylval.string))  ; yylval.valor = (int)strtol(yylval.string, NULL, 16); return CTHEX;}
{id}		{strcpy (yylval.string, yytext); return ID;}
{ctreal}	{yylval.real = atof(yytext); return CTREAL;}
{ctint}		{yylval.valor = atoi(yytext); return CTINT;}
"+"			{strcpy (yylval.string, "MAIS"); return OPAD;}
"-"			{strcpy (yylval.string, "MENOS"); return OPAD;}
"*"			{strcpy (yylval.string, "VEZES"); return OPMULT;}
"/"			{strcpy (yylval.string, "DIV"); return OPMULT;}
"<"			{strcpy (yylval.string, "MENOR"); return OPREL;}
"<="		{strcpy (yylval.string, "MENIG"); return OPREL;}
">"			{strcpy (yylval.string, "MAIOR"); return OPREL;}
">="		{strcpy (yylval.string, "MAIG"); return OPREL;}
"=="		{strcpy (yylval.string, "IGUAL"); return OPREL;}
"!="		{strcpy (yylval.string, "DIFER"); return OPREL;}
"="			{ ;}
"!"         { ;}
{invalido}	{strcpy (yylval.string, yytext); return INVAL;}
{stringMin} { ;}
%%
main () {
	char tipos[10][50];
	strcpy (tipos[1], "ID");
	strcpy (tipos[2], "CTINT");
	strcpy (tipos[3], "CTHEX");
	strcpy (tipos[4], "CTREAL");
	strcpy (tipos[5], "OPREL");
	strcpy (tipos[6], "OPAD");
	strcpy (tipos[7], "OPMULT");
	strcpy (tipos[8], "ABPAR");
	strcpy (tipos[9], "FPAR");
	strcpy (tipos[10], "INVAL");

	int i;
	printf ("\n         texto      |         tipo       |       atributo     \n");
	printf ("--------------------------------------------------------------\n");
	while (i = yylex ()) {
		printf ("%20s|%20s|", yytext, tipos[i]);
		switch (i) {
			case ID:
				printf ("%20s", yylval.string); break;
			case INVAL:
				printf ("%20s", yylval.string); break;
			case CTINT:
				printf ("%20d", yylval.valor); break;
			case CTREAL:
				printf ("%20f", yylval.real); break;
			case CTHEX:
				printf ("%20d", yylval.valor); break;
			case OPREL:
				printf ("%20s", yylval.string); break;
		}
		printf ("\n");
	}
} 