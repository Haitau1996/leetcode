/*
执行用时：12 ms, 在所有 C++ 提交中击败了91.79% 的用户
内存消耗：19.1 MB, 在所有 C++ 提交中击败了50.47% 的用户
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int result;
        for(int i = 0; i < nums.size(); ++i){
            if(count == 0) {
                count++;
                result = nums[i];
            }
            else if(nums[i] == result) ++count;
            else{
                --count;
            }
        }
        return result;
    }
};