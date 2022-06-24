/*
 * 在不使用迭代器的情况下， 递归既可以做中序遍历
 * 而递归相当于是使用一个栈做迭代，我们这里就可以使用栈模拟
 * 先将所有的左子树入栈
 * 选择栈顶元素弹出， 如果它有右子树， 则将右子树中做类似处理， 将根节点和左子树入栈
 */
#include "include/tree.hpp"
#include <stack>

class BSTIterator {
public:
	BSTIterator(TreeNode* root)
	{
		while (root) {
			stk.push(root);
			root = root->left;
		}
	}

	int next()
	{
		auto front = stk.top();
		stk.pop();
		TreeNode* right = front->right;
		while (right) {
			stk.push(right);
			right = right->left;
		}
		return front->val;
	}

	bool hasNext()
	{
		return !stk.empty();
	}

private:
	std::stack<TreeNode*> stk;
};
