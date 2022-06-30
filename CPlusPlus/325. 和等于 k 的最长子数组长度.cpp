/*
 * 前缀和 + 哈希， [i,j] 子数组长度为 i-j+1, 然后其和为 prefix[j] - prefix[i-1]
 */
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long, int> pre2idx;
        int res{0};
        long curr_sum = 0;
        pre2idx[0] = -1;
        for(int i = 0; i < nums.size(); ++i){
            curr_sum += nums[i];
            if(pre2idx.find(curr_sum - (long)k)!= pre2idx.end()){
                res = max(res, i - pre2idx[curr_sum-(long)k]);
            }
            if(pre2idx.find(curr_sum) == pre2idx.end()){
                pre2idx[curr_sum] = i;
            }
        }
        return res;
    }
};
