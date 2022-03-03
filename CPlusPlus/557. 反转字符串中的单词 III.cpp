class Solution {
public:
    string reverseWords(string s) {
        int beg = 0;
        int end = beg+1;
        while(end < s.size()){
            if(s[end] == ' '){
                core(s, beg, end -1);
                beg = end + 1;
                end = beg + 1;
            }
            else{
                ++end;
            }
        }
        if(beg != s.size()){
            core(s, beg, end-1);
        }
        return s;
    }
    void core(string&s, int beg, int end){
        while(beg < end){
            swap(s[beg],s[end]);
            ++beg;
            --end;
        }
    }
};