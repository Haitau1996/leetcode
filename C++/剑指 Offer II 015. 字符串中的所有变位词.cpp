/*
  需要注意两个边界 case:
  * p 的 size 比 s 还大
  * 匹配到最后一个字符串
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return vector<int>();
        vector<int> char_map(26,0);
        vector<int> result;
        for(const auto& elem : p){
            char_map[elem - 'a'] ++;
        }
        int low = 0;
        int high = p.size();
        for(int i = low; i < high && i<s.size(); ++i){
            --char_map[s[i] - 'a'];
        }
        while(high <= s.size()){
            if(all_zero(char_map)) result.push_back(low);
            char_map[s[low] - 'a']++;
            low++;
            if(high < s.size() ){
                char_map[s[high] - 'a']--;
            }
            ++high;
        }
        return result;
    }
private:
    bool all_zero(vector<int>& char_map){
        for(const auto& elem : char_map){
            if(elem != 0) return false;
        }
        return true;
    }
};