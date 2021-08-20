class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // base case:
        if(head == nullptr) return nullptr;
        else if(head->next == nullptr) return new TreeNode(head->val);

        int lenOfList{};
        ListNode* cursor = head;
        while(cursor != nullptr){
            ++lenOfList;
            cursor = cursor->next;
        } 
        int midLen = lenOfList /2;
        ListNode* midCur = head;
        while(midLen != 1){
            midCur = midCur->next;
            midLen--;
        }
        ListNode* temp = midCur;
        midCur = midCur->next;
        temp->next = nullptr;
        TreeNode* res = new TreeNode(midCur->val);
        res->left = sortedListToBST(head);
        res->right = sortedListToBST(midCur->next);
        return res;
    }
};