class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        return binary_core(nums, low, high, target);
    }
private:
    bool binary_core(vector<int>& nums, int low, int high, int target){
        int mid = (low + high)/2;
        if(nums[mid] == target) return true;
        if(low >= high) return false;
        if(nums[mid] > nums[high])
            return binary_mono(nums, low, mid-1, target) || binary_core(nums, mid+1, high, target);
        else if(nums[mid] < nums[low]) 
            return binary_mono(nums, mid+1, high, target) || binary_core(nums, low, mid-1, target);
        else return binary_core(nums, low, mid-1, target) || binary_core(nums, mid+1, high, target);

    }
    bool binary_mono(vector<int>& nums, int low, int high, int target){
        while(low < high){
            if(target > nums[high] || target< nums[low]) return false;
            int mid = (low + high)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return nums[low] == target;
    }
};
