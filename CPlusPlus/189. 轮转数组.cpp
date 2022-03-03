class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse_in_range(nums,0,nums.size()-1);
        reverse_in_range(nums,0,k-1);
        reverse_in_range(nums,k,nums.size()-1);
    }
private:
    void reverse_in_range(vector<int>& nums, int beg, int end){
        while(beg < end){
            swap(nums[beg],nums[end]);
            ++beg;
            --end;
        }
    }
};