/*
* 没有别的， 就是需要特别注意全是 0 的情况
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> result;
        for(const auto& elem : nums){
            result.push_back(to_string(elem));
        }
        auto cmp = [](const string& first, const string& second){
            return first+second > second + first;
        };
        sort(result.begin(), result.end(),cmp);
        if(result.front() == "0") return "0";
        string result_str{};
        for(const auto& elem : result){
            result_str = result_str + elem;
        }
        return result_str;
    }
};