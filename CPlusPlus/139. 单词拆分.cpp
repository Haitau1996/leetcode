/*
这个题目可以使用回溯， 但是因为没有要求找出所有的解， 因此我们可以使用动态规划，使用一个长度为 s.size() + 1 的数组做记忆， 第 i+1 位表示可以从字典构造 s 的子序列 s.substr(0,i):
1. dp[0]表示构建一个空数组， 为 true
2. dp[i+1] 的求解， 如果能够找到一个数字j, 使得从[i-j]到[i] 这 j+1 个字符中， 且 dp[i-j] （实际对应 f(i-j-1)) 为 true, 那么dp[i+1] 就可以为 true
3. 我们要的结果就是 dp.back()
*/
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp (s.size()+1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j <= i && j < 20; j++){
                if(dict.find(s.substr(i-j, j+1)) != dict.end() && dp[i-j]){
                    dp[i+1] = true;
                }
            }
        }
        return dp.back();
    }
};

class BadSolution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, dict);
    }
private:
    bool dfs(const string&s, unordered_set<string>& dict){
        if(s.size() == 0) return true;
        for(int i = 1; i <=20 && i <= s.size(); ++i){
            if(dict.find(s.substr(0,i))!=dict.end()){
                if(dfs(s.substr(i,s.size()-i),dict))
                    return true;
            }
        }
        return false;
    }
};
