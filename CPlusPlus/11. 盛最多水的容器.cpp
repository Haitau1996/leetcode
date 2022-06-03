// 双指针， 挪动矮的那个
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int res { 0 };
        int left { 0 }, right { static_cast<int>(height.size() - 1) };
        while (left < right) {
            res = max(res, min(height[left], height[right]) * (right - left));
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }
        return res;
    }
};
