class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> scounts{};
        for(const auto& str:strs){
            vector<int> buffer(26,0);
            for(const auto&c :str){
                buffer[c-'a']++;
            }
            scounts.insert(make_pair(str, buffer));
        }
        sort(strs.begin(),strs.end(),[&scounts](string s1, string s2){
            return scounts[s1] < scounts[s2];
        });
        vector<vector<string>> result{};
        vector<string> current{};
        for(int i = 0; i < strs.size(); ){
            if(current.size() == 0 || scounts[strs[i]] == scounts[current.back()]){
                current.push_back(strs[i]);
                ++i;
            }
            else{
                result.push_back(current);
                current = vector<string>();
            }
        }
        if(!current.empty()) result.push_back(current);
        return result;
    }
};