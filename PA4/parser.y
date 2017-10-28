/* File: parser.y
 * --------------
 * Bison input file to generate the parser for the compiler.
 *
 * pp2: your job is to write a parser that will construct the parse tree
 *      and if no parse errors were found, print it.  The parser should
 *      accept the language as described in specification, and as augmented
 *      in the pp2 handout.
 */

%{

/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "lexer.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine

%}

/* The section before the first %% is the Definitions section of the yacc
 * input file. Here is where you declare tokens and types, add precedence
 * and associativity options, and so on.
 */

/* yylval
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the lexer to store attibute information about the token just scanned
 * and thus communicate that information to the parser.
 *
 * pp2: You will need to add new fields to this union as you add different
 *      attributes to your non-terminal symbols.
 */
%union {
    int             integerConstant;
    bool            boolConstant;
    char            identifier[MaxIdentLen+1]; // +1 for terminating null
    VarDecl 		*varDecl;
    List<VarDecl*>  *varDeclList;
    List<Decl*>     *declList;
    List<Expr*>     *exprList;
    Decl            *decl;
    VarDeclError    *varDeclError;
    FnDecl 		    *fnDecl;
    FormalsError 	*formalsError;
    ExprError 		*exprError;
    EmptyExpr 		*emptyExpr;
    ArithmeticExpr 	*arithmeticExpr;
    RelationalExpr 	*relationalExpr;
    EqualityExpr 	*equalityExpr;
    LogicalExpr		*logicalExpr;	
    SelectionExpr	*selectionExpr;
    AssignExpr      *assignExpr;
    PostfixExpr     *postfixExpr;
    Call            *call;
    Operator 		*op;
    VarExpr         *varExpr;
    Program         *program;
    Stmt            *stmt;
    List<Stmt*>     *stmt_list;
    StmtBlock       *stmtBlock;
    ConditionalStmt *conditionalStmt;
    LoopStmt        *loopStmt;
    ForStmt         *forStmt;
    WhileStmt       *whileStmt;
    IfStmt          *ifStmt;
    IfStmtExprError *ifStmtExprErorr;
    BreakStmt       *breakStmt;
    ReturnStmt      *returnStmt;
    DeclStmt        *declStmt;
    CompoundExpr 	*compoundExpr;
    Expr 		    *expr;
    Type            *varType;
    Identifier      *fnid;
}

/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Bison will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int
%token   T_LessEqual T_GreaterEqual T_EQ T_NE T_LeftAngle T_RightAngle
%token   T_And T_Or
%token   T_Equal T_MulAssign T_DivAssign T_AddAssign T_SubAssign
%token   T_While T_For T_If T_Else T_Return T_Break T_Continue
%token   T_Inc T_Dec
%token   T_Semicolon T_Comma
%token   T_Dash T_Plus T_Star T_Slash
%token   T_LeftParen T_RightParen T_LeftBracket T_RightBracket T_LeftBrace T_RightBrace
%token   T_Public T_Private T_Static T_Class

%token   <identifier> T_Identifier
%token   <integerConstant>T_IntConstant
%token   <boolConstant>T_BoolConstant

%nonassoc LOWEST
%nonassoc LOWER_THAN_ELSE
%nonassoc T_Else
%right T_Equal T_MulAssign T_DivAssign T_AddAssign T_SubAssign
%left T_Or
%left T_And
%left T_EQ T_NE
%left T_LeftAngle T_RightAngle T_LessEqual T_GreaterEqual
%left T_Plus T_Dash
%left T_Star T_Slash
%left T_Inc T_Dec
%left T_LeftParen T_RightParen

/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" in the yylval union. This
 * means that when we are setting $$ for a reduction for DeclList ore reading
 * $n which corresponds to a DeclList nonterminal we are accessing the field
 * of the union named "declList" which is of type List<Decl*>.
 * pp2: You'll need to add many of these of your own.
 */
%type<program>          Program
%type<declList>         DeclList
%type<varDeclList>      parameter_declaration_list
%type<decl>             Decl
%type<varDecl>          single_declaration paramater_declaraion
%type<varType>          type_specifier
%type<fnDecl>           function_definition function_prototype function_prototype_header
%type<fnid>             function_identifier
%type<stmt>             statement simple_statement iteration_statement compound_statement_with_scope
%type<expr>             condition expression expression_statement constant unary_expression postfix_expression primary_expression function_call_header_with_parameters func_call_expression function_call_header_no_parameters
%type<ifStmt>           selection_statement
%type<whileStmt>        while_statement
%type<forStmt>          for_statement
%type<arithmeticExpr>   arithmetic_expression
%type<relationalExpr>   relational_expression
%type<equalityExpr>     equality_expression
%type<logicalExpr>      logical_expression
%type<returnStmt>       return_statement
%type<declStmt>         decl_statement
%type<breakStmt>        break_statement
%type<assignExpr>       assignment_expression
%type<op>               assignment_operator
%type<stmt_list>        statement_list
%type<exprList>         arg_list

