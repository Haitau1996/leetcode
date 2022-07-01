/*
 * 回溯， [l,r] 之间的结果， 是所有 i 为符号时候的 [l,i-1] [+|-|*] [i+1,r] 一同构成的
 * 需要注意的是， 左右边界和左右的结果命名容易重合
 */
#include <vector>
#include <cctype>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        return dfs(expression, 0, expression.size()-1);
    }
private:
    vector<int> dfs(string& s, int l, int r){
        if(r-l <= 1) return vector<int>{stoi(s.substr(l, r-l+1))};
        vector<int> res{};
        for(int i = l; i <= r; ++i){
            if(!isdigit(s[i])){
                auto lv = dfs(s,l, i-1);
                auto rv = dfs(s, i+1, r);
                for(const auto& a : lv){
                    for(const auto& b: rv){
                        if(s[i]=='+') res.push_back(a+b);
                        else if(s[i] == '-') res.push_back(a-b);
                        else res.push_back(a*b);
                    }
                }
            }
        }
        return res;
    }
};
