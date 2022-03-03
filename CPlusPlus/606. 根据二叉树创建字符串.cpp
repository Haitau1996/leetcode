class Solution {
public:
    string tree2str(TreeNode* root) {
        string result{};
        if(root != nullptr){
            result += to_string(root->val);
        }
        if(root->left){
            result+= "(";
            result += tree2str(root->left);
            result += ")";
        }
        else if(root->left == nullptr && root->right!= nullptr){
            result += "()";
        }
        if(root->right){
            result+="(";
            result += tree2str(root->right);
            result+=")";
        }
        return result;
    }
};