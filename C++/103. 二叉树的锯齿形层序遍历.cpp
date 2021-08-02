class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        zigHelper(root, 1);
        vector<vector<int>> res;
        for(auto temp: resDeq){
            res.push_back(vector<int>(temp.begin(),temp.end()));
        }
        return res;
    }
private:
    vector<deque<int>> resDeq{};
    void zigHelper(TreeNode* root, int level){
        // base case, root = nullptr, return 
        if(root == nullptr) return;
        if (resDeq.size() < level)
            resDeq.push_back(deque<int>());
        if(level%2)
            resDeq[level-1].push_back(root->val);
        if(level%2 ==0)
            resDeq[level-1].push_front(root->val);
        zigHelper(root->left, level+1);
        zigHelper(root->right, level+1);
        return;
    }
};