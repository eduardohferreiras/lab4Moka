#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "lab4.y"

/* Inclusao de arquivos da biblioteca de C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicao dos atributos dos atomos operadores */

#define 	LT 			1
#define		LE 			2
#define		GT 			3
#define 	GE 			4
#define 	EQ 			5
#define 	NE  		6
#define 	PLUS 		7
#define 	MINUS 		8
#define 	MULT 		9
#define 	DIV 		10
#define 	MOD 		11

/*   Definicao dos tipos de identificadores   */

#define     IDPROG      1
#define     IDVAR       2
#define     IDFUNC      3

/*  Definicao dos tipos de variaveis   */

#define     NAOVAR      0
#define     INTEIRO     1
#define     LOGICO      2
#define     REAL        3
#define     CARACTERE   4
#define     FUNCVOID    5

/*   Definicao de outras constantes   */

#define NCLASSHASH  23
#define VERDADE     1
#define FALSO       0
#define MAXDIMS     3

/*  Strings para nomes dos tipos de identificadores  */

char *nometipid[4] = {" ", "IDPROG", "IDVAR", "IDFUNC"};

/*  Strings para nomes dos tipos de variaveis/funções  */

char *nometipvar[6] = {"NAOVAR",
    "INTEIRO", "LOGICO", "REAL", "CARACTERE", "FUNCVOID"
};

/*    Declaracoes para a tabela de simbolos     */

typedef struct celsimb celsimb;
typedef celsimb *simbolo;
struct celsimb {
    char *cadeia;
    char *escopo;
    int tid, tvar, ndims, dims[MAXDIMS+1];
    char inic, ref, array;
    simbolo prox;
};

/*  Variaveis globais para a tabela de simbolos e analise semantica */

simbolo tabsimb[NCLASSHASH];
simbolo simb;
int tipocorrente;
char *escopocorrente;

/*
    Prototipos das funcoes para a tabela de simbolos
        e analise semantica
 */
int tab = 0;
void InicTabSimb (void);
void ImprimeTabSimb (void);
simbolo InsereSimb (char *, int, int);
int hash (char *);
simbolo ProcuraSimb (char *, char *);
void DeclaracaoRepetida (char *);
void TipoInadequado (char *);
void NaoDeclarado (char *);
void VerificaInicRef (void);
void Incompatibilidade (char *);
void Esperado (char *);
void NaoEsperado (char *);

