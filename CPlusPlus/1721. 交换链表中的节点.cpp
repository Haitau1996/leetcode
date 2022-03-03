/*
需要注意这里是从 1 开始计数， 而我们习惯从 0 开始， 添加一个 dummy head 之后刚好符合我们的习惯
*/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for(int i = 0; i < k; ++i){
            fast = fast->next;
        }
        ListNode* knode = fast;
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* revk = slow;
        int temp = knode->val;
        knode->val = revk->val;
        revk->val = temp;
        return dummy->next;
    }
};