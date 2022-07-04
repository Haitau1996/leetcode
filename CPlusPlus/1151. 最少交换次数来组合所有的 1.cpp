// 滑动窗口， 如果一共有 n 个 1， 则对所有的 [left, left+n) 计数， 找到其中 1 最多的窗口
#include <iterator>
#include <vector>

using namespace std;
class Solution {
public:
	int minSwaps(vector<int>& data)
	{
		auto total = count(data.begin(), data.end(), 1);
		if (total <= 1)
			return 0;
		int res = total;
		auto left = data.begin();
		auto right = data.begin() + total;
		auto curr = count(left, right, 1);
		while (1) {
			res = min(res, (int)(total - curr));
			if (right == data.end())
				break;
			else {
				if (*left == 1)
					--curr;
				++left;
				if (*right == 1)
					++curr;
				++right;
			}
		}
		return res;
	}
};
