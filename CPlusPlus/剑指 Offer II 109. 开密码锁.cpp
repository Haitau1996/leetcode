// 使用queue 的 size 函数可以不用维护两个队列
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;
class Solution {
public:
	int openLock(vector<string>& deadends, string target)
	{
		unordered_set<string> de(deadends.begin(), deadends.end());
		unordered_set<string> checked {};
		int curr = 0;
		queue<string> tocheck;
		string src("0000");
		if (de.find(src) == de.end()) {
			tocheck.emplace(src);
			checked.emplace(src);
		}
		while (!tocheck.empty()) {
			int cnt = tocheck.size();
			for (int i = 0; i < cnt; ++i) {
				if (tocheck.front() == target)
					return curr;
				for (int j = 0; j < 4; ++j) {
					string up(tocheck.front());
					string down(tocheck.front());
					up[j] = (up[j] - '0' + 1) % 10 + '0';
					down[j] = (down[j] - '0' + 9) % 10 + '0';
					if (de.find(up) == de.end() && checked.find(up) == checked.end()) {
						tocheck.push(up);
						checked.insert(up);
					}
					if (de.find(down) == de.end() && checked.find(down) == checked.end()) {
						tocheck.push(down);
						checked.insert(down);
					}
				}
				tocheck.pop();
			}
			++curr;
		}
		return -1;
	}
};
