// 解法 1： 暴力枚举， 在 n>= 5 的时候超出时间限制
#include<math.h>
#include<string>

using namespace std;
class BFSolution {
public:
    int largestPalindrome(int n) {
        long long start = pow(10,2*n)-1;
        while(start > 0){
            while(!isPalin(start)){
                --start;
            }
            int mut1 = pow(10, n) -1;
            while(mut1 > sqrt(start)){
                if(start % mut1 == 0) return start%1337;
                else --mut1;
            }
            --start;
        }
        return start;    
    }
private:
    bool isPalin(long long n){
        string temp = to_string(n);
        int low = 0;
        int high = temp.size()-1;
        while(low < high){
            if(temp[low] == temp[high]){
                ++low;
                --high;
            }else return false;
        }
        return true;
    }
};
class Solution {
public:
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        int leftPart = pow(10,n) - 1;
        const int HIGH = leftPart;
        int ledfBound = pow(10,n-1);
        while(leftPart > ledfBound){
            long total = leftPart;
            for(int x = leftPart; x> 0; x/=10){
                total = total*10 + x%10;
            }
            for(long temp = HIGH; temp*temp >= total; --temp){
                if(total%temp == 0){
                    return total%1337;
                }
            }
            --leftPart;
        }
        return leftPart;
    }
};
