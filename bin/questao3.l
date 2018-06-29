%{
#define		BINMENORQUETRES 2
#define		NEGADO 3
#define 	OUTRA 	4
%}
delim				[ \t\n\r]
ws					{delim}+
binMenorQueTres		[01][01]?[01]?
negado				[01]*00[01]*|[01]*010[01]*|[01]*0110[01]*|([01]*[^ \t\n\r01]+[01]*)+
sobraBinario		[01]+
%%
{ws}				{ ;}
{binMenorQueTres}	{return BINMENORQUETRES;}
{negado}			{return NEGADO;}
{sobraBinario}		{return OUTRA;}
%%
main () {
	int i;
	while (i = yylex ())
		switch (i) {
			case NEGADO:
				printf ("%-20s: Rejeitada\n", yytext); 
				break;
			case OUTRA:
				printf ("%-20s: Aceita \n", yytext);
				break;
			case BINMENORQUETRES:
				printf ("%-20s: Aceita \n", yytext);
				break;
		}
}