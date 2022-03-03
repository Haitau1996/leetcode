class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* result = new ListNode(-1);
        ListNode* cursor = result;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        while(l1 && l2){
            int sum = l1->val + l2->val + carry;
            carry = sum /10;
            sum = sum%10;
            cursor->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            cursor = cursor->next;
        }
        if(l2){
            l1 = l2;
        }
        while(l1){
            int sum = l1->val + carry;
            carry = sum /10;
            sum = sum%10;
            cursor->next = new ListNode(sum);
            l1 = l1->next;
            cursor = cursor->next;
        }
        if(carry) cursor->next = new ListNode(1);
        return reverseList(result->next);
    }
private:
    ListNode* reverseList(ListNode* head){
        if(head == nullptr || head-> next == nullptr) return head;
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