class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head-> next == nullptr) return head;
        ListNode* second = splitList(head);
        ListNode* first = sortList(head);
        second = sortList(second);
        return mergeList(first,second);
    }
private:
    ListNode* mergeList(ListNode* first, ListNode* second){
        ListNode* dummyNode = new ListNode();
        ListNode* cursor = dummyNode;
        while(first!= nullptr && second!=nullptr){
            if(first->val < second->val){
                cursor->next = first;
                first = first->next;
                cursor = cursor->next;
            }
            else{
                cursor->next = second;
                second = second-> next;
                cursor = cursor -> next;
            }
        }
        if(first){
            cursor->next = first;
        }
        else{
            cursor-> next = second;
        }
        return dummyNode->next;
    }
    ListNode* splitList(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow-> next = nullptr;
        return fast;
    }
};