/*
 * 使用一个 pair<int, int> 存放状态， first 为不包含当下节点的最大值， second 为不管是否包含当下节点的最大值
 */
#include "include/tree.hpp"
#include <utility>
using namespace std;
class Solution {
	using mp = pair<int, int>;

public:
	int rob(TreeNode* root)
	{
		auto res = dfs(root);
		return res.second;
	}

private:
	mp dfs(TreeNode* root)
	{
		if (root == nullptr) {
			return mp(0, 0);
		}
		auto l = dfs(root->left);
		auto r = dfs(root->right);
		int fir = l.second + r.second;
		int sec = max(fir, l.first + r.first + root->val);
		return mp(fir, sec);
	}
};
