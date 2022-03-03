class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        for_each(nums.begin(), nums.end(),[](int& elem){
            if(elem == 0) elem = -1;
        });
        return subarraySum(nums,0);
    }
private:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sum_to_index;
        int current_sum = 0;
        sum_to_index.emplace(current_sum,-1);
        int max = 0;
        for(int i = 0; i < nums.size(); ++i){
            current_sum += nums[i];
            int diff = current_sum - k;
            if(sum_to_index.find(diff) != sum_to_index.end()){
                max = std::max(i - sum_to_index[diff],max);
            }
            if(sum_to_index.find(current_sum) == sum_to_index.end()){
                sum_to_index.emplace(current_sum, i);
            }
        }
        return max;
    }
};