/*
 * 使用 dp, dp[i+1] 记录前 i 个位置回文分割后的字符串个数
 * todo: 使用预处理的方法降低时间复杂度
 */
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.size()+1,0);
        for(int i = 0; i < s.size(); ++i){
            int local_min = s.size()-1;
            for(int j = 0; j <= i; ++j){
                if(dp[j] < local_min && isPalin(s, j,i)){
                    local_min = dp[j];
                }
            }
            dp[i+1] = local_min + 1;
        }
        return dp.back()-1;
    }
private:
    int isPalin(const string& s, int low, int high){
        while(low < high){
            if(s[low] == s[high]){
                ++low;
                --high;
            }else{
                return false;
            }
        }
        return true;
    }
};
