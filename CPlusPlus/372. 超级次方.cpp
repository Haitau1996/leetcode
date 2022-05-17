// 递归求解， 需要注意的是 b 是一个非常大的数组， 所以不能直接转为 int
// 需要用到模的性质
#include <vector>

using std::vector;
class Solution {
public:
    int superPow(int a, vector<int>& b)
    {
        int n = b.size();
        int res = 1;
        for (int i = 0; i < n; ++i) {
            res = (res % 1337 * core(a, b[i], n - 1 - i) % 1337) % 1337;
        }
        return res;
    }

private:
    int pow(int a, int b)
    {
        if (b == 0)
            return 1;
        long half = pow(a % 1337, b / 2);
        if (b & 1) {
            return ((half % 1337) * (half % 1337) * (a % 1337)) % 1337;
        } else
            return ((half % 1337) * (half % 1337)) % 1337;
    }
    int core(int a, int b, int c)
    {
        if (c == 0)
            return pow(a, b);
        else {
            int new_base = pow(a, 10);
            return core(new_base, b, c - 1);
        }
    }
    // core 里面好像也可以二分， 不过优化后运行时间反而增加了
    int binary_cut_core(int a, int b, int c)
    {
        if (c == 0)
            return pow(a, b);
        else if (c == 1) {
            int new_base = pow(a, 10);
            return binary_cut_core(new_base, b, c - 1);
        } else {
            int new_base = binary_cut_core(a, 1, c / 2);
            return binary_cut_core(new_base, b, (c + 1) / 2);
        }
    }
};
