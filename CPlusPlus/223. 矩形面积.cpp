#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int width_a = abs(ax1 - ax2);
        int height_a = abs(ay1 - ay2);
        int width_b = abs(bx1 - bx2);
        int height_b = abs(by1 - by2);
        int over_x = width_a + width_b - abs(max({ax1,ax2,bx1,bx2}) - min({ax1,ax2,bx1,bx2}));
        over_x = over_x > 0 ? over_x : 0;
        int over_y = height_a + height_b - abs(max({ay1,ay2,by1,by2}) - min({ay1,ay2,by1,by2}));
        over_y = over_y > 0 ? over_y : 0;
        return width_a * height_a + width_b * height_b - over_x * over_y;
    }
};
