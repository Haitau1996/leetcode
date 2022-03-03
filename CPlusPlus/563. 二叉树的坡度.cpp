/*
* 使用后序遍历可以少做很多运算
* 还有就是记得处理空指针
*/
class Solution {
public:
    int findTilt(TreeNode* root) {
        post_order(root);
        return helper(root);
    }
private:
    bool is_leaf(TreeNode* root){
        return root!=nullptr && root->left == nullptr && root->right == nullptr;
    }
    void post_order(TreeNode* root){
        if(root == nullptr) return;
        if(root->left){
            post_order(root->left);
            root->val = root->val + root->left->val;
        }
        if(root ->right){    
            post_order(root->right);
            root->val = root->right->val + root->val;
        }
    }
    int helper(TreeNode* root){
        if(root == nullptr || is_leaf(root)) return 0;
        int left_sum = (root->left) ? root->left->val : 0;
        int right_sum = (root->right) ? root->right->val : 0;
        return abs(left_sum-right_sum) + helper(root->left) + helper(root->right);
    }
};