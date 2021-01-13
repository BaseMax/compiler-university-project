%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "sds.h"

	#define YYERROR_VERBOSE 1

	extern FILE *yyin;
	extern int yylex();
	extern void yyerror(char const* msg);
	extern int line;
	#define BUFER_SIZE 1024
	char buffer[BUFER_SIZE];

	typedef struct str {
		char * val;
		size_t cap;
		size_t len;
	} str;

%}

%output "parser.c"
%defines "parser.h"

%union
{
	sds string;
	//buffer_t *string;
	//char *string;
}

%token <string> PROGRAM
%token <string> DATA
%token <string> PROCEDURE
%token <string> DIVISION
%token <string> GET

%token <string> PUT
%token <string> TO
%token <string> EXECUTE
%token <string> REPEAT
%token <string> EITHER
%token <string> BOTH
%token <string> NEITHER

%left <string> LT
%left <string> LE
%left <string> GT
%left <string> GE
%left <string> NE
%left <string> EQ

%right <string> NOT

%left <string> AND
%left <string> OR
%left <string> NOR
%left <string> ADD
%left <string> SUB
%left <string> MUL
%left <string> DIV

%right <string> SET

%left <string> LEFTPAREN
%left <string> RIGHTPAREN

%token <string> SECTION_OPEN
%token <string> SECTION_CLOSE

%token <string> INTEGER
%token <string> FLOAT
%token <string> CHAR
%token <string> END
%token <string> SEMICOLON
%token <string> COLON
%token <string> COMMANDEND
%token <string> ID
%token <string> NUMBER
%token <string> STRING
%token <string> UNSIGNED


%type<string> heading
%type<string> data_part
%type<string> exe_part

%type <string> data_body
%type <string> data_stmt

%type <string> type
%type <string> id_list

%type <string> stmt_list
%type <string> stmt_list_or_no
%type <string> stmt

%type <string> assgn_stmt
//%type <string> index
//%type <string> no

%type <string> in_stmt
%type <string> out_stmt

%type <string> in_list
%type <string> out_list

%type <string> loop_stmt
%type <string> cond1_stmt

%type <string> structure

%type <string> condition
%type <string> expression


%start program
%%

program: structure {
		// INIT
		// printf("%s", $1);
	}
	;

structure: heading data_part exe_part {
		// $$ = sdsnew("#include <iostream>\n\nusing namespace std;\n\n");
		// sdscat($$, $2);
		// sdscat($$, $3);

		printf("%s", $1);
		printf("#include <iostream>\n\nusing namespace std;\n\n");
		printf("%s", $2);
		printf("int main()\n{\n");
		printf("%s", $3);
		printf("return 0;\n}\n");
	}
	| {
		$$ = sdsnew("// empty program\n");
	}
	;

heading: PROGRAM ID COLON {
		$$ = sdsnew("// Program ");
		$$ = sdscat($$, $2);
		$$ = sdscat($$, "\n");
	}
	| {
		$$ = sdsempty();
	}
	;

data_part: DATA DIVISION COMMANDEND data_body END COMMANDEND {
		$$ = sdsnew($4);
	}
	| {
		$$ = sdsempty();
	}
	;

data_body: data_stmt {
		$$ = sdsnew($1);
	}
	| data_stmt data_body {
		$$ = sdsnew($1);
		$$ = sdscat($$, $2);
	}
	;

data_stmt: id_list COLON type COMMANDEND {
		$$ = sdsnew($3);
		$$ = sdscat($$, " ");
		$$ = sdscat($$, $1);
		$$ = sdscat($$, ";\n");
	}
	;

id_list: ID {
		$$ = sdsnew($1);
	}
	| ID SEMICOLON id_list {
		$$ = sdsnew($1);
		$$ = sdscat($$, ",");
		$$ = sdscat($$, $3);
	}
	;

type: INTEGER {
		$$ = sdsnew("int");
	}
	| FLOAT {
		$$ = sdsnew("float");
	}
	| CHAR {
		$$ = sdsnew("char");
	}
	;

exe_part: PROCEDURE DIVISION COMMANDEND stmt_list_or_no END COMMANDEND {
		// $$ = sdsnew("int main()\n{\n");
		// $$ = sdscat($$, $4);
		// $$ = sdscat($$, "return 0;\n}\n");
		$$ = sdsnew($4);
	}
	;

stmt_list_or_no: stmt_list {
		$$ = sdsnew($1);
	}
	| {
		$$ = sdsnew("// empty stmts\n");
	}
	;

stmt_list: stmt {
		$$ = $1;
	}
	| stmt stmt_list {
		$$ = sdsnew($1);
		$$ = sdscat($$, $2);
	}
	;

stmt: assgn_stmt { $$ = $1; }
	| in_stmt { $$ = $1; }
	| out_stmt { $$ = $1; }
	| loop_stmt { $$ = $1; }
	| cond1_stmt { $$ = $1; }
	;

