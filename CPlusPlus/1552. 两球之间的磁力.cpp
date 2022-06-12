// 二分查找： 距离的取值可以在 [1, max(array)-min(array)] 之间， 做二分查找即可
// 时间复杂度 O(log(max(array)-min(array)) * m log n)
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& position, int m)
    {
        sort(position.begin(), position.end());
        int left = 1;
        int right = position.back() - position.front();
        while (left < right) {
            int mid = (left + right + 1) >> 1;
            if (can_hold(position, mid, m))
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }

private:
    bool can_hold(vector<int>& position, int dist, int m)
    {
        int cnt = 1;
        int curr = 0;
        while (curr < position.size()) {
            curr = lower_bound(position.begin() + curr, position.end(), position[curr] + dist) - position.begin();
            if (curr < position.size())
                ++cnt;
            if (cnt >= m)
                return true;
        }
        return false;
    }
};
