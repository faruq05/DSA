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

// preorder
void preorder(Node *node)
{ // node - left - right
    if (node == NULL)
    {
        return;
    }
    cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

// inorder
void inorder(Node *node)
{
    // left - node - right
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->key << " ";
    inorder(node->right);
}

// postorder
void postorder(Node *node)
{
    // left - right - node
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->key << " ";
}

int main()
{
    ROOT = new Node(100);
    Node *leftOfRoot = new Node(50);
    ROOT->left = leftOfRoot;
    Node *rightOfRoot = new Node(150);
    ROOT->right = rightOfRoot;

    Node *a1 = new Node(25);
    leftOfRoot->left = a1;

    Node *a2 = new Node(10);
    a1->left = a2;

    Node *b1 = new Node(175);
    rightOfRoot->right = b1;

    // tree https://prnt.sc/QZ0qqPiHithj
    cout << "Pre Order: ";
    preorder(ROOT); // 100 50 25 150 175
    cout << endl;
    cout << "In Order: ";
    inorder(ROOT); // 25 50 100 150 175
    cout << endl;
    cout << "Post Order: ";
    postorder(ROOT); // 25 50 175 150 100
    return 0;
}