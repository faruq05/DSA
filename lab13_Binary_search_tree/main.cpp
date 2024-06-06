#include <iostream>
#include "binarysearchtree.h"
#include "binarysearchtree.cpp"
#include <algorithm>
#include <functional>
#include "quetype.cpp"
#include "quetype.h"

using namespace std;

int main()
{
    TreeType<int> tree;

    if (tree.IsEmpty())
    {
        cout << "Tree is Empty" << endl;
    }
    else
    {
        cout << "Tree is not empty" << endl;
    }
    tree.InsertItem(4);
    tree.InsertItem(9);
    tree.InsertItem(2);
    tree.InsertItem(7);
    tree.InsertItem(3);
    tree.InsertItem(11);
    tree.InsertItem(17);
    tree.InsertItem(0);
    tree.InsertItem(5);
    tree.InsertItem(1);

    if (tree.IsEmpty())
    {
        cout << "Tree is Empty" << endl;
    }
    else
    {
        cout << "Tree is not empty" << endl;
    }
    cout << tree.LengthIs() << endl;

    int a = 9;
    bool found;

    tree.RetrieveItem(a, found);
    if (found)
    {
        cout << "Item found" << endl;
    }
    else
    {
        cout << "Item is not found" << endl;
    }

    a = 13;
    tree.RetrieveItem(a, found);
    if (found)
    {
        cout << "Item found" << endl;
    }
    else
    {
        cout << "Item is not found" << endl;
    }
    tree.ResetTree(IN_ORDER);
    int item;
    bool finished = false;
    while (!finished)
    {
        tree.GetNextItem(item, IN_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;

    tree.ResetTree(PRE_ORDER);
    finished = false;
    while (!finished)
    {
        tree.GetNextItem(item, PRE_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;
    tree.ResetTree(POST_ORDER);
    finished = false;
    while (!finished)
    {
        tree.GetNextItem(item, POST_ORDER, finished);
        cout << item << " ";
    }
    cout << endl;
    tree.MakeEmpty();

    // task two
    int sequence[] = {4, 9, 2, 7, 3, 11, 17, 0, 5, 1};
    int n = sizeof(sequence) / sizeof(sequence[0]);
    sort(sequence, sequence + n);

    TreeType<int> balanceTree;
    function<void(int[], int, int)> insertBalance = [&balanceTree, &insertBalance](int arr[], int start, int end)
    {
        if (start > end)
        {
            return;
        }
        int mid = (start + end) / 2;
        balanceTree.InsertItem(arr[mid]);
        insertBalance(arr, start, mid - 1);
        insertBalance(arr, mid + 1, end);
    };
    insertBalance(sequence, 0, n - 1);

    cout << "Balanced tree(Inorder Traversal):";
    balanceTree.ResetTree(IN_ORDER);
    finished = false;
    while (!finished)
    {
        balanceTree.GetNextItem(item, IN_ORDER, finished);
        if (!finished)
        {
            cout << item << " ";
        }
    }
    cout << endl;
}