class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        row = vector<vector<bool>>(9, vector<bool>(9,false));
        col = vector<vector<bool>>(9, vector<bool>(9,false));
        dia = vector<vector<bool>>(9, vector<bool>(9,false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] != '.') modefy(board,i,j);
            }
        }
        dfs(board, 0, 0);
    }
private:
    vector<vector<bool>> row;
    vector<vector<bool>> col;
    vector<vector<bool>> dia;
    void modefy(vector<vector<char>>& board, int i, int j){
        int val = board[i][j] - '1';
        row[i][val] = true;
        col[j][val] = true;
        dia[(i/3)*3 + j/3][val] = true;
    }
    bool check_status(int i, int j, int val){
        return row[i][val] == false && col[j][val] == false && dia[(i/3)*3 + j/3][val] == false;
    }
    void restore(int i, int j, int val){
        row[i][val] = false; 
        col[j][val] = false; 
        dia[(i/3)*3 + j/3][val] = false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j){
        if(i == board.size()) {
            return true;
        }
        int i_next;
        int j_next;
        if(j < 8){
            i_next = i;
            j_next = j+1;
        }else{
            i_next = i + 1;
            j_next = 0;
        }
        if(board[i][j] != '.') return dfs(board,i_next,j_next);
            for(int val = 0; val < 9; val++){
                if(check_status(i,j,val)){
                    board[i][j] = val + '1';
                    modefy(board,i,j);
                    if (dfs(board,i_next,j_next)) return true;
                    else{
                        board[i][j] = '.';
                        restore(i,j,val);
                    }
                }
            }
            return false;
    }
};