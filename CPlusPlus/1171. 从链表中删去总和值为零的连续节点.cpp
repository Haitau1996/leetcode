class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> prefix_sum;
        int sum = 0;
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cursor = dummyHead;
        while(cursor!=nullptr){
            sum += cursor->val;
            prefix_sum[sum] = cursor;
            cursor = cursor->next;
        }
        sum = 0;
        for (cursor = dummyHead; cursor != nullptr; cursor = cursor->next) {
            sum += cursor->val;
            cursor->next = prefix_sum.find(sum)->second->next;
        }
        return dummyHead->next;
    }
};
