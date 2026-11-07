#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    int n, val;

    cout << "How many values? ";
    cin >> n;
    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
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

    int beforeVal, newVal;
    cout << "Before which value to insert? ";
    cin >> beforeVal;
    cout << "Enter new value: ";
    cin >> newVal;

    Node* newNode = new Node();
    newNode->data = newVal;

    // Case 1: Insert before head
    if (head != NULL && head->data == beforeVal) {
        newNode->next = head;
        head = newNode;
    }
    else {
        // Track previous node
        Node* prev = NULL;
        Node* curr = head;
        while (curr != NULL && curr->data != beforeVal) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Value " << beforeVal << " not found!";
        } else {
            newNode->next = curr;
            prev->next = newNode;
            cout << "Inserted!" << endl;
        }
    }

    cout << "List: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    return 0;
}