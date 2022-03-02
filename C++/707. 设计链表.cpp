struct MyNode{
    MyNode* next;
    int val;
    MyNode(int value):val(value),next(nullptr){}
};
typedef MyNode* NodePtr;
class MyLinkedList {
public:
    MyLinkedList() {
        dummyHead = new MyNode(-1);
    }
    
    int get(int index) {
        NodePtr cursor = dummyHead;
        int i = 0;
        while(cursor!= nullptr && i < index){
            ++i;
            cursor = cursor->next;
        }
        if(cursor && cursor->next){
            return cursor->next->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        NodePtr next = dummyHead->next;
        dummyHead->next = new MyNode(val);
        dummyHead->next->next = next;
    }
    
    void addAtTail(int val) {
        NodePtr cursor = dummyHead;
        while(cursor->next){
            cursor = cursor->next;
        }
        cursor->next = new MyNode(val);
    }
    
    void addAtIndex(int index, int val) {
        NodePtr cursor = dummyHead;
        int i = 0;
        while(cursor!=nullptr && i < index){
            ++i;
            cursor = cursor->next;
        }
        if(cursor != nullptr){
            NodePtr next = cursor->next;
            cursor->next = new MyNode(val);
            cursor->next->next = next;
        }
    }
    
    void deleteAtIndex(int index) {
        NodePtr cursor = dummyHead;
        int i = 0;
        while(cursor!=nullptr && i < index){
            ++i;
            cursor = cursor->next;
        }
        if(cursor && cursor->next){
            cursor->next = cursor->next->next;
        }
    }
private:
    NodePtr dummyHead;
};