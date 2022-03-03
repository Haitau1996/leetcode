/*
典型的动态规划
*/
class Solution {
public:
    int translateNum(int num) {
        s = to_string(num);
        dp = vector<int>(s.size()+1,0);
        return helper();
    }
private:
    vector<int> dp;
    string s;
    int helper(){
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= s.size(); ++i){
            auto temp = stoi(s.substr(i-2,2));
            if(temp > 9 && temp <= 25) dp[i] = dp[i-2] + dp[i-1];
            else dp[i] = dp[i-1];
        }
        return dp.back();
    }
};