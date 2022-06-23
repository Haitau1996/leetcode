// 快慢指针， 赶上了就说明有环
#include "include/linked_list.hpp"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) return nullptr;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr ){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast) break;
        }
        if(slow != fast) return nullptr;
        fast = fast -> next;
        int len = 1;
        while(fast != slow){
            ++len;
            fast = fast->next;
        }
        fast = head; slow = head;
        for(int i = 0; i < len; ++i) fast = fast->next;
        while(fast!=slow){
            fast = fast->next;
            slow = slow -> next;
        }
        return fast;
    }
};
