/*
 * 绝对值之差只能调一个， 那么就需要找到调整前后变化最大的那个
 * 可以通过排序+二分找到改变某个值之后的最小绝对值差， 那么只要挨个查找， 记录变化的最大值即可*/

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> abs_diff{};
        for(int i = 0; i < nums1.size(); ++i){
            abs_diff.push_back(abs(nums1[i] - nums2[i]));
        }
        sort(nums1.begin(), nums1.end());
        int max_diff{0};
        for(int i = 0; i < nums2.size(); ++i){
            auto idx = upper_bound(nums1.begin(), nums1.end(), nums2[i]) - nums1.begin();
            int temp_diff;
            if(idx == 0){
                temp_diff = nums1[idx] - nums2[i];
            }else if(idx == nums1.size()){
                temp_diff = nums2[i] - nums1[idx-1];
            }else{
                temp_diff = min(nums1[idx]- nums2[i], nums2[i] - nums1[idx-1]);
            }
            max_diff = max(max_diff, abs_diff[i] - temp_diff);
        }
        return (accumulate(abs_diff.begin(), abs_diff.end(), 0ll) - max_diff)%1000000007;
    }
};
