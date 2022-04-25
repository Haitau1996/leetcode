#include <numeric>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};
class Solution {
public:
    int closestValue(TreeNode* root, double target)
    {
        int res = root->val;
        double min_diff = abs(static_cast<double>(res) - target);
        while (root != nullptr) {
            if (abs(static_cast<double>(root->val) - target) < min_diff) {
                res = root->val;
                min_diff = abs(static_cast<double>(root->val) - target);
            }
            if (static_cast<double>(root->val) > target)
                root = root->left;
            else if (static_cast<double>(root->val) < target)
                root = root->right;
            else
                break;
        }
        return res;
    }
};
