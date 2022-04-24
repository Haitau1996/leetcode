// 简单题， 自己定义一个 lambda 表达式计算相对大小即可
// 需要注意的是， 两个次数相等的字符可能交错
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> hash;
        for(const auto& elem : s){
            hash[elem]++;
        }
        auto cmp = [&hash](const char& a, const char& b){
            if(hash[a] != hash[b])
                return hash[a] > hash[b];
            else return a > b;
        };
        sort(s.begin(), s.end(), cmp);
        return s;
    }
};
