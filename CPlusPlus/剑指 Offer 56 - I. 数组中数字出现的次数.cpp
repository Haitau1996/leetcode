// 一直 xor 之后得到一个非零的结果， 然后根据其中某位为 1 的位
// 将数组分成两个部分， 每个部分包含一个出现一次的数字和若干出现两次的数字
// 相同的数字一定在同一个分组
#include <vector>

using std::vector;
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums)
    {
        int xor_temp = 0;
        for (const auto& elem : nums) {
            xor_temp ^= elem;
        }
        int one_bit = find_non_zero(xor_temp);
        vector<int> res { 0, 0 };
        for (const auto& elem : nums) {
            if (valid(elem, one_bit)) {
                res[0] ^= elem;
            } else
                res[1] ^= elem;
        }
        return res;
    }

private:
    int find_non_zero(int in)
    {
        int i = 0;
        while ((in & 1) == 0 && i < 32) {
            in >>= 1;
            ++i;
        }
        return i;
    }
    bool valid(int in, int b)
    {
        in >>= b;
        return (in & 1);
    }
};
