// 借助 queue::size(), 可以只使用一个 queue 做这类 BFS
#include <queue>
#include <utility>
#include <vector>

using namespace std;
class Solution {
	using mp = pair<int, int>;

public:
	void wallsAndGates(vector<vector<int>>& rooms)
	{
		int m = rooms.size();
		int n = rooms[0].size();
		bool checked[m][n];
		queue<mp> todo {};
		int curr = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (rooms[i][j] == -1)
					checked[i][j] = true;
				else if (rooms[i][j] == 0) {
					todo.push(mp(i, j));
					checked[i][j] = true;
				} else {
					checked[i][j] = false;
				}
			}
		}
		vector<vector<int>> next { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		while (!todo.empty()) {
			int sz = todo.size();
			for (int i = 0; i < sz; ++i) {
				auto fnt = todo.front();
				rooms[fnt.first][fnt.second] = curr;
				for (const auto& ne : next) {
					int x = fnt.first + ne[0];
					int y = fnt.second + ne[1];
					if (x >= 0 && x < m && y >= 0 && y < n && !checked[x][y]) {
						todo.push(mp(x, y));
						checked[x][y] = true;
					}
				}
				todo.pop();
			}
			++curr;
		}
	}
};
