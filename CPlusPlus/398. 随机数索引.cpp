#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    Solution(vector<int>& nums)
    {
        for (int i = 0; i < nums.size(); ++i) {
            temp.emplace(make_pair(nums[i], i));
        }
    }

    int pick(int target)
    {
        auto range = temp.equal_range(target);
        auto len = distance(range.first, range.second);
        int pos = rand() % len;
        auto iter = range.first;
        for (int i = 0; i < pos; ++i) {
            ++iter;
        }
        return iter->second;
    }

private:
    unordered_multimap<int, int> temp;
};
