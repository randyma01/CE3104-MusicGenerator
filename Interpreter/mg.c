#include <stdio.h>


#include <string>

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
"Entonces",
"Note"
"Identifier",
"Number"};

void Loop(int valorInicial, int incremento, int valorMaximo, int cantidadVeces,
			std::string nombreVariable);

int main(void) 
{

	int ntoken, vtoken, rtoken, stoken, ttoken, ktoken, atoken;

	ntoken = yylex();

	while(ntoken) {
		if(yylex() != INIMUSICA){
			printf("Syntax ERROR in line %d.  Expect to start with 'IniMusica' but found %s\n", yylineno, yytext);
			return 1;
		}
		vtoken = yylex();

		switch (ntoken) {

			case DEF:
				printf("Encontré un DEF: ¡hurray!"); 

			case SET:
				printf("Encontré un SEF: ¡hurray!"); 
 
			case LOOP:
				Loop(1, 2, 100, 2, "C"); 

			case PRINCIPAL:
				printf("Encontré un bloque Principal: ¡Genial!");
				
			case FINMUSICA:
				printf("Encontré el token FunMusica: ¡He terminado SÍ!");
				break;

			default:
				printf("Syntax ERROR in line %d\n",yylineno);
		}
		ntoken = yylex();
	}
	return 0;
}



void Loop(int valorInicial, int incremento, int valorMaximo, int cantidadVeces,
			std::string nombreVariable){


				
}

