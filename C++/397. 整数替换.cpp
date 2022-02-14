class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(n == 2147483647) return 32;
        else if (n&0x1) return min(integerReplacement(n+1),integerReplacement(n-1)) + 1;
        else return 1 + integerReplacement(n>>1);
    }
};