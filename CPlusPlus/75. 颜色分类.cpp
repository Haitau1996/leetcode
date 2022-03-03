class Solution {
public:
    void sortColors(vector<int>& nums) {
        int beg = 0;
        int end = nums.size() - 1;
        while(end >= beg){
            while(end >= beg && nums[end] >= 1){
                --end;
            }
            while(end >= beg && nums[beg] < 1){
                ++beg;
            }
            if(end >= beg) swap(nums[beg],nums[end]);
        }
        end = nums.size() - 1;
        while(end >= beg){
            while(end >= beg && nums[end] > 1){
                --end;
            }
            while(end >= beg && nums[beg] == 1){
                ++beg;
            }
            if(end >= beg) swap(nums[beg],nums[end]);
        }
    }
};