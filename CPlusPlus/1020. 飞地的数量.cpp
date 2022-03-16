#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[ 0 ].size());
        for(int i = 0; i < m; ++i){
            if(grid[i][0]) bfs(grid,i,0);
            if(grid[i][n-1]) bfs(grid, i, n-1);
        }
        for(int j = 0; j < n; ++j){
            if(grid[0][j]) bfs(grid,0,j);
            if(grid[m-1][j]) bfs(grid,m-1,j);
        }
        int result{};
        for(int i = 1; i < m-1; ++i){
            for(int j = 1; j < n-1; ++j){
                if(grid[i][j]) ++result;
            }
        }
        return result;
    }
private:
    void bfs(vector<vector<int>>& grid, int x, int y){
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[ 0 ].size());
        queue<vector<int>> to_handle{};
        to_handle.push(vector<int>{x,y});
        grid[x][y] = 0;
        vector<vector<int>> distances{{1,0},{-1,0},{0,1},{0,-1}};
        while(!to_handle.empty()){
            auto front = to_handle.front();
            to_handle.pop();
            for(const auto& diff : distances){
                int new_x = front[0] + diff[0];
                int new_y = front[1] + diff[1];
                if(new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && grid[new_x][new_y]){
                    to_handle.push(vector<int>{new_x,new_y});
                    grid[new_x][new_y] = 0;
                }
            }
        }
    }
};
