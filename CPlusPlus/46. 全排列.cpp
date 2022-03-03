/*
* TODO: 做法有点暴力， 找时间优化一下
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result{};
        if(nums.size() == 1){
            result.push_back(nums);
            return result;
        }
        for(int i = 0; i < nums.size(); ++i){
            auto temp = nums;
            int to_remove = temp[i];
            swap(temp[i], temp[temp.size() - 1]);
            temp.pop_back();
            auto partial_result = permute(temp);
            for(auto& elem : partial_result){
                elem.push_back(to_remove);
            }
            std::copy(partial_result.begin(), partial_result.end(),std::back_inserter(result));
        }
        return result;
    }
    
};