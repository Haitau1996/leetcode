class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        back_tracking(nums,0);
        return sum;
    }
private:
    int sum{};
    vector<int> selected{};
    void back_tracking(vector<int>& nums, int index){
        if(index == nums.size()) return;
        // selected:
        selected.push_back(nums[index]);
        sum += gen_xor();
        back_tracking(nums, index+1);
        selected.pop_back();
        back_tracking(nums, index+1);
    }
    int gen_xor(){
        if(selected.size() == 0) return 0;
        else{
            int first = selected[0];
            for(int i = 1; i <selected.size(); ++i){
                first^=selected[i];
            }
            return first;
        }
    }
};