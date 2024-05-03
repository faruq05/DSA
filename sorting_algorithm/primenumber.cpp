//Omor Faruq ID:2231568642 CSE225L.10

#include <iostream>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << "Prime number between 300 to 500 are: " << endl;
    for (int i = 300; i <= 500; i++)
    {
        if (isPrime(i))
            cout << i << " ";
    }
}