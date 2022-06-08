// 暴力枚举： 时间复杂度为 O(k^n) 超出时间限制
// 更好的解法： 状态压缩 dp
#include <numeric>
#include <vector>

using namespace std;
class BruteForceSolution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k)
            return false;
        buffer = vector<int>(k, sum / k);
        return dfs(nums, 0);
    }

private:
    vector<int> buffer;
    bool dfs(vector<int>& nums, int curr)
    {
        if (curr == nums.size())
            return true;
        for (auto& elem : buffer) {
            elem -= nums[curr];
            if (elem >= 0 && dfs(nums, curr + 1))
                return true;
            elem += nums[curr];
        }
        return false;
    }
};
