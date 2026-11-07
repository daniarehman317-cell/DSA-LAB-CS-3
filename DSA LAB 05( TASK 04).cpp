#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int choice, val, afterVal;

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1) Insert at Start" << endl;
        cout << "2) Insert at End" << endl;
        cout << "3) Insert in Middle (After value)" << endl;
        cout << "4) Display List" << endl;
        cout << "5) Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 5) break;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> val;
            Node* newNode = new Node();
            newNode->data = val;
            newNode->next = head;
            head = newNode;
        }
        else if (choice == 2) {
            cout << "Enter value: ";
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
        else if (choice == 3) {
            cout << "After which value? ";
            cin >> afterVal;
            cout << "Enter new value: ";
            cin >> val;
            Node* temp = head;
            while (temp != NULL && temp->data != afterVal)
                temp = temp->next;
            if (temp == NULL) {
                cout << "Value not found!" << endl;
            } else {
                Node* newNode = new Node();
                newNode->data = val;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
        else if (choice == 4) {
            display(head);
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    cout << "Program Ended.";
    return 0;
}