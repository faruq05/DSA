//Total passes (n-1)
//Total Compariosn n(n-1)/2
//Time complexity O(n^2)
#include <iostream>
using namespace std;

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubblesort(int arr[], int n){
	int i,j;
	bool swapped;
	for(int i=0; i<n-1; i++){
		swapped = false;
		for(int j=0; j<n-i-1; j++){
			if(arr[j]>arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
			if(swapped = false)
			break;
		}
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
	int arr[] = {10, 5, 8, 20 , 25, -5, 111};
	int n  = sizeof(arr)/ sizeof(arr[0]);
	bubblesort(arr,n);
	cout<< "sorted array: "<< endl;
	printarray(arr, n);
	return 0;
}
