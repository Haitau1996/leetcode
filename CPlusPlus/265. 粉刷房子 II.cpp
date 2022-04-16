#include <vector>
#include <limits>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs[0].size();
        vector<int> dp(k,0);
        int smallest = numeric_limits<int>::max();
        int smaller = numeric_limits<int>::max();
        for(int i = 0; i < k; ++i){
            dp[i] = costs[0][i];
            if(dp[i] <= smallest){
                smaller = smallest;
                smallest = dp[i];
            }else if(dp[i] < smaller){
                smaller = dp[i];
            }
        }
        for(int i = 1; i <n; ++i){
            int smallest_new = numeric_limits<int>::max();
            int smaller_new = numeric_limits<int>::max();
            for(int j = 0; j < k; ++j){
                if(dp[j] == smallest){
                    dp[j] = smaller + costs[i][j];
                }else{
                    dp[j] = smallest + costs[i][j];
                }
                if(dp[j] <= smallest_new){
                    smaller_new = smallest_new;
                    smallest_new = dp[j];
                }else if(dp[j] < smaller_new){
                    smaller_new = dp[j];
                }
            }
            smallest = smallest_new;
            smaller = smaller_new;
        }
        return *min_element(dp.begin(),dp.end());
    }
};
