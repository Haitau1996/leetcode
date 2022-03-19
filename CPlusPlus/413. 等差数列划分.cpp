/* 
 * 没什么特别的， 就是使用一个数组 dp 缓存，dp[i]表示以 nums[i] 结尾最长的的等差数列大小
*/
#include <vector>
#include <numeric>

using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for(int i = 0; i < static_cast<int>(nums.size()); ++i){
            if(i == 0) dp[i] = 1;
            else if(i == 1 || nums[i] - nums[i-1] != nums[i-1] - nums[i-2]) dp[i] = 2;
            else dp[i] = dp[i-1] + 1;
        }
        int result = 0;
        for(const auto& elem : dp){
            result += max(0, elem-2);
        }
        return result;
    }
};
