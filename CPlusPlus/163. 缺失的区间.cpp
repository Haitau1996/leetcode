class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if(nums.size() == 0){
            if(lower == upper) {
                res.push_back(to_string(lower));
            }
            else{
                string temp{};
                temp+=to_string(lower);
                temp+=("->");
                temp+=(to_string(upper));
                res.push_back(temp);
            }
            return res;
        }
        int cursor = 0;
        while(cursor < nums.size()){
            if(nums[cursor] == lower){
                ++lower;
                ++cursor;
            }else{
                if(nums[cursor] == lower+1){
                    res.push_back(to_string(lower));
                    ++lower;
                }else{
                    string temp{};
                    temp+=(to_string(lower));
                    temp+=("->");
                    temp+=to_string(nums[cursor]-1);
                    res.push_back(temp);
                    lower = nums[cursor];
                }
            }
        }
        if(nums.back()+1 == upper){
            res.push_back(to_string(upper));
        }else if(nums.back()+1 < upper){
            string temp{};
            temp+=to_string(nums.back()+1);
            temp+=("->");
            temp+= to_string(upper);
            res.push_back(temp);
        }
        return res;
    }
};
