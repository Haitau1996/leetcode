/*
* 这个题目就是先求总体的和， 然后用指针从前往后挪
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long total_sum = std::accumulate(nums.begin(), nums.end(),0);
        long long partial_sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(partial_sum * 2 + nums[i] == total_sum) return i;
            else{
                partial_sum += nums[i];
            }
        }
        return -1;
    }
};