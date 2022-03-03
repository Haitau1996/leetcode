/*
执行用时：28 ms, 在所有 C++ 提交中击败了35.13% 的用户
内存消耗：31.1 MB, 在所有 C++ 提交中击败了5.03% 的用户
todo:加深对递归的理解， 去除重复冗杂的复制和判断
*/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == nullptr) return 0;
        else if(isLeaf(root)) return root->val;
        TreeNode* newTree = copyTree(root);
        updateVal(newTree);
        updateMax(root, newTree);
        findMax(root);
        return root->val;
    }
private: 
    bool isLeaf(TreeNode* root) {
        return root!=nullptr && root->left == nullptr && root->right == nullptr;
    }
    void updateVal(TreeNode* root){
        if(root == nullptr||isLeaf(root)) return;
        updateVal(root->left);
        updateVal(root->right);
        int left = root->left  ? root->left->val:0;
        int right = root->right  ? root->right->val:0;
        int max = std::max({left,right,0});
        root->val = root->val + max;
    }
    TreeNode* copyTree(TreeNode* root){
        if(root == nullptr) return nullptr;
        else {
            TreeNode* newTree = new TreeNode(root->val);
            newTree->left = copyTree(root->left);
            newTree->right = copyTree(root->right);
            return newTree;
        }
    }
    void updateMax(TreeNode* valTree, TreeNode* pathTree){
        if(valTree == nullptr || isLeaf(valTree)) return;
        int left = pathTree->left ?  pathTree->left->val:0;
        int right = pathTree->right ? pathTree->right->val:0;
        left = left < 0 ? 0 : left;
        right = right < 0 ? 0 : right;
        valTree->val = valTree->val + left + right;
        updateMax(valTree->left, pathTree->left);
        updateMax(valTree->right, pathTree->right);
    }
    void findMax(TreeNode * root){
        if(root == nullptr||isLeaf(root)) return;
        findMax(root->left);
        findMax(root->right);
        if(root->right == nullptr) {
            root->val = std::max(root->val,root->left->val);
        }
        else if(root->left == nullptr) {
            root->val = std::max(root->right->val,root->val);
        }
        else root->val = std::max({root->val, root->left->val,root->right->val});
    }
};