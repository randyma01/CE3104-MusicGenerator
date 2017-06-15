#include "mg.h"

//Varias y archivos
std::ofstream instrFile;
std::ifstream tempFunc;

std::ofstream errorFile;
std::ofstream tempFileFunc;

std::string   nameProcess;
std::vector<std::string>   procedimientos; 	 

int lengthNameProcess;

/*Valores de los tiempos.*/
std::string negra = "NEGRA";
std::string blanca = "BLANCA";
std::string corchea = "CORCHEA";
std::string semicorchea = "SEMI"; 

void masMas(){}

void menosMenos(){}

/*
Metodo para el proceso "notas"
Escribe la nota con el tiempo respectivo
a para el piano.
*/
void notasTiempo(std::string tipo){
	int ctoken = yylex();

	if (ctoken == NOTA){ instrFile << yytext + tipo + "|";}

	if(ctoken == NOTA_SOSTENIDA){ instrFile << yytext + "|"; }
	
	if(ctoken == ACORDE_MAYOR){ instrFile << yytext + "|" }
	
	if(ctoken == ACORDE_MAYOR_SOSTENIDO){ instrFile << yytext + "|";}

	if(ctoken == ACORDE_MENOR){ instrFile << yytext + "|";}

	if(ctoken == ACORDE_MENOR_SOSTENIDO){ instrFile << yytext + "|";}
	
	else{ errorFile << "Syntax ERROR: no note after time. Line: " + yylineno; }
}

/*
Metodo para el proceso "EnCaso"
Retorna 0 si esta correcto 
Retorna -1 si hay error o no hay nada escrito en el
*/
int enCasoFunc(){
	int casosToken = yylex();
	if(casosToken == PARENTESIS_IZQ){
		
		int valorV = yylex();
		printf("variable: %s\n", yytext);
		int coma1 = yylex();
		
		int operador = yylex();
		printf("operador %s\n", yytext);
		coma1 = yylex();
		
		int valor = yylex();
		printf("valor: %s\n", yytext);
		coma1 = yylex();

		int parentesisDer = yylex();
	}
	else{
		errorFile << "Syntax ERROR in line: " << yylineno <<   " Expect to start with '(' \n";
		errorFile.close();
		return -1;
	}

	int nextToken = yylex();
	if (nextToken != ENTONCES){
		errorFile << "Syntax ERROR in line: " << yylineno <<   " Expect to start with 'Entonces.' \n";
		errorFile.close();
		return -1;
	}else{
		nextToken = yylex();
		if(nextToken != FINENCASO){
			while(true){
				nextToken = yylex();
					if (nextToken == CONTRARIO){
						break;
					}
					if (entoncesToken == 0){
						errorFile << "Syntax ERROR in line: " << yylineno <<   " Must have a 'Contrario' \n";
						errorFile.close();
						return -1;
					}

					if (nextToken == ENCASO){
						if (enCasoFunc() == 0){
							return 0;
						}else{
							return -1;
						}
					}
					
					if (nextToken == LOOP){
						if (loopFunc() == 0){
							return 0;
						}else{
							return -1;
						}
					}
					
					if (nextToken == DEF){}
					if (nextToken == SET) {}
					if (nextToken == EJECUTE){}	
					
					if (nextToken == INICOMP){
						while(true){
						nextToken = yylex();
						if(nextToken == FINCOMP){
							break;
						}
						if(nextToken == 0){
							errorFile << "Syntax ERROR in line: " << yylineno <<   " Finish with  'FinComp' \n";
							errorFile.close();
							return -1;
						}
						switch (nextToken){
							case BLAK:
								notasTiempo(blanca);
								break;
							case NEG:
								notasTiempo(negra);
								break;
							case SCORCH:
								notasTiempo(semicorchea);
								break;
							case CORCH:
								notasTiempo(corchea);
								//funcion Nota;
								break;
							}
						}
					}
		
				}
			}	
		}
	} 
}

void defFunc(){}

void funcFunc(){}

void setFunc(){}

void ejecuteFunc(){}

void silencFunc(){}


