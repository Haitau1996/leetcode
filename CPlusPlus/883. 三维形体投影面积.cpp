#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        int res { 0 };
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0)
                    ++res;
                if (grid[i][j] > row[i])
                    row[i] = grid[i][j];
                if (grid[i][j] > col[j])
                    col[j] = grid[i][j];
            }
        }
        res = accumulate(row.begin(), row.end(), res);
        res = accumulate(col.begin(), col.end(), res);
        return res;
    }
};
