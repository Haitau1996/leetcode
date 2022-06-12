// 解法 1： 前缀和 + 二分 ， 需要特别注意， 后面的部分 l 超过了 nums.size() 后可能出现搜索到了边界依旧无法满足条件的情况。
#include <vector>

using namespace std;
class BinarySearch_Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        vector<long long> prefix { 0 };
        for (const auto& num : nums) {
            prefix.push_back(prefix.back() + num);
        }
        if (prefix.back() < target)
            return 0;
        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            int base = prefix[i];
            int l = i + 1;
            int r = nums.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (prefix[mid] - base >= target)
                    r = mid;
                else
                    l = mid + 1;
            }
            if (prefix[l] - base >= target)
                res = min(l - i, res);
        }
        return res;
    }
};
