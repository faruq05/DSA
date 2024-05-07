//Total passes O(logn)
//Total Compariosn O(n)
//Time complexity O(nlogn)
#include<iostream>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    //create temp array
    int L[n1], R[n2];
    //create data to temp array
    for(int i=0; i<n1; i++){
        L[i] = arr[left+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = arr[mid+1+j];
    }
    //merge temp array back into main array
    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }else{
            arr[k] = R[j];
            j++;
        }k++;
    }
    //copy left over from temp array if any
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        i++;
        j++;
    }
}
void mergesort(int* arr, int left, int right){
    if(left<right){
        int mid = left + (right - left)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        //merge the sorted halves
        merge(arr, left, mid, right);
    }
}
void printarray(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		cout<< arr[i] << " ";
	}cout<<endl;
}
int main(){
    int arr[] = {10, 20, 30, 5, 65, -10, 21, -55};
	int n  = sizeof(arr)/ sizeof(arr[0]);
	mergesort(arr, 0, n-1);//n-1 is last index
	printarray(arr, n);
	return 0;
}
