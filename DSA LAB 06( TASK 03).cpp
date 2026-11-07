#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

void deleteByValue(int value) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    // Case 1: Value is in first node
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << value << " deleted." << endl;
        return;
    }

    // Case 2: Value is in middle or at end
    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        // Case 3: Not found
        cout << "Value not found" << endl;
    } else {
        prev->next = curr->next;
        delete curr;
        cout << value << " deleted." << endl;
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);

    cout << "Original: ";
    display();

    deleteByValue(10); // first node
    display();

    deleteByValue(30); // middle
    display();

    deleteByValue(100); // not found
    display();

    return 0;
}