/*
执行用时：24 ms, 在所有 C++ 提交中击败了82.59%的用户
内存消耗：14.8 MB, 在所有 C++ 提交中击败了27.49%的用户
*/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* vNode = new ListNode(0);
        vNode->next = head;
        ListNode* cursor = vNode;
        ListNode* temp;
        while(cursor->next != nullptr){
            if(cursor->next->val == val){
                temp = cursor->next;
                cursor->next = temp->next;
                delete temp;
            }
            else{
                cursor = cursor->next;
            }
        }
        return vNode->next;
    }
};