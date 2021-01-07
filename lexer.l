%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

extern int yyparse();
int line=1;
%}

%%
"program"				{ return(PROGRAM); }

"data"				{ return(DATA); }
"procedure"				{ return(PROCEDURE); }
"division"				{ return(DIVISION); }

"get"				{ return(GET); }
"set"				{ return(SET); }
"put"				{ return(PUT); }
"to"				{ return(TO); }

"execute"				{ return(EXECUTE); }
"repeat"				{ return(REPEAT); }

"either"				{ return(EITHER); }
"both"				{ return(BOTH); }
"neither"				{ return(NEITHER); }

"LT"				{ return(LT); }
"LE"				{ return(LE); }
"GT"				{ return(GT); }
"GE"				{ return(GE); }
"NE"				{ return(NE); }
"EQ"				{ return(EQ); }

"not"				{ return(NOT); }
"and"				{ return(AND); }
"nor"				{ return(NOR); }


"+"				{ return(ADD); }
"-"				{ return(MIN); }
"*"				{ return(MUL); }
"/"				{ return(DIV); }

"{"				{ return(SECTION_OPEN); }
"}"				{ return(SECTION_CLOSE); }
"("					{ return(LEFTPAREN); }
")"					{ return(RIGHTPAREN); }

"integer"				{ return(INTEGER); }
"float"				{ return(FLOAT); }
"char"				{ return(CHAR); }

"unsigned"				{ return(UNSIGNED); }
"end"				{ return(END); }


","				{ return(SEMICOLON); }
":"				{ return(COLON); }
";"					{ return(COMMANDEND); }

[a-zA-Z][a-zA-Z0-9]*									{ yylval.string = strdup(yytext); return(ID); }
[1-9][0-9]*|\.[0-9]*|[1-9][0-9]\.|[1-9][0-9]*\.[0-9]*	{ yylval.string = strdup(yytext); return(NUMBER); }
\'(\\.|[^\\'\n])*\'										{ yylval.string = strdup(yytext); return(STRING); }
[ \t]				;
[\n] 	{
	line++;
}
%%

