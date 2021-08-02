/* 
执行用时：44 ms, 在所有 C++ 提交中击败了71.19%的用户
内存消耗：17.7 MB, 在所有 C++ 提交中击败了40.79%的用户
*/
class Solution {
public:
    void reorderList(ListNode* head) {
        // 先便利一遍看链表的长度
        ListNode* cursor = head;
        size_t listLength{0};
        while(cursor != nullptr){
            ++listLength;
            cursor = cursor->next;
        }
        stack<ListNode*> postStack;
        cursor = head;
        ListNode* postList;
        for(size_t i = 0; i< listLength/2; ++i){
            cursor = cursor->next;
        }
        postList = cursor->next;
        cursor->next = nullptr;
        while(postList != nullptr){
            postStack.push(postList);
            postList=postList->next;
        }
        cursor = head;
        ListNode* temp;
        while(!postStack.empty()){
            temp = cursor->next;
            cursor->next = postStack.top();
            cursor = cursor->next;
            cursor->next = temp;
            postStack.pop();
            cursor = cursor->next;
        }
    }
};