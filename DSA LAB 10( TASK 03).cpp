#include <iostream>
using namespace std;

#define MAX 32
int stackArr[MAX];
int top = -1;

void push(int val) {
    top++;
    stackArr[top] = val;
}

int pop() {
    int val = stackArr[top];
    top--;
    return val;
}

bool isEmpty() {
    return top == -1;
}

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    cout << "Binary: ";

    // Special case: input 0
    if (num == 0) {
        cout << 0 << endl;
        return 0;
    }

    // Divide by 2 and push remainder
    int temp = num;
    while (temp > 0) {
        int remainder = temp % 2;
        push(remainder);
        temp = temp / 2;
    }

    // Pop all remainders and print
    while (!isEmpty()) {
        cout << pop();
    }
    cout << endl;

    return 0;
}