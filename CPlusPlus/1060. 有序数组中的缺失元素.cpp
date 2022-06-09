// 简单做法： 双指针

#include <vector>

using namespace std;
class SimpleSolution {
public:
    int missingElement(vector<int>& nums, int k)
    {
        int curr = nums[0];
        int i = 1;
        while (i <= nums.size() && k > 0) {
            if (i == nums.size() || nums[i] - curr > k) {
                return curr + k;
            } else {
                k -= (nums[i] - curr - 1);
                curr = nums[i];
                ++i;
            }
        }
        return -1;
    }
};
