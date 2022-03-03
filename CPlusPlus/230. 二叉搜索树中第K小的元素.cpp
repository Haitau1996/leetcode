class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // base case: the left tree has k-1 node
        int leftSize = countTree(root->left);
        if(leftSize == k-1){
            return root->val;
        }
        else if(leftSize > k-1){
            return kthSmallest(root->left, k);
        }
        else{
            return kthSmallest(root->right, k-leftSize-1);
        }
    }
private:
    int countTree(TreeNode* root){
        if(root==nullptr)
            return 0;
        else return 1 + countTree(root->left) + countTree(root->right);
    }
};