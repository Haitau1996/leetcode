#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int x = *max_element(nums.begin(), nums.end());
        int y = *min_element(nums.begin(), nums.end());
        return max(0,x-y-2*k);
    }
};
