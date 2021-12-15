/*
执行用时：4 ms, 在所有 C++ 提交中击败了77.30% 的用户
内存消耗：10.4 MB, 在所有 C++ 提交中击败了57.57% 的用户
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 有可能删除的刚好是第一个节点， 因此我们需要设置一个虚节点
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        for(int i = 0; i < n; ++i){
            fast = fast->next;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;
        return dummy->next;
    }
};