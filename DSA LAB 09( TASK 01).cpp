#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Precedence check
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // Operand directly to output
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop '('
        }
        else { // Operator
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

int main() {
    string expr1 = "A+B*C";
    string expr2 = "(A-B)*C";
    string expr3 = "A*B+C/D";

    cout << expr1 << " -> Postfix: " << infixToPostfix(expr1) << endl; // ABC*+
    cout << expr2 << " -> Postfix: " << infixToPostfix(expr2) << endl; // AB-C*
    cout << expr3 << " -> Postfix: " << infixToPostfix(expr3) << endl; // AB*CD/+

    return 0;
}
