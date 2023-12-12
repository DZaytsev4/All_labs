#ifndef _MY_EXPRESSION_
#define _MY_EXPRESSION_
#include <iostream>
#include <string>
#include "MyStack.h"
using namespace std;

class TArithmeticExpression
{
	string infix;
	string postfix;
	TStack<char> st;
	TStack<double> st2;
	int Priority(char elem);
public:
	TArithmeticExpression() : st(100), st2(100){
		infix = "";
		postfix = "";
	}
	TArithmeticExpression(string extpr):st(100), st2(100) {
		infix = extpr;
		postfix = "";
	}
	string GetExpression() {
		return infix;
	}
	void SetExpression(string expr) {
		infix = expr;
	}
	string GetPostfix() {
		return postfix;
	}
	//перевод выражения из инфиксной в постф. форму
	void ToPostfix();
	//вычисления выражения по постфиксной форме
	double CalcPostfix();
};

#endif