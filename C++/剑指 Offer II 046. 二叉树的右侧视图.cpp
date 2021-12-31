/*
执行用时：4 ms, 在所有 C++ 提交中击败了65.19% 的用户
内存消耗：11.6 MB, 在所有 C++ 提交中击败了80.80% 的用户
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result{};
        vector<TreeNode*> added{};
        added.push_back(root);
        int deepth = treeDeepth(root);
        while(result.size() < deepth){
            if(result.size() < added.size()){
                result.push_back(added.back()->val);
            }
            else if(!isLeaf(added.back())){
                TreeNode* next = (added.back()->right) ? added.back()->right : added.back()->left;
                added.push_back(next);
            }
            else{
                TreeNode* last_removed = nullptr;
                while(added.back()->left == nullptr || added.back()->left == last_removed){
                    last_removed = added.back();
                    added.pop_back();
                }
                added.push_back(added.back()->left);
            }
        }
        return result;
    }
private:
    int treeDeepth(TreeNode* root){
        if(root == nullptr) return 0;
        else return 1 + std::max(treeDeepth(root->left),treeDeepth(root->right));
    }
    bool isLeaf(TreeNode* root){
        return root!=nullptr && root->left == nullptr && root->right == nullptr;
    }
};