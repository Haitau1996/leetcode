/*
* 两重递归， 效率有点低
todo: 前缀和实现
*/
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        return path_with_root(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    }
private:
    int path_with_root(TreeNode* root, int targetSum){
        if(root == nullptr) return 0;
        if(is_leaf(root) && root->val != targetSum) return 0;
        return  path_with_root(root->left, (targetSum-(root->val))) + 
                path_with_root(root->right, (targetSum-(root->val))) +
                ((root->val == targetSum)? 1 : 0);
    }
    bool is_leaf(TreeNode* root){
        return  root!=nullptr &&
                root->left == nullptr&&
                root->right == nullptr;
    }
};