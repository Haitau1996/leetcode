// k 的取值范围为 1,*max_element(piles.begin(), piles.end())
// 在其中做二分法
// 时间复杂度：O(n*log k)
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while (low < high) {
            int mid = (low + high) >> 1;
            if (can_finish(piles, mid, h))
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

private:
    bool can_finish(vector<int>& piles, int curr, int h)
    {
        int count { 0 };
        for (const auto& pile : piles) {
            count += (pile + curr - 1) / curr;
        }
        return count <= h;
    }
};
