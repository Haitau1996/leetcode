/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.5 MB, 在所有 C++ 提交中击败了7.76% 的用户
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        vector<vector<int>>res(m, vector<int>(n,0));
        for(int i = 0; i< n; ++i)
            res[0][i] = 1;
        for(int i = 0; i < m; ++i)
            res[i][0] = 1;
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                res[i][j] = res[i-1][j] + res[i][j-1];
        return res[m-1][n-1];
    }
};