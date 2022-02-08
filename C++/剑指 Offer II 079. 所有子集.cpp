/*
需要特别注意回退， 因为我们每次有两个选择：
1. 当下 elem 加入 selected
2. 当下 elem 不加入 selected
做出了选择之后， 调用会修改 subset 的值， 因此在处理结束之后要改回去
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return result;
    }
private:
    vector<int> selected{};
    vector<vector<int>> result{};
    void dfs(int index, vector<int>& nums){
        if(index == nums.size()) result.push_back(selected);
        else{
            selected.push_back(nums[index]);
            dfs(index+1, nums);
            selected.pop_back();
            dfs(index+1, nums);
        }
    }
};