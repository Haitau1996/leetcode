// sort + 双指针
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		int size = nums.size();
		int first = 0;
		vector<vector<int>> result {};
		while (first < size - 3) {
			int second = first + 1;
			while (second < size - 2) {
				int low = second + 1;
				int high = nums.size() - 1;
				while (low < high) {
					long long sum = (long long)nums[first] + (long long)nums[second] + (long long)nums[low] + (long long)nums[high];
					if (sum == target) {
						result.emplace_back(vector<int> { nums[first], nums[second], nums[low], nums[high] });
						while (low < high && nums[low + 1] == nums[low])
							++low;
						while (low < high && nums[high - 1] == nums[high])
							--high;
						++low;
						--high;
					} else if (sum < target)
						++low;
					else
						--high;
				}
				while (second < size - 2 && nums[second + 1] == nums[second])
					++second;
				++second;
			}
			while (first < size - 3 && nums[first + 1] == nums[first])
				++first;
			++first;
		}
		return result;
	}
};
