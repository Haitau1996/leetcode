#include <queue>
#include <utility>
#include <vector>

using namespace std;
class Solution {
	using mp = pair<int, int>;

public:
	int minCostConnectPoints(vector<vector<int>>& points)
	{
		int n = points.size();
		idx = vector<int>(n, 0);
		for (int i = 0; i < n; ++i)
			idx[i] = i;
		deepth = vector<int>(n, 1);
		auto cmp = [&points](mp a, mp b) {
			return abs(points[a.first][0] - points[a.second][0]) + abs(points[a.first][1] - points[a.second][1]) > abs(points[b.first][0] - points[b.second][0]) + abs(points[b.first][1] - points[b.second][1]);
		};
		priority_queue<mp, vector<mp>, decltype(cmp)> pq(cmp);
		for (int i = 0; i < n - 1; ++i) {
			for (int j = i + 1; j < n; ++j) {
				pq.push(mp(i, j));
			}
		}
		int cnt = 0;
		int res = 0;
		while (cnt < n - 1) {
			auto p = pq.top().first;
			auto q = pq.top().second;
			if (unite(p, q)) {
				++cnt;
				res += (abs(points[p][0] - points[q][0]) + abs(points[p][1] - points[q][1]));
			}
			pq.pop();
		}
		return res;
	}

private:
	vector<int> idx {};
	vector<int> deepth {};
	int find(int i)
	{
		while (i != idx[i]) {
			i = idx[i];
		}
		return i;
	}
	bool unite(int p, int q)
	{
		int pr = find(p);
		int qr = find(q);
		if (pr == qr)
			return false;
		if (deepth[pr] == deepth[qr]) {
			idx[pr] = qr;
			deepth[qr]++;
		} else if (deepth[pr] > deepth[qr]) {
			idx[qr] = pr;
		} else {
			idx[pr] = qr;
		}
		return true;
	}
};
