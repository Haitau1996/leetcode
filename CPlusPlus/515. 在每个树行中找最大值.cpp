#include "include/tree.hpp"
#include <limits>
#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root)
    {
        queue<TreeNode*> curr;
        queue<TreeNode*> next;
        if (root != nullptr)
            curr.push(root);
        vector<int> res {};
        int val = numeric_limits<int>::min();
        while (!curr.empty()) {
            while (!curr.empty()) {
                auto front = curr.front();
                curr.pop();
                if (val < front->val)
                    val = front->val;
                if (front->left)
                    next.push(front->left);
                if (front->right)
                    next.push(front->right);
            }
            res.push_back(val);
            swap(curr, next);
            val = numeric_limits<int>::min();
        }
        return res;
    }
};
