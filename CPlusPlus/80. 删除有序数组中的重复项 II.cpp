/*
* 典型的双指针， 就是需要仔细考察一下终止条件
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cur = 0;
        int count = 0;
        int fast = cur + 2;
        while(cur + count < nums.size()){
            if(fast>= nums.size() || nums[fast] != nums[cur+count]){
                nums[cur] = nums[cur+count];
                ++cur;
                ++fast;
            }
            else{
                ++count;
                ++fast;
            }
        }
        return nums.size() - count;
    }
};