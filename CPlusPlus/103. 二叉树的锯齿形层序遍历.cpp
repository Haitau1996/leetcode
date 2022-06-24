// BFS: 可以使用双端队列根据需要 push 在开头和结尾， 这里使用 vector,然后对奇数的行做 reverse
#include "include/tree.hpp"
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res{};
        queue<TreeNode*> que;
        if(root){
            que.push(root);
            res.push_back(vector<int>{});
        }
        while(!que.empty()){
            auto sz = que.size();
            for(int i = 0; i < sz; ++i){
                auto front = que.front();
                res.back().push_back(front->val);
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
                que.pop();
            }
            if(!que.empty()){
                res.push_back(vector<int>{});
            }
        }
        for(int i = 1;  i<res.size(); i+=2){
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
