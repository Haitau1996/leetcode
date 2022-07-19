/*
比较少写 bfs 的题目， 有很大的优化空间， 基本的思路是这样的：
1. 使用两个队列 current, next， 先将 0 周围的非 0 点压入待处理的队列 current 中
2. 当待处理的队列不空，依次将其中点的值更新为 flag, 并将它周围未处理的点压入到 next 中准备在下一轮循环中处理
3. 待处理的队列空了之后， 将它和 swap 交换， 重复步骤 2
*/
class Solution {
	using mp = pair<int, int>;

public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
	{
		size_t m = mat.size();
		size_t n = mat[0].size();
		vector<vector<bool>> checked(m, vector<bool>(n, false));
		vector<vector<int>> neighbors { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		queue<mp> curr;
		int dist = 1;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (mat[i][j] == 0) {
					checked[i][j] = true;
					for (const auto next : neighbors) {
						int x = i + next[0];
						int y = j + next[1];
						if (x >= 0 && y >= 0 && x < m && y < n && !checked[x][y] && mat[x][y] == 1) {
							curr.emplace(x, y);
							checked[x][y] = true;
						}
					}
				}
			}
		}
		while (!curr.empty()) {
			int bound = curr.size();
			for (int i = 0; i < bound; ++i) {
				auto front = curr.front();
				mat[front.first][front.second] = dist;
				for (const auto& next : neighbors) {
					int x = front.first + next[0];
					int y = front.second + next[1];
					if (x >= 0 && y >= 0 && x < m && y < n && !checked[x][y] && mat[x][y] == 1) {
						curr.emplace(x, y);
						checked[x][y] = true;
					}
				}
				curr.pop();
			}
			++dist;
		}
		return mat;
	}
};
