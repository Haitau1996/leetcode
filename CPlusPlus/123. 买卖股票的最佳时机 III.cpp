// 没有优化过的 dp： 超时 
// 时间复杂度为 O(n^2)
// 202 / 214 个通过测试用例
#include<vector>
using namespace std;
class BFSolution {
public:
    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();
        vector<vector<int>> buffer(n, vector<int>(n,0));
        // buffer i, j 为 i..j 之间的最小值
        for(size_t i = 0; i < n; ++i){
            for(size_t j = i; j < n; ++j){
				if(i == j) buffer[i][j] = prices[i];
                else if(prices[j] > buffer[i][j-1]) buffer[i][j] = buffer[i][j-1];
                else buffer[i][j] = prices[j]; 
            }
        }
        vector<vector<int>> dp(n, vector<int>(n,0));
        // dp[i][j] 为分别在 i,j 卖出股票所能获得的最大利润
        for(size_t i = 0; i <n ; ++i){
            for(size_t j = i; j < n; ++j){
                if(i == j){
                    if(i == 0) dp[i][j] = 0;
                    else{
                        dp[i][j] = prices[i] - buffer[0][i-1];
                    }
                }else{
                    dp[i][j] = dp[i][i] + prices[j] - buffer[i+1][j];
                }
            }
        }
        int res = 0;
        for(size_t i = 0; i < n; ++i){
            for(size_t j = i; j < n; ++j){
                if(dp[i][j] > res)
                    res = dp[i][j];
            }
        }
        return res;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 = 0;
        for(size_t i = 1; i < n; ++i){
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1+prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};
