#include<vector>

using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = (low + high)/2;
            if(mid%2){
                if(nums[mid+1] == nums[mid]){
                    high = mid -1;
                }
                else if(nums[mid-1] == nums[mid]){
                    low = mid + 1;
                }else return nums[mid];
            }else{
                if(nums[mid+1] == nums[mid]){
                    low = mid+2;
                }else if(nums[mid-1]==nums[mid]){
                    high = mid-2;
                }else{
                    return nums[mid];
                }
            }
        }
        return nums[low];
    }
};
