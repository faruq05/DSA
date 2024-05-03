#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main()
{

    int input;
    dynArr d1;
    dynArr d2(5); // static size 5
    cout << "Enter 5 input values: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> input;
        d2.setValue(i, input);
    }

    for (int i = 0; i < 5; i++)
    {
        cout << d2.getValue(i) << " ";
    }
    cout << endl;

    // size increase
    int size;
    dynArr d(5);
    cout << endl
         << "Enter new size to allocate: " << endl;
    cin >> size;
    d.allocate(size);
    for (int i = 0; i < size; i++)
    {
        cin >> input;
        d.setValue(i, input);
    }

    for (int i = 0; i < size; i++)
    {
        cout << d.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}