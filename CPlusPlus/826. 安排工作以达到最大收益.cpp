// 双指针，记录当前难度可以完成的最大收益

#include <algorithm>
#include <map>
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        multimap<int, int> diff_to_prof {};
        int n = profit.size();
        for (int i = 0; i < n; ++i) {
            diff_to_prof.emplace(difficulty[i], profit[i]);
        }
        sort(worker.begin(), worker.end());
        int res = 0;
        auto iter = diff_to_prof.begin();
        int curr_max = 0;
        int curr = 0;
        while (curr < worker.size()) {
            while (iter != diff_to_prof.end() && iter->first <= worker[curr]) {
                curr_max = max(curr_max, iter->second);
                ++iter;
            }
            res += curr_max;
            ++curr;
        }
        return res;
    }
};
