/*
我们使用一个数组(last_pos)记录每个字母最后一次出现的位置， 然后从前到后扫描数组， 变量说明
1. 保持变量 left 表示当前处理的部分起始位置
2. 使用变量 right 表示当前正在处理的光标位置
3. 使用变量 last 表示已经处理的字符最后出现的位置，

从前到后扫描
1. s[right] 最后出现的位置大于 last, 更新 last
2. right 值和 last 相等
    1. 向结果压入 right-left+1
    2. 更新 left, right 的值
*/
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> last_pos(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            last_pos[s[i] - 'a'] = i;
        }
        int l = 0;
        int r = 0;
        vector<int> res {};
        while (l < s.size()) {
            int last = last_pos[s[l] - 'a'];
            while (last != r) {
                last = max(last, last_pos[s[r] - 'a']);
                ++r;
            }
            res.push_back(r - l + 1);
            l = r + 1;
            r = l;
        }
        return res;
    }
};
