/*
执行用时：4 ms, 在所有 C++ 提交中击败了90.69% 的用户
内存消耗：7.7 MB, 在所有 C++ 提交中击败了71.99% 的用户
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        res[0] = 0;
        for(int i = 1; i<= n; ++i){
            res[i] = res[(i)&(i-1)]+1;
        }
        return res;
    }
};