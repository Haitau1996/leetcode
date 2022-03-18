/*
太狗了， 说满足 32 位整数， 其实是满足 32 位无符号整数
*/
#include <vector>

using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned> dp(target+1,0);
        dp[0] = 1;
        for(int i = 1; i <= target; ++i){
            int count = 0;
            for(const auto& elem : nums){
                if(i - elem >= 0 && dp[i-elem] > 0)
                    count += dp[i-elem];
            }
            dp[i] = count;
        }
        return dp.back();
    }
};
