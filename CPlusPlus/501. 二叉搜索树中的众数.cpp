class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        print_tree(root);
        vector<int> result{};
        int len = 0;
        int i = 0; 
        int j = 0;
        while(i + j < tree_vec.size()){
            if(tree_vec[i] == tree_vec[i+j]){
                ++j;
            }else{
                if(j > len){
                    len = j;
                    result.clear();
                }
                if(j >= len) result.push_back(tree_vec[i]);
                i = i+j;
                j = 0;
            }
        }
        if(j > len){
            len = j;
            result.clear();
        }
        if(j >= len) result.push_back(tree_vec[i]);
        return result;
    }
private: 
    vector<int> tree_vec{};
    void print_tree(TreeNode* root){
        if(root == nullptr) return;
        print_tree(root->left);
        tree_vec.push_back(root->val);
        print_tree(root->right);
    }
};
