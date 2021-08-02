class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return ;
        else{
            flatten(root->left);
            flatten(root->right);
            TreeNode* temp = root->right;
            root->right = root->left;
            root->left = nullptr;
            while(root->right != nullptr)
                root = root->right;
            root->right = temp;
        }
    }
};