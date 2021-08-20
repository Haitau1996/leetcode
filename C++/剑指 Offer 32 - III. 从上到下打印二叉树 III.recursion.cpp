class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        print(root,0);
        for(const auto& i:res){
            result.push_back(vector<int>(i.begin(),i.end()));
        }
        return result;
    }
private:
    vector<deque<int>> res;
    void print(TreeNode* root, int level){
        if(root == NULL)
            return;
        if(res.size() == level)
            res.push_back(deque<int>());
        if(level%2 == 0)res[level].push_back(root->val);
        else res[level].push_front(root->val);
        print(root->left,level+1);
        print(root->right,level+1);
    }
};