%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.

 */
Program   :    DeclList            {
                                      @1;
                                      /* The @1 is needed to convince
                                       * yacc to set up yylloc. You can remove
                                       * it once you have other uses of @n*/
                                      Program *program = new Program($1);
                                      if (ReportError::NumErrors() == 0)
                                          program->Print(0);
                                      program->Check();
                                    }
          ;

DeclList  :    DeclList Decl        { ($$=$1)->Append($2); }
          |    Decl                 { ($$ = new List<Decl*>)->Append($1); }
          ;

Decl      :    single_declaration   { $$ = $1; }
          |    function_definition  { $$ = $1; }
          ;

single_declaration : type_specifier T_Identifier T_Semicolon   { $$ = new VarDecl(new Identifier(@2, $2), $1); }
                   | type_specifier T_Identifier assignment_operator expression T_Semicolon { $$ = new VarDecl(new Identifier(@2, $2), $1, $4); }
                   ;

type_specifier  : T_Void     { $$ = Type::voidType; }
                | T_Int      { $$ = Type::intType; }
                | T_Bool     { $$ = Type::boolType; }
                ;

function_definition : function_prototype compound_statement_with_scope      { ($$ = $1)->SetFunctionBody($2); }
                    | function_prototype T_Semicolon                        { $$ = $1; }
                    ;

function_prototype  : function_prototype_header T_RightParen    { $$ = $1; }
                    ;

function_prototype_header   :   type_specifier T_Identifier T_LeftParen                             { $$ = new FnDecl(new Identifier(@2, $2), $1, new List<VarDecl*>()); }
                            |   type_specifier T_Identifier T_LeftParen parameter_declaration_list  { $$ = new FnDecl(new Identifier(@2, $2), $1, $4); }
                            ;

parameter_declaration_list  :   parameter_declaration_list T_Comma  paramater_declaraion    { ($$ = $1)->Append($3); }
                            |   paramater_declaraion                                        { ($$ = new List<VarDecl*>())->Append($1); }
                            ;

paramater_declaraion        :   type_specifier T_Identifier { $$ = new VarDecl(new Identifier(@2, $2), $1); }
                            ;

compound_statement_with_scope   :   T_LeftBrace statement_list  T_RightBrace    { $$ = new StmtBlock($2); }
                                |   T_LeftBrace T_RightBrace                    { $$ = new StmtBlock(new List<Stmt*>()); }
                                ;

statement_list  :   statement_list  statement   { ($$ = $1)->Append($2); }
                |   statement                   { ($$ = new List<Stmt*>)->Append($1); }
                ;

statement   :   compound_statement_with_scope   { $$ = $1; }
            |   simple_statement                { $$ = $1; }
            |   iteration_statement             { $$ = $1; }
            |   return_statement                { $$ = $1; }
            |   decl_statement                  { $$ = $1; }
            |   break_statement                 { $$ = $1; }
            ;

simple_statement    :   expression_statement    { $$ = $1; }
                    |   selection_statement     { $$ = $1; }
                    ;

expression_statement    :   T_Semicolon             { }
                        |   expression T_Semicolon  { $$ = $1; }
                        ;

selection_statement :   T_If T_LeftParen expression T_RightParen compound_statement_with_scope  { $$ = new IfStmt($3, $5, NULL); }
                    |   T_If T_LeftParen expression T_RightParen compound_statement_with_scope T_Else compound_statement_with_scope { $$ = new IfStmt($3, $5, $7); }
                    ;

iteration_statement :   while_statement { $$ = $1; }
                    |   for_statement   { $$ = $1; }
                    ;

while_statement :   T_While T_LeftParen condition T_RightParen statement    { $$ = new WhileStmt($3, $5); }
                ;

for_statement   :   T_For T_LeftParen expression_statement expression_statement expression T_RightParen statement   { $$ = new ForStmt($3, $4, $5, $7); }
                ;

condition   :  expression   { $$ = $1; }
            ;

return_statement    :   T_Return expression_statement   { $$ = new ReturnStmt(@1, $2); }
                    ;

decl_statement  :   single_declaration  { $$ = new DeclStmt(@1, $1); }
                ;

break_statement :   T_Break T_Semicolon { $$ = new BreakStmt(@1); }
                ;

expression  :   assignment_expression   { $$ = $1; }
            |   arithmetic_expression   { $$ = $1; }
            |   relational_expression   { $$ = $1; }
            |   equality_expression     { $$ = $1; }
            |   logical_expression      { $$ = $1; }
            |   unary_expression        { $$ = $1; }
            ;

