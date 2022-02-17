class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        dfs(root);
        return result;
    }
private:
    vector<int> path;
    vector<string> result;
    string pathToString(vector<int>& path){
        string result{};
        for(int i = 0; i <path.size() -1 ; ++i){
            result += to_string(path[i]);
            result += "->";
        }
        result += to_string(path[path.size()-1]);
        return result;
    }
    bool isLeaf(TreeNode* root){
        return root != nullptr &&
                root->left == nullptr &&
                root->right == nullptr;
    }
    void dfs(TreeNode* root){
        if(root == nullptr ) return;
        if(isLeaf(root)){
            path.push_back(root->val);
            result.push_back(pathToString(path));
            path.pop_back();
        }
        else{
            path.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
            path.pop_back();
        }
    }
};