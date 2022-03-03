class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int> res{};
        for(auto i:nums){
            auto fi=res.find(i);
            if(fi !=res.end() )
                res.erase(fi);
            else
                res.insert(i);        
        }
        return vector<int>(res.begin(),res.end());
    }
};