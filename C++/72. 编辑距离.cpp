class Solution {
public:
    int minDistance(string word1, string word2) {
        auto dp = vector<vector<int>>(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for(int j = 0; j <= word2.size(); ++j) dp[0][j] = j;
        for(int i = 1; i <= word1.size(); ++i){
            for(int j = 1; j <= word2.size(); ++j){
                int case1 = dp[i-1][j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                int case2 = dp[i][j-1] + 1;
                int case3 = dp[i-1][j] + 1;
                dp[i][j] = min({case1,case2,case3});
            }
        }
        return dp[word1.size()][word2.size()];
    }
};