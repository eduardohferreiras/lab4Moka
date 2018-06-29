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
   23,   25,    0,   24,   29,   24,   28,   28,   32,   30,
   31,   31,   31,   31,   31,   33,   35,   33,   37,   34,
   36,   39,   36,   38,   38,   38,   26,   26,   40,   17,
   42,   17,   41,   44,   41,   43,   11,   45,   27,   46,
   14,   47,   13,   12,   12,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   52,   53,   54,   55,
   19,   22,   56,   22,   57,   58,   59,   60,   18,   61,
   62,   63,   64,   20,   65,   66,   67,   68,   69,   70,
   71,   72,   73,   74,   21,   75,   48,   76,   77,   76,
   79,   49,   78,   81,   78,   80,   80,   83,   51,   82,
   82,   16,   85,   16,   86,   87,   88,   50,   84,   89,
   84,    2,   90,    2,    3,   91,    3,    4,   92,    4,
    5,   93,    5,    6,   94,    6,    7,   95,    7,    8,
    8,    8,    8,    8,    8,   96,    8,   97,    8,    8,
   99,    1,    9,  100,    9,   10,   10,   10,  103,  101,
  104,  102,  105,  106,   98,
};
short yylen[] = {                                         2,
    0,    0,    8,    0,    0,    5,    1,    2,    0,    4,
    1,    1,    1,    1,    1,    1,    0,    4,    0,    3,
    0,    0,    4,    1,    3,    5,    0,    2,    2,    4,
    0,    6,    1,    0,    4,    2,    2,    0,    3,    0,
    3,    0,    4,    0,    2,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    0,    0,    0,    0,
    9,    0,    0,    3,    0,    0,    0,    0,    8,    0,
    0,    0,    0,    9,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   20,    0,    6,    1,    0,    4,
    0,    6,    1,    0,    4,    1,    1,    0,    7,    0,
    1,    2,    0,    4,    0,    0,    0,    7,    1,    0,
    4,    1,    0,    4,    1,    0,    4,    1,    0,    3,
    1,    0,    4,    1,    0,    4,    1,    0,    4,    1,
    1,    1,    1,    1,    1,    0,    3,    0,    4,    1,
    0,    3,    0,    0,    4,    1,    1,    1,    0,    4,
    0,    4,    0,    0,    6,
};
short yydefred[] = {                                      1,
    0,    0,    0,    2,    0,    0,   27,    5,    0,    9,
   13,   12,   11,   14,   15,   38,    0,    0,    0,   28,
    0,    7,    0,    0,   29,    0,    3,    0,    6,    8,
    0,   39,   40,   37,    0,   19,    0,   16,    0,   30,
    0,    0,   17,   10,   42,   41,    0,    0,   33,   22,
   20,    0,   44,   36,   32,   34,    0,   18,    0,    0,
    0,    0,   43,   56,   86,    0,    0,    0,   46,   45,
   55,   48,   47,   49,   50,   51,   52,   53,   54,    0,
    0,    0,    0,    0,   35,    0,   23,    0,   91,    0,
  102,    0,   58,   66,   71,   76,  141,  106,    0,    0,
    0,   98,    0,  133,  131,  132,  119,  136,  138,  135,
  134,  130,    0,    0,  115,  118,    0,    0,  127,  140,
    0,    0,    0,    0,    0,    0,    0,   88,    0,   96,
    0,    0,   93,    0,    0,    0,    0,    0,  113,  104,
  116,  122,  125,  128,    0,    0,    0,   77,  144,  142,
  107,   26,    0,   89,    0,   94,    0,    0,    0,  154,
  120,  137,    0,    0,    0,    0,    0,    0,    0,    0,
   72,    0,    0,    0,   87,    0,   92,    0,    0,  110,
    0,  139,    0,  117,    0,    0,  129,   60,   68,    0,
   78,    0,    0,    0,  148,    0,   90,   95,   99,    0,
    0,    0,    0,    0,    0,  149,  145,  151,  108,    0,
  155,    0,   69,    0,    0,    0,    0,   63,   61,   74,
    0,    0,    0,    0,   80,   64,    0,    0,    0,   82,
    0,    0,    0,   84,    0,   85,
};
short yydgoto[] = {                                       1,
  112,  131,  114,  115,  116,  117,  118,  119,  150,  193,
   25,   59,   69,   34,   70,   71,   17,   72,   73,   74,
   75,  219,    2,   26,    5,    9,   18,   21,   10,   22,
   47,   23,   37,   38,   52,   51,   42,   62,   57,   20,
   48,   41,   49,   60,   24,   39,   53,   76,   77,   78,
   79,   80,  121,  169,  202,  224,   81,  122,  170,  203,
   82,  123,  190,  214,   83,  124,  172,  205,  221,  227,
  229,  231,  233,  235,   88,  129,  176,  132,  101,  133,
  178,  158,  134,  159,   92,   84,  126,  174,  200,  164,
  165,  136,  166,  167,  168,  137,  138,  120,  125,  173,
  194,  195,  216,  217,  135,  181,
};
short yysindex[] = {                                      0,
    0, -252, -238,    0, -204, -207,    0,    0, -226,    0,
    0,    0,    0,    0,    0,    0, -204, -159, -147,    0,
 -156,    0, -274, -204,    0, -170,    0, -149,    0,    0,
 -136,    0,    0,    0, -142,    0, -245,    0, -139,    0,
 -274, -127,    0,    0,    0,    0, -126, -220,    0,    0,
    0, -136,    0,    0,    0,    0, -113,    0,  -58, -274,
 -123, -121,    0,    0,    0, -112, -101, -120,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -118,
 -119, -130, -109,  -82,    0,  -80,    0,  -90,    0,  -78,
    0,  -19,    0,    0,    0,    0,    0,    0,  -88,  -82,
 -243,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -255,  -71,    0,    0, -203,  -73,    0,    0,
  -19,  -19,   -7,  -82,  -74,  -72,  -62,    0, -191,    0,
  -60, -187,    0,  -19,  -63,   -1,   -1,  -19,    0,    0,
    0,    0,    0,    0,  -60,  -60,  -85,    0,    0,    0,
    0,    0,  -66,    0,  -59,    0,  -60,  -52,  -56,    0,
    0,    0, -186,  -19,  -19,   -1,   -1,   -1,  -64,  -54,
    0,  -40,   -1,  -19,    0,  -82,    0, -243,  -47,    0,
  -19,    0,  -71,    0,  -33,  -73,    0,    0,    0,  -19,
    0, -239,  -38,  -42,    0, -254,    0,    0,    0,  -19,
  -27,   -7,   -7,  -60,   -1,    0,    0,    0,    0,  -60,
    0,  -35,    0,  -30,  -33,   -1,   -1,    0,    0,    0,
  -46,  -33,  -33,   -7,    0,    0,  -19,  -60,  -34,    0,
   -1,  -33,   -9,    0,   -7,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0, -209,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -20,    0,    0,    0,
 -144,    0,    0,  -20,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   12,    0,    0,    0,    0,    0,
    0, -184,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -246,    0,
   -2,    0,    0,    0,    0,    0,    0,   -6,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    0,
    0,    0, -166,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -67,    0,    0,  -94, -117,    0,    0,
    0,    0, -246,    0, -140,    0,    0,    0,    0,    0,
 -185,    0,    0,    4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -15,   -5,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -163,    0,    8,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    4,    0,  -53,    0,  -77, -100,    0,    0,    0,    0,
    0,    7,    0,   14,    0,    0,    0,    0,    0,    0,
    0, -246, -246,    2,    0,    0,    0,    0,    0, -161,
    0, -229,    0,    0,  -16,    0,    0,    0,    0,    0,
    0, -241,   16, -246,    0,    0,    0,  -10,    0,    0,
    0,   23,    0,    0, -246,    0,
};
short yygindex[] = {                                      0,
  -81,  -92,  120,  129,  161, -164,  133, -133,    0,    0,
  277,    0,  263,    0, -122,    0,    0,    0,    0,    0,
    0,    0,    0,  298,    0,    0,    0,    0,    0,  283,
   11,    0,    0,  253,    0,    0,    0,    0,    0,    0,
    0,    0,  246,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  131,
    0,  126,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 309
short yytable[] = {                                     113,
  147,  185,   98,  162,    3,   11,  139,  139,  192,   12,
  105,   13,   14,  103,  104,  130,  105,  106,  128,   19,
  107,   15,  140,  209,  108,  109,  143,   62,  145,  146,
  150,   43,   44,   31,  187,  150,    4,  206,   57,  110,
  215,  157,  148,   62,   62,  163,   65,  111,   62,   55,
   75,  222,  223,   11,   70,   62,   56,   12,   62,   13,
   14,  142,  143,   62,   62,    8,  232,   62,   62,   15,
    4,   62,   62,   16,    4,  139,    4,    4,  153,  212,
  213,  196,  155,  182,   97,  154,    4,    6,  157,  156,
    4,   97,   21,   21,  197,  141,  141,  204,  141,  141,
  141,  226,  153,  141,  141,  141,  109,  210,  111,   28,
  141,  141,  236,  109,  141,  111,   27,   29,   33,   35,
   36,  143,  143,  141,  143,  143,  143,   40,  143,  143,
   54,  143,  141,   45,  228,    9,  143,  143,  143,    9,
  143,    9,    9,   50,  124,  124,   61,  124,  124,  143,
   87,    9,  124,   86,  124,   90,   89,   91,  143,  124,
  124,  126,  126,  124,  126,  126,   93,  121,  121,  126,
   95,  126,  124,   94,   97,  121,  126,  126,  100,   99,
  126,  124,  121,  121,  123,  123,  121,   96,  127,  126,
  102,  141,  123,  144,  112,  121,  149,  152,  126,  123,
  123,  139,  112,  123,  121,  160,  151,  171,  114,  112,
  112,  175,  123,  112,   45,   63,  114,  179,  177,   64,
  180,  123,  112,  114,  114,  188,  189,  114,  191,   65,
  199,  112,  143,  207,  208,   66,  114,  103,  104,   67,
  105,  106,  211,   68,  107,  114,  218,  220,  108,  109,
  103,  103,  225,  103,  103,  103,  104,  103,  105,  106,
  234,  103,  103,  110,  230,   45,  108,  109,    4,   24,
   64,  111,   25,  100,   59,   67,  103,  101,  146,   73,
   65,  110,   79,  183,  103,  147,   66,  152,   81,  111,
   67,   31,   83,  184,   68,   31,  161,   31,   31,  186,
   32,   46,    7,   30,   58,   85,  201,   31,  198,
};
short yycheck[] = {                                      92,
  123,  166,   84,  137,  257,  280,  262,  262,  173,  284,
  257,  286,  287,  257,  258,  259,  260,  261,  100,    9,
  264,  296,  278,  278,  268,  269,  266,  257,  121,  122,
  272,  277,  278,   23,  168,  277,  275,  277,  285,  283,
  205,  134,  124,  273,  274,  138,  293,  291,  278,  270,
  297,  216,  217,  280,  301,  285,  277,  284,  288,  286,
  287,  265,  266,  293,  294,  273,  231,  297,  298,  296,
  280,  301,  302,  300,  284,  262,  286,  287,  270,  202,
  203,  174,  270,  270,  270,  277,  296,  292,  181,  277,
  300,  277,  277,  278,  176,  262,  263,  190,  265,  266,
  267,  224,  269,  270,  271,  272,  270,  200,  270,  257,
  277,  278,  235,  277,  281,  277,  276,  274,  289,  269,
  257,  262,  263,  290,  265,  266,  267,  270,  269,  270,
  257,  272,  299,  273,  227,  280,  277,  278,  279,  284,
  281,  286,  287,  271,  262,  263,  260,  265,  266,  290,
  272,  296,  270,  277,  272,  257,  269,  278,  299,  277,
  278,  262,  263,  281,  265,  266,  285,  262,  263,  270,
  301,  272,  290,  293,  257,  270,  277,  278,  269,  260,
  281,  299,  277,  278,  262,  263,  281,  297,  277,  290,
  269,  263,  270,  267,  262,  290,  271,  260,  299,  277,
  278,  262,  270,  281,  299,  269,  279,  293,  262,  277,
  278,  278,  290,  281,  273,  274,  270,  270,  278,  278,
  277,  299,  290,  277,  278,  290,  281,  281,  269,  288,
  278,  299,  266,  272,  277,  294,  290,  257,  258,  298,
  260,  261,  270,  302,  264,  299,  282,  278,  268,  269,
  257,  258,  299,  260,  261,  257,  258,  264,  260,  261,
  270,  268,  269,  283,  299,  273,  268,  269,  289,  272,
  278,  291,  272,  270,  290,  281,  283,  270,  272,  278,
  288,  283,  299,  164,  291,  272,  294,  272,  299,  291,
  298,  280,  270,  165,  302,  284,  136,  286,  287,  167,
   24,   39,    5,   21,   52,   60,  181,  296,  178,
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
"ElseStat : ELSE $$17 Statement",
"$$18 :",
"$$19 :",
"$$20 :",
"$$21 :",
"WhileStat : $$18 WHILE $$19 Expression $$20 DO $$21 Statement",
"$$22 :",
"$$23 :",
"$$24 :",
"$$25 :",
"RepeatStat : $$22 REPEAT $$23 Statement WHILE $$24 Expression $$25 SCOLON",
"$$26 :",
"$$27 :",
"$$28 :",
"$$29 :",
"$$30 :",
"$$31 :",
"$$32 :",
"$$33 :",
"$$34 :",
"$$35 :",
"ForStat : $$26 FOR $$27 Variable $$28 OPPAR $$29 AuxExpr4 $$30 COLON $$31 Expression $$32 COLON $$33 AuxExpr4 $$34 CLPAR $$35 Statement",
"$$36 :",
"ReadStat : READ $$36 OPPAR ReadList CLPAR SCOLON",
"ReadList : Variable",
"$$37 :",
"ReadList : ReadList COMMA $$37 Variable",
"$$38 :",
"WriteStat : WRITE OPPAR $$38 WriteList CLPAR SCOLON",
"WriteList : WriteElem",
"$$39 :",
"WriteList : WriteList COMMA $$39 WriteElem",
"WriteElem : STRING",
"WriteElem : Expression",
"$$40 :",
"CallStat : CALL ID OPPAR $$40 Arguments CLPAR SCOLON",
"Arguments :",
"Arguments : ExprList",
"ReturnStat : RETURN SCOLON",
"$$41 :",
"ReturnStat : RETURN $$41 Expression SCOLON",
"$$42 :",
"$$43 :",
"$$44 :",
"AssignStat : $$42 Variable $$43 ASSIGN $$44 Expression SCOLON",
"ExprList : Expression",
"$$45 :",
"ExprList : ExprList COMMA $$45 Expression",
"Expression : AuxExpr1",
"$$46 :",
"Expression : Expression OR $$46 AuxExpr1",
"AuxExpr1 : AuxExpr2",
"$$47 :",
"AuxExpr1 : AuxExpr1 AND $$47 AuxExpr2",
"AuxExpr2 : AuxExpr3",
"$$48 :",
"AuxExpr2 : NOT $$48 AuxExpr3",
"AuxExpr3 : AuxExpr4",
"$$49 :",
"AuxExpr3 : AuxExpr4 RELOP $$49 AuxExpr4",
"AuxExpr4 : Term",
"$$50 :",
"AuxExpr4 : AuxExpr4 ADOP $$50 Term",
"Term : Factor",
"$$51 :",
"Term : Term MULTOP $$51 Factor",
"Factor : Variable",
"Factor : INTCT",
"Factor : FLOATCT",
"Factor : CHARCT",
"Factor : TRUE",
"Factor : FALSE",
"$$52 :",
"Factor : NEG $$52 Factor",
"$$53 :",
"Factor : OPPAR $$53 Expression CLPAR",
"Factor : FuncCall",
"$$54 :",
"Variable : ID $$54 Subscripts",
"Subscripts :",
"$$55 :",
"Subscripts : OPBRAK $$55 SubscrList CLBRAK",
"SubscrList : AuxExpr4",
"SubscrList : TwoSubscr",
"SubscrList : ThreeSubscr",
"$$56 :",
"TwoSubscr : AuxExpr4 COMMA $$56 AuxExpr4",
"$$57 :",
"ThreeSubscr : TwoSubscr COMMA $$57 AuxExpr4",
"$$58 :",
"$$59 :",
"FuncCall : ID $$58 OPPAR $$59 Arguments CLPAR",
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
#line 639 "lab4.y"
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
#line 698 "y.tab.c"
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
case 46:
#line 319 "lab4.y"
{yyval.returnedType = (5 + (yyvsp[0].returnedTypes[0]==1 ?1:0) + 10*(yyvsp[0].returnedTypes[1]==1 ?1:0)+ 100*(yyvsp[0].returnedTypes[2]==1 ?1:0)+1000*(yyvsp[0].returnedTypes[3]==1 ?1:0)+10000*(yyvsp[0].returnedTypes[4]==1 ?1:0));}
break;
case 47:
#line 320 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 48:
#line 321 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 49:
#line 322 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 50:
#line 323 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 51:
#line 324 "lab4.y"
{yyval.returnedType = -1;}
break;
case 52:
#line 325 "lab4.y"
{yyval.returnedType = -1;}
break;
case 53:
#line 326 "lab4.y"
{yyval.returnedType = -1;}
break;
case 54:
#line 327 "lab4.y"
{yyval.returnedType = -1;}
break;
case 55:
#line 328 "lab4.y"
{yyval.returnedType = yyvsp[0].returnedType;}
break;
case 56:
#line 329 "lab4.y"
{yyval.returnedType = -1;}
break;
case 57:
#line 332 "lab4.y"
{tabular ();}
break;
case 58:
#line 332 "lab4.y"
{printf ("if ");}
break;
case 59:
#line 332 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){
                            Esperado("Expressao logica no cabecalho do IF");
                        }
                    }
