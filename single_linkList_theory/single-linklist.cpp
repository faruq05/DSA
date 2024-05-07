#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *next;
    Node(int key)
    {
        this->key = key;
        this->next = NULL;
    }
};

Node *head = NULL;

// PUSH
void pushFront(int key) //O(1)
{
    Node *newNode = new Node(key);
    newNode->next = head;
    head = newNode;
}

void pushBack(int key) //O(n)
{
    Node *newNode = new Node(key);
    if (head == NULL)
    {
        head = newNode;
    }
    Node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;
}

// POP
void popFront() //O(1)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

void popBack() //O(n)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    // if there is only one node in the list
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    // traverse
    Node *prev = NULL;
    Node *cur = head;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    prev->next = NULL;
    delete cur;
}

// FIND
Node *find(int key) //O(n)
{
    Node *cur = head;
    if (cur == NULL)
    {
        return NULL;
    }
    while (cur->next != NULL)
    {
        if (cur->key == key)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

// add after 
void addAfter(Node *node, int key) //O(1)
{
    Node *newNode = new Node(key);
    newNode->next = node->next;
    node->next = newNode;
}

// add before
void addBefore(Node *node, int key) //O(n)
{
    Node *newNode = new Node(key);
    // If the given node is the head node, update head to point to the new node
    if (head == node)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Otherwise, traverse the list to find the node before the given node
    Node *cur = head;
    while (cur->next != NULL && cur->next != node)
    {
        cur = cur->next;
    }
    newNode->next = node;
    cur->next = newNode;
}

// top front value
int topFront() //O(1)
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        return head->key;
    }
}

// top back value
int topBack() //O(n)
{ 
    Node *cur = head;
    if (head == NULL)
    {
        return -1;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur->key;
}

// delete node
void deleteNode(int pos) //O(n)
{
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    if (pos <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }

    // if position is 1, delete head node
    if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *prev = NULL;
    Node *cur = head;
    int curPos = 1;
    while (cur != NULL && curPos < pos)
    {
        prev = cur;
        cur = cur->next;
        curPos++;
    }

    if (cur == NULL)
    {
        cout << "Invalid position" << endl;
        return;
    }

    prev->next = cur->next;
    delete cur;
}

// count nodes
int countNode() //O(n)
{
    int count = 0;
    if (head == NULL)
    {
        cout << "List empty" << endl;
    }
    Node *cur = NULL;
    cur = head;
    while (cur != NULL)
    {
        count++;
        cur = cur->next;
    }
    return count;
}

// erase the list
void erase() //O(n)
{
    Node *cur = head;
    Node *next;

    while (cur != NULL)
    {
        next = cur->next;
        delete cur;
        cur = next;
    }
    head = NULL;
}

// reverse
void reverse() //O(n)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *next = NULL;

    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
}

//palindrome
bool isPalindrome() //O(n)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true; // Empty list or single node list is considered a palindrome
    }

    // Reverse the linked list
    reverse();

    // Store the reversed list head
    Node *reversedHead = head;

    // Reset the head pointer to the beginning of the original list
    reverse();

    // Compare the original list with the reversed list
    Node *originalCurrent = head;
    Node *reversedCurrent = reversedHead;

    while (originalCurrent != nullptr && reversedCurrent != nullptr)
    {
        if (originalCurrent->key != reversedCurrent->key)
        {
            return false; // Not a palindrome
        }
        originalCurrent = originalCurrent->next;
        reversedCurrent = reversedCurrent->next;
    }

    // If one list ends before the other, the lists are not palindromes
    if (originalCurrent != nullptr || reversedCurrent != nullptr)
    {
        return false; // Not a palindrome
    }

    return true; // Linked list is a palindrome
}

// EVEN ODD
void findEvenOdd() //O(n)
{
    Node *cur = head;
    cout << "EVEN: ";
    while (cur != NULL)
    {
        if (cur->key % 2 == 0)
        {
            cout << cur->key << " ";
        }
        cur = cur->next;
    }
    cout << endl;

    cur = head;
    cout << "ODD: ";
    while (cur != NULL)
    {
        if (cur->key % 2 != 0)
        {
            cout << cur->key << " ";
        }
        cur = cur->next;
    }
    cout << endl;
}

// PRINT
void printNode() //O(n)
{
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->key << " ";
        cur = cur->next;
    }
    cout << endl;
}

// get nth node
int getnthNode(Node *head, int idx)
{
    Node *cur = head;
    if (head == NULL)
    {
        cout << "List empty" << endl;
    }
    int count = 0;
    while (cur != NULL)
    {
        if (count == idx)
        {
            return cur->key;
        }
        count++;
        cur = cur->next;
    }
}

int main()
{
    cout << "Push Front....." << endl;
    pushFront(1);
    pushFront(2);
    pushFront(3);
    printNode(); // 3 2 1

    cout << "Push Back....." << endl;
    pushBack(4);
    pushBack(5);
    pushBack(6);
    printNode(); // 3 2 1 4 5 6

    cout << "Pop Front....." << endl;
    popFront();
    printNode(); // 2 1 4 5 6

    cout << "Pop Back....." << endl;
    popBack();
    printNode(); // 2 1 4 5

    cout << endl;

    // finding node
    cout << "Finding NODE..." << endl;
    int search;
    cout << "Enter the value you want to search in the list: " << endl;
    cin >> search;
    Node *node = find(search);
    if (node != NULL)
    {
        cout << "Node Found " << node->key << " and "
             << "Node Address: " << node << endl;
    }
    else
    {
        cout << "Node not found" << endl;
    }

    cout << endl;
    cout << "Add after..." << endl;
    Node *node1 = find(1);
    addAfter(node1, 3);
    printNode(); // 2 1 3 4 5
    cout << endl;

    cout << "Add before..." << endl;
    Node *node2 = find(4);
    addBefore(node2, 100);
    printNode(); // 2 1 3 100 4 5
    cout << endl;

    cout << "Front value: " << topFront() << endl;
    cout << "Back value: " << topBack() << endl;

    // dlt at particular point
    cout << endl;
    cout << "Delete Node at a particular position..." << endl;
    deleteNode(4); // position 4 is 100
    printNode();   // 2 1 3 4 5

    cout << endl;
    // reverse llist
    cout << "Reverse list..." << endl;
    reverse();
    printNode();

    // count nodes
    cout << endl;
    cout << "Number of nodes in this list are: " << countNode() << endl;

    cout << endl;
    // palindrome
    cout << "Palindrome check..." << endl;
    if (isPalindrome())
    {
        cout << "Linked List is a palindrome." << endl;
    }
    else
    {
        cout << "Linked List is not a palindrome." << endl;
    }

    // even odd
    cout << endl;
    cout << "EVEN ODD check..." << endl;
    findEvenOdd();

    // get nth node
    cout << endl;
    int value = getnthNode(head, 3);
    cout << "Value at index 3: " << value << endl;

    // erase
    cout << endl;
    cout << "Erasing..." << endl;
    if (head == NULL)
    {
        cout << "Linked list is already empty." << endl;
    }
    else
    {
        erase(); // Call the eraseLinkedList function to erase the linked list
        cout << "Linked list has been erased. The list is now empty." << endl;
    }

    return 0;
}
