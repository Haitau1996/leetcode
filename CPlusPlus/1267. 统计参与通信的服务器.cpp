class Solution {
public:
    int countServers(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[1].size();
        vector<int> mcount(m, 0);
        vector<int> ncount(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    mcount[i]++;
                    ncount[j]++;
                }
            }
        }
        int res {};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] && (mcount[i] > 1 || ncount[j] > 1)) {
                    ++res;
                }
            }
        }
        return res;
    }
};