break;
case 60:
#line 336 "lab4.y"
{printf ("then \n"); tab++;}
break;
case 61:
#line 337 "lab4.y"
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
case 62:
#line 369 "lab4.y"
{ tab--; yyval.returnedType = -1;}
break;
case 63:
#line 370 "lab4.y"
{tab--; tabular();printf ("else\n ");tab++;}
break;
case 64:
#line 370 "lab4.y"
{tab--; yyval.returnedType = yyvsp[0].returnedType;}
break;
case 65:
#line 375 "lab4.y"
{tabular ();}
break;
case 66:
#line 375 "lab4.y"
{printf ("while ");}
break;
case 67:
#line 375 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){
                            Esperado("Expressao logica no cabecalho do WHILE");
                        }
                    }
break;
case 68:
#line 379 "lab4.y"
{printf ("do \n");tab++;}
break;
case 69:
#line 379 "lab4.y"
{tab--; yyval.returnedType = yyvsp[0].returnedType; }
break;
case 70:
#line 383 "lab4.y"
{tabular ();}
break;
case 71:
#line 383 "lab4.y"
{printf ("repeat \n");tab++;}
break;
case 72:
#line 383 "lab4.y"
{tab--;tabular();printf ("while "); yyval.returnedType = yyvsp[-1].returnedType;}
break;
case 73:
#line 383 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != LOGICO){
                            Esperado("Expressao logica no enncerramento do REPEAT");
                        }
                    }
