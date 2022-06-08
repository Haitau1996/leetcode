// 注意 ！和 == 的优先级顺序， 要用括号把后面的 == 表达式包起来
// 人麻了， 可以直接用 != 
#include <vector>

using namespace std;
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        return ((points[1][1]-points[0][1])*(points[2][0]-points[1][0]) != (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]));
    }
};
