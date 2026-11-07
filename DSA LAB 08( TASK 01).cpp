#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 1. Selection Sort - sab se chota dhoond kar aage rakho
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// 2. Bubble Sort - paas wale 2 ko compare karke bada peeche bhejo
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 3. Insertion Sort - ek ek karke sahi jagah par lagao
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 4. Binary Search - array sorted hona chahiye
void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            cout << key << " found at index " << mid << endl;
            return;
        }
        else if (arr[mid] < key) {
            low = mid + 1; // right side
        }
        else {
            high = mid - 1; // left side
        }
    }
    cout << key << " not found!" << endl;
}

int main() {
    int arr[10];
    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    int choice, key;
    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display Array" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 6) break;

        if (choice == 1) {
            selectionSort(arr, 10);
            cout << "After Selection Sort: ";
            display(arr, 10);
        }
        else if (choice == 2) {
            bubbleSort(arr, 10);
            cout << "After Bubble Sort: ";
            display(arr, 10);
        }
        else if (choice == 3) {
            insertionSort(arr, 10);
            cout << "After Insertion Sort: ";
            display(arr, 10);
        }
        else if (choice == 4) {
            cout << "Enter value to search: ";
            cin >> key;
            cout << "Note: Pehle array sort karo phir search karo!" << endl;
            binarySearch(arr, 10, key);
        }
        else if (choice == 5) {
            cout << "Array: ";
            display(arr, 10);
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    cout << "Program Ended.";
    return 0;
}