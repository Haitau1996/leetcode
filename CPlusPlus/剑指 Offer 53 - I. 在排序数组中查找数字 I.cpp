/*
执行用时：16 ms, 在所有 C++ 提交中击败了12.34% 的用户
内存消耗：12.8 MB, 在所有 C++ 提交中击败了90.48% 的用户
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int pos = searchHelper(nums,0,nums.size()-1, target);
        if(pos == -1) return 0;
        int result = -1;

            int i = pos;
            while(i >= 0 && nums[i] == target){
                ++result;
                --i;
            }
            i = pos;
            while(i<nums.size() && nums[i] == target){
                ++result;
                ++i;
            }
        return result;
    }
private:
    int searchHelper(vector<int>& nums, int low, int high, int target){
        if(nums[low] > target || nums[high] < target) return -1;
        else if(low >= high && nums[low] != target) return -1;
        else{
            int mid = (low + high)/2;
            if(nums[mid] > target) return searchHelper(nums, low, mid-1,target);
            else if(nums[mid] < target) return searchHelper(nums, mid+1, high, target);
            else return mid; 
        }
    }
};