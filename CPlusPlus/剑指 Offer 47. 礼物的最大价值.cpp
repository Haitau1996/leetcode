/*
执行用时：4 ms, 在所有 C++ 提交中击败了96.61% 的用户
内存消耗：9 MB, 在所有 C++ 提交中击败了56.01% 的用户
* 典型的动态规划题目
*/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        for(int i = 1; i <= grid[0].size()-1; ++i){
            grid[0][i] += grid[0][i-1];
        }
        for(int i = 1; i <= grid.size()-1; ++i){
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1; i <= grid.size()-1; ++i){
            for(int j = 1; j<= grid[0].size()-1; ++j){
                grid[i][j] += std::max(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};