class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j]) max = std::max(dfs(grid,i,j), max);
            }
        }
        return max;
    }
private:
    int dfs(vector<vector<int>>&grid, int i,int j){
        if(i < 0 || j < 0 || i >= grid.size() || j>= grid[0].size() || grid[i][j] == 0) return 0;
        int count = 1;
        grid[i][j] = 0;
        count = count + dfs(grid,i-1,j) + dfs(grid,i+1,j) + dfs(grid,i,j+1) + dfs(grid,i,j-1);
        return count;
    }
};