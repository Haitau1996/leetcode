// 对于树的很多问题， 可以考虑使用 hash table 存放 Node->parent 的映射关系
// 然后递归求解就方便很多， 相当于把树的问题转换成了一个图的问题
// 图的问题， 可以考虑使用 DFS 或者 BFS 来求解
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        gen_parents(root, nullptr);
        TreeNode* current = target;
        int diff = 0;
        while (current != nullptr && diff <= k) {
            bfs(target, current, k - diff);
            ++diff;
            target = current;
            current = parent[target];
        }
        return res;
    }

private:
    unordered_map<TreeNode*, TreeNode*> parent {};
    vector<int> res {};
    void gen_parents(TreeNode* curr, TreeNode* pare)
    {
        if (curr == nullptr)
            return;
        parent[curr] = pare;
        gen_parents(curr->left, curr);
        gen_parents(curr->right, curr);
    }
    void bfs(TreeNode* target, TreeNode* pare, int k)
    {
        int dist = 0;
        queue<TreeNode*> curr;
        queue<TreeNode*> next;
        curr.push(pare);
        while (!curr.empty()) {
            if (dist > k)
                break;
            auto front = curr.front();
            if (dist == k)
                res.push_back(front->val);
            if (front->left != nullptr && front->left != target) {
                next.push(front->left);
            }
            if (front->right != nullptr && front->right != target) {
                next.push(front->right);
            }
            curr.pop();
            if (curr.empty()) {
                swap(curr, next);
                ++dist;
            }
        }
    }
};
