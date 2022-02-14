class Solution {
public:
    int waysToStep(int n) {
        array<long, 3> dp{4,1,2};
        for(int i = 4; i <=n; ++i){
            dp[i%3] = (dp[i%3] + dp[(i-2)%3] + dp[(i-1)%3])%1000000007;
        }
        return dp[n%3];
    }
};