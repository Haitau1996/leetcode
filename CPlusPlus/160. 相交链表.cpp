/*
执行用时：44 ms, 在所有 C++ 提交中击败了88.80%的用户
内存消耗：14.3 MB, 在所有 C++ 提交中击败了51.76%的用户
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        int lenA{1};
        int lenB{1};
        ListNode* cursorA = headA;
        ListNode* cursorB = headB;
        while(cursorA->next != NULL){
            cursorA = cursorA->next;
            ++lenA;
        }
        while(cursorB->next != NULL){
            cursorB = cursorB->next;
            ++lenB;
        }
        if(cursorA != cursorB)
            return NULL;
        int diff = lenA - lenB;
        if(diff > 0)
            headA = advance(headA, diff);
        else    headB = advance(headB, -diff);
        while(headA != headB){
            headA= headA->next;
            headB= headB->next;
        }
        return headA;
    }
private:
    ListNode* advance(ListNode* head, int n){
        while(n>0){
            head = head->next;
            --n;
        }
        return head;
    }
};