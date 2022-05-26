// 解法一： 暴力法,忽略
// 解法二： 哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> val_to_pos{};
        for(int i= 0; i < nums.size(); ++i){
            if(val_to_pos.find(target-nums[i])!=val_to_pos.end()){
                return vector<int>{val_to_pos[target-nums[i]],i};
            }
            else{
                val_to_pos[nums[i]] = i;
            }
        }
        return vector<int>{};
    }
};
