// DFS: 这里使用了 size_t ， 它是一定大于等于 0 的， 所有少了很多不必要的判断过程
// 同时对于搜索过的位置， 设置为 Null , 避免了记录路径的开销
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		if (board.size() == 0 || board[0].size() == 0 || word.length() == 0)
			return false;
		else {
			size_t chaIndex = 0;
			for (size_t i = 0; i < board.size(); ++i) {
				for (size_t j = 0; j < board[0].size(); ++j) {
					if (dfs(board, i, j, word, chaIndex)) {
						return true;
					}
				}
			}
			return false;
		}
	}
	bool dfs(vector<vector<char>>& board, size_t row, size_t col, const string& word, size_t chaIndex)
	{
		if (chaIndex == word.length())
			return true;
		if (row < board.size() && col < board[0].size() && board[row][col] == word[chaIndex]) {
			++chaIndex;
			char temp = board[row][col];
			board[row][col] = '\0';
			if (dfs(board, row, col - 1, word, chaIndex) || dfs(board, row, col + 1, word, chaIndex) || dfs(board, row - 1, col, word, chaIndex) || dfs(board, row + 1, col, word, chaIndex))
				return true;

			else {
				--chaIndex;
				board[row][col] = temp;
			}
		}
		return false;
	}
};
