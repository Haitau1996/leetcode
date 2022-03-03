/*
暴力解法， O(n^3)
todo: 优化实现 o(n^2)
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int beg = 0; 
        int end = nums.size()-1;
        int sum = 0;
        while(end > beg+1){
            int inner_beg = beg;
            while(inner_beg < end-1){
                int mid = inner_beg+1;
                while(mid < end && nums[inner_beg] + nums[mid] <= nums[end]){
                    ++mid;
                }
                sum += (end -mid);
                ++inner_beg;
            }
            --end;
        }
        return sum;
    }
};