assignment_expression   :   unary_expression assignment_operator expression { $$ = new AssignExpr($1, $2, $3); }
                        ;

assignment_operator : T_Equal       { $$ = new Operator(@1, "="); }
                    | T_MulAssign   { $$ = new Operator(@1, "*="); }
                    | T_DivAssign   { $$ = new Operator(@1, "/="); }
                    | T_AddAssign   { $$ = new Operator(@1, "+="); }
                    | T_SubAssign   { $$ = new Operator(@1, "-="); }
                    ;

arithmetic_expression   :   expression T_Plus expression    { $$ = new ArithmeticExpr($1,new Operator(@2, "+"),$3); }
                        |   expression T_Dash expression    { $$ = new ArithmeticExpr($1,new Operator(@2, "-"),$3); }
                        |   expression T_Star expression    { $$ = new ArithmeticExpr($1,new Operator(@2, "*"),$3); }
                        |   expression T_Slash expression   { $$ = new ArithmeticExpr($1,new Operator(@2, "/"),$3); }
                        ;

relational_expression   :   expression T_LeftAngle expression       { $$ = new RelationalExpr($1,new Operator(@2, "<"),$3); }
                        |   expression T_RightAngle expression      { $$ = new RelationalExpr($1,new Operator(@2, ">"),$3); }
                        |   expression T_LessEqual expression       { $$ = new RelationalExpr($1,new Operator(@2, "<="),$3); }
                        |   expression T_GreaterEqual expression    { $$ = new RelationalExpr($1,new Operator(@2, ">="),$3); }
                        ;

equality_expression :   expression T_EQ expression  { $$ = (new EqualityExpr($1,new Operator(@2, "=="),$3)); }
                    |   expression T_NE expression  { $$ = (new EqualityExpr($1,new Operator(@2, "!="),$3)); }
                    ;

logical_expression  :   expression T_And expression { $$ = (new LogicalExpr($1,new Operator(@2, "&&"),$3)); }
                    |   expression T_Or expression  { $$ = (new LogicalExpr($1,new Operator(@2, "||"),$3)); }
                    ;

postfix_expression  :   primary_expression          { $$ = $1; }
                    |   postfix_expression T_Inc    { $$ = (new PostfixExpr($1, new Operator(@2, "++"))); }
                    |   postfix_expression T_Dec    { $$ = (new PostfixExpr($1, new Operator(@2, "--"))); }
                    |   func_call_expression        { $$ = $1; }
                    ;

func_call_expression    :   function_call_header_with_parameters T_RightParen       { $$ = $1; }
                        |   function_call_header_no_parameters T_RightParen         { $$ = $1; }
                        ;

function_call_header_no_parameters  :   function_identifier T_LeftParen T_Void      { $$ = new Call(@1, NULL, $1, new List<Expr*>()); }
                                    |   function_identifier T_LeftParen             { $$ = new Call(@1, NULL, $1, new List<Expr*>()); }
                                    ;

function_call_header_with_parameters    :   function_identifier T_LeftParen arg_list { $$ = new Call(@1, NULL, $1, $3); }
                                        ;

arg_list    :   assignment_expression                   { ($$ = new List<Expr*>())->Append($1); }
            |   arg_list T_Comma assignment_expression  { ($$ = $1)->Append($3); }
            |   primary_expression                      { ($$ = new List<Expr*>())->Append($1); }
            |   arg_list T_Comma primary_expression     { ($$ = $1)->Append($3); }
            ;

function_identifier :   T_Identifier    { $$ = new Identifier(@1, $1); }
                    ;

primary_expression  :   T_Identifier                        { $$ = new VarExpr(@1, new Identifier(@1, $1)); }
                    |   constant                            { $$ = $1; }
                    |   T_LeftParen expression T_RightParen { $$ = $2; }
                    ;

unary_expression    :   postfix_expression      { $$ = $1; }
                    |   T_Inc unary_expression  { $$ = new ArithmeticExpr(new Operator(@1, "++"), $2); }
                    |   T_Dec unary_expression  { $$ = new ArithmeticExpr(new Operator(@1, "--"), $2); }
                    |   T_Plus unary_expression { $$ = new ArithmeticExpr(new IntConstant(@1, 1), new Operator(@1, "*"), $2); }
                    |   T_Dash unary_expression { $$ = new ArithmeticExpr(new IntConstant(@1, -1), new Operator(@1, "*"), $2); }
                    ;

constant    :   T_IntConstant   { $$ = new IntConstant(@1, $1);  }
            |   T_BoolConstant  { $$ = new BoolConstant(@1, $1); }
            ;

%%

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}
