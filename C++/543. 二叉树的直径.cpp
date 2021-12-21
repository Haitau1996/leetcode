/*
执行用时：20 ms, 在所有 C++ 提交中击败了10.70% 的用户
内存消耗：19.8 MB, 在所有 C++ 提交中击败了53.12% 的用户
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        printLen(root);
        result = root->val;
        findMax(root);
        return result-1;
    }
private:
    int deepth(TreeNode* root){
        if(root == nullptr) return 0;
        else return 1 + max(deepth(root->left),deepth(root->right));
    }
    void printLen(TreeNode* root){
        if(root == nullptr) return;
        root->val = deepth(root->left) + deepth(root->right) + 1;
        printLen(root->left);
        printLen(root->right);
    }
    void findMax(TreeNode* root){
        if(root == nullptr ) return;
        else if(result < root->val) result = root->val;
        findMax(root->left);
        findMax(root->right);
    }
private:
    int result;
};