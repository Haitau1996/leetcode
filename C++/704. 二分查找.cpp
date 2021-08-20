class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(target < nums[0] || target>nums[nums.size()-1])
            return -1;
        return searchHelper(nums, 0, nums.size()-1, target);
    }
private:
    int searchHelper(vector<int>& nums, int low, int high, int target){
        if(low > high)
            return -1;
        if(low == high && nums[low]!= target) return -1;
        else{
            int mid = (low + high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]> target)
                return searchHelper(nums,low,mid-1, target);
            else 
                return searchHelper(nums,mid+1,high,target);
        }
    }
};