// 题目很简单， 就是一定要注意， 数组的 () 初始化和 {} 初始化出来的结果完全不同
// vector<int>(0,0) 表示用 0 个 0 初始化数组
// vector<int>{0,0} 表示用 2 个 0 初始化数组
#include <queue>
#include <vector>

using std::queue;
using std::vector;
vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter)
{
    vector<vector<bool>> checked(rows, vector<bool>(cols, false));
    queue<vector<int>> curr {};
    vector<vector<int>> neighbors { { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, -1 } };
    curr.push(vector<int> { rCenter, cCenter });
    checked[rCenter][cCenter] = true;
    vector<vector<int>> res {};
    while (!curr.empty()) {
        auto front = curr.front();
        res.push_back(front);
        for (const auto& elem : neighbors) {
            int x = front[0] + elem[0];
            int y = front[1] + elem[1];
            if (x >= 0 && y >= 0 && x < rows && y < cols && !checked[x][y]) {
                checked[x][y] = true;
                curr.push(vector<int> { x, y });
            }
        }
        curr.pop();
    }
    return res;
}
