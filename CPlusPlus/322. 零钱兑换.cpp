// 动态规划， dp[i] 记录i需要的对数
#include <vector>

using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount)
	{
		vector<int> dp(amount + 1, -1);
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			int curr = numeric_limits<int>::max();
			for (const auto& c : coins) {
				if (c <= i && dp[i - c] != -1) {
					curr = min(curr, dp[i - c] + 1);
				}
			}
			if (curr != numeric_limits<int>::max()) {
				dp[i] = curr;
			}
		}
		return dp[amount];
	}
};