break;
case 74:
#line 387 "lab4.y"
{printf (";\n");}
break;
case 75:
#line 390 "lab4.y"
{tabular ();}
break;
case 76:
#line 390 "lab4.y"
{printf ("for ");}
break;
case 77:
#line 390 "lab4.y"
{
                            if(yyvsp[0].simb->array == VERDADE || (yyvsp[0].simb->tvar != CARACTERE && yyvsp[0].simb->tvar != INTEIRO)) {
                                Esperado("Variavel de controle do FOR escalar inteira ou escalar caractere");
                            }
                        }
break;
case 78:
#line 394 "lab4.y"
{printf ("( ");}
break;
case 79:
#line 394 "lab4.y"
{
                            if(yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE){
                                Esperado("Primeira expressao do FOR inteira ou caractere");
                            }
                        }
break;
case 80:
#line 398 "lab4.y"
{printf (": ");}
break;
case 81:
#line 399 "lab4.y"
{
                            if(yyvsp[0].tipoexpr != LOGICO){
                                Esperado("Segunda expressao do FOR logica");
                            }
                        }
break;
case 82:
#line 403 "lab4.y"
{printf (": ");}
break;
case 83:
#line 403 "lab4.y"
{
                        if(yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE){
                            Esperado("Terceira expressao do FOR inteira ou caractere");
                            }
                        }
