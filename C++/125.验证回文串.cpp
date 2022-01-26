/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * 主要是 每次都要检查 beg < end
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int beg = 0;
        int end = s.length()-1;
        while(beg < end) {
            while(beg < end && !(std::isalpha(s[beg]) || std::isalnum(s[beg]))){
                ++beg;
            }
            while(beg < end && !((std::isalpha(s[end]) || std::isalnum(s[end])))){
                --end;
            }
            if(beg < end && tolower(s[beg])!=tolower(s[end])) return false;
            else{
                ++beg;
                --end;
            }
        }
        return true;
    }
};
// @lc code=end

