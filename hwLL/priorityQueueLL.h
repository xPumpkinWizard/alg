
template <class T>
class priorityQueueLL
{
private:
    class node
    {
    public:
        //put what you need here..
        T data;
        node * next;
    };

    //add what you wish here
    node * head;
    node * tail;

public:

    priorityQueueLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    ~priorityQueueLL()
    {
        while (head != nullptr) {
            node * temp = head;
            head = temp->next;
            delete(temp);
        }
        tail = nullptr;
    }

    //return true if empty, false if not
    bool empty()
    {
        if(head == nullptr){
            return true;
        }else{
            return false;
        }
    }

    //add item
    void insert(T x)
    {
        node * current = head;
        node * previous = nullptr;
        node * tempN = new node();

        tempN->data = x;
        tempN->next = nullptr;

        if (head == nullptr || x < head->data) {
            tempN->next = head;
            head = tempN;
            if (tail == nullptr) {
                tail = tempN;
            }
            return;
        }

        while (current != nullptr && current->data <= x) {
            previous = current;
            current = current->next;
        }

        previous->next = tempN;
        tempN->next = current;

        if (current == nullptr) {
            tail = tempN;
        }

    }

    //remove and return smallest item
    T extractMin()
    {
        T value;
        if(!empty()){
            value = head->data;
            node * temp = head;
            head = head->next;
            delete(temp);
            if(head == nullptr){
                tail = nullptr;
            }
        }
        return value;
    }

};
