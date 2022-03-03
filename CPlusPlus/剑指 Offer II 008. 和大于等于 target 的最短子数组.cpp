/*
需要考虑几种边界的情况
* 包含最后一个元素但是已经退出了循环的
* 所有元素的和都小于 target的
*/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(std::accumulate(nums.begin(), nums.end(), 0) < target) return 0;
        int current_sum = nums[0];
        int minLen = std::numeric_limits<int>::max();
        int end = 1;
        int start = 0;
        while(end < nums.size()){
            if(current_sum < target){
                current_sum += nums[end];
                end++;
            }
            else if(current_sum >= target){
                if(end - start < minLen){
                    minLen = end-start;
                }
                current_sum-=nums[start];
                ++start;
            }
        }
        while(current_sum >= target){
            if(end-start < minLen) minLen = end-start;
            current_sum -= nums[start];
            ++start;
        }
        return minLen;
    }
};
