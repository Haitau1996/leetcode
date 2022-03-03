/*
  * 双指针不但可以两边往中间扫描， 也可以中心开花
*/
class Solution {
public:
    using namespace std;
    int countSubstrings(string s) {
        if(s.size() <= 1) return s.size();
        int total_count = 0;
        for(int i=0; i < s.size(); ++i){
            total_count += countWithCenter(s, i, i);
            total_count += countWithCenter(s, i, i+1);
        }
        return total_count;

    }
private:
    int countWithCenter(string&s, int beg, int end){
        int partial_count = 0;
        while(beg >= 0 && end < s.size()){
            if(s[beg] == s[end]) {
                partial_count++;
                beg--;
                end++;
            }
            else break;
        }
        return partial_count;
    }
};