/*
这个题目可以使用回溯， 但是因为没有要求找出所有的解,使用回溯可能会超时， 因此我们可以使用动态规划，使用一个长度为 s.size() 的数组做记忆， 第 i 位表示可以从字典构造 s 的子序列 s.substr(0,i):
*/
#include <string>
#include <unordered_set>
class DPSolution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> lookup(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n, false);
        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= 20 && i + 1 >= j; ++j){
                if((i+1-j == 0 || dp[i-j]) && lookup.find(s.substr(i+1-j,j))!= lookup.end()){
                    dp[i] = true;
                    break;
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
