/*
 * 二分查找， 使用数组的第 i 行预处理得到所有值为 i 的元素下标， 这样可以调用 upper_bound 在 log n 的时间内找到第一个大于 query 元素的位置
 */
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
	vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries)
	{
		vector<vector<int>> pre { 4, vector<int> {} };
		for (int i = 0; i < colors.size(); ++i) {
			pre[colors[i]].push_back(i);
		}
		vector<int> res;
		for (const auto& q : queries) {
			if (pre[q[1]].empty())
				res.push_back(-1);
			else {
				auto pos = upper_bound(pre[q[1]].begin(), pre[q[1]].end(), q[0]) - pre[q[1]].begin();
				if (pos == 0)
					res.push_back(pre[q[1]][pos] - q[0]);
				else if (pos == pre[q[1]].size())
					res.push_back(q[0] - pre[q[1]][pos - 1]);
				else
					res.push_back(min(pre[q[1]][pos] - q[0], q[0] - pre[q[1]][pos - 1]));
			}
		}
		return res;
	}
};
