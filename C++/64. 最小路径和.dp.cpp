/*
执行用时：8 ms, 在所有 C++ 提交中击败了88.15% 的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了5.59% 的用户
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n,0));
        res[0][0] = grid[0][0];
        for(int i = 1; i< n; ++i)
            res[0][i] = res[0][i-1] + grid[0][i];
        for(int i = 1; i< m; ++i)
            res[i][0] = res[i-1][0] + grid[i][0];
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                res[i][j] = std::min(res[i-1][j],res[i][j-1]) + grid[i][j];
        return res[m-1][n-1];
    }
};