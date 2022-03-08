/*
暴力做法： 120 out of 121 test case passed
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        auto len = get_longest_from(s);
        string prefix = s.substr(len);
        reverse(prefix.begin(),prefix.end());
        return prefix+s;
    }
private:
    int get_longest_from(string& s){
        if(s.size() == 0) return 0;
        char beg = s[0];
        vector<int> to_check;
        for(int i = 1; i < s.size(); ++i){
            if(s[i] == beg) to_check.push_back(i);
        }
        int len = 1;
        for(int i = to_check.size()-1; i >= 0; --i){
            if(check_in_range(s,0,to_check[i])){
                len = to_check[i] + 1;
                break;
            }
        }
        return len;
    }
    bool check_in_range(string& s, int low, int high){
        while(low < high){
            if(s[low] != s[high]){
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
};