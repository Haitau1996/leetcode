/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了79.16%的用户
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* cursor = head;
        ListNode* less = new ListNode(-1);
        ListNode* noLess = new ListNode(-1);
        while(cursor != NULL){
            ListNode* temp = cursor->next;
            if(cursor->val < x){
                cursor->next = less->next;
                less->next = cursor;
                cursor = temp;
            }
            else{
                cursor->next = noLess->next;
                noLess->next = cursor;
                cursor = temp;
            }
        }
        cursor = less;
        while(cursor->next != NULL){
            cursor = cursor->next;
        }
        cursor->next = noLess->next;
        return less->next;
    }
};