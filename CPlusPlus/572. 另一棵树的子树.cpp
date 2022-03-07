/*
这里需要特别注意， 因为递归不仅限于一个函数
1. isSubtree 会调用两个递归函数， 很容易混淆
*/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL && subRoot == NULL) return true;
        if(root == NULL || subRoot == NULL) return false;
        return theSameTree(root,subRoot) || isSubtree(root->right,subRoot) ||isSubtree(root->left,subRoot);
    }
private:
    bool theSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL) return true;
        return root && subRoot && ((root->val) == (subRoot->val)) &&
                    theSameTree(root->left, subRoot->left)&&
                    theSameTree(root->right, subRoot->right);
    }
};