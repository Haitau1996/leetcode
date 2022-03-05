class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return dfs(nums);
    }
private:
    vector<vector<int>> dfs(vector<int> nums){
        if(nums.size() == 1) return vector<vector<int>>(1,nums);
        vector<vector<int>> to_return;
        for(int i = nums.size()-1; i >=0; --i){
            if(i != nums.size()-1  && nums[i] == nums[i+1]) ;
            else{
                auto temp = nums;
                temp.erase(temp.begin()+i);
                auto part = dfs(temp);
                for(auto& elem : part){
                    elem.push_back(nums[i]);
                    to_return.push_back(elem);
                }
            }
        }
        return to_return;
    }
};