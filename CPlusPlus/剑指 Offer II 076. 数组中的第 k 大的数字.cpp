/*
* 比起之前的实现， 这里在 [low,high) 中随机使用了一个位置 和 low 交换， 这样在比较极端的情况下依旧可以保持好的时间性能
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int low = 0;
        int high = nums.size()-1;
        int mid = partition(nums,low,high);
        k = k - 1;
        while(mid != k){
            if(mid > k) {
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
            mid = partition(nums, low, high);
        }
        return nums[mid];
    }
private:
    void swap(vector<int>& nums, int low, int high){
        int temp = nums[low];
        nums[low] = nums[high];
        nums[high] = temp;
    }
    int partition(vector<int>& nums, int low, int high){
        if(low == high) return low;
        int pos = low + rand()%(high - low);
        swap(nums, low, pos);
        int provi = nums[low];
        while(low < high){
            while(low < high && nums[high] <= provi){
                --high;
            }
            swap(nums,low,high);
            while(low < high && nums[low] >= provi){
                ++low;
            }
            swap(nums,low,high);
        }
        nums[low] = provi;
        return low; 
    }
};