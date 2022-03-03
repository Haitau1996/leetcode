/*
包含的话， 一定是某个长度和 s1 相等的 substr 和 s1 包含相同的字母， 因为只包含小写字母， 我们就可以使用一个长度为 26 的vector 做哈希。
1. vector 长度固定， 我们可以在常数 O(1) 的时间内判断是否全部归零
2. 滑动窗口， 并且根据 low,high 的元素值更新 vector
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> char_map(26,0);
        for(const auto& elem : s1){
            ++char_map[elem-'a'];
        }
        int low = 0;
        int high = s1.size();
        for(int i = low; i < high; ++i){
            --char_map[s2[i]-'a'];
        }
        high = s1.size()-1;
        while(high < s2.size()){
            if(all_zero(char_map)) return true;
            else{
                ++char_map[s2[low]-'a'];
                ++low;
                ++high;
                if(high!=s2.size()) --char_map[s2[high]-'a'];
            }
        }
        return false;
    }
    bool all_zero(vector<int>& in){
        for(const auto& elem:in){
            if(elem) return false;
        }
        return true;
    }
};