#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int distinctSequences(int n) {
        const int M = int(1E9 + 7);
        if(n == 1) return 6; //if(n == 2) return 22;
        auto dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(7,vector<int>(7,0)));
        for(int i = 1; i <= 6; ++i){
            for(int j = 1; j <= 6; ++j){
                if(i != j && gcd(i,j)==1) dp[2][i][j] = 1;
            }
        }
        for(int curr = 3; curr <= n; ++curr){
            for(int i = 1; i <= 6; ++i){
                for(int j = 1; j <= 6; ++j){
                    if(gcd(i,j) > 1 || i == j) dp[curr][i][j] = 0;
                    else{
                        for(int k = 1; k <= 6; ++k){
                            if(k != j) dp[curr][i][j] = (dp[curr][i][j] + dp[curr-1][k][i])%M;
                        }
                    }
                }
            }
        }
        int res{0};
        for(int i = 1; i <= 6; ++i){
            for(int j = 1; j <= 6; ++j){
                res = (res + dp[n][i][j])%M;
            }
        }
        return res;
    }
};
