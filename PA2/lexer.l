/* File:  lexer.l
 * ----------------
 * Lex input file to generate the lexer for the compiler.
 */
 
%{
#include <iostream>
#include "lexer.h"
#include "location.h"
#include "errors.h"
#include <vector>
#include "utility.h"
#include "parser.h"
using namespace std;

#define TAB_SIZE 8

vector<const char*> savedLines;


/* Macro: YY_USER_ACTION 
 * ---------------------
 * This flex built-in macro can be defined to provide an action which is
 * always executed prior to any matched rule's action. Basically, it is
 * a way of having a piece of code common to all actions factored out to
 * this routine.  We already defined it for you and left the empty
 * function DoBeforeEachAction ready for your use as needed. It will
 * be called once for each pattern scanned from the file, before
 * executing its action.
 */
static void DoBeforeEachAction(); 
#define YY_USER_ACTION DoBeforeEachAction();

int currentLineNum, currentColNum;
%}

/* States
 * ------
 * A little wrinkle on states is the COPY exclusive state which
 * I added to first match each line and copy it ot the list of lines
 * read before re-processing it. This allows us to print the entire
 * line later to provide context on errors.
 */

/* Definitions
 * -----------
 * To make our rules more readable, we establish some definitions here.
 */

%x comment
%x COPY
%option stack

%% 
<COPY>.*              { savedLines.push_back(strdup(yytext));
                        currentColNum = 1;
                        yy_pop_state(); 
                        yyless(0);}

<COPY><<EOF>>         { yy_pop_state(); }

"\n"                  { currentLineNum++; 
                        currentColNum = 1; }

[ ]+                  {}

"\t"                  { currentColNum = (currentColNum + (TAB_SIZE - (currentColNum%TAB_SIZE)) + 1); }

"//"[^\n]*            {}

"/*"                  { BEGIN(comment); }
<comment>"\n"         { ++currentLineNum; }
<comment>"*"+"/"      { BEGIN(INITIAL); }
<comment>[^\n]*       {}
<comment><<EOF>>      { ReportError::UntermComment(); BEGIN(INITIAL); }

"void"[ \n\t]*        { yylloc.last_column -= 1;
                        return T_Void; }

"boolean"[ \n\t]*     { yylloc.last_column -= 1;
                        return T_Bool; }

"int"[ \n\t]*         { yylloc.last_column -= 1;
                        return T_Int; }

"while"[ \n\t]*       { yylloc.last_column -= 1;
                        return T_While; }

"break"[ \n\t]*      { yylloc.last_column -= 1;
                        return T_Break; }

"continue"[ \n\t]*   { yylloc.last_column -= 1;
                        return T_Continue; }

"else"[ \n\t]*       { yylloc.last_column -= 1;
                        return T_Else; }

"for"[ \n\t]*        { yylloc.last_column -= 1;
                        return T_For; }

"if"[ \n\t]*         { yylloc.last_column -= 1;
                        return T_If; }

"return"[ \n\t]*     { yylloc.last_column -= 1;
                        return T_Return; }

[0-9]+                { yylval.integerConstant = atoi(yytext); 
                        return T_IntConstant; }

"true"|"false"        { yylval.boolConstant = (yytext[0] == 't');
                        return T_BoolConstant; }

"++"                  { return T_Inc; }

"--"                  { return T_Dec; }

"<="                  { return T_LessEqual; }

">="                  { return T_GreaterEqual; }

"=="                  { return T_EQ; }

"!="                  { return T_NE; }

"&&"                  { return T_And; }

"||"                  { return T_Or; }

"*="                  { return T_MulAssign; }

"/="                  { return T_DivAssign; }

"+="                  { return T_AddAssign; }

"-="                  { return T_SubAssign; }

"("                   { return T_LeftParen; }

")"                   { return T_RightParen; }

"["                   { return T_LeftBracket; }

"]"                   { return T_RightBracket; }

"{"                   {  return T_LeftBrace; }

"}"                   { return T_RightBrace; }

"="                   { return T_Equal; }

";"                   { return T_Semicolon; }

"-"                   { return T_Dash; }

"+"                   { return T_Plus; }

"*"                   { return T_Star; }

"/"                   { return T_Slash; }

","                   { return T_Comma; }

"<"                   { return T_LeftAngle; }

">"                   { return T_RightAngle; }

"public"[ \r\n\t]*    { yylloc.last_column -= 1;
                        return T_Public; }

"private"[ \r\n\t]*   { yylloc.last_column -= 1;
                        return T_Private; }

"static"[ \r\n\t]*    { yylloc.last_column -= 1;
                        return T_Static; }

"class"[ \r\n\t]*     { yylloc.last_column -= 1;
                        return T_Class; }

[A-Za-z]+[0-9]*       { size_t len = strlen((char*) yylval.identifier);
                        memset(yylval.identifier, 0, len);
                        strncpy(yylval.identifier, yytext, yyleng);
                        return T_Identifier; }

.                    { ReportError::UnrecogChar(&yylloc, yytext[0]);}


%%

/* Function: InitLexer
 * ---------------------
 * This function will be called before any calls to yylex().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the scanner (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yy_flex_debug that controls whether flex prints debugging information
 * about each token and what rule was matched. If set to false, no information
 * is printed. Setting it to true will give you a running trail that might
 * be helpful when debugging your scanner. Please be sure the variable is
 * set to false when submitting your final version.
 */
void InitLexer()
{
    yy_flex_debug = false;
    currentLineNum = 1;
    currentColNum = 1;
    yy_push_state(COPY);
}

/* Function: DoBeforeEachAction()
 * ------------------------------
 * This function is installed as the YY_USER_ACTION. This is a place
 * to group code common to all actions.
 */
static void DoBeforeEachAction()
{
    yylloc.first_line = currentLineNum;
    yylloc.last_line = currentLineNum;

    yylloc.first_column = currentColNum;
    yylloc.last_column = currentColNum + yyleng - 1;
    currentColNum += yyleng;
}

/* Function: GetLineNumbered()
 * ---------------------------
 * Returns string with contents of line numbered n or NULL if the 
 * contents of that line are not available. Our scanner copies
 * each line scanned and appends each to a list so we can later
 * retrieve them to report the context for errors.
 */
 const char* GetLineNumbered(int num) {
     if (num <= 0 || num > savedLines.size()) return NULL;
     return savedLines[num-1];
 }
 