/* 动态规划求解
 * dp[i][j] 表示戳破 (i,j) 之间的气球获得的收益， 不包括 i,j
 * j-i <= 1 的时候， 中间没有任何气球， 收益是 0
 * j-i > 1 的时候， 遍历中间的 k, 取最大的 dp[i][k]+dp[k][j]+ val[i]*val[k]*val[j]
    * 需要特别注意， 求 dp[i][j] 时候需要用到 dp[k][j] 和 dp[i][k] 的数据， 所以对求值的顺序有限制
    * dp[i][k](k < j) 的数据已经知道， 说明对于同一个i, j的值是顺序的
    * dp[k][j](k > i) 的数据已知， 说明对于同一个 j, i 的求值顺序是逆序的
    */
#include <vector>

using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        vector<int> val(n+2, 0);
        val[0] = 1;
        val[n+1] = 1;
        for(int i = 0; i < n; ++i){
            val[i+1] = nums[i];
        }
        for(int i = n-1; i >= 0; --i){
            for(int j = i+ 2; j < n+2; ++j){
                for(int k = i+1; k < j; ++k){
                    int sum = val[i]*val[k]*val[j];
                    dp[i][j] = max(dp[i][j], sum + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n+1];
    }
};
