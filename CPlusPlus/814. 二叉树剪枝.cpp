/* Copyright [2022] <haitau1996>
 * 后序遍历， 先处理子树， 处理完了之后如果当前的节点值为 0 且为叶子节点就返回 nullptr
 */
#include "include/tree.hpp"

class Solution {
 public:
    TreeNode* pruneTree(TreeNode* root){
        if (root == nullptr)
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left || root->right || root->val != 0)
            return root;
        return nullptr;
    }
};
