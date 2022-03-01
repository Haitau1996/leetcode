class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if(tree!=nullptr) current.push(tree);
        vector<ListNode*> result{};
        while(!current.empty()){
            ListNode* head= new ListNode(-1);
            ListNode* cursor = head;
            while(!current.empty()){
                auto to_pop = current.front();
                cursor->next = new ListNode(to_pop->val);
                cursor = cursor->next;
                if(to_pop->left) next.push(to_pop->left);
                if(to_pop->right) next.push(to_pop->right);
                current.pop();
            }
            result.push_back(head->next);
            swap(current,next);
        }
        return result;
    }
private:
    queue<TreeNode*> current;
    queue<TreeNode*> next;
};