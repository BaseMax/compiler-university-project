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
%token <string> SET
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

%token <string> SECTION_OPEN
%token <string> SECTION_CLOSE
%token <string> LEFTPAREN
%token <string> RIGHTPAREN
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

%type <string> program

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
%type <string> logical_exp
%type <string> elem1
%type <string> elem2
%type <string> elem3
%type <string> rel_exp
%type <string> t1
%type <string> rel_op
%type <string> math_exp
%type <string> term
%type <string> factor
%type <string> element
%type <string> structure

%type <string> condition


%start program
%%

program: structure {
		//printf("%s", $1);
	}
	;

structure: heading data_part exe_part {
		printf("%s", $1);
		printf("%s", $2);
		printf("%s", $3);
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
	;

data_part: DATA DIVISION COMMANDEND data_body END COMMANDEND {
		$$ = sdsnew($4);
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
		$$ = sdscat($$, $2);
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
		$$ = sdsnew("#include <stdio.h>\n\nint main()\n{\n");
		$$ = sdscat($$, $4);
		$$ = sdscat($$, "return 0;\n}\n");
	}
	;

stmt_list_or_no: stmt_list {
		$$ = sdsnew($1);
	}
	| {
		$$ = sdsnew("// empty stmts\n");
	}
	;

stmt_list: stmt { $$ = $1; }
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

assgn_stmt: SET ID TO math_exp COMMANDEND {
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
		$$ = sdsnew("get ");
		$$ = sdscat($$, $2);
		$$ = sdscat($$, ";\n");
	}
	;

in_list: ID {
		$$ = $1;
	}
	| ID SEMICOLON in_list {
		// sprintf($$, "%s%s", $1, $2);
	}
	;

out_stmt: PUT out_list COMMANDEND {
	}
	;

out_list: ID SEMICOLON out_list | ID {
	}
	;

loop_stmt: REPEAT SECTION_OPEN stmt_list_or_no SECTION_CLOSE condition COMMANDEND {
		$$ = sdsnew("while( ");
		$$ = sdscat($$, $5);
		$$ = sdscat($$, " ) {\n");
		$$ = sdscat($$, $3);
		$$ = sdscat($$, "}\n");
	}
	;

condition: EITHER logical_exp OR logical_exp {
		$$ = sdsnew($1);
		$$ = sdscat($$, " OR ");
		$$ = sdscat($$, $3);
	}
	| NEITHER logical_exp NOR logical_exp {
		$$ = sdsnew($1);
		$$ = sdscat($$, " NOR ");
		$$ = sdscat($$, $3);
	}
	| BOTH logical_exp AND logical_exp {
		$$ = sdsnew($1);
		$$ = sdscat($$, " AND ");
		$$ = sdscat($$, $3);
	}
	;

cond1_stmt: EXECUTE SECTION_OPEN stmt_list_or_no SECTION_CLOSE condition COMMANDEND {
		$$ = sdsnew("execute( ");
		$$ = sdscat($$, $5);
		$$ = sdscat($$, " ) {\n");
		$$ = sdscat($$, $3);
		$$ = sdscat($$, "}\n");
	}
	;

logical_exp: logical_exp OR elem1 {
		$$ = sdsnew($1);
		$$ = sdscat($$, " OR ");
		$$ = sdscat($$, $3);
	}
	| elem1 {
		$$ = sdsnew($1);
	}
	;

elem1: elem1 AND elem2 {
		$$ = sdsnew($1);
		$$ = sdscat($$, " AND ");
		$$ = sdscat($$, $3);
	}
	| elem2 {
		$$ = sdsnew($1);
	}
	;

elem2: NOT elem2 {
		$$ = sdsnew("NOT ");
		$$ = sdscat($$, $2);
	}
	| elem3 {
		$$ = sdsnew($1);
	}
	;

elem3: LEFTPAREN logical_exp RIGHTPAREN {
		$$ = sdsnew("( ");
		$$ = sdscat($$, $2);
		$$ = sdscat($$, " )");
	}
	| rel_exp {
		$$ = sdsnew($1);
	}
	;


rel_exp: t1 rel_op t1 {
		$$ = sdsnew($1);
		$$ = sdscat($$, " ");
		$$ = sdscat($$, $2);
		$$ = sdscat($$, " ");
		$$ = sdscat($$, $3);
	}
	;

t1: math_exp {
		$$ = sdsnew($1);
	}
	;

rel_op: LT {
		$$ = sdsnew("<");
	}
	| LE {
		$$ = sdsnew("<=");
	}
	| GT {
		$$ = sdsnew(">");
	}
	| GE {
		$$ = sdsnew(">=");
	}
	| NE {
		$$ = sdsnew("!=");
	}
	| EQ {
		$$ = sdsnew("==");
	}
	;

math_exp: math_exp ADD term {
		$$ = sdsnew($1);
		$$ = sdscat($$, " + ");
		$$ = sdscat($$, $3);
	}
	| math_exp SUB term {
		$$ = sdsnew($1);
		$$ = sdscat($$, " - ");
		$$ = sdscat($$, $3);
	}
	| term {
		$$ = sdsnew($1);
	}
	;

term: term MUL factor {
		$$ = sdsnew($1);
		$$ = sdscat($$, " * ");
		$$ = sdscat($$, $3);
	}
	| term DIVISION factor {
		$$ = sdsnew($1);
		$$ = sdscat($$, " / ");
		$$ = sdscat($$, $3);
	}
	| factor {
		$$ = $1;
	}
	;

factor: SUB factor {
		$$ = sdsnew("-");
		$$ = sdscat($$, $2);
	}
	| element {
		$$ = sdsnew($1);
	}
	;

element: LEFTPAREN math_exp RIGHTPAREN {
		$$ = sdsnew("(");
		$$ = sdscat($$, $2);
		$$ = sdscat($$, ")");
	}
	| ID {
		$$ = sdsnew($1);
	}
	| NUMBER {
		$$ = sdsnew($1);
	}
	| STRING {
		$$ = sdsnew($1);
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

