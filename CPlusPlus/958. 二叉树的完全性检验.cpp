class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool null_tree_flag = false;
        queue<TreeNode*> node_to_handle{};
        node_to_handle.push(root);
        while(!node_to_handle.empty()){
            auto to_pop = node_to_handle.front();
            if(null_tree_flag && !(is_leaf(to_pop))){
                return false;
            }
            if(to_pop->left == nullptr) null_tree_flag = true;
            else{
                node_to_handle.push(to_pop->left);
            }
            if(null_tree_flag && to_pop->right){
                return false;
            }else if(to_pop->right == nullptr){
                null_tree_flag = true;
            }else{
                node_to_handle.push(to_pop->right);
            }
            node_to_handle.pop();
        }
        return true;
    }
private:
    
    bool is_leaf(TreeNode* node_to_test){
        return  node_to_test != nullptr &&
                node_to_test->left == nullptr &&
                node_to_test->right == nullptr;
    }
};