/*
 * 二分查找， 取一个值， 判断是否可以分到这么多，然后不断划分区间
 * 判断的时候使用贪心， 累计超过该值的块一共有多少个， 大于 k 即可
 */
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
	int maximizeSweetness(vector<int>& s, int k)
	{
		int left = 0;
		int right = accumulate(s.begin(), s.end(), 0)/(k+1);
		while (left < right) {
			int mid = (left + right + 1) >> 1;
			if (valid(s, k, mid)) {
				left = mid;
			} else {
				right = mid - 1;
			}
		}
		return left;
	}

private:
	bool valid(vector<int>& s, int k, int target)
	{
		int curr = 0;
		int cnt = 0;
		for (const auto& val : s) {
			curr += val;
			if (curr >= target) {
				++cnt;
				curr = 0;
			}
		}
		return cnt > k;
	}
};
