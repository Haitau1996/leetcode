class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return (TreeNode*)nullptr;
        else return builderHelper(nums, 0, nums.size()-1);
    }
private:
    TreeNode* builderHelper(vector<int>& nums, size_t low, size_t high){
        // base case: high = low
        if(high < low)
            return nullptr;
        else if(high == low)
            return new TreeNode(nums[low]);
        else if(high -low == 1){
            TreeNode* res = new TreeNode(nums[low]);
            res->right = new TreeNode(nums[high]);
            return res;
        }
        else{
            size_t mid = (high + low)/2;
            TreeNode* res = new TreeNode(nums[mid]);
            res->left = builderHelper(nums, low, mid-1);
            res->right = builderHelper(nums, mid+1, high);
            return res;
        }
    }
};