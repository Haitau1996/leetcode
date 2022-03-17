/*
思路 1 ： 遇到了 O 看广度优先搜索看是否被包围
57 / 58 个通过测试用例, 最后一个大的 case 超时了
思路 2: 使用 广度优先先标记没有被包围的 'O',然后修改
*/
#include <vector>
#include <queue>

using namespace std;
class Solution2 {
public:
    void solve(vector<vector<char>>& board) {
        m = static_cast<int>(board.size());
        n = static_cast<int>(board[0].size());
        for(int i = 0; i < m; ++i){
            if(board[i][0] == 'O') bfs(board, i, 0);
            if(board[i][n-1] == 'O') bfs(board, i, n-1);
        }
        for(int j = 0; j < n ; ++j){
            if(board[0][j] == 'O') bfs(board,0,j);
            if(board[m-1][j] == 'O') bfs(board, m-1,j);
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
private:
    int m;
    int n;
    void bfs(vector<vector<char>>& board, int x, int y){
        queue<vector<int>> to_handle{};
        vector<vector<int>> diffrence{{-1,0},{1,0},{0,1},{0,-1}};
        to_handle.push(vector<int>{x,y});
        board[x][y] = 'A';
        while(!to_handle.empty()){
            auto current = to_handle.front();
            to_handle.pop();
            for(const auto& elem : diffrence){
                int new_x = current[0]+elem[0];
                int new_y = current[1]+elem[1];
                if(new_x >=0 && new_x < m && new_y >= 0  && new_y < n && board[new_x][new_y] == 'O'){
                    to_handle.push(vector<int>{new_x,new_y});
                    board[new_x][new_y] = 'A';
                }
            }
        }
    }
};
