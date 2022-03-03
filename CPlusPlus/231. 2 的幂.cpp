/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了27.86% 的用户
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count{0};
        while(n && count < 2){
            count += n &0x1;
            n = n>>1;
        }
        if(n == 0 && count == 1)
            return true;
        return false;
    }
};
