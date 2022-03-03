/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：6.1 MB, 在所有 C++ 提交中击败了9.43% 的用户
这个找规律的题目最重要的有两点：
* 将所有的数字分段求解
* 最高位选择出来， 然后剩下两个部分， 一部分可以用递归， 一部分可以直接用排列组合， 相乘即可
*/
class Solution {
public:
    int countDigitOne(int n) {
        // base case if n < 10
        if(n == 0) return 0;
        if( n < 10) return 1;
        else{
            int po = powerOfTens(n);
            int highest = n / std::pow(10,po);
            int rem = n % (int)(highest*std::pow(10,po));
            int oneInHighest = highest >= 2 ? std::pow(10,po):rem+1;
            int oneInOthers = highest * po * std::pow(10,po-1);
            return oneInHighest + oneInOthers + countDigitOne(rem);
        }
    }
private:
    int powerOfTens(int n){
        int result{};
        while(n){
            result++;
            n/=10;
        }
        return result-1;
    }
};