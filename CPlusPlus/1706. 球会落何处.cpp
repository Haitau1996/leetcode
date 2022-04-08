class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<int> result{};
        for(int i = 0; i < n; ++i){
            result.push_back(dfs(0, i, grid));
        }
        return result;
    }
private:
    int m;
    int n;
    int dfs(int m_stat, int n_stat,vector<vector<int>>& grid){
        if(m_stat == m && (n_stat>=0 && n_stat < n))
            return n_stat;
        if(n_stat == 0 && grid[m_stat][0] == -1) return -1;
        else if(n_stat == (n-1) && grid[m_stat][n_stat] == 1) return -1;
        if(grid[m_stat][n_stat] == 1 && grid[m_stat][n_stat+1] == 1) return dfs(m_stat+1, n_stat+1, grid);
        else if(grid[m_stat][n_stat] == -1 && grid[m_stat][n_stat-1] == -1) return dfs(m_stat+1, n_stat-1, grid);
        else return -1; 
    }
};
