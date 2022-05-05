#include <vector>

using namespace std;
class Solution {
public:
    int numWays(int n, int k) {
        vector<vector<int>> dp(2, vector<int>(2,0));
        dp[0][0] = 0;
        dp[1][0] = k;
        for(int i = 1; i < n; ++i){
            dp[0][i%2] = dp[1][(i-1)%2];
            dp[1][i%2] = (dp[1][(i-1)%2]+dp[0][(i-1)%2]) * (k-1);
        }
        return dp[0][(n-1)%2]+dp[1][(n-1)%2];
    }
};
