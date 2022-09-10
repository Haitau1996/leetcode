/*
 * 简单的递归问题： 根据值大小和 low, high 的比较做递归即可
 */
#include "include/tree.hpp"
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return root;
        if(root->val > high) return trimBST(root->left, low, high);
        if(root->val < low) return trimBST(root->right,low,high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
