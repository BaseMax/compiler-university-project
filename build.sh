bison -d $2 parser.y
flex $1 lexer.l
gcc -o parser lex.yy.c parser.c
