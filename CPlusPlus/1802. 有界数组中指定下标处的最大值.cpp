// 对于某个值判断最优情况下的结果是否小于 maxSum,
// 然后做二分， 需要特别注意下标
#include <vector>

using namespace std;
class Solution {
public:
    int maxValue(int n, int index, int maxSum)
    {
        long l = 0;
        long r = maxSum;
        while (l < r) {
            long mid = (l + r + 1) >> 1;
            long left = mid > index + 1 ? (mid + mid - index) * (index + 1) / 2 : (mid + 1) * mid / 2 + index - mid + 1;
            long right = index + mid < n ? (mid + 1) * mid / 2 + n - index - mid : (n - index) * (mid + mid + index - n + 1) / 2;
            if (left + right - mid <= maxSum)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};
