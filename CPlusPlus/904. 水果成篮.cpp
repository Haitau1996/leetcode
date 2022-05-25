#include <vector>

using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits)
    {
        int type_a { -1 };
        int type_b { -1 };
        int count_a { 0 };
        int count_b { 0 };
        int low = 0;
        int high = 0;
        int res { 0 };
        while (high < fruits.size()) {
            if (count_a + count_b > res)
                res = count_a + count_b;
            if (fruits[high] == type_a) {
                ++count_a;
                ++high;
            } else if (fruits[high] == type_b) {
                ++count_b;
                ++high;
            } else if (type_a == -1) {
                type_a = fruits[high];
                ++count_a;
                ++high;
            } else if (type_b == -1) {
                type_b = fruits[high];
                ++count_b;
                ++high;
            } else if (fruits[low] == type_a) {
                --count_a;
                ++low;
                if (count_a == 0)
                    type_a = -1;
            } else if (fruits[low] == type_b) {
                --count_b;
                ++low;
                if (count_b == 0)
                    type_b = -1;
            }
        }
        return max(res, high - low);
    }
};
