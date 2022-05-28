// 简单题， 就是使用一个栈保存 “（” 的下标， 有匹配的 “）”就弹出， 单独的 “）” 标记为无效
// 最后记得将剩下的 “(” 也标记为无效， 
#include <stack>
#include <string>

using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        size_t n = s.size();
        stack<int> index {};
        for (size_t i = 0; i < n; ++i) {
            if (s[i] == '(') {
                index.push(i);
            } else if (s[i] == ')') {
                if (index.empty()) {
                    s[i] = '0';
                } else {
                    index.pop();
                }
            }
        }
        while (!index.empty()) {
            s[index.top()] = '0';
            index.pop();
        }
        auto iter = remove(s.begin(), s.end(), '0');
        s.erase(iter, s.end());
        return s;
    }
};
