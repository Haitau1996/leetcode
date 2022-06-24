#include "include/tree.hpp"
#include <limits>
#include <vector>

using namespace std;
class Solution {
public:
	int minCameraCover(TreeNode* root)
	{
		auto res = dfs(root);
		return res[1];
	}
	vector<int> dfs(TreeNode* root)
	{
		vector<int> res(3, 0);
		if (root == nullptr) {
			res[0] = numeric_limits<int>::max() >> 1;
		} else {
			auto vecl = dfs(root->left);
			auto vecr = dfs(root->right);
			res[0] = 1 + vecl[2] + vecr[2];
			res[1] = min({ res[0], vecl[0] + vecr[1], vecl[1] + vecr[0] });
			res[2] = min(res[0], vecl[1] + vecr[1]);
		}
		return res;
	}
};
