/*
没有什么新东西， 就是二分链表 + 翻转链表， 这种基础的代码块一定要熟
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* second = seperate(head);
        second = reverse(second);
        int result = numeric_limits<int>::min();
        while(second && head){
            int new_sum = second->val + head->val;
            if(new_sum > result) result = new_sum;
            second = second->next;
            head= head->next;
        }
        return result;
    }
private:
    ListNode* seperate(ListNode* head){
        ListNode* fast = head -> next;
        ListNode* slow = head;
        while(fast!=nullptr && fast-> next != nullptr){
            slow = slow-> next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow-> next = nullptr;
        return fast;
    }
    ListNode* reverse(ListNode* head){
        if(head == nullptr || head-> next == nullptr) return head;
        ListNode* prev = nullptr;
        ListNode* next = head->next;
        while(next){
            head->next = prev;
            prev = head;
            head = next;
            next = head->next;
        }
        head-> next = prev;
        return head;
    }
};