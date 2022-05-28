// 典型的回溯题目， 就是需要记住剩余右边括号数量一定大于等于左边剩余括号数量
// 同时只有 l.r > 0 时候才能继续添加

#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        dfs(n, n);
        return res;
    }

private:
    string current {};
    vector<string> res {};
    void dfs(int l, int r)
    {
        if (l == 0 && r == 0) {
            res.push_back(current);
            return;
        }
        if (l > r) {
            return;
        }
        // 压入 左括号
        if (l > 0) {
            current.push_back('(');
            dfs(l - 1, r);
            current.pop_back();
        }
        // 压入 右括号
        if (r > 0) {
            current.push_back(')');
            dfs(l, r - 1);
            current.pop_back();
        }
    }
};
