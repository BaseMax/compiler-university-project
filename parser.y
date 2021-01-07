%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#define BUF_SIZE 9192
	#define TABLE_SIZE 256
	#define SYMBOL_SIZE 128

	extern FILE *yyin;
	extern int yylex();
	extern void yyerror(char const* msg);
	
	typedef struct symbol {
		char symbol[SYMBOL_SIZE];
	}SYMBOL;

	extern int line;
%}

%union
{
	char *string;
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
%token <string> LT
%token <string> LE
%token <string> GT
%token <string> GE
%token <string> NE
%token <string> EQ
%token <string> NOT
%token <string> AND
%token <string> OR
%token <string> NOR
%token <string> ADD
%token <string> MIN
%token <string> MUL
%token <string> DIV
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

%left MUL DIV
%left ADD SUB
%right ASSIGN

%start program
%%

program: heading data_part exe_part
	;
heading: PROGRAM ID COLON {
		printf("// Program %s\n", $2);
	}
	;

data_part: DATA DIVISION COMMANDEND data_body END COMMANDEND {

	}
	;

data_body: data_stmt { $$ = $1; }
	| data_stmt data_body { sprintf($$, "%s%s", $1, $2); }
	;

data_stmt: id_list COLON type COMMANDEND
	;

id_list: ID { $$ = $1; }
	| ID SEMICOLON id_list { sprintf($$, "%s%s", $1, $2); }
	;

type: INTEGER
	| FLOAT
	| CHAR
	;

exe_part: PROCEDURE DIVISION COMMANDEND stmt_list END COMMANDEND
	;

stmt_list: stmt { $$ = $1; }
	| stmt stmt_list { sprintf($$, "%s%s", $1, $2); }
	;

stmt: assgn_stmt { $$ = $1; }
	| in_stmt
	| out_stmt
	| loop_stmt
	| cond1_stmt
	;

assgn_stmt: SET ID TO math_exp COMMANDEND
	| SET ID TO STRING COMMANDEND
	;

//index: ID | NUMBER | ID SEMICOLON index | NUMBER SEMICOLON index
//	;

//no: UNSIGNED
//	| INTEGER
//	;

in_stmt: GET in_list COMMANDEND
	;

in_list: ID SEMICOLON in_list | ID
	;

out_stmt: PUT out_list COMMANDEND
	;

out_list: ID SEMICOLON out_list | ID
	;

loop_stmt: REPEAT SECTION_OPEN stmt_list SECTION_CLOSE condition COMMANDEND
	;

condition: EITHER logical_exp OR logical_exp
	| NEITHER logical_exp NOR logical_exp
	| BOTH logical_exp AND logical_exp
	;

cond1_stmt: EXECUTE SECTION_OPEN stmt_list SECTION_CLOSE condition COMMANDEND
	;

logical_exp: logical_exp OR elem1
	| elem1
	;

elem1: elem1 AND elem2
	| elem2
	;

elem2: NOT elem2
	| elem3
	;

elem3: LEFTPAREN logical_exp RIGHTPAREN
	| rel_exp
	;


rel_exp: t1 rel_op t1
	;

t1: math_exp
	;

rel_op: LT | LE | GT | GE | NE | EQ
	;

math_exp: math_exp ADD term
	| math_exp MIN term
	| term
	;

term: term MUL factor
	| term DIVISION factor
	| factor
	;

factor: MIN factor
	| element
	;

element: LEFTPAREN math_exp RIGHTPAREN
	| ID
	| NUMBER
	| STRING
	;

%%

int yywrap()
{
	return 1;
}

void yyerror(char const* msg)
{
	fprintf(stderr, "[%d]:%s\n", line, msg);
}

int main(int argc, char *argv[])
{
	printf("#include <stdio.h>\n\nint main()\n{\n");

	// Read a file
	if(argc > 1)
		yyin = fopen(argv[1], "r");

	// Parse
	yyparse();

	// Print the footer
	printf("return 0;\n}\n");

	return 0;
}

