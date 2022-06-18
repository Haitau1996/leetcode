/* MergeSort 的应用， 先将 [low, mid],[mid+1, high] 之间排序并计数， 然后使用指针a,b指向 mid, high,让它们逐渐左移，
 * nums[b] >= nums[a], 左移 b, res 不变
 * 否则左移动 a, res+= b-mid, 因为这时候从 mid+1 到 b (包含 b位置) 的值都小于 nums[a]
 */
#include <vector>

using namespace std;
class Solution {
public:
	int reversePairs(vector<int>& nums)
	{
		backup = vector<int>(nums.size(), 0);
		merge_in_range(nums, 0, nums.size() - 1);
		return res;
	}

private:
	int res {};
	vector<int> backup;
	void merge_in_range(vector<int>& nums, int low, int high)
	{
		if (low >= high)
			return;
		int mid = (low + high) >> 1;
		merge_in_range(nums, low, mid);
		merge_in_range(nums, mid + 1, high);
		int a = mid;
		int b = high;
		int curr = high;
		while (a >= low && b > mid) {
			if (nums[b] >= nums[a]) {
				backup[curr--] = nums[b--];
			} else {
				res += b - mid;
				backup[curr--] = nums[a--];
			}
		}
		while (b > mid) {
			backup[curr--] = nums[b--];
		}
		while (a >= low) {
			backup[a--] = nums[curr--];
		}
		for (int i = low; i <= high; ++i) {
			nums[i] = backup[i];
		}
	}
};
