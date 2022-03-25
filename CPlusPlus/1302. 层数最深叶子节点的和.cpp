class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> curr_que{};
        queue<TreeNode*> next_que{};
        curr_que.push(root);
        int result=0;
        while(!curr_que.empty()){
            while(!curr_que.empty()){
                auto front = curr_que.front();
                curr_que.pop();
                result += front->val;
                if(front->left) next_que.push(front->left);
                if(front->right) next_que.push(front->right);
            }
            if(!next_que.empty()){
                swap(curr_que,next_que);
                result = 0;
            }
        }
        return result;
    }
};
