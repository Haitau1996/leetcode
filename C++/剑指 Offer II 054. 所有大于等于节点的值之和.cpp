/*
* 有点像左右颠倒的中序遍历
* 对于左边的树， 需要记住父节点的值
* 对于某个父节点， 中序到它的时候有两种情况
    1. 他有右子树， 那么其值就是 leftmost of right substree + root->value
    2. 如果没有右子数， 值就是 root->val + parentVal
*/
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        return helper(root, 0);
    }
private:
    TreeNode* helper(TreeNode* root, int parentVal){
        if(root == nullptr) ;
        else if(isLeaf(root)){
            root->val = root->val + parentVal;
        }
        else{
            root->right = helper(root->right, parentVal);
            if(root->right) root-> val = root->val + leftMost(root->right);
            else root->val = root->val + parentVal;
            root->left = helper(root->left,root->val);
        }
        return root;
    }
    bool isLeaf(TreeNode* root){
        return root!=nullptr && root->right == nullptr && root->left == nullptr;
    }
    int leftMost(TreeNode* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root->val;
    }
};