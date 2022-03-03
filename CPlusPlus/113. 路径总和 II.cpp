/*
执行用时：16 ms, 在所有 C++ 提交中击败了38.43% 的用户
内存消耗：34.3 MB, 在所有 C++ 提交中击败了16.88% 的用户
*/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return vector<vector<int>>();
        vector<vector<int>> res = sumHelper(root,targetSum);
        for(auto& item: res)
            std::reverse(item.begin(),item.end());
        return res;
    }
private:
    vector<vector<int>> sumHelper(TreeNode* root, int targetSum){
        // base case:
        if(isLeaf(root) && root->val == targetSum)
            return vector<vector<int>>{{root->val}};
        else if(isLeaf(root)&&root->val!=targetSum)
            return vector<vector<int>>{};
        else{
            vector<vector<int>> res;
            if(root->left != nullptr){
                auto leftRes = sumHelper(root->left,targetSum-root->val);
                if(leftRes.size()!=0 && leftRes[0].size()!=0){
                    for(auto& item : leftRes){
                        item.push_back(root->val);
                    }
                    for(auto item :leftRes){
                        res.push_back(item);
                    }
                }
            }
            if(root->right != nullptr){
                auto rightRes = sumHelper(root->right, targetSum-root->val);
                if(rightRes.size()!=0&& rightRes[0].size() != 0){
                    for(auto& item: rightRes){
                        item.push_back(root->val);
                    }
                    for(auto item:rightRes)
                        res.push_back(item);
                }
            }
            return res;
        }
    }
    bool isLeaf(TreeNode* root){
        return  root        != nullptr &&
                root->left  == nullptr &&
                root->right == nullptr;
    }
};