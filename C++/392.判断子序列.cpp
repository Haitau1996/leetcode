/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto sindex = 0;
        auto tindex = 0;
        while(sindex < s.length() && tindex < t.length()) {
            if(s[sindex] == t[tindex]){
                ++sindex;
                ++tindex;
            }
            else{
                ++tindex;
            }
        }
        return sindex == s.length();
    }
};
// @lc code=end

