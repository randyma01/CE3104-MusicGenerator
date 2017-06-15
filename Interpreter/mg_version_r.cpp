#include "mg.h"

//Varias y archivos
std::ofstream instrFile;
std::ifstream tempFunc;

std::ofstream errorFile;
std::ofstream tempFileFunc;

std::string nameProcess;

std::string nombreVariable;
std:: string igualSet;
int valorVariable

std::vector<std::string>   procedimientos; 	 

int lengthNameProcess;

/*Valores de los tiempos.*/
std::string negra = "NEGRA";
std::string blanca = "BLANCA";
std::string corchea = "CORCHEA";
std::string semicorchea = "SEMI"; 
std::string silencio = "SILE";

void masMas(){
    valorVariable++;
}

void menosMenos(){
    valorVaribale--;
}


void defFunc(){
    nomVar = yylex();
    nombreVariable = nombreVariable
    yylex();
    valor = yylex();
    int valorVariable = valor;
}

void setFunc(){
    nomVar = yylex();
     if(nomVar == nombreVariable){
         yylex();
         valor = yylex();
         valorVariable += valor;
     }else{
         defFunc();
     }
}

/*
Metodo para el proceso "Silenc"
Retorna un silencio para ser ejecutado
*/
void silencFunc(){
	instrFile << silencio;
}


