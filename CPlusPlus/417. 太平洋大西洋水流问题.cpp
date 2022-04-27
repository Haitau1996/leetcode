// 多源 bfs
// 时间复杂度: O(n*n)
#include <queue>
#include <utility>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        queue<pair<int, int>> todo {};
        vector<vector<int>> neighbors { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        for (int i = 0; i < m; ++i) {
            atlantic[i][n - 1] = true;
            todo.push(make_pair(i, n - 1));
        }
        for (int j = 0; j < n - 1; ++j) {
            atlantic[m - 1][j] = true;
            todo.push(make_pair(m - 1, j));
        }
        while (!todo.empty()) {
            auto front = todo.front();
            todo.pop();
            for (const auto& elem : neighbors) {
                int x = front.first + elem[0];
                int y = front.second + elem[1];
                if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[front.first][front.second] && !atlantic[x][y]) {
                    atlantic[x][y] = true;
                    todo.push(make_pair(x, y));
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            pacific[i][0] = true;
            todo.push(make_pair(i, 0));
        }
        for (int j = 1; j < n; ++j) {
            pacific[0][j] = true;
            todo.push(make_pair(0, j));
        }
        while (!todo.empty()) {
            auto front = todo.front();
            todo.pop();
            for (const auto& elem : neighbors) {
                int x = front.first + elem[0];
                int y = front.second + elem[1];
                if (x >= 0 && x < m && y >= 0 && y < n && heights[x][y] >= heights[front.first][front.second] && !pacific[x][y]) {
                    pacific[x][y] = true;
                    todo.push(make_pair(x, y));
                }
            }
        }
        vector<vector<int>> res {};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (atlantic[i][j] && pacific[i][j]) {
                    res.push_back(vector<int> { i, j });
                }
            }
        }
        return res;
    }
};
