/* 使用动态规划， 使用 dp[i][j] 记录 [i,j] 之间的回文子序列个数 **重点在于去重**
 * case 1: s[i] == s[j]
     * sub case 1: i, j 之间没有等于 s[i] 的元素， 如 abcba, 则出现的case 包括三种，加起来就是dp[i][j] = 2 * dp[i+1][j-1] +2;
         * 原本就是回文, 如 b, bcb, bb, c
         * 原本就是回文 + 两头加入 s[i], aba, abcba 等等
         * 新元素的回文， 有两个， a 和 aa
     * sub case 2: i,j 之间有一个等于 s[i] 的元素， 这时候前两种case 和上面相同， 新的 case 就只有一个 ， aa, 因为之间有一个等的 s[i] 的元素， a已经计算过了 dp[i][j] = 2 * dp[i+1][j-1] +1;
     * sub case 3: i,j 之间有大于等于两个元素等于 s[i] , 如 ， abacbaa, 中间的 acba 部分，已经和 aa 构建过一次， 需要减去 dp[i][j] = 2 * dp[i+1][j-1] - dp[left+1][right-1];
 * case 2: s[i]!= s[j] 那么， dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
 */
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int countPalindromicSubsequences(string s)
    {
        int n = s.size();
        const int MOD = 1000000007;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int left = i + 1;
                    int right = j - 1;
                    while (left <= right && s[left] != s[i]) {
                        ++left;
                    }
                    while (left <= right && s[right] != s[i]) {
                        --right;
                    }
                    if (left > right) {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 2;
                    } else if (left == right) {
                        dp[i][j] = 2 * dp[i + 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 2 * dp[i + 1][j - 1] - dp[left + 1][right - 1];
                    }
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
                dp[i][j] = (dp[i][j] >= 0) ? dp[i][j] % MOD : dp[i][j] + MOD;
            }
        }
        return dp[0][n - 1];
    }
};
