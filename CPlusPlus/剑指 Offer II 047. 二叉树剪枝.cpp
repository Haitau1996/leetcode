/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9.2 MB, 在所有 C++ 提交中击败了39.37% 的用户
* 没什么新东西， 实质上就是后序遍历
*/

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==nullptr) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(isLeaf(root) && root->val == 0) return nullptr;
        return root;
    }
private:
    bool isLeaf(TreeNode* root){
        return root!= nullptr && root->left == nullptr && root->right == nullptr;
    }
};