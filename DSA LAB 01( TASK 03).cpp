#include <iostream>
using namespace std;

int main() {
    int num, *x = &num;
    cout << "Enter any integer: " << endl;
    cin >> num;

    cout << "Value before changing: " << num << endl;
    *x = -189;
    cout << "Value after changing: " << *x;

    return 0;
}