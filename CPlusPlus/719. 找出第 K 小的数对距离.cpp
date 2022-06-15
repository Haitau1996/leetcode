// 距离差的绝对值范围在 [0, max(nums)-min(nums)] 之间， 对它做二分查找
// 如果距离小于 mid 的个数大于等于 k, right = mid, 否则 left = mid + 1
// 计算个数的时候需要排序之后再二分
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums.front();
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (count_pair(nums, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    int count_pair(vector<int>& nums, int diff)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int next = upper_bound(nums.begin(), nums.end(), nums[i] + diff) - nums.begin();
            res += (next - i - 1);
        }
        return res;
    }
};
