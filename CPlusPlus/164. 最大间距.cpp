/*
想法一： 使用超级大的桶来装数据
ERROR: 超出时间限制
*/
#include<vector>
#include<algorithm>

using namespace std;
class BFSolution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int max_elem = *max_element(nums.begin(), nums.end());
        int min_elem = *min_element(nums.begin(), nums.end());
        if(max_elem == min_elem) return 0;
        vector<bool> checklist(max_elem-min_elem+1,false);
        for(const auto& elem : nums){
            checklist[elem-min_elem] = true;
        }
        int res = 0;
        int local = 0;
        for(size_t i = 0; i< checklist.size(); ++i){
            if(checklist[i]) local = 0;
            else{
                ++local;
                if(local > res) res = local;
            }
        }
        return res+1;
    }
};
/*
  使用抽屉原理： 只用 n 个桶每个桶放一个 pair, 分别存放某个区间的最大值和最小值
  区间长度为 diff/n + 1, 只需要保证这个区间长度小于抽屉原理得到的差的最小值即可
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int max_elem = *max_element(nums.begin(), nums.end());
        int min_elem = *min_element(nums.begin(), nums.end());
        if(max_elem == min_elem) return 0;
        int sz = nums.size();
        int gap = (max_elem - min_elem)/sz + 1;
        pair<int,int> base{-1,-1};
        vector<pair<int,int>> dp(sz, base);
        for(const auto& elem : nums){
            int pos = (elem-min_elem)/gap;
            if(dp[pos].first == -1 || (dp[pos].first!= -1 && dp[pos].first > elem)){
                dp[pos].first = elem;
            }
            if(dp[pos].second == -1 || (dp[pos].first!= -1 && dp[pos].second <elem)){
                dp[pos].second = elem;
            }
        }
        int res{0};
        for(int i = 1; i < sz; ++i){
            if(dp[i].first == -1) {
                dp[i].first = dp[i-1].second;
                dp[i].second = dp[i-1].second;
            }
            else if(dp[i].first - dp[i-1].second > res){
                res = dp[i].first - dp[i-1].second;
            }
        }
        return res;
    }
};
