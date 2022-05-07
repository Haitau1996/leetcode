/*
 * 这个题目最重要的是找到 hash(i) 到 hash(i+1) 之间的桥梁， 发现
 * $hash(i) = (val(s[i]) * p^0 + val(s[i+1]) * p^1 + ... + val(s[i+k-1]) * p^{k-1}) mod m$
 * $hash(i+1) = (val(s[i+1]) * p^0 + val(s[i+2]) * p^1 + ... + val(s[i+k]) * p^{k-1}) mod m$

    因为**模运算只有乘法法则没有除法法则**， 我们从后往前推导：
   $hash(i) = (hash(i+1)*p - val(s[i+k]) * p^{k} + val(s[i]) * p^0) mod m$
   并且 $hash(i+1)*p mod m = (hash(i+1) mod m + p mod m) mod m$
 */
#include <string>

using namespace std;
class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue)
    {
        int sz = s.size();
        long temp = power % modulo;
        for (int i = 0; i < k - 1; ++i) {
            temp = (temp * (power % modulo)) % modulo;
        }
        long long curr { 0 };
        string res {};
        for (int i = 0; i < k; ++i) {
            curr = ((curr * power) % modulo + s[sz - 1 - i] - 'a' + 1) % modulo;
        }
        for (int j = sz - k; j >= 0; --j) {
            if (curr == hashValue || curr + modulo == hashValue)
                res = s.substr(j, k);
            if (j != 0) {
                curr = (((curr % modulo) * (power % modulo)) % modulo + (s[j - 1] - 'a' + 1) % modulo - (s[j + k - 1] - 'a' + 1) * temp % modulo) % modulo;
            }
        }
        return res;
    }
};
