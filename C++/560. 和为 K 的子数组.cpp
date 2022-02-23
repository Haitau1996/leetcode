// 使用 multimap
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_multimap<int, int> sum_to_index;
        int current_sum = 0;
        sum_to_index.emplace(0,-1);
        int count = 0;
        for(int i = 0; i < nums.size(); ++i){
            current_sum += nums[i];
            int diff = current_sum - k;
            auto range = sum_to_index.equal_range(diff);
            for(auto iter = range.first; iter != range.second; ++iter){
                    ++count;
            }
            sum_to_index.emplace(current_sum,i);
        }
        return count;
    }
};
// 使用 map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_to_count;
        int current_sum = 0;
        sum_to_count[0]++;
        int count = 0;
        for(int i = 0; i < nums.size(); ++i){
            current_sum += nums[i];
            int diff = current_sum - k;
            count = count + sum_to_count[diff];
            sum_to_count[current_sum]++;
        }
        return count;
    }
};