bison -d $2 parser.y -Wcounterexamples
flex $1 lexer.l
gcc -o parser lex.yy.c parser.c sds.c
