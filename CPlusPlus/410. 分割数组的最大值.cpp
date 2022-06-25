/*
 * 动态规划： dp[i][j] 表示 前 0..=i 中分割 j 次和的最小值, preVal[i] 表示前缀和
    * 则 dp[i][j] 为所有的 k=0..i 中最小的 max(dp[k][j-1], preVal[i]-preVal[k])
        * 特别的， 当 j = 1 的时候， dp[i][j] = preVal[i]
    * 时间复杂度 O(n^2 * m)
 * TODO: leetcode 官方的解法2 - 贪心+ 二分查找
 */
#include <vector>

using namespace std;
class Solution {
public:
	int splitArray(vector<int>& nums, int m)
	{
		vector<int> preVal {};
		int sum = 0;
		int n = nums.size();
		for (const auto& val : nums) {
			sum += val;
			preVal.push_back(sum);
		}
		vector<vector<int>> dp(n, vector<int>(m + 1, numeric_limits<int>::max()));
		for (int i = 0; i < n; ++i) {
			dp[i][1] = preVal[i];
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 2; j <= m; ++j) {
				int curr = dp[i][j];
				for (int k = 0; k < i; ++k) {
					curr = min(curr, max(dp[k][j - 1], preVal[i] - preVal[k]));
				}
				dp[i][j] = curr;
			}
		}
		return dp[n - 1][m];
	}
};
