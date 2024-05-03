#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of array: "<< endl;
    cin>>n;
    int* arr = new int[n];
    cout<<"Enter the array elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    for(int i=0; i<n; i++){
        cout<< arr[i] << " ";
    }
    delete[] arr;
}
