/*
执行用时：24 ms, 在所有 C++ 提交中击败了60.77% 的用户
内存消耗：18.9 MB, 在所有 C++ 提交中击败了37.39% 的用户
*/
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> col(9, false);
        vector<vector<bool>> record(27,col);
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size();++j){
                if(board[i][j] == '.') continue;
                int index = board[i][j] - '1';
                if(record[i][index])
                    return false;
                record[i][index] = true;
                if(record[j+9][index])
                    return false;
                record[j+9][index] = true;
                if(record[18+ (int)(i/3)*3 +(int)(j/3)][index])
                    return false;
                record[18+ (int)(i/3)*3 +(int)(j/3)][index] = true;
            }
        }
        return true;
    }
};