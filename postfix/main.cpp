#include <iostream>
#include <string>
#include "..\postfixlib\MyExpression.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    TArithmeticExpression A;
    A.SetExpression("(1+2)/3 + 2.7 * 2");
    A.ToPostfix();
    string S;
    S = A.GetPostfix();
    double b = A.CalcPostfix();
    cout << S<< endl;
    cout << b;
}
