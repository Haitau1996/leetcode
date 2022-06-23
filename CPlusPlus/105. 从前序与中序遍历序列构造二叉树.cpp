#include "include/tree.hpp"
#include <vector>

using namespace std;
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		return build_in_range(preorder, 0, preorder.size(),
			inorder, 0);
	}

private:
	TreeNode* build_in_range(vector<int>& preorder, int pre_st, int len,
		vector<int>& inorder, int in_st)
	{
		if (len <= 0)
			return nullptr;
		TreeNode* ret = new TreeNode(preorder[pre_st]);
		int i = 0;
		while (i < len) {
			if (inorder[i + in_st] == preorder[pre_st]) {
				break;
			} else
				++i;
		}
		int left_len = i;
		int right_len = len - i - 1;
		ret->left = build_in_range(preorder, pre_st + 1, left_len, inorder, in_st);
		ret->right = build_in_range(preorder, pre_st + 1 + left_len, right_len, inorder, in_st + left_len + 1);
		return ret;
	}
};
