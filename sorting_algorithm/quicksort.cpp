#include<iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++; // Increase index of smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quicksort(int* arr, int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
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
	quicksort(arr, 0, n-1);//n-1 is last index
	printarray(arr, n);
	return 0;
}
