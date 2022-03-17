/*
去重还是有一点困难， 在每步可能选择一个元素或者跳过， 因为在判断的时候， 如果我们某次选择了元素后面还要选， 可能遇到提前终止而导致的重复，如
1,2,2,2 去凑 5， 如果没有提前终止， 那么可能的情况是 0个2,1个2， 2个2 和 3 个2, 只要比较 selected 的最后一个元素和当前指针指向的元素是否相同，如果相同就不跳过。就可以完成去重。但是如果提前终止之后，一个可能的结果就是 3 个 2 的 case 可能退化成和 2个2 重复了.
做法1. 使用 set 暴力去重
做法2. 使用 unodered_map 保存元素出现的次数， 然后从 0 到 n 每种情况都做处理
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return vector<vector<int>>(result.begin(), result.end());
    }
private:
    int current_sum{};
    vector<int> selected{};
    set<vector<int>> result;
    void dfs(vector<int>& candidates, int cursor, int target){
        if(current_sum == target){
            result.insert(selected);
            return;
        }
        if(current_sum > target || cursor >= candidates.size() || candidates[cursor] >target) return;
        // case 1: selected current
        selected.push_back(candidates[cursor]);
        current_sum+=candidates[cursor];
        dfs(candidates, cursor+1, target);
        selected.pop_back();
        current_sum-=candidates[cursor];
        if(selected.empty() || selected.back()!=candidates[cursor]) dfs(candidates,cursor+1,target);
    }
};


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> val_to_count{};
        for(const auto& elem : candidates){
            val_to_count[elem]++;
        }
        dfs(val_to_count, val_to_count.begin(), target);
        return result;
    }
private:
    vector<int> selected{};
    vector<vector<int>> result{};
    int current_sum{};
    void dfs(const unordered_map<int,int>& val_to_count, unordered_map<int,int>::iterator cursor, int target){
        if(current_sum == target){
            result.push_back(selected);
            return;
        }else if(current_sum > target || cursor == val_to_count.end()){
            return;
        }
        int val = cursor->first;
        int count = cursor->second;
        cursor++;
        for(int i = 0; i < count; ++i){
            selected.push_back(val);
            current_sum += val;
            dfs(val_to_count,cursor, target);
        }
        for(int i = 0; i < count; ++i){
            selected.pop_back();
            current_sum-=val;
        }
        dfs(val_to_count,cursor,target);
    }
};