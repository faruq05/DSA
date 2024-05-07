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

class Queue
{
private:
    Node *head, *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(int key)
    {
        Node *newNode = new Node(key);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void dequeue()
    {
        if (head == NULL)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        delete temp;
        size--;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    int getFront()
    {
        if (head == NULL)
        {
            return -1;
        }
        return head->key;
    }

    int getBack()
    {
        if (tail == NULL)
        {
            return -1;
        }
        return tail->key;
    }

    void printQueue()
    {
        Node *cur = head; // Use a pointer to traverse the queue

        cout << "Queue: ";
        while (cur != NULL)
        {
            cout << cur->key << " ";
            cur = cur->next; // Move to the next node
        }
        cout << endl;
    }

    bool findKey(int target){
        Node* cur = head;
        while(cur!=NULL){
            if(cur->key == target){
                cout<< cur-> key << " Found"<<endl;
                return true;
            }
            cur = cur->next;
        }
        cout<<target<<" Not found"<<endl;
        return false;
    }
};

int main()
{
    Queue qu;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.enqueue(4);
    qu.enqueue(5);
    qu.enqueue(6);

    qu.printQueue();

    qu.dequeue();
    qu.dequeue();

    qu.printQueue();

    cout << "Queue Front: "<< qu.getFront() << endl;
    cout << "Queue Back: "<< qu.getBack() << endl;
    cout<< "Queu Size: "<< qu.getSize() << endl;

    qu.findKey(5);
    qu.findKey(10);
    return 0;
}