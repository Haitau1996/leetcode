// 自己写的二分居然超时了
//
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int numSubseq(vector<int>& nums, int target)
    {
        pretreatment();
        sort(nums.begin(), nums.end());
        int res { 0 };
        const int N = nums.size();
        for (int i = 0; i < nums.size() && 2 * nums[i] <= target; ++i) {
            // auto dist = get_index(nums, i, N-1, target - nums[i]);
            // if(nums[dist]<= target - nums[i]) ++dist;
            auto dist = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            if (dist > i)
                res = (res + f[dist - i - 1]) % P;
        }
        return res;
    }

private:
    static constexpr int MAX_N = int(1E5) + 5;
    static const int P = 1000000007;
    int f[MAX_N];

    void pretreatment()
    {
        f[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            f[i] = (long long)f[i - 1] * 2 % P;
        }
    }
    int get_index(vector<int> nums, int low, int high, int target)
    {
        while (low < high) {
            int mid = (low + high) >> 1;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
