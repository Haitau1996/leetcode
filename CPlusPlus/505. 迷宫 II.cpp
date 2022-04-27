#include <queue>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination)
    {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> can_reach(m, vector<int>(n, -1));
        queue<pair<int, int>> todo {};
        todo.push(make_pair(start[0], start[1]));
        can_reach[start[0]][start[1]] = 0;
        while (!todo.empty()) {
            auto x = todo.front().first;
            auto y = todo.front().second;
            todo.pop();
            int down = 0;
            while (x + down < m - 1 && maze[x + down + 1][y] != 1) {
                ++down;
            }
            if (can_reach[x + down][y] < 0 || (can_reach[x + down][y] > can_reach[x][y] + down)) {
                can_reach[x + down][y] = can_reach[x][y] + down;
                todo.push(make_pair(x + down, y));
            }
            int up = 0;
            while (x - up > 0 && maze[x - up - 1][y] != 1) {
                ++up;
            }
            if (can_reach[x - up][y] < 0 || can_reach[x - up][y] > can_reach[x][y] + up) {
                can_reach[x - up][y] = can_reach[x][y] + up;
                todo.push(make_pair(x - up, y));
            }
            int right = 0;
            while (y + right < n - 1 && maze[x][y + right + 1] != 1) {
                ++right;
            }
            if (can_reach[x][y + right] < 0 || can_reach[x][y + right] > can_reach[x][y] + right) {
                can_reach[x][y + right] = can_reach[x][y] + right;
                todo.push(make_pair(x, y + right));
            }
            int left = 0;
            while (y - left > 0 && maze[x][y - left - 1] != 1) {
                ++left;
            }
            if (can_reach[x][y - left] < 0 || can_reach[x][y - left] > can_reach[x][y] + left) {
                can_reach[x][y - left] = can_reach[x][y] + left;
                todo.push(make_pair(x, y - left));
            }
        }
        return can_reach[destination[0]][destination[1]];
    }
};
