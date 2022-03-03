class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return constructInRange(preorder,0, preorder.size()-1, postorder,0,postorder.size()-1);
    }
private:
    TreeNode* constructInRange(vector<int>& preorder, int pre_low, int pre_high,
                               vector<int>& postorder, int post_low, int post_high){
        if(pre_low > pre_high) return nullptr;
        else if(pre_low == pre_high) return new TreeNode(preorder[pre_low]);
        TreeNode* result = new TreeNode(preorder[pre_low]);
        auto next = postorder[post_high-1];
        int i = 1;
        for(; i <= (pre_high - pre_low); ++i){
            if(preorder[pre_low+i] == next) break;
        }
        result->left = constructInRange(preorder, pre_low+1, pre_low+i-1, postorder, post_low, post_low + i -2);
        result->right = constructInRange(preorder, pre_low+i, pre_high, postorder, post_low + i -1, post_high-1);
        return result;
    }
};