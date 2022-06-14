// 二分法： 但是超出时间限制 58/58
// 最后发现是我实现的 get_val 太复杂， 本来只要 (n-1)/base, 硬是被我写成了一个递归实现
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while(l < r){
            int mid = l + ((r-l)>>1);
            int op_count = get_count(nums, mid);
            if(op_count <= maxOperations){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
private: 
    int get_count(vector<int>& nums, int val){
        int res{0};
        for(const auto& n : nums){
            res += get_val(n, val);
        }
        return res;
    }
    int get_val(int n, int base){
        return (n-1)/base;
        /* 我自己实现的 get_val, 十分丑陋
             if(n <= base){
                return 0;
            }
            int x = floor(log(n/base) / log(2));
            int main = static_cast<int>(pow(2,x)) - 1;
            int left = n - base * (int)(pow(2,x));
            return main + get_val(left, base) + (left == 0? 0 : 1);
            */

    }
};
