/*
 * 使用一个 map 存放以 char c 结尾的最长子串长度， 使用 dp[i] 存放以 p[i] 结尾的最长符合条件的子串长度：
case 1: dp[i] =1 无法和 i-1 连上
case 2: dp[i] = dp[i-1]+1 能连上

接下来就要考虑每次更新 dp[i] 能往集合里添加多少个新的结果：
想了一下， 就是 max(dp[i] - st[p[i]],0)。意思就是， 如果新的 dp[i] 比 st[p[i]] 大则更新值并且将差额加入结果中， 小的话则无需处理。
*/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        unordered_map<char,int> st;
        vector<int> dp(n,0);
        dp[0] = 1;
        st.insert(pair(p[0],1));
        long res{1};
        for(int i = 1; i < n; ++i){
            if((p[i-1]-'a'+1)%26 == p[i]-'a')
                dp[i] = dp[i-1]+1;
            else dp[i] = 1;
            if(st.find(p[i]) == st.end()){
                st[p[i]] = dp[i];
                res += dp[i];
            }else if (dp[i] > st[p[i]]){
                res+= (dp[i] - st[p[i]]);
                st[p[i]] = dp[i];
            }
        }
        return res;
    }
};
