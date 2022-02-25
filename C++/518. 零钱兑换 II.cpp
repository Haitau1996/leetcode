class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int>dp(amount+1,0);
        dp[0] = 1;
        for(const auto& elem:coins){
            for(int i = elem; i <= amount; ++i){
                    dp[i] += dp[i-elem];
            }
        }
        return dp.back();
    }
};