/*
**再次强调三元运算符整个都要用括号包起来， 不然如果 dp[i-1][j-1] >0 , 再加一个 bool 表达式转换过来的 int, 结果一定为 true**
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1,numeric_limits<int>::max()));
        for(int j = 0; j <= word2.size(); ++j) dp[0][j] = j;
        for(int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for(int i = 1; i <= word1.size(); ++i){
            for(int j = 1; j <= word2.size(); ++j){
                int case1 = dp[i-1][j-1] + ((word1[i-1] == word2[j-1]) ? 0 : 2);
                int case2 = dp[i-1][j] + 1;
                int case3 = dp[i][j-1] + 1;
                dp[i][j] = min({case1,case2,case3}); 
            }
        }
        return dp.back().back();
    }
};