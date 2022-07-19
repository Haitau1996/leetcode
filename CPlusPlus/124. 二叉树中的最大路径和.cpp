/*
 * 动态规划， 某个节点， 其左边节点包含左子树根的最大单链和为 left, 右边为 right
 * 取 left 和 0 的较大值， right 和 0 的较大值，加上 root->val 就是以它为转折点的最大路径和
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        res = numeric_limits<int>::min();
        dfs(root);
        return res;
    }
private:
    int res;
    int dfs(TreeNode* root){
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int curr = left + right+ root->val;
        int path = root->val + max(left, right);
        res = max(res, curr);
        return path < 0 ? 0 : path;
    }
};