assgn_stmt: SET ID TO expression COMMANDEND {
		$$ = sdsnew($2);
		$$ = sdscat($$, " = ");
		$$ = sdscat($$, $4);
		$$ = sdscat($$, ";\n");
	}
	;

//index: ID | NUMBER | ID SEMICOLON index | NUMBER SEMICOLON index
//	;

//no: UNSIGNED
//	| INTEGER
//	;

in_stmt: GET in_list COMMANDEND {
		$$ = sdsnew("cin >> ");
		$$ = sdscat($$, $2);
		$$ = sdscat($$, ";\n");
	}
	;

in_list: ID {
		$$ = sdsnew($1);
	}
	| ID SEMICOLON in_list {
		// sprintf($$, "%s%s", $1, $2);
		$$ = sdsnew($1);
		$$ = sdscat($$, " >> ");
		$$ = sdscat($$, $2);
	}
	;

out_stmt: PUT out_list COMMANDEND {
		$$ = sdsnew("cout << ");
		$$ = sdscat($$, $2);
		$$ = sdscat($$, ";\n");
	}
	;

out_list: ID SEMICOLON out_list {
		$$ = sdsnew($1);
		$$ = sdscat($$, " << ");
		$$ = sdscat($$, $2);
	}
	| ID {
		$$ = sdsnew($1);
	}
	;

loop_stmt: REPEAT SECTION_OPEN stmt_list_or_no SECTION_CLOSE condition {
		$$ = sdsnew("while( ");
		$$ = sdscat($$, $5);
		$$ = sdscat($$, " ) {\n");
		$$ = sdscat($$, $3);
		$$ = sdscat($$, "}\n");
	}
	;

cond1_stmt: EXECUTE SECTION_OPEN stmt_list_or_no SECTION_CLOSE COMMANDEND {
		$$ = sdsnew("// execute\n");
		// $$ = sdscat($$, $5);
		// $$ = sdscat($$, " ) {\n");
		$$ = sdscat($$, "{\n");
		$$ = sdscat($$, $3);
		$$ = sdscat($$, "}\n");
	}
	;

condition: EITHER expression COMMANDEND {
		$$ = sdsnew($1);
		$$ = sdscat($$, $2);
		// $$ = sdscat($$, " OR ");
		// $$ = sdscat($$, $3);
	}
	| NEITHER expression COMMANDEND {
		$$ = sdsnew($1);
		$$ = sdscat($$, $2);
		// $$ = sdscat($$, " NOR ");
		// $$ = sdscat($$, $3);
	}
	| BOTH expression COMMANDEND {
		$$ = sdsnew($1);
		$$ = sdscat($$, $2);
		// $$ = sdscat($$, " AND ");
		// $$ = sdscat($$, $3);
	}
	;

expression:
	 SUB expression {
		$$ = sdsnew("- ");
		$$ = sdscat($$, $2);
	}
	| NOT expression {
		$$ = sdsnew("! ");
		$$ = sdscat($$, $2);
	}
	| expression GT expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " > ");
		$$ = sdscat($$, $3);
	}
	| expression GE expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " >= ");
		$$ = sdscat($$, $3);
	}
	| expression LT expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " < ");
		$$ = sdscat($$, $3);
	}
	| expression LE expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " <= ");
		$$ = sdscat($$, $3);
	}
	| expression AND expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " && ");
		$$ = sdscat($$, $3);
	}
	| expression OR expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " || ");
		$$ = sdscat($$, $3);
	}
	| ID {
		$$ = $1;
	}
	| STRING {
		$$ = $1;
	}
	| NUMBER {
		$$ = $1;
	}
	| expression DIV expression {
		// if ($3 == 0) { yyerror("Cannot divide by zero"); exit(1); } else {}
		$$ = sdsnew($1);
		$$ = sdscat($$, " / ");
		$$ = sdscat($$, $3);
	}
	| expression MUL expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " * ");
		$$ = sdscat($$, $3);
	}
	| LEFTPAREN expression RIGHTPAREN {
		$$ = sdsnew("( ");
		$$ = sdscat($$, $2);
		$$ = sdscat($$, " )");
	}
	| expression ADD expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " + ");
		$$ = sdscat($$, $3);
	}
	| expression SUB expression {
		$$ = sdsnew($1);
		$$ = sdscat($$, " - ");
		$$ = sdscat($$, $3);
	}
	;

%%

int yywrap()
{
	return 1;
}

void yyerror(char const* msg)
{
	// fprintf(stderr, "[%d]:%s\n", line, msg);
}

int main(int argc, char *argv[])
{
	// Read a file
	if(argc > 1)
		yyin = fopen(argv[1], "r");

	// Parse
	yyparse();

	return 0;
}

