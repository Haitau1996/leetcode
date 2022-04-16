// 解法 1： 使用哈希表+暴力查找
// 50 / 53 个通过测试用例
#include<unordered_set>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
class BFSolution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_set<int> buffer;
        int sz = nums.size();
        for(int i = 0; i < sz; ++i){
            if(i <= k){
                for(auto iter = buffer.begin(); iter != buffer.end(); ++iter){
                    if(abs((long)*iter-(long)nums[i]) <= t) return true;
                }
                buffer.emplace(nums[i]);
            }
            else{
                buffer.erase(nums[i-k-1]);
                for(auto iter = buffer.begin(); iter != buffer.end(); ++iter){
                    if(abs((long)*iter-(long)nums[i]) <= t) return true;
                }
                buffer.emplace(nums[i]);
            }
        }
        return false;
    }
};
// 改进解法： 使用 lower_bound 和 upper_bound 限制迭代器的范围
// 使用 lower_bound 的时候最好使用有序的 set
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> buffer;
        int sz = nums.size();
        long smallest = *min_element(nums.begin(), nums.end());
        long largest = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < sz; ++i){
            if(i <= k){
                long lower = max(smallest, (long)nums[i] - t);
                long upper = min(largest, (long)nums[i] + t);
                auto lower_bound = buffer.lower_bound(lower);
                auto upper_bound = buffer.upper_bound(upper);
                for(auto iter = lower_bound; iter != upper_bound; ++iter){
                    if(abs((long)*iter-(long)nums[i]) <= t) return true;
                }
                buffer.emplace(nums[i]);
            }
            else{
                buffer.erase(nums[i-k-1]);
                long lower = max(smallest, (long)nums[i] - t);
                long upper = min(largest, (long)nums[i] + t);
                auto lower_bound = buffer.lower_bound(lower);
                auto upper_bound = buffer.upper_bound(upper);
                for(auto iter = lower_bound; iter != upper_bound; ++iter){
                    if(abs((long)*iter-(long)nums[i]) <= t) return true;
                }
                buffer.emplace(nums[i]);
            }
        }
        return false;
    }
};
