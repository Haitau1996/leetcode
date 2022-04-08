class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, long long>> curr;
        queue<pair<TreeNode*, long long>> todo;
        curr.push(pair(root,1LL));
        long long  result = 1;
        while(!curr.empty()){
            long long left = -1;
            long long right = 0;
            while(!curr.empty()){
                auto front = curr.front();
                curr.pop();
                auto first = front.first;
                auto second = front.second;
                if(left == -1) left = second;
                if(second > right) right = second;
                if(first->left) todo.push(pair(first->left, second*2%numeric_limits<unsigned>::max()));
                if(first->right) todo.push(pair(first->right, (second*2+1)%numeric_limits<unsigned>::max()));
            }
            if(right - left +1  > result) result = right-left+1;
            swap(curr, todo);
        }
        return result;
    }
};
