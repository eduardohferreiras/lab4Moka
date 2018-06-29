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
    int tid, tvar, ndims, dims[MAXDIMS+1];
    char inic, ref, array;
    simbolo prox;
};

/*  Variaveis globais para a tabela de simbolos e analise semantica */

simbolo tabsimb[NCLASSHASH];
simbolo simb;
int tipocorrente;

/*
    Prototipos das funcoes para a tabela de simbolos
        e analise semantica
 */
int tab = 0;
void InicTabSimb (void);
void ImprimeTabSimb (void);
simbolo InsereSimb (char *, int, int);
int hash (char *);
simbolo ProcuraSimb (char *);
void DeclaracaoRepetida (char *);
void TipoInadequado (char *);
void NaoDeclarado (char *);
void VerificaInicRef (void);
void Incompatibilidade (char *);
void Esperado (char *);
void NaoEsperado (char *);

#line 91 "lab4.y"
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
#line 113 "y.tab.c"
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
   18,   20,    0,   19,   24,   19,   23,   23,   27,   25,
   26,   26,   26,   26,   26,   28,   30,   28,   32,   29,
   31,   34,   31,   33,   33,   33,   21,   21,   35,   17,
   37,   17,   36,   39,   36,   38,   11,   40,   22,   41,
   14,   42,   13,   12,   12,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   51,   52,   53,   54,
   43,   55,   56,   57,   55,   58,   59,   60,   61,   44,
   62,   63,   64,   65,   45,   66,   67,   68,   69,   70,
   71,   72,   73,   74,   75,   46,   76,   47,   77,   78,
   77,   80,   48,   79,   82,   79,   81,   81,   84,   50,
   83,   83,   86,   16,   87,   16,   88,   89,   90,   49,
   85,   91,   85,    2,   92,    2,    3,   93,    3,    4,
   94,    4,    5,   95,    5,    6,   96,    6,    7,   97,
    7,    8,    8,    8,    8,    8,    8,   98,    8,   99,
    8,    8,  101,    1,    9,  102,    9,   10,   10,   10,
  105,  103,  106,  104,  107,  108,  100,
};
short yylen[] = {                                         2,
    0,    0,    8,    0,    0,    5,    1,    2,    0,    4,
    1,    1,    1,    1,    1,    1,    0,    4,    0,    3,
    0,    0,    4,    1,    3,    5,    0,    2,    2,    4,
    0,    6,    1,    0,    4,    2,    2,    0,    3,    0,
    3,    0,    4,    0,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,
    9,    0,    0,    0,    4,    0,    0,    0,    0,    8,
    0,    0,    0,    0,    9,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   20,    0,    6,    1,    0,
    4,    0,    6,    1,    0,    4,    1,    1,    0,    7,
    0,    1,    0,    3,    0,    4,    0,    0,    0,    7,
    1,    0,    4,    1,    0,    4,    1,    0,    4,    1,
    0,    3,    1,    0,    4,    1,    0,    4,    1,    0,
    4,    1,    1,    1,    1,    1,    1,    0,    3,    0,
    4,    1,    0,    3,    0,    0,    4,    1,    1,    1,
    0,    4,    0,    4,    0,    0,    6,
};
short yydefred[] = {                                      1,
    0,    0,    0,    2,    0,    0,   27,    5,    0,    9,
   13,   12,   11,   14,   15,   38,    0,    0,    0,   28,
    0,    7,    0,    0,   29,    0,    3,    0,    6,    8,
    0,   39,   40,   37,    0,   19,    0,   16,    0,   30,
    0,    0,   17,   10,   42,   41,    0,    0,   33,   22,
   20,    0,   44,   36,   32,   34,    0,   18,    0,    0,
    0,    0,   43,   56,   87,    0,    0,    0,   46,   45,
   55,   47,   48,   49,   50,   51,   52,   53,   54,    0,
    0,    0,    0,    0,   35,    0,   23,    0,   92,    0,
    0,    0,   58,   67,   72,   77,  143,  108,    0,    0,
    0,   99,  104,    0,  135,  133,  134,  121,  138,  140,
  137,  136,  132,    0,    0,  117,  120,    0,    0,  129,
  142,    0,    0,    0,    0,    0,    0,    0,   89,    0,
   97,    0,    0,   94,    0,    0,    0,    0,    0,  115,
  106,  118,  124,  127,  130,    0,    0,    0,   78,  146,
  144,  109,   26,    0,   90,    0,   95,    0,    0,    0,
  156,  122,  139,    0,    0,    0,    0,    0,    0,    0,
    0,   73,    0,    0,    0,   88,    0,   93,    0,    0,
  112,    0,  141,    0,  119,    0,    0,  131,   60,   69,
    0,   79,    0,    0,    0,  150,    0,   91,   96,  100,
    0,    0,    0,    0,    0,    0,  151,  147,  153,  110,
    0,  157,    0,   70,    0,    0,    0,    0,   63,   61,
   75,    0,    0,    0,    0,   81,   64,    0,   65,    0,
    0,   83,    0,    0,    0,   85,    0,   86,
};
short yydgoto[] = {                                       1,
  113,  132,  115,  116,  117,  118,  119,  120,  151,  194,
   25,   59,   69,   34,   70,   71,   17,    2,   26,    5,
    9,   18,   21,   10,   22,   47,   23,   37,   38,   52,
   51,   42,   62,   57,   20,   48,   41,   49,   60,   24,
   39,   53,   72,   73,   74,   75,   76,   77,   78,   79,
   80,  122,  170,  203,  220,  225,  229,   81,  123,  171,
  204,   82,  124,  191,  215,   83,  125,  173,  206,  222,
  228,  231,  233,  235,  237,   88,  130,  177,  133,  101,
  134,  179,  159,  135,  160,   91,   92,   84,  127,  175,
  201,  165,  166,  137,  167,  168,  169,  138,  139,  121,
  126,  174,  195,  196,  217,  218,  136,  182,
};
short yysindex[] = {                                      0,
    0, -247, -224,    0, -227, -206,    0,    0, -258,    0,
    0,    0,    0,    0,    0,    0, -227, -205, -168,    0,
 -182,    0,    3, -227,    0, -194,    0, -156,    0,    0,
 -135,    0,    0,    0, -152,    0, -265,    0, -148,    0,
    3, -142,    0,    0,    0,    0, -127, -263,    0,    0,
    0, -135,    0,    0,    0,    0, -128,    0,  -25,    3,
 -143, -137,    0,    0,    0, -124, -108,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -133,
 -140, -144, -131,  -90,    0, -102,    0, -100,    0,  -97,
 -103,  -33,    0,    0,    0,    0,    0,    0, -107,  -90,
  -62,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -257,  -87,    0,    0, -154,  -83,    0,
    0,  -33,  -33,  -18,  -90,  -91,  -94,  -74,    0, -220,
    0,  -75, -195,    0,  -33,  -79,  -17,  -17,  -33,    0,
    0,    0,    0,    0,    0,  -75,  -75,  -88,    0,    0,
    0,    0,    0,  -85,    0,  -84,    0,  -75,  -67,  -73,
    0,    0,    0, -230,  -33,  -33,  -17,  -17,  -17,  -82,
  -72,    0,  -56,  -17,  -33,    0,  -90,    0,  -62,  -61,
    0,  -33,    0,  -87,    0,  -50,  -83,    0,    0,    0,
  -33,    0, -262,  -53,  -57,    0, -245,    0,    0,    0,
  -33,  -44,  -18,  -18,  -75,  -17,    0,    0,    0,    0,
  -75,    0,  -52,    0,  -45,  -50,  -17,  -17,    0,    0,
    0,  -65,  -50,  -50,  -18,    0,    0,  -33,    0,  -75,
  -60,    0,  -17,  -50,  -32,    0,  -18,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,   -5,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -47,    0,    0,    0,
   14,    0,    0,  -47,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   22,    0,    0,    0,    0,    0,
    0, -157,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -237,    0,
  -26,    0,    0,    0,    0,    0,    0,  -46,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -16,    0,
    0,    0,    0, -193,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -254,    0,    0, -116, -139,    0,
    0,    0,    0, -237,    0, -162,    0,    0,    0,    0,
    0, -184,    0,    0,  -23,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -36,  -24,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -183,    0,  -11,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -23,    0,  -89,    0,  -99, -122,    0,    0,    0,
    0,    0,  -10,    0,   -8,    0,    0,    0,    0,    0,
    0,    0, -237, -237,  -13,    0,    0,    0,    0,    0,
 -179,    0, -239,    0,    0,  -38,    0,    0,    0,    0,
    0,    0, -211,   -4, -237,    0,    0,    0,    0,  -28,
    0,    0,    0,   -3,    0,    0, -237,    0,
};
short yygindex[] = {                                      0,
  -81,  -92,  107,  112,  148, -165,  118, -132,    0,    0,
  264,    0,  253,    0, -123,    0,    0,    0,  288,    0,
    0,    0,    0,    0,  275,    2,    0,    0,  245,    0,
    0,    0,    0,    0,    0,    0,    0,  243,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  125,    0,  123,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 318
short yytable[] = {                                     114,
  148,  186,   98,  144,  140,  163,   55,  114,  193,    3,
   19,   43,   44,   56,  207,  114,  140,   62,  129,  107,
  141,   11,  114,  114,   31,   12,  114,   13,   14,  146,
  147,  140,  210,   62,   62,  114,  188,   15,   62,  183,
  216,   16,  158,  149,  114,   62,  164,   57,   62,  154,
    4,  223,  224,   62,   62,   66,  155,   62,   62,   76,
  152,   62,   62,   71,    6,  152,    8,  234,  143,  143,
   27,  143,  143,  143,  156,  155,  143,  143,  143,  213,
  214,  157,  197,  143,  143,   98,  111,  143,   28,  158,
  113,   29,   98,  111,   33,  198,  143,  113,  205,  145,
  145,  227,  145,  145,  145,  143,  145,  145,  211,  145,
  143,  144,   35,  238,  145,  145,  145,   40,  145,   21,
   21,   36,  126,  126,   45,  126,  126,  145,   50,   54,
  126,   61,  126,   86,   87,  230,  145,  126,  126,  128,
  128,  126,  128,  128,   89,  123,  123,  128,   90,  128,
  126,   93,   94,  123,  128,  128,   95,   99,  128,  126,
  123,  123,  125,  125,  123,   96,   97,  128,  100,  128,
  125,  102,  116,  123,  103,  142,  128,  125,  125,  150,
  116,  125,  123,  145,  152,  153,  140,  116,  116,  161,
  125,  116,  176,  178,  104,  105,  131,  106,  107,  125,
  116,  108,  180,  181,  172,  109,  110,  189,  190,  116,
  105,  105,  192,  105,  105,  144,  200,  105,  208,  209,
  111,  105,  105,  104,  105,  212,  106,  107,  112,  219,
  108,  103,  221,  226,  109,  110,  105,  236,  232,  104,
  105,    4,  106,  107,  105,   24,  101,   45,   63,  111,
  109,  110,   64,   59,   45,   25,   68,  112,  102,   64,
   80,  148,   65,  149,   74,  111,   84,  154,   66,   65,
   82,  184,   67,  112,    4,   66,   68,  185,    4,   67,
    4,    4,   11,   68,  162,  187,   12,   32,   13,   14,
    4,   46,    7,    9,    4,   30,   58,    9,   15,    9,
    9,   31,   85,  199,  202,   31,    0,   31,   31,    9,
    0,    0,    0,    0,    0,    0,    0,   31,
};
short yycheck[] = {                                      92,
  124,  167,   84,  266,  262,  138,  270,  262,  174,  257,
    9,  277,  278,  277,  277,  270,  262,  257,  100,  257,
  278,  280,  277,  278,   23,  284,  281,  286,  287,  122,
  123,  262,  278,  273,  274,  290,  169,  296,  278,  270,
  206,  300,  135,  125,  299,  285,  139,  285,  288,  270,
  275,  217,  218,  293,  294,  293,  277,  297,  298,  297,
  272,  301,  302,  301,  292,  277,  273,  233,  262,  263,
  276,  265,  266,  267,  270,  269,  270,  271,  272,  203,
  204,  277,  175,  277,  278,  270,  270,  281,  257,  182,
  270,  274,  277,  277,  289,  177,  290,  277,  191,  262,
  263,  225,  265,  266,  267,  299,  269,  270,  201,  272,
  265,  266,  269,  237,  277,  278,  279,  270,  281,  277,
  278,  257,  262,  263,  273,  265,  266,  290,  271,  257,
  270,  260,  272,  277,  272,  228,  299,  277,  278,  262,
  263,  281,  265,  266,  269,  262,  263,  270,  257,  272,
  290,  285,  293,  270,  277,  278,  301,  260,  281,  299,
  277,  278,  262,  263,  281,  297,  257,  290,  269,  277,
  270,  269,  262,  290,  278,  263,  299,  277,  278,  271,
  270,  281,  299,  267,  279,  260,  262,  277,  278,  269,
  290,  281,  278,  278,  257,  258,  259,  260,  261,  299,
  290,  264,  270,  277,  293,  268,  269,  290,  281,  299,
  257,  258,  269,  260,  261,  266,  278,  264,  272,  277,
  283,  268,  269,  257,  258,  270,  260,  261,  291,  282,
  264,  278,  278,  299,  268,  269,  283,  270,  299,  257,
  258,  289,  260,  261,  291,  272,  270,  273,  274,  283,
  268,  269,  278,  290,  273,  272,  281,  291,  270,  278,
  299,  272,  288,  272,  278,  283,  270,  272,  294,  288,
  299,  165,  298,  291,  280,  294,  302,  166,  284,  298,
  286,  287,  280,  302,  137,  168,  284,   24,  286,  287,
  296,   39,    5,  280,  300,   21,   52,  284,  296,  286,
  287,  280,   60,  179,  182,  284,   -1,  286,  287,  296,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  296,
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
"Prog : $$1 ID OPTRIP $$2 Decls ModList MainMod CLTRIP",
"Decls :",
"$$3 :",
"Decls : VAR OPBRACE $$3 DeclList CLBRACE",
"DeclList : Declaration",
"DeclList : DeclList Declaration",
"$$4 :",
"Declaration : $$4 Type ElemList SCOLON",
"Type : INT",
"Type : FLOAT",
"Type : CHAR",
"Type : LOGIC",
"Type : VOID",
"ElemList : Elem",
"$$5 :",
"ElemList : ElemList COMMA $$5 Elem",
"$$6 :",
"Elem : ID $$6 Dims",
"Dims :",
"$$7 :",
"Dims : OPBRAK $$7 DimList CLBRAK",
"DimList : INTCT",
"DimList : INTCT COMMA INTCT",
"DimList : INTCT COMMA INTCT COMMA INTCT",
"ModList :",
"ModList : ModList Module",
"Module : ModHeader ModBody",
"ModHeader : Type ID OPPAR CLPAR",
"$$8 :",
"ModHeader : Type ID OPPAR $$8 ParamList CLPAR",
"ParamList : Parameter",
"$$9 :",
"ParamList : ParamList COMMA $$9 Parameter",
"Parameter : Type ID",
"ModBody : Decls Stats",
"$$10 :",
"MainMod : MAIN $$10 ModBody",
"$$11 :",
"Stats : STATEMENTS $$11 CompStat",
"$$12 :",
"CompStat : OPBRACE $$12 StatList CLBRACE",
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
"$$13 :",
"$$14 :",
"$$15 :",
"$$16 :",
"IfStat : $$13 IF $$14 Expression $$15 THEN $$16 Statement ElseStat",
"ElseStat :",
"$$17 :",
"$$18 :",
"ElseStat : ELSE $$17 Statement $$18",
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
"$$42 :",
"ReturnStat : RETURN $$42 SCOLON",
"$$43 :",
"ReturnStat : RETURN $$43 Expression SCOLON",
"$$44 :",
"$$45 :",
"$$46 :",
"AssignStat : $$44 Variable $$45 ASSIGN $$46 Expression SCOLON",
"ExprList : Expression",
"$$47 :",
"ExprList : ExprList COMMA $$47 Expression",
"Expression : AuxExpr1",
"$$48 :",
"Expression : Expression OR $$48 AuxExpr1",
"AuxExpr1 : AuxExpr2",
"$$49 :",
"AuxExpr1 : AuxExpr1 AND $$49 AuxExpr2",
"AuxExpr2 : AuxExpr3",
"$$50 :",
"AuxExpr2 : NOT $$50 AuxExpr3",
"AuxExpr3 : AuxExpr4",
"$$51 :",
"AuxExpr3 : AuxExpr4 RELOP $$51 AuxExpr4",
"AuxExpr4 : Term",
"$$52 :",
"AuxExpr4 : AuxExpr4 ADOP $$52 Term",
"Term : Factor",
"$$53 :",
"Term : Term MULTOP $$53 Factor",
"Factor : Variable",
"Factor : INTCT",
"Factor : FLOATCT",
"Factor : CHARCT",
"Factor : TRUE",
"Factor : FALSE",
"$$54 :",
"Factor : NEG $$54 Factor",
"$$55 :",
"Factor : OPPAR $$55 Expression CLPAR",
"Factor : FuncCall",
"$$56 :",
"Variable : ID $$56 Subscripts",
"Subscripts :",
"$$57 :",
"Subscripts : OPBRAK $$57 SubscrList CLBRAK",
"SubscrList : AuxExpr4",
"SubscrList : TwoSubscr",
"SubscrList : ThreeSubscr",
"$$58 :",
"TwoSubscr : AuxExpr4 COMMA $$58 AuxExpr4",
"$$59 :",
"ThreeSubscr : TwoSubscr COMMA $$59 AuxExpr4",
"$$60 :",
"$$61 :",
"FuncCall : ID $$60 OPPAR $$61 Arguments CLPAR",
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
#line 598 "lab4.y"
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
    ProcuraSimb (cadeia): Procura cadeia na tabela de simbolos;
    Caso ela ali esteja, retorna um ponteiro para sua celula;
    Caso contrario, retorna NULL.
 */

simbolo ProcuraSimb (char *cadeia) {
    simbolo s; int i;
    i = hash (cadeia);
    for (s = tabsimb[i]; (s!=NULL) && strcmp(cadeia, s->cadeia);
        s = s->prox);
    return s;
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
    strcpy (s->cadeia, cadeia);
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
                    printf (", %s, %d, %d",
                        nometipvar[s->tvar], s->inic, s->ref);
                    if (s->array == VERDADE) {
                        int j;
                        printf (", EH ARRAY\n\tndims = %d, dimensoes:", s->ndims);
                        for (j = 1; j <= s->ndims; j++)
                                    printf ("  %d", s->dims[j]);
                    }

                }
                if (s->tid == IDFUNC){
                    printf (", %s",nometipvar[s->tvar]);
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

void VerificaInicRef () {
    int i; simbolo s;

    printf ("\n");
    for (i = 0; i < NCLASSHASH; i++)
        if (tabsimb[i])
            for (s = tabsimb[i]; s!=NULL; s = s->prox)
                if (s->tid == IDVAR) {
                    if (s->inic == FALSO)
                        printf ("%s: Nao Inicializada\n", s->cadeia);
                    if (s->ref == FALSO)
                        printf ("%s: Nao Referenciada\n", s->cadeia);
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

#line 703 "y.tab.c"
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
#line 167 "lab4.y"
{InicTabSimb ();}
break;
case 2:
#line 167 "lab4.y"
{
                        printf ("%s {{{\n", yyvsp[-1].string);
                        InsereSimb (yyvsp[-1].string, IDPROG, NAOVAR);
                    }
break;
case 3:
#line 171 "lab4.y"
{
                        printf ("}}}\n");
                        VerificaInicRef ();
                        ImprimeTabSimb ();
                    }
break;
case 5:
#line 178 "lab4.y"
{printf ("var {\n"); tab++;}
break;
case 6:
#line 179 "lab4.y"
{tab--;printf ("}\n");}
break;
case 9:
#line 184 "lab4.y"
{tabular();}
break;
case 10:
#line 184 "lab4.y"
{printf (";\n");}
break;
case 11:
#line 187 "lab4.y"
{printf ("int "); tipocorrente = INTEIRO;}
break;
case 12:
#line 188 "lab4.y"
{printf ("float "); tipocorrente = REAL;}
break;
case 13:
#line 189 "lab4.y"
{printf ("char "); tipocorrente = CARACTERE;}
break;
case 14:
#line 190 "lab4.y"
{printf ("logic "); tipocorrente = LOGICO;}
break;
case 15:
#line 191 "lab4.y"
{printf ("void "); tipocorrente = FUNCVOID;}
break;
case 17:
#line 194 "lab4.y"
{printf (", ");}
break;
case 19:
#line 197 "lab4.y"
{
                        printf ("%s", yyvsp[0].string);
                        if (ProcuraSimb (yyvsp[0].string) != NULL)
                            DeclaracaoRepetida (yyvsp[0].string);
                        else{

                            simb = InsereSimb (yyvsp[0].string, IDVAR, tipocorrente);
                            simb->array = FALSO; simb->ndims = 0;
                        }
                    }
break;
case 22:
#line 210 "lab4.y"
{printf ("[ ");}
break;
case 23:
#line 211 "lab4.y"
{printf ("] "); simb->array = VERDADE;}
break;
case 24:
#line 214 "lab4.y"
{
                            printf ("%d ", yyvsp[0].valor);
                            if (yyvsp[0].valor <= 0) Esperado ("Valor inteiro positivo");
                            simb->ndims = 1;
                            simb->dims[1] = yyvsp[0].valor;
                        }
break;
case 25:
#line 220 "lab4.y"
{ 
                            printf ("%d , %d ", yyvsp[-2].valor, yyvsp[0].valor);
                            if (yyvsp[-2].valor <= 0 || yyvsp[0].valor <= 0) Esperado ("Valor inteiro positivo");
                            simb->ndims = 2;
                            simb->dims[1] = yyvsp[-2].valor;
                            simb->dims[2] = yyvsp[0].valor;
                        }
break;
case 26:
#line 229 "lab4.y"
{ printf ("%d , %d , %d ", yyvsp[-4].valor, yyvsp[-2].valor, yyvsp[0].valor);
                      if (yyvsp[-4].valor <= 0 || yyvsp[-2].valor <= 0 || yyvsp[0].valor <= 0) Esperado ("Valor inteiro positivo");
                      simb->ndims = 3;
                      simb->dims[1] = yyvsp[-4].valor; simb->dims[2] = yyvsp[-2].valor; simb->dims[3] = yyvsp[0].valor;    }
break;
case 29:
#line 239 "lab4.y"
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
                }
break;
case 30:
#line 278 "lab4.y"
{ InsereSimb(yyvsp[-2].string, IDFUNC, tipocorrente); printf ("%s ()\n", yyvsp[-2].string); yyval.returnedType = tipocorrente;}
break;
case 31:
#line 279 "lab4.y"
{ InsereSimb(yyvsp[-1].string, IDFUNC, tipocorrente); printf ("%s (", yyvsp[-1].string); yyval.returnedType = tipocorrente; }
break;
case 32:
#line 279 "lab4.y"
{printf (")\n"); }
break;
case 34:
#line 283 "lab4.y"
{printf (", ");}
break;
case 36:
#line 286 "lab4.y"
{printf ("%s ", yyvsp[0].string);}
break;
case 37:
#line 290 "lab4.y"
{yyval.returnedTypes[0] = yyvsp[0].returnedTypes[0]; yyval.returnedTypes[1] = yyvsp[0].returnedTypes[1]; yyval.returnedTypes[2] = yyvsp[0].returnedTypes[2]; yyval.returnedTypes[3] = yyvsp[0].returnedTypes[3]; yyval.returnedTypes[4] = yyvsp[0].returnedTypes[4];}
break;
case 38:
#line 293 "lab4.y"
{printf("main\n");}
break;
case 40:
#line 296 "lab4.y"
{printf ("statements ");tab++;}
break;
case 41:
#line 296 "lab4.y"
{tab--; yyval.returnedTypes[0] = yyvsp[0].returnedTypes[0]; yyval.returnedTypes[1] = yyvsp[0].returnedTypes[1]; yyval.returnedTypes[2] = yyvsp[0].returnedTypes[2]; yyval.returnedTypes[3] = yyvsp[0].returnedTypes[3]; yyval.returnedTypes[4] = yyvsp[0].returnedTypes[4];}
break;
case 42:
#line 300 "lab4.y"
{tab--;tabular();tab++;printf ("{\n");}
break;
case 43:
#line 301 "lab4.y"
{tab--;tabular ();tab++; printf ("}\n"); yyval.returnedTypes[0] = yyvsp[-1].returnedTypes[0]; yyval.returnedTypes[1] = yyvsp[-1].returnedTypes[1]; yyval.returnedTypes[2] = yyvsp[-1].returnedTypes[2]; yyval.returnedTypes[3] = yyvsp[-1].returnedTypes[3]; yyval.returnedTypes[4] = yyvsp[-1].returnedTypes[4];}
break;
case 45:
#line 304 "lab4.y"
{if (yyvsp[0].returnedType != -1) {yyval.returnedTypes[yyvsp[0].returnedType] = 1;}}
break;
case 47:
#line 308 "lab4.y"
{yyval.returnedType = -1;}
break;
case 48:
#line 309 "lab4.y"
{yyval.returnedType = -1;}
break;
case 49:
#line 310 "lab4.y"
{yyval.returnedType = -1;}
break;
case 50:
#line 311 "lab4.y"
{yyval.returnedType = -1;}
break;
case 51:
#line 312 "lab4.y"
{yyval.returnedType = -1;}
break;
case 52:
#line 313 "lab4.y"
{yyval.returnedType = -1;}
break;
case 53:
#line 314 "lab4.y"
{yyval.returnedType = -1;}
break;
case 54:
#line 315 "lab4.y"
{yyval.returnedType = -1;}
break;
case 55:
#line 316 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 56:
#line 317 "lab4.y"
{yyval.returnedType = -1;}
break;
case 57:
#line 320 "lab4.y"
{tabular ();}
break;
case 58:
#line 320 "lab4.y"
{printf ("if ");}
break;
case 59:
#line 320 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){
                            Esperado("Expressao logica no cabecalho do IF");
                        }
                    }
break;
case 60:
#line 324 "lab4.y"
{printf ("then \n"); tab++;}
break;
case 62:
#line 328 "lab4.y"
{ tab--;}
break;
case 63:
#line 329 "lab4.y"
{tab--; tabular();printf ("else\n ");tab++;}
break;
case 64:
#line 329 "lab4.y"
{}
break;
case 65:
#line 329 "lab4.y"
{tab--;}
break;
case 66:
#line 334 "lab4.y"
{tabular ();}
break;
case 67:
#line 334 "lab4.y"
{printf ("while ");}
break;
case 68:
#line 334 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){ 
                            Esperado("Expressao logica no cabecalho do WHILE");
                        }
                    }
