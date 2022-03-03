/* 
执行用时：16 ms, 在所有 C++ 提交中击败了63.10% 的用户
内存消耗：12.9 MB, 在所有 C++ 提交中击败了66.79% 的用户
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        vector<bool> rowRecord(m,false);
        vector<bool> colRecord(n, false);
        for(size_t i{}; i < m; ++i){
            for(size_t j{}; j < n; ++j){
                if(matrix[i][j] == 0){
                    rowRecord[i] = true;
                    colRecord[j] = true;
                }
            }
        }
        for(size_t i{}; i < m; ++ i){
            if(rowRecord[i]){
                for(size_t j{}; j < n; ++j)
                    matrix[i][j] = 0;
            }
        }
        for(size_t j{}; j< n; ++j){
            if(colRecord[j]){
                for(size_t i{}; i<m; ++i)
                    matrix[i][j] = 0;
            }
        }
    }
};