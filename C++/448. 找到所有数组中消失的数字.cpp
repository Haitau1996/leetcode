/*
执行用时：52 ms, 在所有 C++ 提交中击败了41.15% 的用户
内存消耗：33 MB, 在所有 C++ 提交中击败了40.45% 的用户
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index{};
        vector<int> result{};
        while(index < nums.size()){
            if(nums[index] == index+1 || nums[index]==0) ++index;
            else{
                int temp = nums[index];
                if(temp == 0) ++index;
                else if(nums[temp-1] == temp) {
                    nums[index] = 0 ;
                    ++index;
                }
                else {
                    nums[index] = nums[temp-1];
                    nums[temp-1] = temp;
                }
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0) result.push_back(i+1);
        }
        return result;
    }
};