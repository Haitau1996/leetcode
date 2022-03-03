class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> max_in_each_row(grid.size(),0);
        vector<int> max_in_each_col(grid[0].size(),0);
        for(int i = 0; i < grid.size(); ++i){
            max_in_each_row[i]= *max_element(grid[i].begin(), grid[i].end());
        }
        for(int j = 0; j < grid[0].size(); ++j){
            max_in_each_col[j] = grid[0][j];
            for(int i = 0; i < grid.size(); i++){
                if(grid[i][j] > max_in_each_col[j]){
                    max_in_each_col[j] = grid[i][j];
                }
            }
        }
        int sum{0};
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                sum += (min(max_in_each_row[i],max_in_each_col[j]) - grid[i][j]);
            }
        }
        return sum;
    }
};