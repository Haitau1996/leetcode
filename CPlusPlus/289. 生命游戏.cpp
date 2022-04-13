class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> status(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int c = count(board, i, j);
                if(board[i][j] && (c == 2 || c == 3)){
                    status[i][j] = true;
                }
                if(!board[i][j] && c == 3){
                    status[i][j] = true;
                }
            }
        }
        for(int i = 0; i< m; ++i){
            for(int j = 0; j < n; ++j){
                if(status[i][j]) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
private:
    int m;
    int n;
    int count(vector<vector<int>>& board, int i, int j){
        int result = 0;
        for(int i_diff = -1; i_diff <=1; ++i_diff){
            for(int j_diff = -1; j_diff <= 1; ++j_diff){
                int new_i = i + i_diff;
                int new_j = j + j_diff;
                if(new_i>=0 && new_i <m && new_j>=0 && new_j<n && board[new_i][new_j]){
                    ++result;
                    if(i_diff==0&& j_diff==0) --result;
                }
            }
        }
        return result;
    }
};
