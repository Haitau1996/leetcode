#include <vector>

using namespace std;
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c)
    {
        double mid = -(static_cast<double>(b) / static_cast<double>(2 * a));
        int high = nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > mid) {
                high = i;
                break;
            }
        }
        auto f = [&a, &b, &c](const auto& x) {
            return a * x * x + b * x + c;
        };
        int low = high - 1;
        vector<int> res {};
        if (a != 0) {
            if (a < 0) {
                reverse(nums.begin(), nums.begin() + low + 1);
                reverse(nums.begin() + high, nums.end());
            }
            while (high < nums.size() || low >= 0) {
                if (low < 0 || (high < nums.size() && f(nums[high]) < f(nums[low]))) {
                    res.push_back(f(nums[high]));
                    ++high;
                } else {
                    res.push_back(f(nums[low]));
                    --low;
                }
            }
        } else {
            if (b < 0)
                reverse(nums.begin(), nums.end());
            for (const auto& elem : nums)
                res.push_back(f(elem));
        }
        return res;
    }
};
