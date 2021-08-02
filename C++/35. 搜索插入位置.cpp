/*
执行用时：4 ms, 在所有 C++ 提交中击败了86.49% 的用户
内存消耗：9.5 MB, 在所有 C++ 提交中击败了12.40% 的用户
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0])
            return 0;
        else  if(target > nums[nums.size()-1])
            return nums.size();
        size_t low = 0;
        size_t high = nums.size() - 1;
        size_t mid ;
        while(high > low){
            mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return high;
    }
};