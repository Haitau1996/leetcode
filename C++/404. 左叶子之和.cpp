class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int result{};
        queue<TreeNode*> buffer{};
        buffer.push(root);
        while(!buffer.empty()){
            if(buffer.front() == nullptr) ; // do nothing
            else {
                if(buffer.front()->left) {
                    if(isLeaf(buffer.front()->left)) result += buffer.front()->left->val;
                    buffer.push(buffer.front()->left);
                }
                if(buffer.front() ->right){
                    buffer.push(buffer.front() -> right);
                }
            }
            buffer.pop();
        }
        return result;
    }
private:
    bool isLeaf(TreeNode* root){
        return root!= nullptr && root->left == nullptr && root->right == nullptr;
    }
};