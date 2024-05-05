// Omor Faruq CSE225.10L (Homework 4- Queue_Array_Based (Lab-09))
#include <iostream>
#include "quetype.cpp"
#include <queue>
#include <string>
using namespace std;

void checkEmpty(bool queue)
{
    if (queue)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }
}

void checkFull(bool queue)
{
    if (queue)
    {
        cout << "Queue is full" << endl;
    }
    else
    {
        cout << "Queue is not full" << endl;
    }
}

void PrintQueue(QueType<int> &qu)
{
    QueType<int> temp;
    while (!qu.IsEmpty())
    {
        int value;
        qu.Dequeue(value);
        cout << value << "\t";
        temp.Enqueue(value);
    }
    cout << endl;
    while (!qu.IsFull())
    {
        int value;
        temp.Dequeue(value);
        qu.Enqueue(value);
    }
}

int main()
{

    QueType<int> qu(5);
    checkEmpty(qu.IsEmpty());
    // enqueue four items
    qu.Enqueue(5);
    qu.Enqueue(7);
    qu.Enqueue(4);
    qu.Enqueue(2);

    checkEmpty(qu.IsEmpty());
    checkFull(qu.IsFull());

    qu.Enqueue(6);
    PrintQueue(qu); // print queue

    checkFull(qu.IsFull());

    if (!qu.IsFull()) // add another item 8, which will print overflow cause queue is already full
    {
        qu.Enqueue(8);
    }
    else
    {
        cout << "Queue Overflow" << endl;
    }

    int d; // dequeueu two items
    qu.Dequeue(d);
    qu.Dequeue(d);

    PrintQueue(qu);

    // dequeueu three items
    qu.Dequeue(d);
    qu.Dequeue(d);
    qu.Dequeue(d);

    checkEmpty(qu.IsEmpty());

    // underflow check
    if (!qu.IsEmpty())
    {
        qu.Dequeue(d);
    }
    else
    {
        cout << "Queue Underflow" << endl;
    }
    cout << endl;

    // binary values task
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    QueType<string> binaryQueue(100); // Assuming a maximum of 100 elements in the queue
    binaryQueue.Enqueue("1");         // Enqueue the first binary number "1"

    for (int i = 0; i < n; ++i)
    {
        string currentBinary;
        binaryQueue.Dequeue(currentBinary); // Dequeue and print the value
        cout << currentBinary << endl;

        string appendedZero = currentBinary + "0";
        string appendedOne = currentBinary + "1";

        binaryQueue.Enqueue(appendedZero); // Append "0" and enqueue it
        binaryQueue.Enqueue(appendedOne);  // Append "1" and enqueue it
    }
    return 0;

    //     // binary values task method 2
    //     QueType<string> binary;
    //     int n;
    //     string var; // var to hold dequeued binary number
    //     cout << "How many queue of binary number you want to print: " << endl;
    //     cin >> n;
    //     cout << endl
    //          << "The binary numbers for " << n << " queue are: " << endl;
    //     binary.Enqueue("1");

    //     while (n--)
    //     {
    //         binary.Dequeue(var);
    //         string s1 = var;
    //         cout << s1 << endl; // prints the dequeeed binary number
    //         binary.Enqueue(s1.append("0"));
    //         binary.Enqueue(var + "1");
    //     }

    //     return 0;
}