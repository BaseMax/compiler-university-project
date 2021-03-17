# Compiler University Project

> Implement an university compiler using Flex, Bison in the C programming language

Keep in mind that I am not a computer science or engeering student and do not need to do an academic project.

It's just a fun project to test myself to see how much time I need to implement such a Uni Compiler.

The `build.sh` file is a shell script and you can use it to compile, create, test the compiler.

## Tokens

```
/* */ \n program data procedure division get set put to execute repeat either both neither lt le gt ge ne eq not nor and or + - * / { } ( ) integer float char unsigned end , : ; 
```

You can find syntax example of this language at [test.lang](test.lang) file.

## Tech Stack

Lexer and parser build using **Flex** and **Bison**, other parts are pure **C language**.

For the dynamic strings I use a library called **sds**, it's a cool and tiny library for C.

## Grammer and compiler syntax

```yacc
%start program

program: structure
structure: heading data_part exe_part |
heading: PROGRAM ID COLON |
data_part: DATA DIVISION COMMANDEND data_body END COMMANDEND
data_body: data_stmt | data_stmt data_body
data_stmt: id_list COLON type COMMANDEND
id_list: ID | ID SEMICOLON id_list
type: INTEGER | FLOAT | CHAR {
exe_part: PROCEDURE DIVISION COMMANDEND stmt_list_or_no END COMMANDEND
stmt_list_or_no: stmt_list | 
stmt_list: stmt | stmt stmt_list
stmt: assgn_stmt | in_stmt | out_stmt | loop_stmt | cond1_stmt
assgn_stmt: SET ID TO expression COMMANDEND
in_stmt: GET in_list COMMANDEND
in_list: ID | ID SEMICOLON in_list
out_stmt: PUT out_list COMMANDEND | PUT COMMANDEND
out_list: ID SEMICOLON out_list | ID
loop_stmt: REPEAT SECTION_OPEN stmt_list_or_no SECTION_CLOSE condition
cond1_stmt: EXECUTE SECTION_OPEN stmt_list_or_no SECTION_CLOSE COMMANDEND
condition: EITHER expression COMMANDEND | NEITHER expression COMMANDEND | BOTH expression COMMANDEND
expression: SUB expression | NOT expression | expression GT expression | expression GE expression | expression LT expression | expression LE expression | expression AND expression | expression OR expression | ID | STRING | NUMBER | expression DIV expression | expression MUL expression | LEFTPAREN expression RIGHTPAREN | expression ADD expression | expression SUB expression
```

© Copyright Max Base
