class Solution {
public:
    int rob(TreeNode* root) {
        if(root == nullptr) return 0;
        dfs(root);
        return root->val;
    }
private:
    void dfs(TreeNode* root){
        if(root == nullptr || is_leaf(root)) return;
        dfs(root->left);
        dfs(root->right);
        // modefy current node val
        int ignore_current = get_child_val(root);
        int select_current = get_child_val(root->left) + get_child_val(root->right) + root->val;
        root->val = max(ignore_current,select_current);
    }
    bool is_leaf(TreeNode* root){
        return root!=nullptr && root->left == nullptr && root->right == nullptr;
    }
    int get_child_val(TreeNode* root){
        if(root == nullptr) return 0;
        int left = (root->left)? root->left->val : 0;
        int right = (root->right)? root->right->val : 0;
        return left + right;
    }
};