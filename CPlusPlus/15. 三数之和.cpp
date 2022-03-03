class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size()<3)
            return vector<vector<int>>();
        std::sort(std::begin(nums),std::end(nums));
        for(auto i{std::begin(nums)}; i!=std::end(nums)-2;++i){
            auto j{i+1};
            auto k{std::end(nums)-1};
            while(j < k ){
                if((*i)+ (*j)+(*k) == 0){
                    res.insert(std::vector<int>{*i,*j,*k});
                    ++j;
                    --k;
                }
                else if((*i)+ (*j)+(*k) > 0){
                    --k;
                }
                else ++j;
            }
        }
        return vector<vector<int>>(res.begin(),res.end());
    }
private:
    set<vector<int>> res;
};