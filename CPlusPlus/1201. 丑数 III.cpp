// 要特别注意在 cnt 计数和 lcm 求值的过程中的 int 溢出问题
// 计算 mid 的时候 ， right 的值最大为  2E9, 因此 left + right 可能会溢出， 注意使用 left + diff/2
#include <numeric>

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c)
    {
        typedef long long ll;
        long long lab = std::lcm((ll)a, (ll)b);
        long long lac = std::lcm((ll)a, (ll)c);
        long long lbc = std::lcm((ll)b, (ll)c);
        long long labc = std::lcm((ll)a, lbc);
        int left = 1;
        int right = 2 * (int)(1E9);
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            long long cnt = 0LL + mid / a + mid / b + mid / c - mid / lab - mid / lac - mid / lbc + mid / labc;
            if (cnt < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
