#include <vector>

using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p)
    {
        sort(p.begin(), p.end());
        int res = 0;
        int left = 0;
        int right = 0;
        while (left < p.size() && right < p.size()) {
            int bound = p[left][1];
            while (right < p.size() && p[right][0] <= bound) {
                bound = min(bound, p[right][1]);
                ++right;
            }
            ++res;
            left = right;
        }
        return res;
    }
};
