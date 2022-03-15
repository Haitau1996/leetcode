class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool>> checked(grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;
        queue<vector<int>> to_check{};
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    to_check.push(vector<int>{i,j});
                    checked[i][j] = true;
                    i = grid.size();
                    j = grid[0].size();
                }
            }
        }
        vector<vector<int>> diff{{1,0},{-1,0},{0,1},{0,-1}};
        while(!to_check.empty()){
            vector<int> front = to_check.front();
            to_check.pop();
            for(const auto& elem : diff){
                int x = front[0] + elem[0];
                int y = front[1] + elem[1];
                if(x < 0 || x >= grid.size() || y < 0 || y >=grid[0].size() || grid[x][y] == 0) ++result;
                else if(!checked[x][y]){
                    to_check.push(vector<int>{x,y});
                    checked[x][y] = true;
                }
            }
        }
        return result;
    }
};