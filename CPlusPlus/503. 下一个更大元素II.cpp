class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums)
    {
        size_t n = nums.size();
        vector<int> res(n, -1);
        stack<size_t> stk;
        for (size_t i = 0; i < 2 * n - 1; ++i) {
            while (!stk.empty() && nums[stk.top()] < nums[i % n]) {
                res[stk.top()] = nums[i%n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return res;
    }
};