break;
case 84:
#line 407 "lab4.y"
{printf (")\n"); tab++; }
break;
case 85:
#line 407 "lab4.y"
{tab--; yyval.returnedType = yyvsp[0].returnedType;}
break;
case 86:
#line 410 "lab4.y"
{tabular(); printf ("read (");}
break;
case 87:
#line 410 "lab4.y"
{printf (");\n");}
break;
case 89:
#line 414 "lab4.y"
{printf (",");}
break;
case 91:
#line 417 "lab4.y"
{ tabular ();printf ("write ( ");}
break;
case 92:
#line 417 "lab4.y"
{printf (");\n");}
break;
case 94:
#line 420 "lab4.y"
{printf (", ");}
break;
case 96:
#line 423 "lab4.y"
{printf ("%s", yyvsp[0].string);}
break;
case 98:
#line 426 "lab4.y"
{
                        simb = ProcuraSimb (yyvsp[-1].string);
                        if (simb == NULL) NaoDeclarado (yyvsp[-1].string);
                        else if (simb->tid != FUNCVOID) TipoInadequado (yyvsp[-1].string);
                        tabular();
                        printf("call %s(",yyvsp[-1].string);
                    }
break;
case 99:
#line 432 "lab4.y"
{printf (");\n");}
break;
case 102:
#line 439 "lab4.y"
{tabular();printf ("return ;\n"); yyval.returnedType = 0;}
break;
case 103:
#line 440 "lab4.y"
{tabular();printf ("return ");}
break;
case 104:
#line 440 "lab4.y"
{yyval.returnedType = yyvsp[-1].tipoexpr; printf (";\n");}
break;
case 105:
#line 443 "lab4.y"
{tabular ();}
break;
case 106:
#line 444 "lab4.y"
{ if  (yyvsp[0].simb != NULL) yyvsp[0].simb->inic = yyvsp[0].simb->ref = VERDADE;}
break;
case 107:
#line 445 "lab4.y"
{printf (":= ");}
break;
case 108:
#line 446 "lab4.y"
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
case 110:
#line 459 "lab4.y"
{printf (", ");}
break;
case 113:
#line 463 "lab4.y"
{printf ("|| ");}
break;
case 114:
#line 463 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != LOGICO || yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador or");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 116:
#line 470 "lab4.y"
{printf ("&& ");}
break;
case 117:
#line 470 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != LOGICO || yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador and");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 119:
#line 477 "lab4.y"
{printf ("! ");}
break;
case 120:
#line 477 "lab4.y"
{
                        if (yyvsp[0].tipoexpr != LOGICO)
                            Incompatibilidade ("Operando improprio para operador not");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 122:
#line 485 "lab4.y"
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
case 123:
#line 494 "lab4.y"
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
case 125:
#line 510 "lab4.y"
{
                        switch (yyvsp[0].atr) {
                            case PLUS: printf ("+ "); break;
                            case MINUS: printf ("- "); break;
                        }
                    }
break;
case 126:
#line 515 "lab4.y"
{
                        if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != REAL && yyvsp[-3].tipoexpr != CARACTERE || yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr!=REAL && yyvsp[0].tipoexpr!=CARACTERE)
                            Incompatibilidade ("Operando improprio para operador aritmetico");
                        if (yyvsp[-3].tipoexpr == REAL || yyvsp[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                        else yyval.tipoexpr = INTEIRO;
                    }
break;
case 128:
#line 524 "lab4.y"
{
                        switch (yyvsp[0].atr) {
                            case MULT: printf ("* "); break;
                            case DIV: printf ("/ "); break;
                            case MOD: printf ("%% "); break;
                        }
                    }
break;
case 129:
#line 530 "lab4.y"
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
case 130:
#line 549 "lab4.y"
{
                        if  (yyvsp[0].simb != NULL) {
                            yyvsp[0].simb->ref  =  VERDADE;
                            yyval.tipoexpr = yyvsp[0].simb->tvar;
                        }
                    }
break;
case 131:
#line 555 "lab4.y"
{
                        printf ("%d ", yyvsp[0].valor);
                        yyval.tipoexpr = INTEIRO;
                    }
break;
case 132:
#line 559 "lab4.y"
{
                        printf ("%g ", yyvsp[0].valreal);
                        yyval.tipoexpr = REAL;
                    }
break;
case 133:
#line 563 "lab4.y"
{
                        printf ("\'%c\' ", yyvsp[0].string);
                        yyval.tipoexpr = CARACTERE;
                    }
break;
case 134:
#line 567 "lab4.y"
{
                        printf ("true ");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 135:
#line 571 "lab4.y"
{
                        printf ("false ");
                        yyval.tipoexpr = LOGICO;
                    }
break;
case 136:
#line 575 "lab4.y"
{printf ("~ ");}
break;
case 137:
#line 575 "lab4.y"
{
                        if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != REAL && yyvsp[0].tipoexpr != CARACTERE)
                            Incompatibilidade  ("Operando improprio para menos unario");
                        if (yyvsp[0].tipoexpr == REAL) yyval.tipoexpr = REAL;
                        else yyval.tipoexpr = INTEIRO;
                    }
break;
case 138:
#line 581 "lab4.y"
{printf ("( ");}
break;
case 139:
#line 582 "lab4.y"
{printf (") "); yyval.tipoexpr = yyvsp[-1].tipoexpr;}
break;
case 141:
#line 586 "lab4.y"
{
                        printf ("%s ", yyvsp[0].string);
                        simb = ProcuraSimb (yyvsp[0].string);
                        if (simb == NULL) NaoDeclarado (yyvsp[0].string);
                        else if (simb->tid != IDVAR) TipoInadequado (yyvsp[0].string);
                        yyval.simb = simb;
                    }
break;
case 142:
#line 592 "lab4.y"
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
case 143:
#line 605 "lab4.y"
{yyval.nsubscr = 0;}
break;
case 144:
#line 606 "lab4.y"
{printf ("[ ");}
break;
case 145:
#line 607 "lab4.y"
{printf ("] "); yyval.nsubscr = yyvsp[-1].nsubscr; }
break;
case 146:
#line 610 "lab4.y"
{
                        yyval.nsubscr = 1;
                        if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                        Incompatibilidade ("Tipo inadequado para subscrito");
                    }
break;
case 147:
#line 615 "lab4.y"
{yyval.nsubscr = 2;}
break;
case 148:
#line 616 "lab4.y"
{yyval.nsubscr =3;}
break;
case 149:
#line 619 "lab4.y"
{printf (", ");}
break;
case 150:
#line 619 "lab4.y"
{ if (yyvsp[-3].tipoexpr != INTEIRO && yyvsp[-3].tipoexpr != CARACTERE ||
                                                                    yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                                                                    Incompatibilidade ("Tipo inadequado para subscrito");   }
break;
case 151:
#line 625 "lab4.y"
{printf (", ");}
break;
case 152:
#line 625 "lab4.y"
{ if (yyvsp[0].tipoexpr != INTEIRO && yyvsp[0].tipoexpr != CARACTERE)
                        Incompatibilidade ("Tipo inadequado para subscrito"); }
break;
case 153:
#line 630 "lab4.y"
{
                            simb = ProcuraSimb (yyvsp[0].string);
                            if (simb == NULL) NaoDeclarado (yyvsp[0].string);
                            else if (simb->tid == FUNCVOID) TipoInadequado (yyvsp[0].string);
                            printf ("%s ", yyvsp[0].string);}
break;
case 154:
#line 635 "lab4.y"
{printf ("(");}
break;
case 155:
#line 635 "lab4.y"
{printf (")");}
break;
#line 1608 "y.tab.c"
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
