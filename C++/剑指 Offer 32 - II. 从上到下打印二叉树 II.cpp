/*
执行用时：4 ms, 在所有 C++ 提交中击败了80.06% 的用户
内存消耗：13.3 MB, 在所有 C++ 提交中击败了5.00% 的用户
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        print(root,0);
        return res;
    }
private:
    vector<vector<int>> res;
    void print(TreeNode* root, int level){
        if(root == NULL)
            return;
        if(res.size() == level)
            res.push_back(vector<int>());
        res[level].push_back(root->val);
        print(root->left,level+1);
        print(root->right,level+1);
    }
};