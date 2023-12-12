#include "MyExpression.h"
int TArithmeticExpression::Priority(char elem) {
	switch (elem) {
	case '(': return 1;
	case ')': return 1;
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 3;
	default: throw elem;
	}
}
void TArithmeticExpression::ToPostfix() {
	st.Clear();
	postfix = "";
	string src = "(" + infix + ")";
	char elem = ' ! ';
	unsigned int i = 0;
	while (i < src.size()) {
		if (src[i] >= '0' && src[i] <= '9' || src[i] == '.') {
			postfix += src[i];
		}
		if (src[i] == '+' || src[i] == '-' || src[i] == '*' || src[i] == '/') {
			postfix += " ";
			elem = st.Pop();
			while (Priority(elem) >= Priority(src[i])) {
				postfix += elem;
				elem = st.Pop();
			}
			st.Push(elem);
			st.Push(src[i]);
		}
		else if (src[i] == '(') {
			st.Push(src[i]);
		}
		else if (src[i] == ')') {
			elem = st.Pop();
			while (elem != '(') {
				postfix += elem;
				elem = st.Pop();
			}
		}
		i++;
	}
}
double TArithmeticExpression::CalcPostfix() {
	st2.Clear();
	unsigned int i = 0;
	while (i < postfix.size()) {
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
			double b = st2.Pop();
			double a = st2.Pop();
			switch (postfix[i]) {
			case '+' :{st2.Push(a + b); break; }
			case '-': {st2.Push(a - b); break; }
			case '*': {st2.Push(a * b); break; }
			case '/': {st2.Push(a / b); break; }
			}
		}
		else if (postfix[i] >= '0' && postfix[i] <= '9' || postfix[i] == '.') {
			size_t idx;
			double tmp = stod(&postfix[i], &idx);
			st2.Push(tmp);
			i += idx - 1;
		}
		i++;
	}
	return st2.Pop();
}