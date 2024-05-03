#include <iostream>
using namespace std;

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionsort(int arr[], int n){
    int i, j , min_idx;
    for(i=0; i<n-1; i++){
        min_idx = i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx])
                min_idx = j;
        }
        if(min_idx!=i)
            swap(arr[min_idx], arr[i]);
    }

}

void printarray(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		cout<< arr[i] << " ";
	}cout<<endl;
}

int main() {
	// your code goes here
	int arr[] = {575, 22, -575, 12, 94, 64, 10, -95, 62, 34, 3668, -566};
	int n  = sizeof(arr)/ sizeof(arr[0]);
	selectionsort(arr,n);
	cout<< "sorted array: "<< endl;
	printarray(arr, n);
	return 0;
}
