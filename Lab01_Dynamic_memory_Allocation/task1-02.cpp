#include <iostream>
using namespace std;

int main()
{
    int numRows, numCols;
    cout << "Enter Number of Rows and Columns: " << endl;
    cin >> numRows;
    cin >> numCols;

    // Even Array
    int **evenArray = new int *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        evenArray[i] = new int[numCols];
    }

    // input values
    cout << "Enter elements of Array: " << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cin >> evenArray[i][j];
        }
    }

    // output values
    cout << "The Even Array: " << endl;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            cout << evenArray[i][j]<<" ";
        }
        cout<<endl;
    }

    // deallocate
    for (int i = 0; i < numRows; i++)
    {
        delete[] evenArray[i];
    }
    delete[] evenArray;
    return 0;
}
