// 暴力枚举： 时间复杂度为 O(k^n) 超出时间限制
// 更好的解法： 状态压缩 dp
class BruteForceSolution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        AVG = sum / k;
        buffer = vector<int>(k, 0);
        return dfs(nums, 0, 0);
    }

private:
    int AVG {};
    vector<int> buffer;
    bool dfs(vector<int>& nums, int cursor, int k)
    {
        if (buffer[k] > AVG)
            return false;
        if (cursor == nums.size())
            return true;
        for (int i = 0; i < buffer.size(); ++i) {
            buffer[i] += nums[cursor];
            if (dfs(nums, cursor + 1, i))
                return true;
            buffer[i] -= nums[cursor];
        }
        return false;
    }
};
