class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        auto result = two_Node(root);
        return result.first;
    }
private:
    bool isLeaf(TreeNode* root){
        return root != nullptr && root->left == nullptr && root->right == nullptr;
    }
    std::pair<TreeNode*, TreeNode*> two_Node(TreeNode* root){
        if(root == nullptr) return std::make_pair(nullptr, nullptr);
        else if(isLeaf(root)) return std::make_pair(root, root);
        else if(root -> left == nullptr){
            auto right_pair = two_Node(root->right);
            root->right = right_pair.first;
            return std::make_pair(root, right_pair.second);
        }
        else if(root ->right == nullptr){
            auto left_pair = two_Node(root->left);
            root ->left = nullptr;
            left_pair.second->right = root;
            return std::make_pair(left_pair.first, root);
        }
        else{
            auto left_pair = two_Node(root->left);
            auto right_pair = two_Node(root->right);
            root->left = nullptr;
            root->right = right_pair.first;
            left_pair.second->right = root;
            return make_pair(left_pair.first, right_pair.second);
        }
    }
};