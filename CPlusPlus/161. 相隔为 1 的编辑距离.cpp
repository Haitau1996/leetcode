class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if(abs((int)s.size() - (int)t.size()) > 1) return false;
        int size_diff{};
        if(s.size() == t.size()) size_diff = 0;
        else if(s.size() > t.size()) size_diff = 1;
        else size_diff = -1;
        int index = 0;
        while(index < s.size() && index < t.size()){
            if(s[index] == t[index]){
                ++index;
            }
            else if(size_diff == 0) return the_same_string(s,index+1, t, index+1);
            else if(size_diff == 1) return the_same_string(s, index+1, t, index);
            else return the_same_string(s, index, t, index+1);
        }
        return size_diff;
    }
private:
    bool the_same_string(string& s, int si, string& t, int ti){
        while(si < s.size() && ti < t.size()){
            if(s[si] == t[ti]){
                ++si;
                ++ti;
            }
            else return false;
        }
        return (si == s.size()) && (ti == t.size());
    }
};