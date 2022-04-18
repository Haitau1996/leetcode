class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = -1, b = -1; 
        int abk = -1;
        for(int i = 0; i < nums.size(); ++i){
            if(a == -1) a = i;
            else if(nums[i] <= nums[a]){
                if(b == -1) a = i;
                else if(abk == -1 || nums[i] < nums[abk])
                    abk = i;
                else if(nums[i] > nums[abk]){
                    b = i;
                    a = abk;
                }
            }else if(nums[i] > nums[a] && (b == -1 || nums[i] < nums[b])){
                b = i;
                if(abk != -1){
                    a = abk;
                    abk = -1;
                }
            }else if(b!= -1 && nums[i] > nums[b]){
                return true;
            }
        }
        return false;
    }
};
