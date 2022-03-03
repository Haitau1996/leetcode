/*
执行用时：636 ms, 在所有 C++ 提交中击败了5.03% 的用户
内存消耗：47.3 MB, 在所有 C++ 提交中击败了9.69% 的用户
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<= 1) return true;
        vector<bool> can(nums.size(), false);
        for(int i = nums.size()-1; i >= 0; i--){
            for(int j = 1; j<= nums[i]; ++j){
                if(i+j+1 >= nums.size() || can[i+j] == true){
                    can[i] = true;
                    break;
                }
            }
        }
        return can[0];
    }
};