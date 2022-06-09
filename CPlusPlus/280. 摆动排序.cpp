// 将三个数字按照大小排列成 min, max, median, 然后将下标递增 2

#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    void wiggleSort(vector<int>& nums)
    {
        int i = 2;
        while (i < nums.size()) {
            sort(nums.begin() + i - 2, nums.begin() + i + 1);
            int max_val = nums[i];
            int mid_val = nums[i - 1];
            int min_val = nums[i - 2];
            nums[i] = mid_val;
            nums[i - 1] = max_val;
            nums[i - 2] = min_val;
            i += 2;
        }
        if (nums.size() % 2 == 0) {
            if (nums[nums.size() - 1] < nums[nums.size() - 2]) {
                swap(nums[nums.size() - 1], nums[nums.size() - 2]);
            }
        }
    }
};
