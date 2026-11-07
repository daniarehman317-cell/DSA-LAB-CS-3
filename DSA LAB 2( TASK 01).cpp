#include <iostream>
using namespace std;

int main() {
    int arr[5];
    int even = 0, odd = 0;
    int *p = arr; // pointer points to array

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> *(p + i);
    }

    for (int i = 0; i < 5; i++) {
        if (*(p + i) % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    cout << "Even numbers: " << even << endl;
    cout << "Odd numbers: " << odd << endl;

    return 0;
}