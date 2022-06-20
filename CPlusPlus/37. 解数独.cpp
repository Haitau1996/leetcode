/* 每个位置的每个数都试一下，如果不冲突则写入，否则回溯 */

#include <vector>
using std::vector;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        row_stat = vector<vector<bool>>(9, vector<bool>(9, false));
        col_stat = vector<vector<bool>>(9, vector<bool>(9, false));
        blk_stat = vector<vector<bool>>(9, vector<bool>(9, false));
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    row_stat[i][board[i][j] - '1'] = true;
                    col_stat[j][board[i][j] - '1'] = true;
                    blk_stat[(i/3)*3+j/3][board[i][j] - '1'] = true;
                }
            }
        }
        dfs(board,0,0);
    }
private:
    vector<vector<bool>> row_stat;
    vector<vector<bool>> col_stat;
    vector<vector<bool>> blk_stat;
    bool dfs(vector<vector<char>>& board,int i, int j){
        if(i == 9) return true;
        int i_n = i + (j+1)/9;
        int j_n = (j+1)%9;
        if(board[i][j] != '.') return dfs(board,i_n,j_n);
        for(int k = 1; k <= 9; ++k){
            if(!row_stat[i][k-1] && !col_stat[j][k-1] && !blk_stat[(i/3)*3+j/3][k-1]){
                board[i][j] = '0' + k;
                row_stat[i][k-1] = true;
                col_stat[j][k-1] = true;
                blk_stat[(i/3)*3+j/3][k-1] = true;
                if(dfs(board,i_n,j_n)) return true;
                // 别忘记将状态写回去
                board[i][j] = '.';
                row_stat[i][k-1] = false;
                col_stat[j][k-1] = false;
                blk_stat[(i/3)*3+j/3][k-1] = false;
            }
        }
        return false;
    }
};
