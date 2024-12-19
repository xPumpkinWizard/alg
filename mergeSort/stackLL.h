#include <iostream>
using namespace std;

class stackLL
{
private:
    class node
    {
    public:
        //put what you need in here
        int data;
        node *next;
        node(int data){
            this->data = data;
            this->next = nullptr;
        }
    };

    node * top;

public:

    stackLL()
    {
        top = nullptr;
    }

    //Take care of memory leaks...
    //O(n)
    ~stackLL()
    {
        node *temp = top;
        while (temp != nullptr) {
            node *temp2 = temp;
            temp = temp2->next;
        }
    }

    //return true if empty, false if not
    //O(1)
    bool empty()
    {
        if(top == nullptr) {
            return true;
        }else{
            return false;
        }
    }

    //add item to top of stack
    //O(1)
    void push(int x)
    {
        node *newNode = new node(x);
        if(top == nullptr) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    //remove and return top item from stack
    //O(1)
    int pop()
    {
        if (top == nullptr) {
            return -1;
        } else {
            node *temp = top;
            top = top->next;
            int data = temp->data;
            return data;
        }
    }

    //add item x to stack, but insert it
    //right after the current ith item from the top
    //(and before the i+1 item).
    //O(n)
    void insertAt(int x, int i)
    {
        node *temp = top;
        node *newNode = new node(x);
        if (i == 0) {
            newNode->next = top;
            top = newNode;
        } else {
            for (int j = 0; j < i - 1; j++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

};