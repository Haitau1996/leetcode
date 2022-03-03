class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next == nullptr)
            return head;
        ListNode* virtualNode = new ListNode(0);
        virtualNode->next = head;
        ListNode* cursor = virtualNode;
        while(cursor->next != nullptr && cursor -> next->next != nullptr){
            if(cursor->next->val != cursor->next->next->val)
                cursor = cursor->next;
            else{
                ListNode* toDelete = cursor->next;
                while(toDelete->next!= nullptr){
                    if(toDelete->next->val != toDelete->val)
                        break;
                    else   toDelete=toDelete->next;
                }
                cursor->next = toDelete->next;
            }
        }
        return virtualNode->next;
    }
};