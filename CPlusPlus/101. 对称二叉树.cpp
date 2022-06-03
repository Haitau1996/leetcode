#include "include/tree.hpp"

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        return core(root, root);
    }

private:
    bool core(TreeNode* a, TreeNode* b)
    {
        if (a == nullptr && b == nullptr) {
            return true;
        } else if (a == nullptr || b == nullptr) {
            return false;
        } else
            return a->val == b->val && core(a->left, b->right) && core(a->right, b->left);
    }
};
