class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        inOrderPrint(root);
        auto i = std::begin(temp);
        while(i!= std::end(temp)-1){
            if(*i == p)
                return *(++i);
            ++i;
        }
        return NULL;
    }
private:
    vector<TreeNode*> temp;
    void inOrderPrint(TreeNode* root){
        if(root == NULL)
            return;
        else {
            inOrderPrint(root->left);
            temp.push_back(root);
            inOrderPrint(root->right);
        }
    }
};