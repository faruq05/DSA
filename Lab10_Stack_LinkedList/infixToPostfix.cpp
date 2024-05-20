#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// precedence of operators
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// associativity of operators 
char associativity(char c)
{
    if (c == '^')
        return 'R';
    return 'L';
}


void infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // If it is an operand add to the output string
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;

        // If the scanned character is ( push in stack
        else if (c == '(')
            st.push('(');

        // if user gives ) pop and add to output string from the stack, until get (
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // Pop '('
        }

        // if Operator scanned
        else
        {
            while (!st.empty() && precedence(s[i]) < precedence(st.top()) ||
                   !st.empty() && precedence(s[i]) == precedence(st.top()) &&
                       associativity(s[i]) == 'L')
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop rest elements
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << result << endl;
}

int main()
{
    string exp;
    cout << "Enter infix expression" << endl;
    cin >> exp;
    // a+b*(c^d-e)^(f+g*h)-i;                     
    infixToPostfix(exp);

    return 0;
}
