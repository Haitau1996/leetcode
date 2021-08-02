class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // base case 
        if(root == nullptr)
            return true;
        return SymmerticHelper(root->left, root->right);
        
    }
private:
    bool SymmerticHelper(TreeNode* root1, TreeNode* root2){
        if(root1== nullptr && root2==nullptr)
            return true;
        else if(root1 == nullptr || root2 == nullptr)
            return false; 
        else if(root1->val != root2->val)
            return false;
        else
            return SymmerticHelper(root1->left, root2->right)
                    && SymmerticHelper(root1->right, root2->left);
    }
};