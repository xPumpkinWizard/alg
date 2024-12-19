
template <class T>
class priorityQueueLL
{
private:
    class node
    {
    public:
        //put what you need here..
        T data;
        node *next;
    };

    //add what you wish here
    node *head;
    node *tail;

public:

    priorityQueueLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    //O(n)
    ~priorityQueueLL()
    {
        while (head != nullptr) {
            node *temp = head;
            head = temp->next;
        }
        tail = nullptr;
    }

    //return true if empty, false if not
    //O(1)
    bool empty()
    {
        if(head == nullptr) {
            return true;
        }else{
            return false;
        }
    }

    //add item
    //O(n)
    void insert(T x)
    {
        node *curr = head;
        node *prev = nullptr;
        node *temp = new node();
        temp->data = x;
        temp->next = nullptr;

        if (head == nullptr || x < head->data) {
            temp->next = head;
            head = temp;
            if(tail == nullptr) {
                tail = temp;
            }
            return;
        }
        while (curr != nullptr && curr->data <= x){
            prev = curr;
            curr = curr->next;
        }
        prev->next = temp;
        temp->next = curr;
        if(curr == nullptr) {
            tail = temp;
        }
    }

    //remove and return smallest item
    //O(1)
    T extractMin()
    {
        T x;
        if (!empty()) {
            x = head->data;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
        return x;
    }

};