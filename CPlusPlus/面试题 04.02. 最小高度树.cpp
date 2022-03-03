class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    TreeNode* helper(vector<int>& nums, int low, int high){
        if(low > high)
            return nullptr;
        else if(low == high)
            return new TreeNode(nums[low]);
        else{
            int mid = (low + high)/2;
            TreeNode* result = new TreeNode(nums[mid]);
            result->left = helper(nums, low, mid-1);
            result->right = helper(nums, mid+1, high);
            return result;
        }
    }
};