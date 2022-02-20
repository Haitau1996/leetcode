class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int start = 0;
        while(start < nums.size()-1){
            if(nums[start+1] >= nums[start]) ++start;
            else break;
        }
        if(start == nums.size()-1) return 0;
        int end = nums.size() - 1;
        while(end > 0){
            if(nums[end-1] <= nums[end]) --end;
            else break;
        }
        int min_in_range = numeric_limits<int>::max();
        int max_in_range = numeric_limits<int>::min();
        for(int i = start; i <= end; ++i){
            if(nums[i] < min_in_range) min_in_range = nums[i];
            if(nums[i] > max_in_range) max_in_range = nums[i];
        }
        int new_start = 0;
        while(new_start < nums.size()){
            if(nums[new_start] <= min_in_range) ++new_start;
            else break;
        }
        int new_end = nums.size()-1;
        while(new_end >= 0){
            if(nums[new_end] >= max_in_range) --new_end;
            else break;
        }
        return new_end - new_start + 1;
    }
};