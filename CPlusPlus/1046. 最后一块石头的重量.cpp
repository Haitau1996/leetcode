#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() >= 2) {
            auto y = pq.top();
            pq.pop();
            auto x = pq.top();
            pq.pop();
            if (y > x)
                pq.push(y - x);
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
};
