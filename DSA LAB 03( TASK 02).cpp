#include <iostream>
using namespace std;

int main() {
    char *ch = new char; // allocate memory

    cout << "Enter a character: ";
    cin >> *ch;

    cout << "Stored character: " << *ch << endl;

    delete ch; // free memory
    ch = nullptr;

    cout << "Memory freed." << endl;

    return 0;
}