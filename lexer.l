%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

extern int yyparse();
int line=1;

%}

%%

<INITIAL>"program"				{ return(PROGRAM); }

<INITIAL>"data"				{ return(DATA); }
<INITIAL>"procedure"				{ return(PROCEDURE); }
<INITIAL>"division"				{ return(DIVISION); }

<INITIAL>"get"				{ return(GET); }
<INITIAL>"set"				{ return(SET); }
<INITIAL>"put"				{ return(PUT); }
<INITIAL>"to"				{ return(TO); }

<INITIAL>"execute"				{ return(EXECUTE); }
<INITIAL>"repeat"				{ return(REPEAT); }

<INITIAL>"either"				{ return(EITHER); }
<INITIAL>"both"				{ return(BOTH); }
<INITIAL>"neither"				{ return(NEITHER); }

<INITIAL>"LT"				{ return(LT); }
<INITIAL>"LE"				{ return(LE); }
<INITIAL>"GT"				{ return(GT); }
<INITIAL>"GE"				{ return(GE); }
<INITIAL>"NE"				{ return(NE); }
<INITIAL>"EQ"				{ return(EQ); }

<INITIAL>"not"				{ return(NOT); }
<INITIAL>"nor"				{ return(NOR); }
<INITIAL>"and"				{ return(AND); }
<INITIAL>"or"				{ return(OR); }

<INITIAL>"/*"[^*]*[*]+([^*/][^*]*[*]+)*[/] { ; }

<INITIAL>"+"				{ return(ADD); }
<INITIAL>"-"				{ return(MIN); }
<INITIAL>"*"				{ return(MUL); }
<INITIAL>"/"				{ return(DIV); }

<INITIAL>"{"				{ return(SECTION_OPEN); }
<INITIAL>"}"				{ return(SECTION_CLOSE); }
<INITIAL>"("					{ return(LEFTPAREN); }
<INITIAL>")"					{ return(RIGHTPAREN); }

<INITIAL>"integer"				{ return(INTEGER); }
<INITIAL>"float"				{ return(FLOAT); }
<INITIAL>"char"				{ return(CHAR); }

<INITIAL>"unsigned"				{ return(UNSIGNED); }
<INITIAL>"end"				{ return(END); }


<INITIAL>","				{ return(SEMICOLON); }
<INITIAL>":"				{ return(COLON); }
<INITIAL>";"					{ return(COMMANDEND); }

[a-zA-Z][a-zA-Z0-9]*									{ yylval.string = strdup(yytext); return(ID); }
[1-9][0-9]*|\.[0-9]*|[1-9][0-9]\.|[1-9][0-9]*\.[0-9]*	{ yylval.string = strdup(yytext); return(NUMBER); }
\'(\\.|[^\\'\n])*\'										{ yylval.string = strdup(yytext); return(STRING); }
[ \t]				;
[\n] 	{
	line++;
}
%%

