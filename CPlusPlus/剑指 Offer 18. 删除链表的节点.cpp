/* 
执行用时：8 ms, 在所有 C++ 提交中击败了94.18% 的用户
内存消耗：9 MB, 在所有 C++ 提交中击败了64.64% 的用户
*/ 
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* vHead = new ListNode(0);
        vHead->next = head;
        ListNode* cursor = vHead;
        while(cursor->next != NULL && cursor->next->val != val){
            cursor = cursor->next;
        }
        cursor->next = cursor->next->next;
        return vHead->next;
    }
};