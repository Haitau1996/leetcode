/*
 * 回溯：首先找到要删除多少个括号， 然后挨个删除看是否符合预期
 * 注意去重， 如一串 )))), 我们优先删除前面的 ), 如果选择了第一个， 那么后几个就不能再跳过*/
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
	vector<string> removeInvalidParentheses(string s)
	{
		int n = s.size();
		int left = 0;
		int right = 0;
		for (const auto c : s) {
			if (c == '(') {
				++left;
			}
			if (c == ')') {
				if (left > 0)
					--left;
				else
					++right;
			}
		}
		dfs(s, left, right, 0);
		return res;
	}

private:
	string curr {};
	vector<string> res {};
	void dfs(string& s, int left, int right, int cursor)
	{
		if (cursor >= s.size()) {
			if (left == 0 && right == 0 && valid())
				res.push_back(curr);
			return;
		}
		// case 1: select element
		curr.push_back(s[cursor]);
		dfs(s, left, right, cursor + 1);
		curr.pop_back();
		// case 2: ignore current
		if (s[cursor] == '(' && left > 0 && (curr.size() == 0 || curr.back() != s[cursor])) {
			dfs(s, left - 1, right, cursor + 1);
		}
		if (s[cursor] == ')' && right > 0 && (curr.size() == 0 || curr.back() != s[cursor])) {
			dfs(s, left, right - 1, cursor + 1);
		}
	}
	bool valid()
	{
		int left = 0;
		for (const auto c : curr) {
			if (c == '(')
				++left;
			if (c == ')') {
				if (left == 0)
					return false;
				else
					--left;
			}
		}
		return left == 0;
	}
};
