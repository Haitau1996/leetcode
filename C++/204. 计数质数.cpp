/*
执行用时：144 ms, 在所有 C++ 提交中击败了34.90% 的用户
内存消耗：7.1 MB, 在所有 C++ 提交中击败了65.17% 的用户
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1)
            return 0;
        vector<bool> isPrime(n,true);
        int res = n - 2;
        isPrime[0] = false;
        isPrime[1] = false;
        int nsqart = std::ceil(std::sqrt(n));
        for(int i = 2; i <= nsqart; ++i){
            for(int j = 2; i * j <= n-1; ++j ){
                if(isPrime[i*j] == true){
                    isPrime[i*j] = false;
                    --res;
                }
            }
        }
        return res;
    }
};