#include<vector>

using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int biggest = nums[0];
        int bigger = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] >= biggest){
                bigger = biggest;
                biggest = nums[i];
            }else if(nums[i] > bigger){
                bigger = nums[i];
            }
        }
        return (biggest - 1)*(bigger -1);
    }
};
