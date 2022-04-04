/*
 * 子数组和字符串的子序列的区别在于，在默认情况下， 前者要连续， 而后者默认可以不连续
 */
#include <vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int result = 0;
        int sz1= nums1.size();
        int sz2= nums2.size();
        vector<vector<int>> dp(sz1, vector<int>(sz2,0));
        for(int i = 0; i < sz1; ++i){
            for(int j = 0; j < sz2; ++j){
                if(nums1[i] == nums2[j]){
                    int last = (i == 0 || j==0) ? 0 : dp[i-1][j-1];
                    dp[i][j] = last + 1;
                    if(last + 1 > result) result = last + 1;
                }
            }
        }
        return result;
    }
};
