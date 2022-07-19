// dp[i][j] 表示 i,j 结尾的做大的正方形边长， 如果 matrix[i][j] == '1'
// dp[i][i] 为上方、左方、左上方三个元素的最小值加一
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		int edge = 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0')
					dp[i][j] = 0;
				else {
					int up = i == 0 ? 0 : dp[i - 1][j];
					int left = j == 0 ? 0 : dp[i][j - 1];
					int up_left = (i == 0 || j == 0) ? 0 : dp[i - 1][j - 1];
					dp[i][j] = min({ up, left, up_left }) + 1;
					edge = max(edge, dp[i][j]);
				}
			}
		}
		return edge * edge;
	}
};
