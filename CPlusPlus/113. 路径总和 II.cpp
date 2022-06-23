/* 
 * 回溯， 记录当下路径， 符合条件则添加， 记得处理完毕后将节点的值从 curr 删除
 */
#include "include/tree.hpp"
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
private:
    bool is_leaf(TreeNode* root){
        return root != nullptr &&
                root->left == nullptr &&
                root->right == nullptr;
    }
    vector<vector<int>> res{};
    vector<int> curr{};
    void dfs(TreeNode* root, int sum){
        if(root == nullptr) return;
        if(is_leaf(root) && root->val == sum){
            curr.push_back(root->val);
            res.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(root->val);
        dfs(root->left, sum-root->val);
        dfs(root->right, sum - root->val);
        curr.pop_back();
    }
};
