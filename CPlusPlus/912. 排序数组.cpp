/*
 * 就是简单的 quick sort 实现
 todo: 实现 merge sort
*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
        return nums;
    }
private:
    int partition(vector<int>& nums, int low, int high){
        int rd = rand()%(high - low) + low;
        swap(nums[low], nums[rd]);
        int povit = nums[low];
        while(low < high){
            while(low < high && nums[high] >= povit){
                --high;
            }
            swap(nums[low], nums[high]);
            while(low < high && nums[low] <= povit){
                ++low;
            }
            swap(nums[low],nums[high]);
        }
        nums[low] = povit;
        return low;
    }
    void quick_sort(vector<int>& nums, int low, int high){
        if(low >= high) return;
        int mid = partition(nums,low, high);
        quick_sort(nums,low,mid-1);
        quick_sort(nums,mid+1,high);
    }
};