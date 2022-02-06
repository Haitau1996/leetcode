class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> counts(1001,0);
        vector<int> result{};
        for(const auto& elem:arr1){
            counts[elem]++;
        }
        for(const auto& elem :arr2){
            while(counts[elem]){
                result.push_back(elem);
                --counts[elem];
            }
        }
        for(int i = 0; i < counts.size(); ++i){
            while(counts[i]){
                result.push_back(i);
                --counts[i];
            }
        }
        return result;
    }
};