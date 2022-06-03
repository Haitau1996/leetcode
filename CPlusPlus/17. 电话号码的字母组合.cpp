// 需要特别注意， 输入的结果可能为空
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> mp { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        if (digits.size() != 0)
            dfs(digits, 0, mp);
        return res;
    }

private:
    string selected {};
    vector<string> res {};
    void dfs(string& s, int cursor, vector<string>& mp)
    {
        if (cursor == s.size()) {
            res.push_back(selected);
            return;
        } else {
            for (const auto& c : mp[s[cursor] - '2']) {
                selected.push_back(c);
                dfs(s, cursor + 1, mp);
                selected.pop_back();
            }
        }
    };
};
