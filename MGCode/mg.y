%{

/*****Declaraciones en C básicas****/

void yyerror (char *s);  
#include <stdio.h>     
#include <stdlib.h>
int symbols[52];
int symbolVal(char symbol);
int loop_count=0;   /*Contador para el Loop.*/
void updateSymbolVal(char symbol, int val);
%}

/*****Definiciones YACC*****/

%union {int num; char id;}         

/*Inicio de líneas*/
%start LINEA 

/*Tokens para palabras reservadas*/
%token SET
%token DEF
%token LOOP
%token INILOOP
%token FINLOOP
%token BLAK
%token NEG
%token CORCH
%token SCORCH
%token INICOMP
%token FINCOMP
%token INIMUSICA
%token FINMUSICA
%token ENCASO
%token CONTRARIO
%token FINENCASO
%token EJECUTE
%token SILENC

/*Tokens especiales*/
%token <id> NOTE
%token <num> NUMERO
%token <id> IDENTIFICADOR

/*Tipos de Tokens*/
%type <id> ASIGNACION
%type <num> LINEA EXP TER  


%%

/*Gramática Libre de Contexto*/

LINEA   : ASIGNACION ';'		{;}
		| LINEA ASIGNACION ';'	{;}
        ;

ASIGNACION : IDENTIFICADOR '=' exp  { updateSymbolVal($1,$3); }
			;
exp    	: term                  {$$ = $1;}
       	| exp '+' term          {$$ = $1 + $3;}
       	| exp '-' term          {$$ = $1 - $3;}
       	;
term   	: number                {$$ = $1;}
		| identifier			{$$ = symbolVal($1);} 
        ;

%%                     /* C code */

int computeSymbolIndex(char token)
{
	int idx = -1;
	if(islower(token)) {
		idx = token - 'a' + 26;
	} else if(isupper(token)) {
		idx = token - 'A';
	}
	return idx;
} 

/* returns the value of a given symbol */
int symbolVal(char symbol)
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol */
void updateSymbolVal(char symbol, int val)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main (void) {
	/* init symbol table */
	int i;
	for(i=0; i<52; i++) {
		symbols[i] = 0;
	}

	return yyparse ( );
}

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 

