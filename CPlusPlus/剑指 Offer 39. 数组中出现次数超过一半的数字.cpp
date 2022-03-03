/*
执行用时：16 ms, 在所有 C++ 提交中击败了68.40% 的用户
内存消耗：18.2 MB, 在所有 C++ 提交中击败了91.16% 的用户
* 这个解法利用了数组的性质， 引入一个计数最后大于零那个肯定就是想要的结果
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result= nums[0];
        int times = 1;
        for(auto i = 1; i < nums.size(); ++i){
            if(times == 0){
                result = nums[i];
                times = 1;
            }
            else{
                if(nums[i] == result) ++times;
                else --times;
            }
        }
        return result;
    }
};