break;
case 69:
#line 338 "lab4.y"
{printf ("do \n");tab++;}
break;
case 70:
#line 338 "lab4.y"
{tab--;}
break;
case 71:
#line 342 "lab4.y"
{tabular ();}
break;
case 72:
#line 342 "lab4.y"
{printf ("repeat \n");tab++;}
break;
case 73:
#line 342 "lab4.y"
{tab--;tabular();printf ("while ");}
break;
case 74:
#line 342 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){ 
                            Esperado("Expressao logica no enncerramento do REPEAT");
                        }
                    }
break;
case 75:
#line 346 "lab4.y"
{printf (";\n");}
break;
case 76:
#line 349 "lab4.y"
{tabular ();}
break;
case 77:
#line 349 "lab4.y"
{printf ("for ");}
break;
case 78:
#line 349 "lab4.y"
{
                            if(yyvsp[0].simb->array == VERDADE || (yyvsp[0].simb->tvar != CARACTERE && yyvsp[0].simb->tvar != INTEIRO)) {
                                Esperado("Variavel de controle do FOR escalar inteira ou escalar caractere");
                            } 
                        }
break;
case 79:
#line 353 "lab4.y"
{printf ("( ");}
break;
case 80:
#line 353 "lab4.y"
{
                            if(yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE){ 
                                Esperado("Primeira expressao do FOR inteira ou caractere");
                            }
                        }
