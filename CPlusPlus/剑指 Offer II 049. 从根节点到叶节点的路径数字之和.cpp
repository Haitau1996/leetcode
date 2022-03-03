class Solution {
public:
    int sumNumbers(TreeNode* root) {
        sumHelper(root,0);
        return sum;
    }
private:
    int sum = 0;
    bool isLeaf(TreeNode* root){
        return root!=nullptr && root->left == nullptr && root->right == nullptr;
    }
    void sumHelper(TreeNode* root, int pathSum){
        if(root == nullptr) return;
        if(isLeaf(root)) sum = sum + pathSum*10 + root->val;
        else{
            sumHelper(root->left, pathSum*10 + root->val);
            sumHelper(root->right, pathSum*10 + root->val);
        }
    }
};