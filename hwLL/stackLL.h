#include <iostream>
using namespace std;

class stackLL{
    class node{

    public:
        int data;
        node *next;
        node(int data){
            this->data = data;
            this->next = nullptr;
        }
    };
    node *top;
public:
    stackLL(){
        top = nullptr;
    }
    ~stackLL(){
        node *temp = top;
        while(temp != nullptr){
            node *temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }
    bool empty(){
        if(top == nullptr){
            return true;
        }else{
            return false;
        }
    }

    void push(int data){
        node *newNode = new node(data);
        if(top == nullptr){
            top = newNode;
        }
        else{
            newNode->next = top;
            top = newNode;
        }
    }

    int pop(){
        if(top == nullptr){
            return -1;
        }
        else{
            node *temp = top;
            top = top->next;
            int data = temp->data;
            delete temp;
            return data;
        }
    }


    //add item x to stack, but insert it
    //right after the current ith item from the top
    //(and before the i+1 item).
    void insertAt(int x, int i){
        // Your code here
        node *temp = top;
        node *newNode = new node(x);
        if(i == 0){
            newNode->next = top;
            top = newNode;
        }
        else{
            for(int j = 0; j < i-1; j++){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

};