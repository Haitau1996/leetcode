class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        auto pos_iter = lower_bound(nums.begin(), nums.end(),0);
        auto pos = distance(nums.begin(), pos_iter);
        for(int i = 0; i < pos; ++i){
            nums[i] = -nums[i];
        }
        reverse(nums,0, pos-1);
        auto first = 0;
        auto second = pos;
        vector<int> result{};
        while(first < pos && second < nums.size()){
            if(nums[first] > nums[second]){
                result.push_back(nums[second]);
                ++second;
            }
            else{
                result.push_back(nums[first]);
                ++first;
            }
        }
        int beg{};
        int end{};
        if(first == pos){
            beg = second;
            end = nums.size();
        }
        else{
            beg = first;
            end = pos;
        }
        for(int i = beg; i < end; ++i){
            result.push_back(nums[i]);
        }
        for_each(result.begin(), result.end(), [](int& n){ n*=n;});
        return result;
    }
private:
    void reverse(vector<int>& nums, int low, int high){
        while(low  < high){
            swap(nums[low],nums[high]);
            ++low;
            --high;
        }
    }
};