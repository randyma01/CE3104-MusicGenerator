#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>



#include "mg.h"

extern int yylex();
extern int yylineno;
extern char* yytext;


void loopDef(int valorInicial, int incremento, int valorMaximo, int cantidadVeces, char nombreVariable){


}



int main(void) 
{

	int ntoken, vtoken, rtoken, stoken, ttoken, ktoken, atoken;

	ntoken = yylex();

	if(ntoken != INIMUSICA){
		printf("Syntax ERROR in line %d.  Expect to start with 'IniMusica'\n", yylineno);
		return 1;
	}

	while(ntoken == INIMUSICA) {
		vtoken = yylex();
		printf("current token: %d \n", vtoken );

		switch (vtoken) {
	
			case DEF:
				printf("Encontro un DEF: �hurray!\n");

			case SET:
				printf("Encontro un SET: �hurray!\n");

			case FUNC:
				if (yylex() == INICIO){
				//stokenFunc = yylex();
					int tokenFunc;	
					while(1){
						tokenFunc = yylex();
						if (tokenFunc == FINAL){
							break;
						}
						switch (tokenFunc){
							case DEF:
						
							case LOOP:
								printf("LOOP en un FUNC\n");
								printf("token current: %d\n", yylex());

							case SET:

							case NOTE:

							case NEG:

							case BLAK:

							case CORCH:

							case SCORCH:

							case INICOMP:

							case FINCOMP:

							case ENCASO:
								printf("ENCASO en un FUNC\n");
						}
					}
				}
				else{
					printf("Syntax ERROR in line %d, Expect to start with [Inicio]\n", yylineno);
				}

			case LOOP:
				printf("encontro un looop ffuera de una funcion\n");
				break;
				//loopDef(1, 2, 100, 2, 'C');		

			case NEG:
				printf("Encontro un bloque NEG: �Genial!\n");
				//fputs( "\nEncontro una negra\n", fptr);
				break;

			case NUMBER:
				printf("Encontro un numero: \n");
				printf("number: %d\n", atoi(yytext));
				printf("number esta en la linea: %d \n", yylineno);
				break;

				
			case FINMUSICA:
				printf("Encontro el token FunMusica: �He terminado!\n");
				ntoken = -1;
				break;

		
				
		}
		//ntoken = yylex();
	}
	//fclose(fptr);
	return 0;
}



