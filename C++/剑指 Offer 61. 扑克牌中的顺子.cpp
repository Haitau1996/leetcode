/*
执行用时：4 ms, 在所有 C++ 提交中击败了48.68% 的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了32.36% 的用户
* 本题目最重要的思路是将 zero 的数量和 gap 的数量比较， 大于等于则成立
*/
class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero_count = std::count(nums.begin(),nums.end(),0);
        int gap_count{};
        int low = zero_count;
        int high = zero_count+1;
        while(high < nums.size()){
            if(nums[low] == nums[high]) return false;
            gap_count += nums[high] - nums[low] -1;
            ++low;
            ++high;
        }
        return zero_count>=gap_count ? true : false;
    }
};