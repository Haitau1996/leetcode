/*
一定不要忘记判断空树，空链表等等
*/
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int result = 0;
        if(root == nullptr) return 0;
        if(all_the_same(root)) result += 1;
        if(root->left) result += countUnivalSubtrees(root->left);
        if(root->right) result += countUnivalSubtrees(root->right);
        return result;
    }
private:
    bool is_leaf(TreeNode* root){
        return root!=nullptr &&
                root->left == nullptr &&
                root->right == nullptr;
    }
    bool all_the_same(TreeNode* root){
        if(root == nullptr) return false;
        if(is_leaf(root)) return true;
        else{
            if(root->left && !(all_the_same(root->left) && root->val == root->left->val)) return false;
            if(root->right && !(all_the_same(root->right) && root->val == root->right->val)) return false;
            return true;
        }
    }
};