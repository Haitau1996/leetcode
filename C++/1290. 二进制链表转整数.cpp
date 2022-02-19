class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result{};
        while(head){
            result = (result<< 1) + head->val;
            head = head->next;
        }
        return result;
    }
};