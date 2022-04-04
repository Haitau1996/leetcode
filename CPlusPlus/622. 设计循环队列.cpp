struct MyNode{
    int val;
    MyNode* prev;
    MyNode* next;
    MyNode(int val):val(val),prev(nullptr),next(nullptr){}
};
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        dummy_head = new MyNode(-1);
        MAX_SIZE = k;
        cur_size = 0;
        dummy_head->next = dummy_head;
        dummy_head->prev = dummy_head;
    }
    
    bool enQueue(int value) {
        if(this->isFull()) return false;
        else{
            ++cur_size;
            MyNode* tail = dummy_head->prev;
            MyNode* new_tail = new MyNode(value);
            tail -> next = new_tail;
            new_tail->prev = tail;
            dummy_head->prev = new_tail;
            new_tail->next = dummy_head;
            return true;
        }
    }
    
    bool deQueue() {
        if(this->isEmpty()) return false;
        else{
            --cur_size;
            MyNode* to_remove = dummy_head->next;
            dummy_head->next = to_remove->next;
            to_remove->next->prev = dummy_head;
            delete(to_remove);
            return true;
        }
    }
    
    int Front() {
        return dummy_head->next->val;
    }
    
    int Rear() {
        return dummy_head->prev->val;
    }
    
    bool isEmpty() {
        return cur_size == 0;
    }
    
    bool isFull() {
        return cur_size == MAX_SIZE;
    }
private:
    MyNode* dummy_head;
    int MAX_SIZE;
    int cur_size;
};
