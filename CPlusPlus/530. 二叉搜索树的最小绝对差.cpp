/*
 * 简单的树上 DFS
 */
#include "include/tree.hpp"

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return numeric_limits<int>::max();
        int left = root->left == nullptr ? -10001: biggest(root->left);
        int right = root->right == nullptr ? 20001: smallest(root->right);
        int left_res = getMinimumDifference(root->left);
        int right_res = getMinimumDifference(root->right);
        return min({root->val - left, right- root->val, left_res, right_res});
    }
private:
    int biggest(TreeNode* root){
        while(root->right) 
            root = root->right;
        return root->val;
    }
    int smallest(TreeNode* root){
        while(root->left)
            root = root->left;
        return root->val;
    }
};
