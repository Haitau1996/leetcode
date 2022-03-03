/*
执行用时：8 ms, 在所有 C++ 提交中击败了75.39% 的用户
内存消耗：11.5 MB, 在所有 C++ 提交中击败了14.41% 的用户
8*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k ==0)
            return head;
        ListNode* end = head;
        size_t len{1};
        while(end->next != nullptr){
            end = end->next;
            ++len;
        }
        k = k % len;
        if(k == 0)
            return head;
        else{
            ListNode* cursor = head;
            for(int i = 0; i < len - k - 1; ++i){
                cursor = cursor->next;
            }
            ListNode* newHead = cursor->next;
            cursor->next = nullptr;
            end->next = head;
            return newHead;
        }
    }
};