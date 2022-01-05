/*
执行用时：4 ms, 在所有 C++ 提交中击败了93.31% 的用户
内存消耗：12.5 MB, 在所有 C++ 提交中击败了5.01% 的用户
* 需要注意这里的 lambda 闭包中只比较 a,b 是不够的， 如 “30” 和 “3”， 只比较 ab 得到的结果是 "330", 而我们需要 ”303”
*/
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> res;
        for(auto& elem:nums){
            res.push_back(to_string(elem));
        }
        std::sort(res.begin(), res.end(),[](string& a, string&b){ return a+b < b+a;});
        return std::accumulate(res.begin(),res.end(),string());
    }
};