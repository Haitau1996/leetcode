#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    long long appealSum(string s) {
        int size = s.size();
        vector<int> prev(size, -1);
        vector<int> prev_buffer(26,-1);
        for(int i = 0; i < size; ++i){
            auto& c = s[i];
            prev[i] = prev_buffer[c-'a'];
            prev_buffer[c-'a'] = i;
        }
        int total = 0;
        for(int i = 0; i < 26; ++i){
            if(prev_buffer[i]!= -1){
                ++total;
            }
        }
        long long res{0};
        vector<int> dp(size, 0);
        for(int i = 0; i < size; ++i){
            for(int j = i; j < size; ++j){
                if(i == j) dp[j] = 1;
                else{
                    if(prev[j] < i){
                        dp[j] = dp[j-1]+1;
                    }
                    else dp[j] = dp[j-1];
                }
                if(dp[j] < total) res += dp[j];
                else{
                    res += (total * (size-j));
                    break;
                }
            }
        }
        return res;
    }
};
