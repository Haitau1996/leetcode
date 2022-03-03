class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> buffer;
        TreeNode* def = new TreeNode(0);
        vector<TreeNode*> one_node{def};
        vector<TreeNode*> two_node{};
        buffer.push_back(one_node);
        buffer.push_back(two_node);
        for(int i = 3; i <= n; ++i){
            vector<TreeNode*> n_nodes{};
            for(int left = 1; left < i-1; ++left){
                vector<TreeNode*>& left_trees = buffer[left-1];
                vector<TreeNode*>& right_trees = buffer[i - left-2];
                for(const auto& left_tree : left_trees){
                    for(const auto& right_tree: right_trees){
                        TreeNode* temp = new TreeNode(0);
                        temp->left = left_tree;
                        temp->right = right_tree;
                        n_nodes.push_back(temp);
                    }
                }
            }
            buffer.push_back(n_nodes);
        }
        return buffer[n-1];
    }
};