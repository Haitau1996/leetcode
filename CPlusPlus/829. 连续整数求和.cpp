/*
 * 求和为 n, 则 (a+b)(a-b+1)=2*n
 * 假设 x,y 为两个整数， x*y = 2*n, 则 a = (x+y-1)/2, b = (x-y+1)/2
 * 因此， 只需要找到符合条件的 2*n 的因子，即可得到 a,b
 */

class Solution {
public:
    int consecutiveNumbersSum(int n)
    {
        int temp = n << 1;
        int res {};
        for (int i = 1; i * i <= temp; ++i) {
            if (temp % i == 0) {
                int j = temp / i;
                if ((i + j - 1) % 2 == 0)
                    ++res;
            }
        }
        return res;
    }
};
