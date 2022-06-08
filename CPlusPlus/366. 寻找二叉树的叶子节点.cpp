#include "include/tree.hpp"
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        N = deepth(root);
        if(N == 0) return res;
        res = vector<vector<int>>(N, vector<int>());
        in_ordered(root);
        return res;
    }
private:
    vector<vector<int>> res{};
    int N{};
    int deepth(TreeNode* root){
        if(root == nullptr) return 0;
        else return 1 + max(deepth(root->left),deepth(root->right));
    }
    void in_ordered(TreeNode* root){
        if(root == nullptr) return;
        in_ordered(root->left);
        int deep = deepth(root);
        res[deep-1].push_back(root->val);
        in_ordered(root->right);
    }
};
