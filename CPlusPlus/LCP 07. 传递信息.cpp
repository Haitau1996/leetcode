#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k)
    {
        unordered_map<int, unordered_set<int>> nexts;
        for (const auto& elem : relation) {
            auto& src = elem[0];
            auto& dest = elem[1];
            if (nexts.find(src) == nexts.end()) {
                nexts.emplace(src, unordered_set<int>());
            }
            nexts[src].insert(dest);
        }
        queue<int> curr_que;
        queue<int> next_que;
        int curr = 1;
        for (const auto& elem : nexts[0]) {
            curr_que.push(elem);
        }
        int res {};
        while (!curr_que.empty() && curr <= k) {
            auto front = curr_que.front();
            if (curr == k && front == n - 1) {
                ++res;
            }
            if (curr < k) {
                for (const auto& elem : nexts[front]) {
                    next_que.push(elem);
                }
            }
            curr_que.pop();
            if (curr_que.empty()) {
                swap(curr_que, next_que);
                ++curr;
            }
        }
        return res;
    }
};