/*
Metodo para el proceso "Loop"
Retorna 0 si esta correcto o no hay nada escrito en el
Retorna -1 si hay error
*/
int loopFunc(){
	int loopToken = yylex();
	if(loopToken == PARENTESIS_IZQ){
		int valorI = yylex();
		printf("valor inicial: %s\n", yytext);
		int coma1 = yylex();
		int valorM = yylex();
		printf("valor maximo: %s\n", yytext);
		coma1 = yylex();
		int incremento = yylex();
		printf("valor incremento: %s\n", yytext);
		coma1 = yylex();
		int repeticion = yylex();
		printf("repetecicion: %s\n", yytext);
		coma1 = yylex();
		int variable = yylex();
		printf("variable: %s\n", yytext);
		int cierraLoop = yylex();
		printf("cerrar ): %s\n", yytext);
	}
	else{
		errorFile << "Syntax ERROR in line: " << yylineno <<   " Expect to start with '(' \n";
		errorFile.close();
		return -1;
	}
	
	int nextToken = yylex();
	if (nextToken != INILOOP){
		//printf("Syntax ERROR in line %d, Expect to start with 'IniLoop'\n", yylineno);
		errorFile << "Syntax ERROR in line: " << yylineno <<   " Expect to start with 'IniLoop' \n";
		errorFile.close();
		return -1;
	}else{
		nextToken = yylex();
		if (nextToken != FINLOOP){
			while(true){
				nextToken = yylex();
				if (nextToken == FINLOOP){
					//return 0;
					break;
				}
				if (nextToken == 0){
					errorFile << "Syntax ERROR in line: " << yylineno <<   " Finish with  'FinLoop' \n";
					errorFile.close();
					//printf("Syntax ERROR in line %d, Loop finish with 'FinLoop'\n", yylineno);
					return -1;
				}
				if (nextToken == INICOMP){
					while(true){
						nextToken = yylex();
						if(nextToken == FINCOMP){
							//return 0;
							break;
						}
						if(nextToken == 0){
							errorFile << "Syntax ERROR in line: " << yylineno <<   " Finish with  'FinComp' \n";
							errorFile.close();
							//printf("Syntax ERROR in line %d, Loop finish with 'FinLoop'\n", yylineno);
							return -1;
						}
						switch (nextToken){
							case BLAK:
								notasTiempo(blanca);
								//funcion Nota;
								break;
							case NEG:
								notasTiempo(negra);
								//funcion Nota;
								break;
							case SCORCH:
								notasTiempo(semicorchea);
								//funcion Nota;
								break;
							case CORCH:
								notasTiempo(corchea);
								//funcion Nota;
								break;
						}
					}
				}
				else{
					if(nextToken == LOOP){
						loopFunc();
					}
					if(nextToken == DEF){

					}
					if(nextToken == SET){

					}
					if(nextToken == NOTA){
						errorFile << "Syntax ERROR in line: " << yylineno <<   "Expect to start with 'IniComp' \n";
							errorFile.close();
							//printf("Syntax ERROR in line %d, Loop finish with 'FinLoop'\n", yylineno);
							return -1;
					}

				}
			}
			return 0;
		}
		else{
			return 0;
		}
	}

}


/*
Metodo para indicar si el nombre de un "Proceso" a ejecutar
esta declaro previamente
si no lo esta retorna false
si esta retorna true
*/
bool inVector(std::string name){
	int lengthVector = procedimientos.size();
	//printf("largo del vector: %d\n", lengthVector);
	
	for(int i = 0; i < lengthVector; i++){
		//printf("current in vector: %s\n", procedimientos[i].c_str() );
		//printf("name to find: %s\n", name.c_str());
		if (procedimientos[i] == name) {
			return true;
		}
	}
	return false;
}

/*
Metodo para el leer "Procesos" declarados
Retorna 0 si esta correcto 
Retorna -1 si hay error o no hay nada escrito en el
*/
int procesoFunc(){
	return 0;
}

