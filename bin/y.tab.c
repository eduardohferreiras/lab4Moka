/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     CHARCT = 259,
     STRING = 260,
     INTCT = 261,
     FLOATCT = 262,
     OR = 263,
     AND = 264,
     NOT = 265,
     RELOP = 266,
     ADOP = 267,
     MULTOP = 268,
     NEG = 269,
     OPPAR = 270,
     CLPAR = 271,
     OPBRAK = 272,
     CLBRAK = 273,
     OPBRACE = 274,
     CLBRACE = 275,
     OPTRIP = 276,
     CLTRIP = 277,
     COMMA = 278,
     SCOLON = 279,
     ASSIGN = 280,
     CHAR = 281,
     DO = 282,
     ELSE = 283,
     FALSE = 284,
     FLOAT = 285,
     IF = 286,
     INT = 287,
     LOGIC = 288,
     READ = 289,
     STATEMENTS = 290,
     THEN = 291,
     TRUE = 292,
     VAR = 293,
     WHILE = 294,
     WRITE = 295,
     INVAL = 296,
     VOID = 297,
     FOR = 298,
     CALL = 299,
     COLON = 300,
     MAIN = 301,
     REPEAT = 302,
     RETURN = 303
   };
#endif
/* Tokens.  */
#define ID 258
#define CHARCT 259
#define STRING 260
#define INTCT 261
#define FLOATCT 262
#define OR 263
#define AND 264
#define NOT 265
#define RELOP 266
#define ADOP 267
#define MULTOP 268
#define NEG 269
#define OPPAR 270
#define CLPAR 271
#define OPBRAK 272
#define CLBRAK 273
#define OPBRACE 274
#define CLBRACE 275
#define OPTRIP 276
#define CLTRIP 277
#define COMMA 278
#define SCOLON 279
#define ASSIGN 280
#define CHAR 281
#define DO 282
#define ELSE 283
#define FALSE 284
#define FLOAT 285
#define IF 286
#define INT 287
#define LOGIC 288
#define READ 289
#define STATEMENTS 290
#define THEN 291
#define TRUE 292
#define VAR 293
#define WHILE 294
#define WRITE 295
#define INVAL 296
#define VOID 297
#define FOR 298
#define CALL 299
#define COLON 300
#define MAIN 301
#define REPEAT 302
#define RETURN 303




