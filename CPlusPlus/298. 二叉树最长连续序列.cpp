class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if(root == nullptr) return 0;
        helper(root->left, root->val, 1);
        helper(root->right, root->val, 1);
        return max_val;
    }
private:
    int max_val{1};
    void helper(TreeNode* root, int parent_val, int path_len){
        if(path_len>max_val) max_val = path_len;
        if(root==nullptr) return ;
        else if(root->val == parent_val+1){
            helper(root->left, root->val, path_len+1);
            helper(root->right, root->val, path_len+1);
        }
        else{
            helper(root->left, root->val, 1);
            helper(root->right, root->val, 1);
        }
    }
};
