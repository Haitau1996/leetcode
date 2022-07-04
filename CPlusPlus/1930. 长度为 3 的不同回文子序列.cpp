/*
 * 记录不同的字符的第一个和最后一个位置，然后对于 s 中第二个到倒数第二个字符， 判断是否在两者中间
 */
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
	int countPalindromicSubsequence(string s)
	{
		int n = s.size();
		int prev[26];
		memset(prev, -1, sizeof(prev));
		int post[26];
		memset(post, -1, sizeof(post));
		for (int i = 0; i < n; ++i)
			if (prev[s[i] - 'a'] == -1)
				prev[s[i] - 'a'] = i;
		for (int i = n - 1; i >= 0; --i)
			if (post[s[i] - 'a'] == -1)
				post[s[i] - 'a'] = i;
		vector<vector<bool>> mm(26, vector<bool>(26, false));
		int res {};
		for (int i = 1; i < n - 1; ++i) {
			int val = s[i] - 'a';
			for (int j = 0; j < 26; ++j) {
				if (!mm[val][j] && i > prev[j] && i < post[j]) {
					++res;
					mm[val][j] = true;
				}
			}
		}
		return res;
	}
};
