class Solution {
public:
    bool isValidBST(TreeNode* root) {
        inOrderPrint(root);
        if(inOrder.size()< 2)
            return true;
        int i = 0;
        while(i <= inOrder.size()-2){
            if(inOrder[i+1]<= inOrder[i])
                return false;
            else ++i;
        }
        return true;
    }
private:
    vector<int> inOrder;
    void inOrderPrint(TreeNode* root){
        if(root == NULL) return;
        else{
            inOrderPrint(root->left);
            inOrder.push_back(root->val);
            inOrderPrint(root->right);
        }
        return;
    }
};