break;
case 81:
#line 357 "lab4.y"
{printf (": ");}
break;
case 82:
#line 358 "lab4.y"
{
                            if(yyvsp[0].tipoexpr != LOGICO){ 
                                Esperado("Segunda expressao do FOR logica");
                            }
                        }
break;
case 83:
#line 362 "lab4.y"
{printf (": ");}
break;
case 84:
#line 362 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE){ 
                            Esperado("Terceira expressao do FOR inteira ou caractere");
                            }
                        }
break;
case 85:
#line 366 "lab4.y"
{printf (")\n"); tab++; }
break;
case 86:
#line 366 "lab4.y"
{tab--;}
break;
case 87:
#line 369 "lab4.y"
{tabular(); printf ("read (");}
break;
case 88:
#line 369 "lab4.y"
{printf (");\n");}
break;
case 90:
#line 373 "lab4.y"
{printf (",");}
break;
case 92:
#line 376 "lab4.y"
{ tabular ();printf ("write ( ");}
break;
case 93:
#line 376 "lab4.y"
{printf (");\n");}
break;
case 95:
#line 379 "lab4.y"
{printf (", ");}
break;
case 97:
#line 382 "lab4.y"
{printf ("%s", yyvsp[0].string);}
break;
case 99:
#line 385 "lab4.y"
{
                        simb = ProcuraSimb (yyvsp[-1].string);
                        if (simb == NULL) NaoDeclarado (yyvsp[-1].string);
                        else if (simb->tid != FUNCVOID) TipoInadequado (yyvsp[-1].string);
                        tabular();
                        printf("call %s(",yyvsp[-1].string);
                    }
