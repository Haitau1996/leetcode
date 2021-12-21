/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.8 MB, 在所有 C++ 提交中击败了67.44% 的用户
* i 和 i&(i-1) 在二进制表示中 1 的个数刚好差一个
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        x^=y;
        y =0;
        while(x){
            x&=(x-1);
            ++y;
        }
        return y;
    }
};