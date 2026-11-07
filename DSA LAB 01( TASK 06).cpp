#include <iostream>
using namespace std;

struct Product {
    int productID;
    string productName;
    float price;
    int quantity;
};

int main() {
    Product p;
    cout << "Enter Product ID: ";
    cin >> p.productID;

    cout << "\nEnter Product name: ";
    cin >> p.productName;

    cout << "\nEnter Price: ";
    cin >> p.price;

    cout << "\nEnter Quantity: ";
    cin >> p.quantity;

    float totalPrice = p.price * p.quantity;

    cout << "\n--- Product Details ---" << endl;
    cout << "Product ID: " << p.productID << endl;
    cout << "Product Name: " << p.productName << endl;
    cout << "Price: " << p.price << endl;
    cout << "Quantity: " << p.quantity << endl;
    cout << "Total Price: " << totalPrice << endl;

    return 0;
}