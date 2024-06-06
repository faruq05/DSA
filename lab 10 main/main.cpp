//Omor Faruq 2231568642 CSE225L.10 HW5
#include <iostream>
#include <string>
#include "stacktype.cpp"
using namespace std;

int priority(char ch)
{
    int value = 0;
    if (ch == '+')
        value = 1;
    else if (ch == '-')
        value = 2;
    else if (ch == '*')
        value = 3;
    else if (ch == '/')
        value = 4;
    return value;
}

string infixToPostfix(const string &input)
{
    StackType<char> st;
    string postfix;

    for (char i : input)
    {
        if (i == ' ')
            continue;

        if (isdigit(i))
            postfix += i;
        else
        {
            if (i == '(')
                st.Push(i);
            else if (i == ')')
            {
                while (!st.IsEmpty() && st.Top() != '(')
                {
                    postfix = postfix + " " + st.Top();
                    st.Pop();
                }
                if (st.IsEmpty())
                    return "Invalid input";
                st.Pop();
            }
            else
            {
                while (!st.IsEmpty() && st.Top() != '(' && priority(st.Top()) >= priority(i))
                {
                    postfix = postfix + " " + st.Top();
                    st.Pop();
                }
                postfix += " ";
                st.Push(i);
            }
        }
    }

    while (!st.IsEmpty())
    {
        if (st.Top() == '(')
            return "Invalid input";
        postfix = postfix + " " + st.Top();
        st.Pop();
    }

    return postfix;
}

double evaluatePostfix(const string &postfix)
{
    StackType<double> result;
    string value;

    for (int i = 0; i < postfix.length(); i++)
    {
        if (!isdigit(postfix[i]) && postfix[i] != ' ')
        {
            double value2 = result.Top();
            result.Pop();

            if (result.IsEmpty())
                return -1;

            double value1 = result.Top();
            result.Pop();

            if (postfix[i] == '+')
                result.Push(value1 + value2);
            else if (postfix[i] == '-')
                result.Push(value1 - value2);
            else if (postfix[i] == '*')
                result.Push(value1 * value2);
            else if (postfix[i] == '/')
            {
                if (value2 == 0)
                    return -1;
                result.Push(value1 / value2);
            }
            i++;
        }
        else if (isdigit(postfix[i]))
        {
            value += postfix[i];
        }
        else if (postfix[i] == ' ')
        {
            char *ptr;
            if (!value.empty())
                result.Push(strtod(value.c_str(), &ptr));
            value = "";
        }
    }

    return result.Top();
}

int main()
{
    string input;
    cout << "Enter an infix expression: ";
    getline(cin, input);

    string postfix = infixToPostfix(input);
    double result = evaluatePostfix(postfix);
    if (result == -1)
    {
        cout << "Invalid expression" << endl;
    }
    else
    {
        cout << "Result: " << result << endl;
    }
    return 0;
}

// given inputs:
//  10 + 3 * 5 / (16 - 4)
//  (5 + 3) * 12 / 3
//  3 + 4 / (2 - 3) * / 5
//  7 / 5 + (4 - (2) * 3
