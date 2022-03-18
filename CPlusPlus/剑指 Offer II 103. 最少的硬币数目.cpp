#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            int local_min = numeric_limits<int>::max();
            for(const auto& elem : coins){
                if(elem > i) continue;
                else if(elem == i){
                    dp[i] = 1;
                    break;
                }
                if(dp[i-elem]!= -1 && dp[i-elem] < local_min) {
                    local_min = dp[i-elem];
                    dp[i] = dp[i-elem] + 1;
                }
            }
        }
        return dp.back();
    }
};
