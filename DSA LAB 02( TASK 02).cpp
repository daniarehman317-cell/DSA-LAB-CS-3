#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int *p = &num;
    int **pp = &p;

    cout << "Original value: " << num << endl;

    **pp = 50; // value change using double pointer

    cout << "New value: " << num << endl;

    return 0;
}