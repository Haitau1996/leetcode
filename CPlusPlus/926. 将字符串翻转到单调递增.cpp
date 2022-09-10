/*
 * dp[i+1][0] 表示0..i 修改成以 0 结尾时需要的最小修改次数， dp[i+1][i] 表示修改成以 1 结尾时候需要的最小修改次数
    1. 当 s[i] == '0', dp[i+1][0] = dp[i][0], dp[i+1][1] = dp[i][1]+1(修改当下元素)
    2. s[i] == '1', 那么修改为 0 结尾就要改当前元素， dp[i+1][0] = dp[i][0]+1, 而以 1 结尾则无需修改， 取前一个位置的较小值。
*/
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        for(int i = 0; i < n; ++i){
            if(s[i] == '0') {
                dp[i+1][0] = dp[i][0];
                dp[i+1][1] = dp[i][1] + 1;
            }else{
                dp[i+1][0] = dp[i][0] + 1;
                dp[i+1][1] = min(dp[i][0],dp[i][1]);
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};
