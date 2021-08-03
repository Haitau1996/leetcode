/*
执行用时：4 ms, 在所有 C++ 提交中击败了74.54% 的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了20.22% 的用户
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t m = obstacleGrid.size();
        size_t n = obstacleGrid[0].size();
        vector<vector<long long>> res(m,vector<long long>(n,0));
        for(size_t i = 0; i< n; ++i){
            if(obstacleGrid[0][i])
                break;
            res[0][i] = 1;
        }
        for(size_t i = 0; i < m; ++i){
            if(obstacleGrid[i][0])
               break; 
            res[i][0] = 1;    
        }
        for(size_t i = 1; i < m; ++i)
            for(size_t j = 1; j < n; ++j){
                if(!obstacleGrid[i][j])
                    res[i][j] = res[i-1][j] + res[i][j-1];
            }
        
        return res[m-1][n-1];
    }
};