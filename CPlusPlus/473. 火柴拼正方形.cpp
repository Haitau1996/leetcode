#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
    bool makesquare(vector<int>& matchsticks)
    {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4)
            return false;
        AVG = sum / 4;
        sort(matchsticks.begin(), matchsticks.end(), std::greater<int>());
        return dfs(matchsticks, 0);
    }

private:
    int AVG {};
    vector<int> curr_sum { 0, 0, 0, 0 };
    bool dfs(vector<int>& matchsticks, int cursor)
    {
        if (*max_element(curr_sum.begin(), curr_sum.end()) > AVG)
            return false;
        else if (cursor == matchsticks.size())
            return true;
        for (int i = 0; i < curr_sum.size(); ++i) {
            curr_sum[i] += matchsticks[cursor];
            if (dfs(matchsticks, cursor + 1))
                return true;
            curr_sum[i] -= matchsticks[cursor];
        }
        return false;
    }
};

class RecursiveSolution {
public:
    bool makesquare(vector<int>& matchsticks)
    {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4)
            return false;
        AVG = sum / 4;
        int size = matchsticks.size();
        vector<bool> selected(size, false);
        return dfs(matchsticks, selected, 0, 0);
    }

private:
    int AVG { 0 };
    vector<int> buffer { 0, 0, 0, 0 };
    bool dfs(vector<int>& matchsticks, vector<bool>& selected, int curr, int ptr)
    {
        if (curr >= 4)
            return true;
        if (buffer[curr] == AVG) {
            return dfs(matchsticks, selected, curr + 1, 0);
        } else if (buffer[curr] > AVG) {
            return false;
        } else if (ptr >= matchsticks.size()) {
            return false;
        }
        // select ptr
        if (!selected[ptr]) {
            selected[ptr] = true;
            buffer[curr] += matchsticks[ptr];
            if (dfs(matchsticks, selected, curr, ptr + 1))
                return true;
            buffer[curr] -= matchsticks[ptr];
            selected[ptr] = false;
        }
        // ignore ptr
        return dfs(matchsticks, selected, curr, ptr + 1);
    }
};
