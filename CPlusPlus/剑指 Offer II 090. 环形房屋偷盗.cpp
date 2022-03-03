class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int result1 = dp(nums,0,nums.size()-1);
        int result2 = dp(nums,1,nums.size());
        return std::max(result1,result2);
    }
private:
    int dp(vector<int>&nums, int low, int high){
        std::array<int, 2> arr{nums[low],0};
        if(high - low > 1){
            arr[1] = std::max(nums[low],nums[low+1]);
        }
        for(int i = 2; i + low < high; ++i){
            arr[i % 2] = std::max(arr[(i-2)%2] + nums[low+i],arr[(i-1)%2]);
        }
        return std::max(arr[0],arr[1]);
    }
};