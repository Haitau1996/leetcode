// 使用 dp[i][j] 存放以 i,j 结尾的数据， 然后对于任意 i,j 搜索 k
// 因为数组是严格递增的，可以使用二分查找降低找到 k 的复杂度(从 n^3 降低到 n^2 log n)
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
	int lenLongestFibSubseq(vector<int>& arr)
	{
		int n = arr.size();
		vector<vector<int>> dp(n, vector<int>(n, 0));
		int res { 0 };
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				auto pos = lower_bound(arr.begin(), arr.end(), arr[j] - arr[i]) - arr.begin();
				if (pos < i && arr[pos] == arr[j] - arr[i])
					dp[i][j] = dp[pos][i] + 1;
				else
					dp[i][j] = 2;
				res = max(dp[i][j], res);
			}
		}
		return res > 2 ? res : 0;
	}
};
