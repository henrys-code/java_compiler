/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "symtable.h"


IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}
void IntConstant::PrintChildren(int indentLevel) {
    printf("%d", value);
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

void BoolConstant::PrintChildren(int indentLevel) {
    printf("%s", value ? "true" : "false");
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

void Operator::PrintChildren(int indentLevel) {
    printf("%s",tokenString);
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r)
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this);
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r)
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL;
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o)
  : Expr(Join(l->GetLocation(), o->GetLocation())) {
    Assert(l != NULL && o != NULL);
    (left=l)->SetParent(this);
    (op=o)->SetParent(this);
}

void CompoundExpr::PrintChildren(int indentLevel) {
   if (left) left->Print(indentLevel+1);
   op->Print(indentLevel+1);
   if (right) right->Print(indentLevel+1);
}

SelectionExpr::SelectionExpr(Expr *c, Expr *t, Expr *f)
  : Expr(Join(c->GetLocation(), f->GetLocation())) {
    Assert(c != NULL && t != NULL && f != NULL);
    (cond=c)->SetParent(this);
    (trueExpr=t)->SetParent(this);
    (falseExpr=f)->SetParent(this);
}

void SelectionExpr::PrintChildren(int indentLevel) {
    cond->Print(indentLevel+1);
    trueExpr->Print(indentLevel+1, "(true) ");
    falseExpr->Print(indentLevel+1, "(false) ");
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

void Call::PrintChildren(int indentLevel) {
    if (base) base->Print(indentLevel+1);
    if (field) field->Print(indentLevel+1);
    if (actuals) actuals->PrintAll(indentLevel+1, "(actuals) ");
}

void VarExpr::PrintChildren(int identLevel) {
  id->Print(identLevel + 1);
}

VarExpr::VarExpr(yyltype loc, Identifier *ident) : Expr(loc) {
  id = ident;
}

string IntConstant::Emit() {
  return to_string(value);
}

string BoolConstant::Emit() {
  return value ? "true" : "false";
}

string Operator::Emit() {
  return string(tokenString);
}

string Call::Emit() {
    int numParams = actuals->NumElements();
    for (int i = 0; i < numParams; i++)
    {
      Expr * varElem = dynamic_cast<VarExpr *>(actuals->Nth(i));
      if (varElem)
      {
          TACContainer.push_back(string("    ") + string("PushParam ") + varElem->GetName());
      }
      else
      {
          varElem = dynamic_cast<IntConstant *>(actuals->Nth(i));
          if (!varElem)
          {
              TACContainer.push_back(string("    ") + string("PushParam ") + varElem->GetValue());
          }
          else
          {
              varElem = dynamic_cast<BoolConstant *>(actuals->Nth(i));
          }
      }
      TACContainer.push_back(string("    ") + string("PushParam ") + varElem->GetName());
  }
  string returnValue = "t" + to_string(registerCounter++);
  string fnId = field->GetName();
  TACContainer.push_back(string("    ") + returnValue + string(" call ") + fnId + string(" ") + to_string(numParams));
  TACContainer.push_back(string("    ") + string("PopParam ") + to_string(numParams * sizeof(int)));

  return returnValue;
}

string VarExpr::Emit() {
  string localVarName = id->GetName();
  return string(localVarName);
}

string EmptyExpr::Emit() {
  return "";
}

string ArithmeticExpr::Emit() {
  string opString = op->Emit();
  string leftString;
  string rightString;
  if (left)
  {
      leftString = left->Emit();
  }
  else
  {
      leftString = "";
  }
  if (right)
  {
      rightString = right->Emit();
  }
  else
  {
      rightString = "";
  }

  string registerString = "t" + to_string(registerCounter);
  registerCounter++;

  TACContainer.push_back(string("    ") + registerString + string(" := ") + leftString + string(" ") + opString + string(" ") + rightString);   

  return registerString;
}

string RelationalExpr::Emit() {
  string leftString = left->Emit();
  string rightString = right->Emit();
  string opString = op->Emit();

  string registerString = "t" + to_string(registerCounter);
  registerCounter++;

  TACContainer.push_back(string("    ") + registerString + string(" := ") + leftString + string(" ") + opString + string(" ") + rightString);   

  return registerString;
}

string AssignExpr::Emit() {
  string leftString = left->Emit();
  string rightString = right->Emit();

  string registerString = "t" + to_string(registerCounter);
  registerCounter++;

  TACContainer.push_back(string("    ") + registerString + string(" := ") + leftString + string(" ") + string(" = ") + string(" ") + rightString);   

  return registerString;
}

string LogicalExpr::Emit() {
  string leftString = left->Emit();
  string rightString = right->Emit();
  string opString = op->Emit();

  string registerString = "t" + to_string(registerCounter);
  registerCounter++;

  TACContainer.push_back(string("    ") + registerString + string(" := ") + leftString + string(" ") + opString + string(" ") + rightString);   

  return registerString;
}

string EqualityExpr::Emit() {
  string leftString = left->Emit();
  string rightString = right->Emit();
  string opString = op->Emit();

  string registerString = "t" + to_string(registerCounter);
  registerCounter++;

  TACContainer.push_back(string("    ") + registerString + string(" := ") + leftString + string(" ") + opString + string(" ") + rightString);   

  return registerString;
}

string PostfixExpr::Emit() {
  
  return "PostfixExpr::Emit()";
}
