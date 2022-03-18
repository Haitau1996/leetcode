#include <numeric>
#include <vector>
/**
 * 通过分析， 因为所有的数字都是正数， 可以使用标准库函数求得所有符号都为正的和 SUM 
 * 问题可以转化为从 nums 中选出 和为 (SUM - target)/2 的组合个数， 即➹指Offer II 问题 104
*/
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        auto SUM = accumulate(nums.begin(), nums.end(),0);
        if((SUM + target) % 2 || SUM < target || SUM < -target){
            return 0;
        }
        else return helper(nums, (SUM+target) >> 1);
    }
private:
    int helper(vector<int>& nums, int target){
        vector<int> dp(target+1);
        dp[0] = 1;
        for(const auto& num : nums){
            for(int j = target; j >= num; --j){
                dp[j] += dp[j-num];
            }
        }
        return dp.back();
    }
};
