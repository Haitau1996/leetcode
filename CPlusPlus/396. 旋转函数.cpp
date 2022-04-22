/*
 我们要理解 F(k) 和 F(k-1) 的关系， 就是建立他们之间的递推函数, 假设所有 arr 元素和为 sum
$F(k) = F(k-1) + sum - arr_{k-1}[n-1] \times (n-1+1)$
因为两个最大的区别在于两点
1. $arr_{k-1}[n] \times(n-1)$ 变成了 0
2. 除了 $arr_{k-1}[n-1]$ 之外所有位置得因子都加了 1

因此我们将两者综合， 先所有元素的因子都加上 1，这时候就相差一个数 $arr_{k-1}[n] \times(n-1+1)$
*/
#include<vector>
#include<limits>
#include<numeric>

using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long res= numeric_limits<long>::min();
        long cur{0};
        long sum = accumulate(nums.begin(), nums.end(),0);
        vector<int> prefix(nums.size(), nums[0]);
        for(int i = 0; i < nums.size(); ++i){
            cur += i * nums[i];
        }
        if(cur > res) res = cur;
        for(int k = 1; k < nums.size(); ++k){
            cur = cur + sum - nums[nums.size()-k]* nums.size();
            if(cur > res) res = cur;
        }
        return res;
    }
};
