class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for(int i = 0; i< grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] != 0){
                    auto new_size = dfs(grid,i,j);
                    if(new_size > max) max = new_size;
                }
            }
        }
        return max;
    }
private:
    int dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0){
            return 0;
        }
        int result = 1;
        grid[i][j] = 0;
        vector<vector<int>> maps{{1,0},{-1,0},{0,1},{0,-1}};
        for(const auto& elem: maps){
            int newi = i + elem[0];
            int newj = j + elem[1];
            result += dfs(grid, newi,newj);
        }
        return result;
    }
};