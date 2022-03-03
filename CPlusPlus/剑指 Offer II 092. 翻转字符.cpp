class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(2, vector<int>(2,0));
        dp[0][0] = (s[0] == '0') ? 0 : 1;
        dp[0][1] = (s[0] == '1') ? 0 : 1;
        for(int i = 1; i < s.size(); ++i){
            dp[i%2][0] = dp[(i+1)%2][0] + ((s[i] == '0')? 0 : 1);
            dp[i%2][1] = min(dp[(i+1)%2][0], dp[(i+1)%2][1]) + ((s[i] == '1')? 0 : 1);
        }
        return min(dp[(s.size()-1)%2][0],dp[(s.size()-1)%2][1]);
    }
};