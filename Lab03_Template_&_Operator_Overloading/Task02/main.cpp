#include <iostream>
#include "complex.cpp"
using namespace std;

int main()
{

    Complex c1(5, 2), c2(5, 3);

    Complex c3 = c1 + c2; // Adding
    c3.Print();

    Complex c4 = c1 * c2; // Multiplying
    c4.Print();

    // cout << (c1 != c2) << endl;
    // Checking if two complex numbers are not equal
    if ((c1 != c2) == 0)
    {
        cout << "The complex numbers are not equal";
    }
    else
    {
        cout << "The complex numbers are equal";
    }
    return 0;
}