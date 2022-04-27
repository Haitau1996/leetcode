// 简单的 BFS
#include <queue>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
    {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> can_stay(m, vector<bool>(n, false));
        queue<pair<int, int>> todo {};
        todo.push(make_pair(start[0], start[1]));
        while (!todo.empty()) {
            auto x = todo.front().first;
            auto y = todo.front().second;
            todo.pop();
            // check down
            int down = 0;
            while (x + down < m - 1 && maze[x + down + 1][y] != 1) {
                ++down;
            }
            if (!can_stay[x + down][y]) {
                can_stay[x + down][y] = true;
                todo.push(make_pair(x + down, y));
            }
            // check up
            int up = 0;
            while (x - up > 0 && maze[x - up - 1][y] != 1) {
                ++up;
            }
            if (!can_stay[x - up][y]) {
                can_stay[x - up][y] = true;
                todo.push(make_pair(x - up, y));
            }
            // check right
            int right = 0;
            while (y + right < n - 1 && maze[x][y + right + 1] != 1) {
                ++right;
            }
            if (!can_stay[x][y + right]) {
                can_stay[x][y + right] = true;
                todo.push(make_pair(x, y + right));
            }
            int left = 0;
            while (y - left > 0 && maze[x][y - left - 1] != 1) {
                ++left;
            }
            if (!can_stay[x][y - left]) {
                can_stay[x][y - left] = true;
                todo.push(make_pair(x, y - left));
            }
        }
        return can_stay[destination[0]][destination[1]];
    }
};
