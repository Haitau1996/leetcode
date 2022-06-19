/* 动态规划， dp[i][j] 表示 i*j 木头售价的最大值， 只能横着切或者竖着切
 * 横着切： dp[i][j] = max({dp[i][j], dp[k][j]+dp[i-k][j]});
 * 竖着切： dp[i][j] = max({dp[i][j], dp[i][k]+dp[i][j-k]});
 */

#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices)
    {
        vector<vector<int>> map(m + 1, vector<int>(n + 1));
        for (const auto& p : prices) {
            if (p[0] <= m && p[1] <= n)
                map[p[0]][p[1]] = p[2];
        }
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = map[i][j];
                for (int k = 1; k < i; ++k) {
                    dp[i][j] = max( dp[i][j], dp[k][j] + dp[i - k][j] );
                }
                for (int k = 1; k < j; ++k) {
                    dp[i][j] = max( dp[i][j], dp[i][k] + dp[i][j - k] );
                }
            }
        return dp[m][n];
    }
};
