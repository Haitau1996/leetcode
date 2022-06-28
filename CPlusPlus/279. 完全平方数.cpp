// 动态规划， dp[i] 为 值为 i 时候的结果
// i 为完全平方数， 则无需考虑，dp[i] 为 1
// i 不是， 则找到所有 小于等于 sqrt(i) 的j, 求 dp[i-j*j]+1 的最小值
#include<vector>
#include <limits>

using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        for(int i = 1; i <= n; i++){
            int temp = floor(sqrt(i));
            if(temp*temp == i) dp[i] = 1;
            else{
                int part_min = numeric_limits<int>::max();
                for(int j = 1; j <= temp; ++j){
                    if(dp[i -j*j] == -1) dp[i-j*j] = numSquares(i-j*j);
                    if(dp[i - j*j] < part_min){
                        part_min = dp[i-j*j];
                    }
                }
                dp[i] = part_min+1;
            }
        }
        return dp[n];
    }
};
