%{
#include "y.tab.h"
%}
%%

:                            {return COLON;}
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
"ValorInicial"               {return VALOR_INICIAL;}
"Salto"                      {return SALTO;}
"ValorMaximo"                {return VALOR_MAXIMO;}
"CantidadReiteros"           {return CANTIDAD_REITEROS;}
"Contador"                   {return CONTADOR;}
"Variable"                   {return VARIABLE;}
"Operador"                   {return OPERADOR;}
"Valor"                      {return VALOR;}
"Entonces"                   {return ENTONCES;}


[A-G][#][m][^]               {yylval.id = yytext[0]; return NOTE;}

[a-zA-Z]			         {yylval.id = yytext[0]; return IDENTIFIER;}
[0-9]+                       {yylval.num = atoi(yytext); return NUMBER;}
[ \t\n]                      ;
'/*'                         ;
[-+=;<>]           	         {return yytext[0];}
.                            {ECHO; yyerror ("Lexical ERROR, the character is not valid in this language.");}

%%
int yywrap (void) {return 1;}

