class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::multimap<std::string, std::string> result_map;
        std::set<std::string> sorted;
        for(const auto& elem: strs){
            auto key = elem;
            std::sort(key.begin(), key.end());
            if(sorted.find(key) == sorted.end()) sorted.insert(key);
            result_map.insert(std::make_pair(key, elem));
        }
        vector<vector<string>> result;
        for(auto& elem : sorted){
            auto items = result_map.equal_range(elem);
            vector<string> temp;
            for(auto i = items.first; i != items.second; ++i){
                temp.push_back(i->second);
            }
            result.push_back(temp);
        }
        return result;
    }
};