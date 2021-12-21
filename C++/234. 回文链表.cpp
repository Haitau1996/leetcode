/*
执行用时：172 ms, 在所有 C++ 提交中击败了81.87% 的用户
内存消耗：111.4 MB, 在所有 C++ 提交中击败了74.00% 的用户
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* vNode = new ListNode(0);
        vNode->next = head;
        ListNode* fast = vNode;
        ListNode* slow = vNode;
        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* post = slow->next;
        slow->next = nullptr;
        post = revList(post);
        slow = vNode->next;
        while(slow!= nullptr && post!=nullptr){
            if(slow->val != post->val) return false;
            slow = slow->next;
            post = post->next;
        }
        return true;
    }
private:
    ListNode* revList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* next = head->next;
        head->next = nullptr;
        while(next!= nullptr){
            ListNode* temp = next->next;
            next->next = head;
            head = next;
            next = temp;
        }
        return head;
    }
};