%{
#include "mg.h"
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

[A-Z][#][m]*                 {return NOTE;}
[a-zA-Z][(][)]               {return FUNC;}
[a-zA-Z]			         {return IDENTIFIER;}
[0-9]+                       {return NUMBER;}
[ \t\n]                      ;
[-+=;]           	         {return yytext[0];}
.                            {printf("Lexical ERROR in line %d, the character is not valid in this language\n",  yylineno);}

%%
int yywrap (void) {return 1;}2