#include <iostream>
#include <stack>
#include <string>
using namespace std;

void dryRun(string expr) {
    stack<char> s;
    string postfix = "";
    cout << "Scanned Char | Stack | Postfix Output\n";
    cout << "-----------------------------------------\n";

    for (char c : expr) {
        if (isalnum(c)) {
            postfix += c;
            cout << c << "            | ";
            for (int i = 0; i < s.size(); i++) cout << s.top(); s.pop();
            cout << " | " << postfix << endl;
            s.push(c); // restore stack for next step
        }
        else if (c == '(') {
            s.push(c);
            cout << c << "            | ( | " << postfix << endl;
        }
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // remove '('
            cout << c << "            | - | " << postfix << endl;
        }
        else { // operator
            while (!s.empty() && s.top() != '(' && (c == '+' || c == '-') && (s.top() == '*' || s.top() == '/')) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
            cout << c << "            | ";
            for (int i = 0; i < s.size(); i++) cout << s.top(); s.pop();
            cout << " | " << postfix << endl;
            s.push(c); // restore
        }
    }
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    cout << "End          | - | " << postfix << endl;
}

int main() {
    string expr = "(A+B)*C";
    dryRun(expr);
    return 0;
}