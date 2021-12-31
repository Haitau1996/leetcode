/*
用时99% 的用户
内存6% 的用户
*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        pushToVerc(root, 0);
        vector<int> to_return{};
        for(const auto& elem : result){
            to_return.push_back(*max_element(elem.begin(),elem.end()));
        }
        return to_return;
    }
private:
    vector<vector<int>> result{};
    void pushToVerc(TreeNode* root, int deepth){
        if(root == nullptr) return;
        if(result.size() == deepth) result.push_back(vector<int>());
        result[deepth].push_back(root->val);
        pushToVerc(root->left, deepth+1);
        pushToVerc(root->right, deepth+1);
    }
};
/**
 执行用时：16 ms, 在所有 C++ 提交中击败了35.01% 的用户
内存消耗：21.5 MB, 在所有 C++ 提交中击败了89.32% 的用户
*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        pushToVerc(root, 0);
        return result;
    }
private:
    vector<int> result{};
    void pushToVerc(TreeNode* root, int deepth){
        if(root == nullptr) return;
        if(result.size() == deepth) 
            result.push_back(root->val);
        else if(root->val > result[deepth]) result[deepth] = root->val;
        pushToVerc(root->left, deepth+1);
        pushToVerc(root->right, deepth+1);
    }
};