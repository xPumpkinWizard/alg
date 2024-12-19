template <typename T>

class queueLL
{
private:
    //put what you need here...
    struct node{
        T data;
        node *next;
        node(T &x){
            this->data = x;
            this->next = nullptr;
        }
    };
    node *head;
    node *tail;

public:
    queueLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    //O(n)
    ~queueLL()
    {
        while(!empty()){
            dequeue();
        }
    }

    //add item to back of queue
    //O(1)
    void enqueue(T x)
    {
        if(empty()){
            head = new node(x);
            tail = head;
        }else{
            tail->next = new node(x);
            tail = tail->next;
        }
    }

    //remove and return first item from queue
    //O(1)
    T dequeue()
    {
        node *temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        auto data = temp->data;
        return data;
    }

    //return true if empty, false otherwise.
    //O(1)
    bool empty()
    {
        if(head == nullptr) {
            return true;
        }else{
            return false;
        }
    }

    //For the final part of the test program, template this class
    //and add a decimate method.
    //O(n)
    void decimate(){
        int count = 0;
        node *curr = head;
        node *prev = nullptr;
        while (curr != nullptr) {
            count++;
            if(count % 10 == 0) {
                if(prev == nullptr) {
                    head = curr->next;
                    curr = head;
                }else{
                    prev->next = curr->next;
                    curr = prev->next;
                }
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        if (prev != nullptr) {
            tail = prev;
        }
    }

};