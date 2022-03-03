class Solution {
public:
    bool isValidBST(TreeNode* root);
private:
    int Tmax(TreeNode* root);
    int Tmin(TreeNode* root);
};
bool Solution::isValidBST(TreeNode* root){
    // base case: the root is nullptr, then  it's a BST
    if(root == nullptr) return true;
    else if((!isValidBST(root->left)) || (!isValidBST(root->right)))
        return false;
    else if((root->left == nullptr  
                || Tmax(root->left)< root->val)
            &&(root->right==nullptr || (Tmin(root->right) > root->val)))
        return true;
    else return false;
}
int Solution::Tmax(TreeNode* root){
    while(root -> right != nullptr)
        root=root->right;
    return root->val;
}
int Solution::Tmin(TreeNode* root){
    while(root->left != nullptr)
        root= root->left;
    return root->val;
}