/* Copy the first part of user declarations.  */
#line 1 "lab4.y"


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



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 91 "lab4.y"
{
	char string[50];
	int atr, valor;
	float valreal;
	char carac;
    simbolo simb;
    int tipoexpr;
    int nsubscr;
    int returnedTypes[5];
    int returnedType;
}
/* Line 193 of yacc.c.  */
#line 295 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 308 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNRULES -- Number of states.  */
#define YYNSTATES  239

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,    14,    15,    16,    22,    24,
      27,    28,    33,    35,    37,    39,    41,    43,    45,    46,
      51,    52,    56,    57,    58,    63,    65,    69,    75,    76,
      79,    82,    87,    88,    95,    97,    98,   103,   106,   109,
     110,   114,   115,   119,   120,   125,   126,   129,   131,   133,
     135,   137,   139,   141,   143,   145,   147,   149,   151,   152,
     153,   154,   155,   165,   166,   167,   168,   173,   174,   175,
     176,   177,   186,   187,   188,   189,   190,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   231,   232,
     239,   241,   242,   247,   248,   255,   257,   258,   263,   265,
     267,   268,   276,   277,   279,   282,   283,   288,   289,   290,
     291,   299,   301,   302,   307,   309,   310,   315,   317,   318,
     323,   325,   326,   330,   332,   333,   338,   340,   341,   346,
     348,   349,   354,   356,   358,   360,   362,   364,   366,   367,
     371,   372,   377,   379,   380,   384,   385,   386,   391,   393,
     395,   397,   398,   403,   404,   409,   410,   411
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      50,     0,    -1,    -1,    -1,    51,     3,    21,    52,    53,
      66,    74,    22,    -1,    -1,    -1,    38,    19,    54,    55,
      20,    -1,    56,    -1,    55,    56,    -1,    -1,    57,    58,
      59,    24,    -1,    32,    -1,    30,    -1,    26,    -1,    33,
      -1,    42,    -1,    61,    -1,    -1,    59,    23,    60,    61,
      -1,    -1,     3,    62,    63,    -1,    -1,    -1,    17,    64,
      65,    18,    -1,     6,    -1,     6,    23,     6,    -1,     6,
      23,     6,    23,     6,    -1,    -1,    66,    67,    -1,    68,
      73,    -1,    58,     3,    15,    16,    -1,    -1,    58,     3,
      15,    69,    70,    16,    -1,    72,    -1,    -1,    70,    23,
      71,    72,    -1,    58,     3,    -1,    53,    76,    -1,    -1,
      46,    75,    73,    -1,    -1,    35,    77,    78,    -1,    -1,
      19,    79,    80,    20,    -1,    -1,    80,    81,    -1,    78,
      -1,    82,    -1,    90,    -1,    95,    -1,   100,    -1,   111,
      -1,   115,    -1,   125,    -1,   120,    -1,   123,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    83,    31,    84,   131,    85,
      36,    86,    81,    87,    -1,    -1,    -1,    -1,    28,    88,
      81,    89,    -1,    -1,    -1,    -1,    -1,    91,    39,    92,
     131,    93,    27,    94,    81,    -1,    -1,    -1,    -1,    -1,
      96,    47,    97,    81,    39,    98,   131,    99,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    43,   102,   146,   103,    15,   104,   139,   105,    45,
     106,   131,   107,    45,   108,   139,   109,    16,   110,    81,
      -1,    -1,    34,   112,    15,   113,    16,    24,    -1,   146,
      -1,    -1,   113,    23,   114,   146,    -1,    -1,    40,    15,
     116,   117,    16,    24,    -1,   119,    -1,    -1,   117,    23,
     118,   119,    -1,     5,    -1,   131,    -1,    -1,    44,     3,
      15,   121,   122,    16,    24,    -1,    -1,   129,    -1,    48,
      24,    -1,    -1,    48,   124,   131,    24,    -1,    -1,    -1,
      -1,   126,   146,   127,    25,   128,   131,    24,    -1,   131,
      -1,    -1,   129,    23,   130,   131,    -1,   133,    -1,    -1,
     131,     8,   132,   133,    -1,   135,    -1,    -1,   133,     9,
     134,   135,    -1,   137,    -1,    -1,    10,   136,   137,    -1,
     139,    -1,    -1,   139,    11,   138,   139,    -1,   141,    -1,
      -1,   139,    12,   140,   141,    -1,   143,    -1,    -1,   141,
      13,   142,   143,    -1,   146,    -1,     6,    -1,     7,    -1,
       4,    -1,    37,    -1,    29,    -1,    -1,    14,   144,   143,
      -1,    -1,    15,   145,   131,    16,    -1,   155,    -1,    -1,
       3,   147,   148,    -1,    -1,    -1,    17,   149,   150,    18,
      -1,   139,    -1,   151,    -1,   153,    -1,    -1,   139,    23,
     152,   139,    -1,    -1,   151,    23,   154,   139,    -1,    -1,
      -1,     3,   156,    15,   157,   122,    16,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   167,   167,   167,   167,   177,   178,   178,   181,   181,
     184,   184,   187,   188,   189,   190,   191,   194,   194,   194,
     197,   197,   209,   210,   210,   214,   220,   228,   235,   236,
     239,   278,   279,   279,   282,   283,   283,   286,   290,   293,
     293,   296,   296,   300,   300,   303,   304,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   320,   320,
     320,   324,   320,   328,   329,   329,   329,   334,   334,   334,
     338,   334,   342,   342,   342,   342,   342,   349,   349,   349,
     353,   353,   357,   358,   362,   362,   366,   349,   369,   369,
     372,   373,   373,   376,   376,   379,   379,   379,   382,   382,
     385,   385,   394,   395,   398,   399,   399,   402,   403,   404,
     402,   417,   418,   418,   421,   422,   422,   428,   429,   429,
     435,   436,   436,   443,   444,   444,   468,   469,   469,   482,
     483,   483,   508,   514,   518,   522,   526,   530,   534,   534,
     540,   540,   542,   545,   545,   564,   565,   565,   568,   574,
     575,   578,   578,   584,   584,   589,   594,   589
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "CHARCT", "STRING", "INTCT",
  "FLOATCT", "OR", "AND", "NOT", "RELOP", "ADOP", "MULTOP", "NEG", "OPPAR",
  "CLPAR", "OPBRAK", "CLBRAK", "OPBRACE", "CLBRACE", "OPTRIP", "CLTRIP",
  "COMMA", "SCOLON", "ASSIGN", "CHAR", "DO", "ELSE", "FALSE", "FLOAT",
  "IF", "INT", "LOGIC", "READ", "STATEMENTS", "THEN", "TRUE", "VAR",
  "WHILE", "WRITE", "INVAL", "VOID", "FOR", "CALL", "COLON", "MAIN",
  "REPEAT", "RETURN", "$accept", "Prog", "@1", "@2", "Decls", "@3",
  "DeclList", "Declaration", "@4", "Type", "ElemList", "@5", "Elem", "@6",
  "Dims", "@7", "DimList", "ModList", "Module", "ModHeader", "@8",
  "ParamList", "@9", "Parameter", "ModBody", "MainMod", "@10", "Stats",
  "@11", "CompStat", "@12", "StatList", "Statement", "IfStat", "@13",
  "@14", "@15", "@16", "ElseStat", "@17", "@18", "WhileStat", "@19", "@20",
  "@21", "@22", "RepeatStat", "@23", "@24", "@25", "@26", "ForStat", "@27",
  "@28", "@29", "@30", "@31", "@32", "@33", "@34", "@35", "@36",
  "ReadStat", "@37", "ReadList", "@38", "WriteStat", "@39", "WriteList",
  "@40", "WriteElem", "CallStat", "@41", "Arguments", "ReturnStat", "@42",
  "AssignStat", "@43", "@44", "@45", "ExprList", "@46", "Expression",
  "@47", "AuxExpr1", "@48", "AuxExpr2", "@49", "AuxExpr3", "@50",
  "AuxExpr4", "@51", "Term", "@52", "Factor", "@53", "@54", "Variable",
  "@55", "Subscripts", "@56", "SubscrList", "TwoSubscr", "@57",
  "ThreeSubscr", "@58", "FuncCall", "@59", "@60", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    51,    52,    50,    53,    54,    53,    55,    55,
      57,    56,    58,    58,    58,    58,    58,    59,    60,    59,
      62,    61,    63,    64,    63,    65,    65,    65,    66,    66,
      67,    68,    69,    68,    70,    71,    70,    72,    73,    75,
      74,    77,    76,    79,    78,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    83,    84,
      85,    86,    82,    87,    88,    89,    87,    91,    92,    93,
      94,    90,    96,    97,    98,    99,    95,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   100,   112,   111,
     113,   114,   113,   116,   115,   117,   118,   117,   119,   119,
     121,   120,   122,   122,   123,   124,   123,   126,   127,   128,
     125,   129,   130,   129,   131,   132,   131,   133,   134,   133,
     135,   136,   135,   137,   138,   137,   139,   140,   139,   141,
     142,   141,   143,   143,   143,   143,   143,   143,   144,   143,
     145,   143,   143,   147,   146,   148,   149,   148,   150,   150,
     150,   152,   151,   154,   153,   156,   157,   155
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     8,     0,     0,     5,     1,     2,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     4,
       0,     3,     0,     0,     4,     1,     3,     5,     0,     2,
       2,     4,     0,     6,     1,     0,     4,     2,     2,     0,
       3,     0,     3,     0,     4,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     0,
       0,     0,     9,     0,     0,     0,     4,     0,     0,     0,
       0,     8,     0,     0,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,     6,
       1,     0,     4,     0,     6,     1,     0,     4,     1,     1,
       0,     7,     0,     1,     2,     0,     4,     0,     0,     0,
       7,     1,     0,     4,     1,     0,     4,     1,     0,     4,
       1,     0,     3,     1,     0,     4,     1,     0,     4,     1,
       0,     4,     1,     1,     1,     1,     1,     1,     0,     3,
       0,     4,     1,     0,     3,     0,     0,     4,     1,     1,
       1,     0,     4,     0,     4,     0,     0,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     5,     0,    28,     6,
       0,    10,    14,    13,    12,    15,    16,    39,     0,    29,
       5,     0,    10,     8,     0,     5,     0,     0,    30,     4,
       7,     9,     0,    40,    32,    41,    38,    20,     0,    17,
      31,     0,     0,    22,    18,    11,     0,     0,    34,    43,
      42,    23,    21,     0,    37,    33,    35,    45,     0,    19,
       0,    58,    25,     0,    36,    44,    57,    88,     0,     0,
     105,    47,    46,    48,     0,    49,     0,    50,     0,    51,
       0,    52,    53,    55,    56,    54,     0,     0,    24,     0,
      93,     0,   104,     0,    59,    68,    73,    78,   143,   108,
      26,     0,     0,   100,   143,   135,   133,   134,   121,   138,
     140,   137,   136,     0,   114,   117,   120,   123,   126,   129,
     132,   142,     0,     0,    58,     0,   145,     0,     0,     0,
      90,    98,     0,    95,    99,   102,     0,     0,     0,     0,
     115,   106,   118,   124,   127,   130,    60,    69,     0,    79,
     146,   144,   109,    27,     0,    91,     0,    96,     0,   103,
     111,   156,   122,   139,     0,     0,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,    89,     0,    94,     0,
       0,   112,   102,   141,   116,   119,   125,   128,   131,    61,
      70,     0,    80,   148,     0,   149,   150,     0,    92,    97,
     101,     0,     0,    58,    58,    75,     0,   151,   147,   153,
     110,   113,   157,    63,    71,     0,    81,     0,     0,    64,
      62,    76,     0,   152,   154,    58,    82,    65,     0,    66,
      83,     0,    84,     0,    85,     0,    86,    58,    87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,    27,    11,    22,    23,    24,    46,
      38,    53,    39,    43,    52,    58,    63,    10,    19,    20,
      41,    47,    60,    48,    28,    21,    25,    36,    42,    71,
      57,    61,    72,    73,    74,   122,   170,   203,   220,   225,
     229,    75,    76,   123,   171,   204,    77,    78,   124,   191,
     215,    79,    80,   125,   173,   206,   222,   228,   231,   233,
     235,   237,    81,    89,   129,   177,    82,   102,   132,   179,
     133,    83,   135,   158,    84,    93,    85,    86,   127,   175,
     159,   201,   134,   165,   114,   166,   115,   137,   116,   167,
     117,   168,   118,   169,   119,   138,   139,   120,   126,   151,
     174,   194,   195,   217,   196,   218,   121,   136,   182
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -164
static const yytype_int16 yypact[] =
{
    -164,     9,    17,  -164,    10,  -164,    -2,    26,  -164,  -164,
     -20,  -164,  -164,  -164,  -164,  -164,  -164,  -164,    45,  -164,
      -2,    40,    30,  -164,   106,    -2,    48,    31,  -164,  -164,
    -164,  -164,    68,  -164,    59,  -164,  -164,  -164,    -9,  -164,
    -164,   106,    57,    60,  -164,  -164,    75,     2,  -164,  -164,
    -164,  -164,  -164,    68,  -164,  -164,  -164,  -164,    73,  -164,
     106,    13,    65,    74,  -164,  -164,  -164,  -164,    76,    93,
      81,  -164,  -164,  -164,    66,  -164,    67,  -164,    52,  -164,
      70,  -164,  -164,  -164,  -164,  -164,   107,   109,  -164,   101,
    -164,   105,  -164,    97,  -164,  -164,  -164,  -164,  -164,  -164,
     100,   107,    80,  -164,   110,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,    -3,   118,  -164,  -164,    28,   111,  -164,
    -164,  -164,    97,    97,    25,   107,   114,   103,   127,    35,
    -164,  -164,    51,  -164,   129,    97,   125,   115,   115,    97,
    -164,  -164,  -164,  -164,  -164,  -164,   129,   129,   102,  -164,
    -164,  -164,  -164,  -164,   119,  -164,   121,  -164,   126,   123,
     129,  -164,  -164,  -164,    19,    97,    97,   115,   115,   115,
     113,   120,  -164,   135,   115,    97,  -164,   107,  -164,    80,
     130,  -164,    97,  -164,   118,  -164,   139,   111,  -164,  -164,
    -164,    97,  -164,    -4,   137,   133,  -164,    -1,  -164,  -164,
    -164,    97,   141,    25,    25,   129,   115,  -164,  -164,  -164,
    -164,   129,  -164,   131,  -164,   134,   139,   115,   115,  -164,
    -164,  -164,   108,   139,   139,    25,  -164,  -164,    97,  -164,
     129,   116,  -164,   115,   139,   144,  -164,    25,  -164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -164,  -164,  -164,  -164,   156,  -164,  -164,   142,  -164,    14,
    -164,  -164,   112,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,   117,   138,  -164,  -164,  -164,  -164,   124,
    -164,  -164,  -123,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,
     -12,  -164,  -164,   -14,  -164,  -164,  -164,  -164,  -164,  -164,
    -164,  -164,   -93,  -164,     4,  -164,     5,  -164,    33,  -164,
    -163,  -164,     6,  -164,  -135,  -164,  -164,   -84,  -164,  -164,
    -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164,  -164
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -156
static const yytype_int16 yytable[] =
{
     113,   148,    99,   163,   186,   140,    12,   140,   144,     3,
      13,   193,    14,    15,    44,    45,  -107,   130,    55,   207,
       4,   141,    16,   210,    18,    56,    17,   140,  -107,   146,
     147,     5,    49,    65,   188,   183,     7,    66,    32,   143,
     144,   149,   160,   216,    49,     9,   164,    67,    26,    66,
      30,   154,   -67,    68,   223,   224,   -77,    69,   155,    67,
     -72,    70,    29,    34,   -67,    68,    35,   156,   -77,    69,
     234,    37,   -72,    70,   157,    40,    49,    51,    54,    62,
     213,   214,   197,   104,   105,   131,   106,   107,    87,   160,
     108,    90,    88,   198,   109,   110,    91,    94,   205,    96,
     104,   105,   227,   106,   107,    92,    95,   108,   211,   111,
      98,   109,   110,    97,   238,   100,   101,   112,   104,   105,
     103,   106,   107,   128,   145,  -155,   111,   142,   152,   109,
     110,   150,    12,   153,   112,   230,    13,   140,    14,    15,
     161,   172,   180,   176,   111,   178,   181,   190,    16,   189,
     192,   144,   112,   226,   200,   208,   209,   212,   221,   219,
     236,   232,     8,    33,    31,    59,    50,   199,   202,   184,
     162,   185,     0,     0,   187,     0,     0,    64
};

static const yytype_int16 yycheck[] =
{
      93,   124,    86,   138,   167,     8,    26,     8,    12,     0,
      30,   174,    32,    33,    23,    24,     3,   101,    16,    23,
       3,    24,    42,    24,    10,    23,    46,     8,     3,   122,
     123,    21,    19,    20,   169,    16,    38,    24,    24,    11,
      12,   125,   135,   206,    19,    19,   139,    34,     3,    24,
      20,    16,    39,    40,   217,   218,    43,    44,    23,    34,
      47,    48,    22,    15,    39,    40,    35,    16,    43,    44,
     233,     3,    47,    48,    23,    16,    19,    17,     3,     6,
     203,   204,   175,     3,     4,     5,     6,     7,    23,   182,
      10,    15,    18,   177,    14,    15,     3,    31,   191,    47,
       3,     4,   225,     6,     7,    24,    39,    10,   201,    29,
       3,    14,    15,    43,   237,     6,    15,    37,     3,     4,
      15,     6,     7,    23,    13,    15,    29,     9,    25,    14,
      15,    17,    26,     6,    37,   228,    30,     8,    32,    33,
      15,    39,    16,    24,    29,    24,    23,    27,    42,    36,
      15,    12,    37,    45,    24,    18,    23,    16,    24,    28,
      16,    45,     6,    25,    22,    53,    42,   179,   182,   165,
     137,   166,    -1,    -1,   168,    -1,    -1,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    50,    51,     0,     3,    21,    52,    38,    53,    19,
      66,    54,    26,    30,    32,    33,    42,    46,    58,    67,
      68,    74,    55,    56,    57,    75,     3,    53,    73,    22,
      20,    56,    58,    73,    15,    35,    76,     3,    59,    61,
      16,    69,    77,    62,    23,    24,    58,    70,    72,    19,
      78,    17,    63,    60,     3,    16,    23,    79,    64,    61,
      71,    80,     6,    65,    72,    20,    24,    34,    40,    44,
      48,    78,    81,    82,    83,    90,    91,    95,    96,   100,
     101,   111,   115,   120,   123,   125,   126,    23,    18,   112,
      15,     3,    24,   124,    31,    39,    47,    43,     3,   146,
       6,    15,   116,    15,     3,     4,     6,     7,    10,    14,
      15,    29,    37,   131,   133,   135,   137,   139,   141,   143,
     146,   155,    84,    92,    97,   102,   147,   127,    23,   113,
     146,     5,   117,   119,   131,   121,   156,   136,   144,   145,
       8,    24,     9,    11,    12,    13,   131,   131,    81,   146,
      17,   148,    25,     6,    16,    23,    16,    23,   122,   129,
     131,    15,   137,   143,   131,   132,   134,   138,   140,   142,
      85,    93,    39,   103,   149,   128,    24,   114,    24,   118,
      16,    23,   157,    16,   133,   135,   139,   141,   143,    36,
      27,    98,    15,   139,   150,   151,   153,   131,   146,   119,
      24,   130,   122,    86,    94,   131,   104,    23,    18,    23,
      24,   131,    16,    81,    81,    99,   139,   152,   154,    28,
      87,    24,   105,   139,   139,    88,    45,    81,   106,    89,
     131,   107,    45,   108,   139,   109,    16,   110,    81
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 167 "lab4.y"
    {InicTabSimb ();}
    break;

  case 3:
#line 167 "lab4.y"
    {
                        printf ("%s {{{\n", (yyvsp[(2) - (3)].string));
                        InsereSimb ((yyvsp[(2) - (3)].string), IDPROG, NAOVAR);
                    }
    break;

  case 4:
#line 171 "lab4.y"
    {
                        printf ("}}}\n");
                        VerificaInicRef ();
                        ImprimeTabSimb ();
                    }
    break;

  case 6:
#line 178 "lab4.y"
    {printf ("var {\n"); tab++;}
    break;

  case 7:
#line 179 "lab4.y"
    {tab--;printf ("}\n");}
    break;

  case 10:
#line 184 "lab4.y"
    {tabular();}
    break;

  case 11:
#line 184 "lab4.y"
    {printf (";\n");}
    break;

  case 12:
#line 187 "lab4.y"
    {printf ("int "); tipocorrente = INTEIRO;}
    break;

  case 13:
#line 188 "lab4.y"
    {printf ("float "); tipocorrente = REAL;}
    break;

  case 14:
#line 189 "lab4.y"
    {printf ("char "); tipocorrente = CARACTERE;}
    break;

  case 15:
#line 190 "lab4.y"
    {printf ("logic "); tipocorrente = LOGICO;}
    break;

  case 16:
#line 191 "lab4.y"
    {printf ("void "); tipocorrente = FUNCVOID;}
    break;

  case 18:
#line 194 "lab4.y"
    {printf (", ");}
    break;

  case 20:
#line 197 "lab4.y"
    {
                        printf ("%s", (yyvsp[(1) - (1)].string));
                        if (ProcuraSimb ((yyvsp[(1) - (1)].string)) != NULL)
                            DeclaracaoRepetida ((yyvsp[(1) - (1)].string));
                        else{

                            simb = InsereSimb ((yyvsp[(1) - (1)].string), IDVAR, tipocorrente);
                            simb->array = FALSO; simb->ndims = 0;
                        }
                    }
    break;

  case 23:
#line 210 "lab4.y"
    {printf ("[ ");}
    break;

  case 24:
#line 211 "lab4.y"
    {printf ("] "); simb->array = VERDADE;}
    break;

  case 25:
#line 214 "lab4.y"
    {
                            printf ("%d ", (yyvsp[(1) - (1)].valor));
                            if ((yyvsp[(1) - (1)].valor) <= 0) Esperado ("Valor inteiro positivo");
                            simb->ndims = 1;
                            simb->dims[1] = (yyvsp[(1) - (1)].valor);
                        }
    break;

  case 26:
#line 220 "lab4.y"
    {
                            printf ("%d , %d ", (yyvsp[(1) - (3)].valor), (yyvsp[(3) - (3)].valor));
                            if ((yyvsp[(1) - (3)].valor) <= 0 || (yyvsp[(3) - (3)].valor) <= 0) Esperado ("Valor inteiro positivo");
                            simb->ndims = 2;
                            simb->dims[1] = (yyvsp[(1) - (3)].valor);
                            simb->dims[2] = (yyvsp[(3) - (3)].valor);
                        }
    break;

  case 27:
#line 229 "lab4.y"
    { printf ("%d , %d , %d ", (yyvsp[(1) - (5)].valor), (yyvsp[(3) - (5)].valor), (yyvsp[(5) - (5)].valor));
                      if ((yyvsp[(1) - (5)].valor) <= 0 || (yyvsp[(3) - (5)].valor) <= 0 || (yyvsp[(5) - (5)].valor) <= 0) Esperado ("Valor inteiro positivo");
                      simb->ndims = 3;
                      simb->dims[1] = (yyvsp[(1) - (5)].valor); simb->dims[2] = (yyvsp[(3) - (5)].valor); simb->dims[3] = (yyvsp[(5) - (5)].valor);    }
    break;

  case 30:
#line 239 "lab4.y"
    {
                    if ((yyvsp[(1) - (2)].returnedType) == INTEIRO)
                    {
                        if((yyvsp[(2) - (2)].returnedTypes)[0] == 1 || (yyvsp[(2) - (2)].returnedTypes)[REAL] == 1 || (yyvsp[(2) - (2)].returnedTypes)[LOGICO] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    if ((yyvsp[(1) - (2)].returnedType) == REAL)
                    {
                        if((yyvsp[(2) - (2)].returnedTypes)[0] == 1 || (yyvsp[(2) - (2)].returnedTypes)[LOGICO] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    if ((yyvsp[(1) - (2)].returnedType) == CARACTERE)
                    {
                        if((yyvsp[(2) - (2)].returnedTypes)[0] == 1 || (yyvsp[(2) - (2)].returnedTypes)[REAL] == 1 || (yyvsp[(2) - (2)].returnedTypes)[LOGICO] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    if ((yyvsp[(1) - (2)].returnedType) == LOGICO)
                    {
                        if((yyvsp[(2) - (2)].returnedTypes)[0] == 1 || (yyvsp[(2) - (2)].returnedTypes)[REAL] == 1 || (yyvsp[(2) - (2)].returnedTypes)[INTEIRO] == 1 || (yyvsp[(2) - (2)].returnedTypes)[CARACTERE] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                    if ((yyvsp[(1) - (2)].returnedType) == FUNCVOID)
                    {
                        if((yyvsp[(2) - (2)].returnedTypes)[LOGICO] == 1 || (yyvsp[(2) - (2)].returnedTypes)[REAL] == 1 || (yyvsp[(2) - (2)].returnedTypes)[INTEIRO] == 1 || (yyvsp[(2) - (2)].returnedTypes)[CARACTERE] == 1)
                        {
                            Incompatibilidade ("Return indevido no escopo da funcao.");
                        }
                    }
                }
    break;

  case 31:
#line 278 "lab4.y"
    { InsereSimb((yyvsp[(2) - (4)].string), IDFUNC, tipocorrente); printf ("%s ()\n", (yyvsp[(2) - (4)].string)); (yyval.returnedType) = tipocorrente;}
    break;

  case 32:
#line 279 "lab4.y"
    { InsereSimb((yyvsp[(2) - (3)].string), IDFUNC, tipocorrente); printf ("%s (", (yyvsp[(2) - (3)].string)); (yyval.returnedType) = tipocorrente; }
    break;

  case 33:
#line 279 "lab4.y"
    {printf (")\n"); }
    break;

  case 35:
#line 283 "lab4.y"
    {printf (", ");}
    break;

  case 37:
#line 286 "lab4.y"
    {printf ("%s ", (yyvsp[(2) - (2)].string));}
    break;

  case 38:
#line 290 "lab4.y"
    {(yyval.returnedTypes)[0] = (yyvsp[(2) - (2)].returnedTypes)[0]; (yyval.returnedTypes)[1] = (yyvsp[(2) - (2)].returnedTypes)[1]; (yyval.returnedTypes)[2] = (yyvsp[(2) - (2)].returnedTypes)[2]; (yyval.returnedTypes)[3] = (yyvsp[(2) - (2)].returnedTypes)[3]; (yyval.returnedTypes)[4] = (yyvsp[(2) - (2)].returnedTypes)[4];}
    break;

  case 39:
#line 293 "lab4.y"
    {printf("main\n");}
    break;

  case 41:
#line 296 "lab4.y"
    {printf ("statements ");tab++;}
    break;

  case 42:
#line 296 "lab4.y"
    {tab--; (yyval.returnedTypes)[0] = (yyvsp[(3) - (3)].returnedTypes)[0]; (yyval.returnedTypes)[1] = (yyvsp[(3) - (3)].returnedTypes)[1]; (yyval.returnedTypes)[2] = (yyvsp[(3) - (3)].returnedTypes)[2]; (yyval.returnedTypes)[3] = (yyvsp[(3) - (3)].returnedTypes)[3]; (yyval.returnedTypes)[4] = (yyvsp[(3) - (3)].returnedTypes)[4];}
    break;

  case 43:
#line 300 "lab4.y"
    {tab--;tabular();tab++;printf ("{\n");}
    break;

  case 44:
#line 301 "lab4.y"
    {tab--;tabular ();tab++; printf ("}\n"); (yyval.returnedTypes)[0] = (yyvsp[(3) - (4)].returnedTypes)[0]; (yyval.returnedTypes)[1] = (yyvsp[(3) - (4)].returnedTypes)[1]; (yyval.returnedTypes)[2] = (yyvsp[(3) - (4)].returnedTypes)[2]; (yyval.returnedTypes)[3] = (yyvsp[(3) - (4)].returnedTypes)[3]; (yyval.returnedTypes)[4] = (yyvsp[(3) - (4)].returnedTypes)[4];}
    break;

  case 46:
#line 304 "lab4.y"
    {if ((yyvsp[(2) - (2)].returnedType) != -1) {(yyval.returnedTypes)[(yyvsp[(2) - (2)].returnedType)] = 1;}}
    break;

  case 48:
#line 308 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 49:
#line 309 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 50:
#line 310 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 51:
#line 311 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 52:
#line 312 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 53:
#line 313 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 54:
#line 314 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 55:
#line 315 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 56:
#line 316 "lab4.y"
    {(yyval.returnedType) = (yyvsp[(1) - (1)].returnedType);}
    break;

  case 57:
#line 317 "lab4.y"
    {(yyval.returnedType) = -1;}
    break;

  case 58:
#line 320 "lab4.y"
    {tabular ();}
    break;

  case 59:
#line 320 "lab4.y"
    {printf ("if ");}
    break;

  case 60:
#line 320 "lab4.y"
    {
                        if((yyvsp[(4) - (4)].tipoexpr) != LOGICO){
                            Esperado("Expressao logica no cabecalho do IF");
                        }
                    }
    break;

  case 61:
#line 324 "lab4.y"
    {printf ("then \n"); tab++;}
    break;

  case 63:
#line 328 "lab4.y"
    { tab--;}
    break;

  case 64:
#line 329 "lab4.y"
    {tab--; tabular();printf ("else\n ");tab++;}
    break;

  case 65:
#line 329 "lab4.y"
    {}
    break;

  case 66:
#line 329 "lab4.y"
    {tab--;}
    break;

  case 67:
#line 334 "lab4.y"
    {tabular ();}
    break;

  case 68:
#line 334 "lab4.y"
    {printf ("while ");}
    break;

  case 69:
#line 334 "lab4.y"
    {
                        if((yyvsp[(4) - (4)].tipoexpr) != LOGICO){
                            Esperado("Expressao logica no cabecalho do WHILE");
                        }
                    }
    break;

  case 70:
#line 338 "lab4.y"
    {printf ("do \n");tab++;}
    break;

  case 71:
#line 338 "lab4.y"
    {tab--;}
    break;

  case 72:
#line 342 "lab4.y"
    {tabular ();}
    break;

  case 73:
#line 342 "lab4.y"
    {printf ("repeat \n");tab++;}
    break;

  case 74:
#line 342 "lab4.y"
    {tab--;tabular();printf ("while ");}
    break;

  case 75:
#line 342 "lab4.y"
    {
                        if((yyvsp[(7) - (7)].tipoexpr) != LOGICO){
                            Esperado("Expressao logica no enncerramento do REPEAT");
                        }
                    }
    break;

  case 76:
#line 346 "lab4.y"
    {printf (";\n");}
    break;

  case 77:
#line 349 "lab4.y"
    {tabular ();}
    break;

  case 78:
#line 349 "lab4.y"
    {printf ("for ");}
    break;

  case 79:
#line 349 "lab4.y"
    {
                            if((yyvsp[(4) - (4)].simb)->array == VERDADE || ((yyvsp[(4) - (4)].simb)->tvar != CARACTERE && (yyvsp[(4) - (4)].simb)->tvar != INTEIRO)) {
                                Esperado("Variavel de controle do FOR escalar inteira ou escalar caractere");
                            }
                        }
    break;

  case 80:
#line 353 "lab4.y"
    {printf ("( ");}
    break;

  case 81:
#line 353 "lab4.y"
    {
                            if((yyvsp[(8) - (8)].tipoexpr) != INTEIRO && (yyvsp[(8) - (8)].tipoexpr) != CARACTERE){
                                Esperado("Primeira expressao do FOR inteira ou caractere");
                            }
                        }
    break;

  case 82:
#line 357 "lab4.y"
    {printf (": ");}
    break;

  case 83:
#line 358 "lab4.y"
    {
                            if((yyvsp[(12) - (12)].tipoexpr) != LOGICO){
                                Esperado("Segunda expressao do FOR logica");
                            }
                        }
    break;

  case 84:
#line 362 "lab4.y"
    {printf (": ");}
    break;

  case 85:
#line 362 "lab4.y"
    {
                        if((yyvsp[(16) - (16)].tipoexpr) != INTEIRO && (yyvsp[(16) - (16)].tipoexpr) != CARACTERE){
                            Esperado("Terceira expressao do FOR inteira ou caractere");
                            }
                        }
    break;

  case 86:
#line 366 "lab4.y"
    {printf (")\n"); tab++; }
    break;

  case 87:
#line 366 "lab4.y"
    {tab--;}
    break;

  case 88:
#line 369 "lab4.y"
    {tabular(); printf ("read (");}
    break;

  case 89:
#line 369 "lab4.y"
    {printf (");\n");}
    break;

  case 91:
#line 373 "lab4.y"
    {printf (",");}
    break;

  case 93:
#line 376 "lab4.y"
    { tabular ();printf ("write ( ");}
    break;

  case 94:
#line 376 "lab4.y"
    {printf (");\n");}
    break;

  case 96:
#line 379 "lab4.y"
    {printf (", ");}
    break;

  case 98:
#line 382 "lab4.y"
    {printf ("%s", (yyvsp[(1) - (1)].string));}
    break;

  case 100:
#line 385 "lab4.y"
    {
                        simb = ProcuraSimb ((yyvsp[(2) - (3)].string));
                        if (simb == NULL) NaoDeclarado ((yyvsp[(2) - (3)].string));
                        else if (simb->tid != FUNCVOID) TipoInadequado ((yyvsp[(2) - (3)].string));
                        tabular();
                        printf("call %s(",(yyvsp[(2) - (3)].string));
                    }
    break;

  case 101:
#line 391 "lab4.y"
    {printf (");\n");}
    break;

  case 104:
#line 398 "lab4.y"
    {tabular();printf ("return ;\n"); (yyval.returnedType) = 0;}
    break;

  case 105:
#line 399 "lab4.y"
    {tabular();printf ("return ");}
    break;

  case 106:
#line 399 "lab4.y"
    {(yyval.returnedType) = (yyvsp[(3) - (4)].tipoexpr); printf (";\n");}
    break;

  case 107:
#line 402 "lab4.y"
    {tabular ();}
    break;

  case 108:
#line 403 "lab4.y"
    { if  ((yyvsp[(2) - (2)].simb) != NULL) (yyvsp[(2) - (2)].simb)->inic = (yyvsp[(2) - (2)].simb)->ref = VERDADE;}
    break;

  case 109:
#line 404 "lab4.y"
    {printf (":= ");}
    break;

  case 110:
#line 405 "lab4.y"
    {
                        printf (";\n");
                        if ((yyvsp[(2) - (7)].simb) != NULL)
                            if ((((yyvsp[(2) - (7)].simb)->tvar == INTEIRO || (yyvsp[(2) - (7)].simb)->tvar == CARACTERE) &&
                                ((yyvsp[(6) - (7)].tipoexpr) == REAL || (yyvsp[(6) - (7)].tipoexpr) == LOGICO)) ||
                                ((yyvsp[(2) - (7)].simb)->tvar == REAL && (yyvsp[(6) - (7)].tipoexpr) == LOGICO) ||
                                ((yyvsp[(2) - (7)].simb)->tvar == LOGICO && (yyvsp[(6) - (7)].tipoexpr) != LOGICO))
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
                        if ((yyvsp[(1) - (4)].tipoexpr) != LOGICO || (yyvsp[(4) - (4)].tipoexpr) != LOGICO)
                            Incompatibilidade ("Operando improprio para operador or");
                        (yyval.tipoexpr) = LOGICO;
                    }
    break;

  case 118:
#line 429 "lab4.y"
    {printf ("&& ");}
    break;

  case 119:
#line 429 "lab4.y"
    {
                        if ((yyvsp[(1) - (4)].tipoexpr) != LOGICO || (yyvsp[(4) - (4)].tipoexpr) != LOGICO)
                            Incompatibilidade ("Operando improprio para operador and");
                        (yyval.tipoexpr) = LOGICO;
                    }
    break;

  case 121:
#line 436 "lab4.y"
    {printf ("! ");}
    break;

  case 122:
#line 436 "lab4.y"
    {
                        if ((yyvsp[(3) - (3)].tipoexpr) != LOGICO)
                            Incompatibilidade ("Operando improprio para operador not");
                        (yyval.tipoexpr) = LOGICO;
                    }
    break;

  case 124:
#line 444 "lab4.y"
    {
                        switch ((yyvsp[(2) - (2)].atr)) {
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
                        switch ((yyvsp[(2) - (4)].atr)) {
                            case LT: case LE: case GT: case GE:
                                if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != REAL && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE || (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr) != REAL && (yyvsp[(4) - (4)].tipoexpr) != CARACTERE)
                                    Incompatibilidade   ("Operando improprio para operador relacional");
                                break;
                            case EQ: case NE:
                                if (((yyvsp[(1) - (4)].tipoexpr) == LOGICO || (yyvsp[(4) - (4)].tipoexpr) == LOGICO) && (yyvsp[(1) - (4)].tipoexpr) != (yyvsp[(4) - (4)].tipoexpr))
                                    Incompatibilidade ("Operando improprio para operador relacional");
                                break;
                        }
                        (yyval.tipoexpr) = LOGICO;
                    }
    break;

  case 127:
#line 469 "lab4.y"
    {
                        switch ((yyvsp[(2) - (2)].atr)) {
                            case PLUS: printf ("+ "); break;
                            case MINUS: printf ("- "); break;
                        }
                    }
    break;

  case 128:
#line 474 "lab4.y"
    {
                        if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != REAL && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE || (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr)!=REAL && (yyvsp[(4) - (4)].tipoexpr)!=CARACTERE)
                            Incompatibilidade ("Operando improprio para operador aritmetico");
                        if ((yyvsp[(1) - (4)].tipoexpr) == REAL || (yyvsp[(4) - (4)].tipoexpr) == REAL) (yyval.tipoexpr) = REAL;
                        else (yyval.tipoexpr) = INTEIRO;
                    }
    break;

  case 130:
#line 483 "lab4.y"
    {
                        switch ((yyvsp[(2) - (2)].atr)) {
                            case MULT: printf ("* "); break;
                            case DIV: printf ("/ "); break;
                            case MOD: printf ("%% "); break;
                        }
                    }
    break;

  case 131:
#line 489 "lab4.y"
    {
                        switch ((yyvsp[(2) - (4)].atr)) {
                            case MULT: case DIV:
                                if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != REAL && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE
                                    || (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr)!=REAL && (yyvsp[(4) - (4)].tipoexpr)!=CARACTERE)
                                    Incompatibilidade ("Operando improprio para operador aritmetico");
                                if ((yyvsp[(1) - (4)].tipoexpr) == REAL || (yyvsp[(4) - (4)].tipoexpr) == REAL) (yyval.tipoexpr) = REAL;
                                else (yyval.tipoexpr) = INTEIRO;
                                break;
                            case MOD:
                                if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE
                                    ||  (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr) != CARACTERE)
                                    Incompatibilidade ("Operando improprio para operador resto");
                                (yyval.tipoexpr) = INTEIRO;
                                break;
                        }
                    }
    break;

  case 132:
#line 508 "lab4.y"
    {
                        if  ((yyvsp[(1) - (1)].simb) != NULL) {
                            (yyvsp[(1) - (1)].simb)->ref  =  VERDADE;
                            (yyval.tipoexpr) = (yyvsp[(1) - (1)].simb)->tvar;
                        }
                    }
    break;

  case 133:
#line 514 "lab4.y"
    {
                        printf ("%d ", (yyvsp[(1) - (1)].valor));
                        (yyval.tipoexpr) = INTEIRO;
                    }
    break;

  case 134:
#line 518 "lab4.y"
    {
                        printf ("%g ", (yyvsp[(1) - (1)].valreal));
                        (yyval.tipoexpr) = REAL;
                    }
    break;

  case 135:
#line 522 "lab4.y"
    {
                        printf ("\'%c\' ", (yyvsp[(1) - (1)].string));
                        (yyval.tipoexpr) = CARACTERE;
                    }
    break;

  case 136:
#line 526 "lab4.y"
    {
                        printf ("true ");
                        (yyval.tipoexpr) = LOGICO;
                    }
    break;

  case 137:
#line 530 "lab4.y"
    {
                        printf ("false ");
                        (yyval.tipoexpr) = LOGICO;
                    }
    break;

  case 138:
#line 534 "lab4.y"
    {printf ("~ ");}
    break;

  case 139:
#line 534 "lab4.y"
    {
                        if ((yyvsp[(3) - (3)].tipoexpr) != INTEIRO && (yyvsp[(3) - (3)].tipoexpr) != REAL && (yyvsp[(3) - (3)].tipoexpr) != CARACTERE)
                            Incompatibilidade  ("Operando improprio para menos unario");
                        if ((yyvsp[(3) - (3)].tipoexpr) == REAL) (yyval.tipoexpr) = REAL;
                        else (yyval.tipoexpr) = INTEIRO;
                    }
    break;

  case 140:
#line 540 "lab4.y"
    {printf ("( ");}
    break;

  case 141:
#line 541 "lab4.y"
    {printf (") "); (yyval.tipoexpr) = (yyvsp[(3) - (4)].tipoexpr);}
    break;

  case 143:
#line 545 "lab4.y"
    {
                        printf ("%s ", (yyvsp[(1) - (1)].string));
                        simb = ProcuraSimb ((yyvsp[(1) - (1)].string));
                        if (simb == NULL) NaoDeclarado ((yyvsp[(1) - (1)].string));
                        else if (simb->tid != IDVAR) TipoInadequado ((yyvsp[(1) - (1)].string));
                        (yyval.simb) = simb;
                    }
    break;

  case 144:
#line 551 "lab4.y"
    {
                                    (yyval.simb) = (yyvsp[(2) - (3)].simb);
                                    if ((yyval.simb) != NULL) {
                                        if ((yyval.simb)->array == FALSO && (yyvsp[(3) - (3)].nsubscr) > 0)
                                            NaoEsperado ("Subscrito\(s)");
                                        else if ((yyval.simb)->array == VERDADE && (yyvsp[(3) - (3)].nsubscr) == 0)
                                            Esperado ("Subscrito\(s)");
                                        else if ((yyval.simb)->ndims != (yyvsp[(3) - (3)].nsubscr))
                                            Incompatibilidade ("Numero de subscritos incompativel com declaracao");
                                    }
                        }
    break;

  case 145:
#line 564 "lab4.y"
    {(yyval.nsubscr) = 0;}
    break;

  case 146:
#line 565 "lab4.y"
    {printf ("[ ");}
    break;

  case 147:
#line 566 "lab4.y"
    {printf ("] "); (yyval.nsubscr) = (yyvsp[(3) - (4)].nsubscr); }
    break;

  case 148:
#line 569 "lab4.y"
    {
                        (yyval.nsubscr) = 1;
                        if ((yyvsp[(1) - (1)].tipoexpr) != INTEIRO && (yyvsp[(1) - (1)].tipoexpr) != CARACTERE)
                        Incompatibilidade ("Tipo inadequado para subscrito");
                    }
    break;

  case 149:
#line 574 "lab4.y"
    {(yyval.nsubscr) = 2;}
    break;

  case 150:
#line 575 "lab4.y"
    {(yyval.nsubscr) =3;}
    break;

  case 151:
#line 578 "lab4.y"
    {printf (", ");}
    break;

  case 152:
#line 578 "lab4.y"
    { if ((yyvsp[(1) - (4)].tipoexpr) != INTEIRO && (yyvsp[(1) - (4)].tipoexpr) != CARACTERE ||
                                                                    (yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr) != CARACTERE)
                                                                    Incompatibilidade ("Tipo inadequado para subscrito");   }
    break;

  case 153:
#line 584 "lab4.y"
    {printf (", ");}
    break;

  case 154:
#line 584 "lab4.y"
    { if ((yyvsp[(4) - (4)].tipoexpr) != INTEIRO && (yyvsp[(4) - (4)].tipoexpr) != CARACTERE)
                        Incompatibilidade ("Tipo inadequado para subscrito"); }
    break;

  case 155:
#line 589 "lab4.y"
    {
                            simb = ProcuraSimb ((yyvsp[(1) - (1)].string));
                            if (simb == NULL) NaoDeclarado ((yyvsp[(1) - (1)].string));
                            else if (simb->tid == FUNCVOID) TipoInadequado ((yyvsp[(1) - (1)].string));
                            printf ("%s ", (yyvsp[(1) - (1)].string));}
    break;

  case 156:
#line 594 "lab4.y"
    {printf ("(");}
    break;

  case 157:
#line 594 "lab4.y"
    {printf (")");}
    break;


/* Line 1267 of yacc.c.  */
#line 2589 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 597 "lab4.y"

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

