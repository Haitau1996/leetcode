#include "include/linked_list.hpp"
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        head = copy_list(head);
        copy_rand(head);
        return split(head);
    }
private:
    Node* copy_list(Node* head){
        Node* cursor = head;
        while(cursor){
            Node* temp = new Node(cursor->val);
            temp ->next = cursor->next;
            cursor->next = temp;
            cursor = cursor->next->next;
        }
        return head;
    }
    void copy_rand(Node* head){
        while(head && head->next){
            if(head->random){
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
    }
    Node* split(Node* head){
        Node* res = head->next;
        Node* curhead = head;
        Node* curres = res;
        while(curres && curhead){
            curhead->next = curres->next;
            curhead = curhead->next;
            if(curhead) curres->next = curhead->next;
            curres = curres->next;
        }
        return res;
    }
};
