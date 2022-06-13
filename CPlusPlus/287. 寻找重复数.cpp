// 思路 1 ： 原地修改数组
// 思路 2 ： 二分查找， 不断计数， 看 res 在哪一半
#include<vector>

using namespace std;
class ModefyArray_Solution {
public:
    int findDuplicate(vector<int>& nums) {
        nums.push_back(0);
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == i){
                ++i;
            }else if(nums[i] < i){
                return nums[i];
            }else{
                int val = nums[i];
                if(val == nums[val]) return val;
                swap(nums[val], nums[i]);
            }
        }
        return -1;
    }
};

class BinarySearch_Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int beg = 1;
        int end = nums.size() - 1;
        while(beg < end){
            int mid = (beg + end)/2;
            auto count = count_in_range(nums,beg, mid);
            if(count >(mid-beg + 1)) end = mid;
            else beg = mid+1;
        }
        return beg;
    }
private:
    int count_in_range(vector<int>&nums, int start, int end){
        int result = 0;
        for(const auto& elem : nums){
            if(elem >=start &&elem <= end){
                ++result;
            }
        }
        return result;
    }
};
