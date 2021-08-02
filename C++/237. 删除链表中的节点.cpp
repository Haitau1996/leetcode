/*
执行用时：8 ms, 在所有 C++ 提交中击败了93.66%的用户
内存消耗：7.5 MB, 在所有 C++ 提交中击败了73.91%的用户
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};