/*
 * 自定义排序： 将长的字符串和长度相等时候较小的字符串放前面
 * 子序列问题使用 dp 求解
 */
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
	string findLongestWord(string s, vector<string>& dict)
	{
		auto cmp = [](const auto& a, const auto& b) {
			if (a.size() != b.size())
				return a.size() > b.size();
			else
				return a < b;
		};
		sort(dict.begin(), dict.end(), cmp);
		for (const auto& w : dict) {
			if (valid(s, w))
				return w;
		}
		return string("");
	}

private:
	bool valid(const string& s, const string& w)
	{
		if (w.size() > s.size())
			return false;
		int is = 0;
		int iw = 0;
		while (is < s.size() && iw < w.size()) {
			if (s[is] == w[iw]) {
				++is;
				++iw;
			} else {
				++is;
			}
		}
		return iw == w.size();
	}
};