/*
Metodo para el proceso "Principal"
Retorna 0 si esta correcto 
Retorna -1 si hay error o no hay nada escrito en el
*/
int principalFunc(){
	while(true){
		int currentToken = yylex();
		/*
		si encuentra FinMusica --> no hay nada en Principal
		*/
		if (currentToken ==  FINMUSICA){
			//printf("no hay ejecucion en PRINCIPAL!\n");
			return -1;
		}
		
		//caso para cuando se llame "Ejecute Proceso"
		if (currentToken == EJECUTE){
			int nextToken = yylex();
			std::string tempName;
			tempName = yytext;
			//printf("funcion!: %s\n", tempName.c_str());
			if (inVector(tempName)){
				tempFunc.open("funcion.txt");
				char output[1000000];
				if (tempFunc.is_open()) {
					while (!tempFunc.eof()) {
						tempFunc >> output;
					}
				}
				tempFunc.close();
				instrFile << output;
				return 0;
			}else{
				errorFile << "Syntax ERROR in line: " << yylineno << ". " << tempName << " not declared!\n";
				errorFile.close();
				//printf("Error! %s, no declarado!. In line %d\n", tempName.c_str(), yylineno);
				return -1;
			}
		}

		//caso para llamar "loop" desde "Principal"
		if (currentToken == LOOP){
			if (loopFunc() == 0){
				return 0;
			}else{
				return -1;
			}
		}

		//caso para llamar "Def" desde "Principal"
		if (currentToken == DEF){
		}


		//caso para llamar "SET" desde "Principal"
		if (currentToken == SET){
		}

		//caso para llamar "IniComp" desde 'Principal'
		if (currentToken == INICOMP){
			while(true){
				currentToken = yylex();
				if(currentToken == FINCOMP){
					//return 0;
					break;
				}
				if(currentToken == 0){
					errorFile << "Syntax ERROR in line: " << yylineno <<   " Finish with  'FinComp' \n";
					errorFile.close();
					//printf("Syntax ERROR in line %d, Loop finish with 'FinLoop'\n", yylineno);
					return -1;
				}
				switch (currentToken){
					case BLAK:
						notasTiempo(blanca);
						//funcion Nota;
						break;
					case NEG:
						notasTiempo(negra);
						//funcion Nota;
						break;
					case SCORCH:
						notasTiempo(semicorchea);
						//funcion Nota;
						break;
					case CORCH:
						notasTiempo(corchea);
						//funcion Nota;
						break;
				}
			}
		}
				
	}

}

int main(void){
	yyin = fopen("source_code.mg", "rt");
	//crear los archivos de salida
	errorFile.open ("errores.txt");
	instrFile.open ("instrucciones.txt");

	int vtoken;

	if(yylex() != INIMUSICA){
		errorFile << "Syntax ERROR in line: " << yylineno <<   " Expect to start with 'IniMusica' \n";
		errorFile.close();	
		//printf("Syntax ERROR in line %d.  Expect to start with 'IniMusica'\n", yylineno);
		return -1;
	}

	while(true) {
		vtoken = yylex();//printf("current token: %d \n", vtoken );


		//termina el ciclo cuando encuentra el token FinMusica
		if (vtoken ==  FINMUSICA){
			instrFile.close();
			//return 0;
			break;
		}

		//muestra error si no encuentra  el token FinMusica
		if (vtoken == 0){
			errorFile << "Syntax ERROR in line: " <<  (yylineno - 1) <<   " Finish with  'FinMusic'\n";
			errorFile.close();
			printf("Syntax ERROR in line %d. Finish with  'FinMusic\n", (yylineno- 1) );
			return -1;
		}

		

		switch (vtoken) {
			case FUNC:
				lengthNameProcess = (yyleng -2);  //menos los perentecis
 				nameProcess = yytext; // nameProcess.c_str(); //string to char *
				procedimientos.push_back( nameProcess.substr(0, lengthNameProcess) );
				
				tempFileFunc.open("funcion.txt");
				tempFileFunc << "funcion";
				tempFileFunc.close();
				break;
				
			case PRINCIPAL:
				if(principalFunc() == 0){
					break;
				}
				else{
					exit(-1);
				}
		}	
	}
	//printf("vector: %s\n", procedimientos[0].c_str());
	//printf("vector: %s\n", procedimientos[1].c_str());

	return 0;
}
