/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"


Program::Program(List<Decl*> *d) {
	Assert(d != NULL);
	(decls=d)->SetParentAll(this);
}

void Program::PrintChildren(int indentLevel) {
	decls->PrintAll(indentLevel+1);
	printf("\n");
}

StmtBlock::StmtBlock(List<Stmt*> *s) {
	Assert(s != NULL);
	(stmts=s)->SetParentAll(this);
}

void StmtBlock::PrintChildren(int indentLevel) {
	stmts->PrintAll(indentLevel+1);
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) {
	Assert(t != NULL && b != NULL);
	(test=t)->SetParent(this);
	(body=b)->SetParent(this);
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) {
	Assert(i != NULL && t != NULL && s != NULL && b != NULL);
	(init=i)->SetParent(this);
	(step=s)->SetParent(this);
}

void ForStmt::PrintChildren(int indentLevel) {
	init->Print(indentLevel+1, "(init) ");
	test->Print(indentLevel+1, "(test) ");
	step->Print(indentLevel+1, "(step) ");
	body->Print(indentLevel+1, "(body) ");
}

void WhileStmt::PrintChildren(int indentLevel) {
	test->Print(indentLevel+1, "(test) ");
	body->Print(indentLevel+1, "(body) ");
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) {
	Assert(t != NULL && tb != NULL); // else can be NULL
	elseBody = eb;
	if (elseBody) elseBody->SetParent(this);
}

void IfStmt::PrintChildren(int indentLevel) {
	if (test) test->Print(indentLevel+1, "(test) ");
	if (body) body->Print(indentLevel+1, "(then) ");
	if (elseBody) elseBody->Print(indentLevel+1, "(else) ");
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) {
	Assert(e != NULL);
	(expr=e)->SetParent(this);
}

void ReturnStmt::PrintChildren(int indentLevel) {
	expr->Print(indentLevel+1);
}

DeclStmt::DeclStmt(yyltype loc, Decl *decl) : Stmt(loc) {
	Assert(decl != NULL);
	(varDecl=decl)->SetParent(this);
}

void DeclStmt::PrintChildren(int indentLevel) {
	varDecl->Print(indentLevel+1);
}

string Program::Emit() {
	if ( decls->NumElements() > 0 ) {
		for ( int i = 0; i < decls->NumElements(); ++i ) {
			Decl *d = decls->Nth(i);
			d->Emit();
		}
	}

	for (int i = 0; i < TACContainer.size(); i++) {
		cout << TACContainer[i] << endl;
	}

	return "Program::Emit()";
}

string StmtBlock::Emit() {
	for(int i = 0; i < stmts->NumElements(); i++){
		Stmt* ith_statement = stmts->Nth(i); 
		ith_statement->Emit();
	}

	return "StmtBlock::Emit()";
}

string ForStmt::Emit() {
    
	string L0 = "L" + to_string(labelCounter);
	labelCounter++;
	string L1 = "L" + to_string(labelCounter);
	labelCounter++;
	string L2 = "L" + to_string(labelCounter);
	labelCounter++;


	init->Emit();

	TACContainer.push_back(L0+string(":"));
	string conditionResult = test->Emit();

	TACContainer.push_back(string("		") + string("if ") + conditionResult + string(" goto ") + L1);

	TACContainer.push_back(string("		") + string(" goto ") + L2);

	TACContainer.push_back(L1+string(":"));

	body->Emit();
	step->Emit();

	TACContainer.push_back(string("		") + string(" goto ") + L0);



	TACContainer.push_back(L2 + string(":"));

	return "ForStmt::Emit()";
}

string WhileStmt::Emit() {
	string conditionResult = test->Emit();
	string L0 = "L" + to_string(labelCounter);
	labelCounter++;
	string L1 = "L" + to_string(labelCounter);
	labelCounter++;
	string L2 = "L" + to_string(labelCounter);
	labelCounter++;


	TACContainer.push_back(L1+string(":"));

	TACContainer.push_back(string("		") + string("if ") + conditionResult + string(" goto ") + L1);

	TACContainer.push_back(string("		") + string(" goto ") + L2);

	TACContainer.push_back(L1+string(":"));

	body->Emit();
	TACContainer.push_back(string("		") + string(" goto ") + L0);



	TACContainer.push_back(L2 + string(":"));


	return "WhileStmt";
}

string IfStmt::Emit() {
	string conditionResult = test->Emit();
	string labelString1 = "L" + to_string(labelCounter);
	labelCounter++;
	string labelString2 = "L" + to_string(labelCounter);
	labelCounter++;

	TACContainer.push_back(string("		") + string("if ") + conditionResult + string(" goto ") + labelString1);

	TACContainer.push_back(string("		") + string(" goto ") + labelString2);

	TACContainer.push_back(labelString1+string(":"));

	body->Emit();
	TACContainer.push_back(labelString2+string(":"));

	if(elseBody){
		elseBody->Emit();	

	}


	//	update label container and push label container to tac container
	//	TAcontianer push labe before the branch

	//begining of if statement, have both labvesls ready for use 
	//should generate branching logic
	//can be bool constant. we have a field called test which is of typ eexpr ast_stmt.h test field!! call emit of test field, and we can test->emit() should have string variable result, now we are done with emiting with our, afer getting temp register stirng, we can directory generate lines, if test tru ethen go to code thats execute the body, otherwise skip it, 
	//the next step, we should genearate label, when we generate label, we already need to generate label, have vrarinale to record l0, call body body emit 
	return "IFstatement";
}

string ReturnStmt::Emit() {
	//what if its not returning a variable
	string ret = expr->Emit();
	TACContainer.push_back(string("    ") + string("Return ") + ret);

	return "ReturnStmt Emit()";
}

string DeclStmt::Emit() {
	varDecl->Emit();
	return "DeclStmt Emit()";
}