/*
 * 这个题目主要是考虑它的斜率， 如果斜率向上的话， 那么峰值在后面，斜率向下的峰值在前面
 * 不存在连续两个数相等的情况
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int beg = 0;
        int end = nums.size() - 1;
        while(beg < end){
            int mid = (beg + end)/2;
            if(nums[mid] > nums[mid+1] &&((mid == 0) || nums[mid] > nums[mid-1]))
                return mid;
            else if(nums[mid] > nums[mid+1]){
                end = mid - 1;
            }
            else{
                beg = mid + 1;
            }
            
        }
        return beg;
    }
};
