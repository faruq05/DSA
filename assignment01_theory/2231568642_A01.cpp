//Omor Faruq 2231568642 Cse 225.10 Assignment 01
#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stack>

using namespace std;

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to generate a random array
void generate_random_array(int A[], int n) {
    random_device rd;  // Use C++11 random number generator
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, INT_MAX);  // Generate random numbers between 1 and INT_MAX
    for (int i = 0; i < n; i++) {
        A[i] = dis(gen);
    }
}

// Bubble Sort implementation
void bubble_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
            }
        }
    }
}

// Selection Sort implementation
void selection_sort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(&A[i], &A[min_index]);
        }
    }
}

// Insertion Sort implementation
void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Merge function for Merge Sort
void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort implementation
void merge_sort(int A[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

// Partition function for Quick Sort
int partition(int A[], int low, int high) {
    // Randomly choose pivot index
    int pivotIndex = low + rand() % (high - low + 1);
    int pivot = A[pivotIndex];
    swap(&A[pivotIndex], &A[high]);

    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return i + 1;
}

// Quick Sort implementation
void quick_sort(int A[], int low, int high) {
    stack<int> stack;
    stack.push(low);
    stack.push(high);

    while (!stack.empty()) {
        high = stack.top();
        stack.pop();
        low = stack.top();
        stack.pop();

        if (low < high) {
            int pivot = partition(A, low, high);

            if (pivot - 1 > low) {
                stack.push(low);
                stack.push(pivot - 1);
            }
            if (pivot + 1 < high) {
                stack.push(pivot + 1);
                stack.push(high);
            }
        }
    }
}


// Function to measure execution time using clock()
double measure_time(void (*sort_func)(int[], int), int A[], int n) {
    clock_t start_time = clock();
    sort_func(A, n);
    clock_t end_time = clock();
    double time_elapsed = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    return time_elapsed;
}

// Function to measure execution time of Merge Sort and quick sort
double measure_time_second(void (*sort_func)(int[], int, int), int A[], int left, int right) {
    clock_t start_time = clock();
    sort_func(A, left, right);
    clock_t end_time = clock();
    double time_elapsed = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    return time_elapsed;
}


int main() {
    // Define dataset sizes
    int dataset_sizes[] = {20000, 70000, 90000, 100000};

    for (int size : dataset_sizes) {
        int A[size]; // Array to be sorted

        // Generate random array for each dataset size
        generate_random_array(A, size);

        cout << "Dataset size: " << size << endl;

        // Measure execution time for each sorting algorithm
        double bubble_sort_time = measure_time(bubble_sort, A, size);
        cout << "Bubble Sort execution time: " << bubble_sort_time << " seconds" << endl;

        double selection_sort_time = measure_time(selection_sort, A, size);
        cout << "Selection Sort execution time: " << selection_sort_time << " seconds" << endl;

        double insertion_sort_time = measure_time(insertion_sort, A, size);
        cout << "Insertion Sort execution time: " << insertion_sort_time << " seconds" << endl;

        double merge_sort_time = measure_time_second(merge_sort, A, 0, size - 1);
        cout << "Merge Sort execution time: " << merge_sort_time << " seconds" << endl;

        double quick_sort_time = measure_time_second(quick_sort, A, 0, size - 1);
        cout << "Quick Sort execution time: " << quick_sort_time << " seconds" << endl;
        cout << endl;
    }

    return 0;
}
