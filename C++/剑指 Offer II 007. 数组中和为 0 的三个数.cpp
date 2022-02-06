/*
* 需要注意 size_t 的 0 - 1 等于  numeric_limits<size_t>::max(), 比所有的 Int 都大， 因此 size_t 做差的时候先转成 int
* 需要注意跳过元素相等的情况
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        std::sort(nums.begin(),nums.end());
        int beg = 0;        
        while(beg < len - 2){
            int temp = 0 - nums[beg];
            int mid = beg + 1;
            int end = len - 1;
            while(mid  < end){
                if(nums[mid] + nums[end] == temp){
                    result.push_back(vector<int>{nums[beg],nums[mid],nums[end]});
                    while(mid < end && nums[mid+1] == nums[mid]) ++mid;
                    while(mid < end && nums[end - 1] == nums[end]) --end;
                    ++mid;
                    --end;
                }
                else if(nums[mid] + nums[end] > temp) --end;
                else ++mid;
            }
            while((beg < len -2) && nums[beg+1] == nums[beg]) ++beg;
            ++beg;
        }
        return result;
    }
};