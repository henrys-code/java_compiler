/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "symtable.h"

Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this);
}


VarDecl::VarDecl(Identifier *n, Type *t, Expr *e) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
    if (e) (assignTo=e)->SetParent(this);
}

void VarDecl::PrintChildren(int indentLevel) {
   if (type) type->Print(indentLevel+1);
   if (id) id->Print(indentLevel+1);
   if (assignTo) assignTo->Print(indentLevel+1, "(initializer) ");
}

string VarDecl::Emit() {
    string varName = GetIdentifier()->GetName();

    if (assignTo) {
        string rhsRegisterName = assignTo->Emit();
        TACContainer.push_back(string("    ") + varName + string(" := ") + rhsRegisterName);
        varCounter++;
    }     

    return "VarDecl::Emit()";
}

FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) {
    (body=b)->SetParent(this);
}

string FnDecl::Emit() {
    std::cerr << "TEST 1" << std::endl;
    TACContainer.push_back(string(id->GetName()) + string(":"));
    int paramLength = formals->NumElements();
    for (int i = 0; i < paramLength; i++)
    {
        TACContainer.push_back(string("    ") + string("LoadParam ") + formals->Nth(i)->GetIdentifier()->GetName());
    }
    std::cerr << "TEST 1a" << std::endl;
    int index = TACContainer.size();
    int diff = registerCounter;
    int localVars = varCounter;
    std::cerr << "TEST 1b" << std::endl;
    string numVars = "numVars";
    body->Emit();
    std::cerr << "TEST 1c" << std::endl;
    diff = registerCounter - diff;
    localVars = varCounter - localVars;
    int numBytes = (paramLength + diff + localVars) * sizeof(int);
    std::cerr << "TEST 2" << std::endl;
    TACContainer.insert(TACContainer.begin() + index, string("    ") + string("BeginFunc ") + to_string(numBytes));
    TACContainer.push_back(string("    ") + string("EndFunc"));
    std::cerr << "TEST 3" << std::endl;
    return "";
}

void FnDecl::PrintChildren(int indentLevel) {
    if (returnType) returnType->Print(indentLevel+1, "(return type) ");
    if (id) id->Print(indentLevel+1);
    if (formals) formals->PrintAll(indentLevel+1, "(formals) ");
    if (body) body->Print(indentLevel+1, "(body) ");
}


