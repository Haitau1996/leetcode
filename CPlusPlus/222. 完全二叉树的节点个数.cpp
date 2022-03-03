class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        size_t deepOfRoot = getDeepth(root);
        // base case: 两边长度相等， 是满二叉树
        size_t rightDeepth = getRDeepth(root);
        if(deepOfRoot == rightDeepth)
            return pow(2,deepOfRoot) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
private:
    size_t getDeepth(TreeNode *root){
        size_t deepth = 0;
        while(root != nullptr){
            ++deepth;
            root=root->left;
        }
        return deepth;
    }
    size_t getRDeepth(TreeNode *root){
        size_t deepth = 0;
        while(root != nullptr){
            ++deepth;
            root = root->right;
        }
        return deepth;
    }
};