/*
在剑指 Offer 中做过， 但是重复写的时候发现依然容易犯一个问题， 就是数组的第 i 个元素下标是 i-1
*/
#include<numeric>
#include<vector>

using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 0x1) return false;
        else{
            auto target = sum >> 1;
            dp = vector<vector<int>>(nums.size()+1, vector<int>(target+1,-1));
            return getSumFrom(nums, nums.size(), target);
        }
    }
private:
    vector<vector<int>> dp;
    int getSumFrom(vector<int>& nums, int index, int target){
        if(dp[index][target] == -1){
            if(target == 0) dp[index][target] = 1;
            else if(index == 0) dp[index][target] = 0;
            else{
                dp[index][target] = getSumFrom(nums, index-1, target);
                if(dp[index][target] == 0 && target >= nums[index-1]){
                    dp[index][target] = getSumFrom(nums,index-1, target - nums[index-1]);
                }
            }
        }
        return dp[index][target];
    }
};
