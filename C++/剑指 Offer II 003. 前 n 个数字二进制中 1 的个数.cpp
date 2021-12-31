/*
有两个需要关注的点：
* i 和 i&(i-1) 刚好差了最右边的 1
* 注意特殊情况的输入
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        for(int i = 1; i <= n; ++i){
            result[i] = result[i&(i-1)]+1;
        }
        return result;
    }
};