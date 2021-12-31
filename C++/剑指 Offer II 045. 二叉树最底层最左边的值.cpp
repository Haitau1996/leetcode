/*
执行用时：28 ms, 在所有 C++ 提交中击败了9.48% 的用户
内存消耗：21.1 MB, 在所有 C++ 提交中击败了89.20% 的用户
todo: 好像遍历的次数有点重复，使用剪枝重新实现
*/
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(isLeaf(root)) return root->val;
        else if(deepth(root->left) < deepth(root->right)) return findBottomLeftValue(root->right);
        return findBottomLeftValue(root->left);
    }
private:
    int deepth(TreeNode* root){
        if(root == nullptr) return 0;
        else return 1 + std::max(deepth(root->left), deepth(root->right));
    }
    bool isLeaf(TreeNode* root){
        return root != nullptr && root->left == nullptr && root->right == nullptr;
    }
};