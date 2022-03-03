class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(2, vector<int>(3,0));
        for(int i = 0; i < costs.size(); ++i){
            for(int j = 0; j < 3; ++j){
                dp[i%2][j] = costs[i][j] + min(dp[(i+1)%2][(j+1)%3],dp[(i+1)%2][(j+2)%3]);
            }
        }
        return *min_element(dp[(costs.size() -1)%2].begin(),dp[(costs.size() -1)%2].end());
    }
};