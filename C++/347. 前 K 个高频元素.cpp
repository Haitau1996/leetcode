class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> keyToFrequency;
        vector<int> result;
        for(const auto& elem : nums){
            auto iter = keyToFrequency.find(elem);
            if(iter == keyToFrequency.end()){
                keyToFrequency.insert(std::make_pair(elem,1));
            }
            else{
                iter->second = iter->second + 1;
            }
        }
        auto cmp = [&keyToFrequency](const int& first, const int& second){
            return keyToFrequency[first] > keyToFrequency[second];
        };
        for(const auto& elem:keyToFrequency){
            if(result.size() < k-1){
                result.push_back(elem.first);
            }
            else if(result.size() == k-1){
                result.push_back(elem.first);
                std::make_heap(result.begin(), result.end(), cmp);
            }else{
                if(keyToFrequency[elem.first] > keyToFrequency[result[0]]){
                    std::pop_heap(result.begin(), result.end(),cmp);
                    result.pop_back();
                    result.push_back(elem.first);
                    std::push_heap(result.begin(), result.end(),cmp);
                }
            }
        }
        return result;
    }
};