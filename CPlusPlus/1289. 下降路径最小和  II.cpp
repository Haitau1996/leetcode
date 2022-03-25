lass Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(1 == n) return grid[0][0];
        int index_s = grid[0][0] < grid[0][1] ? 0 : 1;
        int index_m = grid[0][0] < grid[0][1] ? 1 : 0;
        for(int j = 2; j < n; ++j){
            if(grid[0][j] <= grid[0][index_s]){
                index_m = index_s;
                index_s = j;
            }
            else if(grid[0][j] < grid[0][index_m]){
                index_m = j;
            }
        }
        for(int i = 1; i < n; ++i){
            int last_s = index_s;
            int last_m = index_m;
            for(int j = 0; j < 2; ++j){
                if(j == last_s){
                    grid[i][j] += grid[i-1][last_m];
                }
                else{
                    grid[i][j] += grid[i-1][last_s];
                }
            }
            index_s = grid[i][0] < grid[i][1] ? 0 : 1;
            index_m = grid[i][0] < grid[i][1] ? 1 : 0;
            for(int j = 2; j < n; ++j){
                if(j == last_s){
                    grid[i][j] += grid[i-1][last_m];
                }
                else{
                    grid[i][j] += grid[i-1][last_s];
                }
                if(grid[i][j] <= grid[i][index_s]){
                    index_m = index_s;
                    index_s = j;
                }
                else if(grid[i][j] < grid[i][index_m]){
                    index_m = j;
                }
            }
        }
        return *min_element(grid.back().begin(), grid.back().end());
    }
};
