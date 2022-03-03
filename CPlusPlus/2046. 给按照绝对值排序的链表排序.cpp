class Solution {
public:
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* dummp_pos = new ListNode(0);
        dummp_pos -> next = head;
        ListNode* dummp_neg = new ListNode(0);
        ListNode* cur_pos = dummp_pos;
        ListNode* cur_neg = dummp_neg;
        while(cur_pos -> next){
            if(cur_pos->next->val >=0){
                cur_pos = cur_pos->next;
            }
            else{
                cur_neg->next = cur_pos->next;
                cur_neg = cur_neg->next;
                cur_pos->next = cur_neg->next;
                cur_neg->next = nullptr;
            }
        }
        dummp_neg->next = reverse(dummp_neg->next);
        cur_neg = dummp_neg;
        while(cur_neg->next){
            cur_neg= cur_neg->next;
        }
        cur_neg->next = dummp_pos->next;
        return dummp_neg->next;
    }
private:
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* next = head->next;
        while(next){
            head->next = prev;
            prev = head;
            head = next;
            next = head->next;
        }
        head->next = prev;
        return head;
    }
};