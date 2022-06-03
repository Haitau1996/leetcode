/*
 * i&(i-1) 将最右边的1变为0
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1,0);
        for(int i = 1; i<= n; ++i){
            res[i] = res[(i)&(i-1)]+1;
        }
        return res;
    }
};
