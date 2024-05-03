#include <iostream>
using namespace std;

void insertionsort(int arr[], int n){
	int i,j,key;
	for(int i=1; i<n; i++){
		key = arr[i];
		j = i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1] = arr[j];
			j= j-1;
		}
		arr[j+1] = key;
	}
}

void printarray(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		cout<< arr[i] << " ";
	}cout<<endl;
}

int main() {
	int arr[] = {10, 5, 8, 20 , 25, -5, 111};
	int n  = sizeof(arr)/ sizeof(arr[0]);
	insertionsort(arr,n);
	cout<< "sorted array: "<< endl;
	printarray(arr, n);
	return 0;
}
