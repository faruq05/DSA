#include <iostream>
#include <vector>
using namespace std;

int binarysearch(int arr[], int low, int high, int target){
    while(low<= high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid]<target)
            low = mid+1;
        else
            high = mid - 1;
    }
    return -1;
}

//int linearsearch(int arr[], int size, int target){
//    for(int i =0; i<size; i++){
//        if(arr[i] == target)
//            return i;
//    }
//    return -1;
//}

int main(){
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = n-1;
    int target = 5;
    int result = binarysearch(arr, low, high, target);
//    int result = linearsearch(arr, n, target);
    if(result!=-1)
        cout<<"Element found at index: "<<result<<endl;
    else
        cout<<"Element not found"<< endl;
    return 0;
}
