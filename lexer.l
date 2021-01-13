%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sds.h"

//#ifndef YYSTYPE
//	#define YYSTYPE char*
//#endif

#include "parser.h"

extern int yyparse();
int line=1;


%}

%option yylineno
%x COMMENT

%%

<INITIAL>"/*"       { BEGIN(COMMENT); }
<COMMENT>"*/"       { BEGIN(INITIAL); }
<COMMENT>\n         { line++; }
<COMMENT>.          { ; }

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

<INITIAL>"lt"				{ return(LT); }
<INITIAL>"le"				{ return(LE); }
<INITIAL>"gt"				{ return(GT); }
<INITIAL>"ge"				{ return(GE); }
<INITIAL>"ne"				{ return(NE); }
<INITIAL>"eq"				{ return(EQ); }

<INITIAL>"not"				{ return(NOT); }
<INITIAL>"nor"				{ return(NOR); }
<INITIAL>"and"				{ return(AND); }
<INITIAL>"or"				{ return(OR); }

<INITIAL>"+"				{ return(ADD); }
<INITIAL>"-"				{ return(SUB); }
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

[1-9][0-9]*|\.[0-9]*|[1-9][0-9]\.|[1-9][0-9]*\.[0-9]*	{ yylval.string = sdsnew(yytext); return(NUMBER); }
[a-zA-Z][a-zA-Z0-9]*									{ yylval.string = sdsnew(yytext); return(ID); }
\'(\\.|[^\\'\n])*\'										{ yylval.string = sdsnew(yytext); return(STRING); }
[ \t]				;
[\n] 	{
	line++;
}
%%

