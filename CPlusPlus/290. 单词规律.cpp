// 需要注意 s 是 string, 而不是 vector<string>, 故要使用 getline 分割
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        auto s_len = count(s.begin(), s.end(), ' ');
        if(s_len+1!= pattern.size()) return false;
        unordered_map<char, string> for_map{};
        unordered_map<string, char> rev_map{};
        string temp{};
        istringstream ss(s);
        for(int i = 0; i < pattern.size(); ++i){
            getline(ss, temp,' ');
            if(for_map.find(pattern[i]) == for_map.end() && rev_map.find(temp) == rev_map.end()){
                for_map[pattern[i]] = temp;
                rev_map[temp] = pattern[i];
            }else if(for_map[pattern[i]]!=temp || rev_map[temp]!= pattern[i]){
                return false;
            }
        }
        return true;
    }
};
