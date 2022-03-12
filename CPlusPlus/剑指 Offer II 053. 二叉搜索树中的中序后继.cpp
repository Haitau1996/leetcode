class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* cursor = root;
        TreeNode* result = nullptr;
        while(cursor!=nullptr){
            if(cursor->val > p->val){
                result = cursor;
                cursor= cursor->left;
            }else{
                cursor = cursor->right;
            }
        }
        return result;
    }
};