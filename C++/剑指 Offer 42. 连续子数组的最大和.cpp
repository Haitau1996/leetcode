/*
执行用时：24 ms, 在所有 C++ 提交中击败了30.65% 的用户
内存消耗：22.4 MB, 在所有 C++ 提交中击败了73.74% 的用户
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int result = numeric_limits<int>::min();
        for(auto& num: nums){
            currentSum += num;
            if(currentSum > result)
                result = currentSum;
            if(currentSum < 0) currentSum = 0;
        }
        return result;
    }
};