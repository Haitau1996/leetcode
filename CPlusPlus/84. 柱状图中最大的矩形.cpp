/*
 * 单调栈， 存放一个单调递增的栈存放下标， 然后扫描， 如果 h[i] < h[stk.top()], 说明以 stk.top() 为顶的矩形已经到了边界了
 * NOTE: 需要将 -1 先压入栈中
 */
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& h)
    {
        stack<int> mono_stk {};
        mono_stk.push(-1);
        int n = h.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            while (mono_stk.top() != -1 && h[mono_stk.top()] > h[i]) {
                int curr = h[mono_stk.top()];
                mono_stk.pop();
                int width = i - 1 - mono_stk.top();
                res = max(res, curr * width);
            }
            mono_stk.push(i);
        }
        while (mono_stk.top() != -1) {
            int curr = h[mono_stk.top()];
            mono_stk.pop();
            int width = n - mono_stk.top() - 1;
            res = max(res, curr * width);
        }
        return res;
    }
};
