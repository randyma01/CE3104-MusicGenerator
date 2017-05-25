%{
#include "y.tab.h"
%}
%%


:                            {return COLON;}
"SET"                        {return SET;}
"DEF"                        {return DEF}
"Principal"                  {return PRINICPAL}
"Loop"                       {return LOOP}
"IniLoop"                    {return INILOOP}
"FinLoop"                    {return FINLOOP}
"Blak"                       {return BLACk}
"Neg"                        {return CORCH}
"Corch"                      {return BLAK}
"Scorch"                     {return SCORCH}
"IniComp"                    {return INICOMP}
"FinComp"                    {return FINCOMP}
"IniMusica"                  {return INIMUSICA}
"FinMusica"                  {return FINMUSICA}
"EnCaso"                     {return ENCASO}
"Contrario"                  {return CONTRARIO}
"FinCaso"                    {return FINENCASO}
"Ejecute"                    {return EJECUTE}
"Silenc"                     {return SILENC}

[CDEFGAB][#][m][^]*          {return NOTE;}


[a-z]			       {yylval.id = yytext[0]; return identifier;}
[0-9]+                 {yylval.num = atoi(yytext); return number;}
[ \t\n/*]               ;
[-+=;<>]           	   {return yytext[0];}
.                      //{ECHO; yyerror ("unexpected character");}  //printf("ERROR. The unexpected character.");


%%
int yywrap (void) {return 1;}

