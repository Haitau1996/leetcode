class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build_in_range(preorder, 0, preorder.size()-1);
    }
private:
    TreeNode* build_in_range(vector<int>& preorder, int low, int high){
        if(low > high) return nullptr;
        int root_val = preorder[low];
        int right_start = low+1;
        while(right_start <= high){
            if(preorder[right_start] > root_val) break;
            else ++right_start;
        }
        TreeNode* root = new TreeNode(root_val);
        root->left = build_in_range(preorder,low+1, right_start-1);
        root->right = build_in_range(preorder, right_start, high);
        return root;
    }
};