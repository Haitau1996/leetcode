/*
执行用时：4 ms, 在所有 C++ 提交中击败了40.32% 的用户
内存消耗：6.7 MB, 在所有 C++ 提交中击败了96.98% 的用户
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t size = matrix.size();
        int start = 0;
        while(start < size/2){
            for(int i = start; i < (size -1 - start); ++i){
                int temp = matrix[start][i];
                matrix[start][i] = matrix[size-1 - i][start];
                matrix[size-1-i][start] = matrix[size-1-start][size-1-i];
                matrix[size-1-start][size-1-i] = matrix[i][size-1-start];
                matrix[i][size-1-start] = temp;
            }
            ++ start;
        }
    }
};