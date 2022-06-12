// 哈希映射
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res{};
        for(const auto& word : words){
            vector<int> map(26, -1);
            vector<int> rev_map(26,-1);
            int i {};
            for( i = 0; i < pattern.size(); ++i){
                if(map[word[i]-'a'] == -1 && rev_map[pattern[i]-'a'] == -1){
                    map[word[i]-'a'] = pattern[i]-'a';
                    rev_map[pattern[i]-'a'] = word[i]-'a';
                }else if(map[word[i]-'a'] !=pattern[i]-'a' || rev_map[pattern[i]-'a'] != word[i]-'a' ){
                    break;
                }
            }
            if(i == pattern.size()){
                res.push_back(word);
            }
        }
        return res;
    }
};
