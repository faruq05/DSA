#include <iostream>
#include <algorithm>
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

int depth(Node *node)
{
    if (node == NULL)
    {
        return -1;
    }
    int leftofDepth = depth(node->left);
    int rightofDepth = depth(node->right);

    return 1 + max(leftofDepth, rightofDepth);
}

int height(Node *root)
{
    return depth(root);
}

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

Node *findkey(Node *node, int target)
{
    if (node == NULL || node->key == target)
    {   
        return node;
    }
    Node *leftResult = findkey(node -> left, target);
    if(leftResult!=NULL){
        return leftResult;
    }

    return findkey(node -> right, target);
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
    preorder(ROOT); // 100 50 25 10 150 175
    cout << endl;
    cout << "In Order: ";
    inorder(ROOT); // 10 25 50 100 150 175
    cout << endl;
    cout << "Post Order: ";
    postorder(ROOT); // 10 25 50 175 150 100

    cout << endl
         << "Depth of the tree: " << depth(ROOT) << endl;
    cout << "Height of the tree: " << height(ROOT) << endl;

    int targetKey = 205;
    Node* resultnode = findkey(ROOT, targetKey);
    if(resultnode!=NULL){
        cout<<"Found "<< targetKey <<" in the tree"<<endl;
    }else{
        cout<<targetKey<<" Not found in the tree"<<endl;
    }
    return 0;
}