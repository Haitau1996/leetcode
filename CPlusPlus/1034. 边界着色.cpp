class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result(m, vector<int>(n,-1));
        const int KEY = grid[row][col];
        queue<pair<int,int>> to_handle{};
        to_handle.push(pair(row,col));
        vector<pair<int,int>> next{{-1,0},{1,0},{0,1},{0,-1}};
        while(!to_handle.empty()){
            auto front = to_handle.front();
            to_handle.pop();
            int count = 0;
            for(const auto & elem : next){
                int x = elem.first + front.first;
                int y = elem.second + front.second;
                if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == KEY){
                    count = count + 1;
                    if(result[x][y] == -1){
                        to_handle.push(pair(x,y));
                        result[x][y] = 0;
                    }
                }
            }
            if(count != 4){
                result[front.first][front.second] = color;
            }
            else{
                result[front.first][front.second] = KEY;
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(result[i][j] <= 0){
                    result[i][j] = grid[i][j];
                }
            }
        }
        return result;
    }
};
