class Solution {
public:
    int balancedStringSplit(string s) {
        return splitInRange(s, 0, s.size()-1);
    }
    int splitInRange(string& s, int low, int high){
        if(low == s.size()) return 0;
        int count;
        if(s[low] == 'L') count = 1;
        else count = -1;
        ++low;
        while(count != 0){
            if(s[low] == 'L') {
                ++count;
                ++low;
            }
            else{
                --count;
                ++low;
            }
        }
        return 1 + splitInRange(s,low,high);
    }
};