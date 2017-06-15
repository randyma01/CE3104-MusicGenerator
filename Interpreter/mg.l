%{
#include "mg.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <fstream>
%}
%option nounput yylineno

%%

"SET"                        {return SET;}
"Def"                        {return DEF;}
"Principal"                  {return PRINCIPAL;}
"Loop"                       {return LOOP;}
"IniLoop"                    {return INILOOP;}
"FinLoop"                    {return FINLOOP;}
"Blak"                       {return BLAK;}
"Neg"                        {return NEG;}
"Corch"                      {return CORCH;}
"Scorch"                     {return SCORCH;}
"IniComp"                    {return INICOMP;}
"FinComp"                    {return FINCOMP;}
"IniMusica"                  {return INIMUSICA;}
"FinMusica"                  {return FINMUSICA;}
"EnCaso"                     {return ENCASO;}
"Contrario"                  {return CONTRARIO;}
"FinEnCaso"                  {return FINENCASO;}
"Ejecute"                    {return EJECUTE;}
"Silenc"                     {return SILENC;}
"Entonces"                   {return ENTONCES;}
"Inicio"                     {return INICIO;}
"Final"                      {return FINAL;}


[A-G][N][o][t][a]            { return NOTA;}
[A-G][Nota][#]               {return NOTA_SOSTENIDA;}
[A-G][M]                     {return ACORDE_MAYOR;}
[a-g][M][#]                  {return ACORDE_MAYOR_SOSTENIDO;}
[A-G][m]                     {return ACORDE_MENOR;}
[A-G][m][#]                  {return ACORDE_MENOR_SOSTENIDO;}

[(]                          {return PARENTESIS_IZQ;}
[)]                          {return PARENTESIS_DER;}
[/*]                         ;
[a-zA-Z]+[(][)]              {return FUNC;}
[a-zA-Z]+			         {return IDENTIFIER;}
[0-9]+                       {return NUMBER;}
[ \t\n]                      ;
[-+=,;]           	         {return yytext[0];}
.                            {printf("Lexical ERROR in line %d, the character is not valid in this language.\n",  yylineno);}

%%
int yywrap (void) {return 1;}
