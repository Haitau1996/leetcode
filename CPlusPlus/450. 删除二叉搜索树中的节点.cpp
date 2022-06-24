// DFS思路： 找到该节点， 如果左子树为空， 直接返回右子树， 否则将右子树挂到左子树的最右边， 返回左子树
#include "include/tree.hpp"

class Solution {
public:
	TreeNode* deleteNode(TreeNode* root, int key)
	{
		if (root == nullptr)
			return root;
		if (root->val == key) {
			if (root->left == nullptr)
				return root->right;
			else {
				TreeNode* ret = root->left;
				TreeNode* cursor = ret;
				while (cursor->right) {
					cursor = cursor->right;
				}
				cursor->right = root->right;
				return ret;
			}
		} else if (root->val > key) {
			root->left = deleteNode(root->left, key);
		} else {
			root->right = deleteNode(root->right, key);
		}
		return root;
	}
};
