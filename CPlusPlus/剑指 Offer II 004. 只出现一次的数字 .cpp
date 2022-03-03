/*
执行用时：8 ms, 在所有 C++ 提交中击败了77.50% 的用户
内存消耗：9.2 MB, 在所有 C++ 提交中击败了91.55% 的用户
需要注意下面几点：
* 对于每一位计数的数组存放数据， 可以是从低位到高位，也可以从高位到低位
* 实际上 bit representation 中的存放， 是从高位到低位
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitSum(32,0);
        for(auto elem : nums){
            for(auto i{0}; i <= 31; ++i){
                bitSum[i] += (elem>>(i)) & 1;
            }
        }
        int res = 0;
        for(auto i = 0; i< 32; ++i){
            res = (res<< 1) + bitSum[31-i]%3;
        }
        return res;
    }
};