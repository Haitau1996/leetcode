class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildCore(inorder,0, inorder.size()-1, postorder, postorder.size()-1);
    }
private:
    TreeNode* buildCore(vector<int>& inorder, int begIn, int endIn,
                        vector<int>& postorder, int endPost){
        if(begIn > endIn) return nullptr;
        if(begIn == endIn)
            return new TreeNode(inorder[begIn]);
        else{
            auto rootVal = postorder[endPost];
            size_t offset{};
            while(inorder[offset+begIn] != rootVal)
                ++offset;
            auto res = new TreeNode(rootVal);
            res->left = buildCore(inorder, begIn, begIn+offset-1, postorder, endPost-1-(endIn-(begIn+offset)));
            res->right=buildCore(inorder, begIn+offset+1, endIn,postorder,endPost-1);
            return res;
        }
    }
};