/*
 * @lc app=leetcode.cn id=190 lang=cpp
 * 需要注意这个题目可以从低位向高位扫描， 同时对 mask 移位而不是对 n
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t binary = 0;
        uint32_t mask = 1;
        for(int i = 0; i <32; ++i){
            if(mask&n) binary =  (binary<<1) + 1;
            else binary =  (binary<<1) + 0;
            mask <<=1;
        }
        return binary;
    }
};
// @lc code=end

