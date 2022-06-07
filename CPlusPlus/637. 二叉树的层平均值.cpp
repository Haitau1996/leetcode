// 简单的 BFS
#include "include/tree.hpp"
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> res {};
        int cnt {};
        double sum {};
        queue<TreeNode*> curr {};
        queue<TreeNode*> next {};
        if (root)
            curr.push(root);
        while (!curr.empty()) {
            auto front = curr.front();
            ++cnt;
            sum += front->val;
            if (front->left)
                next.push(front->left);
            if (front->right)
                next.push(front->right);
            curr.pop();
            if (curr.empty()) {
                res.push_back(sum / cnt);
                cnt = 0;
                sum = 0.0;
                swap(curr, next);
            }
        }
        return res;
    }
};