#line 93 "lab4.y"
typedef union {
	char string[50];
	int atr, valor;
	float valreal;
	char carac;
    simbolo simb;
    int tipoexpr;
    int nsubscr;
    int returnedTypes[5];
    int returnedType;
} YYSTYPE;
#line 115 "y.tab.c"
#define ID 257
#define CHARCT 258
#define STRING 259
#define INTCT 260
#define FLOATCT 261
#define OR 262
#define AND 263
#define NOT 264
#define RELOP 265
#define ADOP 266
#define MULTOP 267
#define NEG 268
#define OPPAR 269
#define CLPAR 270
#define OPBRAK 271
#define CLBRAK 272
#define OPBRACE 273
#define CLBRACE 274
#define OPTRIP 275
#define CLTRIP 276
#define COMMA 277
#define SCOLON 278
#define ASSIGN 279
#define CHAR 280
#define DO 281
#define ELSE 282
#define FALSE 283
#define FLOAT 284
#define IF 285
#define INT 286
#define LOGIC 287
#define READ 288
#define STATEMENTS 289
#define THEN 290
#define TRUE 291
#define VAR 292
#define WHILE 293
#define WRITE 294
#define INVAL 295
#define VOID 296
#define FOR 297
#define CALL 298
#define COLON 299
#define MAIN 300
#define REPEAT 301
#define RETURN 302
#define YYERRCODE 256
short yylhs[] = {                                        -1,
   23,   25,   27,    0,   24,   30,   24,   29,   29,   33,
   31,   32,   32,   32,   32,   32,   34,   36,   34,   38,
   35,   37,   40,   37,   39,   39,   39,   26,   26,   41,
   17,   43,   17,   42,   45,   42,   44,   11,   46,   28,
   47,   14,   48,   13,   12,   12,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   53,   54,   55,
   56,   19,   22,   57,   22,   58,   59,   60,   61,   18,
   62,   63,   64,   65,   20,   66,   67,   68,   69,   70,
   71,   72,   73,   74,   75,   21,   76,   49,   77,   78,
   77,   80,   50,   79,   82,   79,   81,   81,   84,   52,
   83,   83,   16,   86,   16,   87,   88,   89,   51,   85,
   90,   85,    2,   91,    2,    3,   92,    3,    4,   93,
    4,    5,   94,    5,    6,   95,    6,    7,   96,    7,
    8,    8,    8,    8,    8,    8,   97,    8,   98,    8,
    8,  100,    1,    9,  101,    9,   10,   10,   10,  104,
  102,  105,  103,  106,  107,   99,
};
short yylen[] = {                                         2,
    0,    0,    0,    9,    0,    0,    5,    1,    2,    0,
    4,    1,    1,    1,    1,    1,    1,    0,    4,    0,
    3,    0,    0,    4,    1,    3,    5,    0,    2,    2,
    4,    0,    6,    1,    0,    4,    2,    2,    0,    3,
    0,    3,    0,    4,    0,    2,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    0,    0,    0,
    0,    9,    0,    0,    3,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   20,    0,    6,    1,    0,
    4,    0,    6,    1,    0,    4,    1,    1,    0,    7,
    0,    1,    2,    0,    4,    0,    0,    0,    7,    1,
    0,    4,    1,    0,    4,    1,    0,    4,    1,    0,
    3,    1,    0,    4,    1,    0,    4,    1,    0,    4,
    1,    1,    1,    1,    1,    1,    0,    3,    0,    4,
    1,    0,    3,    0,    0,    4,    1,    1,    1,    0,
    4,    0,    4,    0,    0,    6,
};
short yydefred[] = {                                      1,
    0,    0,    0,    2,    0,    0,    3,    6,   28,   10,
    0,    0,    8,    0,   14,   13,   12,   15,   16,   39,
    0,    0,    0,   29,    7,    9,    0,    0,   30,    0,
    4,    0,   20,    0,   17,   40,   41,   38,    0,    0,
   18,   11,    0,   31,    0,   23,   21,    0,   43,   42,
    0,    0,   34,    0,   19,   45,   37,   33,   35,    0,
    0,    0,    0,    0,   24,   44,   57,   87,    0,    0,
    0,   47,   46,   56,   49,   48,   50,   51,   52,   53,
   54,   55,    0,    0,    0,    0,    0,   36,    0,    0,
   92,    0,  103,    0,   59,   67,   72,   77,  142,  107,
    0,    0,    0,   99,    0,  134,  132,  133,  120,  137,
  139,  136,  135,  131,    0,    0,  116,  119,    0,    0,
  128,  141,    0,    0,    0,    0,    0,    0,   27,   89,
    0,   97,    0,    0,   94,    0,    0,    0,    0,    0,
  114,  105,  117,  123,  126,  129,    0,    0,    0,   78,
  145,  143,  108,    0,   90,    0,   95,    0,    0,    0,
  155,  121,  138,    0,    0,    0,    0,    0,    0,    0,
    0,   73,    0,    0,    0,   88,    0,   93,    0,    0,
  111,    0,  140,    0,  118,    0,    0,  130,   61,   69,
    0,   79,    0,    0,    0,  149,    0,   91,   96,  100,
    0,    0,    0,    0,    0,    0,  150,  146,  152,  109,
    0,  156,    0,   70,    0,    0,    0,    0,   64,   62,
   75,    0,    0,    0,    0,   81,   65,    0,    0,    0,
   83,    0,    0,    0,   85,    0,   86,
};
short yydgoto[] = {                                       1,
  114,  133,  116,  117,  118,  119,  120,  121,  152,  194,
   29,   62,   72,   38,   73,   74,   21,   75,   76,   77,
   78,  220,    2,   30,    5,   11,    9,   22,   12,   10,
   13,   51,   14,   34,   35,   48,   47,   40,   61,   54,
   24,   52,   45,   53,   63,   28,   43,   56,   79,   80,
   81,   82,   83,  123,  170,  203,  225,   84,  124,  171,
  204,   85,  125,  191,  215,   86,  126,  173,  206,  222,
  228,  230,  232,  234,  236,   90,  131,  177,  134,  103,
  135,  179,  159,  136,  160,   94,   87,  128,  175,  201,
  165,  166,  138,  167,  168,  169,  139,  140,  122,  127,
  174,  195,  196,  217,  218,  137,  182,
};
short yysindex[] = {                                      0,
    0, -242, -269,    0, -227, -225,    0,    0,    0,    0,
 -277, -201,    0, -193,    0,    0,    0,    0,    0,    0,
 -227, -186, -173,    0,    0,    0, -157, -227,    0, -170,
    0, -161,    0, -214,    0,    0,    0,    0, -142, -155,
    0,    0, -143,    0, -193,    0,    0, -157,    0,    0,
 -125, -232,    0, -129,    0,    0,    0,    0,    0, -136,
 -139,   -9, -193, -118,    0,    0,    0,    0, -121, -122,
 -135,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -140, -131, -151, -148,  -99,    0, -112,  -98,
    0,  -92,    0,  -36,    0,    0,    0,    0,    0,    0,
  -90,  -99,  -49,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -254,  -97,    0,    0, -144,  -88,
    0,    0,  -36,  -36,  -42,  -99,  -91,  -96,    0,    0,
 -192,    0,  -80, -181,    0,  -36,  -84,   -7,   -7,  -36,
    0,    0,    0,    0,    0,    0,  -80,  -80, -105,    0,
    0,    0,    0,  -89,    0,  -81,    0,  -80,  -77,  -79,
    0,    0,    0, -211,  -36,  -36,   -7,   -7,   -7,  -87,
  -82,    0,  -69,   -7,  -36,    0,  -99,    0,  -49,  -72,
    0,  -36,    0,  -97,    0,  -59,  -88,    0,    0,    0,
  -36,    0, -252,  -56,  -60,    0, -244,    0,    0,    0,
  -36,  -52,  -42,  -42,  -80,   -7,    0,    0,    0,    0,
  -80,    0,  -55,    0,  -48,  -59,   -7,   -7,    0,    0,
    0,  -73,  -59,  -59,  -42,    0,    0,  -36,  -80,  -70,
    0,   -7,  -59,  -35,    0,  -42,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,  -14,    0,    0,    0,    0,    0,
    0,   -6,    0,    0,    0,    0,    0,    0,    0,    0,
  -50,    0,    0,    0,    0,    0,    0,  -50,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    8, -154,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -29,
    0, -235,    0,    0,    0,    0,    0,    0,    0,    0,
  -20,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -27,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -195,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -86,    0,    0, -250, -126,
    0,    0,    0,    0, -235,    0, -152,    0,    0,    0,
    0,    0, -172,    0,    0,  -13,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -32,  -22,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -171,    0,   -3,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -13,    0,  -76,    0, -103, -109,    0,    0,    0,
    0,    0,   -4,    0,    3,    0,    0,    0,    0,    0,
    0,    0, -235, -235,   -1,    0,    0,    0,    0,    0,
 -168,    0, -241,    0,    0,  -16,    0,    0,    0,    0,
    0,    0, -251,   15, -235,    0,    0,    0,   -8,    0,
    0,    0,   26,    0,    0, -235,    0,
};
short yygindex[] = {                                      0,
  -85,  -94,  132,  133,  160, -163,  134, -134,    0,    0,
  272,    0,  258,    0, -124,    0,    0,    0,    0,    0,
    0,    0,    0,  298,    0,    0,    0,    0,    0,    0,
  293,   25,    0,    0,  259,    0,    0,    0,    0,    0,
    0,    0,    0,  243,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  129,    0,  127,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 309
short yytable[] = {                                     115,
  149,  100,   15,  186,  163,    4,   16,  141,   17,   18,
  193,  122,  122,  145,    3,   63,  130,  141,   19,  122,
  151,  106,   20,  142,  207,  151,  122,  122,  147,  148,
  122,   63,   63,  210,  188,   23,   63,   58,   27,  122,
  150,  158,  216,   63,   59,  164,   63,    8,  122,   58,
  141,   63,   63,  223,  224,   63,   63,   66,  183,   63,
   63,   76,   41,   42,    6,   71,  142,  142,  233,  142,
  142,  142,   25,  154,  142,  142,  142,  154,  213,  214,
  197,  142,  142,   32,  155,  142,   15,  158,  156,   31,
   16,  198,   17,   18,  142,  157,  205,   98,  110,   33,
  227,  112,   19,  142,   98,  110,  211,   39,  112,  144,
  144,  237,  144,  144,  144,   46,  144,  144,   37,  144,
  144,  145,   22,   22,  144,  144,  144,   44,  144,   49,
   60,   57,   65,  229,   92,  125,  125,  144,  125,  125,
   64,   89,   93,  125,   95,  125,  144,   91,   98,   97,
  125,  125,  127,  127,  125,  127,  127,   99,  124,  124,
  127,   96,  127,  125,  101,  143,  124,  127,  127,  129,
  102,  127,  125,  124,  124,  113,  104,  124,  146,  151,
  127,  141,  153,  113,  161,  115,  124,  172,  176,  127,
  113,  113,  180,  115,  113,  124,  178,  181,  190,  192,
  115,  115,  189,  113,  115,  200,  145,  105,  106,  132,
  107,  108,  113,  115,  109,  208,  209,  212,  110,  111,
  105,  106,  115,  107,  108,  226,  219,  109,  231,  221,
   49,  110,  111,  112,  235,   67,  104,  104,    5,  104,
  104,  113,   25,  104,   26,   68,  112,  104,  104,  105,
  106,   69,  107,  108,  113,   70,  101,   60,   68,   71,
  110,  111,  104,   49,   66,    5,  102,  147,   67,    5,
  104,    5,    5,   10,  148,  112,   74,   10,   68,   10,
   10,    5,   80,  113,   69,    5,  153,   32,   70,   10,
   82,   32,   71,   32,   32,   84,  184,  162,  185,   36,
   50,  187,    7,   32,   26,   88,   55,  199,  202,
};
short yycheck[] = {                                      94,
  125,   87,  280,  167,  139,  275,  284,  262,  286,  287,
  174,  262,  263,  266,  257,  257,  102,  262,  296,  270,
  272,  257,  300,  278,  277,  277,  277,  278,  123,  124,
  281,  273,  274,  278,  169,   11,  278,  270,   14,  290,
  126,  136,  206,  285,  277,  140,  288,  273,  299,  285,
  262,  293,  294,  217,  218,  297,  298,  293,  270,  301,
  302,  297,  277,  278,  292,  301,  262,  263,  232,  265,
  266,  267,  274,  269,  270,  271,  272,  270,  203,  204,
  175,  277,  278,  257,  277,  281,  280,  182,  270,  276,
  284,  177,  286,  287,  290,  277,  191,  270,  270,  257,
  225,  270,  296,  299,  277,  277,  201,  269,  277,  262,
  263,  236,  265,  266,  267,  271,  269,  270,  289,  272,
  265,  266,  277,  278,  277,  278,  279,  270,  281,  273,
  260,  257,  272,  228,  257,  262,  263,  290,  265,  266,
  277,  260,  278,  270,  285,  272,  299,  269,  297,  301,
  277,  278,  262,  263,  281,  265,  266,  257,  262,  263,
  270,  293,  272,  290,  277,  263,  270,  277,  278,  260,
  269,  281,  299,  277,  278,  262,  269,  281,  267,  271,
  290,  262,  279,  270,  269,  262,  290,  293,  278,  299,
  277,  278,  270,  270,  281,  299,  278,  277,  281,  269,
  277,  278,  290,  290,  281,  278,  266,  257,  258,  259,
  260,  261,  299,  290,  264,  272,  277,  270,  268,  269,
  257,  258,  299,  260,  261,  299,  282,  264,  299,  278,
  273,  268,  269,  283,  270,  278,  257,  258,  289,  260,
  261,  291,  272,  264,  272,  288,  283,  268,  269,  257,
  258,  294,  260,  261,  291,  298,  270,  290,  281,  302,
  268,  269,  283,  273,  274,  280,  270,  272,  278,  284,
  291,  286,  287,  280,  272,  283,  278,  284,  288,  286,
  287,  296,  299,  291,  294,  300,  272,  280,  298,  296,
  299,  284,  302,  286,  287,  270,  165,  138,  166,   28,
   43,  168,    5,  296,   12,   63,   48,  179,  182,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 302
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","CHARCT","STRING","INTCT",
"FLOATCT","OR","AND","NOT","RELOP","ADOP","MULTOP","NEG","OPPAR","CLPAR",
"OPBRAK","CLBRAK","OPBRACE","CLBRACE","OPTRIP","CLTRIP","COMMA","SCOLON",
"ASSIGN","CHAR","DO","ELSE","FALSE","FLOAT","IF","INT","LOGIC","READ",
"STATEMENTS","THEN","TRUE","VAR","WHILE","WRITE","INVAL","VOID","FOR","CALL",
"COLON","MAIN","REPEAT","RETURN",
};
char *yyrule[] = {
"$accept : Prog",
"$$1 :",
"$$2 :",
"$$3 :",
"Prog : $$1 ID OPTRIP $$2 Decls $$3 ModList MainMod CLTRIP",
"Decls :",
"$$4 :",
"Decls : VAR OPBRACE $$4 DeclList CLBRACE",
"DeclList : Declaration",
"DeclList : DeclList Declaration",
"$$5 :",
"Declaration : $$5 Type ElemList SCOLON",
"Type : INT",
"Type : FLOAT",
"Type : CHAR",
"Type : LOGIC",
"Type : VOID",
"ElemList : Elem",
"$$6 :",
"ElemList : ElemList COMMA $$6 Elem",
"$$7 :",
"Elem : ID $$7 Dims",
"Dims :",
"$$8 :",
"Dims : OPBRAK $$8 DimList CLBRAK",
"DimList : INTCT",
"DimList : INTCT COMMA INTCT",
"DimList : INTCT COMMA INTCT COMMA INTCT",
"ModList :",
"ModList : ModList Module",
"Module : ModHeader ModBody",
"ModHeader : Type ID OPPAR CLPAR",
"$$9 :",
"ModHeader : Type ID OPPAR $$9 ParamList CLPAR",
"ParamList : Parameter",
"$$10 :",
"ParamList : ParamList COMMA $$10 Parameter",
"Parameter : Type ID",
"ModBody : Decls Stats",
"$$11 :",
"MainMod : MAIN $$11 ModBody",
"$$12 :",
"Stats : STATEMENTS $$12 CompStat",
"$$13 :",
"CompStat : OPBRACE $$13 StatList CLBRACE",
"StatList :",
"StatList : StatList Statement",
"Statement : CompStat",
"Statement : IfStat",
"Statement : WhileStat",
"Statement : RepeatStat",
"Statement : ForStat",
"Statement : ReadStat",
"Statement : WriteStat",
"Statement : AssignStat",
"Statement : CallStat",
"Statement : ReturnStat",
"Statement : SCOLON",
"$$14 :",
"$$15 :",
"$$16 :",
"$$17 :",
"IfStat : $$14 IF $$15 Expression $$16 THEN $$17 Statement ElseStat",
"ElseStat :",
"$$18 :",
"ElseStat : ELSE $$18 Statement",
"$$19 :",
"$$20 :",
"$$21 :",
"$$22 :",
"WhileStat : $$19 WHILE $$20 Expression $$21 DO $$22 Statement",
"$$23 :",
"$$24 :",
"$$25 :",
"$$26 :",
"RepeatStat : $$23 REPEAT $$24 Statement WHILE $$25 Expression $$26 SCOLON",
"$$27 :",
"$$28 :",
"$$29 :",
"$$30 :",
"$$31 :",
"$$32 :",
"$$33 :",
"$$34 :",
"$$35 :",
"$$36 :",
"ForStat : $$27 FOR $$28 Variable $$29 OPPAR $$30 AuxExpr4 $$31 COLON $$32 Expression $$33 COLON $$34 AuxExpr4 $$35 CLPAR $$36 Statement",
"$$37 :",
"ReadStat : READ $$37 OPPAR ReadList CLPAR SCOLON",
"ReadList : Variable",
"$$38 :",
"ReadList : ReadList COMMA $$38 Variable",
"$$39 :",
"WriteStat : WRITE OPPAR $$39 WriteList CLPAR SCOLON",
"WriteList : WriteElem",
"$$40 :",
"WriteList : WriteList COMMA $$40 WriteElem",
"WriteElem : STRING",
"WriteElem : Expression",
"$$41 :",
"CallStat : CALL ID OPPAR $$41 Arguments CLPAR SCOLON",
"Arguments :",
"Arguments : ExprList",
"ReturnStat : RETURN SCOLON",
"$$42 :",
"ReturnStat : RETURN $$42 Expression SCOLON",
"$$43 :",
"$$44 :",
"$$45 :",
"AssignStat : $$43 Variable $$44 ASSIGN $$45 Expression SCOLON",
"ExprList : Expression",
"$$46 :",
"ExprList : ExprList COMMA $$46 Expression",
"Expression : AuxExpr1",
"$$47 :",
"Expression : Expression OR $$47 AuxExpr1",
"AuxExpr1 : AuxExpr2",
"$$48 :",
"AuxExpr1 : AuxExpr1 AND $$48 AuxExpr2",
"AuxExpr2 : AuxExpr3",
"$$49 :",
"AuxExpr2 : NOT $$49 AuxExpr3",
"AuxExpr3 : AuxExpr4",
"$$50 :",
"AuxExpr3 : AuxExpr4 RELOP $$50 AuxExpr4",
"AuxExpr4 : Term",
"$$51 :",
"AuxExpr4 : AuxExpr4 ADOP $$51 Term",
"Term : Factor",
"$$52 :",
"Term : Term MULTOP $$52 Factor",
"Factor : Variable",
"Factor : INTCT",
"Factor : FLOATCT",
"Factor : CHARCT",
"Factor : TRUE",
"Factor : FALSE",
"$$53 :",
"Factor : NEG $$53 Factor",
"$$54 :",
"Factor : OPPAR $$54 Expression CLPAR",
"Factor : FuncCall",
"$$55 :",
"Variable : ID $$55 Subscripts",
"Subscripts :",
"$$56 :",
"Subscripts : OPBRAK $$56 SubscrList CLBRAK",
"SubscrList : AuxExpr4",
"SubscrList : TwoSubscr",
"SubscrList : ThreeSubscr",
"$$57 :",
"TwoSubscr : AuxExpr4 COMMA $$57 AuxExpr4",
"$$58 :",
"ThreeSubscr : TwoSubscr COMMA $$58 AuxExpr4",
"$$59 :",
"$$60 :",
"FuncCall : ID $$59 OPPAR $$60 Arguments CLPAR",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 672 "lab4.y"
#include "lex.yy.c"

tabular () {
    int i;
    for (i = 1; i <= tab; i++)
    printf ("\t");
}

/*  InicTabSimb: Inicializa a tabela de simbolos   */

void InicTabSimb () {
    int i;
    for (i = 0; i < NCLASSHASH; i++)
        tabsimb[i] = NULL;
}

/*
    ProcuraSimb (cadeia, escopo): Procura cadeia na tabela de simbolos;
    Caso ela ali esteja, retorna um ponteiro para sua celula;
    Caso contrario, retorna NULL.
 */

simbolo ProcuraSimb (char *cadeia, char *escopo) {
    simbolo s; int i;
    i = hash (cadeia);
    for (s = tabsimb[i]; (s!=NULL) && ( strcmp(cadeia, s->cadeia)  || strcmp(escopo, s->escopo) );
        s = s->prox);
    //if(s != NULL) printf("iguais: c1:%s c2:%s e1:%s e2:%s",cadeia, s->cadeia, escopo, s->escopo);
    return s;
}

void SetarEscopo (char *escopo) {
    escopocorrente = (char*) malloc ((strlen(escopo)+1)*sizeof(char)); 
    strcpy(escopocorrente, escopo);

}

/*
    InsereSimb (cadeia, tid, tvar): Insere cadeia na tabela de
    simbolos, com tid como tipo de identificador e com tvar como
    tipo de variavel; Retorna um ponteiro para a celula inserida
 */

simbolo InsereSimb (char *cadeia, int tid, int tvar) {
    int i; simbolo aux, s;
    i = hash (cadeia); aux = tabsimb[i];
    s = tabsimb[i] = (simbolo) malloc (sizeof (celsimb));
    s->cadeia = (char*) malloc ((strlen(cadeia)+1) * sizeof(char));
    s->escopo = (char*) malloc ((strlen(escopocorrente)+1) * sizeof(char));
    strcpy (s->cadeia, cadeia);
    strcpy (s->escopo, escopocorrente);
    s->tid = tid;       s->tvar = tvar;
    s->inic = FALSO;    s->ref = FALSO;
    s->prox = aux;  return s;
}

/*
    hash (cadeia): funcao que determina e retorna a classe
    de cadeia na tabela de simbolos implementada por hashing
 */

int hash (char *cadeia) {
    int i, h;
    for (h = i = 0; cadeia[i]; i++) {h += cadeia[i];}
    h = h % NCLASSHASH;
    return h;
}

/* ImprimeTabSimb: Imprime todo o conteudo da tabela de simbolos  */

void ImprimeTabSimb () {
    int i; simbolo s;
    printf ("\n\n   TABELA  DE  SIMBOLOS:\n\n");
    for (i = 0; i < NCLASSHASH; i++)
        if (tabsimb[i]) {
            printf ("Classe %d:\n", i);
            for (s = tabsimb[i]; s!=NULL; s = s->prox){
                printf ("  (%s, %s", s->cadeia,  nometipid[s->tid]);
                if (s->tid == IDVAR){
                    printf (", %s, Escopo: %s, %d, %d",
                        nometipvar[s->tvar], s->escopo, s->inic, s->ref);
                    if (s->array == VERDADE) {
                        int j;
                        printf (", EH ARRAY\n\tndims = %d, dimensoes:", s->ndims);
                        for (j = 1; j <= s->ndims; j++)
                                    printf ("  %d", s->dims[j]);
                    }

                }
                if (s->tid == IDFUNC){
                    printf (", %s, Escopo: %s",nometipvar[s->tvar], s->escopo);
                }
                printf(")\n");
            }
        }
}

/*  Mensagens de erros semanticos  */

void DeclaracaoRepetida (char *s) {
    printf ("\n\n***** Declaracao Repetida: %s *****\n\n", s);
}


void NaoDeclarado (char *s) {
    printf ("\n\n***** Identificador Nao Declarado: %s *****\n\n", s);
}

void TipoInadequado (char *s) {
    printf ("\n\n***** Identificador de Tipo Inadequado: %s *****\n\n", s);
}

void TipoFuncaoInadequado (char *s) {
    printf ("\n\n***** Tipo de Funcao do Identificador Inadequado: %s *****\n\n", s);
}

void VerificaInicRef () {
    int i; simbolo s;

    printf ("\n");
    for (i = 0; i < NCLASSHASH; i++)
        if (tabsimb[i])
            for (s = tabsimb[i]; s!=NULL; s = s->prox)
                if (s->tid == IDVAR) {
                    if (s->inic == FALSO)
                        printf ("%s(Escopo: %s): Nao Inicializada\n", s->cadeia, s->escopo);
                    if (s->ref == FALSO)
                        printf ("%s(Escopo: %s): Nao Referenciada\n", s->cadeia, s->escopo);
                }
}

void Incompatibilidade (char *s) {
    printf ("\n\n***** Incompatibilidade: %s *****\n\n", s);
}

void Esperado (char *s) {
        printf ("\n\n***** Esperado: %s *****\n\n", s);
}

void NaoEsperado (char *s) {
printf ("\n\n***** Nao Esperado: %s *****\n\n", s);
}
#line 715 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 169 "lab4.y"
{InicTabSimb ();}
break;
case 2:
#line 169 "lab4.y"
{
                        printf ("%s {{{\n", yyvsp[-1].string);
                        SetarEscopo("GLOBAL");
                        InsereSimb (yyvsp[-1].string, IDPROG, NAOVAR);
                    }
break;
case 3:
#line 174 "lab4.y"
{SetarEscopo("GLOBAL");}
break;
case 4:
#line 174 "lab4.y"
{
                        printf ("}}}\n");
                        VerificaInicRef ();
                        ImprimeTabSimb ();
                    }
break;
case 6:
#line 181 "lab4.y"
{printf ("var {\n"); tab++;}
break;
case 7:
#line 182 "lab4.y"
{tab--;printf ("}\n");}
break;
case 10:
#line 187 "lab4.y"
{tabular();}
break;
case 11:
#line 187 "lab4.y"
{printf (";\n");}
break;
case 12:
#line 190 "lab4.y"
{printf ("int "); tipocorrente = INTEIRO;}
break;
case 13:
#line 191 "lab4.y"
{printf ("float "); tipocorrente = REAL;}
break;
case 14:
#line 192 "lab4.y"
{printf ("char "); tipocorrente = CARACTERE;}
break;
case 15:
#line 193 "lab4.y"
{printf ("logic "); tipocorrente = LOGICO;}
break;
case 16:
#line 194 "lab4.y"
{printf ("void "); tipocorrente = FUNCVOID;}
break;
case 18:
#line 197 "lab4.y"
{printf (", ");}
break;
case 20:
#line 200 "lab4.y"
{
                        printf ("%s", yyvsp[0].string);
                        if (ProcuraSimb (yyvsp[0].string, escopocorrente) != NULL) {
                            DeclaracaoRepetida (yyvsp[0].string);
                        }
                        else{

                            simb = InsereSimb (yyvsp[0].string, IDVAR, tipocorrente);
                            simb->array = FALSO; simb->ndims = 0;
                        }
                    }
break;
case 23:
#line 214 "lab4.y"
{printf ("[ ");}
break;
case 24:
#line 215 "lab4.y"
{printf ("] "); simb->array = VERDADE;}
break;
case 25:
#line 218 "lab4.y"
{
                            printf ("%d ", yyvsp[0].valor);
                            if (yyvsp[0].valor <= 0) Esperado ("Valor inteiro positivo");
                            simb->ndims = 1;
                            simb->dims[1] = yyvsp[0].valor;
                        }
break;
case 26:
#line 224 "lab4.y"
{
                            printf ("%d , %d ", yyvsp[-2].valor, yyvsp[0].valor);
                            if (yyvsp[-2].valor <= 0 || yyvsp[0].valor <= 0) Esperado ("Valor inteiro positivo");
                            simb->ndims = 2;
                            simb->dims[1] = yyvsp[-2].valor;
                            simb->dims[2] = yyvsp[0].valor;
                        }
break;
case 27:
#line 233 "lab4.y"
{ printf ("%d , %d , %d ", yyvsp[-4].valor, yyvsp[-2].valor, yyvsp[0].valor);
                      if (yyvsp[-4].valor <= 0 || yyvsp[-2].valor <= 0 || yyvsp[0].valor <= 0) Esperado ("Valor inteiro positivo");
                      simb->ndims = 3;
                      simb->dims[1] = yyvsp[-4].valor; simb->dims[2] = yyvsp[-2].valor; simb->dims[3] = yyvsp[0].valor;    }
break;
case 30:
#line 243 "lab4.y"
{
                    if (yyvsp[-1].returnedType == INTEIRO)
                    {
                        if(yyvsp[0].returnedTypes[0] == 1 || yyvsp[0].returnedTypes[REAL] == 1 || yyvsp[0].returnedTypes[LOGICO] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    if (yyvsp[-1].returnedType == REAL)
                    {
                        if(yyvsp[0].returnedTypes[0] == 1 || yyvsp[0].returnedTypes[LOGICO] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    if (yyvsp[-1].returnedType == CARACTERE)
                    {
                        if(yyvsp[0].returnedTypes[0] == 1 || yyvsp[0].returnedTypes[REAL] == 1 || yyvsp[0].returnedTypes[LOGICO] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    if (yyvsp[-1].returnedType == LOGICO)
                    {
                        if(yyvsp[0].returnedTypes[0] == 1 || yyvsp[0].returnedTypes[REAL] == 1 || yyvsp[0].returnedTypes[INTEIRO] == 1 || yyvsp[0].returnedTypes[CARACTERE] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    if (yyvsp[-1].returnedType == FUNCVOID)
                    {
                        if(yyvsp[0].returnedTypes[LOGICO] == 1 || yyvsp[0].returnedTypes[REAL] == 1 || yyvsp[0].returnedTypes[INTEIRO] == 1 || yyvsp[0].returnedTypes[CARACTERE] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    SetarEscopo("GLOBAL");
                }
break;
case 31:
#line 283 "lab4.y"
{ 
                        simb = ProcuraSimb (yyvsp[-2].string, "GLOBAL");
                        if(simb != NULL) DeclaracaoRepetida (yyvsp[-2].string);
                        else { InsereSimb(yyvsp[-2].string, IDFUNC, tipocorrente); }
                        
                        printf ("%s ()\n", yyvsp[-2].string); 
                        yyval.returnedType = tipocorrente; 
                        SetarEscopo(yyvsp[-2].string);

                        }
break;
case 32:
#line 293 "lab4.y"
{ 
                        simb = ProcuraSimb (yyvsp[-1].string, "GLOBAL");
                        if(simb != NULL) DeclaracaoRepetida (yyvsp[-1].string);
                        else { InsereSimb(yyvsp[-1].string, IDFUNC, tipocorrente); }

                        printf ("%s (", yyvsp[-1].string); 
                        yyval.returnedType = tipocorrente; 
                        SetarEscopo(yyvsp[-1].string);

                        }
break;
case 33:
#line 302 "lab4.y"
{printf (")\n"); }
break;
case 35:
#line 306 "lab4.y"
{printf (", ");}
break;
case 37:
#line 309 "lab4.y"
{
                        simb = ProcuraSimb (yyvsp[0].string, escopocorrente);
                        if (simb != NULL) DeclaracaoRepetida (yyvsp[0].string);
                        
                        simb = InsereSimb (yyvsp[0].string, IDVAR, tipocorrente);
                        simb->array = FALSO; simb->ndims = 0;

                        printf ("%s ", yyvsp[0].string);}
break;
case 38:
#line 320 "lab4.y"
{yyval.returnedTypes[0] = yyvsp[0].returnedTypes[0]; yyval.returnedTypes[1] = yyvsp[0].returnedTypes[1]; yyval.returnedTypes[2] = yyvsp[0].returnedTypes[2]; yyval.returnedTypes[3] = yyvsp[0].returnedTypes[3]; yyval.returnedTypes[4] = yyvsp[0].returnedTypes[4];}
break;
case 39:
#line 323 "lab4.y"
{printf("main\n"); SetarEscopo("MAIN");}
break;
case 40:
#line 323 "lab4.y"
{SetarEscopo("GLOBAL");}
break;
case 41:
#line 326 "lab4.y"
{printf ("statements ");tab++;}
break;
case 42:
#line 326 "lab4.y"
{tab--; yyval.returnedTypes[0] = yyvsp[0].returnedTypes[0]; yyval.returnedTypes[1] = yyvsp[0].returnedTypes[1]; yyval.returnedTypes[2] = yyvsp[0].returnedTypes[2]; yyval.returnedTypes[3] = yyvsp[0].returnedTypes[3]; yyval.returnedTypes[4] = yyvsp[0].returnedTypes[4];}
break;
case 43:
#line 330 "lab4.y"
{tab--;tabular();tab++;printf ("{\n");}
break;
case 44:
#line 331 "lab4.y"
{tab--;tabular ();tab++; printf ("}\n"); yyval.returnedTypes[0] = yyvsp[-1].returnedTypes[0]; yyval.returnedTypes[1] = yyvsp[-1].returnedTypes[1]; yyval.returnedTypes[2] = yyvsp[-1].returnedTypes[2]; yyval.returnedTypes[3] = yyvsp[-1].returnedTypes[3]; yyval.returnedTypes[4] = yyvsp[-1].returnedTypes[4];}
break;
case 46:
#line 334 "lab4.y"
{if (yyvsp[0].returnedType != -1) {
                if (yyvsp[0].returnedType < 5) {yyval.returnedTypes[yyvsp[0].returnedType] = 1;}
                else {
                  int i=0;
                  int gambi = yyvsp[0].returnedType-5;
                  for (i=0; i<5; i++) {
                    yyval.returnedTypes[i] = (gambi%10 == 1 || yyvsp[-1].returnedTypes[i]==1) ? 1:0;
                    gambi = gambi/10;
                  }
                }
                }

                }
break;
case 47:
#line 349 "lab4.y"
{yyval.returnedType = (5 + (yyvsp[0].returnedTypes[0]==1 ?1:0) + 10*(yyvsp[0].returnedTypes[1]==1 ?1:0)+ 100*(yyvsp[0].returnedTypes[2]==1 ?1:0)+1000*(yyvsp[0].returnedTypes[3]==1 ?1:0)+10000*(yyvsp[0].returnedTypes[4]==1 ?1:0));}
break;
case 48:
#line 350 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 49:
#line 351 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 50:
#line 352 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 51:
#line 353 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 52:
#line 354 "lab4.y"
{yyval.returnedType = -1;}
break;
case 53:
#line 355 "lab4.y"
{yyval.returnedType = -1;}
break;
case 54:
#line 356 "lab4.y"
{yyval.returnedType = -1;}
break;
case 55:
#line 357 "lab4.y"
{yyval.returnedType = -1;}
break;
case 56:
#line 358 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 57:
#line 359 "lab4.y"
{yyval.returnedType = -1;}
break;
case 58:
#line 362 "lab4.y"
{tabular ();}
break;
case 59:
#line 362 "lab4.y"
{printf ("if ");}
break;
case 60:
#line 362 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){
                            Esperado("Expressao logica no cabecalho do IF");
                        }
                    }
break;
case 61:
#line 366 "lab4.y"
{printf ("then \n"); tab++;}
break;
case 62:
#line 367 "lab4.y"
{
                        int bosta[5] ={0};
                        if (yyvsp[-1].returnedType < 5) {
                            if (yyvsp[-1].returnedType >= 0) {
                                bosta[yyvsp[-1].returnedType] = 1;
                            }
                        } else {
                            int i=0;
                            int gambi = yyvsp[-1].returnedType-5;
                            for (i=0; i<5; i++) {
                                bosta[i] = (gambi%10 == 1) ? 1:0;
                                gambi = gambi/10;
                            }
                        }

                        if (yyvsp[0].returnedType < 5) {
                            if (yyvsp[0].returnedType >= 0) {
                                bosta[yyvsp[0].returnedType] = 1;
                            }
                        } else {
                            int i=0;
                            int gambi = yyvsp[0].returnedType-5;
                            for (i=0; i<5; i++) {
                                bosta[i] = (gambi%10 == 1 || bosta[i]==1) ? 1:0;
                                gambi = gambi/10;
                            }
                        }
                    yyval.returnedType = (5 + (bosta[0]==1 ?1:0) + 10*(bosta[1]==1 ?1:0)+ 100*(bosta[2]==1 ?1:0)+1000*(bosta[3]==1 ?1:0)+10000*(bosta[4]==1 ?1:0));
                    }
break;
case 63:
#line 399 "lab4.y"
{ tab--; yyval.returnedType = -1;}
break;
case 64:
#line 400 "lab4.y"
{tab--; tabular();printf ("else\n ");tab++;}
break;
case 65:
#line 400 "lab4.y"
{tab--; yyval.returnedType = yyvsp[0].returnedType;}
break;
case 66:
#line 405 "lab4.y"
{tabular ();}
break;
case 67:
#line 405 "lab4.y"
{printf ("while ");}
break;
case 68:
#line 405 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){
                            Esperado("Expressao logica no cabecalho do WHILE");
                        }
                    }
break;
case 69:
#line 409 "lab4.y"
{printf ("do \n");tab++;}
break;
case 70:
#line 409 "lab4.y"
{tab--; yyval.returnedType = yyvsp[0].returnedType; }
break;
case 71:
#line 413 "lab4.y"
{tabular ();}
break;
case 72:
#line 413 "lab4.y"
{printf ("repeat \n");tab++;}
break;
case 73:
#line 413 "lab4.y"
{tab--;tabular();printf ("while "); yyval.returnedType = yyvsp[-1].returnedType;}
break;
case 74:
#line 413 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){
                            Esperado("Expressao logica no enncerramento do REPEAT");
                        }
                    }
break;
case 75:
#line 417 "lab4.y"
{printf (";\n");}
break;
case 76:
#line 420 "lab4.y"
{tabular ();}
break;
case 77:
#line 420 "lab4.y"
{printf ("for ");}
break;
case 78:
#line 420 "lab4.y"
{
                            if(yyvsp[0].simb->array == VERDADE || (yyvsp[0].simb->tvar != CARACTERE && yyvsp[0].simb->tvar != INTEIRO)) {
                                Esperado("Variavel de controle do FOR escalar inteira ou escalar caractere");
                            }
                        }
break;
case 79:
#line 424 "lab4.y"
{printf ("( ");}
break;
case 80:
#line 424 "lab4.y"
{
                            if(yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE){
                                Esperado("Primeira expressao do FOR inteira ou caractere");
                            }
                        }
break;
case 81:
#line 428 "lab4.y"
{printf (": ");}
break;
case 82:
#line 429 "lab4.y"
{
                            if(yyvsp[0].tipoexpr != LOGICO){
                                Esperado("Segunda expressao do FOR logica");
                            }
                        }
break;
case 83:
#line 433 "lab4.y"
{printf (": ");}
break;
case 84:
#line 433 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE){
                            Esperado("Terceira expressao do FOR inteira ou caractere");
                            }
                        }
break;
case 85:
#line 437 "lab4.y"
{printf (")\n"); tab++; }
break;
case 86:
#line 437 "lab4.y"
{tab--; yyval.returnedType = yyvsp[0].returnedType;}
break;
case 87:
#line 440 "lab4.y"
{tabular(); printf ("read (");}
break;
case 88:
#line 440 "lab4.y"
{printf (");\n");}
break;
case 90:
#line 444 "lab4.y"
{printf (",");}
break;
case 92:
#line 447 "lab4.y"
{ tabular ();printf ("write ( ");}
break;
case 93:
#line 447 "lab4.y"
{printf (");\n");}
break;
case 95:
#line 450 "lab4.y"
{printf (", ");}
break;
case 97:
#line 453 "lab4.y"
{printf ("%s", yyvsp[0].string);}
break;
case 99:
#line 456 "lab4.y"
{
                        simb = ProcuraSimb (yyvsp[-1].string, "INDEF");
                        if (simb == NULL) NaoDeclarado (yyvsp[-1].string);
                        else if (simb->tid != IDFUNC)   TipoInadequado (yyvsp[-1].string);
                        else if (simb->tvar != FUNCVOID) TipoFuncaoInadequado (yyvsp[-1].string);
                        tabular();
                        printf("call %s(",yyvsp[-1].string);
                    }
break;
case 100:
#line 463 "lab4.y"
{printf (");\n");}
break;
case 103:
#line 470 "lab4.y"
{tabular();printf ("return ;\n"); yyval.returnedType = 0;}
break;
case 104:
#line 471 "lab4.y"
{tabular();printf ("return ");}
break;
case 105:
#line 471 "lab4.y"
{yyval.returnedType = yyvsp[-1].tipoexpr; printf (";\n");}
break;
case 106:
#line 474 "lab4.y"
{tabular ();}
break;
case 107:
#line 475 "lab4.y"
{ if  (yyvsp[0].simb != NULL) yyvsp[0].simb->inic = yyvsp[0].simb->ref = VERDADE;}
break;
case 108:
#line 476 "lab4.y"
{printf (":= ");}
break;
case 109:
#line 477 "lab4.y"
{
                        printf (";\n");
                        if (yyvsp[-5].simb != NULL)
                            if (((yyvsp[-5].simb->tvar == INTEIRO || yyvsp[-5].simb->tvar == CARACTERE) &&
                                (yyvsp[-1].tipoexpr == REAL || yyvsp[-1].tipoexpr == LOGICO)) ||
                                (yyvsp[-5].simb->tvar == REAL && yyvsp[-1].tipoexpr == LOGICO) ||
                                (yyvsp[-5].simb->tvar == LOGICO && yyvsp[-1].tipoexpr != LOGICO))
                                Incompatibilidade ("Lado direito de comando de atribuicao improprio");
                    }
break;
case 111:
#line 490 "lab4.y"
{printf (", ");}
break;
case 114:
#line 494 "lab4.y"
{printf ("|| ");}
break;
case 115:
#line 494 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != LOGICO || yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador or");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 117:
#line 501 "lab4.y"
{printf ("&& ");}
break;
case 118:
#line 501 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != LOGICO || yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador and");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 120:
#line 508 "lab4.y"
{printf ("! ");}
break;
case 121:
#line 508 "lab4.y"
{
                        if (yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador not");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 123:
#line 516 "lab4.y"
{
                        switch (yyvsp[0].atr) {
                            case LT: printf ("< "); break;
                            case LE: printf ("<= "); break;
                            case EQ: printf ("= "); break;
                            case NE: printf ("!= "); break;
                            case GT: printf ("> "); break;
                            case GE: printf (">= "); break;
                        }
                    }
break;
case 124:
#line 525 "lab4.y"
{
                        switch (yyvsp[-2].atr) {
                            case LT: case LE: case GT: case GE:
                                if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != REAL && yyvsp[-3].tipoexpr != CARACTERE || yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != REAL && yyvsp[0].tipoexpr != CARACTERE)
                                    Incompatibilidade   ("Operando improprio para operador relacional");
                                break;
                            case EQ: case NE:
                                if ((yyvsp[-3].tipoexpr == LOGICO || yyvsp[0].tipoexpr == LOGICO) && yyvsp[-3].tipoexpr != yyvsp[0].tipoexpr)
                                    Incompatibilidade ("Operando improprio para operador relacional");
                                break;
                        }
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 126:
#line 541 "lab4.y"
{
                        switch (yyvsp[0].atr) {
                            case PLUS: printf ("+ "); break;
                            case MINUS: printf ("- "); break;
                        }
                    }
break;
case 127:
#line 546 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != REAL && yyvsp[-3].tipoexpr != CARACTERE || yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr!=REAL && yyvsp[0].tipoexpr!=CARACTERE)
                            Incompatibilidade ("Operando improprio para operador aritmetico");
                        if (yyvsp[-3].tipoexpr == REAL || yyvsp[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                        else yyval.tipoexpr = INTEIRO;
                    }
break;
case 129:
#line 555 "lab4.y"
{
                        switch (yyvsp[0].atr) {
                            case MULT: printf ("* "); break;
                            case DIV: printf ("/ "); break;
                            case MOD: printf ("%% "); break;
                        }
                    }
break;
case 130:
#line 561 "lab4.y"
{
                        switch (yyvsp[-2].atr) {
                            case MULT: case DIV:
                                if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != REAL && yyvsp[-3].tipoexpr != CARACTERE
                                    || yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr!=REAL && yyvsp[0].tipoexpr!=CARACTERE)
                                    Incompatibilidade ("Operando improprio para operador aritmetico");
                                if (yyvsp[-3].tipoexpr == REAL || yyvsp[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                                else yyval.tipoexpr = INTEIRO;
                                break;
                            case MOD:
                                if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != CARACTERE
                                    ||  yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                                    Incompatibilidade ("Operando improprio para operador resto");
                                yyval.tipoexpr = INTEIRO;
                                break;
                        }
                    }
break;
case 131:
#line 580 "lab4.y"
{
                        if  (yyvsp[0].simb != NULL) {
                            yyvsp[0].simb->ref  =  VERDADE;
                            yyval.tipoexpr = yyvsp[0].simb->tvar;
                        }
                    }
break;
case 132:
#line 586 "lab4.y"
{
                        printf ("%d ", yyvsp[0].valor);
                        yyval.tipoexpr = INTEIRO;
                    }
break;
case 133:
#line 590 "lab4.y"
{
                        printf ("%g ", yyvsp[0].valreal);
                        yyval.tipoexpr = REAL;
                    }
break;
case 134:
#line 594 "lab4.y"
{
                        printf ("\'%c\' ", yyvsp[0].string);
                        yyval.tipoexpr = CARACTERE;
                    }
break;
case 135:
#line 598 "lab4.y"
{
                        printf ("true ");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 136:
#line 602 "lab4.y"
{
                        printf ("false ");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 137:
#line 606 "lab4.y"
{printf ("~ ");}
break;
case 138:
#line 606 "lab4.y"
{
                        if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != REAL && yyvsp[0].tipoexpr != CARACTERE)
                            Incompatibilidade  ("Operando improprio para menos unario");
                        if (yyvsp[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                        else yyval.tipoexpr = INTEIRO;
                    }
break;
case 139:
#line 612 "lab4.y"
{printf ("( ");}
break;
case 140:
#line 613 "lab4.y"
{printf (") "); yyval.tipoexpr = yyvsp[-1].tipoexpr;}
break;
case 142:
#line 617 "lab4.y"
{
                        printf ("%s ", yyvsp[0].string);
                        simb = ProcuraSimb (yyvsp[0].string, escopocorrente);
                        if( simb == NULL) {simb = ProcuraSimb (yyvsp[0].string, "GLOBAL");}
                        if (simb == NULL) NaoDeclarado (yyvsp[0].string);
                        else if (simb->tid != IDVAR) TipoInadequado (yyvsp[0].string);
                        yyval.simb = simb;
                    }
break;
case 143:
#line 624 "lab4.y"
{
                                    yyval.simb = yyvsp[-1].simb;
                                    if (yyval.simb != NULL) {
                                        if (yyval.simb->array == FALSO && yyvsp[0].nsubscr > 0)
                                            NaoEsperado ("Subscrito\(s)");
                                        else if (yyval.simb->array == VERDADE && yyvsp[0].nsubscr == 0)
                                            Esperado ("Subscrito\(s)");
                                        else if (yyval.simb->ndims != yyvsp[0].nsubscr)
                                            Incompatibilidade ("Numero de subscritos incompativel com declaracao");
                                    }
                        }
break;
case 144:
#line 637 "lab4.y"
{yyval.nsubscr = 0;}
break;
case 145:
#line 638 "lab4.y"
{printf ("[ ");}
break;
case 146:
#line 639 "lab4.y"
{printf ("] "); yyval.nsubscr = yyvsp[-1].nsubscr; }
break;
case 147:
#line 642 "lab4.y"
{
                        yyval.nsubscr = 1;
                        if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                        Incompatibilidade ("Tipo inadequado para subscrito");
                    }
break;
case 148:
#line 647 "lab4.y"
{yyval.nsubscr = 2;}
break;
case 149:
#line 648 "lab4.y"
{yyval.nsubscr =3;}
break;
case 150:
#line 651 "lab4.y"
{printf (", ");}
break;
case 151:
#line 651 "lab4.y"
{ if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != CARACTERE ||
                                                                    yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                                                                    Incompatibilidade ("Tipo inadequado para subscrito");   }
break;
case 152:
#line 657 "lab4.y"
{printf (", ");}
break;
case 153:
#line 657 "lab4.y"
{ if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                        Incompatibilidade ("Tipo inadequado para subscrito"); }
break;
case 154:
#line 662 "lab4.y"
{
                            simb = ProcuraSimb (yyvsp[0].string, "INDEF");
                            if (simb == NULL) NaoDeclarado (yyvsp[0].string);
                            else if (simb->tid != IDFUNC)   TipoInadequado (yyvsp[0].string);
                            else if (simb->tvar == FUNCVOID) TipoFuncaoInadequado (yyvsp[0].string);
                            printf ("%s ", yyvsp[0].string);}
break;
case 155:
#line 668 "lab4.y"
{printf ("(");}
break;
case 156:
#line 668 "lab4.y"
{printf (")");}
break;
#line 1664 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
