/*
前缀异或， 刚刚试着理解了一下异或运算的性质：
1. x^0 = x, x^x = 0
2. a^b^c = a^(b^c)
3. a^b^a = a^a^b = 0^b = b

因此如果我们求了从 0..(i-1) 的异或 a, 和 0..j 的异或 b, 那么 i 到 j 之间的异或为 x,
a^x = b, 已知 a和 b, 只要两边对 a 做异或就可以得到 x, 即 x = a^a^x = a^b。

因此， 我们已经知道了所有下标的前缀异或 xor_prefix， 那么[a,b] 的异或， 就能直接通过 xor_prefix[b]^xor_prefix[a-1] 得到。
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xor_prefix{0};
        for(const auto & elem : arr){
            xor_prefix.push_back(elem^xor_prefix.back());
        }
        vector<int> result;
        for(const auto& elem : queries){
            result.push_back(xor_prefix[elem[1]+1]^xor_prefix[elem[0]]);
        }
        return result;
    }
};
