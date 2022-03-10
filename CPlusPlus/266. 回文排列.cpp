class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char,int> count{};
        for(const auto& elem:s){
            count[elem]++;
        }
        int result = 0;
        for(const auto& elem :count){
            if(elem.second % 2 != 0) ++result;
        }
        return result<2;
    }
};