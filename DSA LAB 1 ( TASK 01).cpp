#include <iostream>
using namespace std;
int main(){
    int arr[5];
    int sum, avg;
    cout << "Enter 5 numbers: " << endl;
    for (int i=0; i<=4; i++){
        cin>>arr[i];
        sum+=arr[i];
        avg=sum/2;
    }
    cout<<"\nSum of all numbers: "<<sum;
    cout<<"\nAverage: "<<avg;
    return 0;
}