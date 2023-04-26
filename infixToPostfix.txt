#include <stack>
#include <cstring>
#include <iostream>
using namespace std;
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

 string infixToPostfix( string expression) {
     stack<char> s;
    s.push('N');
    int l = expression.length();
     string postfix = "";
    for (int i = 0; i < l; i++) {
        if ((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z'))
            postfix += expression[i];
        else if (expression[i] == '(')
            s.push('(');
        else if (expression[i] == ')') {
            while (s.top() != 'N' && s.top() != '(') {
                char c = s.top();
                s.pop();
                postfix += c;
            }
            if (s.top() == '(') {
                char c = s.top();
                s.pop();
            }
        } else {
            while (s.top() != 'N' && precedence(expression[i]) <= precedence(s.top())) {
                char c = s.top();
                s.pop();
                postfix += c;
            }
            s.push(expression[i]);
        }
    }
    while (s.top() != 'N') {
        char c = s.top();
        s.pop();
        postfix += c;
    }
    return postfix;
}

int main() {
    string expression;
     cout << "Enter the infix expression: ";
     getline( cin, expression);
     string postfix = infixToPostfix(expression);
     cout << "Postfix expression: " << postfix <<  endl;
    return 0;
}
