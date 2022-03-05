/*
回溯，随手写了个去重的方法， 通过了，但是我自己也不知道为什么。
仔细想了下， 我这个相当于一旦选取了重复的元素， 那么后面就不能跳过，例如要处理 [1 2 2 2 2],打印的序列
[[1,2,2,2,2],[1,2,2,2],[1,2,2],[1,2],[1],[2,2,2,2],[2,2,2],[2,2],[2],[]]
第一个是全选的结果 1 2 2 2
然后是跳过第一个2 ， 选后面的 1 null 2 2 2， 然后跳过前两个。。。 直到只剩下一个 1， 因此就没有重复
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums,0);
        return result;
    }
private:
    vector<int> selected{};
    vector<vector<int>> result{};
    void dfs(vector<int>& nums, int index){
        if(index == nums.size()){
            result.push_back(selected);
            return;
        }
        // case 1: selected current
        selected.push_back(nums[index]);
        dfs(nums,index+1);
        selected.pop_back();
        if(!(index > 0 && nums[index] == nums[index-1] && !selected.empty() && selected.back()==nums[index])) dfs(nums,index+1);
    }
};