// 解法 1： 使用 set 去重
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return vector<vector<int>>();
        std::sort(std::begin(nums),std::end(nums));
        for(auto i{std::begin(nums)}; i!=std::end(nums)-2;++i){
            auto j{i+1};
            auto k{std::end(nums)-1};
            while(j < k ){
                if((*i)+ (*j)+(*k) == 0){
                    res.insert(std::vector<int>{*i,*j,*k});
                    ++j;
                    --k;
                }
                else if((*i)+ (*j)+(*k) > 0){
                    --k;
                }
                else ++j;
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
private:
    set<vector<int>> res;
};
// 解法 2： 挪动指针的时候判断和前者是否相等， 相等则跳过
class BetterSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        int n = nums.size();
        for(int i = 0; i < n-2; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1;
            int right = n -1;
            while(left < right){
                if(left > i+1 && nums[left] == nums[left-1]){
                    ++left;
                }else if(right < nums.size()-1 && nums[right] == nums[right+1]){
                    --right;
                }else if(nums[left]+nums[right]+nums[i] > 0){
                    --right;
                }else if(nums[left]+nums[right]+ nums[i] == 0){
                    res.emplace_back(vector<int>{nums[i],nums[left],nums[right]});
                    ++left;
                    --right;
                }else{
                    ++left;
                }
            }
        }
        return res;
    }
};
