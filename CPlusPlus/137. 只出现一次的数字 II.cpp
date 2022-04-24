// 写代码的时候细心一点， 变量名老是写错
#include<vector>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitCount(32,0);
        for(const auto& elem : nums){
            int n = 0;
            while(n < 32){
                if(elem & (0x1<<n)) bitCount[n]++;
                ++n;
            }
        }
        int res{0};
        for(int i = 0; i < 32; ++i){
            res += ((bitCount[i]%3)<<i);
        }
        return res;
    }
};
