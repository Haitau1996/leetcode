/*
 * 简单的贪心
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> res { a, b, c };
        sort(res.begin(), res.end());
        int max_times = res[2] - res[0] - 2;
        int min_times { 2 };
        if (res[2] - res[0] == 2)
            min_times = 0;
        else {
            for (int i = 1; i < 3; ++i) {
                if (res[i] - res[i - 1] <= 2) {
                    min_times = 1;
                    break;
                }
            }
        }
        return vector<int> { min_times, max_times };
    }
};
