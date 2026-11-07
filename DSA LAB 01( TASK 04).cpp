#include <iostream>
using namespace std;

int main() {
    int a, b;
    int *x = &a;
    int *y = &b;
    cout << "Enter any 2 numbers: " << endl;
    cin >> a >> b;
    cout << "Values before swapping: " << a << " " << b << endl;
    int temp = *x;
    *x = *y;
    *y = temp;

    cout << "Values after swapping: " << a << " " << b << endl;

    return 0;
}