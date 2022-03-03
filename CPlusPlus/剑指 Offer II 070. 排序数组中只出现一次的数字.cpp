/*
* 需要特别考虑 low == high 的情况
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        return helper(nums,0,nums.size() -1);
    }
private:
    int helper(vector<int>&nums, int low, int high){
        if(low == high) return nums[low];
        int mid = (low + high)/2;
        if(nums[mid] < nums[mid+1] && (mid == 0 || nums[mid]>nums[mid-1])) return nums[mid];
        if((mid - low)%2==0 && nums[mid] == nums[mid-1]) return helper(nums,low, mid-2);
        else if((mid - low)%2==0 && nums[mid] == nums[mid+1]) return helper(nums, mid+2, high);
        else if(nums[mid] == nums[mid-1]) return helper(nums, mid+1, high);
        else return helper(nums,low,mid-1);
    }
};