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
    while (temp != NULL && temp->data != afterVal) temp = temp->next;
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

void deleteAtStart() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
}

void deleteAtEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
}

void deleteByValue(int val) {
    if (head == NULL) return;
    if (head->data == val) {
        deleteAtStart();
        return;
    }
    Node* temp = head;
    while (temp != NULL && temp->data != val) temp = temp->next;
    if (temp == NULL) {
        cout << "Value not found!" << endl;
        return;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    delete temp;
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
    insertAtEnd(101);
    insertAtEnd(102);
    insertAtEnd(103);
    insertAtEnd(104);
    insertAtEnd(105);

    cout << "Original: ";
    display();

    insertAtStart(100);       // 1
    insertAfter(103, 1035);   // 2
    insertAtEnd(106);         // 3

    cout << "After Inserts: ";
    display(); // 100 <-> 101 <-> 102 <-> 103 <-> 1035 <-> 104 <-> 105 <-> 106

    deleteAtStart();          // 4 - delete 100
    deleteByValue(104);       // 5 - delete 104
    deleteAtEnd();            // 6 - delete 106

    cout << "Final: ";
    display(); // 101 <-> 102 <-> 103 <-> 1035 <-> 105
    return 0;
}