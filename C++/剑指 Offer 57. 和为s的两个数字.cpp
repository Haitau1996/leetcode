// 简单的双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t i = 0;
        size_t j = nums.size()-1;
        while(i < j){
            if(nums[i] + nums[j] == target) break;
            else if(nums[i] + nums[j] > target) --j;
            else ++i;
        }
        return vector<int>{nums[i],nums[j]};
    }
};