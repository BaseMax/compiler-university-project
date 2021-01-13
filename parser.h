/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    DATA = 259,                    /* DATA  */
    PROCEDURE = 260,               /* PROCEDURE  */
    DIVISION = 261,                /* DIVISION  */
    GET = 262,                     /* GET  */
    PUT = 263,                     /* PUT  */
    TO = 264,                      /* TO  */
    EXECUTE = 265,                 /* EXECUTE  */
    REPEAT = 266,                  /* REPEAT  */
    EITHER = 267,                  /* EITHER  */
    BOTH = 268,                    /* BOTH  */
    NEITHER = 269,                 /* NEITHER  */
    LT = 270,                      /* LT  */
    LE = 271,                      /* LE  */
    GT = 272,                      /* GT  */
    GE = 273,                      /* GE  */
    NE = 274,                      /* NE  */
    EQ = 275,                      /* EQ  */
    NOT = 276,                     /* NOT  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    NOR = 279,                     /* NOR  */
    ADD = 280,                     /* ADD  */
    SUB = 281,                     /* SUB  */
    MUL = 282,                     /* MUL  */
    DIV = 283,                     /* DIV  */
    SET = 284,                     /* SET  */
    LEFTPAREN = 285,               /* LEFTPAREN  */
    RIGHTPAREN = 286,              /* RIGHTPAREN  */
    SECTION_OPEN = 287,            /* SECTION_OPEN  */
    SECTION_CLOSE = 288,           /* SECTION_CLOSE  */
    INTEGER = 289,                 /* INTEGER  */
    FLOAT = 290,                   /* FLOAT  */
    CHAR = 291,                    /* CHAR  */
    END = 292,                     /* END  */
    SEMICOLON = 293,               /* SEMICOLON  */
    COLON = 294,                   /* COLON  */
    COMMANDEND = 295,              /* COMMANDEND  */
    ID = 296,                      /* ID  */
    NUMBER = 297,                  /* NUMBER  */
    STRING = 298,                  /* STRING  */
    UNSIGNED = 299                 /* UNSIGNED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "parser.y"

	sds string;
	//buffer_t *string;
	//char *string;

#line 114 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
