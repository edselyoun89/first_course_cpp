#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <cmath>
#include <cctype>
#include <stack>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int performOperation(char op, int operand1, int operand2) {
    switch(op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0; 
    }
}

int evaluatePostfix(const string& expression) {
    stack<int> operands;

    for (size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];
        if (isdigit(ch)) {
            operands.push(ch - '0');
        } else if (isOperator(ch)) {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            int result = performOperation(ch, operand1, operand2);
            operands.push(result);
            continue;
        }
    }
    return operands.top();
}

int main() {
    string postfixExpression;
    cout << "Введите постфиксное выражение: ";
    getline(cin, postfixExpression);

    cout << "Значение выражения " << postfixExpression << " равно: " << evaluatePostfix(postfixExpression) << endl;

    return 0;
}
