#include <vector>

using namespace std;
class Solution {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges)
	{
		vector<bool> flag(n, true);
		for (const auto& e : edges) {
			flag[e[1]] = false;
		}
		vector<int> res {};
		for (int i = 0; i < n; ++i) {
			if (flag[i])
				res.push_back(i);
		}
		return res;
	}
};
