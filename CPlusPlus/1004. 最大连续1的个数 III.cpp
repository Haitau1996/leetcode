#include<vector>

using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int curr = 0;
        size_t left = 0;
        size_t right = 0;
        size_t res = 0;
        while(right <= nums.size()){
            if(curr <= k){
                if(right < nums.size() && nums[right] == 0) ++curr;
                ++right;
                if(curr <= k && right <= nums.size() && right - left > res){
                    res = right - left;
                }
            }
            else if(curr > k){
                if(nums[left] == 0) --curr;
                ++left;
            }
        }
        return res;
    }
};
