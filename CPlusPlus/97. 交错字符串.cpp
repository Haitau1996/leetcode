#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int sizeA = s1.size();
        int sizeB = s2.size();
        if(sizeA+sizeB != s3.size()) return false;
        vector<vector<bool>> dp(sizeA+1, vector<bool>(sizeB+1,false));
        dp[0][0] = true;
        for(int i = 0; i < sizeA;++i){
            if(s1[i] == s3[i]) dp[i+1][0] = dp[i][0];
        }
        for(int j = 0; j < sizeB; ++j){
            if(s2[j] == s3[j]) dp[0][j+1] = dp[0][j];
        }
        for(int i = 0; i < sizeA; ++i){
            for(int j = 0; j < sizeB; ++j){
                dp[i+1][j+1] = (s1[i] == s3[i+j+1] && dp[i][j+1]) || (s2[j] == s3[i+j+1] && dp[i+1][j]);
            }
        }
        return dp.back().back();
    }
};
