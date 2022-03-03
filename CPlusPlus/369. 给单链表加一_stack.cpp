/*
执行用时：4 ms, 在所有 C++ 提交中击败了73.72% 的用户
内存消耗：8.5 MB, 在所有 C++ 提交中击败了21.90% 的用户
*/
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode* cursor = head;
        stack<ListNode*> stk;
        bool status = true;
        while(cursor!=nullptr){
            stk.push(cursor);
            cursor = cursor -> next;
        }
        while(status && !stk.empty()){
            if(stk.top()->val != 9){
                stk.top()->val = stk.top()->val + 1;
                status = false;
            }
            else{
                stk.top()->val = 0;
                stk.pop();
            }
        }
        if(status){
            ListNode* newHead =new ListNode(1);
            newHead->next = head;
            return newHead;
        }
        else
            return head;
    }
};
