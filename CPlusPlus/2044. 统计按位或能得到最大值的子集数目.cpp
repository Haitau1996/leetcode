// 一看长度小于 20， 直接dfs暴力枚举， 每步可以选择下标元素页可以跳过。
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        for (const auto& elem : nums) {
            base |= elem;
        }
        dfs(0, 0, nums);
        return res;
    }

private:
    int base { 0 };
    int res { 0 };
    void dfs(int index, int current, const vector<int>& nums)
    {
        if (current == base && index == nums.size()) {
            ++res;
            return;
        } else if (index >= nums.size()) {
            return;
        }
        // select current index
        dfs(index + 1, current | nums[index], nums);
        // ignore current index
        dfs(index + 1, current, nums);
    }
};
