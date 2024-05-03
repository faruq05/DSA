#include <iostream>
using namespace std;

int main() {

    int row, column;                             // Variables to store user specified row and column size
    cout << "Enter number of rows and columns: ";
    cin >> row >> column;                        // Taking inputs and storing row and column size

    int colArray[row];                           // Initialize colArray to store different column sizes in each row
    int **ptr = new int *[row];                  // Allocating a pointer array to store addresses of row arrays

    // Input column sizes for each row and allocate memory for each row array
    cout << "Enter column sizes for each row:" << endl;
    for (int i = 0; i < row; i++) {
        cin >> column;                           // Taking and storing the input column size for the current row
        ptr[i] = new int[column];                // Dynamically allocating memory for the row array
        colArray[i] = column;                    // Storing the column size in colArray to keep track
    }

    // Input values for each element in the 2D array
    cout << "Enter elements for the 2D array:" << endl;
    for (int i = 0; i < row; i++) {              // Iterate over each row
        cout << "Row " << i << ": ";
        for (int j = 0; j < colArray[i]; j++) {  // Iterate over each column in the current row
            cin >> ptr[i][j];                    // Input and store element in the 2D array
        }
    }

    // Output the elements of the 2D array
    cout << "The 2D array:" << endl;
    for (int i = 0; i < row; i++) {              // Iterate over each row
        cout << "Row " << i << ": ";
        for (int j = 0; j < colArray[i]; j++) {  // Iterate over each column in the current row
            cout << ptr[i][j] << " ";            // Output element from the 2D array
        }
        cout << endl;                            // Move to the next row
    }

    // Deallocate memory for the row arrays
    for (int i = 0; i < row; i++) {
        delete[] ptr[i];                         // Deallocate memory for each row array
    }
    delete[] ptr;                                // Deallocate memory for the pointer array

    return 0;
}
