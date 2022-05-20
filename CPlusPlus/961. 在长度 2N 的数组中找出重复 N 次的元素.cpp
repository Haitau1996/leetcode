// 因为除了相同的， 其他都是不同的， 所以只要找到两个相同的数即可
#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums)
    {
        int size = nums.size();
        int a = rand() % size;
        int b = rand() % size;
        while (a == b || nums[a] != nums[b]) {
            a = rand() % size;
            b = rand() % size;
        }
        return nums[a];
    }
};