break;
case 100:
#line 391 "lab4.y"
{printf (");\n");}
break;
case 103:
#line 398 "lab4.y"
{tabular();printf ("return ;\n"); yyval.returnedType = 0;}
break;
case 105:
#line 399 "lab4.y"
{tabular();printf ("return ");}
break;
case 106:
#line 399 "lab4.y"
{yyval.returnedType = yyvsp[-1].tipoexpr; printf (";\n");}
break;
case 107:
#line 402 "lab4.y"
{tabular ();}
break;
case 108:
#line 403 "lab4.y"
{ if  (yyvsp[0].simb != NULL) yyvsp[0].simb->inic = yyvsp[0].simb->ref = VERDADE;}
break;
case 109:
#line 404 "lab4.y"
{printf (":= ");}
break;
case 110:
#line 405 "lab4.y"
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
case 112:
#line 418 "lab4.y"
{printf (", ");}
break;
case 115:
#line 422 "lab4.y"
{printf ("|| ");}
break;
case 116:
#line 422 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != LOGICO || yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador or");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 118:
#line 429 "lab4.y"
{printf ("&& ");}
break;
case 119:
#line 429 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != LOGICO || yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador and");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 121:
#line 436 "lab4.y"
{printf ("! ");}
break;
case 122:
#line 436 "lab4.y"
{
                        if (yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador not");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 124:
#line 444 "lab4.y"
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
case 125:
#line 453 "lab4.y"
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
case 127:
#line 469 "lab4.y"
{
                        switch (yyvsp[0].atr) {
                            case PLUS: printf ("+ "); break;
                            case MINUS: printf ("- "); break;
                        }
                    }
break;
case 128:
#line 474 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != REAL && yyvsp[-3].tipoexpr != CARACTERE || yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr!=REAL && yyvsp[0].tipoexpr!=CARACTERE)
                            Incompatibilidade ("Operando improprio para operador aritmetico");
                        if (yyvsp[-3].tipoexpr == REAL || yyvsp[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                        else yyval.tipoexpr = INTEIRO;
                    }
break;
case 130:
#line 483 "lab4.y"
{
                        switch (yyvsp[0].atr) {
                            case MULT: printf ("* "); break;
                            case DIV: printf ("/ "); break;
                            case MOD: printf ("%% "); break;
                        }
                    }
break;
case 131:
#line 489 "lab4.y"
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
case 132:
#line 508 "lab4.y"
{
                        if  (yyvsp[0].simb != NULL) {
                            yyvsp[0].simb->ref  =  VERDADE;
                            yyval.tipoexpr = yyvsp[0].simb->tvar;
                        }
                    }
break;
case 133:
#line 514 "lab4.y"
{
                        printf ("%d ", yyvsp[0].valor);
                        yyval.tipoexpr = INTEIRO;
                    }
break;
case 134:
#line 518 "lab4.y"
{
                        printf ("%g ", yyvsp[0].valreal);
                        yyval.tipoexpr = REAL;
                    }
break;
case 135:
#line 522 "lab4.y"
{
                        printf ("\'%c\' ", yyvsp[0].string);
                        yyval.tipoexpr = CARACTERE;
                    }
break;
case 136:
#line 526 "lab4.y"
{
                        printf ("true ");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 137:
#line 530 "lab4.y"
{
                        printf ("false ");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 138:
#line 534 "lab4.y"
{printf ("~ ");}
break;
case 139:
#line 534 "lab4.y"
{
                        if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != REAL && yyvsp[0].tipoexpr != CARACTERE)
                            Incompatibilidade  ("Operando improprio para menos unario");
                        if (yyvsp[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                        else yyval.tipoexpr = INTEIRO;
                    }
break;
case 140:
#line 540 "lab4.y"
{printf ("( ");}
break;
case 141:
#line 541 "lab4.y"
{printf (") "); yyval.tipoexpr = yyvsp[-1].tipoexpr;}
break;
case 143:
#line 545 "lab4.y"
{
                        printf ("%s ", yyvsp[0].string);
                        simb = ProcuraSimb (yyvsp[0].string);
                        if (simb == NULL) NaoDeclarado (yyvsp[0].string);
                        else if (simb->tid != IDVAR) TipoInadequado (yyvsp[0].string);
                        yyval.simb = simb;
                    }
break;
case 144:
#line 551 "lab4.y"
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
case 145:
#line 564 "lab4.y"
{yyval.nsubscr = 0;}
break;
case 146:
#line 565 "lab4.y"
{printf ("[ ");}
break;
case 147:
#line 566 "lab4.y"
{printf ("] "); yyval.nsubscr = yyvsp[-1].nsubscr; }
break;
case 148:
#line 569 "lab4.y"
{
                        yyval.nsubscr = 1;
                        if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                        Incompatibilidade ("Tipo inadequado para subscrito");
                    }
break;
case 149:
#line 574 "lab4.y"
{yyval.nsubscr = 2;}
break;
case 150:
#line 575 "lab4.y"
{yyval.nsubscr =3;}
break;
case 151:
#line 578 "lab4.y"
{printf (", ");}
break;
case 152:
#line 578 "lab4.y"
{ if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != CARACTERE || 
                                                                    yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                                                                    Incompatibilidade ("Tipo inadequado para subscrito");   }
break;
case 153:
#line 584 "lab4.y"
{printf (", ");}
break;
case 154:
#line 584 "lab4.y"
{ if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                        Incompatibilidade ("Tipo inadequado para subscrito"); }
break;
case 155:
#line 589 "lab4.y"
{
                            simb = ProcuraSimb (yyvsp[0].string);
                            if (simb == NULL) NaoDeclarado (yyvsp[0].string);
                            else if (simb->tid == FUNCVOID) TipoInadequado (yyvsp[0].string);
                            printf ("%s ", yyvsp[0].string);}
break;
case 156:
#line 594 "lab4.y"
{printf ("(");}
break;
case 157:
#line 594 "lab4.y"
{printf (")");}
break;
#line 1569 "y.tab.c"
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
