class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,0,target);
        return result;
    }
private:
    vector<int> selected{};
    vector<vector<int>> result{};
    int current_sum{};
    void dfs(vector<int>& candidates, int cursor,int target){
        if(current_sum > target || cursor >= candidates.size())
            return;
        if(current_sum == target){
            result.push_back(selected);
            return;
        }
        // 两个 case: 选择该点或者跳过该点
        dfs(candidates, cursor+1, target);
        // selected:
        selected.push_back(candidates[cursor]);
        current_sum+= candidates[cursor];
        dfs(candidates,cursor,target);
        selected.pop_back();
        current_sum -= candidates[cursor];
    }
};