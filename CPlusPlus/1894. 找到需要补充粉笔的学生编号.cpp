// 前缀和 + 二分查找： 注意题目的规模， 使用 Int 会溢出
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        vector<long long> prefix{};
        for(auto& e : chalk){
            sum = (long long)e + sum;
            prefix.push_back(sum);
        }
        auto total = prefix.back();
        k = k % total;
        return upper_bound(prefix.begin(), prefix.end(),k) - prefix.begin();
    }
// 也可以使用自己写的二分查找
private:
    int binary_search(vector<long long> nums, int target){
        int low = 0; 
        int high = nums.size() - 1;
        while(low < high){
            int mid = (low + high)/2;
            if(nums[mid] <= target){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};
