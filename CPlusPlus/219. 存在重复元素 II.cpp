// brute force : 超出时间限制
#include<vector>
#include<unordered_set>

using namespace std;
class BFSolution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(size_t i = 0; i < nums.size(); ++i){
            for(size_t j = 1; static_cast<int>(j) <= k && i+j < nums.size(); ++j){
                if(nums[i] == nums[i+j]) return true;
            }
        }
        return false;
    }
};
// 使用 hash table 优化
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> buffer;
		int sz = nums.size();
        for(int i = 0; i < sz; ++i){
            if(i <= k){
                if(buffer.find(nums[i]) != buffer.end())
                    return true;
                else buffer.emplace(nums[i]);
            }
            else{
                buffer.erase(nums[i-k-1]);
                if(buffer.find(nums[i]) != buffer.end())
                    return true;
                else buffer.emplace(nums[i]);
            }
        }
        return false;
    }
};
