/*
执行用时：0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗：9 MB, 在所有 C++ 提交中击败了9.99% 的用户
*/
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int cursorA = m-1;
        int cursorB = n-1;
        while(cursorB >= 0){
            if(cursorA < 0 || A[cursorA]<B[cursorB]){
                A[cursorA+cursorB+1] = B[cursorB];
                --cursorB;
            }
            else{
                A[cursorA+cursorB+1] = A[cursorA];
                --cursorA;
            }
        }
    }
};