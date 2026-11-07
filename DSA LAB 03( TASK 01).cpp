#include <iostream>
using namespace std;

struct Product {
    string name;
    int code;
    float price;
};

int main() {
    int n;
    cout << "How many products? ";
    cin >> n;

    Product *p = new Product[n]; // dynamic memory

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Product " << i + 1 << " Name: ";
        cin >> p[i].name;
        cout << "Enter Code: ";
        cin >> p[i].code;
        cout << "Enter Price: ";
        cin >> p[i].price;
    }

    cout << "\n--- All Products ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Name: " << p[i].name;
        cout << ", Code: " << p[i].code;
        cout << ", Price: " << p[i].price << endl;
    }

    delete[] p; // free memory
    p = nullptr;

    return 0;
}