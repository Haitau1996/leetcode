/*
 * 我们维护两个数值， low, high 表示还没有使用过的最小值和最大值:
 *  s[current] 为 D 就插入最大值， 后续无论插入哪个数都下降
 *  s[current] 为 I 就插入最小值， 同样后面无论如何都是增加
 */
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> diStringMatch(string s)
    {
        int low = 0;
        int high = s.size();
        vector<int> res {};
        for (const auto& elem : s) {
            if (elem == 'I') {
                res.push_back(low);
                ++low;
            } else {
                res.push_back(high);
                --high;
            }
        }
        res.push_back(low);
        return res;
    }
};
