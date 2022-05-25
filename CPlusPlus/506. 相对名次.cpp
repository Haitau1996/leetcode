#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        int n = score.size();
        vector<int> rank(n, 0);
        for (int i = 1; i < n; ++i) {
            rank[i] = i;
        }
        auto cmp = [&score](const int& a, const int& b) {
            return score[a] > score[b];
        };
        sort(rank.begin(), rank.end(), cmp);
        vector<string> res(n, "");
        for (int i = 0; i < n; ++i) {
            if (i == 0)
                res[rank[i]] += "Gold Medal";
            else if (i == 1)
                res[rank[i]] += "Silver Medal";
            else if (i == 2)
                res[rank[i]] += "Bronze Medal";
            else {
                res[rank[i]] += to_string(i + 1);
            }
        }
        return res;
    }
};
