/*
和剑指Offer 面试题 3 很像， 区别在于重复数字比较多就需要分类讨论，为了方便我们在头部添加了一个0：
 * 如果 nums[i] 为 0 或者 i 就直接跳过
 * 设 i 处的值为 temp, temp 和 i 的大小有三种情况
        * case 1: temp 比 i 大， 如果两处的值不相等，我们可以将 temp 位置和 i 处的交换， 这样就设置好了 nums[temp] 处的值， 相等的话就将它们放入结果中并且设为 0(已经处理过)
        * case 2: temp 比 i 小， 那么看 nums[temp] 处是否有零值， 
            * 如果nums[temp] = temp, 而且 nums[i] 也为 temp, 说明出现两次， 将它设置为 0 并且放入结果中
            * 否则， 设置 nums[temp] 为 temp, 并且将 i 处的值设置为 0
    */
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        vector<int> res{};
        for(int i = 0; i < nums.size(); ){
            if(nums[i] == i || nums[i] == 0) ++i;
            else{
                int temp = nums[i];
                if(temp > i){
                    if(nums[temp] == nums[i]){
                        res.push_back(nums[i]);
                        nums[i] = 0;
                        nums[temp] = 0;
                        ++i;
                    }
                    else{
                        swap(nums[temp],nums[i]);
                    }
                }else{
                    if(nums[temp]!=0){
                        res.push_back(nums[temp]);
                        nums[i] = 0;
                        ++i;
                    }else{
                        nums[temp] = temp;
                        nums[i] = 0;
                        ++i;
                    }
                }
            }
        }
        return res;    
    }
};
/* 解法 2： 
 * 直接翻转对应位置的值， 如果它是负的话， 说明之前已经翻过一次了
 */
class BetterSolution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        for(int idx=0;idx<n;idx++){
            int val = abs(nums[idx])-1;
            if(nums[val] < 0){
                ret.push_back(val + 1);
            }
            else{
                nums[val] = -nums[val];
            }
        }
        return ret;
    }
};
