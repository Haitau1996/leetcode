// dp[i][0] 表示 i 时候持有股票时候的最大收益
// dp[i][1] 表示 i 时候不持有股票时候的最大收益
#include <vector>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices)
	{
		int n = prices.size();
		int dp[n][2];
		memset(dp, 0, sizeof(dp));
		dp[0][0] = -prices[0];
		for (int i = 1; i < n; ++i) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
		}
		return dp[n - 1][1];
	}
};
