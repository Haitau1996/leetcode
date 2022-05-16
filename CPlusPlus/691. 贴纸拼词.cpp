// 暴力递归： 超出时间限制
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
class BFSolution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        unordered_set<string> s(stickers.begin(), stickers.end());
        if(s.find(target)!= s.end()) return 1;
        else{
            for(int i = 1; i < target.size(); ++i){
                if(s.find(target.substr(0,i))!=s.end() && s.find(target.substr(i,n-i))!=s.end()){
                    return 2;
                }
            }
        }
        vector<bool> has(26,false);
        want = vector<int>(26,0);
        selected = want;
        lookup = vector<vector<int>>(n, vector<int>(26,0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < stickers[i].size(); ++j){
                lookup[i][stickers[i][j]-'a']= lookup[i][stickers[i][j]-'a']+1;
                has[stickers[i][j]-'a'] = true;
            }
        }
        for(int i = 0; i < target.size(); ++i){
            if(!has[target[i]-'a']) return -1;
            else want[target[i]-'a']++;
        }
        return dfs(0,target.size());
    }
private:
    vector<int> want{};
    vector<int> selected{};
    vector<vector<int>> lookup{};
    void add(int curr){
        for(int i = 0; i < 26; ++i){
            selected[i] += lookup[curr][i]; 
        }
    }
    void minus(int curr){
        for(int i = 0; i < 26; ++i){
            selected[i] -= lookup[curr][i];
        }
    }
    bool valid(int curr){
        for(int i = 0; i < 26; ++i){
            if(lookup[curr][i] > 0 && selected[i] < want[i])
                return true;
        }
        return false;
    }
    bool base_case(){
        for(int i = 0; i < 26; ++i){
            if(selected[i] < want[i]){
                return false;
            }
        }
        return true;
    }
    int dfs(int curr, int max){
        if(curr>max) return max;
        if(base_case()) return 0;
        else{
            int min = max;
            for(int i = 0; i < lookup.size(); ++i){
                if(valid(i)){
                    add(i);
                    int temp = dfs(curr+1, max);
                    if(temp < min) min = temp;
                    minus(i);
                }
            }
            return min+1;
        }
    }
};
// 使用动态规划： 因为target 的长度小于 15， 它的所有状态都可以放入一个整数中
// 共有 2^m 次方种可能性，如果某个位置已经构造好，就设置为 1， 否则为 0
// 于是我们需要建立状态 a：1111001 和状态b:0000001 之间的关系
// 使用动态规划
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        m = target.size();
        teg = target;
        vector<int> dp(1<<m, -1);
        dp[0] = 0;
        int res = helper((1<<m)-1,dp,stickers);
        return res>m? -1: res;
    }
private:
    int m{};
    string teg{};
    int helper(int mask, vector<int>&dp,vector<string>& ss){
        if(dp[mask]!=-1){
            return dp[mask];
        }
        dp[mask] = m+1;
        for(auto& s:ss){
            int left = mask;
            vector<int> cnt(26,0);
            for(const auto& c: s){
                cnt[c-'a']++;
            }
            for(int i =0; i < m; ++i){
                if(((mask >> i) & 1) && cnt[teg[i]-'a']>0){
                    cnt[teg[i]-'a']--;
                    left^= (1<<i);
                }
            }
            if(left < mask){
                dp[mask] = min(dp[mask], helper(left, dp, ss) +1);
            }
        }
        return dp[mask];
    }
};
