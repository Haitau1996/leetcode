//二分查找， 小于等于 mid 的能被 a,b 整数的数字个数为 mid/a + mid/b - mid/lcm(a,b)
// left 边界为 n, right 边界为 n * min(a,b)
#include <numeric>

using namespace std;
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int c = lcm(a,b);
        long long left = n;
        long long right = (long long) n * min(a,b);
        const int MOD = (int)1E9 + 7;
        while(left < right){
            long long mid = (left + right)>>1;
            if(mid/a + mid/b - mid/c >= n){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left%MOD;
    }
};
