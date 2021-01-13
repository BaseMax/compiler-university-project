bison -d $2 parser.y -Wcounterexamples
flex $1 lexer.l
g++ -o parser scanner.cpp parser.cpp
