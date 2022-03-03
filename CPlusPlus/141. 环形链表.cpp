class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode* fastCur = head;
        ListNode* slowCur = head;
        while(fastCur != NULL){
            fastCur = fastCur-> next;
            if(fastCur == NULL) return false;
            else{
                fastCur = fastCur->next;
                slowCur = slowCur ->next;
            }
            if(fastCur == slowCur)
                break;
        }
        return fastCur != NULL;
    }
};