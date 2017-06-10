#include <stdio.h>
#include "mg.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names[] = 
{NULL,                       
"Set",
"Def",
"Principal",
"Loop",
"IniLoop",
"FinLoop",
"Blak",
"Neg",
"Corch",
"Scorch",
"IniComp",
"FinComp",
"IniMusica",
"FinMusica",
"EnCaso",
"Contrario",
"FinEnCaso",
"Ejecute",
"Silenc",
"ValorInicial",
"Salto",
"ValorMaximo",
"CantidadReiteros",
"Contador",
"Variable",
"Operador",
"Valor",
"Entonces"};

int main(void) 
{

	int ntoken, vtoken, rtoken, stoken, ttoken, ktoken, atoken;

	ntoken = yylex();
	while(ntoken) {
		if(yylex() != INIMUSICA){
			printf("Syntax ERROR in line %d.  Expect to start with 'IniMusica' but found %s\n", yylineno, yytext);
			return 1;
}
		}
		vtoken = yylex();
		/*rtoken = yylex();
		stoken = yylex();
		ttoken = yylex();
		ktoken = yylex();
		atoken = yylex();*/

		switch (ntoken) {

			case DEF: 

			case SET: 

			case LOOP:
				switch(vtoken){
					case EnCaso:
					case Entonces:

				} 

			case PRINCIPAL:
			
			
			case FINMUSICA:

			default:
				printf("Syntax ERROR in line %d\n",yylineno);
		}
		ntoken = yylex();
	}
	return 0;
}