class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructInRange(nums,0,nums.size()-1);
    }
private:
    TreeNode* constructInRange(vector<int>& nums, int low, int high){
        if(low > high) return nullptr;
        int max_element = nums[low];
        int max_index = low;
        for(int i = low; i <= high; ++i){
            if(nums[i] > max_element){
                max_element = nums[i];
                max_index = i;
            }
        }
        TreeNode* result = new TreeNode(max_element);
        result->left = constructInRange(nums, low, max_index-1);
        result->right = constructInRange(nums, max_index+1, high);
        return result;
    }
};