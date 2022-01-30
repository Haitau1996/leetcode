/*
TODO: 效率有点低， 想想办法
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() == 1) return vector<vector<int>> (1,nums);
        if(nums.size() == 0) return vector<vector<int>>();
        vector<vector<int>> result;
        for(const auto& elem:nums){
            vector<int> temps;
            remove_copy(nums.begin(), nums.end(),back_inserter(temps),elem);
            auto partial_result = permute(temps);
            for(auto&temp : partial_result){
                temp.push_back(elem);
            }
            copy(std::begin(partial_result),std::end(partial_result),back_inserter(result));
        }
        return result;
    }
};