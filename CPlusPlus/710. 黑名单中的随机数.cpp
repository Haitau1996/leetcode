/*
 * 做法 1： 思路很巧妙， 就是选从 [0, n-m-1] 中的数， 如果数字被 blocked 了就 map 到后面的数字上
  TODO:线段树实现
*/
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
	Solution(int n, vector<int>& b)
		: n(n)
	{
		sort(b.begin(), b.end());
		m = b.size();
		bs = unordered_set<int>(b.begin(), b.end());
		int curr = 0;
		int next = n - m;
		while (curr < m && b[curr] < n - m) {
			if (bs.find(next) != bs.end()) {
				next = get_next(next);
			}
			mapp[b[curr]] = next;
			++curr;
			++next;
		}
	}

	int pick()
	{
		int val = rand() % (n - m);
		if (bs.find(val) == bs.end())
			return val;
		return mapp[val];
	}

private:
	unordered_map<int, int> mapp;
	unordered_set<int> bs;
	int m;
	int n;
	int get_next(int next)
	{
		while (bs.find(next) != bs.end()) {
			++next;
		}
		return next;
	}
};
