class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root== nullptr) return vector<vector<int>>{};
        int left = get_left(root);
        int right = get_right(root);
        vector<vector<int>> result(left+right+1,vector<int>());
        levelorder_print(root, left, result);
        return result;
    }
private:
    void levelorder_print(TreeNode* root, int cursor, vector<vector<int>>& result){
        queue<pair<TreeNode*, int>> todo;
        todo.push(pair(root,cursor));
        while(!todo.empty()){
            auto front= todo.front();
            todo.pop();
            auto first = front.first;
            auto second = front.second;
            result[second].push_back(first->val);
            if(first->left) todo.push(pair(first->left, second-1));
            if(first->right) todo.push(pair(first->right, second+1));
        }
    }
    int get_left(TreeNode* root){
        int left = 0;
        queue<pair<TreeNode*, int>> todo;
        todo.push(pair(root,0));
        while(!todo.empty()){
            auto front = todo.front();
            todo.pop();
            auto first = front.first;
            auto second = front.second;
            if(second > left) left = second;
            if(first->left) todo.push(pair(first->left, second+1));
            if(first->right) todo.push(pair(first->right, second-1));
        }
        return left;
    }
    int get_right(TreeNode* root){
        int right = 0;
        queue<pair<TreeNode*, int>> todo;
        todo.push(pair(root,0));
        while(!todo.empty()){
            auto front = todo.front();
            todo.pop();
            auto first = front.first;
            auto second = front.second;
            if(second > right) right = second;
            if(first->left) todo.push(pair(first->left, second-1));
            if(first->right) todo.push(pair(first->right, second+1));
        }
        return right;
    }

};
