#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

int main() {
    Node* first = new Node();
    Node* second = new Node();
    Node* third = new Node();

    first->data = 90;
    second->data = 30;
    third->data = 10;

    first->next = second;
    second->next = third;
    third->next = NULL;

    // Traverse and print
    Node* temp = first;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}