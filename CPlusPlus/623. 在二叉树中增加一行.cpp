// 简单的 BFS

class BFS_Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        if (depth == 1) {
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        int curr_deepth = 1;
        queue<TreeNode*> curr {};
        queue<TreeNode*> next {};
        curr.push(root);
        while (!curr.empty() && curr_deepth < depth) {
            auto front = curr.front();
            if (curr_deepth == depth - 1) {
                auto left = front->left;
                auto right = front->right;
                front->left = new TreeNode(val);
                front->right = new TreeNode(val);
                front->left->left = left;
                front->right->right = right;
            } else {
                if (front->left)
                    next.push(front->left);
                if (front->right)
                    next.push(front->right);
            }
            curr.pop();
            if (curr.empty()) {
                ++curr_deepth;
                swap(curr, next);
            }
        }
        return root;
    }
};
