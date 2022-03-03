/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> table(26,0);
        for(const auto& elem: s){
            table[elem-'a']++;
        }
        for(const auto& elem: t){
            table[elem-'a']--;
        }
        for(int i = 0; i < table.size(); ++i){
            if(table[i] == -1) return i + 'a';
        }
        return '\0';
    }
};
// @lc code=end

