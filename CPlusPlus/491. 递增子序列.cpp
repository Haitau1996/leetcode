/*
这个问题典型的回溯， 但是实现起来有一个问题就是如何去除重复， 因为每遍历一个下标， 如果值可以添加到递增序列中， 就会有两种选择
1. 选择该节点
2. 跳过该节点

我的去重策略是， 如果**当下的值和已有序列最后一个值相等的时候， 它就不被允许跳过**。 
如一个序列 7，7，7
第一步如果选择了 7， 那么就没有分支了， 结果一定是 7->7->7
如果跳过了 7， 那么就有两个分叉， 第二步可以选择 7, 这时候第三步也一定要选： null -> 7 -> 7  或者跳过 7 得到两个分叉 null->null-> 7 和 null->null->null
*/
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums,0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> selected{};
    void dfs(vector<int>& nums, int current){
        if(current == nums.size() && selected.size()>1){
            result.push_back(selected);
            return;
        }else if(current >= nums.size()) return;
        // case 1: selected current
        if(selected.empty() || selected.back() <= nums[current]){
            selected.push_back(nums[current]);
            dfs(nums,current+1);
            selected.pop_back();
        }
        if(!(!selected.empty() && selected.back() == nums[current]))
            dfs(nums,current+1);
    }
};