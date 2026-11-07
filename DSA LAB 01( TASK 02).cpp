#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int positive = 0, negative = 0, zero = 0;
    cout << "Enter any 10 integers: " << endl;
    for (int i = 0; i <= 9; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            negative++;
        }
        else if (arr[i] > 0) {
            positive++;
        }
        else {
            zero++;
        }
    }
    cout << "Positive numbers are: " << positive << endl;
    cout << "Negative numbers are: " << negative << endl;
    cout << "Zeros are: " << zero;
    return 0;
}