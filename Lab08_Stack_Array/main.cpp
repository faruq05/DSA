// Omor Faruq 2231568642 CSE225L.10
#include <iostream>
#include "stackType.cpp"
using namespace std;

void checkEmpty(bool a)
{
    if (a)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}

void checkFull(bool a)
{
    if (a)
    {
        cout << "Stack is Full" << endl;
    }
    else
    {
        cout << "Stack is not full" << endl;
    }
}

void PrintStack(StackType<int> obj)
{
    StackType<int> temp;
    while (!obj.IsEmpty())
    {
        temp.Push(obj.Top());
        obj.Pop();
    }
    while (!obj.IsFull())
    {
        cout << temp.Top() << " ";
        obj.Push(temp.Top());
        temp.Pop();
    }
    cout << endl;
}

int main()
{
    // StackType<int> obj;

    // checkEmpty(obj.IsEmpty());

    // obj.Push(5);
    // obj.Push(7);
    // obj.Push(4);
    // obj.Push(2);

    // checkEmpty(obj.IsEmpty());
    // checkFull(obj.IsFull());
    // // Print stack
    // PrintStack(obj);
    // // push 3
    // obj.Push(3);
    // // Print stack after pushing 3
    // PrintStack(obj);
    // checkFull(obj.IsFull());
    // // pop two elements
    // cout << "Popped two elements" << endl;
    // obj.Pop();
    // obj.Pop();
    // checkEmpty(obj.IsEmpty());
    // // Print top elements of the stack
    // cout << "The top element of the stack is: " << obj.Top();


    StackType<char> parentheses;
    string str;
    cout << endl
         << "Enter Parenthesis set to check balance or unbalance:" << endl;
    cin >> str;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char item = str[i];
        if (item != '(' && item != ')')
        {
            cout << "Invalid input. Only '(' and ')' characters are allowed." << endl;
            return 0;
        }

        if (item == '(')
        {
            parentheses.Push(item);
        }
        try
        {
            if (item == ')')
            {
                parentheses.Pop();
            }
        }
        catch (EmptyStack)
        {
            cout << "Unbalanced" << endl;
            return 0;
        }
    }

    if (parentheses.IsEmpty())
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }
    return 0;
}
