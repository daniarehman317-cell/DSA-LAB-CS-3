#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stack[++top] = val;
    cout << val << " pushed." << endl;
}

void pop() {
    if (top == -1) {
        cout << "Stack underflow!" << endl;
        return;
    }
    cout << stack[top--] << " popped." << endl;
}

int search(int x) {
    for (int i = top; i >= 0; i--) {
        if (stack[i] == x) return (top - i + 1); // steps from top
    }
    return -1;
}

void display() {
    if (top == -1) {
        cout << "Stack empty." << endl;
        return;
    }
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
    cout << endl;
}

int main() {
    int n, val;
    cout << "Enter 5 integers:\n";
    for (int i = 0; i < 5; i++) {
        cin >> val;
        push(val);
    }

    push(99); // overflow
    display();

    // Search
    int x = stack[top]; // top element
    cout << "Searching " << x << ": position " << search(x) << endl;
    cout << "Searching 999: position " << search(999) << endl;

    // Pop all
    for (int i = 0; i < 5; i++) pop();
    pop(); // underflow

    return 0;
}