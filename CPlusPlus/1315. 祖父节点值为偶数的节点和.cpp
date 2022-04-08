class Solution {
public:
    int sumEvenGrandparent(TreeNode* root) {
        int result{};
        queue<TreeNode*> to_check{};
        if(root != nullptr) to_check.push(root);
        while(!to_check.empty()){
            auto front= to_check.front();
            to_check.pop();
            if(front->val % 2 == 0) result+=check_grandson(front);
            if(front->left) to_check.push(front->left);
            if(front->right) to_check.push(front->right);
        }
        return result;
    }
private:
    int check_grandson(TreeNode* root){
        int val = 0;
        if(root->left){
            if(root->left->left)
                val += root->left->left->val;
            if(root->left->right)
                val += root->left->right->val;
        }
        if(root->right){
            if(root->right->left) val += root->right->left->val;
            if(root->right->right) val+= root->right->right->val;
        }
        return val;
    }
};
