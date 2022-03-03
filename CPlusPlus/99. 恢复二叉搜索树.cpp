class Solution {
public:
    void recoverTree(TreeNode* root) {
        inOrder(root);
        for(int i = 1; i <tree_vec.size(); ++i){
            if(tree_vec[i] < tree_vec[i-1])
                index.push_back(i);
        }
        if(index.size() == 2){
            index[0]--;
        }
        else if(index.size() == 1){
            index.push_back(index[0]-1);
        }
        fix_tree(root);
    }
private:
    vector<int> tree_vec{};
    vector<int> index{};
    void inOrder(TreeNode* root){
        if(root == nullptr) return;
        inOrder(root->left);
        tree_vec.push_back(root->val);
        inOrder(root->right);
    }
    void fix_tree(TreeNode* root){
        if(root == nullptr) return;
        fix_tree(root->left);
        if(root->val == tree_vec[index[0]]) root->val = tree_vec[index[1]];
        else if(root->val == tree_vec[index[1]]) root->val = tree_vec[index[0]];
        fix_tree(root->right);
    }
};