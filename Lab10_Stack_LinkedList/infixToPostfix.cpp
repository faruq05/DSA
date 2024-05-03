#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

int precedence(char op)
{
    // operator
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    unordered_map<char, int> precedenceMap;

    precedenceMap['+'] = 1;
    precedenceMap['-'] = 1;
    precedenceMap['*'] = 2;
    precedenceMap['/'] = 2;

    for (char c : infix)
    {
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            // push ( to stack
            st.push(c);
        }
        else if (c == ')')
        {
            // pop operators from stack until ( is encountered
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove ( from stack
        }
        else
        {
            // character is an operator
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c); // push current operator
        }
    }

    // pop remaining operators from stack to postfix
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix_expression;
    cout << "Enter infix expression: ";
    getline(cin, infix_expression);

    string postfix_expression = infixToPostfix(infix_expression);
    cout << "Postfix expression: " << postfix_expression << endl;

    return 0;
}