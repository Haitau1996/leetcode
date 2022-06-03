#include "include/tree.hpp"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        dfs(root);
        return res;
    }

private:
    vector<int> res {};
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};
