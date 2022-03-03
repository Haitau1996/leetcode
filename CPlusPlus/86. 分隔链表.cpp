/*
执行用时：4 ms, 在所有 C++ 提交中击败了92.91%的用户
内存消耗：9.8 MB, 在所有 C++ 提交中击败了99.45%的用户
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // base case: if head is null or linked list has only one element
        if(head==nullptr || head->next == nullptr)
            return head;
        ListNode* vNode = new ListNode(x);
        vNode->next = head;
        ListNode* vGreater = new ListNode(x);
        ListNode* greaterCursor = vGreater;
        ListNode* cursor = vNode;
        ListNode* temp;
        while(cursor->next != nullptr){
            if(cursor->next->val < x)
                cursor = cursor->next;
            else{
                temp = cursor->next;
                cursor->next = temp->next;
                greaterCursor->next = temp;
                greaterCursor = greaterCursor->next;
                greaterCursor->next = nullptr;
            }
        }
        cursor->next = vGreater->next;
        return vNode->next;
    }
};