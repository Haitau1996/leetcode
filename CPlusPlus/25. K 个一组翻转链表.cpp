/*
执行用时：8 ms, 在所有 C++ 提交中击败了98.48% 的用户
内存消耗：11.2 MB, 在所有 C++ 提交中击败了33.38% 的用户
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cursor = head;
        ListNode* tail = nullptr;
        for(int i = 1; i < k; i++){
            if(cursor!= nullptr) cursor = cursor->next;
            else return head;
        }
        if(cursor == nullptr) return head;
        ListNode* next = cursor->next;
        cursor->next = nullptr;
        tail = head;
        head = reverseList(head);
        tail->next = reverseKGroup(next,k);
        return head;
    }
private:
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* next = head->next;
        head->next = nullptr;
        while(next!=nullptr){
            ListNode* temp = next->next;
            next->next = head;
            head = next;
            next = temp;
        }
        return head;
    }
};