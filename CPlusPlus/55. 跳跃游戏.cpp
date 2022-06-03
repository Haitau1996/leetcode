/*
 * 基础的做法是挨个设置为 true, 636 ms
 * 进阶的做法使用了双指针， 这样的话每个位置做多设置为一次 true,可以降低最坏条件下的时间复杂度 52ms
 */
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return true;
        vector<bool> can(nums.size(), false);
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j + 1 >= nums.size() || can[i + j] == true) {
                    can[i] = true;
                    break;
                }
            }
        }
        return can[0];
    }
};
class BetterSolution {
public:
    bool canJump(vector<int>& nums)
    {
        int curr_max { 0 };
        int n = nums.size();
        vector<bool> dp(n, 0);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dp[i])
                return false;
            int curr = i + nums[i];
            if (curr >= nums.size() - 1)
                return true;
            if (curr > curr_max) {
                for (int j = curr_max + 1; j <= curr; ++j)
                    dp[j] = true;
                curr_max = curr;
            }
        }
        return false;
    }
};
