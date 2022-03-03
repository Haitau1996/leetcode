/*
执行用时：4 ms, 在所有 C++ 提交中击败了75.56% 的用户
内存消耗：10.6 MB, 在所有 C++ 提交中击败了95.93% 的用户
*/
#include<vector>
using std::vector;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        else
            return searchHealper(nums,0,nums.size()-1,target);
    }
private:
    int binSearch(vector<int>& nums, int low, int high,int target){
        // base case:
        if(low > high)
            return -1;
        if(low == high){
            if(nums[low] == target)
                return low;
            else
                return -1;
        }
        int mid = (low + high)/2;
        if(nums[mid] > target)
            return binSearch(nums,low,mid-1, target);
        if(nums[mid] < target)
            return binSearch(nums,mid+1,high,target);
        else return mid;
    }
    int searchHealper(vector<int>& nums, int low, int high,int target){
        if(low > high)
            return -1;
        if(low == high && nums[low]!= target)
            return -1;
        int mid = (low + high)/2;
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] > nums[low]){
            if(target >= nums[low] && target< nums[mid])
                return binSearch(nums,low,mid-1,target);
            else
                return searchHealper(nums,mid+1,high,target);
        }
        else if(nums[mid] < nums[low]){
            if(target> nums[mid] && target<= nums[high])
                return binSearch(nums,mid+1,high,target);
            else
                return searchHealper(nums,low,mid-1,target);
        }
        else{
            return searchHealper(nums,mid+1,high,target);
        }

    }
};