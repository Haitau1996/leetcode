#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tcount(52,0);
        vector<int> scount(52,0);
        for(const auto& c:s){
            if(c < 'a') scount[c-'A']++;
            else scount[c-'a' + 26]++;
        }
        for(const auto& c: t){
            if(c < 'a') tcount[c-'A']++;
            else tcount[c-'a'+26]++;
        }
        if(!check_all(scount,tcount)) return string("");
        vector<int> buffer(52,0);
        int res_len = s.size()+1;
        string res;
        int low = 0;
        int high = 0;
        while(high <= s.size()){
            if(!check_all(buffer,tcount)){
                if(high < s.size()){
                    const char& c = s[high];
                    if(c < 'a') buffer[c-'A']++;
                    else buffer[c-'a'+26]++;
                }
                ++high;
            }else{
                while(check_all(buffer,tcount)){
                    if(high - low < res_len){
                        res_len = high - low;
                        res = s.substr(low, res_len);
                    }
                    const char& c = s[low];
                    if(c < 'a') buffer[c - 'A']--;
                    else buffer[c - 'a' + 26]--;
                    ++low;
                }
            }
        }
        return res;
    }
private:
    bool check_all(const vector<int>& first, const vector<int>& second){
        for(int i = 0; i < first.size(); ++i){
            if(first[i] < second[i]) return false;
        }
        return true;
    }
};
