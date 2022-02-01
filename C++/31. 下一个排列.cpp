class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int first = nums.size()-1;
        int second = first - 1;
        while(second >= 0){
            if(nums[first] <= nums[second]){
                --first;
                --second;
            }
            else break;
        }
        if(second == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        first = nums.size() - 1;
        while(nums[first] <= nums[second]){
            --first;
        }
        swap(nums[second],nums[first]);
        reverse(nums.begin()+second+1, nums.end());
            
    }
};