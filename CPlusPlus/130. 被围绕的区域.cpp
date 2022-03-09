/*
思路 1 ： 遇到了 O 看广度优先搜索看是否被包围
57 / 58 个通过测试用例, 最后一个大的 case 超时了
todo: 想办法降低时间复杂度
*/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> checked(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == 'X') checked[i][j] = true;
                else if(!checked[i][j] && board[i][j] == 'O'){
                    if(surround(board, checked, i, j)) board[i][j] = 'Y';
                    else board[i][j] = 'N';
                    checked[i][j] = true;
                }
            }
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == 'Y') board[i][j] = 'X';
                else if(board[i][j] == 'N') board[i][j] = 'O';
            }
        }
    }
private:
    bool surround(vector<vector<char>>& board, vector<vector<bool>> checked, int i, int j){
        queue<vector<int>> to_check;
        to_check.push(vector<int>{i,j});
        checked[i][j] = true;
        vector<vector<int>> diff{{1,0},{-1,0},{0,1},{0,-1}};
        while(!to_check.empty()){
            int current_i = to_check.front()[0];
            int current_j = to_check.front()[1];
            if(current_i == 0 || current_j == 0 || current_i == board.size()-1 || current_j == board[0].size() - 1) return false;
            else if(board[current_i][current_j] == 'Y') return true;
            else if(board[current_i][current_j] == 'N') return false;
            for(const auto& elem : diff){
                int next_i = current_i + elem[0];
                int next_j = current_j + elem[1];
                if(board[next_i][next_j] == 'O' && !checked[next_i][next_j]){
                    to_check.push(vector<int>{next_i,next_j});
                    checked[next_i][next_j] = true;
                }else if(board[next_i][next_j] == 'Y' || board[next_i][next_j] == 'N'){
                    to_check.push(vector<int>{next_i,next_j});
                }
            }
            to_check.pop();
        }
        return true;
    }
};
/*
思路2 ： 遇到了边上的 0 后广度优先， 将附近的点全部标记为 N
*/