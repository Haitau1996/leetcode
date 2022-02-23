/*
非递归： 使用一个 stack 辅助实现
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result{};
        stack<Node*> stk;
        if(root != nullptr){
            stk.push(root);
        }
        while(!stk.empty()){
            Node* cursor = stk.top();
            result.push_back(cursor->val);
            stk.pop();
            auto cursor_children = cursor->children;
            for(int i = cursor_children.size()-1; i >=0; --i){
                if(cursor_children[i]) stk.push(cursor_children[i]);
            }
        }
        return result;
    }
};