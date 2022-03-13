class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<vector<bool>> checked(grid.size(),vector<bool>(grid[0].size(), false));
        return bfs(grid, checked, 0,grid.size()-1);
    }
private:
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& checked, int beg, int end){
        queue<vector<int>> current;
        queue<vector<int>> next;
        int result = 1;
        vector<vector<int>> neighbors{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        if(grid[beg][beg] == 0){
            current.push(vector<int>{beg,beg});
            checked[beg][beg] = true;
        }
        vector<int> target{end,end};
        while(!current.empty()){
            while(!current.empty()){
                auto top = current.front();
                current.pop();
                if(top == target) return result;
                for(const auto& elem : neighbors){
                    int x = top[0] + elem[0];
                    int y = top[1] + elem[1];
                    if(x >= 0 && x < grid.size() && y >= 0 && y< grid[0].size() && !checked[x][y] && grid[x][y] == 0){
                        next.push(vector<int>{x,y});
                        checked[x][y] = true;
                    }
                }
            }
            result = result + 1;
            swap(current, next);
        }
        return -1;
    }
};