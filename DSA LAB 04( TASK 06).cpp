#include <iostream>
using namespace std;

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;

    // Shift from index 2 to left
    for (int i = 2; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    cout << "After Delete: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}