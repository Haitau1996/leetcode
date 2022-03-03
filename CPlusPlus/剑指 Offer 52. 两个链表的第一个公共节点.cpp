/*
执行用时：36 ms, 在所有 C++ 提交中击败了89.85% 的用户
内存消耗：14.2 MB, 在所有 C++ 提交中击败了62.01% 的用户
* 需要考虑有空指针的情况
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* cursorA = headA;
        ListNode* cursorB = headB;
        int lenA = 0;
        int lenB = 0;
        while(cursorA != NULL){
            ++lenA;
            cursorA = cursorA->next;
        }
        while(cursorB != NULL){
            ++lenB;
            cursorB = cursorB->next;
        }
        int diff = abs(lenB - lenA);
        if(lenA > lenB){
            for(int i =0; i< diff; i++)
                headA = headA->next;
        }
        else{
            for(int i = 0; i < diff; i++)
                headB = headB->next;
        }
        while(headA != headB ){
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};