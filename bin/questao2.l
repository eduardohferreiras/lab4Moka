%{
#define		NEGADO 3
#define 	OUTRA 	4
%}
delim				[ \t\n\r]
ws					{delim}+
negado				(0*1(0*10*1)*0*)|((1*01*0)*1*)|([01]*[^ \t\n\r01]+[01]*)+
sobraBinario		[01]+
%%
{ws}				{ ;}
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
		}
}