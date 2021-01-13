// A Bison parser, made by GNU Bison 3.7.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.



// First part of user prologue.
#line 1 "parser.y"

	#include <iostream>
	#include <string>

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


#line 62 "parser.cpp"


#include "parser.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 140 "parser.cpp"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (semantic_type) v)
    : Base (t)
    , value (YY_MOVE (v))
  {}

  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
  }

  // by_kind.
  parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  void
  parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YYUSE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: structure
#line 128 "parser.y"
                   {
		printf("%s", (yystack_[0].value.string));
	}
#line 592 "parser.cpp"
    break;

  case 3: // structure: heading data_part exe_part
#line 133 "parser.y"
                                      {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += (yystack_[1].value.string);
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 602 "parser.cpp"
    break;

  case 4: // structure: %empty
#line 138 "parser.y"
          {
		(yylhs.value.string) += "// empty program\n";
	}
#line 610 "parser.cpp"
    break;

  case 5: // heading: PROGRAM ID COLON
#line 143 "parser.y"
                          {
		(yylhs.value.string) += "// Program ";
		(yylhs.value.string) += (yystack_[1].value.string);
		(yylhs.value.string) += "\n";
	}
#line 620 "parser.cpp"
    break;

  case 6: // data_part: DATA DIVISION COMMANDEND data_body END COMMANDEND
#line 150 "parser.y"
                                                             {
		(yylhs.value.string) = (yystack_[2].value.string);
	}
#line 628 "parser.cpp"
    break;

  case 7: // data_body: data_stmt
#line 155 "parser.y"
                     {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 636 "parser.cpp"
    break;

  case 8: // data_body: data_stmt data_body
#line 158 "parser.y"
                              {
		(yylhs.value.string) = (yystack_[1].value.string);
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 645 "parser.cpp"
    break;

  case 9: // data_stmt: id_list COLON type COMMANDEND
#line 164 "parser.y"
                                         {
		(yylhs.value.string) = (yystack_[1].value.string);
		(yylhs.value.string) += " ";
		(yylhs.value.string) += (yystack_[3].value.string);
		(yylhs.value.string) += ";\n";
	}
#line 656 "parser.cpp"
    break;

  case 10: // id_list: ID
#line 172 "parser.y"
            {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 664 "parser.cpp"
    break;

  case 11: // id_list: ID SEMICOLON id_list
#line 175 "parser.y"
                               {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += ",";
		(yylhs.value.string) += (yystack_[1].value.string);
	}
#line 674 "parser.cpp"
    break;

  case 12: // type: INTEGER
#line 182 "parser.y"
              {
		(yylhs.value.string) += "int";
	}
#line 682 "parser.cpp"
    break;

  case 13: // type: FLOAT
#line 185 "parser.y"
                {
		(yylhs.value.string) += "float";
	}
#line 690 "parser.cpp"
    break;

  case 14: // type: CHAR
#line 188 "parser.y"
               {
		(yylhs.value.string) += "char";
	}
#line 698 "parser.cpp"
    break;

  case 15: // exe_part: PROCEDURE DIVISION COMMANDEND stmt_list_or_no END COMMANDEND
#line 193 "parser.y"
                                                                       {
		(yylhs.value.string) += "#include <stdio.h>\n\nint main(\n{\n";
		(yylhs.value.string) += (yystack_[2].value.string);
		(yylhs.value.string) += "return 0;\n}\n";
	}
#line 708 "parser.cpp"
    break;

  case 16: // stmt_list_or_no: stmt_list
#line 200 "parser.y"
                           {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 716 "parser.cpp"
    break;

  case 17: // stmt_list_or_no: %empty
#line 203 "parser.y"
          {
		(yylhs.value.string) += "// empty stmts\n";
	}
#line 724 "parser.cpp"
    break;

  case 18: // stmt_list: stmt
#line 208 "parser.y"
                { (yylhs.value.string) = (yystack_[0].value.string); }
#line 730 "parser.cpp"
    break;

  case 19: // stmt_list: stmt stmt_list
#line 209 "parser.y"
                         {
		(yylhs.value.string) = (yystack_[1].value.string);
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 739 "parser.cpp"
    break;

  case 20: // stmt: assgn_stmt
#line 215 "parser.y"
                 { (yylhs.value.string) = (yystack_[0].value.string); }
#line 745 "parser.cpp"
    break;

  case 21: // stmt: in_stmt
#line 216 "parser.y"
                  { (yylhs.value.string) = (yystack_[0].value.string); }
#line 751 "parser.cpp"
    break;

  case 22: // stmt: out_stmt
#line 217 "parser.y"
                   { (yylhs.value.string) = (yystack_[0].value.string); }
#line 757 "parser.cpp"
    break;

  case 23: // stmt: loop_stmt
#line 218 "parser.y"
                    { (yylhs.value.string) = (yystack_[0].value.string); }
#line 763 "parser.cpp"
    break;

  case 24: // stmt: cond1_stmt
#line 219 "parser.y"
                     { (yylhs.value.string) = (yystack_[0].value.string); }
#line 769 "parser.cpp"
    break;

  case 25: // assgn_stmt: SET ID TO math_exp COMMANDEND
#line 222 "parser.y"
                                          {
		(yylhs.value.string) = (yystack_[3].value.string);
		(yylhs.value.string) += " = ";
		(yylhs.value.string) += (yystack_[1].value.string);
		(yylhs.value.string) += ";\n";
	}
#line 780 "parser.cpp"
    break;

  case 26: // in_stmt: GET in_list COMMANDEND
#line 237 "parser.y"
                                {
	}
#line 787 "parser.cpp"
    break;

  case 27: // in_list: ID
#line 241 "parser.y"
            {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 795 "parser.cpp"
    break;

  case 28: // in_list: ID SEMICOLON in_list
#line 244 "parser.y"
                               {
		// sprintf($$, "%s%s", $1, $2);
	}
#line 803 "parser.cpp"
    break;

  case 29: // out_stmt: PUT out_list COMMANDEND
#line 249 "parser.y"
                                  {
	}
#line 810 "parser.cpp"
    break;

  case 30: // out_list: ID SEMICOLON out_list
#line 253 "parser.y"
          { (yylhs.value.string) = (yystack_[2].value.string); }
#line 816 "parser.cpp"
    break;

  case 31: // out_list: ID
#line 253 "parser.y"
                                     {
	}
#line 823 "parser.cpp"
    break;

  case 32: // loop_stmt: REPEAT SECTION_OPEN stmt_list_or_no SECTION_CLOSE condition COMMANDEND
#line 257 "parser.y"
                                                                                  {
	}
#line 830 "parser.cpp"
    break;

  case 33: // condition: EITHER logical_exp OR logical_exp
#line 261 "parser.y"
                                             {
		(yylhs.value.string) += "eit ";
		(yylhs.value.string) += (yystack_[2].value.string);
		(yylhs.value.string) += " OR ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 841 "parser.cpp"
    break;

  case 34: // condition: NEITHER logical_exp NOR logical_exp
#line 267 "parser.y"
                                              {
		(yylhs.value.string) += "eit ";
		(yylhs.value.string) += (yystack_[2].value.string);
		(yylhs.value.string) += " NOR ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 852 "parser.cpp"
    break;

  case 35: // condition: BOTH logical_exp AND logical_exp
#line 273 "parser.y"
                                           {
		(yylhs.value.string) += "eit ";
		(yylhs.value.string) += (yystack_[2].value.string);
		(yylhs.value.string) += " AND ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 863 "parser.cpp"
    break;

  case 36: // cond1_stmt: EXECUTE SECTION_OPEN stmt_list_or_no SECTION_CLOSE condition COMMANDEND
#line 281 "parser.y"
                                                                                    {

	}
#line 871 "parser.cpp"
    break;

  case 37: // logical_exp: logical_exp OR elem1
#line 286 "parser.y"
                                  {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += " OR ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 881 "parser.cpp"
    break;

  case 38: // logical_exp: elem1
#line 291 "parser.y"
                {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 889 "parser.cpp"
    break;

  case 39: // elem1: elem1 AND elem2
#line 296 "parser.y"
                       {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += " AND ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 899 "parser.cpp"
    break;

  case 40: // elem1: elem2
#line 301 "parser.y"
                {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 907 "parser.cpp"
    break;

  case 41: // elem2: NOT elem2
#line 306 "parser.y"
                 {
		(yylhs.value.string) += "NOT ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 916 "parser.cpp"
    break;

  case 42: // elem2: elem3
#line 310 "parser.y"
                {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 924 "parser.cpp"
    break;

  case 43: // elem3: LEFTPAREN logical_exp RIGHTPAREN
#line 315 "parser.y"
                                        {
		(yylhs.value.string) += "( ";
		(yylhs.value.string) += (yystack_[1].value.string);
		(yylhs.value.string) += " )";
	}
#line 934 "parser.cpp"
    break;

  case 44: // elem3: rel_exp
#line 320 "parser.y"
                  {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 942 "parser.cpp"
    break;

  case 45: // rel_exp: t1 rel_op t1
#line 326 "parser.y"
                      {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += " ";
		(yylhs.value.string) += (yystack_[1].value.string);
		(yylhs.value.string) += " ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 954 "parser.cpp"
    break;

  case 46: // t1: math_exp
#line 335 "parser.y"
             {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 962 "parser.cpp"
    break;

  case 47: // rel_op: LT
#line 340 "parser.y"
           {
		(yylhs.value.string) += "LT";
	}
#line 970 "parser.cpp"
    break;

  case 48: // rel_op: LE
#line 343 "parser.y"
             {
		(yylhs.value.string) += "LE";
	}
#line 978 "parser.cpp"
    break;

  case 49: // rel_op: GT
#line 346 "parser.y"
             {
		(yylhs.value.string) += "GT";
	}
#line 986 "parser.cpp"
    break;

  case 50: // rel_op: GE
#line 349 "parser.y"
             {
		(yylhs.value.string) += "GE";
	}
#line 994 "parser.cpp"
    break;

  case 51: // rel_op: NE
#line 352 "parser.y"
             {
		(yylhs.value.string) += "NE";
	}
#line 1002 "parser.cpp"
    break;

  case 52: // rel_op: EQ
#line 355 "parser.y"
             {
		(yylhs.value.string) += "EQ";
	}
#line 1010 "parser.cpp"
    break;

  case 53: // math_exp: math_exp ADD term
#line 360 "parser.y"
                            {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += " ADD ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 1020 "parser.cpp"
    break;

  case 54: // math_exp: math_exp SUB term
#line 365 "parser.y"
                            {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += " SUB ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 1030 "parser.cpp"
    break;

  case 55: // math_exp: term
#line 370 "parser.y"
               {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 1038 "parser.cpp"
    break;

  case 56: // term: term MUL factor
#line 375 "parser.y"
                      {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += " * ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 1048 "parser.cpp"
    break;

  case 57: // term: term DIVISION factor
#line 380 "parser.y"
                               {
		(yylhs.value.string) = (yystack_[2].value.string);
		(yylhs.value.string) += " / ";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 1058 "parser.cpp"
    break;

  case 58: // term: factor
#line 385 "parser.y"
                 {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 1066 "parser.cpp"
    break;

  case 59: // factor: SUB factor
#line 390 "parser.y"
                   {
		(yylhs.value.string) += "-";
		(yylhs.value.string) += (yystack_[0].value.string);
	}
#line 1075 "parser.cpp"
    break;

  case 60: // factor: element
#line 394 "parser.y"
                  {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 1083 "parser.cpp"
    break;

  case 61: // element: LEFTPAREN math_exp RIGHTPAREN
#line 399 "parser.y"
                                       {
		(yylhs.value.string) += "( ";
		(yylhs.value.string) += (yystack_[1].value.string);
		(yylhs.value.string) += " )";
	}
#line 1093 "parser.cpp"
    break;

  case 62: // element: ID
#line 404 "parser.y"
             {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 1101 "parser.cpp"
    break;

  case 63: // element: NUMBER
#line 407 "parser.y"
                 {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 1109 "parser.cpp"
    break;

  case 64: // element: STRING
#line 410 "parser.y"
                 {
		(yylhs.value.string) = (yystack_[0].value.string);
	}
#line 1117 "parser.cpp"
    break;


#line 1121 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0





  const signed char parser::yypact_ninf_ = -99;

  const signed char parser::yytable_ninf_ = -39;

  const signed char
  parser::yypact_[] =
  {
      11,    -6,    55,   -99,    54,    31,   -99,    65,    67,   -99,
      33,    68,   -99,    34,    36,    41,    43,    34,    38,    45,
      34,    42,   -99,   -18,    37,    44,    47,    51,    53,    49,
     -99,    45,   -99,   -99,   -99,   -99,   -99,   -99,   -99,   -99,
     -99,   -99,    50,    56,    52,    74,    57,    58,    45,    45,
      59,   -99,   -99,    37,   -99,     2,    47,   -99,    60,    62,
     -99,   -99,     2,     2,   -99,   -99,   -99,   -20,    -5,   -99,
     -99,   -99,    46,    46,   -99,     6,     2,     2,   -99,     2,
       2,   -17,   -17,   -17,    61,    63,   -99,    -5,    -5,   -99,
     -99,   -17,   -17,    72,    64,   -99,   -99,   -99,    30,    15,
      39,    40,   -99,   -99,   -99,     7,     6,   -17,   -17,   -99,
     -99,   -99,   -99,   -99,   -99,     2,   -17,   -17,   -17,   -99,
      73,   -12,   -99,   -99,    73,   -99,    73
  };

  const signed char
  parser::yydefact_[] =
  {
       4,     0,     0,     2,     0,     0,     1,     0,     0,     5,
       0,     0,     3,     0,     0,    10,     0,     7,     0,    17,
       0,     0,     8,     0,     0,     0,     0,     0,     0,     0,
      16,    18,    20,    21,    22,    23,    24,    11,     6,    12,
      13,    14,     0,    27,     0,     0,    31,     0,    17,    17,
       0,    19,     9,     0,    26,     0,     0,    29,     0,     0,
      15,    28,     0,     0,    62,    63,    64,     0,    55,    58,
      60,    30,     0,     0,    59,     0,     0,     0,    25,     0,
       0,     0,     0,     0,     0,     0,    61,    53,    54,    57,
      56,     0,     0,     0,    38,    40,    42,    44,     0,    46,
       0,     0,    36,    32,    41,     0,    46,     0,     0,    47,
      48,    49,    50,    51,    52,     0,     0,     0,     0,    43,
      33,    37,    39,    45,    35,    37,    34
  };

  const signed char
  parser::yypgoto_[] =
  {
     -99,   -99,   -99,   -99,   -99,    83,   -99,    69,   -99,   -99,
      18,    71,   -99,   -99,   -99,    66,   -99,    48,   -99,    32,
     -99,   -80,   -98,   -78,   -99,   -99,    -9,   -99,   -55,    -8,
     -58,   -99
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,     2,     3,     4,     8,    16,    17,    18,    42,    12,
      29,    30,    31,    32,    33,    44,    34,    47,    35,    84,
      36,    93,    94,    95,    96,    97,    98,   115,    99,    68,
      69,    70
  };

  const signed char
  parser::yytable_[] =
  {
      67,    79,   100,   101,    74,    91,    76,    77,    75,   121,
      62,   108,   105,   104,     1,    92,    39,    40,    41,   125,
      78,    89,    90,    80,    64,    65,    66,   120,   -38,    62,
     122,   117,    76,    77,    63,     5,   124,   106,   126,    86,
     119,    76,    77,    64,    65,    66,   109,   110,   111,   112,
     113,   114,    24,    25,    26,     6,    27,    28,     7,    81,
      82,    83,   116,   117,   117,   118,    58,    59,    87,    88,
       9,    10,    11,    13,    14,    15,    19,    23,    43,    20,
      21,    48,    38,    49,    55,    45,    50,   108,    46,    37,
      52,    72,    54,    73,    53,    56,   107,   117,    57,    60,
      22,   102,    51,   103,    71,    85,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61
  };

  const signed char
  parser::yycheck_[] =
  {
      55,     6,    82,    83,    62,    22,    26,    27,    63,   107,
      27,    23,    92,    91,     3,    32,    34,    35,    36,   117,
      40,    79,    80,    28,    41,    42,    43,   107,    40,    27,
     108,    24,    26,    27,    32,    41,   116,    92,   118,    33,
      33,    26,    27,    41,    42,    43,    16,    17,    18,    19,
      20,    21,     7,     8,     9,     0,    11,    12,     4,    13,
      14,    15,    23,    24,    24,    25,    48,    49,    76,    77,
      39,     6,     5,    40,     6,    41,    40,    39,    41,    38,
      37,    30,    40,    30,    10,    41,    37,    23,    41,    20,
      40,    31,    40,    31,    38,    38,    24,    24,    40,    40,
      17,    40,    31,    40,    56,    73,   115,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    46,    47,    48,    41,     0,     4,    49,    39,
       6,     5,    54,    40,     6,    41,    50,    51,    52,    40,
      38,    37,    50,    39,     7,     8,     9,    11,    12,    55,
      56,    57,    58,    59,    61,    63,    65,    52,    40,    34,
      35,    36,    53,    41,    60,    41,    41,    62,    30,    30,
      37,    56,    40,    38,    40,    10,    38,    40,    55,    55,
      40,    60,    27,    32,    41,    42,    43,    73,    74,    75,
      76,    62,    31,    31,    75,    73,    26,    27,    40,     6,
      28,    13,    14,    15,    64,    64,    33,    74,    74,    75,
      75,    22,    32,    66,    67,    68,    69,    70,    71,    73,
      66,    66,    40,    40,    68,    66,    73,    24,    23,    16,
      17,    18,    19,    20,    21,    72,    23,    24,    25,    33,
      66,    67,    68,    71,    66,    67,    66
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    49,    50,    50,    51,
      52,    52,    53,    53,    53,    54,    55,    55,    56,    56,
      57,    57,    57,    57,    57,    58,    59,    60,    60,    61,
      62,    62,    63,    64,    64,    64,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    70,    71,    72,    72,    72,
      72,    72,    72,    73,    73,    73,    74,    74,    74,    75,
      75,    76,    76,    76,    76
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     0,     3,     6,     1,     2,     4,
       1,     3,     1,     1,     1,     6,     1,     0,     1,     2,
       1,     1,     1,     1,     1,     5,     3,     1,     3,     3,
       3,     1,     6,     4,     4,     4,     6,     3,     1,     3,
       1,     2,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     2,
       1,     3,     1,     1,     1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "DATA",
  "PROCEDURE", "DIVISION", "GET", "SET", "PUT", "TO", "EXECUTE", "REPEAT",
  "EITHER", "BOTH", "NEITHER", "LT", "LE", "GT", "GE", "NE", "EQ", "NOT",
  "AND", "OR", "NOR", "ADD", "SUB", "MUL", "DIV", "SECTION_OPEN",
  "SECTION_CLOSE", "LEFTPAREN", "RIGHTPAREN", "INTEGER", "FLOAT", "CHAR",
  "END", "SEMICOLON", "COLON", "COMMANDEND", "ID", "NUMBER", "STRING",
  "UNSIGNED", "$accept", "program", "structure", "heading", "data_part",
  "data_body", "data_stmt", "id_list", "type", "exe_part",
  "stmt_list_or_no", "stmt_list", "stmt", "assgn_stmt", "in_stmt",
  "in_list", "out_stmt", "out_list", "loop_stmt", "condition",
  "cond1_stmt", "logical_exp", "elem1", "elem2", "elem3", "rel_exp", "t1",
  "rel_op", "math_exp", "term", "factor", "element", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   128,   128,   133,   138,   143,   150,   155,   158,   164,
     172,   175,   182,   185,   188,   193,   200,   203,   208,   209,
     215,   216,   217,   218,   219,   222,   237,   241,   244,   249,
     253,   253,   257,   261,   267,   273,   281,   286,   291,   296,
     301,   306,   310,   315,   320,   326,   335,   340,   343,   346,
     349,   352,   355,   360,   365,   370,   375,   380,   385,   390,
     394,   399,   404,   407,   410
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    // Last valid token kind.
    const int code_max = 299;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // yy
#line 1555 "parser.cpp"

#line 415 "parser.y"


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

