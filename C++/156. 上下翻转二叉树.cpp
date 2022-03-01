/*
* 需要提前将 root 的 left right 断开
*/
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root == nullptr || root->left == nullptr) return root;
        TreeNode* right = root->right;
        TreeNode* left = root->left;
        root->left = nullptr;
        root->right = nullptr;
        TreeNode* result = upsideDownBinaryTree(left);
        TreeNode* rightest = right_most(result);
        rightest->left = right;
        rightest->right = root;
        return result;
    }
private:
    TreeNode* right_most(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
};