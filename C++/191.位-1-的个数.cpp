/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) return n;
        else return hammingWeight(n&(n-1)) + 1;
    }
};
// @lc code=end

