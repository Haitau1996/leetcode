class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size();
        vector<int> buffer(sz,0);
        buffer[0] = 1;
        int global_max{1};
        for(int i = 1; i < sz; i++){
            int max = 1;
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(max < buffer[j] + 1){
                        max = buffer[j] + 1;
                        if(max > global_max) global_max = max;
                    }
                }
            }
            buffer[i] = max;
        }
        return global_max;
    }
};