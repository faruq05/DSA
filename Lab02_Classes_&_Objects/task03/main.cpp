#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main()
{
    // row column size sets to 3*3
    dynArr d(3,3);

    cout << "Enter elements for the 3x3 matrix:" << endl;
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            int input;
            cin >> input;
            d.setValue(i, j, input); 
        }
    }

    // Output the 3x3 matrix
    cout << "The 3x3 Matrix:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) { 
            cout << d.getValue(i, j) << "\t"; 
        }
        cout << endl; 
    }

    return 0;
}
