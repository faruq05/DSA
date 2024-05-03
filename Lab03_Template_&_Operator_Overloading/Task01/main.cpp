#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main()
{

    int input, size = 5; //chaning int to char, float, double will allow to take corresponding input
    dynArr<int> d(size); //chaning int to char, float, double will allow to take corresponding input
    cout << "Enter 5 values: " << endl;
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