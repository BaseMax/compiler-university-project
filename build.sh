# parser
bison -d $2 parser.y -Wcounterexamples
# bison -d $2 parser.y

# lexer
flex $1 lexer.l

# bind
gcc -o parser lex.yy.c parser.c sds.c

# compile
g++ test.cpp -o test
# run/test
./test
