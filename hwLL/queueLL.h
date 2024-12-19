template <typename T>
class queueLL {
private:
    //put what you need here...
    struct node {
        T data;
        node* next;
        node(T& value) {
            this->data = value;
            this->next = nullptr;
        }
    };

    node* head;
    node* tail;

public:
    queueLL() {
        head = nullptr;
        tail = nullptr;
    }

    ~queueLL() {
        while (!empty()) {
            dequeue();
        }
    }

    // Add item to the back of the queue
    void enqueue(T x) {
        if(empty()){
            head=new node(x);
            tail=head;
        }
        else{
            tail->next=new node(x);
            tail=tail->next;
        }
    }

    // Remove and return the first item from the queue
    T dequeue() {
        node* temo=head;
        head=head->next;
        if(head==nullptr){
            tail=nullptr;
        }
        auto data=temo->data;
        delete temo;
        return data;
    }

    bool empty() {
        if(head == nullptr){
            return true;
        }else{
            return false;
        }
    }

    // For the final part of the test program, template this class
    // and add a decimate method.
    void decimate() {
        int count = 0;
        node* current = head;
        node* previous = nullptr;

        while (current != nullptr) {
            count++;
            if (count % 10 == 0) {
                if (previous == nullptr) {
                    head = current->next;
                    delete current;
                    current = head;
                } else {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                }
            } else {
                previous = current;
                current = current->next;
            }
        }

        if (previous != nullptr) {
            tail = previous;
        }
    }
};