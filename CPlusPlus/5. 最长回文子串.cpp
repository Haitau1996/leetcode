// 做法 1： 中心开花， 看最长的回文
// 做法 2： 动态规划， dp[i][j] 表示 s[i..j] 的回文长度， 0 则不回文， j-i+1 则为回文长度

#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s)
    {
        int res_len { 1 };
        string res { s.substr(0, 1) };
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2)
                        dp[i][j] = 2;
                    else if (dp[i + 1][j - 1] > 0)
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    if (dp[i][j] > res_len) {
                        res_len = dp[i][j];
                        res = s.substr(i, len);
                    }
                }
            }
        }
        return res;
    }
};
