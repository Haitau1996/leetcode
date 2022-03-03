/*
执行用时：120 ms, 在所有 C++ 提交中击败了77.07% 的用户
内存消耗：81.1 MB, 在所有 C++ 提交中击败了32.28% 的用户
* 原地修改数组
* 考虑到有数字重合， 导致交换无法完成的特例
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(0);
        rearange(nums);
        for(auto i = 0; i < nums.size(); ++i){
            if(nums[i] != i) return i;
        }
        return nums.size();
    }
    void rearange(vector<int>& nums){
        int i = 0;
        while(i < nums.size()){
            if(nums[i] == 0 || nums[i] == i) ++i;
            else if(nums[i] < 0 || nums[i] >= nums.size()) {
                nums[i] = 0;
                ++i;
            }
            else{
                int temp = nums[i];
                if(nums[temp] == temp) nums[temp] = 0;
                else{
                    int tempi = nums[temp];
                    nums[temp] = temp;
                    nums[i] = tempi;
                }
            }
        }
    }
};