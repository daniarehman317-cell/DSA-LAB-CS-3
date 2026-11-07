#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node* next;
};

Node* top = nullptr;

void push(string word)
{
    Node* newNode = new Node;
    newNode->data = word;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (top == nullptr)
    {
        cout << "Nothing to undo." << endl;
        return;
    }

    cout << "Undone: " << top->data << endl;

    Node* temp = top;
    top = top->next;
    delete temp;
}

string peek()
{
    if (top == nullptr)
        return "";

    return top->data;
}

int size()
{
    int count = 0;
    Node* temp = top;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int main()
{
    int choice;
    string word;

    do
    {
        cout << "\n1. Type word";
        cout << "\n2. Undo";
        cout << "\n3. Show word count and last word";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter word: ";
            cin >> word;

            push(word);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            cout << "Word count: " << size() << endl;

            if (top == nullptr)
                cout << "No words in editor." << endl;
            else
                cout << "Last word: " << peek() << endl;
        }

    } while (choice != 0);

    while (top != nullptr)
        pop();

    return 0;
}