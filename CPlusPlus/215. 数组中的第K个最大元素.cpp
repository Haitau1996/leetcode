// 使用排时候的分割， 找出第 nums.size() - k 小的元素
#include <vector>

using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k)
	{
		k = nums.size() - k;
		int low = 0, high = nums.size() - 1;
		int par = partition(nums, low, high);
		while (par != k) {
			if (par > k)
				high = par - 1;
			else
				low = par + 1;
			par = partition(nums, low, high);
		}
		return nums[k];
	}

private:
	int partition(vector<int>& nums, int low, int high)
	{
		int pivot = nums[low];
		while (low < high) {
			while (low < high && nums[high] >= pivot) {
				--high;
			}
			swap(nums[low], nums[high]);
			while (low < high && nums[low] <= pivot) {
				++low;
			}
			swap(nums[low], nums[high]);
		}
		nums[low] = pivot;
		return low;
	}
};
