#include<vector>

using namespace std;
class Solution {
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
