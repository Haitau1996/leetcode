class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // base case: 
        if(head == NULL || head->next == NULL)
            return NULL;
        ListNode* fastCur = head;
        ListNode* slowCur = head;
        while(fastCur != NULL){
            fastCur = fastCur->next;
            if(fastCur == slowCur)
                break;
            else if(fastCur == NULL)
                return NULL;
            else{
                fastCur= fastCur->next;
                slowCur= slowCur->next;
            }
        }
        if(fastCur != slowCur)
            return NULL;
        else{
            size_t loopSz = 1;
            fastCur = fastCur->next;
            while(fastCur!= slowCur){
                loopSz++;
                fastCur=fastCur->next;
            }
            fastCur = head;
            for(int i =0; i< loopSz; ++i)
                fastCur = fastCur->next;
            while(fastCur!=head){
                fastCur = fastCur->next;
                head = head->next;
            }
            return fastCur;
        }
    }
};