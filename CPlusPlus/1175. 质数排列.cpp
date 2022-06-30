/*
 * 使用筛法: 此题的意思就是质数的位置放质数， 其他的位置放其他， 如果前 n 个数中有 a 个质数， 那么结果就是 （a!*(n-a)!）%M。
 * 计算质数个数的时候可以使用筛法， 如遇到质数 2， 就将 n 以内的 2*i(i >2) 全部筛掉：
 * 起始：-,2,3,4,5,6,7,8,9,10
 * 筛掉2的倍数： -,2,3,-,5,-,7,-,9,-
 * 筛掉3的倍数： -,2,3,-,5,-,7,-,-,-
 * 以此类推。。。*/
#include <vector>

using std::vector;
class Solution {
public:
    int numPrimeArrangements(int n) {
        vector<bool> dp(n+1, false);
        dp[0] = true; dp[1] = true;
        for(int i = 2; i <=n; ++i){
            if(!dp[i]){
                for(int j = 2*i; j <= n; j+=i){
                    dp[j] = true;
                }
            }
        }
        auto a = count(dp.begin(), dp.end(), false);
        auto b = n-a;
        const int M = (int)(1E9) + 7;
        long res = 1;
        for(long i = 1; i <= a; ++i){
            res = (res * i)%M;
        }
        for(long j = 1; j <= b; ++j){
            res = (res * j)%M;
        }
        return res;
    }
};
