/* 这道题难点是在于区分不同的状态， 需要分三个状态
 * dp[i][0] 在 i 时刻持有股票的最大收益
 * dp[i][1] 在 i 时刻不持有股票但是处于冷冻期的最大收益
 * dp[i][2] 在 i 时刻不持有股票且不处于冷冻期的最大收益 */

#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp.back()[1], dp.back()[2]);
    }
};
