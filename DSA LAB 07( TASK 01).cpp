#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertAtEnd(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void insertAtStart(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    head = newNode;
}

void insertAfter(int afterVal, int newVal) {
    Node* temp = head;
    while (temp != NULL && temp->data != afterVal) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Value not found!" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = newVal;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    cout << "Original: ";
    display();

    insertAtStart(5);
    insertAfter(20, 25);
    insertAtEnd(60);

    cout << "Final: ";
    display(); // 5 <-> 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 50 <-> 60
    return 0;
}