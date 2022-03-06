class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> val_to_len{};
        int result{};
        for(const auto& elem : nums){
            if(val_to_len.find(elem) == val_to_len.end()){
                auto prev = val_to_len.find(elem-1);
                int prev_len = prev == val_to_len.end() ? 0 : prev->second;
                auto next = val_to_len.find(elem+1);
                int next_len = next == val_to_len.end() ? 0 : next->second;
                int current = prev_len + next_len + 1;
                val_to_len[elem] = current;
                val_to_len[elem-prev_len] = current;
                val_to_len[elem+next_len] = current;
                if(current > result) result = current;
            }     
        }
        return result;
    }
};