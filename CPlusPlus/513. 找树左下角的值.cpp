class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> curr_que{};
        queue<TreeNode*> next_que{};
        int temp;
        curr_que.push(root);
        while(!curr_que.empty()){
            temp = curr_que.front()->val;
            while(!curr_que.empty()){
                auto front = curr_que.front();
                curr_que.pop();
                if(front->left) next_que.push(front->left);
                if(front->right) next_que.push(front->right);
            }
            swap(curr_que, next_que);
        }
        return temp;
    }
};
