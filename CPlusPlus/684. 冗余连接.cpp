#include <vector>
using std::vector;
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges)
	{
		int edge_cnt = edges.size();
		id = vector<int>(edge_cnt + 1, 0);
		for (int i = 0; i < id.size(); ++i)
			id[i] = i;
		for (const auto& e : edges) {
			if (uni(e[0], e[1]))
				return e;
		}
		return vector<int> {};
	}

private:
	vector<int> id;
	int find(int p)
	{
		while (p != id[p])
			p = id[p];
		return p;
	}
	bool uni(int p, int q)
	{
		int pr = find(p);
		int qr = find(q);
		if (pr == qr)
			return true;
		id[pr] = qr;
		return false;
	}
};
