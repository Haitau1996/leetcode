/*
执行用时：16 ms, 在所有 C++ 提交中击败了21.50% 的用户
内存消耗：9.3 MB, 在所有 C++ 提交中击败了12.39% 的用户
*/
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<string, int>> romanTable{{"M",1000},{"CM",900},{"D",500},{"CD",400},
                                             {"C",100},{"XC",90},{"L",50},{"XL",40},
                                             {"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
        string res{};
        for(const auto& item:romanTable){
            auto [key, value] = item;
            int times = num/value;
                for(auto i = 0; i < times; ++i){
                    res+= key;
                }
            num = num - times * value;
        }
        return res;
    }
};