class CBTInserter {
public:
    CBTInserter(TreeNode* root):root(root) {
        tree_que.push(root);
        TreeNode* cursor = tree_que.front();
        while(!isLeaf(cursor)){
            if(cursor->left) tree_que.push(cursor->left);
            if(cursor->right) tree_que.push(cursor->right);
            if(cursor->left && cursor->right) {
                tree_que.pop();
                cursor = tree_que.front();
            }
            else break;
        }
    }
    
    int insert(int v) {
        TreeNode* cursor = tree_que.front();
        TreeNode* to_add = new TreeNode(v);
        tree_que.push(to_add);

        if(isLeaf(cursor)){
            cursor->left = to_add;
        }
        else{
            cursor->right = to_add;
            tree_que.pop();
        }
        return cursor->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
private:
    queue<TreeNode*> tree_que{};
    TreeNode* root{nullptr};
    bool isLeaf(TreeNode* root){
        return root != nullptr && root->left == nullptr && root->right == nullptr;
    }
};