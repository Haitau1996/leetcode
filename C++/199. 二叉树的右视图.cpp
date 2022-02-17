class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> print_tree{};
        queue<TreeNode*> buffer_tree{};
        if(root != nullptr) print_tree.push(root);
        bfs(print_tree,buffer_tree);
        return result;
    }
private:    
    vector<int> result{};
    void bfs(queue<TreeNode*> print_tree, queue<TreeNode*> buffer_tree){
        if(print_tree.empty()) return;
        TreeNode* cursor{nullptr};
        while(!print_tree.empty()){
            cursor = print_tree.front();
            if(cursor-> left) buffer_tree.push(cursor->left);
            if(cursor->right) buffer_tree.push(cursor->right);
            print_tree.pop();
        }
        if(cursor) result.push_back(cursor->val);
        bfs(buffer_tree,print_tree);
    }
};