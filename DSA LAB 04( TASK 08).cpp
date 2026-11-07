#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5, key = 40;
    int low = 0, high = n - 1, pos = -1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            pos = mid;
            break;
        }
        else if (arr[mid] < key) {
            low = mid + 1; // go right
        }
        else {
            high = mid - 1; // go left
        }
    }

    if (pos != -1)
        cout << "40 found at index " << pos;
    else
        cout << "40 not found";

    return 0;
}