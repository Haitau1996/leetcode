/*
 * 前缀和 + 二分查找(n log n)
    * 对于选定的mid 的右边界i, 可以判断此时可选的 mid 左边界， 它需要满足两个条件：
        * 1. 左边界的前缀和小于mid的前缀和 nums[i] >= 2 * nums[right], 确定了最右边的可选值
        * 2. 右边的部分和大于等于中间部分 nums.back()-nums[i] >= nums[i] - nums[left]，即 nums[left] >= 2 * nums[i] - nums[back]
        * 需要特别注意， 左右边界都要小于等于 i-1
 * TODO: 三指针
*/

#include <vector>
using namespace std;

class Solution {
public:
    int waysToSplit(vector<int>& nums)
    {
        int prefix { 0 };
        int temp {};
        int res { 0 };
        const int MOD = 1000000007;
        for (auto& elem : nums) {
            temp = elem;
            elem += prefix;
            prefix += temp;
        }
        for (int i = 1; i < nums.size() - 1; ++i) {
            int r = min(i - 1, get_right(nums, nums[i] >> 1));
            int l = get_left(nums, 2 * nums[i] - nums.back());
            if (nums[r] <= nums[i] >> 1 && nums[l] >= 2 * nums[i] - nums.back())
                res = (res + max(0, r - l + 1)) % MOD;
        }
        return res;
    }

private:
    int get_right(vector<int>& nums, int val)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high + 1) >> 1;
            if (nums[mid] > val)
                high = mid - 1;
            else
                low = mid;
        }
        return low;
    }
    int get_left(vector<int>& nums, int val)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = (low + high) >> 1;
            if (nums[mid] < val)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
