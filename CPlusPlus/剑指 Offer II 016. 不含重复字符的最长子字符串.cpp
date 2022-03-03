class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index_of_char(128,-1);
        int beg = 0;
        int end = 0;
        int size = 0;
        while(end <= s.size()){
            if(end == s.size()){
                size = max(end - beg, size);
                break;
            }
            else if(index_of_char[s[end]] != -1){
                size = max(end-beg,size);
                beg = max(index_of_char[s[end]] + 1,beg);
                index_of_char[s[end]] = end;
                ++end; 
            }
            else{
                index_of_char[s[end]] = end;
                ++end;
            }
        }
        return size;
    }
};