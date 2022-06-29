/*
 * 记录每次跳变的位置， 然后逐渐扫描， 记录跳变位置的最大值
 * 最大值放在优先队列中， 具体而言是存的是结束位置和当前的高度
 * 如果结束位置小于等于当前的线， 则弹出
 */
#include <queue>
#include <vector>
using namespace std;
class Solution {
	using mp = pair<int, int>;

public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
	{
		vector<int> lines;
		for (const auto& b : buildings) {
			lines.emplace_back(b[0]);
			lines.emplace_back(b[1]);
		}
		sort(lines.begin(), lines.end());
		vector<vector<int>> res {};
		int n = buildings.size();
		int curr = 0;
		auto cmp = [](const mp& a, const mp& b) {
			return a.second < b.second;
		};
		priority_queue<mp, vector<mp>, decltype(cmp)> pq(cmp);
		for (const auto& l : lines) {
			while (curr < n && buildings[curr][0] <= l) {
				pq.emplace(mp(buildings[curr][1], buildings[curr][2]));
				++curr;
			}
			while (!pq.empty() && pq.top().first <= l) {
				pq.pop();
			}
			int currmax = pq.empty() ? 0 : pq.top().second;
			if (res.size() == 0 || currmax != res.back()[1]) {
				res.push_back(vector<int> { l, currmax });
			}
		}
		return res;
	}
};
