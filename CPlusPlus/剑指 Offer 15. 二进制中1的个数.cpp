/**
执行用时：4 ms, 在所有 C++ 提交中击败了40.61% 的用户
内存消耗：5.9 MB, 在所有 C++ 提交中击败了55.38% 的用户
这个题目需要注意的有 1 点：
* 如果输入的不是 uint 而是 int, 负数的补码表示最高是 1， 做右移可能有死循环
*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t flag{1};
        size_t count{0};
        while(flag){
            if(n&flag) ++count;
            flag = flag << 1;
        }
        return count;
    }
};