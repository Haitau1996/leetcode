class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> arr(10001,0);
        for(const auto& num:nums){
            arr[num] += num;
        }
        vector<int> dp{arr[0],arr[1]};
        for(int i = 2; i< arr.size(); ++i){
            dp[i % 2] = max(arr[i]+dp[i%2],dp[(i+1)%2]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};