class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int diff_max = 0;
        stack<int> min_element{};
        for(const auto elem : nums){
            while(!min_element.empty()&& min_element.top() >= elem){
                min_element.pop();
            }
            if(min_element.empty()) min_element.push(elem);
            else diff_max = max(diff_max, elem - min_element.top());
        }
        return diff_max? diff_max : -1;
    } 
};