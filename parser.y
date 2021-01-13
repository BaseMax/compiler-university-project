%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "buffer.h"

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
	buffer_t *string;
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


%start program
%%

program: structure {
		printf("%s", $1);
	}
	;

structure: heading data_part exe_part {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, buffer_string($2));
		buffer_append($$, buffer_string($3));
	}
	| {
		$$ = buffer_new_with_string("// empty program\n");
	}
	;

heading: PROGRAM ID COLON {
		$$ = buffer_new_with_string("// Program ");
		buffer_append($$, buffer_string($2));
		buffer_append($$, "\n");
	}
	;

data_part: DATA DIVISION COMMANDEND data_body END COMMANDEND {
		$$ = buffer_new_with_string(buffer_string($4));
	}
	;

data_body: data_stmt {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	| data_stmt data_body {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, buffer_string($2));
	}
	;

data_stmt: id_list COLON type COMMANDEND {
		$$ = buffer_new_with_string(buffer_string($3));
		buffer_append($$, " ");
		buffer_append($$, buffer_string($1));
		buffer_append($$, ";\n");
	}
	;

id_list: ID {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	| ID SEMICOLON id_list {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, ",");
		buffer_append($$, buffer_string($2));
	}
	;

type: INTEGER {
		$$ = buffer_new_with_string("int");
	}
	| FLOAT {
		$$ = buffer_new_with_string("float");
	}
	| CHAR {
		$$ = buffer_new_with_string("char");
	}
	;

exe_part: PROCEDURE DIVISION COMMANDEND stmt_list_or_no END COMMANDEND {
		$$ = buffer_new_with_string("#include <stdio.h>\n\nint main()\n{\n");
		buffer_append($$, buffer_string($4));
		buffer_append($$, "return 0;\n}\n");
	}
	;

stmt_list_or_no: stmt_list {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	| {
		$$ = buffer_new_with_string("// empty stmts\n");
	}
	;

stmt_list: stmt { $$ = $1; }
	| stmt stmt_list {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, buffer_string($2));
	}
	;

stmt: assgn_stmt { $$ = $1; }
	| in_stmt { $$ = $1; }
	| out_stmt { $$ = $1; }
	| loop_stmt { $$ = $1; }
	| cond1_stmt { $$ = $1; }
	;

assgn_stmt: SET ID TO math_exp COMMANDEND {
		$$ = buffer_new_with_string(buffer_string($2));
		buffer_append($$, " = ");
		buffer_append($$, buffer_string($4));
		buffer_append($$, ";\n");
	}
	;

//index: ID | NUMBER | ID SEMICOLON index | NUMBER SEMICOLON index
//	;

//no: UNSIGNED
//	| INTEGER
//	;

in_stmt: GET in_list COMMANDEND {
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
	}
	;

condition: EITHER logical_exp OR logical_exp
	| NEITHER logical_exp NOR logical_exp
	| BOTH logical_exp AND logical_exp
	;

cond1_stmt: EXECUTE SECTION_OPEN stmt_list_or_no SECTION_CLOSE condition COMMANDEND {

	}
	;

logical_exp: logical_exp OR elem1 {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, " OR ");
		buffer_append($$, buffer_string($3));
	}
	| elem1 {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	;

elem1: elem1 AND elem2 {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, " AND ");
		buffer_append($$, buffer_string($3));
	}
	| elem2 {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	;

elem2: NOT elem2 {
		$$ = buffer_new_with_string("NOT ");
		buffer_append($$, buffer_string($2));
	}
	| elem3 {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	;

elem3: LEFTPAREN logical_exp RIGHTPAREN {
		$$ = buffer_new_with_string("( ");
		buffer_append($$, buffer_string($2));
		buffer_append($$, " )");
	}
	| rel_exp {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	;


rel_exp: t1 rel_op t1 {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, " ");
		buffer_append($$, buffer_string($2));
		buffer_append($$, " ");
		buffer_append($$, buffer_string($3));
	}
	;

t1: math_exp {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	;

rel_op: LT {
		$$ = buffer_new_with_string("LT");
	}
	| LE {
		$$ = buffer_new_with_string("LE");
	}
	| GT {
		$$ = buffer_new_with_string("GT");
	}
	| GE {
		$$ = buffer_new_with_string("GE");
	}
	| NE {
		$$ = buffer_new_with_string("NE");
	}
	| EQ {
		$$ = buffer_new_with_string("EQ");
	}
	;

math_exp: math_exp ADD term {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, " ADD ");
		buffer_append($$, buffer_string($3));
	}
	| math_exp SUB term {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, " SUB ");
		buffer_append($$, buffer_string($3));
	}
	| term {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	;

term: term MUL factor {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, " * ");
		buffer_append($$, buffer_string($3));
	}
	| term DIVISION factor {
		$$ = buffer_new_with_string(buffer_string($1));
		buffer_append($$, " / ");
		buffer_append($$, buffer_string($3));
	}
	| factor {
		$$ = $1;
	}
	;

factor: SUB factor {
		$$ = buffer_new_with_string("-");
		buffer_append($$, buffer_string($2));
	}
	| element {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	;

element: LEFTPAREN math_exp RIGHTPAREN {
		$$ = buffer_new_with_string("(");
		buffer_append($$, buffer_string($2));
		buffer_append($$, ")");
	}
	| ID {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	| NUMBER {
		$$ = buffer_new_with_string(buffer_string($1));
	}
	| STRING {
		$$ = buffer_new_with_string(buffer_string($1));
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

