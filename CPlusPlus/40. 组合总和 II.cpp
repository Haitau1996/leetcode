/*
标准的回溯无法解决这个问题， 因为数字可能出现很多次重复， 会陷入 2^n 泥潭
//todo: 将数据放在一起处理
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        core(candidates, 0, target);
        for(auto& elem : result){
            sort(elem.begin(), elem.end());
        }
        sort(result.begin(), result.end());
        auto iter = unique(result.begin(), result.end());
        result.erase(iter, result.end());
        return result;
    }
private:
    vector<vector<int>> result{};
    vector<int> selected{};
    int current_sum{};
    void core(vector<int>& nums, int cursor, int target){
        if(current_sum == target){
            result.push_back(selected);
            return;
        }
        if(current_sum > target || cursor >= nums.size()){
            return;
        }
        // 剩下的有两种情况， 选择cursor点或者忽略
        else{// selected 
            current_sum += nums[cursor];
            selected.push_back(nums[cursor]);
            core(nums, cursor+1, target);
            current_sum -= nums[cursor];
            selected.pop_back();
            // negelect
            core(nums,cursor+1, target);
        }
    }
};

