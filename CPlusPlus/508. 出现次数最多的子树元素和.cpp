class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        dfs(root);
        return res;
    }

private:
    int curr_count { 0 };
    unordered_map<int, int> maps {};
    vector<int> res {};
    void dfs(TreeNode* root)
    {
        if (root == nullptr)
            return;
        dfs(root->left);
        dfs(root->right);
        int left = root->left == nullptr ? 0 : root->left->val;
        int right = root->right == nullptr ? 0 : root->right->val;
        root->val = root->val + left + right;
        maps[root->val]++;
        if (maps[root->val] == curr_count) {
            res.push_back(root->val);
        }
        if (maps[root->val] > curr_count) {
            res.clear();
            res.push_back(root->val);
            curr_count = maps[root->val];
        }
    }
};
