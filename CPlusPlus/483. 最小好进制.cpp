/*
 * 需要找到n位数最长的 111111 表示
 * 对于长度为 len 的 x 进位值， 可以表示为 1 + x + x*x +...+ x^(len-1)
 * 固定了 len 之后对 x 做二分查找
 */
#include <cstddef>
#include <string>

using namespace std;
class Solution {
public:
	string smallestGoodBase(string n)
	{
		long long nll = stoll(n);
		long long res {};
		for (int len = ceil(log2(nll)); len >= 2; --len) {
			long long i = get_res(nll, len);
			if (i != -1) {
				res = i;
				break;
			}
		}
		return to_string(res);
	}

private:
	long long get_res(long long n, int len)
	{
		int m = len - 1;
		long long l = 2;
		long long r = n - 1;
		while (l < r) {
			long long mid = (l + r) >> 1;
			long long sum = 1;
			long long curr = 1;
			for (int i = 0; i < m; ++i) {
				if (sum > n || curr > n / mid) {
					sum = n + 1;
					break;
				}
				curr = curr * mid;
				sum += curr;
			}
			if (sum >= n)
				r = mid;
			else
				l = mid + 1;
		}
		long long sum = 1;
		long long curr = 1;
		for (int i = 0; i < m; ++i) {
			if (sum > n || curr > n / l)
				return -1;
			curr = curr * l;
			sum += curr;
		}
		if (sum == n)
			return l;
		return -1;
	}
};
