#include <iostream>
using namespace std;

struct Student {
    string name;
    int rollNo;
    float marks;
};

int main() {
    Student s1;
    cout << "Enter student name: ";
    cin >> s1.name;

    cout << "Enter roll no: ";
    cin >> s1.rollNo;

    cout << "Enter marks: ";
    cin >> s1.marks;

    if (s1.marks < 50) {
        cout << "Student has fail.";
    }
    else {
        cout << "Student has passed.";
    }

    return 0;
}