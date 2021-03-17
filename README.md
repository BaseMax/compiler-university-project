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

© Copyright Max Base
