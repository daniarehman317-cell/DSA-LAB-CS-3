#include <iostream>
using namespace std;

struct Node {
    string data; // page name
    Node* next;
};

Node* top = NULL;

void push(string page) {
    Node* newNode = new Node();
    newNode->data = page;
    newNode->next = top;
    top = newNode;
    cout << "Visit " << page << endl;
}

void pop() { // Back button
    if (top == NULL) {
        cout << "Cannot go back" << endl;
        return;
    }
    if (top->next == NULL) {
        cout << "Back -> Cannot go back" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
    cout << "Back -> Current page: " << top->data << endl;
}

void peek() { // Current page
    if (top == NULL)
        cout << "No page open" << endl;
    else
        cout << "Current page: " << top->data << endl;
}

void display() { // History
    if (top == NULL) {
        cout << "History empty" << endl;
        return;
    }
    cout << "History (top to bottom): ";
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice;
    string page;
    while (true) {
        cout << "\n1. Visit page" << endl;
        cout << "2. Back" << endl;
        cout << "3. Current page" << endl;
        cout << "4. History" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) break;

        if (choice == 1) {
            cout << "Enter page name: ";
            cin >> page;
            push(page);
        }
        else if (choice == 2) {
            pop();
        }
        else if (choice == 3) {
            peek();
        }
        else if (choice == 4) {
            display();
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}