/*
执行用时：4 ms, 在所有 C++ 提交中击败了95.65% 的用户
内存消耗：7.2 MB, 在所有 C++ 提交中击败了36.74% 的用户
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size() || s == t) return false;
        vector<int> hashS(26,0);
        for(auto& elem: s){
            ++hashS[elem-'a'];
        }
        for(auto& elem: t){
            --hashS[elem-'a'];
        }
        for(auto& elem : hashS){
            if(elem) return false;
        }
        return true;
    }
};