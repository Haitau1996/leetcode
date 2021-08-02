/* 
执行用时：28 ms, 在所有 C++ 提交中击败了46.41%的用户
内存消耗：9.3 MB, 在所有 C++ 提交中击败了46.16%的用户
*/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* vNode = new ListNode(0);
        ListNode* cursor = head;
        ListNode* insertPos;
        ListNode* temp;
        ListNode* cursorBuckup;
        while(cursor!=nullptr){
            insertPos = vNode;
            while(insertPos->next != nullptr && insertPos->next->val < cursor->val){
                insertPos = insertPos->next;
            }
            temp = insertPos->next;
            insertPos->next = cursor;
            cursorBuckup = cursor->next;
            cursor->next = temp;
            cursor = cursorBuckup;
        }
        return vNode->next;
    }
};