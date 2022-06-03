// 典型的二分查找， 因为要找第一个&&最后一个， 所以除了相等外还要判断前一个、后一个是否不相等
// 时间复杂度：O(logN)

#include <vector>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int low = find_first(nums, target);
        if (low == -1)
            return vector<int> { -1, -1 };
        else
            return vector<int> { low, find_last(nums, target) };
    }

private:
    int find_first(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int find_last(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target && (mid == nums.size() - 1 || nums[mid + 1] != target))
                return mid;
            else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
// 过去的做法是先找到相等的值， 然后两边挨个查找，在最坏的情况下需要遍历所有的数字
// O(N)的时间复杂度
class OtherSolution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int mid = findEqual(nums, target, 0, nums.size() - 1);
        if (mid == -1)
            return vector<int> { -1, -1 };
        else {
            int high = mid;
            while (high + 1 < nums.size() && nums[high + 1] == target)
                ++high;
            int low = mid;
            while (low > 0 && nums[low - 1] == target)
                --low;
            return vector<int> { low, high };
        }
    }

private:
    int findEqual(vector<int>& nums, int target, int low, int high)
    {
        if (low > high)
            return -1;
        int mid = (low + high) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return findEqual(nums, target, low, mid - 1);
        else
            return findEqual(nums, target, mid + 1, high);
    }
};
