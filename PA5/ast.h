/**
 * File: ast.h
 * ----------- 
 * This file defines the abstract base class Node and the concrete 
 * Identifier and Error node subclasses that are used through the tree as 
 * leaf nodes. A parse tree is a hierarchical collection of ast nodes (or, 
 * more correctly, of instances of concrete subclassses such as VarDecl,
 * ForStmt, and AssignExpr).
 * 
 * Location: Each node maintains its lexical location (line and columns in 
 * file), that location can be NULL for those nodes that don't care/use 
 * locations. The location is typcially set by the node constructor.  The 
 * location is used to provide the context when reporting semantic errors.
 *
 * Parent: Each node has a pointer to its parent. For a Program node, the 
 * parent is NULL, for all other nodes it is the pointer to the node one level
 * up in the parse tree.  The parent is not set in the constructor (during a 
 * bottom-up parse we don't know the parent at the time of construction) but 
 * instead we wait until assigning the children into the parent node and then 
 * set up links in both directions. The parent link is typically not used 
 * during parsing, but is more important in later phases.
 *
 * Printing: The only interesting behavior of the node classes for pp2 is the 
 * bility to print the tree using an in-order walk.  Each node class is 
 * responsible for printing itself/children by overriding the virtual 
 * PrintChildren() and GetPrintNameForNode() methods. All the classes we 
 * provide already implement these methods, so your job is to construct the
 * nodes and wire them up during parsing. Once that's done, printing is a snap!

 */

#ifndef _H_ast
#define _H_ast

#include <stdlib.h>   // for NULL
#include <iostream>
#include <string>
#include "location.h"
#include <vector>
#include <set>
#include <stdio.h>
#include <map>

using namespace std;
class SymbolTable;

struct TACObject{
    int type;
    //1 is label
    string l0;
    //2 is action and action item,
    string acname;
    string acitem;
    //3 is is branch (if "t1" goto "label")
    string l1;//t1
    string l2;//label
    //4 destination, source1 source 2
    string dest;
    string s1;
    string s2;
    //5 jump, example ("goto l1")
    string l3;
    //6 return statement
    string ret;
    //7 function call: t1 call foo 5params
    string l4; //t1
    string func;
    int np;//number of params
    //8 logical expr or relational or equality
    string l5;//t1
    string l6;//leftstring
    string op;
    string l7;//rightString
    //9 assignment expr
    string l8;
    string l9;
    //10 postfix
    string l10;
    string addsub;
    //11 arithemticexpr
    string l11;
    string l12;
    string op1;
    string l13;
    //12 begin function
    //string l14;
    string l15;
    //13 endfunc
    string l16;
    //14 var decl
    string l17;
    string l18;
    string IF = "if ";
    string GOTO = " goto ";
    string complete1 ;//= l0 + ":";
    string complete2 ;//= "      "+acname + " " + acitem; 
    string complete3 ;//= "      " + IF + l1 + GOTO + l2;
    string complete5 ;//= GOTO + l3;
    string complete6 ;//= "      Return " + ret;
    string complete7 ;//= "      " + l4 + " call " + func + " " ;//+ to_string(np);
    string complete8 ;//= "      "+l5+" := " + l6 +" "+ op + " " + l7;
    string complete9 ;//= "      "+l8+" := " + l9;
    string complete10;// = "	" + l10 + " := " + addsub;
    string complete11 ;//=	"	" + l11+ " := " + l12 + " " + op1 + " " + l13;
    string complete12;// = "	BeginFunc " + l15;
    string complete13;// = l16;
    string complete14 ;//= l17 +" =: "+l18;

    void complete(){
        complete1 = l0 + ":";
        complete2 = "    " + acname + " " + acitem; 
        complete3 = "    " + IF + l1 + GOTO + l2;
        complete5 = "   " + GOTO + l3;
        complete6 = "    Return " + ret;
        complete7 = "    " + l4 + " call " + func + " ";
        complete8 = "    " + l5 + " := " + l6 +" " + op +" " + l7;
        complete9 = "    " + l8 + " := " + l9;
        complete10 ="    " + l10 + " := " + l10 + addsub;
        complete11 ="    " + l11+ " := " + l12 + " " + op1 + " " + l13;
        complete12 ="    BeginFunc " + l15;
        complete13 ="    " + l16;
        complete14 ="    " + l17 + " =: " + l18;
    }
};

class Node  {
  protected:
    yyltype *location;
    Node *parent;
    static SymbolTable *symtab;

    // Declare any global variables you need here
    // And initialize them in ast.cc
    static int registerCounter;
    static int labelCounter;
    static int varCounter;
    static int mipsReg;
    static vector<TACObject> TACContainer;
    static set<string> localVars;
    static map<string, bool> globalVars;
    static bool inFunc;
    static map<string, int> propMap;
    static map<string, bool> deadMap;
    static map<string, string> mipsMap;

  public:
    Node(yyltype loc);
    Node();
    virtual ~Node() {}
    
    yyltype *GetLocation()   { return location; }
    void SetParent(Node *p)  { parent = p; }
    Node *GetParent()        { return parent; }

    virtual const char *GetPrintNameForNode() = 0;
    
    // Print() is deliberately _not_ virtual
    // subclasses should override PrintChildren() instead
    void Print(int indentLevel, const char *label = NULL); 
    virtual void PrintChildren(int indentLevel)  {}
    virtual string Emit();
};
   

class Identifier : public Node 
{
  protected:
    char *name;
    
  public:
    Identifier(yyltype loc, const char *name);
    const char *GetPrintNameForNode()   { return "Identifier"; }
    void PrintChildren(int indentLevel);
    char *GetName() const { return name; }

    // virtual string Emit();
};


// This node class is designed to represent a portion of the tree that 
// encountered syntax errors during parsing. The partial completed tree
// is discarded along with the states being popped, and an instance of
// the Error class can stand in as the placeholder in the parse tree
// when your parser can continue after an error.
class Error : public Node
{
  public:
    Error() : Node() {}
    const char *GetPrintNameForNode()   { return "Error"; }
};



#endif
