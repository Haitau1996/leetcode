/*
* 看到题目的第一印象是可以使用回溯， 但回溯的时间复杂度奔着 2^n 去了
Error: 超出时间限制
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(),0);
        if(sum % 2) return false;
        return dfs(nums,0, sum/2);
    }
private:
    int current_sum{};
    bool dfs(vector<int>&nums, int cursor, int target){
        if(current_sum == target) return true;
        else if(cursor == nums.size()) return false;
        // 两种选择： 
        // case 1 : 选择当下的点
        current_sum+= nums[cursor];
        if(dfs(nums,cursor+1,target)) return true;
        else{
            current_sum -= nums[cursor];
        }
        // case 2 : 忽略当下的点
        return dfs(nums,cursor+1,target);
    }
};

/* 
改使用动态规划
f(i, j) 表示前 i 个数字可以有和为 j 的子数组， 那么
f(i,j) = f(i-1,j) || f(i-1,j-nums[i])
*/