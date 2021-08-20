/*
执行用时：4 ms, 在所有 C++ 提交中击败了43.90% 的用户
内存消耗：6.9 MB, 在所有 C++ 提交中击败了50.75% 的用户
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        helper(matrix, 0, matrix.size()-1);
    }
private:
    void helper(vector<vector<int>>& matrix, size_t beg, size_t end){
        if(beg >= end)
            return;
        else{
            int temp;
            for(int i = 0; i< end-beg; ++i){
                temp = matrix[beg][beg+i];
                matrix[beg][beg+i] = matrix[end-i][beg];
                matrix[end-i][beg] = matrix[end][end-i];
                matrix[end][end-i] = matrix[i+beg][end];
                matrix[i+beg][end] = temp;

            }
            helper(matrix,++beg,--end);
        }
    }
};