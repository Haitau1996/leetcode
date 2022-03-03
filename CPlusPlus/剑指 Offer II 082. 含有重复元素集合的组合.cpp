/*****
 todo: 目前时间效率有点低
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target);
        sort(result.begin(), result.end());
        auto iter = unique(result.begin(), result.end());
        result.erase(iter, result.end());
        return result;
    }
private:
    vector<vector<int>> result{};
    vector<int> selected{};
    int currentSum{};
    void dfs(vector<int>& candidates,int cursor,int target){
        if(currentSum == target){
            result.push_back(selected);
            return;
        }
        if(currentSum > target || cursor == candidates.size()) return;
        selected.push_back(candidates[cursor]);
        currentSum+= candidates[cursor];
        dfs(candidates,cursor+1,target);
        currentSum-=candidates[cursor];
        selected.pop_back();
        dfs(candidates,cursor+1,target);
    }
};