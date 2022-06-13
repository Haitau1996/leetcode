// 二分查找， 需要特别注意 hour = 2.0 这种整数并且和 nums.size()-1 接近的情况

#include <vector>

using namespace std;
class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        if (dist.size() - 1 > hour || abs(dist.size() - 1 - hour) < 0.001)
            return -1;
        int l = 1;
        int r = (int)1E9;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (valid_speed(dist, mid, hour))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

private:
    bool valid_speed(vector<int>& dist, int curr, double hour)
    {
        double time { 0.0 };
        for (int i = 0; i < dist.size() - 1; ++i) {
            time += (dist[i] + curr - 1) / curr;
        }
        time += (double)(dist.back()) / curr;
        return time <= hour;
    }
};
