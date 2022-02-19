/*
* 翻转链表的时候记得和 prev 连在一起
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode* second_part = seperate(head);
        second_part = reverse(second_part);
        while(second_part){
            if(head ->val != second_part->val) return false;
            else{
                head = head->next;
                second_part = second_part->next;
            }
        }
        return true;
    }
private:
    ListNode* seperate(ListNode* head){
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        return fast;
    }
    ListNode* reverse(ListNode * head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* next = head-> next;
        while(next){
            head -> next = prev;
            prev = head;
            head = next;
            next = head->next;
        }
        head->next = prev;
        return head;
    }
};