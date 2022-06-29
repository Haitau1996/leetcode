/*
在剑指 Offer 中做过， 但是重复写的时候发现依然容易犯一个问题， 就是数组的第 i 个元素下标是 i-1
* dp[i+1][j] 表示前 i 个字符可以写成 j , 那么 dp[i+1][j] = dp[i][j] | dp[i][j-nums[i]]
*/
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
	bool canPartition(vector<int>& nums)
	{
		auto sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum & 0x1)
			return false;
		return dpsearch(nums, sum >> 1);
	}

private:
	bool dpsearch(vector<int>& nums, int target)
	{
		int n = nums.size();
		vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
		for (int i = 0; i <= n; ++i)
			dp[i][0] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 1; j <= target; ++j) {
				dp[i + 1][j] = dp[i][j];
				if (!dp[i + 1][j] && j >= nums[i])
					dp[i + 1][j] = dp[i][j - nums[i]];
			}
		}
		return dp[n][target];
	}
};
