/*
 * 解法 1： 动态规划， dp[i] 保存下标为 i 元素结尾的最长递增子序列的长度
 * 解法 2： 贪心 + 二分查找， greed[i] 保存长度为 i + 1 的子序列结尾的最小值
 */
#include <algorithm>
#include <vector>

using namespace std;
class DP_Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int sz = nums.size();
        vector<int> buffer(sz, 0);
        buffer[0] = 1;
        int global_max { 1 };
        for (int i = 1; i < sz; i++) {
            int max = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (max < buffer[j] + 1) {
                        max = buffer[j] + 1;
                        if (max > global_max)
                            global_max = max;
                    }
                }
            }
            buffer[i] = max;
        }
        return global_max;
    }
};
class Greedy_BinarySearch_Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> greed { nums[0] };
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > greed.back()) {
                greed.push_back(nums[i]);
            } else {
                int l = -1;
                int r = greed.size() - 1;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (greed[mid] >= nums[i])
                        r = mid - 1;
                    else
                        l = mid;
                }
                greed[l + 1] = nums[i];
            }
        }
        return greed.size();
    }
};
