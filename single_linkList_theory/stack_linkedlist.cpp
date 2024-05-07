#include <iostream>
using namespace std;

class Node
{
public:
    int key;    // data field
    Node *next; // address field
    Node(int key)
    {
        this->key = key;
        this->next = NULL;
    }
};

class Stack
{
    Node *top;
    int size;
    int maxSize;

public:
    Stack(int maxSize)
    {
        top = NULL;
        size = 0;
        this->maxSize = maxSize;
    }

    void push(int key)
    {
        Node *temp = new Node(key);
        if (size >= maxSize)
        {
            cout << "Stack Overflow. Cannot push element." << endl;
            return;
        }
        if (!temp)
        {
            cout << "Memory Allocation failed";
        }
        temp->key = key;
        temp->next = top;
        top = temp;
        size++;
        cout << "Pushing " << temp->key << endl;
    }

    void sortedPush(int key)
    {
        Node *newNode = new Node(key);
        if (!newNode)
        {
            cout << "Memory allocation failed. Cannot push element." << endl;
            return;
        }

        if (isEmpty() || key <= top->key)
        {
            // If the stack is empty or the new key is less than or equal to the top element,
            // insert the new element at the top of the stack
            newNode->next = top;
            top = newNode;
        }
        else
        {
            // Traverse the stack to find the correct position to insert the new element
            Node *current = top;
            while (current->next != NULL && current->next->key < key)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }

        cout << "Pushing " << newNode->key << endl;
        size++;
    }

    void pop()
    {

        if (isEmpty())
        {
            cout << "Stack underflow, Cannot Pop";
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << "Popping " << temp->key << endl;
        delete temp;
        size--;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    int peek() // check top
    {
        if (isEmpty())
        {
            cout << "Empty Stack, Cannot Peek";
            return 0;
        }
        else
        {
            return top->key;
        }
    }

    void printStack()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        Node *cur = top;
        while (cur != NULL)
        {
            cout << cur->key;
            if (cur->next != NULL)
                cout << " -> ";
            cur = cur->next;
        }
        cout << endl;
    }

    bool findKey(int target)
    {
        Node *cur = top;
        while (cur != NULL)
        {
            if (cur->key == target)
            {
                cout << "Target " << cur->key << " Found" << endl;
                return true;
            }
            cur = cur->next;
        }
        cout << target << " Not Found" << endl;
        return false;
    }
};

int main()
{   //lifo
    Stack s(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.printStack();

    s.sortedPush(55);
    s.sortedPush(47);
    s.sortedPush(100);
    s.sortedPush(42);
    s.sortedPush(72);
    s.sortedPush(64);
    s.printStack();

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.printStack();

    s.findKey(64);
    cout << "Top Element: " << s.peek() << endl;
}

// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int key;    // data field
//     Node *next; // address field
//     Node(int key)
//     {
//         this->key = key;
//         this->next = NULL;
//     }
// };

// class Stack
// {
//     Node *top;

// public:
//     Stack()
//     {
//         top = NULL;
//     }

//     void push(int key)
//     {
//         Node *temp = new Node(key);
//         if (!temp)
//         {
//             cout << "Overflow";
//         }
//         temp->key = key;
//         temp->next = top;
//         top = temp;
//         cout << "Pushing " << temp->key << endl;
//     }

//     void pop()
//     {
//         Node *temp;
//         if (top == NULL)
//         {
//             cout << "Stack underflow";
//         }
//         else
//         {
//             temp = top;
//             top = top->next;
//             cout << "Popping " << temp->key << endl;
//             delete temp;
//         }
//     }

//     bool isEmpty()
//     {
//         return top == NULL;
//     }

//     int peek() // check top
//     {
//         if (top == NULL)
//         {
//             return top->key;
//         }
//         else
//         {
//             cout << "Empty Stack";
//             return 0;
//         }
//     }

//     void printStack()
//     {
//         Node *cur;
//         if (top == NULL)
//         {
//             cout << "Stack Underflow";
//         }
//         else
//         {
//             cur = top;
//             while (cur != NULL)
//             {
//                 cout << cur->key << " -> ";
//                 cur = cur->next;
//             }
//             cout << "NULL" << endl;
//         }
//     }
// };

// int main()
// {
//     Stack s;
//     s.push(11);
//     s.push(12);
//     s.push(13);
//     s.push(14);
//     s.push(15);
//     s.printStack();

//     s.pop();
//     s.pop();
//     s.pop();
//     s.pop();
//     s.pop();
//     s.pop();
//     s.printStack();

//     cout << "Top Element: " << s.peek() << endl;
// }