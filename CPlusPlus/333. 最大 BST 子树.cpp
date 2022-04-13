class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        if(isBST(root)) return count(root);
        else return std::max(largestBSTSubtree(root->left),largestBSTSubtree(root->right));
    }
private:
    bool isBST(TreeNode* root){
        if(root == nullptr) return true;
        if(isLeaf(root)) return true;
        if(isBST(root->left) && isBST(root->right) && 
            (root->left == nullptr || max(root->left) < root->val)&&
            (root->right == nullptr || min(root->right)> root->val))
            return true;
        return false;
    }
    int max(TreeNode* root){
        while(root->right)
            root = root->right;
        return root->val;
    }
    int min(TreeNode* root){
        while(root->left)
            root = root->left;
        return root->val;
    }
    int count(TreeNode* root){
        if(root == nullptr) return 0;
        else return 1 + count(root->left) + count(root->right);
    }
    bool isLeaf(TreeNode* root){
        return root!=nullptr && root->left == nullptr && root->right == nullptr;
    }
};
