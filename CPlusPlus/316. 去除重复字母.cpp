// 使用一个set 和单调栈记录已经压入结果的字母
// 使用一个哈希表记录每个字母出现的次数
// 需要注意两个点： 记录剩余的字母数量 && 记录已经在栈中的字符
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> mon_stk {};
        vector<int> cnt(26, 0);
        for (const auto& c : s) {
            cnt[c - 'a']++;
        }
        unordered_set<char> hash {};
        for (const auto& c : s) {
            if (hash.find(c) == hash.end()) {
                while (!mon_stk.empty() && mon_stk.top() >= c && cnt[mon_stk.top() - 'a'] != 0) {
                    hash.erase(mon_stk.top());
                    mon_stk.pop();
                }
                mon_stk.push(c);
                hash.insert(c);
            }
            cnt[c - 'a']--;
        }
        string res;
        while (!mon_stk.empty()) {
            res.push_back(mon_stk.top());
            mon_stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
