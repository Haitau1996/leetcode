/*
 * 暴力解法， O(n^3)
 * 划定窗口实现 o(n^2)： 因为 mid 和 right 可以朝着一个方向挪动
 * 二分查找 O(n^2 log n) 
*/
#include <vector>
#include <algorithm>

using namespace std;
class BruteForce_Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int beg = 0; 
        int end = nums.size()-1;
        int sum = 0;
        while(end > beg+1){
            int inner_beg = beg;
            while(inner_beg < end-1){
                int mid = inner_beg+1;
                while(mid < end && nums[inner_beg] + nums[mid] <= nums[end]){
                    ++mid;
                }
                sum += (end -mid);
                ++inner_beg;
            }
            --end;
        }
        return sum;
    }
};

class SlidingWindow_Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res{0};
        for(int i = 0; i < nums.size()-2; ++i){
            int mid = i+1;
            int right = mid + 1;
            while(right < nums.size()){
                while(mid < right && nums[i] + nums[mid] <= nums[right]){
                    ++mid;
                }
                res += right-mid;
                ++right;
            }
        }
        return res;
    }
};

class BinarySearch_Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res{0};
        int n = nums.size();
        for(int i = 0; i < nums.size()-2; ++i){
            for(int j = i+1; j < nums.size()-1; ++j){
                int k = binary_search(nums, nums[i]+nums[j]);
                if(k>j) res += (k - j-1);
            }
        }
        return res;
    }
private:
    int binary_search(vector<int>& nums, int val){
        int l = 0;
        int r = nums.size();
        while(l < r){
            int mid = (l + r)>>1;
            if(nums[mid] >= val){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};
