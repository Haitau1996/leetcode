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
    vector<string> res;
    void dfs(int left, int right)
    {
        if (left == 0 && right == 0) {
            res.push_back(current);
            return;
        }
        if (left > 0) {
            current.push_back('(');
            dfs(left - 1, right);
            current.pop_back();
        }
        if (right > 0 && right > left) {
            current.push_back(')');
            dfs(left, right - 1);
            current.pop_back();
        }
    }
};
