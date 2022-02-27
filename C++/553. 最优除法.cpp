/*
题目挺简单的， 分类讨论一下
**不要怕**
*/
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        return max_in_range(nums,0, nums.size()-1);
    }
private:
    string max_in_range(vector<int>&nums, int low, int high){
        // base case:
        if(low - high == 0) return to_string(nums[low]);
        else if(high - low == 1) return to_string(nums[low]) + "/" + to_string(nums[high]);
        else return to_string(nums[low]) + "/(" + min_in_range(nums,low+1,high) +")";
    }
    string min_in_range(vector<int>&nums, int low, int high){
        string result{""};
        for(int i = low; i < high; i++){
            result += to_string(nums[i]);
            result += "/";
        }
        result += to_string(nums[high]);
        return result;
    }
};