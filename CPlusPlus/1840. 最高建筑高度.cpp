// 想法 1： 使用优先队列暴力求解，超出时间限制
// 改进想法： 我们无需处理每个高楼， 只需要处理 restrictions 中的边界
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
class BFSolution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions)
    {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        vector<int> dp(n + 1, -1);
        dp[1] = 0;
        pq.push(vector<int> { 1, 0 });
        for (const auto& elem : restrictions) {
            pq.push(elem);
            dp[elem[0]] = elem[1];
        }
        vector<int> neighbors { -1, 1 };
        while (!pq.empty()) {
            auto curr = pq.top();
            for (const auto& neigh : neighbors) {
                int x = neigh + curr[0];
                if (x > 1 && x <= n && (dp[x] == -1 || dp[x] > curr[1] + 1)) {
                    pq.push(vector<int> { x, curr[1] + 1 });
                    dp[x] = curr[1] + 1;
                }
            }
            pq.pop();
        }
        return *max_element(dp.begin() + 1, dp.end());
    }
};
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r)
    {
        r.emplace_back(vector<int> { 1, 0 });
        sort(r.begin(), r.end());
        r.emplace_back(vector<int> { n, n - 1 });
        for (int i = 0; i < r.size() - 1; ++i) {
            r[i + 1][1] = min(r[i + 1][1], r[i][1] + r[i + 1][0] - r[i][0]);
        }
        for (int i = r.size() - 1; i > 0; --i) {
            r[i - 1][1] = min(r[i - 1][1], r[i][1] + r[i][0] - r[i - 1][0]);
        }
        int res {};
        for (int i = 0; i < r.size() - 1; ++i) {
            res = max(res, r[i + 1][0] - r[i][0] + r[i + 1][1] + r[i][1]);
        }
        return res / 2;
    }
};
