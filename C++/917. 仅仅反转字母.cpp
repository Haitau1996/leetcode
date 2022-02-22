class Solution {
public:
    string reverseOnlyLetters(string s) {
        int beg = 0;
        int end = s.size();
        while(beg < end){
            while(!isalpha(s[beg]) && beg < end){
                ++beg;
            }
            while(!isalpha(s[end]) && beg < end){
                --end;
            }
            if(beg < end){
                swap(s[beg],s[end]);
                ++beg;
                --end;
            }
        }
        return s;
    }
};