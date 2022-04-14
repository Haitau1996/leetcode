#include<vector>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        else if(nums.front() < nums.back()) return nums.front();
        int low = 0;
        int high = nums.size() - 1;
        return findInRange(nums, low, high);
    }
private:
    int findInRange(vector<int>&nums, int low, int high){
        if(low == high) return nums[low];
        int mid = (low +high)/2;
        if(nums[mid]>nums[mid+1]) return nums[mid+1];
        if(nums[mid] > nums[low]) return findInRange(nums, mid+1, high);
        else return findInRange(nums, low, mid);
    }
};
