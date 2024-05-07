#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *ROOT;

void preorder(Node *node)
{ // Node - left - right
    if (node == NULL)
    {
        return;
    }
    cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node *node)
{ // left - Node - right
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

void postorder(Node *node)
{ // left - right - Node
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->key << " ";
}

// insert function
Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        // when the tree is empty
        Node *newNode = new Node(key);
        return newNode;
    }
    // left side of root in BST is smaller than root
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    } // right side of root in BST is larger than root
    else
    {
        node->right = insert(node->right, key);
    }
    return node;
}

// search function
Node *search(Node *node, int key)
{ // if node is empty
    if (node == NULL)
    {
        return node;
    }
    // if root has the search value return ROOT
    if (node->key == key)
    {
        return node;
    }
    // search left side for smaller values than ROOT
    if (key < node->key)
    {
        return search(node->left, key);
    }
    // search right side for larger values than ROOT
    else
    {
        return search(node->right, key);
    }
}

// find minimum
Node *findmMin(Node *node)
{ // if node is empty
    if (node == NULL)
    {
        return node;
    }
    Node *cur = node;
    while (cur->left != NULL)
    {
        cur = cur->left;
    }
    return cur;
}

// find maximum
Node *findmMax(Node *node)
{ // if node is empty
    if (node == NULL)
    {
        return node;
    }
    Node *cur = node;
    while (cur->right != NULL)
    {
        cur = cur->right;
    }
    return cur;
}

//delete node
Node* deleteNode(Node* node, int key){
    //do it yourself B!tch
}

int main()
{
    // your code goes here
    // ROOT = new Node(100);
    // Node *leftOfROOT = new Node(50);
    // ROOT->left = leftOfROOT;
    // Node *rightOfROOT = new Node(150);
    // ROOT->right = rightOfROOT;

    // Node *a = new Node(25);
    // leftOfROOT->left = a;

    // Node *b = new Node(175);
    // rightOfROOT->right = b;

    // cout << "Pre order: ";
    // preorder(ROOT); // 100 50 150
    // cout << endl;
    // cout << "In order: ";
    // inorder(ROOT);
    // cout << endl;
    // cout << "Post order: ";
    // postorder(ROOT);
    // cout << endl;

    ROOT = insert(ROOT, 100);
    insert(ROOT, 50);
    insert(ROOT, 150);
    insert(ROOT, 20);
    insert(ROOT, 70);
    insert(ROOT, 200);
    insert(ROOT, 75);
    insert(ROOT, 10);
    // this is how the tree will look like https://prnt.sc/Bg-m2u4z2kYJ

    cout << "Pre order: ";
    preorder(ROOT); // 100 50 20 10 70 75 150 200
    cout << endl;
    cout << "In order: ";
    inorder(ROOT); // 10 20 50 70 75 100 150 200
    cout << endl;
    Node *node = search(ROOT, 5000);
    if (node != NULL)
    {
        cout << "Value Exist" << endl;
    }
    else
    {
        cout << "Value Doesn't Exist" << endl;
    }

    // find minimum
    node = findmMin(ROOT);
    if (node != NULL)
    {
        cout << "Minimum value: " << node->key << endl;
    }

    // find maximum
    node = findmMax(ROOT);
    if (node != NULL)
    {
        cout << "Maximum value: " << node->key << endl;
    }
    return 0;
}