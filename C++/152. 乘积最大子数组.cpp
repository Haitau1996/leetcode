class Solution {
public:
    int maxProduct(vector<int>& nums) {
        return Helper(nums,0,nums.size()-1);
    }
private:
    int Helper(vector<int>& nums, int beg, int end){
        if(end < beg) return 0;
        if(beg == end) return nums[beg];
        int pos_of_zero{};
        int index = beg;
        for(; index <= end; ++index){
            if(nums[index] == 0){
                pos_of_zero = index;
                break;
            }
        }
        if(index != (end+1)){
            return max({0, Helper(nums,beg,pos_of_zero-1), Helper(nums, pos_of_zero+1,end)});
        }
        int neg_count{};
        int result = 1;
        for(int i = beg; i <= end; ++i){
            result = result * nums[i];
        }
        if(result > 0 ) return result;
        else{
            int pre_result = result;
            for(int i = beg; i <= end; i++){
                if(pre_result > 0) break;
                else pre_result = pre_result/nums[i];
            }
            int post_result = result;
            for(int i = end; i >= beg; --i){
                if(post_result > 0) break;
                else post_result = post_result/nums[i];
            }
            return max(pre_result,post_result);
        }

    }
};