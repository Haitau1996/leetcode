#include <limits>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int curr = 0;
		int res = numeric_limits<int>::min();
		for (const auto val : nums) {
			curr += val;
			res = max(curr, res);
			if (curr < 0)
				curr = 0;
		}
		return res;
	}
};
