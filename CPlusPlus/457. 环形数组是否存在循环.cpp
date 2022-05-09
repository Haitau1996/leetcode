/*
 * 使用快慢指针
 */
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < nums.size(); ++i){
            int cnt = 0;
            int fast = get_next(nums,i);
            int slow = i;
            bool status = true;
            //if(nums[fast] * nums[slow] < 0) continue;
            while(cnt < nums.size() && fast != slow){
                if(nums[slow] * nums[get_next(nums,slow)] < 0) status = false;
                slow = get_next(nums,slow);
                fast = get_next(nums,fast);
                if(fast == slow) break;
                fast = get_next(nums,fast);
                ++cnt;
            }
            if(fast != slow || !status) continue;
            cnt = 1;
            fast = get_next(nums,slow);
            while(fast!=slow){
                if(nums[slow] * nums[fast] < 0) status = false;
                fast = get_next(nums,fast);
                ++cnt;
            }
            if(cnt > 1 && status) return true;
        }
        return false;
    }
private:
    int get_next(vector<int>& nums, int curr){
        if(nums[curr] > 0 ){
            return (curr+nums[curr])%nums.size();
        }
        else{
            int diff = (-nums[curr])%nums.size();
            if(diff <= curr){
                return curr-diff;
            }return curr+nums.size()-diff;
        }
    }
};
