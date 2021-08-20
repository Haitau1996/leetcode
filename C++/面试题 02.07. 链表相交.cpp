class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       // 先判断是否为空
       if(headA == NULL || headB == NULL)
        return NULL;
        else{
            int lenA{}, lenB{};
            ListNode* cursorA = headA;
            ListNode* cursorB = headB;
            while(cursorA->next != NULL){
                cursorA = cursorA ->next;
                ++lenA;
            }
            while(cursorB->next != NULL){
                cursorB = cursorB->next;
                ++lenB;
            }
            if(cursorA != cursorB)
                return NULL;
            
            int diff = lenA - lenB;
            if(diff>0){
                while(diff!=0){
                    headA = headA->next;
                    --diff;
                }
            }
            else if(diff <0){
                while(diff!=0){
                    headB = headB->next;
                    ++diff;
                }
            }
            while(headA != headB){
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }
    }
};