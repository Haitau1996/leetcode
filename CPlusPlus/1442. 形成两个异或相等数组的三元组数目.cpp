/*
从 i 到 j 的异或 a 可以用 从 0 到 i-1 的异或 b 和 从 0 到 j 的异或 c 表示: a = b^c.
a^b = c, b = b^a^a = a^b^a = c^a. 因此, 我们先求出前缀和数组：
a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1] = xor_prefix[j-1]^xor_prefix[j-1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]     = xor_prefix[j-1]^xor_prefix[k]
a == b 就相当于 xor_prefix[i-1]== xor_prefix[k], 和 j 没有关系， i<j<=k， 就可以选出 k-i 个 j.
为了方便处理 i=0 的情况， 我们在前缀和前面加一个0.
*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int> xor_prefix{0};
        for(const auto& elem: arr){
            xor_prefix.push_back(xor_prefix.back()^elem);
        }
        // a 从 i ... j-1 => xor_prefix(i-1)^xor_prefix(j-1)
        // b 从 j ... k => xor_prefix(j-1)^xor_prefix(k)
        // a == b => xor_prefix(i-1) == xor_prefix(k)
        int result = 0;
        // 需要注意下面的 i 其实相当于上式中的 i-1, 因此 k 和 i 的差大于等于 1, k 和 i 的差就大于等于 2
        // 对于固定的 i，k, (i,j,k)的对数为 k-i, 换成 newi 就是 k-newi-1 
        for(int newi = 0; newi < arr.size(); ++newi){
            for(int k = newi+2; k <= arr.size(); ++k){
                if(xor_prefix[newi] == xor_prefix[k]){
                    result+= (k-newi-1);
                }
            }
        }
        return result;
    }
};
