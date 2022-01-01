/*
执行用时：16 ms, 在所有 C++ 提交中击败了92.78% 的用户
内存消耗：10.3 MB, 在所有 C++ 提交中击败了95.73% 的用户
*/
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> counts(26,0);
        for(auto& ch : s){
            ++counts[ch-'a'];
        }
        for(auto& ch:s){
            if(counts[ch-'a'] == 1) return ch;
        }
        return ' ';
    }
};