#include <vector>

using namespace std;
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<int>> neighbors { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
        vector<vector<int>> status(m, vector<int>(n, 0));
        for (const auto& elem : guards)
            status[elem[0]][elem[1]] = 2;
        for (const auto& elem : walls)
            status[elem[0]][elem[1]] = 3;
        for (auto& elem : guards) {
            int x = elem[0];
            int y = elem[1];
            for (auto& nei : neighbors) {
                int xn = x + nei[0];
                int yn = y + nei[1];
                while (xn >= 0 && yn >= 0 && xn < m && yn < n && status[xn][yn] != 2 && status[xn][yn] != 3) {
                    status[xn][yn] = 1;
                    xn += nei[0];
                    yn += nei[1];
                }
            }
        }
        int res {};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (status[i][j] == 0)
                    ++res;
            }
        }
        return res;
    }
};
