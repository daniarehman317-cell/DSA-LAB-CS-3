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

    int afterVal, newVal;
    cout << "After which value to insert? ";
    cin >> afterVal;
    cout << "Enter new value: ";
    cin >> newVal;

    Node* temp = head;
    while (temp != NULL && temp->data != afterVal) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Value " << afterVal << " not found!";
    } else {
        Node* newNode = new Node();
        newNode->data = newVal;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted!" << endl;
    }

    cout << "List: ";
    temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
    return 0;
}