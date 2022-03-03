/*
 * 简单的从右边开始的中序遍历， 需要考虑几种特殊的情况
 1. 没有右子树， 节点的值更新为 root->val + parentVal
 2. 有右子树， 更新为 leftmost of right subtree + root->val
*/
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        core(root, 0);
        return root;
    }
private:
    void core(TreeNode* root, int parentVal){
        if(root == nullptr) return;
        if(is_leaf(root)){
            root->val = parentVal + root->val;
            return;
        }
        if(root ->right){
            core(root->right,parentVal);
        }
        int right_val = right_sub(root);
        if(root -> right == nullptr) root->val = root->val + parentVal;
        else root->val = right_val + root->val;
        if(root -> left){
            core(root->left, root->val);
        }
    }
    bool is_leaf(TreeNode* root){
        return root!= nullptr && root->left == nullptr && root->right == nullptr;
    }
    int right_sub(TreeNode* root){
        if(root->right == nullptr) return 0;
        else{
            TreeNode* cursor;
            cursor = root -> right;
            while(cursor->left){
                cursor = cursor->left;
            }
            return cursor -> val;
        }
    }
};