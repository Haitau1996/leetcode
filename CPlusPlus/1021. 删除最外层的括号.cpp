// 只需要使用一个 flag 记录当前的括号层次， 根据层级判断是否要将当前的字符串添加到结果中

#include <string>
using std::string;
class Solution {
public:
    string removeOuterParentheses(string s)
    {
        int curr_deepth = 0;
        string res {};
        for (const auto& c : s) {
            if (c == '(') {
                if (curr_deepth != 0) {
                    res.push_back(c);
                }
                ++curr_deepth;
            } else if (c == ')') {
                if (curr_deepth != 1) {
                    res.push_back(c);
                }
                --curr_deepth;
            }
        }
        return res;
    }
};
