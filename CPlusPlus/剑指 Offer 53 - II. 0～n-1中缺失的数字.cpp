/* 二分法， 需要特别注意两点
 * 缺失的可能是最后一个数字
 * 数组的长度可能为 0
 */
#include <vector>

using std::vector;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = (low + high)>>1;
            if(nums[mid] == mid){
                low = mid +1;
            }else{
                high = mid;
            }
        }
        return nums[low] == low ? low+1 : low;
    }
};
