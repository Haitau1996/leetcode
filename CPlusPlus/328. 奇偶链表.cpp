/*
执行用时：12 ms, 在所有 C++ 提交中击败了87.49% 的用户
内存消耗：10.2 MB, 在所有 C++ 提交中击败了57.65% 的用户
*/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* vNode = new ListNode();
        vNode ->next = head;
        ListNode* odd = new ListNode();
        ListNode* evenCur = vNode;
        ListNode* oddCur = odd;
        ListNode* temp;
        size_t flag = 1;
        while(evenCur->next != nullptr){
            if(flag % 2){
                ++flag;
                evenCur = evenCur->next;
            }
            else{
                temp = evenCur->next;
                evenCur -> next = temp->next;
                oddCur->next = temp;
                oddCur = oddCur->next;
                oddCur ->next = nullptr;
                ++flag;
            }
        }
        evenCur->next = odd->next;
        return vNode->next;
    }
};