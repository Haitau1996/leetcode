class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelHelper(root, 1);
        vector<vector<int>> res;
        for(auto iter = resDeq.rbegin(); iter!= resDeq.rend(); ++iter)
            res.emplace_back((*iter).begin(),(*iter).end());
        return res;
    }
private:
    deque<vector<int>> resDeq{};
    void levelHelper(TreeNode* root, int level){
        if(root== nullptr)
            return;
        if(resDeq.size() < level)
            resDeq.push_back(vector<int>());
        resDeq[level-1].push_back(root->val);
        levelHelper(root->left, level+1);
        levelHelper(root->right, level+1);
    }    
};