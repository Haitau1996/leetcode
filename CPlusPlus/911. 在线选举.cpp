// 这里需要预处理+ 二分查找
// 预处理的目的是找出某个时间点领先的候选人

#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times)
        : times(times)
    {
        unordered_map<int, int> cnt {};
        int curr_max = -1;
        int curr_p = -1;
        for (const auto& p : persons) {
            cnt[p]++;
            if (cnt[p] >= curr_max) {
                curr_p = p;
                curr_max = cnt[p];
            }
            top.push_back(curr_p);
        }
    }

    int q(int t)
    {
        auto idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return top[idx];
    }

private:
    vector<int> times;
    vector<int> top {};
};
