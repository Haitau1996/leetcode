/* 
    执行用时：8 ms, 在所有 C++ 提交中击败了76.83% 的用户
    内存消耗：19.4 MB, 在所有 C++ 提交中击败了41.60% 的用户
    涉及树的路径需要注意两点
    * 路径的意思是我们需要用某种数据结构将它存起来， 在这里我们用的是 vector<int>
    * 递归回到上一层后， 记得将路径清楚， 在这里对应 path.pop_back()
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<int> path{};
        pathHelper(root, target, path, 0);
        return result;
    }

private:
    vector<vector<int>> result{};
    bool isLeaf(TreeNode* root){
        return root->left == nullptr &&
                root->right == nullptr;
    }
    void pathHelper(TreeNode* root, int target, vector<int>& path, int pathSum){
        if(!root) return;
        pathSum += root->val;
        path.push_back(root->val);
        if(isLeaf(root) && pathSum == target){
            result.push_back(path);
        }
        pathHelper(root->left, target, path, pathSum);
        pathHelper(root->right, target, path, pathSum);
        path.pop_back();
    }
};