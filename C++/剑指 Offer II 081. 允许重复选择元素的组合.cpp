/*
分为两种情况：
1. 忽略当下的点
2. 选择当前的点，将 target - nums[current] 并且 current 不变
**之前我认为有第三种情况： 选择当下的点， 将 target - nums[current] 然后 current + 1, 这其实是 先 2 后1 的组合， 因此在 case 2 中加了这个情况就相等于重复计算了**
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates, 0, target);
        return result;
    }
private:
    vector<vector<int>> result{};
    vector<int> selected;
    void helper(vector<int>& candidates, int index, int target){
        if(target == 0){
            result.push_back(selected);
        }
        else if(index < candidates.size() && target > 0){
            // case 1 : neglect current
            helper(candidates, index+1, target);
            // case 2: selected current
            selected.push_back(candidates[index]);
            helper(candidates, index, target-candidates[index]);
            // error: don't needed 
            // helper(candidates, index+1, target-candidates[index]);
            selected.pop_back();
        }
    }
};