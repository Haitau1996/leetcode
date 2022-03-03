class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return find_in_range(nums, 0, nums.size()-1, target);
    }
private:
    int find_in_range(vector<int>&nums, int beg, int end, int target){
        if(beg == end){
            if(nums[beg]== 0 && target==0) return 2;
            if(nums[beg] == target) return 1;
            else if(-nums[beg] ==target) return 1;
            else return 0;
        }
        return find_in_range(nums, beg, end-1, target + nums[end]) + find_in_range(nums, beg, end-1, target - nums[end]);
    }
};