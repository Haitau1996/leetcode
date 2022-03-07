/*
### 解题思路
典型的动态规划， 在进行每一步的时候， 根据前面的结果看是否可以匹配， f(i+1, j+1) 表示 p[0...i] 和 s[0..j] 可以匹配：
如 s = "acdccb", p = "\*a\*?b"
| null | null | a | c | d | c | c | b |
|:----:|:----:|:-:|:-:|:-:|:-:|:-:|:-:|
|null  |   1  | 0 | 0 | 0 | 0 | 0 | 0 |
|  *   |   1  | 1 | 1 | 1 | 1 | 1 | 1 |
|  a   |   0  | 1 | 0 | 0 | 0 | 0 | 0 |
|  *   |   0  | 1 | 1 | 1 | 1 | 1 | 1 |
|  ?   |   0  | 0 | 1 | 1 | 1 | 1 | 0 |
|  b   |   0  | 0 | 0 | 0 | 0 | 0 | 1 |

从上图可以看到几种个 case :
1.  如果 p[i] == '*', 那么在第 i 行找到一个为 true 的位置 j, 第 i + 1 行从 j 到最后都是 true
2.  如果 p[i] == '?', 那么在第 i 行找到任意一个为 true 的位位置 j, dp[i+1][j+1] 为 true
3.  如果 p[i] 为普通字母， 那么在第 只有找到第 i 行为 true 且位置j 且满足 p[i]==s[j], dp[i+1][j+1] 才能为 true
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(p.size()+1, vector<bool>(s.size()+1,false));
        dp[0][0] = true;
        int i = 0;
        int j = 0;
        for(int i = 0; i < p.size(); ++i){
            if(p[i]!='*'){
                for(int j = 0; j < s.size(); ++j){
                    if(dp[i][j] && (p[i] == s[j] || p[i] == '?')){
                        dp[i+1][j+1] = dp[i][j];
                    }
                }
            }
            else{
                int start = s.size()+1;
                for(int j = 0; j <= s.size(); ++j){
                    if(dp[i][j] && j < start){
                        start = j;
                    }
                }
                for(int j = start; j <= s.size(); ++j){
                    dp[i+1][j] = true;
                }
            }
        }
        return dp.back().back();
    }
};
/* 
递归实现： 超时了， 
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchStartFrom(s,0,p,0);
    }
private:
    bool isMatchStartFrom(string& s, int s_pos, string& p, int p_pos){
        if(s_pos == s.size() && p_pos == p.size()) return true;
        else if((s_pos >= s.size() && p[p_pos]!='*') || p_pos >= p.size()) return false;
        else if(s_pos >= s.size() && p[p_pos]=='*'){
            return isMatchStartFrom(s,s_pos,p,p_pos+1);
        }
        else if(s[s_pos] == p[p_pos] || p[p_pos] == '?'){
            return isMatchStartFrom(s,s_pos+1,p,p_pos+1);
        }else if(p[p_pos] == '*'){
            return isMatchStartFrom(s, s_pos,p, p_pos+1) ||
                   isMatchStartFrom(s, s_pos+1,p, p_pos+1)||
                   isMatchStartFrom(s, s_pos+1, p,p_pos);
        }
        return false;
    }
};