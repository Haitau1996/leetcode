class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff = numeric_limits<int>::max();
        int result{};
        for(int i = 0; i < nums.size() - 2; ++i){
            int beg = i+1;
            int end = nums.size() - 1;
            while(beg < end){
                int sum = nums[i] + nums[beg] + nums[end];
                int new_diff = abs(sum - target);
                if(new_diff == 0) return target;
                else if(new_diff < diff){
                    diff = new_diff;
                    result = sum;
                }
                if(sum > target) --end;
                else ++beg;
            }
        }
        return result;
    }
};